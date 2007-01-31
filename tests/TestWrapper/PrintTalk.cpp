
#include "JDF.h"
#include "JDFColorSpaceConversionParams.h"
#include "JDFColorantControl.h"
#include "JDFAddress.h"
#include "JDFConventionalPrintingParams.h"
#include "JDFExposedMedia.h"
#include "JDFColorantControl.h"
#include <jdf/util/PlatformUtils.h>
#include "MyArgs.h"

using namespace std;
using namespace JDF;

//////////////////////////////////////////////////////////////////
namespace JDF{
	class JDFPrintTalk : public JDFElement{
	public:
		
		//////////////////////////////////////////////////////////////////////
		// Constructors / Destructors  
		//////////////////////////////////////////////////////////////////////
		
		JDFPrintTalk():JDFElement(){};
		JDFPrintTalk(const DOM_Element & other):JDFElement( other){};
		JDFPrintTalk(const DOM_Node & other):JDFElement((DOM_Element &) other){};
		virtual ~JDFPrintTalk(){};
		bool init(){
			SetTimeStamp("timestamp");
			JDFElement header=GetElement("Header",true);
			header.GetElement("From",true)<<"default cxml header";
			header.GetElement("To",true)<<"default cxml header";
			header.GetElement("Sender",true)<<"default cxml header";
			return true;
		}
		void SwapFromTo(){
			JDFElement header=GetElement("Header",true);
			header.GetElement("From").RenameElement("__FROM__");
			header.GetElement("To").RenameElement("From");
			header.GetElement("__FROM__").RenameElement("To");
			// reorder
			header.MoveNode(GetElement("From"));
			header.MoveNode(GetElement("To"));
			header.MoveNode(GetElement("Sender"));

		}
		JDFRoot AddRequest(KString boType){
			KElement req=GetElement("Request",true,L"",-1);
			req=req.AppendElement(boType);
			JDFRoot r=req.AppendElement("JDF");
			r.init();
			return r;
		}
		JDFPrintTalk GetBO(){
			JDFElement e=GetDocRoot().GetElement("Request");
			if(e.isNull()){
				cout<<"invalid object: "<<e<<endl;
				return JDFElement();
			}
			vKString vBos=JDFNodeInfo::BusinessObjectString().Tokenize(L",");
			return e.GetChildFromList(vBos);
		}
		JDFNodeInfo::EnumBusinessObject GetBOEnum(){
			JDFElement e=GetBO();
			if(e.isNull()){
				cout<<"invalid object: "<<e<<endl;
				return (JDFNodeInfo::EnumBusinessObject)0;
			}
			vKString vBos=JDFNodeInfo::BusinessObjectString().Tokenize(L",");
			return (JDFNodeInfo::EnumBusinessObject) vBos.index(e.GetNodeName());
		}
		
		bool UpdateBusiness(JDFNodeInfo::EnumBusinessObject businessObject,KString newID=L""){
			KElement e=GetBO();
			vKString vBos=JDFNodeInfo::BusinessObjectString().Tokenize(L",");
			int oldType=vBos.index(e.GetNodeName());
			e.RenameElement(vBos[businessObject]);
			if(businessObject>oldType){
				e.SetAttribute("BusinessRefID",e.GetAttribute("BusinessID"));
				if(!newID.empty()) e.SetAttribute("BusinessID",newID);
			}
			return true;
		}
		
	}; 
	
	
	
	//////////////////////////////////////////////////////////////////
	
	class  PTDoc :public XMLDoc{
	public:
		PTDoc():XMLDoc("PrintTalk"){};
		~PTDoc(){};
		inline JDFPrintTalk GetPT(){return GetRoot();};
		JDFPrintTalk GetBO(){return GetPT().GetBO();};

		int DoQuote(double base=1000.);
		int PrepareQuote();
		int SelectQuote();
		int DoTest();
		int DoBible();
		int DoPO( int iAccept=0);
		int DoConfirm();
		int DoInvoice();
	};
}
//////////////////////////////////////////////////////////////////


