//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
//////////////////////////////////////////////////////////////////////
#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include "jdf/wrapper/JDF.h"
#include <jdf/WrapperCore/XMLDocUserData.h>
#include "MyArgs.h"
#include "MyTime.h"
#include <iostream>

using namespace std;
using namespace JDF;
XERCES_CPP_NAMESPACE_USE

int main(int argc, char* argv[]){
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	
	string usage="MergeJDF: JDF merger simulation;\nArguments: 1=parent input JDF, 2=child input JDF;\n-o: output JDF;\n-c(0,1,2): cleanup merge audits at level 0(none) to 2(remove) \n-d: delete completed tasks from the output JDF\n-u unspawn id --> unspawn instead of merge\n";
	MyArgs args(argc,argv,"devIX","cou");
	KString unSpawnID=args.ParameterString('u');
	
	KString xmlFile1=args.ArgumentString(0);
	KString xmlFile2=args.ArgumentString(1);
	//	if((_access(xmlFile1.c_str(),0))||(_access(xmlFile2.c_str(),0))) {
	//		cerr<<args.Usage(usage);
	//		return 1;
	//	}
	
	KString outFile=args.ParameterString('o');
	
	// scoping to avoid destuctor error after termination of the library
	//	for(int k=0;k<100;k++){
	//		cout<<k<<"___________________________________"<<std::endl;
	{
		MyTime pTime("all");
		MyTime pTime1("parse main",false);
		MyTime pTime15("parse sub",false);
		MyTime pTime2("merge",false);
		MyTime pTime3("write",false);
		MyTime pTime4("diff",false);
		MyTime pTime5("diff write",false);
		MyTime pTime6("diff parse",false);
		MyTime pTime7("diff apply",false);
		MyTime pTime8("IsEqual",false);
		JDFParser parser;
		pTime1.Start();
		if(parser.Parse(xmlFile1,args.BoolParameter('v'))==false){
			cerr<<args.Usage(xmlFile1+": Parse Error")<<std::endl;
			return 2;
		}
		pTime1.Stop();
		
		JDFDoc gd=parser.GetRoot();
		if(args.BoolParameter('I')){
			gd.GetCreateXMLDocUserData()->SetDirtyPolicy(XMLDocUserData::DirtyPolicy_ID);
		}else if(args.BoolParameter('X')){
			gd.GetCreateXMLDocUserData()->SetDirtyPolicy(XMLDocUserData::DirtyPolicy_XPath);
		}
		
		JDFNode root=gd.GetRoot();


		if(unSpawnID.empty()){
			//			for(int iii=10;iii<64;iii++){
			//				cout<<iii<<" ";
			//				if(parser.Parse(KString::valueOf(iii)+xmlFile2,args.BoolParameter('v'))==false){
			pTime15.Start();
			if(parser.Parse(xmlFile2,args.BoolParameter('v'))==false){
				cerr<<args.Usage(xmlFile2+": Parse Error")<<std::endl;
				return 2;
			}
			pTime15.Stop();
			
			JDFDoc gd2=parser.GetRoot();
			JDFNode root2=gd2.GetRoot();
			int nCleanup=args.IntParameter('c');
			nCleanup=max(0,min(nCleanup,2));
			//				root.MergeJDF(root2,KString::valueOf(iii)+xmlFile2,(JDFNode::EnumCleanUpMerge)nCleanup,(JDFResource::EnumAmountMerge)2);
			//				gd.Write2File(KString::valueOf(iii)+outFile);
			pTime2.Start();
			root.MergeJDF(root2,xmlFile2,(JDFNode::EnumCleanUpMerge)nCleanup,(JDFResource::EnumAmountMerge)2);
			pTime2.Stop();
			pTime3.Start();
			gd.Write2File(outFile);
			pTime3.Stop();
			//			}
		}else{
			MyTime pTime("Unspawn");
			root.UnSpawn(unSpawnID);
		}
		
		gd.Write2File(outFile);

		if(args.BoolParameter('I')){
			cout<<"Dirty IDs: \n";
			vWString dirtyIDs=gd.GetDirtyIDs();
			cout<<dirtyIDs<<std::endl;
		}
		if(args.BoolParameter('X')){
			cout<<"Dirty XPaths: \n";
			vWString dirtyIDs=gd.GetDirtyXPaths();
			cout<<dirtyIDs.GetString(L"\n")<<std::endl;
			pTime4.Start();
			XMLDoc diffDoc=gd.GetDirtyDiff();
			pTime4.Stop();
			pTime5.Start();
			diffDoc.Write2File(outFile+L".dif");
			pTime5.Stop();

			pTime1.Start();
			if(parser.Parse(xmlFile1,args.BoolParameter('v'))==false){
				cerr<<args.Usage(xmlFile1+": Parse Error")<<std::endl;
				return 2;
			}
			pTime1.Stop();
			JDFDoc oldparse=parser.GetRoot();
			pTime6.Start();
			if(parser.Parse(outFile+L".dif",args.BoolParameter('v'))==false){
				cerr<<args.Usage(xmlFile1+": Parse Error")<<std::endl;
				return 2;
			}
			pTime6.Stop();
			pTime7.Start();
			JDFDoc diffDoc2=parser.GetRoot();
			oldparse.SetDirtyDiff(diffDoc2);
			pTime7.Stop();

			pTime8.Start();
			root.EraseEmptyNodes();
			oldparse.GetRoot().EraseEmptyNodes();
			if(oldparse.GetRoot().IsEqual(gd.GetRoot())){
				cout<<"Heureka"<<endl;
			}else{
				cout<<"whazzup"<<endl;
				oldparse.Write2File(outFile+L".snafu");
				gd.Write2File(outFile+L".OldSnafu");
			}
			pTime8.Stop();



		}
		gd.DeleteUserData();
		
	}
	// clean up
	
	JDF::PlatformUtils::Terminate();
	XMLPlatformUtils::Terminate();
	
    return 0;
}

