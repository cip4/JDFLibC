#include <jdf/util/PlatformUtils.h>

#include "jdf/wrapper/JDF.h"
#include "jdf/net/URLEncoder.h"
#include "jdf/net/URL.h"
#include "jdf/net/URI.h"
#include "jdf/io/File.h"
#include "JDFSimulator.h"
#include <xercesc/util/PlatformUtils.hpp>

#include "MyTime.h"
#include "MyArgs.h"
#include <iostream>

XERCES_CPP_NAMESPACE_USE

using namespace std;
using namespace JDF;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

/**
*  a simple generic main routine for a dumb console app
*
*  switches:
* -a: actions to perform - DoAll calls all test programs
* -i input JDF file
* -o output JDF File 
* 
*/


int main(int argC, char* argV[]){
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	
	// trivial argument handling
	MyArgs args(argC,argV,"","aio");
	
	// Watch for special case help request
	WString usage="JDFExample; example usages of the JDF Library\nArguments: -a: actions to perform \n";
	usage.append("-i input JDF file\n-o output JDF File\n");
	if ((argC>1)&&(strcmp(argV[1], "-?") == 0)){
		cerr<< args.Usage(usage);
		return 0;
	}
	
	
	// setup indentation for the output - 2 blanks/level
	// read input, output and action settings from the command line
	WString action=args.ParameterString('a');
	WString inFile=args.ParameterString('i');
	WString outFile=args.ParameterString('o');
	
	// create a JDF Doc
	// use TestDoc as a container that holds the various example routines
	// clean up
	if(0){
		try{
			JDFDoc doc(0);
			//			doc.StringParse(inString,false);
			JDFNode MyJDF=doc.GetJDFRoot();
			JDFContact c=MyJDF.AppendCustomerInfo().AppendContact();
			c.MakeRootResource();
			
			JDFNode n=doc.GetRoot();
			
			JDFComponent lp=n.AddConsumable(JDFElement::elm_Component);
			lp.SetPartUsage(lp.PartUsage_Implicit);
			vWString v;
			v.push_back("SignatureName");
			v.push_back("SheetName");
			v.push_back("Condition");
			vWString vCond(L"Good Bad Waste SnarfGood");
			MyTime tCreate("create");
			cout<<"create"<<endl;
			for(int s1=0;s1<4;s1++){
				for(int s2=0;s2<2;s2++){
					for(int s3=0;s3<vCond.size();s3++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						m.AddPair(L"Condition",vCond[s3]);
						lp.GetCreatePartition(m,v);
					}
				}
			}
			tCreate.Stop();
			{
				cout<<lp<<endl;
				mAttribute m;
				m.AddPair(L"SheetName","Sheet1");
				m.AddPair(L"Side","Front");
				JDFComponent lp2=lp.GetPartition(m);
				cout<< "Surface Front"<<lp2<<endl;
				mAttribute m3;
				m3.AddPair(L"SignatureName","Sig2");
				JDFComponent lp3=lp.GetPartition(m3);
				cout<< "SignatureName Sig2"<<lp3<<endl;
				mAttribute m31;
				m31.AddPair(L"SheetName","Sheet7");
				m31.AddPair(L"SignatureName","Sig1");
				JDFComponent lp31=lp3.GetPartition(m31);
				cout<< "non root"<<lp31<<endl;

				m3.AddPair(L"SheetName","Sheet7");
				lp3=lp.GetPartition(m3);
				cout<< "SignatureName Sig2 SheetName Sheet7"<<lp3<<endl;
				mAttribute m4;
				m4.AddPair(L"SheetName","Sheet1");
				JDFComponent lp4=lp.GetPartition(m4);
				cout<< "SheetName Sheet1"<<lp4<<endl;
				m4.AddPair(L"SignatureName","Sig2");
				lp4=lp.GetPartition(m4);
				cout<< "SheetName Sheet1 SignatureName Sig2"<<lp4<<endl;
				return 0;
			}
			MyTime tRead("Read",false);
			MyTime tRead1("Read1",false);
			MyTime tRead2("Read2",false);
			MyTime tRead3("Read3",false);
			MyTime tRead4("Read4",false);
			MyTime tRead5("Read5",false);
			MyTime tRead6("Read6",false);
			MyTime tRead7("Read7",false);
			MyTime tRead8("Read8",false);
			MyTime tRead9("Read9",false);
			MyTime tReada("Reada",false);
			for(int read=0;read<1;read++){
				cout<<"read "<<read<<endl;
				tRead.Start();
				int s1;
				tRead1.Start();
				for(s1=0;s1<100;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead1.Stop();
				
				tRead2.Start();
				for(s1=100;s1<200;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead2.Stop();
				tRead3.Start();
				for(s1=200;s1<300;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead3.Stop();
				tRead4.Start();
				for(s1=300;s1<400;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead4.Stop();
				tRead5.Start();
				for(s1=400;s1<500;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead5.Stop();
				cout<<"   500\n";
				tRead6.Start();
				for(s1=500;s1<600;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead6.Stop();
				tRead7.Start();
				for(s1=600;s1<700;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead7.Stop();
				cout<<"   700\n";
				tRead8.Start();
				for(s1=700;s1<800;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead8.Stop();
				cout<<"   800\n";
				tRead9.Start();
				for(s1=800;s1<900;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tRead9.Stop();
				cout<<"   900\n";
				tReada.Start();
				for(s1=900;s1<1000;s1++){
					for(int s2=0;s2<10;s2++){
						mAttribute m;
						m.AddPair(L"SignatureName",L"Sig"+WString::valueOf(s1));
						m.AddPair(L"SheetName",L"Sheet"+WString::valueOf(s2));
						lp.GetPartition(m);
					}
				}
				tReada.Stop();
				
				tRead.Stop();
				
				}
				//				cout<<lp<<endl;
				
				{
					JDFResourceLink rl=n.GetResourceLinkPool().GetElement("LayoutPreparationParamsLink");
					cout<<rl;
					mAttribute m;
					m.AddPair(L"SignatureName",L"Sig0");
					m.AddPair(L"SheetName",L"Sheet");
					rl.SetPartMap(m);
					vElement v1=rl.GetTargetVector();
					cout<<endl<<v1.size()<<endl;
					for(int vv=0;vv<v1.size();vv++){
						cout<<v1[vv]<<endl;
					}
				}
				
				{
					JDFResourceLink rl=n.GetResourceLinkPool().GetElement("LayoutPreparationParamsLink");
					cout<<rl;
					mAttribute m;
					m.AddPair(L"SignatureName",L"Sig0");
					m.AddPair(L"SheetName",L"Sheet1");
					rl.SetPartMap(m);
					vElement v1=rl.GetTargetVector();
					cout<<endl<<v1.size()<<endl;
					for(int vv=0;vv<v1.size();vv++){
						cout<<v1[vv]<<endl;
					}
				}
				
				/*			
				{
				JDFResourceLink rl=n.GetResourceLinkPool().GetElement("LayoutPreparationParamsLink");
				cout<<rl;
				mAttribute m;
				m.AddPair(L"SheetName",L"Sheet1");
				rl.SetPartMap(m);
				vElement v1=rl.GetTargetVector();
				cout<<endl<<v1.size()<<endl;
				for(int vv=0;vv<v1.size();vv++){
				cout<<v1[vv]<<endl;
				}
				}
				*/				
		}catch(JDFException e){
			cout<<"what "<<e.what()<<endl;
		}
	}else if(0){
		for(int iii=0;iii<10;iii++)
		{int i=1;
		cout<<++i<<endl;
		}
		JDFDoc doc;
		doc.Write2File("empty.jdf");
		doc.Parse(inFile);
		JDFNode n=doc.GetJDFRoot();
		n=n.GetvJDFNode("ConventionalPrinting").at(0);
		JDFResourceLink rl =n.GetXPathElement("ResourceLinkPool/ColorantControlLink");
		cout<<rl<<endl<<rl.GetTarget()<<endl;
		
		
		vResource vR=n.GetLinkedResources();
		for(int i=0;i<vR.size();i++){
			JDFResource r=vR[i];
			if(r.GetLocalName()=="Component"){
				vResource vrr=r.GetLeaves();
				for(int j=0;j<vrr.size();j++){
					JDFResource(vrr.at(j)).UpdateAmounts(-1);
				}
				cout<<r<<endl;
			}
		}
		doc.Write2File(outFile);
		cout <<WString(L"a");
	}else if(0){
      JDFDoc doc(0);
       JDFNode root = doc.GetJDFRoot();
	   root.SetEnumVersion(JDFElement::Version_1_3);
       JDFAttributeMap pm("SheetName","s1");
       root.SetPartStatus(pm, JDFElement::Status_Waiting);
       JDFNodeInfo ni=root.GetNodeInfo().GetPartition(pm);
	   cout<<root<<endl;
       
	   root.SetEnumVersion(JDFElement::Version_1_2);
       root.SetPartStatus(pm, JDFElement::Status_Completed);
	   cout<<root<<endl;
	}else if(1){
		JDFDoc dc;
		dc.Parse("mimetest1.xml",false);
		cout<<dc<<endl;
          JDFDoc d(0);
        JDFNode n=d.GetJDFRoot();         
        n.SetType("fnarf");
		cout<<n<<endl;

	}else if(1){
		JDFDoc doc;
		doc.Parse(inFile,false);
		JDFNode n=doc.GetJDFRoot();
		JDFRunList rl=n.GetMatchingResource(L"RunList");
		mAttribute ma;
		ma.AddPair("SignatureName","Sig1");
		ma.AddPair("SheetName","Sig1_Sheet1");
		ma.AddPair("Side","Front");

		JDFRunList rlp=rl.GetPartition(ma);
		rlp.Collapse();
		cout<<rl<<endl;

		doc.Write2File(outFile);
	}else if(1){
					cout <<endl<<JDFResource::PartIDKeyString(JDFResource::PartIDKey_WebProduct)<<endl;

		JDFDoc doc(0);
		JDFNode n=doc.GetJDFRoot();
		JDFXYPair xyp(L"");
		JDFXYPair xyp1("");
		JDFXYPair xyp2(WString::emptyStr);
		JDFXYPair xypa=L"";
		JDFXYPair xypa1="";
		JDFXYPair xypa2=WString::emptyStr;

		n.init();
		n.SetType("Product");
		n.SetStatus(n.Status_Waiting);
		n.SetPartStatus(mAttribute("Run","R1"),n.Status_Completed);
		n.SetPartStatus(mAttribute("Run","R2"),n.Status_Completed);
		cout<<n.GetPartStatus(mAttribute("RunIndex","0"));
		n.SetAttribute("Url","a&b");
		JDFNodeInfo ni=n.GetNodeInfo();
		cout<<ni<<endl;
		JDFNodeInfo ni2=ni.GetPartition(mAttribute("RunIndex","0"));
		cout<<ni2<<endl;
		ni2=ni.GetPartition(mAttribute("Run","R1"));
		cout<<ni2<<endl;
		WString s;
		doc.Write2String(s);
		JDFDoc doc2;
		doc2.StringParse(s);
		n=doc2.GetJDFRoot();
		cout<<n.GetAttribute("Url")<<endl;
		cout<<n;

		WString ww("a&b .pdf");
		ww=ww.Escape("","%",16,2,0x40,0x7fffffff);
		cout<<ww<<endl;
		
		WString unc=L"d:temp/preview#1 & #2.png";
		File fff(unc);
		URI fileURI=fff.toURI();
		cout<<fileURI.toString()<<endl;

		
		return 0;

		JDFDeviceInfo di=n.AppendElement("DeviceInfo");
		di.SetDeviceStatus(di.DeviceStatus_Unknown);
		cout << di.IsValid()<<" "<<di;
		n.SetPartStatus(mAttribute::emptyMap,n.Status_Waiting,"Waiting");
		n.SetVersion("1.2");
		n.AppendMatchingResource("LayoutIntent",n.ProcessUsage_AnyInput);
		JDFResource r=n.AppendMatchingResource("DeliveryIntent",n.ProcessUsage_AnyInput);
		JDFResource rr=r.AppendElement("DropIntent");
		rr=rr.AppendElement("DropItemIntent");
		cout <<rr.GetResourceRoot();
		n.MoveElement(r);
		cout <<rr.GetResourceRoot();
		XMLDoc d("fnarf");
		rr=d.GetRoot();
		cout <<rr.GetResourceRoot();


		JDFComponent c=n.AppendMatchingResource("Component",n.ProcessUsage_AnyOutput);
		JDFResourceLink l=n.GetMatchingLink("Component",n.ProcessUsage_AnyOutput);
		mAttribute mPart=mAttribute("SheetName","S3");
		mPart.AddPair("Separation","yellow");

		JDFMedia med=n.AddConsumable(L"Media");
		JDFExposedMedia xmed=n.AddConsumable(L"ExposedMedia");
		xmed.RefElement(med);
		
		n.RemoveResource(L"Media");
		n.RemoveResource(L"ExposedMedia");
		n.RemoveResource(L"Media");
		
		l.SetDraftOK(true);
		l.SetPartMap(mPart);

		JDFComponent c1=c.AddPartition(JDFResource::PartIDKey_SheetName,"S1");
		c1.AddPartition(c1.PartIDKey_Separation,"cyan");
		c1.AddPartition(c1.PartIDKey_Separation,"magenta");
		c1.AddPartition(c1.PartIDKey_Separation,"yellow");

		JDFComponent c2=c.AddPartition(JDFResource::PartIDKey_SheetName,"S2");
		JDFComponent c3=c.AddPartition(JDFResource::PartIDKey_SheetName,"S3");
		c3.AppendElement(c3.elm_Identical).AppendElement(c3.elm_Part).SetAttribute(c3.atr_SheetName,"S1");

		cout<<l<<endl<<l.GetTarget();

		n.SetPartStatus(MapWString("SheetName","S1"),n.Status_Completed,L"done");
		n.SetPartStatus(MapWString("SheetName","S2"),n.Status_Waiting,L"not done");
		MapWString mm=MapWString("SheetName","S2");
		mm.AddPair("Side", "Front");
		cout<<n<<endl<<endl;
		n.SetPartStatus(mm,n.Status_Setup,L"test");

		cout<<n<<endl<<endl;
		n.SetPartStatus(MapWString("SheetName","S2"),n.Status_Waiting,L"again done");
		cout<<n<<endl<<endl;
		n.SetPartStatus(MapWString("SheetName","S2"),n.Status_Completed);
		cout<<n<<endl<<endl;

		
		n.FixVersion(n.Version_1_3);
		cout<<n<<endl;
		n.FixVersion(n.Version_1_2);
		cout<<n<<endl;
		

	}else if(0){
		
		JDFDoc doc(0);
		//			doc.StringParse(inString,false);
		JDFNode root=doc.GetJDFRoot();

		JDFNode n=doc.GetRoot();
		n.SetAttribute("bool",true);
		n.SetType("ProcessGroup");

		JDFNode MyJDF=doc.GetJDFRoot().AddProcess("ConventionalPrinting");
		MyJDF.SetJobPartID("j1");
		JDFContact c=MyJDF.AppendCustomerInfo().AppendContact();
		c.MakeRootResource(WString::emptyStr,root.GetCreateResourcePool());
		mAttribute ma;
		ma.AddPair("Run","r1");
		MyJDF.SetAttribute("Version","1.2");
		MyJDF.SetPartStatus(ma,MyJDF.Status_InProgress);
		cout<<MyJDF.StatusString(MyJDF.GetPartStatus(ma))<<endl<<MyJDF<<endl;
		
		JDFLayoutPreparationParams lp=n.AddParameter(JDFElement::elm_LayoutPreparationParams);
		JDFRunList rul=n.AddParameter(JDFElement::elm_RunList);
		rul.AddPartition(rul.PartIDKey_Separation,"cyan");
		rul.AddPartition(rul.PartIDKey_Separation,"magenta");
		rul.AddPartition(rul.PartIDKey_Separation,"yellow");
		vElement vvv=rul.GetLeaves();
		cout<<rul;

		int jj=0;
		for(vElement::iterator i=vvv.begin();i!=vvv.end();i++){
			JDFResource r=*i;
			r.SetLocked(jj%2);
			cout<<jj<<r<<endl;
			r.SetLocked((1+jj)%2);
			cout<<jj<<r<<endl;
			r.SetLocked((jj)%2);
			cout<<jj++<<r<<endl;
		}
		JDFResource rr=rul.AppendLayoutElement().AppendFileSpec();
		cout<<rr<<endl;
		rul.SetIsPage(true);
		JDFDevice dev=n.AddHandling(JDFElement::elm_Device);
		JDFPhaseTime pt=n.GetCreateAuditPool().AddPhaseTime(JDFPhaseTime::Status_InProgress);
		pt.RefElement(dev);
		JDFNode n2=n.AddProcess("p2");
		JDFResource r2=n2.AddParameter("Test");
		JDFResource r3=n2.AddParameter("HDM:Test", false, n2,true, "www.hdm.com");
		JDFNode n3=n.AddProcess("p3");
		n3.LinkResource(r2);
		n3.LinkResource(r3);
		cout<<n<<endl;
		doc.Write2File("audit.jdf");


		return 1;

								
	}else{
		JDFDoc d(1);
		JDFJMF jmf=d.GetJMFRoot();
		JDFSignal s=jmf.AppendSignal(JDFMessage::Type_Status);
		cout<<d<<endl;
		s.AppendStatusQuParams();
		cout<<d<<endl;
		
	}
	JDF::PlatformUtils::Terminate();
	return 0;
}

