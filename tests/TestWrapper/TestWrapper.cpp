#include <jdf/util/PlatformUtils.h>

#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/net/URLEncoder.h"
#include "jdf/net/URL.h"
#include "jdf/net/URLConnection.h"
#include "jdf/net/URI.h"
#include "jdf/io/File.h"
#include "jdf/io/FileInputStream.h"
#include "jdf/io/FileOutputStream.h"
#include "jdf/io/OutputStream.h"
#include "jdf/util/MyWalker.h"
#include "JDFSimulator.h"
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOMElement.hpp>


#include "MyTime.h"
#include "MyArgs.h"
#include <iostream>
#include <locale.h>

XERCES_CPP_NAMESPACE_USE
int nnnn=0;
#define assertEquals(a,b)if(a!=b)cout<<"bad assertEquals\n"<<a<<endl<<b;
#define assertNotSame(a,b)if(a==b)cout<<"bad assertNotSame\n"<<a<<endl<<b;
#define assertTrue(a)if(!a)cout<<"bad True\n"<<a<<endl;
#define assertFalse(a)if(a)cout<<"bad False\n"<<a<<endl;
#define CPPUNIT_ASSERT(a)if(!a)cout<<"bad Equals\n"<<nnnn++<<endl;else{nnnn++;}
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
	MyWalker walker; // memleak check
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



	//	JDF::PlatformUtils::setProperty("http.keepAlive","false");

	// setup indentation for the output - 2 blanks/level
	// read input, output and action settings from the command line
	WString action=args.ParameterString('a');
	WString inFile=args.ParameterString('i');
	WString outFile=args.ParameterString('o');

	// create a JDF Doc
	// use TestDoc as a container that holds the various example routines
	// clean up
	if(0)
	{
		JDFDoc d(1);
		JDFJMF j=d.GetJMFRoot();
		j.AppendSignal(JDFMessage::Type_AbortQueueEntry).SetTime(0);
		j.AppendSignal(JDFMessage::Type_AbortQueueEntry).SetTime(-1);
		cout<<d;
	}
