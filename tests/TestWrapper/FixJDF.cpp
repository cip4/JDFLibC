#pragma warning( disable : 4786 ) // long debug names from stl
#pragma warning( disable : 4804 ) // bool checking


#include "MyArgs.h"
#include "MyTime.h"
#include "jdf/wrapper/JDFFactory.h"
#include "jdf/wrapper/JDF.h"
#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>

XERCES_CPP_NAMESPACE_USE
using namespace JDF;
using namespace std;
//////////////////////////////////////////////////////////////////

/**
*
* simple helper to create an indented string with leading blanks
* @param indent number of leadingbla
*/
WString Indent(int indent){
	WString s;
	for (int i=0;i<indent;i++) s+=" ";
	return s;
}
/**
* the subroutine to print out invalid parts of a jdf.
* @param JDFElement &jdfElement the element to print
* @param bool bQuiet flag what to do with valid elements; shut up if true
* @param KElement::EnumValidationLevel level validation level of the element
*/


int main(int argc, char* argv[]){
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	
	MyArgs args(argc,argv,"?cqvVnot","lLup");
	
	WString version="FixJDF: JDF version modifier; -- (c) 2005 CIP4\n";
	version+="JDF 1.3 compatible preliminary alpha version\n";
	version+="\n Code based on schema JDF_1.3.xsd\n";
	version+="Build version "+JDFAudit::Software();
	
	WString usage=L"\n\nUsage:FixJDF<flags> <input files>\n"; 
    usage+="-V(ersion)  -q(uiet)   -t(ime)\n";
	usage+="-L(ocation)<schemaLocation> -l(ocation)<privateSchemaLocation> \n";              
	usage+="-? usage info\n";
	usage+="-o overwrite input files\n";
	usage+="-p <prefix> of output files\n";
	usage+="-u <updateVersion> [1.0,1.1,1.2,1.3] updated version of output files\n";
	usage+="-q is quiet for valid files\n";
	usage+="-v validate using XML Schema validation;\n\tthe Schema can be defined in the xsi:schemaLocation tag in the JDF or using the -l or -L switch\n";
	usage+="-V Always print a version stamp, even in quiet mode (-q)\n";
	usage+="-L location of the schema for the Namespace \"http://www.CIP4.org/JDFSchema_1_1\"\n\tNote that blanks ' ' are invalid in the file names\n";
	usage+="-l location of additional private schema for validation in the same format as xsi:schemaLocation\n\texcept that multiple schema and schema/namespace pairs are separated by commas ',' not blanks ' '\n\tThe JDF schema specified in the -L switch should not be included in this list\n";
	usage+="-t print out Timing information\n";
	
	if(args.BoolParameter('?')){
		cout<<"FixJDF:\n"<<version<<usage;
		return 0;
	}
	
	bool bQuiet=args.BoolParameter('q');
	bool bValidate=args.BoolParameter('v');
	bool bVersion=!bQuiet||args.BoolParameter('V');

	if(bVersion)
		cout<<endl<<version<<endl<<endl;
	
	WString schemaLocation=args.ParameterString('L').c_str();
	if(!schemaLocation.empty()){
		schemaLocation="http://www.CIP4.org/JDFSchema_1_1 "+schemaLocation;
	}
	
	WString schemaLocation0=args.ParameterString('l').c_str();
	
	// convert "," to "_"
	if(!schemaLocation0.empty()){
		vWString vs=schemaLocation0.Tokenize(L",");
		if(vs.size()%2){
			cout<<"error in schema location: format is \"NameSpaceURI1,Location1,NameSpaceURI2,Location2\"\n";
			cout<<usage;
			return 3;
		}
		schemaLocation0=vs.GetString();
		schemaLocation+=schemaLocation0;
	}
	
	
	if(!args.NArgs()){
		cout<<args.Usage(usage)<<endl;
		return 2;
	}

	WString prefix;
	if(!args.BoolParameter('o')){ 
		prefix=args.ParameterString('p');
		if(prefix.empty())
			prefix=L"_";
	}

	WString updateVersion=args.ParameterString('u');
	int iV=JDFElement::VersionString().PosOfToken(updateVersion,WString::comma);
	if(iV==WString::npos){
		cout << "Invalid update version (-u): "<<args.ParameterString('u');
		cout<<args.Usage(usage)<<endl;
		return 3;
	}
	JDFElement::EnumVersion eV=(JDFElement::EnumVersion)iV;

	MyTime * pTime=0;
	MyTime * pTime1=0;
	MyTime * pTime2=0;
	MyTime * pTime3=0;
	if(args.BoolParameter('t')){
		pTime=new MyTime("All");
		pTime1=new MyTime("Parse",false);
		pTime2=new MyTime("Internal FixJDF",false);
		pTime3=new MyTime("Write output",false);
	}

	for(int arg=0;arg<args.NArgs();arg++){

		WString xmlFile=args.ArgumentString(arg);
			
		WString outFile=prefix+xmlFile;

		if(!bQuiet) 
			cout<<"\n*** Fixing "<<xmlFile<<" *** to "<<outFile<<endl;
		
		JDFDoc gd;
		// I prefer catching exceptions in the debugger
		try{		
			if(args.BoolParameter('t')){
				pTime1->Start();
			}
			
			if(bValidate){
				cout<<"Output of the XERCES schema validation follows:\n";
			}
			JDFParser parser;
			
			try{
				if(_waccess(xmlFile.c_str(),0)){
					cout<<"**** no such file: "<<xmlFile<<endl<<endl;
					continue;
				}
				bool bSnafu;
				bSnafu=!parser.Parse(xmlFile.c_str(),bValidate,true,true,0,schemaLocation.c_str());
				if(bSnafu){
					cout<<" **** Validating parse failed for: "<<xmlFile<<" attempt non-validating parse!!!"<<endl<<endl;
					if(bValidate){
						bSnafu=!parser.Parse(xmlFile.c_str(),false,true,true,0,schemaLocation.c_str());
					}
					if(bSnafu){
						cout<<args.Usage(usage)<<endl;
						continue;
					}
				}
				gd=parser.GetRoot();
			}catch(JDFException x){
				cout <<"error parsing :"+xmlFile<<endl;
				continue;
			}
			if(bValidate){
				cout<<"\n\n**********************************************************\n\n";
				cout<<"Output of fixJDF proper follows:\n";
			}
			
			if(args.BoolParameter('t')){
				pTime1->Stop();
				pTime2->Start();
			}
			
			
			JDFNode root=gd.GetJDFRoot();
			JDFJMF jmf=gd.GetJMFRoot();
			// find the correct root
			if(!root.isNull()&&!jmf.isNull()){
				if (jmf.IsAncestor(root)){
					root=JDFNode();
				}else{
					jmf=JDFJMF();
				}
			}
			JDFElement * pRoot=0;
			if(!root.isNull()){
				pRoot=&root;
				JDFModified mod=root.GetCreateAuditPool().AddModified();
				mod.SetDescriptiveName(L"FixJDF update to version "+updateVersion);
				mod.SetAgentName(L"FixJDF");
				mod.SetAgentVersion(JDFAudit::Software());
			}else{
				pRoot=&jmf;
			}

			if(pRoot){ // no jdf, maybe jmf
				pRoot->FixVersion(eV);
				pRoot->EraseEmptyNodes();
			}else{
				cout<<" no jdf or jmf root for: "<<xmlFile<<endl;
				continue;
			}
			if(args.BoolParameter('t')){
				pTime1->Stop();
				pTime3->Start();
			}
			gd.Write2File(outFile);
			if(args.BoolParameter('t')){
				pTime3->Stop();
			}
			
		}catch (JDFException e){
			gd.DeleteUserData();
			cout<<"Caught Exception "<<e.getType()<<" "<<e.getMessage()<<endl;
		}
		
		
		delete(pTime);
		delete(pTime1);
		delete(pTime2);
		delete(pTime3);
		
	}
	
	JDF::PlatformUtils::Terminate();
	XMLPlatformUtils::Terminate();
	return 0;
}

