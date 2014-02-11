#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>

#include "jdf/wrapper/JDF.h"
#include "jdf/util/myuti.h"
#include "JDFSimulator.h"

#include "MyArgs.h"
#include <iostream>

#ifdef WIN32
#include <io.h>
#endif

#ifdef __GNUC__
#include <unistd.h>
#define _access access
#endif

XERCES_CPP_NAMESPACE_USE

using namespace std;

//////////////////////////////////////////////////////////////////
namespace JDF{

	JDFParser*parser=0;

	class JDFPrintTalk : public JDFElement{
	public:
		
		//////////////////////////////////////////////////////////////////////
		// Constructors / Destructors  
		//////////////////////////////////////////////////////////////////////
		
		JDFPrintTalk():JDFElement(){};
		JDFPrintTalk(const KElement & other):JDFElement( other){};
		virtual ~JDFPrintTalk(){};
		bool init(){
			SetTimeStamp("timestamp");
			JDFElement header=GetCreateElement("Header");
			header.GetCreateElement("From").AppendText("default cxml header");
			header.GetCreateElement("To").AppendText("default cxml header");
			header.GetCreateElement("Sender").AppendText("default cxml header");
			return true;
		}
		JDFNode AddRequest(){
			JDFElement req=GetCreateElement("Request",L"",-1);
			JDFNode r=req.AppendElement("JDF");
			r.init();
			return r;
		}
		
		
	}; 
	
	//////////////////////////////////////////////////////////////////
	
	class MyResponse:public JDFResponse{
	public:
		MyResponse(KElement o):JDFResponse(o){};
		MyResponse():JDFResponse(){};
		~MyResponse(){};
		virtual bool IsQueryImplemented(JDFQuery q){
			WString s=q.GetType();
			if(!s.compare(L"Status")) return true;
			return false;
		}
	};
	
	//////////////////////////////////////////////////////////////////
	
	class MyRunList:public JDFRunList{
	public:
		MyRunList(KElement o):JDFRunList(){*this=o;};
		MyRunList():JDFRunList(){};
		~MyRunList(){};
		inline MyRunList &operator =(const KElement& other){
			KElement::operator=(other); 
			if(!IsValid(ValidationLevel_Construct)) 
				throw JDFException(L"Invalid constructor for MyRunList: "+GetNodeName());
			return *this;
		};
		
		virtual WString ValidNodeNames()const{
			WString s=JDFRunList::ValidNodeNames()+L",MyRunList,HDM:HDMRunList";
			vWString v=s.Tokenize(",");
			v.RemoveStrings("*:");
			s=v.GetString(",");
			return s;
		};
	};
	
	
	//////////////////////////////////////////////////////////////////
	
	class  SpecDoc :public JDFDoc{
	public:
		SpecDoc(int docType=0):JDFDoc(docType){};
		SpecDoc(const XMLDoc & d):JDFDoc(d){};
		~SpecDoc(){};
		int DoExample(int i, WString fName="");
		void setnodecustomer(JDFNode p, JDFCompany company, WString b);
		
	protected:
		int DoAudits();
		int DoSimple();
		int DoSimplePartition();
		int DoCPrint();
		int DoCut();
		int DoFold();
		int DoLayoutPreparation();
		int DoIDPrint();
		int DoColorConv();
		int DoBrochure();
		int DoQuote(WString fileName, double base=1000.);
		int PrepareQuote();
		int SelectQuote();
		int DoDeliver();
		int DoArtwork();
		int DoRunList();
		int PrepareQuote2();
		int DoQuote2();
		int DoScreen();
		int DoQuery();
		int DoResponse();
		int DoQuery2();
		int DoResponse2(int nn);
		int DoTest();
		int DoBible();
		int DoPO(WString fileName, int iAccept=0);
		int DoConfirm(WString fileName);
		int DoInvoice(WString fileName);
		int DoExtendRun();
		int DoBundle();
		int DoPreview();
		int DoRefOrient();
		int DoFoldCatalog();
		
	};
}
//////////////////////////////////////////////////////////////////

using namespace JDF;

int main(int argC, char* argV[]){

	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	// this bracket is needed because terminate is otherwise called before the document goes out of focus
	{
	 parser=new JDFParser;

		// trivial argument handling
		MyArgs args(argC,argV,"e","fln");
		
		// Watch for special case help request
		WString usage="DomJDF: JDF creator simulation;\nArguments: -f: first example #\n-l last example\n1: Simple node\n2: Conventional Printing\n3: ColorSpaceConversion\n-n FileNmae to process";
		if ((argC>1)&&(strcmp(argV[1], "-?") == 0)){
			cerr<< args.Usage(usage);
			return 0;
		}
		WString fName=args.Parameter('n');
		WString ks="abc";
		WString ws(L"aaa");
		SpecDoc gdoc;
		// setup indentation
		
		int iex=args.IntParameter('f',1);
		int iexmax=args.IntParameter('l',999)+1;
		// special case: 0=all
		if(iex>iexmax){
			iex=1;
			iexmax=999;
		}else if(iex==iexmax){
			iexmax++;
		};
		// loop over chosen examples
		for(;iex<iexmax;iex++){
			int iDoc=0;
			if(((iex>8)&&(iex<12))||(iex>=22)) 
				iDoc=1;
			if((iex>15)&&(iex<22)) 
				iDoc=1;
			if(iex>=27) 
				iDoc=0;
			SpecDoc gdoc(iDoc);
			
			JDFElement root=gdoc.GetRoot();
			if(iDoc==0){
				JDFNode r=root;
				r.init(true);
			}else if (iDoc==1){
				JDFJMF m=root;
				m.init();
			}
			cout<<"\n\n**************** "<<iex<<" ********************\n\n";
			cout<<1<<root;
			if(gdoc.DoExample(iex,fName)==-1) break;
			cout<<2<<root;
			root.EraseEmptyNodes();
			WString outFile=WString("testjdf")+WString(iex)+WString(".jdf");
			remove(outFile.peekBytes());
			//cout<<gdoc;
			gdoc.Write2File(outFile.peekBytes());
		}
		delete parser;
	} // terminate focus
	JDF::PlatformUtils::Terminate();
    XMLPlatformUtils::Terminate();
	return 0;
}