else if(1)
{
		JDFDoc doc;
		doc.Parse("c:\\data\\ulf1.jdf",false);
		JDFNode n=doc.GetJDFRoot();
		JDFResource rl=n.GetMatchingResource(L"ColorantControl");
		rl.Collapse(true);
		cout<<rl<<endl;

		doc.Write2File("c:\\data\\ulf2.jdf");
}
else if(true)
	{
		JDFDoc d;
		d.Parse("O:\\JDFLibJ\\test\\data\\evilParts.jdf");
		JDFNode n = d.GetJDFRoot();
		cout<<"foo"<<endl;
		VString v = n.GetPartIDKeys();
		cout<<"foo"<<endl;

		JDFAuditPool ap=n.GetCreateAuditPool();
		JDFCreated c=ap.GetAudit(0,JDFAudit::AuditType_Created);
		if(c.isNull())
			c=ap.AddCreated();
		c.SetAgentName("fooBar");

		JDFModified m=ap.AddModified();
			m.SetAgentName("fooBar");
			JDFAudit::setStaticAgentName("fpo");

			d.Write2File("C:\\data\\jdf\\foo.jdf");

	}
	else if(1)
	{
		JDFDoc doc(0);//JDF
		WString filePath("O:\\JDFLibC\\tests\\TestFiles\\data\\partitioned_private_resources.jdf");
		doc.Parse(filePath, false);

		JDFNode myRoot              = doc.GetJDFRoot();
		JDFResourcePool myResPool   = myRoot.GetResourcePool();
		JDFResource myPreview       = (JDFResource)myResPool.GetElement("Preview", WString::emptyStr, 0);
		JDFAttributeMap m;

		m.put("Side", "Front");
		m.put("Separation", "Black");
		m.put("PreviewType", "Separation");

		myPreview = myPreview.GetPartition(m, JDFResource::PartUsage_Explicit);
		vElement vRes = myPreview.GetLeaves(false);

		for (int i = 0; i < vRes.size(); i++)
		{
			JDFAttributeMap myMap = ((JDFResource) vRes.elementAt(i)).GetPartMap(); 
			if (WString("Black").equals(myMap.GetValue("Separation")))
			{				
				assertEquals( WString("Front"),myMap.GetValue("Side") );
				assertEquals( WString("Separation"),myMap.GetValue("PreviewType") );
				assertTrue ( myMap.GetValue("SheetName").startsWith("Sheet ") ); // "Sheet 1" or "Sheet 2"
				assertEquals( WString("Black"),myMap.GetValue("Separation") );
			}
		}

	}
	else if(0)
	{
		JDFDoc doc(1);//JMF
		WString filePath("C:\\data\\jdf\\hp Olga\\JMFrespQueueAJob.jmf.xml");
		cout<<filePath<<endl;
		doc.Parse(filePath, false);

		cout<<doc<<endl;
		JDFJMF jdfJmfRoot = doc.GetJMFRoot();
		JDFResponse respEl = jdfJmfRoot.GetResponse();

		JDFQueue queueEl = respEl.GetQueue();//====================>>>> here I have the Exception problem!!!!
		cout<<"OK"<<endl<<queueEl<<endl;

	}
	else if(0)
	{
		WString s="file:///C:/Documents%20and%20Settings/All%20Users/Desktop/Prinect_Imposition_Editor/Examples/x.jdf";
		URL url(s);
		cout<<url.getPath()<<endl;
	}
	else if(1)
	{
		JDFParser p;
		p.Parse(inFile);
		JDFDoc d=p.GetDocument();
		JDFNode n=d.GetJDFRoot();

		cout<<n.GetAncestorPool()<<endl;


		return 1;

	}
	else if(0){
		WString dumpURL="http://localhost:8080/JDFUtility/dump";
		//		WString dumpURL="http://10.10.146.58:8010/FJC/imgpass";
		for(int j=0;j<6;j++)
		{
			if(j==5)
				dumpURL="http://10.10.146.58:8010/FJC/imgpass";
			cout<<"---------"<<j<<"--------------"<<endl;
			File f("C:\\data\\canon\\test.mjm");
			FileInputStream is(f);

			URL url(dumpURL);

			URLConnection* pURLConnection =url.openConnection();

			pURLConnection->setDoOutput(true);
			//			pURLConnection->setRequestProperty(L"Connection",   L"keep-alive");
			pURLConnection->setRequestProperty(L"Content-Type", L"multipart/related");

			OutputStream& os =pURLConnection->getOutputStream();
			while (42)
			{
				int r=is.read();
				if(r<=-1)
					break;
				cout<<(char)r;
				os.write(r);
			}

			cout <<"\n-------------------\n end of submit write --------"<<endl;
			InputStream& is2=pURLConnection->getInputStream();
			cout <<"\n-------------------\n end of getInputStream --------"<<endl;
			while (42)
			{
				int r=is2.read();
				if(r<=-1)
					break;
				cout<<char(r);
			}

			cout <<" end of submit "<<endl;

			JDFDoc doc(1);
			JDFJMF root = doc.GetJMFRoot();
			JDFQuery q=root.AppendQuery(JDFMessage::Type_Status);
			JDFStatusQuParams qp=q.AppendStatusQuParams();
			qp.SetJobID("pp070730-1_Book0003_p1_Book0004_p1");
			qp.SetJobPartID("PP0.D");
			JDFSubscription sub=q.AppendSubscription();
			sub.SetURL("http://10.10.146.85/JDFUtility/dump");
			JDFDoc docResp=doc.Write2URL(dumpURL);
			cout<<docResp<<endl;
			cout<<"\n---------------------- done ---------------------------"<<endl;
			for(int i=120;i<100;i++)
			{
				JDFDoc dClean(1);
				JDFJMF root = doc.GetJMFRoot();
				JDFCommand c=root.AppendCommand(JDFMessage::Type_AbortQueueEntry);
				c.AppendQueueEntryDef().SetQueueEntryID(WString(i));
				JDFDoc docResp=doc.Write2URL(dumpURL);
				cout<<docResp<<endl;

			}

		}
		return 0; 

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
	}else if(1){
		JDFDoc doc(1);
		JDFJMF root = doc.GetJMFRoot();
		JDFCommand c=root.AppendCommand(JDFMessage::Type_Unknown);
		c.SetType("HDM:AR");
		KElement k=c.AppendElement("AR");
		k.SetAttribute("UNC","Foo");

		doc.Write2File("test.jmf");

		JDFDoc dc;
		dc.Parse("test.jmf",false);
		cout<<dc<<endl;
		JDFJMF newjmf=dc.GetJMFRoot();
		KString s=newjmf.GetCommand(0).GetElement("AR").GetAttribute("UNC");
		cout<<endl<<s<<endl;
	}else if(0){
		JDFDoc dc;
		dc.Parse("mimetest1.xml",false);
		cout<<dc<<endl;
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();         
		n.SetType("fnarf");
		cout<<n<<endl;
	}else if(0){
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


	}else if(1){
		cout<<"boo"<<endl;
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
		JDFColorantControl cc=n.AddParameter(JDFElement::elm_ColorantControl);
		JDFSeparationList sl=cc.AppendColorantOrder();
		sl.setSeparations(vWString("a b c"));

		JDFRunList rul=n.AddParameter(JDFElement::elm_RunList);
		rul.AddPartition(rul.PartIDKey_Separation,"cyan");
		rul.AddPartition(rul.PartIDKey_Separation,"magenta");
		JDFRunList rul2=rul.AddPartition(rul.PartIDKey_Separation,"yellow");
		rul2.AppendLayoutElement().AppendSeparationSpec().SetName("foo");
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

