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

#include <xercesc/util/PlatformUtils.hpp>
#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include <jdf/WrapperCore/XMLDocUserData.h>
#include "MyArgs.h"
#include "MyTime.h"
#include "jdf/util/MyWalker.h"

#ifdef WIN32
// for _access
#include "io.h"
#include <iostream>
#endif

XERCES_CPP_NAMESPACE_USE
using namespace std;
using namespace JDF;

int main(int argc, char* argv[]){
	MyWalker walker; // memleak check
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	
	// brackets for terminate scope
	{
		MyArgs args(argc,argv,"acdeJnvIOX","ikoprsStw");
		WString usage="SpawnJDF: JDF spawn processor;\n-i: input JDF;\n-o: output JDF;\n-c: copy NodeInfo and CustomerInfo into Ancestors\n-O if set, overwrite the input\n-p:jobpartId;\n-w list of global resources rw in the format Resource:Input/OutPut/ProcessUsage separated by commas\n-d: delete node from original file\n-n use a namespace conforming parser\n-r: run id partition\n-s: separation partition\n-S: SheetName partition\n-k comma separated list of partition key value pairs; underscores are replaced by blanks\n-I: print ID of modified JDF elements\n";
		WString runID=args.ParameterString('r');
		WString sepID=args.ParameterString('s');
		WString sheetName=args.ParameterString('S');
		bool bInformative=args.BoolParameter('J');
		
		mAttribute part1;
		if(!runID.empty()) 
			part1.AddPair("Run",runID);
		if(!sheetName.empty()) 
			part1.AddPair("SheetName",sheetName);
		if(!sepID.empty()) 
			part1.AddPair("Separation",sepID);
		
		WString keys=args.ParameterString('k');
		vWString partKeys=keys.Tokenize(L",");
		for(int i=1;i<partKeys.size();i+=2){
			part1.AddPair(partKeys[i-1],partKeys[i].replaceChar(L'_',L' '));
		}
		
		bool useVDOMParser=args.BoolParameter('v');
		WString resRW=args.Parameter('w');
		
		// Check command line and extract arguments.
		WString xmlFile=args.Parameter('i')?args.Parameter('i'):"";
#ifdef WIN32
		if(_access(xmlFile.peekBytes(),0)) {
			cerr<<args.Usage(usage);
			return 1;
		}
#endif
		MyTime pTime("all");
		MyTime pTime1("parse main",false);
		MyTime pTime15("parse sub",false);
		MyTime pTime2("spawn",false);
		MyTime pTime3("write",false);
		MyTime pTime4("diff",false);
		MyTime pTime5("diff write",false);
		MyTime pTime6("diff parse",false);
		MyTime pTime7("diff apply",false);
		MyTime pTime8("IsEqual",false);
		
		WString outFile=args.ParameterString('o');
		WString task=args.ParameterString('t');
		WString partID=args.ParameterString('p');
		
//		for(int iii=10;iii<14;iii++){
			//			JDFElement::UniqueID(4000);
			//			JDFParser parser;
			JDFDoc docIn;
			if(docIn.Parse(xmlFile,args.BoolParameter('v'),true,args.BoolParameter('n'))==false){
				cerr<<args.Usage()<<endl;
				return 1;
			}
			if(args.BoolParameter('I')){
				docIn.GetCreateXMLDocUserData()->SetDirtyPolicy(XMLDocUserData::DirtyPolicy_ID);
			}else if(args.BoolParameter('X')){
				docIn.GetCreateXMLDocUserData()->SetDirtyPolicy(XMLDocUserData::DirtyPolicy_XPath);
			}
			
			
			JDFNode rootIn=docIn.GetRoot();
			//			WString::UniqueID();
			//			rootIn.GetMinID();
			JDFNode pCut;
			if(task.empty()){
				if(partID.empty()){
					pCut=rootIn;
				}else{
					pCut=rootIn.GetJobPart(partID);
					if(pCut.isNull()){
						cerr <<"No such JobPartID: "<<partID<<endl;
						exit(1);
					}
				}
			}else{
				pCut=rootIn.GetChildWithAttribute("JDF","Type","",task,0,false);
				if(pCut.isNull()){
					cerr <<"No such node: "<<task<<endl;
					exit(1);
				}
			}
			vmAttribute vMap;
			
			if(!part1.empty()) 
				vMap.push_back(part1);
			
				/*
				mAttribute map;
				for(int iii=0;iii<8;iii++){
				map.clear();
				map.AddPair("Side","Front");
				map.AddPair("SheetName","Sig1_Sheet1");
				map.AddPair("RunPage",WString(iii));
				vMap.push_back(map);
				}
				for(int iiii=0;iiii<8;iiii++){
				map.clear();
				map.AddPair("Side","Back");
				map.AddPair("SheetName","Sig1_Sheet1");
				map.AddPair("RunPage",WString(iiii));
				vMap.push_back(map);
				}
				
			*/
			vWString vRWRes=resRW.Tokenize(L",");
			
			/*
			mAttribute map;
			JDFResource res6=rootIn.GetTargetResource("Link528262000006");
			for(int iiii=0;iiii<2;iiii++){
			cout<<iiii<<" ";
            JDFResource resPart=res6.AddPartition(JDFResource::PartIDKey_SheetName,WString::valueOf(iiii));
            resPart.MoveElement(res6.GetElement("Signature").GetElement("SheetRef"));
			}
			*/
			mAttribute map;
			//		for(int iii=10;iii<14;iii++){
//			cout<<iii<<" ";
//			map.clear();
//			vMap.clear();
			//            map.put("Side","Front");
//            map.AddPair("SheetName","000"+WString::valueOf(iii)+"#Sheet_"+WString::valueOf(iii));
//            map.AddPair("RunIndex","0~8");
//            map.AddPair("Separation","Cyan");
			//            map.put("RunPage",String.valueOf(iii));
  //          vMap.push_back(map);
			
			//        for(int iiii=0;iiii<8;iiii++){
			//            map.clear();
			//            map.put("Side","Back");
			//            map.put("SheetName","Sig1_Sheet1");
			//            map.put("RunPage",String.valueOf(iiii));
			//            vSpawnParts.addElement(new JDFAttributeMap(map));
			//        }
			
			
			
			pTime2.Start();
			JDFDoc docOut;
			if(!bInformative){
				cout<<vRWRes<<endl;
				docOut= pCut.Spawn(xmlFile, outFile, vRWRes, vMap ,false,true,true);
			}else{
				docOut= pCut.SpawnInformative(xmlFile, outFile, vMap ,false,true,true);
			}
			pTime2.Stop();
			
			JDFNode rootOut=docOut.GetRoot();
			rootOut.EraseEmptyNodes();
//			docOut.Write2File(WString::valueOf(iii)+outFile);
			docOut.Write2File(outFile);
			if(!bInformative)
				docIn.Write2File(L"_"+xmlFile);

			if(args.BoolParameter('X')){
				cout<<"Dirty XPaths: \n";
				vWString dirtyIDs=docIn.GetDirtyXPaths();
				cout<<dirtyIDs.GetString(L"\n")<<std::endl;
				pTime4.Start();
				XMLDoc diffDoc=docIn.GetDirtyDiff();
				pTime4.Stop();
				pTime5.Start();
				diffDoc.Write2File(xmlFile+L".dif");
				pTime5.Stop();
			}
//        }
		
		/*		
		// this is the real thing
		bool bCopyNodeCustomer=args.BoolParameter('c');
		JDFDoc docOut=pCut.Spawn(xmlFile,outFile,vRWRes,vMap,false,bCopyNodeCustomer,bCopyNodeCustomer);
		JDFNode rootOut=docOut.GetRoot();
		rootOut.EraseEmptyNodes();
		
		  docOut.Write2File(outFile);
		  */		
		  /*		
		  if(!args.BoolParameter('O')) xmlFile="_"+xmlFile;
		  rootIn.EraseEmptyNodes();
		  docIn.Write2File(xmlFile);
		  if(args.BoolParameter('I')){
		  cout<<"Dirty IDs: \n";
		  vWString dirtyIDs=docIn.GetDirtyIDs();
		  cout<<dirtyIDs<<endl;
		  }
		  
			docIn.DeleteUserData();
			*/	}
			
			JDF::PlatformUtils::Terminate();
			XMLPlatformUtils::Terminate();
			
			
			return 0;
}

