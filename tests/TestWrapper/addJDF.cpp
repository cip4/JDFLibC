

#include "jdf/wrapper/JDF.h"
#include "MyArgs.h"
#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>

XERCES_CPP_NAMESPACE_USE
using namespace std;
using namespace JDF;

int main(int argc, char* argv[]){
    // Initialize the XML4C2 system
    try{
        XMLPlatformUtils::Initialize();
    }catch(const XMLException& toCatch){
        cerr << "Error during XML4C2 Initialization.\n"
			"  Exception message is \"%s\"\n"
			<< toCatch.getMessage() << endl;
        return 1;
    }
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}

	MyArgs args(argc,argv,"aeuv","bcChHijJknopPqQrsStT");
	
	WString outFile=args.ParameterString('o');
	
	WString xmlFile=args.Parameter('i')?args.Parameter('i'):"";

	WString usage="AddJDF: JDF modifier simulation;\n-bSeparation of sheets by sheet name\n";
	usage+="-k Comment to be added\n";
	usage+="-j JobID of the JDF node to be created\n-J JobPartID of the parent node to be modified\n";
	usage+="-u The new node is up 1 level and the resource is an input\n";
	usage+="-r name of the resource to be defined (default: Component)\n";
	usage+="-t type of process to create resource\n-T list of types if -t=Combined\n";
	usage+="-p(P) parameters of process to create resource;\n";
	usage+="-q(Q) quantifiable input resource of process to create resource;\n";
	usage+="-h(H) handling input resource of process to create resource;\n";
	usage+="-c(C) consumable input resource of process to create resource;\n";
	usage+="-a handling resources are available (default: unavailable)\n";
	usage+="-s potential separation names separated by commas;\n";
	usage+="-S Separations (comma separated) to be created by this process (works on -H resource!)";

	JDFParser parser;
	if(parser.Parse(xmlFile,args.BoolParameter('v'))==false){
		cerr<<args.Usage(usage)<<endl;
		return 1;
	}
	JDFDoc gd=parser.GetRoot();

	bool error=false;
	WString argString=" test";
	JDFNode root=gd.GetRoot();
	int nID=root.GetMinID();

	JDFAudit aMod=root.GetCreateAuditPool().AddModified(WString("AddJDF ")+argString);
	WString jID=args.ParameterString('j');
	if(jID.empty()) jID="0";
	WString jPartID=args.ParameterString('J');
	int jobPart=1+root.GetMaxJobPartId();
	jobPart=max((int)jID,jobPart);
	if(jPartID.empty()) 
		jPartID+=WString(jobPart-1);
	WString nameRes=args.ParameterString('r');
	if(nameRes.empty())	
		nameRes="Component";
	
	WString nameRes2=nameRes.Token(1,L":");
	if(!nameRes2.empty())
		nameRes=nameRes.Token(0,L":");
	
	JDFNode proc=root.GetJobPart(jPartID);
	if(proc.isNull()){
		cerr<<"!!! no such process:  jobPartID="<<jPartID<<endl;
		cerr<<args.Usage(usage)<<endl;
		return 1;
	}
	JDFResourceLinkPool lp=proc.GetResourceLinkPool();
	vElement vRes=lp.GetInOutLinks(args.BoolParameter('u'),false,nameRes);

	
	if(vRes.size()<1){
		cout <<proc;
		cerr<<"!!! output resource is invalid!\n";
		cerr<<args.Usage(usage)<<endl;
		return 1;
	}

	JDFResource res=vRes[0];


	WString sepsheets=args.ParameterString('b');
	if(!sepsheets.empty()){
		vResource vP=res.AddPartitions(JDFResource::PartIDKey_SheetName,sepsheets.Tokenize(","));
		vP.SetAttributes("Test",sepsheets.Tokenize(","));
	}
	WString seps=args.ParameterString('s');
	if(!seps.empty()){
		if(seps=="CMYK") seps="Cyan,Magenta,Yellow,Black";
		vResource vP=res.AddPartitions(JDFResource::PartIDKey_Separation,seps.Tokenize(","));
		vP.SetAttributes("Separation",seps.Tokenize(","));
	}


	WString task=args.ParameterString('t');
	WString combiTask=args.ParameterString('T');

	if(args.BoolParameter('u')) proc=proc.GetParentNode();
	JDFNode subProc;
	if(task!=L"Combined"){
		subProc=proc.AddProcess(task);
	}else{
		subProc=proc.AddCombined(combiTask.Tokenize(","));
	}
	subProc.SetJobPartID(jobPart++);
	subProc.LinkResource(res,false);
	aMod.AppendHRef(subProc,"jRef");

	if(!nameRes2.empty()){
		vElement vResLinks=subProc.GetResourceLinkPool().GetInOutLinks(false, true, nameRes);
		for(int i=0;i<vResLinks.size();i++){
			JDFResourceLink rl=vResLinks[i];
			if(rl.GetTarget()==res){
				rl.SetProcessUsage(nameRes2);
				break;
			}
		}				
	}			

	WString comment=args.ParameterString('k');
	if(!comment.empty()){
		cout <<comment<<endl;
		subProc.SetDescriptiveName(comment);
	}

	int ii;
	for(ii=0;ii<2;ii++){
		WString s=args.ParameterString(ii?'h':'H');
		WString s2=s.Token(1,L":");
		if(!s2.empty())
			s=s.Token(0,L":");

		if(!s.empty()){
			WString sep=args.ParameterString('S');
			JDFResource r=subProc.AddResource(s,JDFResource::Class_Handling,true,subProc.GetParentNode());
			if (args.BoolParameter('a')){
				r.SetStatus(JDFResource::Status_Available);
			}else{
				r.SetStatus(JDFResource::Status_Unavailable);
			}
			if(!s2.empty()){
				vElement vResLinks=subProc.GetResourceLinkPool().GetInOutLinks(true, true, s);
				for(int i=0;i<vResLinks.size();i++){
					JDFResourceLink rl=vResLinks[i];
					if(rl.GetTarget()==r){
						rl.SetProcessUsage(s2);
						break;
					}
				}				
			}			
		}
	}

	for(ii=0;ii<2;ii++){
		WString s=args.ParameterString(ii?'q':'Q');
		int quantity=args.IntParameter('n',-1);
		WString s2=s.Token(1,L":");
		if(!s2.empty())
			s=s.Token(0,L":");
		if(!s.empty()){
			JDFResource r=subProc.AddResource(s,JDFResource::Class_Quantity,true,subProc.GetParentNode());
			r.SetAmount(quantity);
			if(!s2.empty()){
				vElement vResLinks=subProc.GetResourceLinkPool().GetInOutLinks(true, true, s);
				for(int i=0;i<vResLinks.size();i++){
					JDFResourceLink rl=vResLinks[i];
					if(rl.GetTarget()==r){
						rl.SetProcessUsage(s2);
						break;
					}
				}				
			}			
		}
	}
	
	for(ii=0;ii<2;ii++){
		WString s=args.ParameterString(ii?'c':'C');
		int quantity=args.IntParameter('n',-1);
		WString s2=s.Token(1,L":");
		if(!s2.empty())
			s=s.Token(0,L":");
		if(!s.empty()){
			JDFResource r=subProc.AddResource(s,JDFResource::Class_Consumable,true,subProc);
			r.SetAmount(quantity);
			if(!s2.empty()){
				vElement vResLinks=subProc.GetResourceLinkPool().GetInOutLinks(true, true, s);
				for(int i=0;i<vResLinks.size();i++){
					JDFResourceLink rl=vResLinks[i];
					if(rl.GetTarget()==r){
						rl.SetProcessUsage(s2);
						break;
					}
				}				
			}			
		}
	}

	for(ii=0;ii<2;ii++){
		WString s=args.ParameterString(ii?'p':'P');
		WString s2=s.Token(1,L":");
		if(!s2.empty())
			s=s.Token(0,L":");
		if(!s.empty()){
			JDFResource r=subProc.AddResource(s,JDFResource::Class_Parameter,true);
			if(!s2.empty()){
				vElement vResLinks=subProc.GetResourceLinkPool().GetInOutLinks(true, true, s);
				for(int i=0;i<vResLinks.size();i++){
					JDFResourceLink rl=vResLinks[i];
					if(rl.GetTarget()==r){
						rl.SetProcessUsage(s2);
						break;
					}
				}				
			}			
		}
	}

	root.EraseEmptyNodes();
	if(!error) 
		gd.Write2File(outFile);
	return 0;
}