int main(int argC, char* argV[]){
    // Initialize the XML4C2 system
    try{
        XMLPlatformUtils::Initialize();
    }catch(const XMLException& toCatch){
        cerr << "Error during XML4C2 Initialization.\n"
			"  Exception message is \"%s\"\n"
			<< toCatch.getMessage() << endl;
        return 1;
    }
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	// trivial argument handling
	MyArgs args(argC,argV,"ce","aioq");
	
    // Watch for special case help request
	string usage="PrintTalk: PrintTalk File Manipulation;\nArguments: -i input File;\n-o output File;\nQuote:\n-q base quote price;\nPO:\n-a accept delivery intent #a (zero based)\n-c request a confirmation\n";
    if ((argC==1)||(argC>1)&&(strcmp(argV[1], "-?") == 0)){
        cerr<< args.Usage(usage);
        return 0;
    }
	KString fName=args.Parameter('i');
	KString ofName=args.Parameter('o');
	double base=args.FloatParameter('b',1000.);
	int iAccept=args.IntParameter('a',0);
	bool  bConfirm=args.BoolParameter('c');
	// setup indentation
	XMLIndent(2,true);
	
	// loop over chosen examples
	PTDoc gdoc;
	gdoc.Parse(fName,false,false);
	
	JDFPrintTalk pt=gdoc.GetPT();
	pt.SwapFromTo();
	JDFNodeInfo::EnumBusinessObject boe=pt.GetBOEnum();
	switch(boe){
	case (JDFNodeInfo::BusinessObject_RFQ): gdoc.DoQuote(base); break;
	case (JDFNodeInfo::BusinessObject_Quote): gdoc.DoPO(iAccept); break;
	case (JDFNodeInfo::BusinessObject_PO): {
		if(bConfirm){
			gdoc.DoConfirm();
		}else{
			gdoc.DoInvoice();
		}
		break;
										   }
	default:cout<<"Illegal Business Type: "<<pt.GetBO().GetNodeName()<<endl; break;

	}
	
	pt.EraseEmptyNodes();
	if(!ofName.empty()) gdoc.Write2File(ofName);
    XMLPlatformUtils::Terminate();
	return 0;
}

///////////////////////////////////////////////////////////////////////////

int PTDoc::DoQuote(double base){
	
	
	JDFRoot r=GetRoot().GetDeepElement("JDF");
	int i;
	for(i=0;;i++){
		JDFNodeProduct n=r;
		JDFIntentResource ri=n.GetIntent("DeliveryIntent",i);
		if(ri.isNull()) break;
		
		ri.PreferredToActual();
		JDFElement q=ri.GetElement("Pricing",true);
		q.SetAttribute("Price",base*(i+1));
		q.SetAttribute("AdditionalPrice",base*0.05*(i+1));
		JDFElement q2=q.AppendElement("Pricing");
		q2.SetAttribute("item","Processing");
		q2.SetAttribute("Price",base*(i+1));
		q2.SetAttribute("AdditionalPrice",base*0.05*(i+1));
		q2=q.AppendElement("Pricing");
		q2.SetAttribute("item","shipping");
		q2.SetAttribute("HasPrice",false);
	}		
	vElement vJDF=r.GetChildrenByTagName("JDF",L"",mAttribute(),false);	
	for(i=0;i<vJDF.size();i++){
		JDFNodeProduct n=vJDF[i];
		vElement v=n.GetIntents();
		for(int j=0;j<v.size();j++){
			JDFIntentResource intent=v[j];
			intent.PreferredToActual();
		}
		
	}
	GetBO().UpdateBusiness(JDFNodeInfo::BusinessObject_Quote,"QuoteID");
	GetBO().GetElement("Quote").RemoveAttribute("LastResponse");
	GetBO().RemoveAttribute("BusinessLastID");
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
int PTDoc::DoPO(int  iAccept){
	
	
	JDFRoot r=GetRoot().GetDeepElement("JDF");
	for(int i=0;;i++){
		JDFNodeProduct n=r;
		JDFIntentResource ri=n.GetIntent("DeliveryIntent",i);
		
		if(ri.isNull()) break;
		ri.SetAttribute("Accepted",i==iAccept);
	}
	GetBO().RemoveAttribute("Estimate");
	GetBO().UpdateBusiness(JDFNodeInfo::BusinessObject_PO,"Purchase Order ID");
	//	r.SetStatus(r.Status_quoted);
	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
int PTDoc::DoConfirm(){
	
	
	JDFRoot r=GetRoot().GetDeepElement("JDF");
	GetBO().UpdateBusiness(JDFNodeInfo::BusinessObject_Confirmation,"Confirmation ID");
	GetBO().RemoveAttribute("Estimate");
	for(int i=0;;i++){
		JDFNodeProduct n=r;
		JDFIntentResource ri=n.GetIntent("DeliveryIntent",i);
		
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
int PTDoc::DoInvoice(){
	
	
	GetBO().SetAttribute("LastResponse",MyDate(100000).DateTimeISO());
	GetBO().RemoveAttribute("Estimate");
	JDFRoot r=GetRoot().GetDeepElement("JDF");
	GetBO().UpdateBusiness(JDFNodeInfo::BusinessObject_Invoice,"Invoice ID");
	for(int i=0;;i++){
		JDFNodeProduct n=r;
		JDFIntentResource ri=n.GetIntent("DeliveryIntent",i);
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
		
		JDFElement quote=ri.GetElement("Pricing");
		double sum=quote.GetRealAttribute("Price");
		vElement qc=quote.GetChildElementVector("Pricing");
		quote.RemoveAttribute("AdditionalPrice");
		for(int ii=0;ii<qc.size();ii++){
			qc[ii].RemoveAttribute("AdditionalPrice");
			if (!qc[ii].GetBoolAttribute("HasPrice",true)){
				qc[ii].SetAttribute("HasPrice",true);
				qc[ii].SetAttribute("Price",(int)(sum*0.1));
				sum*=1.1;
			}
		}
		quote.SetAttribute("Price",(int)sum);
	}		
	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////