/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoExample(int i,WString fName){
	switch(i){
	case 0: return DoTest();
	case 1: return DoSimple();
	case 2: return DoCPrint();
	case 3: return DoColorConv();
	case 4: return DoBrochure();
	case 5: return DoSimplePartition();
		//	case 6: return DoPerform2();
		//	case 5: return 0;
	case 6: return 0;
	case 7: return PrepareQuote();
//	case 8: return DoQuote("TestJDF7.jdf",1000);
//	case 9: return SelectQuote();
//	case 10: return DoDeliver();
	case 11: return DoArtwork();
	case 12: return DoRunList();
//	case 13: return PrepareQuote2();
//	case 14: return DoQuote2();
	case 15: return DoScreen();
	case 16: return DoQuery();
	case 17: return DoResponse();
	case 18: return DoQuery2();
	case 19: return DoResponse2(0);
	case 20: return DoResponse2(1);
	case 21: return DoResponse2(2);
//	case 22: return DoBible();
//	case 23: return DoQuote(fName.empty()?"TestJDF22.jdf":fName,5000);
//	case 24: return DoPO(fName.empty()?"TestJDF23.jdf":fName,1);
//	case 25: return DoConfirm(fName.empty()?"TestJDF24.jdf":fName);
//	case 26: return DoInvoice(fName.empty()?"TestJDF24.jdf":fName);
	case 27: return DoIDPrint();
	case 28: return DoCut();
	case 29: return DoFold();
	case 30: return DoAudits();
	case 31: return DoBundle();
	case 32: return	DoLayoutPreparation();
	case 33: return DoExtendRun();
	case 34: return DoPreview();
	case 35: return DoRefOrient();
	case 36: return DoFoldCatalog();
		
	}
	return i<40 ? 0 : -1;
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoTest(){
	JDFNode r=GetRoot();
	JDFComment c=r.AppendComment();
	c.AppendText("This is a comment");
	JDFNode p=r;
	p.SetType("Product");
	JDFResource pa=p.AddParameter("SomeInputResource");
	pa.AddPartitions(pa.PartIDKey_Separation,WString("C M Y K").Tokenize(" "));
	for(int i=0;i<4;i++){
		pa.GetPartition(pa.PartIDKey_Separation,WString("C M Y K").Tokenize(" ")[i]).GetCreateElement("Elem1");
	}
	JDFResource rer=pa.GetCreateElement("ElemRoot");
	rer.SetAttribute("key1",1);
	JDFResource p2=pa.GetPartition(pa.PartIDKey_Separation,"Y");
	p2.GetCreateElement("ElemRoot").SetAttribute("key1",2);;
	JDFResource po=p.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
	rer.RefElement(po);
	p2=pa.GetPartition(pa.PartIDKey_Separation,"M");
	JDFResource er=p2.GetCreateElement("ElemRoot");
	er.SetAttribute("ns:NS",5,"testns");
	cout<<er.ToString()<<p2.ToString();
	cout<<er.GetAttribute("NS","testns")<<endl;
	KElement e1=pa.GetCreateElement("e1");
	e1.SetAttribute("a","a");
	e1.AppendText("test");
	KElement e2=pa.AppendElement("e1");
	e2.SetAttribute("a","a");
	e2.AppendText("test");
	cout <<e1.IsEqual(e2)<<endl;
	
	return 1;
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoSimple(){
	JDFNode r=GetRoot();
	JDFComment c=r.AppendComment();
	c.AppendText("This is a comment");
	JDFNode p=r;
	p.init();
	p.SetEnumType(JDFNode::Type_ImageSetting);
	JDFImageSetterParams inputParams=p.AppendMatchingResource(JDFNode::elm_ImageSetterParams,JDFNode::ProcessUsage_AnyInput);
	cout<<p<<endl;
	JDFMedia inputMedia=p.AppendMatchingResource(JDFNode::elm_Media,JDFNode::ProcessUsage_AnyInput);
	JDFExposedMedia outputMedia=p.AppendMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyOutput);
	outputMedia.RefElement(inputMedia);
	JDFRunList inputRunList=p.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);
	return 1; 
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoSimplePartition(){
	DoSimple();
	JDFNode p=GetRoot();
	cout<<p<<endl;
	JDFMedia inputMedia=p.GetMatchingResource(JDFNode::elm_Media);
	cout<<inputMedia;
	inputMedia.AddPartitions(JDFResource::PartIDKey_Separation,vWString("Cyan Magenta Yellow Black"));
	JDFExposedMedia outputMedia=p.GetMatchingResource(JDFNode::elm_ExposedMedia);
	outputMedia.AddPartitions(JDFResource::PartIDKey_Separation,vWString("Cyan Magenta Yellow Black"));
	return 1; 
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoIDPrint(){
	
	// define a vector of separation strings
	vWString vsepstring=WString("Cyan,Magenta,Yellow,Black,Heidelberg Spot Blau").Tokenize(",");
	// define a vector of separation strings
	vWString vLocString=WString("Tray 1,Tray 2").Tokenize(",");
	
	// set up root node
	JDFNode r=GetRoot();
	JDFNode p=r;
	p.SetType("IDPrinting");
	
	
	JDFMedia media=p.AddResource("Media",JDFResource::Class_Consumable,true);
	media.SetMediaType(JDFMedia::MediaType_Paper);
	media.SetAvailable();
	media.AddPartitions(media.PartIDKey_Location,vLocString);
	media.SetDimension(WString("700 900"));
	mAttribute mmap;
	mmap.AddPair("Location","Tray 1");
	JDFMedia mp=media.GetPartition(mmap);
	mp.SetAttribute("Weight",90);
	mmap.clear();
	mmap.AddPair("Location","Tray 2");
	mp=media.GetPartition(mmap);
	mp.SetAttribute("Weight",120);
	//	mp.SetWeight(120);
	
	JDFRunList rli=p.AddParameter("RunList",true);
	JDFRunList rr=rli.AddRun("Cover.pdf",0,0);
	rr=rli.AddRun("File2.pdf",0,7);
	rr=rli.AddRun("File2.pdf",0,0);
	
	JDFIDPrintingParams idp=p.AddResource("IDPrintingParams",JDFResource::Class_Parameter,true);
	JDFIDPLayout idl=idp.GetCreateIDPLayout();
	idl.SetNumberUp(JDFXYPair("2 2"));
	
	JDFColorantControl cc=p.AddResource("ColorantControl",JDFResource::Class_Parameter,true);
	JDFColorantControl ccp=cc.AddPartition(cc.PartIDKey_DocSheetIndex,"0");
	ccp.SetProcessColorModel("DeviceN");
	ccp=cc.AddPartition(cc.PartIDKey_DocSheetIndex,"1");
	ccp.SetProcessColorModel("DeviceCMYK");
	ccp=cc.AddPartition(cc.PartIDKey_DocSheetIndex,"2~-1");
	ccp.SetProcessColorModel("DeviceGray");
	
	JDFMediaSource ms=idp.GetCreateMediaSource();
	ms.RefElement(media);
	ms.SetMediaLocation("Tray 1");
	
	JDFIDPCover cover=idp.GetCreateCover(0);
	cover.SetCoverType(cover.CoverType_Front);
	cover.SetFrontSide(true);
	idl=cover.GetCreateElement("IDPLayout");
	idl.SetNumberUp(JDFXYPair("1 1"));
	
	ms=cover.GetCreateMediaSource();
	ms.RefElement(media);
	ms.SetMediaLocation("Tray 2");
	
	
	return 1;
	
}
/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoCut(){
	JDFNode r=GetRoot();
	JDFNode p=r;
	p.SetType("Cutting");
	return 1;
	
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoLayoutPreparation(){
	JDFNode root=GetRoot();
	JDFNode p=root;
	p.SetType("LayoutPreparation");
	JDFResource r=p.AddParameter("LayoutPreparationParams");
	return 1;
	
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoFold(){
	JDFNode r=GetRoot();
	JDFNode p=r;
	p.SetType("Folding");
	JDFFoldingParams fp=p.AddParameter("FoldingParams",true,r);
	fp.SetStatus(JDFResource::Status_Incomplete);
	return 1;
	
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoCPrint(){
	int i;
	// set up root node
	JDFNode r=GetRoot();
	r.SetType("ProcessGroup");
	JDFNode g=r;
	JDFNode p=g.AddProcess("ConventionalPrinting");
	p.SetJobPartID("Part1");
	
	// define a vector of separation strings
	vWString vsepstring=WString("Cyan,Magenta,Yellow,Black,Heidelberg Spot Blau").Tokenize(",");
	
	// add and setup the input Plates
	JDFExposedMedia plate=p.AddHandling("ExposedMedia");
	plate.SetAvailable(); 
	plate.AddPartitions(plate.PartIDKey_Separation,vsepstring);
	vElement v=plate.GetLeaves();
	
	plate.SetBrand("HDM");
	JDFMedia media=plate.GetCreateMedia();
	media.SetMediaType(JDFMedia::MediaType_Plate);
	media.SetAvailable();
	media.SetDimensionInch(JDFXYPair(10,15));
	
	for(int i=0;i<v.size();i++){
		JDFExposedMedia pplate=v[i];
		pplate.SetProductID(WString("J1P1")+vsepstring[i]);
		pplate.SetDescriptiveName(WString("Platte ")+vsepstring[i]);
	}
	// add and setup the input Media
	media=p.AddResource("Media",JDFResource::Class_Consumable,true);
	media.SetMediaType(JDFMedia::MediaType_Paper);
	media.SetAttribute("Weight",120);
	//	media.SetWeight(120);
	media.SetDimensionInch(JDFXYPair(10,15));
	media.SetAvailable();
	
	
	// add a ConventionalPrintingParams resource
	JDFConventionalPrintingParams cpp=p.AddParameter("ConventionalPrintingParams",true);
	cpp.init();
	cpp.SetAvailable();
	
	cpp.SetPrintingType(JDFConventionalPrintingParams::PrintingType_SheetFed);
	cpp.SetDirectProof(true);
	cpp.SetDrying(cpp.Drying_On);
	cpp.SetWorkStyle(cpp.WorkStyle_Perfecting);
	cpp.SetFirstSurface(cpp.FirstSurface_Back);
	cpp.SetSpeed(42);
	
	cout<<cpp.ToString();
	cout<<cpp.IsValid()<<endl;
	WString s;
	
	vWString vfb= WString("Front,Back").Tokenize(",");
	
	cpp.AddPartitions(cpp.PartIDKey_Side,vfb);
	cout<<cpp;
	// define a map of attributes for part selection
	mAttribute mp;
	mp.AddPair(JDFResource::PartIDKeyString(cpp.PartIDKey_Side),"Front");
	
	// select the front side and set the appropriate attributes
	JDFConventionalPrintingParams sp=cpp.GetPartition(mp);
	cout<<sp;
	sp.SetAttribute("Powder",12.1);
	
	// create the separations for the front
	sp.AddPartitions(sp.PartIDKey_Separation,vsepstring);
	cout<<sp;
	
	// get the individual parts by number and modify appropriately
	JDFConventionalPrintingParams sep=sp.GetLeaves()[0];
	sep.SetModuleDrying(sep.Drying_IR);
	sep=sp.GetLeaves()[2];
	sep.SetModuleDrying(sep.Drying_IR);
	cout<<cpp;
	
	// grab the back side and repeat the above
	mp.clear();
	mp.AddPair(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Side),"Back");
	sp=cpp.GetPartition(mp);
	sp.SetPowder(8.5);
	sp.SetSeparation("Black");
	//	sp.AddPartitions("Separation",vsepstring);
	sp.GetCreateComment().AppendText("Note that the back side is black only");
	vmAttribute vmaps;
	mp.clear();
	mp.AddPair("Separation","Cyan");
	vmaps.push_back(mp);
	mp.clear();
	mp.AddPair("Separation","Black");
	vmaps.push_back(mp);
	
	cpp.ReducePartitions(vmaps);
	
	
	
	JDFColorantControl cc=p.AddParameter("ColorantControl",true);
	cc.SetAvailable();
	cc.AddPartitions(cc.PartIDKey_Side,vfb);
	JDFColorantControl c1=cc.GetPartition(cc.PartIDKey_Side,"Front");
	c1.SetProcessColorModel("DeviceCMYK+Spot");
	
	JDFSeparationList dco=c1.GetCreateDeviceColorantOrder();
	for(int kk=0;kk<vsepstring.size();kk++){
		dco.GetCreateSeparationSpec(kk).SetName(vsepstring[kk]);
	}
	c1=cc.GetPartition(cc.PartIDKey_Side,"Back");
	c1.SetProcessColorModel("DeviceGray");
	dco=c1.GetCreateDeviceColorantOrder();
	dco.GetCreateSeparationSpec().SetName(vsepstring[3]);
	
	// set up color pool
	JDFColorPool colorPool=p.AddParameter("ColorPool",true);
	WString cmyks="1 0 0 0,0 1 0 0,0 0 1 0,0 0 0 1,0.7 0.7 0.3 0.7";
	for(int iCol=0;iCol<vsepstring.size();iCol++){
		JDFColor col = colorPool.AppendColor();
		col.SetName(vsepstring[iCol]);
		col.SetCMYK(cmyks.Tokenize(",")[iCol]);
	}
	
	// define inks
	JDFInk ink=p.AddConsumable("Ink",true);
	ink.SetAvailable();
	ink.SetBrand("NasenRotz");
	//ink.SetMediaType(ink.MediaType_Coated);
	ink.AddPartitions(ink.PartIDKey_Separation,vsepstring);
	JDFResourceLink inkLink=p.GetLink(ink,true);
	JDFAmountPool amountPool=inkLink.AppendAmountPool();
	WString amounts="1000 1200 777 3000 300 33";
	vElement vInk=ink.GetLeaves();
	for(int iCol=0;iCol<vsepstring.size();iCol++){
		JDFInk ie=vInk[iCol];
		ie.SetColorName(vsepstring[iCol]);
		mAttribute sepMap;
		sepMap.AddPair("Separation",vsepstring[iCol]);
		JDFPartAmount pa=amountPool.AppendPartAmount(sepMap);
		pa.SetAmount((int)amounts.Token(iCol));
	}
	
	// add the output components
	JDFComponent comp=p.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
	vElement vComp=comp.AddPartitions(ink.PartIDKey_Condition,WString(L"Good Waste").Tokenize());

	comp.SetAmount(30000);
	comp.SetComponentType(comp.ComponentType_Sheet);
	((JDFComponent&)vComp[1]).SetIsWaste(true);
	
	// define some scheduling
	JDFNodeInfo ni=p.GetCreateNodeInfo();
	JDFDate d;
	ni.SetStart(d);
	d.SetOffset(7200);
	ni.SetEnd(d);
	ni.SetDueLevel(ni.DueLevel_Penalty);
	
	// define the customer
	JDFCustomerInfo cust=p.GetCreateCustomerInfo();
	cust.SetCustomerID(4711);
	cust.SetCustomerOrderID("4711-007");
	JDFCompany cmp=cust.GetCreateCompany();
	cmp.SetOrganizationName("MI5");
	JDFContact contact=cmp.GetCreateContact();
	contact.SetContactTypes(vWString("Customer"));
	JDFPerson person=contact.GetCreatePerson();
	person.SetFamilyName("Bond");
	person.SetFirstName("James");
	person.SetJobTitle("Her Majesties Favorite Spy");
	
	return 1;
}
/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoColorConv(){
	// set up the root process
	JDFNode r=GetRoot();
	JDFNode p=r;
	p.SetType("ColorSpaceConversion");
	
	// define the input runlist
	JDFRunList rli=p.AddParameter("RunList",true);
	rli.AddPDF("in/colortest.pdf");
	rli.init();
	rli.SetAvailable();
	// define the conversion parameters
	JDFColorSpaceConversionParams csp=p.AddParameter("ColorSpaceConversionParams",true);
	csp.init();
	csp.SetAvailable();
	csp.SetAttribute("FinalTargetDevice","File::SMProcessCMYK.icc");
	// at the moment this is simply hard-wired
	// define the sourceobjects
	vWString vcs=WString("ImagePhotographic ImageScreenShot SmoothShades,Text LineArt").Tokenize(",");
	vWString vUrl=WString("image.icc,text.icc").Tokenize(",");
	
	// create ColorSpaceConversion elements for each group of sourceobjects
	// and fill with dummy data
	for(int i=0;i<vcs.size();i++){
		JDFColorSpaceConversionOp csc=csp.AppendElement("ColorSpaceConversionOp");
		csc.SetOperation(csc.Operation_Convert);
		csc.SetSourceCS(csc.SourceCS_RGB);
		csc.SetAttribute("SourceObjects",vcs[i]);
		csc.SetAttribute("SourceProfile",WString("File::")+vUrl[i]);
		csc.SetAttribute("RenderingIntent","Perceptual");
	}
	
	JDFResource colorPool=p.AddParameter("ColorPool",true,r,false);
	colorPool.SetAvailable();
	WString Colors="Cyan Magenta Yellow Black Blue";
	WString cmyk="1 0 0 0,0 1 0 0,0 0 1 0,0 0 0 1,0.8 0.8 0 0";
	
	vWString vc=Colors.Tokenize(" ");
	for(int i=0;i<vc.size();i++){
		JDFElement color=colorPool.AppendElement("Color");
		color.SetAttribute("Name",vc[i]);
		color.SetAttribute("CMYK",cmyk.Tokenize(",")[i]);
	}
	
	JDFColorantControl cc=p.AddParameter("ColorantControl");
	cc.SetAvailable();
	cc.RefElement(colorPool);
	cc.SetProcessColorModel("DeviceCMYK");
	// clone the output runlist from the input run list
	JDFRunList rlo=p.AddParameter("RunList",false);
	rlo.init();
	rlo.AddPDF("out/colortest.pdf");	
	rlo.SetStatus(JDFResource::Status_Unavailable);
	return 3;
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoBrochure(){
	// set up the root process
	JDFNode r=GetRoot();
	JDFNode p=r;
	r.SetType("Product");
	p.SetJobPartID("Part1");
	JDFComponent comp=p.AppendMatchingResource(JDFNode::elm_Component,p.ProcessUsage_AnyOutput);
	comp.SetAttribute("Amount",10000);
	p.AppendMatchingResource(JDFNode::elm_BindingIntent,p.ProcessUsage_AnyInput);
	JDFProductionIntent pi=p.AppendMatchingResource(JDFNode::elm_ProductionIntent,p.ProcessUsage_AnyInput);
	JDFSpanPrintProcess sp=pi.AppendPrintProcess();
	sp.SetRange(sp.SpanPrintProcess_Gravure);
	JDFNode c1=p.AddProduct();
	c1.SetDescriptiveName("Cover");
	c1.SetJobPartID("Part2");
	
	comp=c1.AppendMatchingResource(JDFNode::elm_Component,c1.ProcessUsage_AnyOutput,p);
	p.LinkResource(comp);
	c1.AppendMatchingResource(JDFNode::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput);
	c1.AppendMatchingResource(JDFNode::elm_ColorIntent,JDFNode::ProcessUsage_AnyInput);
	JDFNode c2=p.AddProduct();
	c1.SetDescriptiveName("Insert");
	
	c2.SetJobPartID("Part3");
	comp=c2.AppendMatchingResource(JDFNode::elm_Component,c2.ProcessUsage_AnyOutput,p);
	p.LinkResource(comp);
	c2.AppendMatchingResource(JDFNode::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput);
	c2.AppendMatchingResource(JDFNode::elm_ColorIntent,JDFNode::ProcessUsage_AnyInput);
	
	return 0;
}


int SpecDoc::PrepareQuote(){
	
	JDFNode p=GetRoot();
	p.SetEnumType(JDFNode::Type_Product);
	vElement vQuotes;
	for(int i=0;i<2;i++) {
		vQuotes.push_back(p.AddProduct());
		p.SetDescriptiveName(WString("Product Definition # ")+(i+1));
	}
	
	JDFNode product=vQuotes[0];
	
	setnodecustomer(p,JDFResource(),"RFQ");
	p.SetType("Product");
	for(int i=0;i<1;i++) {
		JDFNode n=vQuotes[i];
		JDFComponent comp=n.AppendMatchingResource(JDFNode::elm_Component,n.ProcessUsage_AnyOutput);
		comp.SetAttribute("Amount",10000);
		n.SetJobPartID(WString("Quote")+(i+1));
		MyDate dat(1555555);
		
		//		JDFNode q=n.AddProduct(WString("Quote #")+(i+1));
		//		q.SetType("Request");
		JDFNode q=p;
		JDFIntentResource del=q.AppendMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput);
		JDFNameSpan nameI=del.GetCreateSpan("Method",JDFSpanBase::DataType_Name);
		nameI.SetPreferred("none");
		JDFElement DropIntent=del.AppendElement("DropIntent");
		JDFResource DropItemIntent=DropIntent.AppendElement("DropItemIntent");
		DropItemIntent.SetAttribute("Amount",10000);
		DropItemIntent.SetAttribute("AdditionalAmount",1000);
		DropItemIntent.RefElement(comp);
		
	}
	
	JDFIntentResource LayoutIntent=product.AppendMatchingResource(JDFNode::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput,p);
	JDFXYPairSpan xyInt=LayoutIntent.GetCreateSpan("Dimensions",JDFSpanBase::DataType_XYPair);
	xyInt.SetPreferred(8.5*72,11*72);
	xyInt.AddRange(8*72, 10*72, 9*72, 12*72);
	JDFIntegerSpan intInt=LayoutIntent.GetCreateSpan("Pages",JDFSpanBase::DataType_Integer);
	intInt.SetPreferred(16);
	
	for(int i=0;i<2;i++) {
		JDFNode n=vQuotes[i];
		JDFResourceLink l=n.LinkResource(LayoutIntent);
	}
	
	JDFIntentResource MediaIntent=product.AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput,p);
	JDFNameSpan namInt=MediaIntent.GetCreateSpan("FrontCoatings",JDFSpanBase::DataType_Name);
	namInt.SetPreferred("none");
	
	JDFIntentResource part=MediaIntent.GetPartition(MediaIntent.PartIDKey_Option,"1",JDFResource::PartUsage_Implicit);
	namInt=part.GetCreateSpan("FrontCoatings",JDFSpanBase::DataType_Name);
	namInt.SetPreferred("glossy");
	
	
	namInt=MediaIntent.GetCreateSpan("BackCoatings",JDFSpanBase::DataType_Name);
	namInt.SetPreferred("none");
	
	for(int i=0;i<2;i++) {
		JDFNode n=vQuotes[i];
		JDFResourceLink l=n.LinkResource(MediaIntent);
		if(i==1) 
			l.SetPartition(MediaIntent.PartIDKey_Option,"1");
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////


int SpecDoc::PrepareQuote2(){
	
	JDFNode r=GetRoot();
	setnodecustomer(r,JDFResource(),"RFQ");
	JDFNodeInfo ni=r.GetNodeInfo();
	ni.SetAttribute("Currency","DEM");
	
	
	vElement vQuotes;
	JDFNode product=r;
	for(int i=0;i<6;i++) {
		vQuotes.push_back(product.AddProduct());
		product.SetDescriptiveName(WString("Product Definition # ")+(i+1));
	}
	
	JDFIntentResource LayoutIntent=product.AppendMatchingResource(JDFNode::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput,r);
	
	JDFNumberSpan numInt;
	
	JDFXYPairSpan xyInt=LayoutIntent.GetCreateSpan("Dimensions",JDFSpanBase::DataType_XYPair);
	xyInt.SetPreferred(8.5*72,11*72);
	xyInt.AddRange(8*72, 10*72, 9*72, 12*72);
	
	JDFIntegerSpan intInt=LayoutIntent.GetCreateSpan("Pages",JDFSpanBase::DataType_Integer);
	intInt.SetPreferred(32);
	
	JDFIntentResource p=LayoutIntent.GetPartition(JDFResource::PartIDKey_Option,"3",JDFResource::PartUsage_Implicit);
	intInt=p.GetCreateSpan("Pages",JDFSpanBase::DataType_Integer);
	intInt.SetPreferred(36);
	
	for(int i=0;i<6;i++) {
		JDFNode n=vQuotes[i];
		JDFResourceLink l=n.LinkResource(LayoutIntent);
		if(i==3) l.SetPartition(JDFResource::PartIDKey_Option,"3");
	}
	
	
	JDFIntentResource MediaIntent=product.AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput,r);
	JDFNameSpan namInt=MediaIntent.GetCreateSpan("FrontCoatings",JDFSpanBase::DataType_Name);
	
	namInt.SetPreferred("none");
	
	p=MediaIntent.GetPartition(JDFResource::PartIDKey_Option,"1",JDFResource::PartUsage_Implicit);
	namInt=p.GetCreateSpan("FrontCoatings",JDFSpanBase::DataType_Name);
	namInt.SetPreferred("glossy");
	
	p=MediaIntent.GetPartition(JDFResource::PartIDKey_Option,"2",JDFResource::PartUsage_Implicit);
	namInt=p.GetCreateSpan("FrontCoatings",JDFSpanBase::DataType_Name);
	namInt.SetPreferred("satin");
	
	namInt=MediaIntent.GetCreateSpan("BackCoatings",JDFSpanBase::DataType_Name);
	namInt.SetPreferred("none");
	
	for(int i=0;i<6;i++) {
		JDFNode n=vQuotes[i];
		JDFResourceLink l=n.LinkResource(MediaIntent);
		if(i==1) l.SetPartition(JDFResource::PartIDKey_Option,"1");
		if(i==2) l.SetPartition(JDFResource::PartIDKey_Option,"2");
	}
	
	JDFIntentResource ColorIntent=product.AppendMatchingResource(JDFNode::elm_ColorIntent,JDFNode::ProcessUsage_AnyInput,r);
	JDFElement cu=ColorIntent.AppendElement("ColorsUsed");
	cu.AppendElement("SeparationSpec").SetAttribute("Name","Black");
	cu.AppendElement("SeparationSpec").SetAttribute("Name","Spot");
	
	p=ColorIntent.GetPartition(JDFResource::PartIDKey_Option,"4",JDFResource::PartUsage_Explicit);
	cu=p.AppendElement("ColorsUsed");
	cu.AppendElement("SeparationSpec").SetAttribute("Name","Black");
	
	for(int i=0;i<6;i++) {
		JDFNode n=vQuotes[i];
		JDFResourceLink l=n.LinkResource(ColorIntent);
		if(i==4) l.SetPartition(JDFResource::PartIDKey_Option,"4");
	}
	
	
	
	JDFResource company=product.AddParameter("Company",true,product,false);
	
	JDFAddress address=company.AppendElement("Contact").AppendElement("Address");
	address.SetCity("Hamburg");
	address.SetCountry("Germany");
	address.SetPostalCode("24000");
	
	for(int i=0;i<6;i++) {
		JDFNode n=vQuotes[i];
		JDFComponent comp=n.AppendMatchingResource(JDFNode::elm_Component,n.ProcessUsage_AnyOutput);
		comp.SetAttribute("Amount",10000);
		JDFIntentResource delivRes=product.AppendMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput,r);
		JDFResourceLink l=product.LinkResource(delivRes);
		
		JDFNameSpan nameI=delivRes.GetCreateSpan("Method",JDFSpanBase::DataType_Name);
		nameI.AddRange("SurfaceMail");
		nameI.AddRange("AirMail");
		
		JDFIntentResource drop=delivRes.AppendElement("DropIntent");
		if(i!=5) drop.RefElement(company);
		JDFTimeSpan timInt=drop.GetCreateSpan("Earliest",JDFSpanBase::DataType_Duration);
		JDFDate dat(555555);
		JDFDate dat2(655555);
		timInt.SetRange(JDFDateTimeRange(dat,dat2));
		JDFIntentResource package=drop.AppendElement("DropItemIntent");
		JDFIntegerSpan nII=package.GetCreateIntegerSpan("Amount");
		nII.SetPreferred(10000);
		
		package.RefElement(comp);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoQuote(WString fileName, double base){
	parser->Parse(fileName,false,true);
	XMLDoc doc=parser->GetRoot();
	
	JDFNode r=GetJDFRoot();
	for(int i=0;;i++){
		JDFNode n=r;
		JDFIntentResource ri=n.GetMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput,mAttribute(),i);
		if(ri.isNull()) break;
		
		ri.PreferredToActual();
		JDFElement q=ri.GetElement("Quote",true);
		q.SetAttribute("Price",base*(i+1));
		q.SetAttribute("AdditionalPrice",base*0.05*(i+1));
		JDFElement q2=q.AppendElement("Quote");
		q2.SetAttribute("item","Processing");
		q2.SetAttribute("Price",base*(i+1));
		q2.SetAttribute("AdditionalPrice",base*0.05*(i+1));
		q2=q.AppendElement("Quote");
		q2.SetAttribute("item","shipping");
		q2.SetAttribute("HasPrice",false);
	}		
	vElement vJDF=r.GetChildrenByTagName("JDF",L"",mAttribute(),false);	

	JDFNodeInfo ni=r.GetCreateNodeInfo();
	/*
	ni.UpdateBusiness(ni.BusinessObject_Quote,"QuoteID");
	ni.GetElement("BusinessInfo").GetElement("Quote").RemoveAttribute("LastQuote");
	*/
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
int SpecDoc::DoPO(WString fileName, int  iAccept){
	
	parser->Parse(fileName,false,true);
	*this=parser->GetRoot();
	
	JDFNode r=GetJDFRoot();
	for(int i=0;;i++){
		JDFNode n=r;
		JDFIntentResource ri=n.GetMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput,mAttribute(),i);
		
		if(ri.isNull()) break;
		ri.SetAttribute("Accepted",i==iAccept);
	}		
	JDFNodeInfo ni=r.GetCreateNodeInfo();
	ni.UpdateBusiness(ni.BusinessObject_PO,"Purchase Order ID");
	//	r.SetStatus(r.Status_quoted);
	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
int SpecDoc::DoConfirm(WString fileName){
	
	parser->Parse(fileName,false,true);
	*this=parser->GetRoot();
	
	JDFNode r=GetJDFRoot();
	JDFNodeInfo ni=r.GetCreateNodeInfo();
	ni.UpdateBusiness(ni.BusinessObject_Confirmation,"Confirmation ID");
	for(int i=0;;i++){
		JDFNode n=r;
		JDFIntentResource ri=n.GetMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput,mAttribute(),i);
		
		if(ri.isNull()) break;
		if(!ri.GetBoolAttribute("Accepted")) {
			ri.DeleteNode();
			i--;
		}
	}		
	//	r.SetStatus(r.Status_quoted);
	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
int SpecDoc::DoInvoice(WString fileName){
	
	parser->Parse(fileName,false,true);
	*this=parser->GetRoot();
	
	JDFNode r=GetJDFRoot();
	JDFNodeInfo ni=r.GetCreateNodeInfo();
	ni.UpdateBusiness(ni.BusinessObject_Invoice,"Invoice ID");
	for(int i=0;;i++){
		JDFNode n=r;
		JDFIntentResource ri=n.GetMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput,mAttribute(),i);
		vElement drops=ri.GetChildrenByTagName("DropIntent");
		for(int d=0;d<drops.size();d++){
			JDFElement r=drops[d];
			vElement dropitems=r.GetChildrenByTagName("DropItemIntent");
			for(int di=0;di<dropitems.size();di++){
				JDFElement r=dropitems[di];
				r.RemoveAttribute("AdditionalAmount");
				r.SetAttribute("Amount",(int)r.GetRealAttribute("Amount")*1.02);
			}
		}
		
		if(ri.isNull()) break;
		if(!ri.GetBoolAttribute("Accepted")) {
			ri.DeleteNode();
			i--;
		}
		
		JDFElement quote=ri.GetElement("Quote");
		double sum=quote.GetRealAttribute("Price");
		vElement qc=quote.GetChildElementVector("Quote");
		for(int ii=0;ii<qc.size();ii++){
			qc[ii].RemoveAttribute("AdditionalPrice");
			if (!qc[ii].GetBoolAttribute("HasPrice",true)){
				qc[ii].SetAttribute("HasPrice",L"",true);
				qc[ii].SetAttribute("Price",(int)(sum*0.1));
				sum*=1.1;
			}
		}
		quote.SetAttribute("Price",(int)sum);
	}		
	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoQuote2(){
	parser->Parse("TestJDF13.jdf",false,true);
	*this=parser->GetRoot();
	
	
	JDFNode r=GetRoot();
	JDFNode p=r;
	
	
	for(int i=0;;i++){
		WString jobID="Q";
		jobID+=i;
		JDFNode n=r.GetJobPart(jobID);
		if(n.isNull()) break;
		//		n.SetStatus(n.Status_quoted);
		
		JDFElement nodeInfo=n.GetElement("DeliveryIntent");
		JDFElement q=nodeInfo.GetElement("Quote",true);
		q.SetAttribute("Amount",10000*((i>4)?10:1));
		q.SetAttribute("AdditionalAmount",1000*((i>4)?10:1));
		q.SetAttribute("Price",2000*(i+1));
		q.SetAttribute("AdditionalPrice",100*(i+1));
		
		
		JDFIntentResource LayoutIntent=n.GetMatchingResource(JDFNode::elm_LayoutIntent);
		cout<<LayoutIntent;
		JDFNumberSpan numInt=LayoutIntent.GetCreateSpan("Height",JDFSpanBase::DataType_Number);
		numInt.SetActual(11*72);
		numInt=LayoutIntent.GetCreateNumberSpan("Width");
		numInt.SetActual(8.5*72);
		JDFIntegerSpan intInt=LayoutIntent.GetCreateSpan("Pages",JDFSpanBase::DataType_Integer);
		
		intInt.SetActual(32);
		JDFIntentResource part=LayoutIntent.GetPartition(JDFResource::PartIDKey_Option,"3");
		intInt=part.GetIntegerSpan("Pages");
		intInt.SetActual(36);
		
		
		JDFIntentResource MediaIntent=n.GetMatchingResource(JDFNode::elm_MediaIntent);	
		MediaIntent.PreferredToActual("FrontCoatings");
		
	}
	//	r.SetStatus(r.Status_quoted);
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////

int SpecDoc::SelectQuote(){
	parser->Parse("TestJDF8.jdf",false,true);
	*this=parser->GetRoot();
	
	JDFNode r=GetRoot();
	vElement v=r.GetChildElementVector();
	JDFNodeInfo ni=r.GetNodeInfo();
	ni.SetAttribute("QuoteSelection",2);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoDeliver(){
	
	JDFPrintTalk pt=GetRoot();
	pt.init();
	JDFNode r=pt.AddRequest();
	JDFNode p=r;
	setnodecustomer(r,JDFResource(),"RFQ");
	
	
	
	JDFResource company=r.AddParameter("Company",true,r,false);
	JDFAddress address=company.AppendElement("Contact").AppendElement("Address");
	address.SetCity("Kiel");
	address.SetCountry("Germany");
	address.SetPostalCode("24113");
	
	/*
	JDFIntentResource adi=p.AppendMatchingResource(JDFNode::elm_("ArtDeliveryIntent");
	adi.AppendComment("This is a most simple artdeliveryintent for those who have no clue except that it's half digital, half analog");
	JDFIntentResource ad1=adi.AppendElement("ArtDelivery");
	ad1.SetAttribute("ArtDeliveryType","ImposedFilm"); 
	ad1.SetAttribute("PageList","0~1 6~7");
	ad1=adi.AppendElement("ArtDelivery");
	ad1.SetAttribute("ArtDeliveryType","RunList"); 
	ad1.SetAttribute("PageList","2~5");
	*/	
	JDFNode pp1=r;
	pp1.SetEnumType(JDFNode::Type_Product);
	pp1=pp1.AddProduct();
	pp1.SetDescriptiveName("Details first product");
	JDFComponent c1=pp1.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,r);
	
	JDFIntentResource dr1=pp1.AppendMatchingResource(JDFNode::elm_ArtDeliveryIntent,JDFNode::ProcessUsage_AnyInput);
	
	JDFIntentResource d1=dr1.AppendElement("ArtDelivery");
	d1.SetAttribute("ArtDeliveryType","ImposedFilm"); 
	
	dr1.RefElement(company);
	d1.SetAttribute("PageList","0~3");
	
	JDFExposedMedia xm=pp1.AddHandling("ExposedMedia",true);
	xm.SetAttribute("ColorType","Color");
	xm.SetAvailable();
	
	JDFMedia m=xm.AppendElement("Media");
	m.SetMediaType(JDFMedia::MediaType_Film);
	d1.RefElement(xm);
	pp1=r;
	pp1=pp1.AddProduct();
	pp1.SetDescriptiveName("Details second product");
	JDFComponent c2=pp1.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,r);
	dr1=pp1.AppendMatchingResource(JDFNode::elm_ArtDeliveryIntent,JDFNode::ProcessUsage_AnyInput);
	d1=dr1.AppendElement("ArtDelivery");
	d1.SetAttribute("ArtDeliveryType","RunList"); 
	d1.SetAttribute("PageList","0~3");
	
	JDFRunList rl=pp1.AddParameter("RunList",true);
	rl.SetAttribute("NPage",4);
	WString vs="Cyan,Magenta,Yellow,Black,SpotGreen";
	JDFRunList ru=rl.AddSepRun("Cyan.pdf,Magenta.pdf,Yellow.pdf,Black.pdf,Green.pdf",vs,0,4);
	ru.AppendComment().AppendText("now use all the details of run elements that you like");
	
	d1.RefElement(rl);
	JDFNameSpan nameI=dr1.GetCreateNameSpan("Method");
	nameI.SetPreferred("eMail");
	
	
	/// delivery + quote stuff 
	JDFNode deliv[3];
	for(int i=0;i<3;i++){
		WString s123=WString("First Second Third").Tokenize(" ")[i];
		JDFIntentResource delivRes=p.AppendMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput);
		delivRes.AppendComment().AppendText(s123+L" quote delivery option");
		nameI=delivRes.GetCreateNameSpan("Method");
		nameI.SetPreferred("none");
		JDFIntentResource drop=delivRes.AppendElement("DropIntent");
		JDFTimeSpan timInt=drop.GetCreateTimeSpan("Earliest");
		JDFDate dat(555555);
		JDFDate dat2(655555);
		timInt.SetRange(JDFDateTimeRange(dat,dat2));
		drop.RefElement(company);
		
		JDFIntentResource package=drop.AppendElement("DropItemIntent");
		package.SetAttribute("AdditionalAmount",1000);
		if(i%2){
			package.RefElement(c2);
			package.SetAttribute("Amount",7500);
			package.SetAttribute("AdditionalAmount",1000);
		}else{
			package.RefElement(c1);
			package.SetAttribute("Amount",5000);
		}
		if(i==2){
			JDFIntentResource package=drop.AppendElement("DropItemIntent");
			package.RefElement(c2);
			package.SetAttribute("Amount",7500);
			package.SetAttribute("AdditionalAmount",1000);
		}
		
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

int SpecDoc::DoArtwork(){
	JDFPrintTalk pt=GetRoot();
	pt.init();
	JDFNode r=pt.AddRequest();
	
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

int SpecDoc::DoRunList(){
	JDFNode rt=GetRoot();
	JDFNode p=rt;
	p.SetType("Imposition");
	
	JDFRunList rl=p.AddParameter("RunList");
	rl.SetNPage(10);
	WString vs="Cyan Magenta Yellow Black SpotGreen";
	JDFRunList r=rl.AddSepRun("Cyan.pdf Magenta.pdf Yellow.pdf Black.pdf Green.pdf",vs,0,1,true," ");
	r.InsertAt("Comment",0).AppendText("Preseparated Runs in multiple files\nAll LayoutElements are inline resources");
	
	JDFLayoutElement layoutelem=p.AddParameter("LayoutElement");
	JDFFileSpec fileSpec=layoutelem.GetCreateFileSpec();
	fileSpec.SetURL("PreSepCMYKG.pdf");
	r=rl.AddSepRun(layoutelem,vs,0,2,true," ");
	r.InsertAt("Comment",0).AppendText("Preseparated Runs in one file CMYKGCMYKG\nLayoutElements are inter-resource links");
	
	r=rl.AddSepRun(layoutelem,"Cyan Yellow Black Green",10,1,true," ");
	r.InsertAt("Comment",0).AppendText("No Magenta, the missing sep does not exist as a page");
	
	r=rl.AddSepRun(layoutelem,vs,14,2,true," ");
	r.InsertAt("Comment",0).AppendText("Continuation of Preseparated Runs in one file CMYKGCMYKG - the missing sep of the previous page does not exist as a page");
	
	
	layoutelem=p.AddParameter("LayoutElement");
	fileSpec=layoutelem.GetCreateFileSpec();	
	fileSpec.SetURL("PreSepCCMMYYKKGG.pdf");
	r=rl.AddSepRun(layoutelem,vs,0,2,false," ");
	r.InsertAt("Comment",0).AppendText("Preseparated Runs in one file CCMMYYKKGG");
	
	r=rl.AddRun("Combined.pdf",0,1);
	r.InsertAt("Comment",0).AppendText("Combined Runs in one file ");
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7


void SpecDoc::setnodecustomer(JDFNode p, JDFCompany company, WString busTyp){
	
	// define the customer
	JDFCustomerInfo cust=p.GetCreateCustomerInfo();
	cust.SetAttribute("CustomerID",4711);
	cust.SetAttribute("CustomerOrderID","4711-007");
	if(company.isNull()){
		company=p.AddParameter("Company",true,p,false);
		company.SetAttribute("OrganizationName","MI5");
		JDFElement cust=company.AppendElement("Contact");
		cust.SetAttribute("ContactType","Customer");
		cust=cust.AppendElement("Person");
		cust.SetAttribute("FamilyName","Bond");
		cust.SetAttribute("FirstName","James");
		cust.SetAttribute("JobTitle","Her Majesties Favorite Spy");
	}
	cust.RefElement(company);
	
	
	JDFNodeInfo nodeInfo=p.GetCreateNodeInfo();
	nodeInfo.SetAttribute("LastEnd",MyDate(2555555).DateTimeISO());
	JDFElement bi=nodeInfo.GetCreateElement("BusinessInfo");
	bi=bi.GetCreateElement("RFQ");
	bi.SetAttribute("BusinessID","RFQ_ID");
	bi.SetAttribute("LastQuote",MyDate(555555).DateTimeISO());
	bi.SetAttribute("Currency","DEM");
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

int SpecDoc::DoScreen(){
	JDFNode r=GetRoot();
	JDFNode p=r;
	vElement vQuotes;
	
	JDFNode product=p;
	
	p.SetType("Product");
	cout<<p;
	JDFComponent comp=product.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
	comp.SetAttribute("Amount",10000);
	MyDate dat(1555555);
	
	
	JDFIntentResource LayoutIntent=product.AppendMatchingResource(JDFNode::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput,r);
	JDFXYPairSpan xyInt=LayoutIntent.GetCreateSpan("Dimensions",JDFSpanBase::DataType_XYPair);
	xyInt.SetPreferred(8.5*72,11*72);
	xyInt.AddRange(8*72, 10*72, 9*72, 12*72);
	JDFIntegerSpan intInt=LayoutIntent.GetCreateIntegerSpan("Pages");
	intInt.SetPreferred(16);
	
	JDFResourceLink l=product.LinkResource(LayoutIntent);
	
	JDFIntentResource MediaIntent=product.AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput,r);
	JDFNameSpan namInt=MediaIntent.GetCreateNameSpan("FrontCoatings");
	namInt.SetPreferred("none");
	
	JDFIntentResource part=MediaIntent.GetCreatePartition(JDFResource::PartIDKey_Option,"1");
	namInt=part.GetCreateNameSpan("FrontCoatings");
	namInt.SetPreferred("glossy");
	
	
	namInt=MediaIntent.GetCreateNameSpan("BackCoatings");
	namInt.SetPreferred("none");
	
	l=product.LinkResource(MediaIntent);
	
	JDFNode screen=product.AddProcess("Screening");
	JDFResource sp=screen.AddParameter("ScreeningParams");
	sp.SetStatus(sp.Status_Incomplete);
	sp=sp.AppendElement("ScreenSelector");
	sp.SetAttribute("ScreeningFamily","My favorite screen");
	sp.SetAttribute("SpotFunction","Ellipse");
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
int SpecDoc::DoQuery(){
	JDFJMF m=GetJMFRoot();
	m.init();
	m.SetSenderID("JMFClient");
	JDFQuery query=m.AppendQuery(JDFMessage::Type_KnownMessages);
	JDFKnownMsgQuParams qp=query.AppendKnownMsgQuParams();
	qp.SetListCommands(true);
	qp.SetListSignals(false);
	qp.SetListQueries(true);
	return 1;
}
/////////////////////////////////////////////////////////////////////////////
int SpecDoc::DoResponse(){
	parser->Parse("TestJDF16.jdf",false,true);
	JDFDoc dIn=parser->GetRoot();
	JDFJMF mIn=dIn.GetRoot();
	
	
	JDFJMF m=GetJMFRoot();
	m.init();
	m.SetSenderID("JMFClient #2");
	for(int i=0;42;i++){
		JDFQuery query=mIn.GetQuery(i);
		if(query.isNull()) break;
		MyResponse Response=m.AppendResponse(query.GetEnumType());
		if(Response.SetQuery(query)){
			if(Response.GetType()=="KnownMessages"){
				JDFElement km=Response.AppendElement("KnownMessages");
				
				JDFMessageService ms=km.AppendElement("MessageService");
				ms.SetAttribute("Type","KnownMessages");
				ms.SetAttribute("Query",true);
				
				ms=km.AppendElement("MessageService");
				ms.SetAttribute("Type","Status");
				ms.SetAttribute("Query",true);
				ms.SetAttribute("Persistent",true);
				
				ms=km.AppendElement("MessageService");
				ms.SetAttribute("Type","StopPersistentChannel");
				ms.SetAttribute("Command",true);
			}
		}
	}
	return 1;
}

/////////////////////////////////////////////////////////////////////////////


int SpecDoc::DoQuery2(){
	JDFJMF m=GetJMFRoot();
	m.init();
	m.SetSenderID("JMFClient");
	JDFQuery query=m.AppendQuery(JDFMessage::Type_Status);
	JDFElement subs=query.AppendElement("Subscription");
	subs.SetAttribute("ChangeAttributes","*");
	subs.SetAttribute("URL","http:://123.123.123.123/message/recipient");
	JDFStatusQuParams sqp=query.AppendElement("StatusQuParams");
	sqp.SetJobDetails(sqp.JobDetails_Brief);
	return 1;
}

/////////////////////////////////////////////////////////////////////////////
int SpecDoc::DoResponse2(int nn){
	parser->Parse("TestJDF18.jdf",false,true);
	JDFDoc dIn=parser->GetRoot();
	JDFJMF mIn=dIn.GetRoot();
	
	JDFJMF m=GetJMFRoot();
	m.init();
	m.SetSenderID("JMFClient #2");
	for(int i=0;42;i++){
		JDFQuery query=mIn.GetQuery(i);
		if(query.isNull()) break;
		JDFMessage signal;
		if(nn){
			signal=m.AppendSignal(query.GetEnumType());
		}else{
			signal=m.AppendResponse(query.GetEnumType());
		}
		if(signal.SetQuery(query)){
			if(signal.GetType()=="Status"){
				JDFElement km=signal.AppendElement("DeviceInfo");
				if(nn==0) km.SetAttribute("DeviceStatus","idle");				
				if(nn==1) km.SetAttribute("DeviceStatus","setup");				
				if(nn==2) {
					km.SetAttribute("DeviceStatus","running");
					signal.SetAttribute("LastRepeat",true);
				}
			}
		}
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoBible(){
	
	JDFElement r=GetRoot();
	r.AppendElement("Header").AppendText("CXML delight");
	JDFNode p=r.AppendElement("Request").AppendElement("JDF");
	JDFNode rr=p; rr.init();
	JDFNode vP[6];
	JDFComponent out[6];
	
	JDFNodeInfo ni=p.GetCreateNodeInfo();
	ni.UpdateBusiness(ni.BusinessObject_RFQ,"RFQ_Bible_ID");
	cout<<r;
	
	JDFCustomerInfo cust=p.GetCreateCustomerInfo();
	cust.SetAttribute("CustomerJobName","Bible Study");
	cust.SetAttribute("CustomerOrderID","Customers_ID_Bible");
	
	int i;
	
	vP[0]=p.AddProduct();
	vP[0].SetDescriptiveName("224 page hard case bound book with a 4/0 dust jacket");
	vP[3]=vP[0].AddProduct();
	vP[3].SetDescriptiveName("Book Case");
	vP[1]=p.AddProduct();
	vP[1].SetDescriptiveName("soft cover, perfect bound book");
	vP[2]=p.AddProduct();
	vP[2].SetDescriptiveName("text for both");
	vP[4]=vP[1].AddProduct();
	vP[4].SetDescriptiveName("Soft Cover");
	
	out[0]=vP[0].AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,p);
	out[1]=vP[1].AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,p);
	out[2]=vP[2].AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,p);
	out[3]=vP[3].AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,vP[0]);
	out[4]=vP[4].AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput,vP[1]);
	vP[0].LinkResource(out[2]);
	vP[1].LinkResource(out[2]);
	vP[0].LinkResource(out[3]).SetAttribute("ProcessUsage","Cover");
	vP[1].LinkResource(out[4]).SetAttribute("ProcessUsage","Cover");
	
	JDFIntentResource BindingIntent=vP[0].AppendMatchingResource(JDFNode::elm_BindingIntent,JDFNode::ProcessUsage_AnyOutput,vP[0]);
	JDFNameSpan nSpan=BindingIntent.GetNameSpan("BindingType");
	nSpan.SetPreferred("AdhesiveBinding");
	
	vP[0].LinkResource(BindingIntent);
	vP[1].LinkResource(BindingIntent);
	
	JDFIntentResource LayoutIntent=p.AppendMatchingResource(JDFNode::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput,p);
	JDFXYPairSpan xyInt=LayoutIntent.GetCreateSpan("Dimensions",JDFSpanBase::DataType_XYPair);
	xyInt.SetPreferred(8.5*72,11*72);
	xyInt.AddRange(8*72, 10*72, 9*72, 12*72);
	JDFIntegerSpan intInt=LayoutIntent.GetCreateIntegerSpan("Pages");
	intInt.SetPreferred(224);
	
	JDFResource company=p.AddParameter("Company",true,p,false);
	
	JDFIntentResource ColorIntent=p.AppendMatchingResource(JDFNode::elm_ColorIntent,JDFNode::ProcessUsage_AnyInput,p);
	JDFNumberSpan rSpan=ColorIntent.GetCreateNumberSpan("Coverage");
	rSpan.SetPreferred(50);
	nSpan=ColorIntent.GetCreateNameSpan("ColorStandard");
	nSpan.AddRange("SWOP");
	nSpan.AddRange("CMYK");
	nSpan.SetPreferred("SWOP");
	nSpan=ColorIntent.GetCreateNameSpan("InkManufacturer");
	nSpan.AddRange("Toyo");
	nSpan.AddRange("Crayola");
	nSpan.SetPreferred("Toyo");
	vP[3].LinkResource(ColorIntent);
	vP[4].LinkResource(ColorIntent);
	
	JDFIntentResource ColorIntentBW=vP[2].AppendMatchingResource(JDFNode::elm_ColorIntent,JDFNode::ProcessUsage_AnyInput);
	rSpan=ColorIntentBW.GetCreateNumberSpan("Coverage");
	rSpan.SetPreferred(10);
	nSpan=ColorIntentBW.GetCreateNameSpan("ColorStandard");
	nSpan.SetPreferred("MonoChrome");
	nSpan=ColorIntentBW.GetCreateNameSpan("InkManufacturer");
	nSpan.AddRange("Toyo");
	nSpan.AddRange("Crayola");
	nSpan.SetPreferred("Toyo");
	
	JDFIntentResource MediaIntent=vP[2].AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput);
	nSpan=MediaIntent.GetCreateNameSpan("FrontCoatings");
	nSpan.SetPreferred("none");
	nSpan=MediaIntent.GetCreateNameSpan("StockType");
	nSpan.SetPreferred("offset");
	
	MediaIntent=vP[3].AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput);
	nSpan=MediaIntent.GetCreateNameSpan("FrontCoatings");
	nSpan.SetPreferred("none");
	nSpan=MediaIntent.GetCreateNameSpan("StockType");
	nSpan.SetPreferred("cardboard");
	
	MediaIntent=vP[4].AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput);
	nSpan=MediaIntent.GetCreateNameSpan("FrontCoatings");
	nSpan.SetPreferred("none");
	nSpan=MediaIntent.GetCreateNameSpan("StockType");
	nSpan.SetPreferred("cover");
	
	setnodecustomer(p,JDFResource(),"RFQ");
	p.SetType("Product");
	MyDate date;
	date.SetDate(2000,12,6);
	for(int i=2;i<5;i++) {
		JDFNode n=vP[i];
		JDFResourceLink l=n.LinkResource(LayoutIntent);
	}
	
	for(int i=0;i<3;i++) {
		JDFIntentResource del=p.AppendMatchingResource(JDFNode::elm_DeliveryIntent,JDFNode::ProcessUsage_AnyInput);
		JDFNameSpan nameI=del.GetCreateNameSpan("Method");
		nameI.SetPreferred("none");
		del.RefElement(company);
		
		JDFElement DropIntent=del.AppendElement("DropIntent");
		JDFResource DropItemIntent=DropIntent.AppendElement("DropItemIntent");
		DropItemIntent.SetAttribute("AdditionalAmount",1000);
		DropItemIntent.SetAttribute("Required",date.DateTimeISO());
		if(i==0)	del.AppendComment().AppendText("Delivery of hardcover job");
		if(i==1)	del.AppendComment().AppendText("Delivery of softcover job");
		if(i==2)	del.AppendComment().AppendText("Delivery of both hard and softcover job");
		
		if((i==0)||(i==2)){
			DropItemIntent.SetAttribute("Amount",7500);
			DropItemIntent.RefElement(out[0]);
		}
		if((i==1)){
			DropItemIntent.SetAttribute("Amount",5000);
			DropItemIntent.RefElement(out[1]);
		}
		if(i==2){			
			JDFElement DropIntent=del.AppendElement("DropIntent");
			JDFResource DropItemIntent=DropIntent.AppendElement("DropItemIntent");
			DropItemIntent.SetAttribute("AdditionalAmount",1000);
			DropItemIntent.SetAttribute("Required",date.DateTimeISO());
			DropItemIntent.SetAttribute("Amount",5000);
			DropItemIntent.RefElement(out[1]);
		}
		
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

int SpecDoc::DoAudits(){
	JDFNode rt=GetRoot();
	JDFNode p=rt;
	p.SetType("Proofing");
	JDFColorantControl cc=p.AddParameter("ColorantControl",true);
	JDFColorSpaceConversionParams csp=p.AddParameter("ColorSpaceConversionParams",true);
	JDFColorSpaceConversionParams cspn=p.AddParameter("ColorSpaceConversionParams",true,p,true,L"",csp);
	JDFProofingParams cpp=p.AddParameter("ProofingParams",true);
	JDFAuditPool ap=p.GetAuditPool();
	ap.AddModified(L"Some Application");
	ap.AddModified(L"Another Application");
	JDFSimulator s=p;
	s.DoDefault();
	ap.AddProcessRun(JDFNode::Status_Completed);
	
	
	
	
	return 0;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

int SpecDoc::DoExtendRun(){
	JDFNode rt=GetRoot();
	JDFNode p=rt;
	p.SetType("Proofing");
	MyRunList rl;
	cout <<rl.ValidNodeNames()<<endl;
	rl=p.AddParameter("MyRunList",true);
	MyRunList cc1(p.AddParameter("MyRunList",true));
	MyRunList cc2(p.AddParameter("JDF:RunList",true));
	p.AddNameSpace("HDM","www.hdm.com");
	MyRunList cc3(p.AddParameter("HDM:HDMRunList",true));
	//	MyRunList cc4(p.AddParameter("HDM:_HDMRunList",true));
	cout<<p;
	//	MyRunList cc5(p.AddParameter("_HDMRunList",true));
	//MyRunList cc6(p.AddParameter("JDF:HDMRunList",true));
	
	
	
	return 0;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
int SpecDoc::DoBundle(){
	JDFNode rt=GetRoot();
	JDFNode pg=rt;
	pg.SetType("ProcessGroup");
	
	JDFNode boxPacking=pg.AddProcess("BoxPacking");
	JDFComponent cBox=boxPacking.AddResource("Component",JDFResource::Class_Quantity,true,pg);
	cBox.SetAmount(100);
	JDFResourceLink l=boxPacking.GetResourceLinkPool().GetElement("ComponentLink");
	l.SetProcessUsage("Box");
	cBox.SetAmount(100);
	
	JDFResource r=boxPacking.AddParameter("BoxPackingParams",true);
	r.SetAttribute("Quantity",42);
	
	JDFComponent c=boxPacking.AddResource("Component",JDFResource::Class_Quantity,true,pg);
	c.SetAmount(4200);
	
	
	JDFElement e=cBox.AppendElement("Bundle");
	e.SetAttribute("TotalAmount", 42);
	e=e.AppendElement("BundleItem");
	e.RefElement(c);
	e.SetAttribute("Amount",42);
	
	JDFNode palletizing=pg.AddProcess("Palletizing");
	palletizing.LinkResource(cBox,true);
	r=palletizing.AddConsumable("Palette",true);
	r.SetAmount(10);
	r=palletizing.AddParameter("PalletizingParams",true);
	r.SetAttribute("Quantity",10);
	
	
	JDFComponent cPallete=palletizing.AddResource("Component",JDFResource::Class_Quantity,true,pg);
	cPallete.SetAmount(10);
	
	e=cPallete.AppendElement("Bundle");
	e.SetAttribute("TotalAmount", 420);
	e=e.AppendElement("BundleItem");
	e.RefElement(cBox);
	e.SetAttribute("Amount",10);
	
	return 0;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

int SpecDoc::DoPreview(){
	JDFNode pg=GetRoot();
	pg.init();
	pg.SetEnumType(JDFNode::Type_ProcessGroup);
	pg.AddNameSpace("HDM","www.heidelberg.com/namespace/JDFExtensions");
	
	JDFNode npg=pg.AddProcess(L"PreviewGeneration");	
	npg.AppendMatchingResource(JDFNode::elm_PreviewGenerationParams,JDFNode::ProcessUsage_AnyInput);
	JDFPreview pv=npg.AppendMatchingResource(JDFNode::elm_Preview,npg.ProcessUsage_AnyOutput,pg);
	pv.SetDescriptiveName("Inkzone Preview");
	
	JDFNode npg2=pg.AddProcess(L"PreviewGeneration");	
	npg2.AppendMatchingResource(JDFNode::elm_PreviewGenerationParams,JDFNode::ProcessUsage_AnyInput);
	JDFPreview pv2=npg2.AppendMatchingResource(JDFNode::elm_Preview,npg.ProcessUsage_AnyOutput,pg);
	pv2.SetDescriptiveName("ImageControl Preview");
	
	JDFNode niz=pg.AddProcess(L"InkZoneCalculation");	
	niz.LinkMatchingResource(pv,niz.ProcessUsage_AnyInput);
	
	JDFNode icont=pg.AddProcess(L"HDM:ImageControl");
	icont.LinkResource(pv2,true);
	return 0;
	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
int SpecDoc::DoRefOrient(){
	JDFNode dp=GetRoot();
	dp.init();
	dp.SetEnumType(JDFNode::Type_DigitalPrinting);
	JDFDigitalPrintingParams dpp=dp.AppendMatchingResource(JDFNode::elm_DigitalPrintingParams,JDFNode::ProcessUsage_AnyInput);
	JDFMedia m1=dp.AppendMatchingResource(JDFNode::elm_Media,JDFNode::ProcessUsage_AnyInput);
	m1.SetAttribute("Orientation","Rotate0");
	JDFMedia m2=dp.AddConsumable("Media");
	m2.SetAttribute("Orientation","Flip90");
	dpp.AddPartitions(dpp.PartIDKey_DocRunIndex,WString("0 1 -2 -1,2~-3").Tokenize(","));
	JDFDigitalPrintingParams dppCover=dpp.GetPartition(dpp.PartIDKey_DocRunIndex,"0 1 -2 -1");
	dppCover.RefElement(m1);
	JDFDigitalPrintingParams dppInsert=dpp.GetPartition(dpp.PartIDKey_DocRunIndex,"2~-3");
	dppInsert.RefElement(m2);
	
	
	return 0;
	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
int SpecDoc::DoFoldCatalog(){
	int n=0;
	JDFNode nod=GetJDFRoot();
	JDFResourcePool rp=nod.AppendResourcePool();
	for(int i=0;i<65;i++){
		for(int j=0;j<20;j++){
			WString w=L"D:\\local\\bin\\folds\\f";
			WString WName=L"F";
			if(i<10)
				w+="0";
			w+=i;
			WName+=i;
			w+="-";
			WName+="-";
			if(j<10)
				w+="0";
			w+=j;
			WName+=j;
			w+=".txt";
			if(!_access(w.peekBytes(),0)){
				cout<<n<<" "<<WName<<endl;
				FILE* f=fopen(w.peekBytes(),"r");
				char buf[100];
				int i=fread(buf,1,99,f);
				buf[i]=0;
				cout<<buf<<endl;
				fclose(f);
				vWString vFolds;
				WString stBuf=buf; 
				int iP1=0;
				while(42){
					int iP2=stBuf.find_first_of('/',iP1);
					if(iP2==WString::npos)
						break;
					iP2+=2;
					if(stBuf.length()>iP2){
						JDFCh cc=stBuf[iP2];
						if((cc>=L'0')&&(cc<=L'9')){
							iP2++;
						}
					}

					vFolds.push_back(stBuf.substring(iP1,iP2));
					cout<<stBuf.substring(iP1,iP2)<<endl;
					iP1=iP2;

				}

				JDFFoldingParams fp=rp.AppendElement(JDFElement::elm_FoldingParams);
				fp.SetFoldCatalog(WName);
				bool swapFront=false;
				for(int k=0;k<vFolds.size();k++){
					int pos=0;
					WString sBuf=vFolds[k];
					JDFFold fold=fp.AppendFold();
					if(sBuf[0]==L'+'){
						pos++;
						swapFront=!swapFront;
					}
					if(swapFront){
						fold.SetFrom(fold.From_Left);
					}else{
						fold.SetFrom(fold.From_Front);
					}
					if(sBuf[pos++]=='U'){
						fold.SetTo(fold.To_Up);
					}else{
						fold.SetTo(fold.To_Down);
					}
					double d1=(double)WString(sBuf[pos]);
					double d2=(double)WString(sBuf[pos+2]);
					if(sBuf.length()-3>pos){
						JDFCh cc=sBuf[pos+3];
						if((cc>=L'0')&&(cc<=L'9')){
							pos++;
							d2=10.0*d2+(double)WString(cc);
						}
					}
					double d=100.0*d1/d2;
					fold.SetRelativeTravel(d);

				}
			}
		}
	}
	return n;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
