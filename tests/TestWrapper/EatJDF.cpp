#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>

#include "jdf/wrapper/JDF.h"
#include "JDFSimulator.h"
#include "MyArgs.h"
#include <iostream>

XERCES_CPP_NAMESPACE_USE
using namespace std;
using namespace JDF;
//////////////////////////////////////////////////////////////////

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

	MyArgs args(argc,argv,"adev","piot");
	WString usage="EatJDF: JDF consumer simulation;\n-i: input JDF;\n-o: output JDF;";
	usage+="\n-p JobPartID of the node to be completed\n-d: delete completed tasks from the output JDF\n";

	WString xmlFile=args.Parameter('i')?args.Parameter('i'):"";
	if(xmlFile.empty()){
		cerr<<args.Usage(usage)<<endl;
		return 2;
	}
	WString outFile=args.ParameterString('o');

	JDFParser parser;
	if(parser.Parse(xmlFile,args.BoolParameter('v'))==false){
		cerr<<args.Usage(usage)<<endl;
		return 1;
	}
	JDFDoc gd=parser.GetRoot();
	JDFNode root=gd.GetRoot();
	root.GetMinID();

//	cout<<p<<endl;
	WString part=args.ParameterString('p');
	if(part.empty()){
		WString task=args.ParameterString('t');
		if (task.empty()) task="*";
		JDFAudit aMod=root.GetCreateAuditPool().AddModified("EatJDF Complete: task="+task);
		vJDFNode vProcs=root.GetvJDFNode(task);
		while(42){
			bool bDone=false;
			for (int i=0;i<vProcs.size();i++){
				JDFSimulator p=vProcs[i];
				if(p.IsExecutable()){
					cout <<"Emulating: "<<p.GetType()<<endl;
					bDone=p.DoTask();
					if(bDone){
						vProcs.erase(vProcs.begin()+i);
						break;
					}
				}else{
					cout <<"Not Ready: "<<p.GetType()<<endl;
				}
			}
			if(!bDone) break;
		}
	}else{
		JDFAudit aMod=root.GetCreateAuditPool().AddModified(WString("EatJDF Part ")+WString(part));
		
		JDFSimulator partProc=root.GetJobPart(part);
		aMod.AppendHRef(partProc,"jRef");
		partProc.DoTask();
		
	}
	root.EraseEmptyNodes();
	gd.Write2File(outFile);

    return 0;
}

