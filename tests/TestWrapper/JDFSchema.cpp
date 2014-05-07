
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2009
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
//////////////////////////////////////////////////////////////////////

//#include "jdf.h"
#include "jdf/WrapperCore/KElement.h"
#include "jdf/WrapperCore/vElement.h"
#include "jdf/WrapperCore/MyDate.h"
#include "jdf/WrapperCore/XMLDoc.h"
#include "MyArgs.h"
#include "jdf/WrapperCore/JDFParser.h"
#include <jdf/util/myuti.h>
#include <jdf/util/PlatformUtils.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <xercesc/util/PlatformUtils.hpp>
#include "jdf/lang/Exception.h"

XERCES_CPP_NAMESPACE_USE


	using namespace std; 
using namespace JDF;

bool bDoStatus; // global fudge
bool bDoOrientation; // global fudge
mAttribute classMap;
mAttribute messageMap;
vWString allAtts;
vWString allElms;
vWString processUsages;

WString typeNames;
WString typeNameString;
WString linkNames;
WString linkInfo;


class  SchemaDoc :public XMLDoc{
public:
	SchemaDoc(int docType=0):XMLDoc(){
		schemaFileName="";
	};
	SchemaDoc(const XMLDoc&d):XMLDoc(d){
		schemaFileName="";
	};
	~SchemaDoc(){};
	int MakeC(const WString & classString);
	int MakeCC();
	int MakeCProc();
	void MergeRes(const WString &name, WString nameNoStrip);
	int ToProcCode2(const WString & schemaName,vWString vName,vWString info,WString schemaFileName);
	int ToProcCode(const WString & schemaName,vWString vName,vWString info,WString schemaFileName);
	int Strip();
	int MoveJDF(SchemaDoc s);
	void MergeDoc (XMLDoc d){
		KElement e=GetRoot();
		vElement v=d.GetRoot().GetChildElementVector();
		for(int i=0;i<v.size();i++){
			e.CopyElement(v[i]);
		}
	};
	WString schemaFileName;
	static void Escape(WString& theString, WString toEscape, WString escapeChar=WString("\\"), int radix=0, int escapeLen=0, int escapeBelow=0, int escapeAbove=256){
		WString escapedString;
		int l=theString.size();
		const wchar_t* pc=theString.c_str();
		for(int i=0;i<l;i++){
			if ((*pc>escapeAbove)||(*pc<escapeBelow)||(toEscape.find(*pc)!=toEscape.npos)){ // the character must be escaped
				escapedString+=escapeChar;
				if(radix>0){ // radix is a flag to convert to octal, hex etc.
					wchar_t buf[16];
#ifdef _WIN32
					_itow((int)*pc,buf,radix);
#else
					if(radix==8){
						swprintf(buf,L"%o",*pc);
					}else if(radix==10){
						swprintf(buf,L"%u",*pc);
					}else if(radix==16){
						swprintf(buf,L"%x",*pc);
					}else{
						throw TException("WString::Escape radix out of range");
					}

#endif
					wcsupr(buf);  //capitalize hex stuff
					if(escapeLen){ // prepad zeroes to a total of escapeLen
						int lenBuf=wcslen(buf);
						if(lenBuf<escapeLen){ 
							escapedString.insert(escapedString.size(),escapeLen-lenBuf,L'0');
						}
					}
					escapedString+=buf;
				}else if(radix<0){
					// nop
				}else{ // radix=0; just insert thge escape character in front of the actual char
					escapedString+=*pc;
				}
			}else{ // no escape necessary --> just copy it
				escapedString+=*pc;
			}
			pc++;
		}
		theString.assign(escapedString);
	}

};

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
class  SchemaElement :public KElement{
public:
	SchemaElement():KElement(){};
	SchemaElement(const KElement & other):KElement( other){};
	virtual ~SchemaElement(){};
	SchemaElement GetRoot(){
		return GetOwnerDocument().GetRoot();
	}
	//////////////////////////////////////////////////////////////////////
	vWString& GetResourceList(){
		static vWString resList;
		static bool bFirst=true;
		if(bFirst){
			bFirst=false;
			resList.clear();
			KElement r=GetDocRoot();
			vWString vv=WString("IntentResourceList PhysicalResourceList ImplementationResourceList PlaceHolderResourceList ParameterResourceList").Tokenize();
			for(int abc=0;abc<vv.size();abc++){
				WString list=vv[abc];
				KElement e=r.GetChildWithAttribute("xs:group","name","",list);
				e=e.GetElement("xs:sequence");
				vElement v=e.GetChildElementVector("xs:element");
				for(int i=0;i<v.size();i++){
					resList.push_back(v[i].GetAttribute("name"));
				}
			}

		}
		return resList;
	}

	/////////////////////////////////////////////////////////////////////////7

	WString GetCTName(WString s="", bool bStrip=true, bool elmName=false){
		if(s.empty()) 
			s=GetAttribute("name");
		SchemaDoc::Escape(s,"-*+","_",-1);
		if(s.empty()){ // recursive call
			if(HasAttribute("ref")){
				s=GetAttribute("ref");
			}else{
				SchemaElement se=GetParentNode();
				if(se.isNull()) {
					std::cout<<"GetCTName ...";//<<*this;
					return "";
				}
				return se.GetCTName("",bStrip);
			}
		}

		WString base=GetXPathAttribute("xs:complexContent/xs:restriction@base");
		if(base.empty())
			base=GetXPathAttribute("xs:complexContent/xs:extension@base");


		if((s.rightStr(3)=="_lr")||(s.rightStr(3)=="_lu")||(s.rightStr(2)=="_l")){
			vWString v=s.Tokenize("_");
			if(v.size()>=3){
				int si=v.size();
				if(s.find(L"ColorantControl_CO_CP_DCO")==s.npos){
					// nop
					if(bStrip){ 
						s=v[si-2];
					}else{
						s=v[si-2]+"_"+v[si-1];
					}
				}
				if(v[0]=="IDPrintingParams")
					s="IDP"+s;
			}else if(s.find("Preflight")!=s.npos){
				//				cout<<"\n**********************"<<s<<endl;
			}else{
				cout << "GetCTName: oops for reselements: "<<s<<endl;
			}
		}

		if(!bStrip) 
			return s;

		if(s.leftStr(4)=="jdf:") 
			s=s.rightStr(-4);
		if(s.leftStr(7)=="jdftyp:") 
			s=s.rightStr(-7);

		if(s.rightStr(2)=="__"){
			s=s.leftStr(-2);
		}else if(s.rightStr(12)=="ResLinkPool_"){
			s=s.leftStr(-12);
		}else if(s.rightStr(1)=="_"){
			s=s.leftStr(-1);
		}else if(s.rightStr(2)=="_r"){
			s=s.leftStr(-2);
		}else if(s.rightStr(3)=="_rp"){
			s=s.leftStr(-3);
		}else if(s.rightStr(3)=="_lr"){
			s=s.leftStr(-3);
		}else if(s.rightStr(3)=="_me"){
			s=s.leftStr(-3);
		}else if(s.rightStr(3)=="_lu"){
			s=s.leftStr(-3);
		}else if(s.rightStr(2)=="_a"){
			s=s.leftStr(-2);
		}else if(s.rightStr(9)=="Element_m"){
			s=s.leftStr(-9);
		}else if(s.rightStr(8)=="BaseType"){
			s=s=s.leftStr(-8);
		}else if(s.rightStr(2)=="_m"){
			s=s.leftStr(-2);
		}else if(s.rightStr(3)=="_re"){
			s=s.leftStr(-3);
		}else if(s.rightStr(5)=="Audit"){
			if(s!="ResourceAudit")
				s=s.leftStr(-5);
		}else if((s.leftStr(16)=="IDPrintingParams")&&(s.size()>16)){
			s="IDP"+s.rightStr(-16);
		}

		if(s=="JDF") {
			if(!elmName)
				s="Node";
		}
		if(s=="HoleMakingParamsHole") 
			s="Hole";
		if(s=="AuditElement") 
			s="Audit";
		if(s=="Comment_Type") 
			s="Comment";
		if(s=="ColorantControl_CO_CP_DCO")
			s="SeparationList";
		if(s=="ParamsDrop")
			s="Drop";
		if(s=="JMFRootMessage")
			s="JMF";
		if(s=="DevCapState")
			s="DevCap";


		if(s=="Subscription_ObservationTarget")
			s="ObservationTarget";
		if(s=="Trigger_Added")
			s="Added";
		if(s=="Trigger_Removed")
			s="Removed";
		if(s=="Trigger_ChangedAttribute")
			s="ChangedAttribute";
		if(s=="Trigger_ChangedPath")
			s="ChangedPath";
		if(s=="DeviceInfo_ModuleStatus")
			s="ModuleStatus";
		if(s=="Preflight_BoxArgument")
			s="BoxArgument";
		if(s=="Preflight_BoxToBoxDifference")
			s="BoxToBoxDifference";
		if(s=="PhaseTimeAudit_Activity")
			s="Activity";



		if((s.size()>13)&&s.leftStr(13)=="BindingIntent")
			s=s.rightStr(-13);


		return s;
	}

	//////////////////////////////////////////////////////////////////////
	WString GetSpanName(){
		WString cName="Span"+GetCTName();
		if(cName.rightStr(5)=="Color") {
			cName="SpanNamedColor";
		}
		if(cName.rightStr(9)=="ColorName") {
			cName="SpanNamedColor";
		}
		if(cName.rightStr(4)=="Glue") {
			cName="SpanGlue";
		}
		if(cName.rightStr(8)=="Coatings") {
			cName="SpanCoatings";
		}
		return cName;
	}
	//////////////////////////////////////////////////////////////////////

	WString GetCType(bool bAttrib, const WString& thisClass=WString::emptyStr, const WString& tt=WString::emptyStr,bool bEscape=true){
		WString t;
		WString tNoStrip;
		if(tt.empty()){
			tNoStrip=GetAttribute("type");
		}else{
			tNoStrip=tt;
		}
		if(!tNoStrip.empty()){
			t=GetCTName(tNoStrip);
		}else{
			SchemaElement eref=GetRef();
			if(!eref.isNull()) 
				return eref.GetCType(bAttrib,thisClass,tt,bEscape);
			// search for unlinked stuff e.g. in the message defs
			t=GetAttribute("ref");
			if(!t.empty()) 
				t=GetCTName(t);

		}
		if(bEscape)
			SchemaDoc::Escape(t,"-*+","_",-1);

		if((tNoStrip.find(L"IDPrintingParams_")!=tNoStrip.npos)&&(!t.startsWith(L"IDP")))
			t=L"IDP"+t;

		if(t=="jdf:DevCapState") 
			return "DevCap"; 		

		if(t=="jdf:ResourceRef") 
			return ""; 		
		if(t=="Expr") 
			return ""; 		
		if(t=="jdf:DevCap_State") 
			return ""; 		

		if(t.rightStr(8)=="_Element") 
			t=t.leftStr(-8);

		if(t.rightStr(4)=="Span") {
			if(t=="EnumerationSpan"){
				t=GetSpanName();
			}
			return "JDF"+t;
		}

		if(t=="jdftyp:DoubleAndXYPair") 
			return "double";

		if(t=="xs:double") 
			return "double";		
		if(t=="number") 
			return "double";
		if(t=="xs:integer") 
			return "int";
		if(t=="Integer") 
			return "int";
		if(t=="Integer0To100")
			return "int";
		if(t=="LongInteger")
			return "JDFInt64";

		if(t=="LanguagesOrAll") 
			return "vWString";
		if(t=="languages") return "vWString";
		if(t=="languages") return "vWString";
		if(t=="xs:anyURI") return "WString";
		if(t=="xs:hexBinary") return "WString";
		if(t=="TimeRange") return "JDFDate";
		if(t=="NameIntent") return "JDFNameSpan";
		if(t=="CMYKColor") return "JDFCMYKColor";
		if(t=="LabColor") return "JDFLabColor";
		if(t=="sRGBColor") return "JDFRGBColor";
		if(t=="XYPair") return "JDFXYPair";
		if(t=="shape") return "JDFShape";
		if(t=="matrix") return "JDFMatrix";
		if(t=="rectangle") return "JDFRectangle";
		if(t=="NumberIntent") return "JDFNumberSpan";
		if(t=="OptionIntent") return "JDFOptionSpan";
		if(t=="IntegerIntent") return "JDFIntegerSpan";
		if(t=="StringIntent") return "JDFStringSpan";
		if(t=="TimeIntent") return "JDFTimeSpan";

		if(t=="Comment_Type") return "JDFComment";
		if(t=="JDFProcessNode") 
			return "JDFNode";
		if(t=="Comment") return "JDFComment";
		if(t=="IntegerRangeList") return "JDFIntegerRangeList";
		if(t=="IntegerList") return "JDFIntegerList";
		if(t=="IntegerRange") return "JDFIntegerRange";
		if(t=="NumberList") return "JDFNumberList";
		if(t=="DoubleList") return "JDFNumberList";
		if(t=="TransferFunction") return "JDFNumberList";
		if(t=="NumberRangeList") return "NumberRangeList";
		if(t=="DoubleRangeList") return "NumberRangeList";
		if(t=="DoubleAndSeparators") 
			return "NumberRange";
		if(t=="NumberRange") return "NumberRange";
		if(t=="NameRangeList") return "NameRangeList";
		if(t=="NameRange") return "NameRange";
		if(t=="XYPairRangeList") return "JDFXYPairRangeList";
		if(t=="XYPairRange") return "JDFXYPairRange";
		if(t=="ePartitionKeys") return "";
		if(t=="URL") 
			return "WString";
		if(t=="path") 
			return "WString";
		if(t=="BaseElement") return "JDFElement";
		if(t=="EmptyElement") return "JDFElement";
		if(t=="telem") return "JDFElement";
		if(t=="ResponseTypeObj") 
			return "JDFElement";


		if(bAttrib){
			WString name=GetCTName();
			// next three are hacks for preview schem hack
			if(name=="NoOp")
				return "";
			if(name=="Class" &&(t!="eNotificationClass"))
				return "";
			if(name=="PartUsage")
				return "";
			if(name=="PresentationDirection")
				return "WString";
			if(name=="Version")
				return "WString";
			if(t=="xs:boolean") return "bool";
			if(t=="boolean") return "bool";
			if(t=="NMTOKEN") return "WString";
			if(t=="xs:NMTOKEN") return "WString";
			if(t=="jdftyp:NMTOKEN") return "WString";
			if(t=="xs:IDREFS") return "vWString";
			if(t=="xs:ID") return "WString";
			if(t=="xs:IDREF") return "WString";
			if(t=="string") return "WString";
			if(t=="xs:string") return "WString";
			if(t=="xs:token") return "WString";
			if(t=="shortstring") return "WString";
			if(t=="jdftyp:shortstring") return "WString";
			if(t=="shortString") return "WString";
			if(t=="jdftyp:shortString") return "WString";
			if(t=="longString") return "WString";
			if(t=="jdftyp:longString") return "WString";

			if(t=="jdftyp:token") return "WString";
			if(t=="xs:normalizedString") return "WString";
			if(t=="xs:dateTime") return "JDFDate";
			if(t=="dateTime") return "JDFDate";
			if(t=="xs:duration") return "JDFDuration";
			if(t=="duration") return "JDFDuration";
			if(t=="xs:gYearMonth") return "JDFDate";
			if(t=="xs:language") return "WString";

			SchemaElement se=GetElement("xs:simpleType").GetChildWithAttribute("xs:restriction","base","","jdftyp:EnumerationBaseType");
			if(!se.isNull()) 
				return "enum";

			if(t.empty()){
				t=GetElement(L"xs:simpleType").GetElement("xs:restriction").GetAttribute("base");
				if(!t.empty()){
					return GetCType(bAttrib, thisClass,t,bEscape);
				}
			}
			if((t.size()>=2)&&((t.leftStr(1)==L"e")||(t.leftStr(1)==L"p"))){
				WString alpha(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
				if(alpha.find(t[1])!=alpha.npos){
					if(tNoStrip.leftStr(4)=="jdf:")
						tNoStrip=tNoStrip.rightStr(-4);
					if(tNoStrip.leftStr(7)=="jdftyp:")
						tNoStrip=tNoStrip.rightStr(-7);
					SchemaElement se=GetDocRoot().GetChildWithAttribute("xs:simpleType","name","",tNoStrip);
					if(se.isNull()){
						cout <<" oops "<<endl;
					}else{
						if(!se.GetChildWithAttribute("xs:restriction","base","","jdftyp:EnumerationBaseType").isNull()){
							return "enum";
						}
						KElement ssee=se.GetChildWithAttribute("xs:restriction","base","","jdftyp:string");
						if(!ssee.isNull()){
							if(ssee.HasChildElement("xs:enumeration"))
								return "enum";
						}
						WString jdfEnumRestriction=L"jdftyp:"+tNoStrip.rightStr(-1);
						if(!se.GetChildWithAttribute("xs:restriction","base","",jdfEnumRestriction).isNull()){
							return "enum";
						}
						if(!se.GetElement("xs:list").isNull()){
							WString enumType=se.GetXPathAttribute("xs:list@itemType");
							if(enumType.leftStr(4)=="jdf:")
								enumType=enumType.rightStr(-4);
							if(enumType.leftStr(7)=="jdftyp:")
								enumType=enumType.rightStr(-7);
							se=GetDocRoot().GetChildWithAttribute("xs:simpleType","name","",enumType);
							bool bb;
							vWString v=se.EnumValues(enumType,bEscape,bb);
							//							cout<<"enums "<<v;
							WString s="enums";
							for(int i=0;i<v.size();i++){
								s+=" "+v[i];
							}
							return s;
						}
					}
				}
			}
			if(t=="NamedColor") 
				return "enum";
			if(t=="WorkStyle") 
				return "enum";
			if(t=="Orientation") 
				return "enum";

			if(t=="xs:QName") 
				return "WString";


			if((t=="xs:NMTOKENS") || (t=="NMTOKENS")){
				WString tokens=GetXPathAttribute("xs:annotation/xs:appinfo/Constraint@Tokens");
				if(tokens.empty())
					return "vWString";
				return "enums "+tokens;
			}
			if(t=="IDPFinishingsList") 
				return "vWString";
			if(t.rightStr(7)=="Classes") 
				return "vWString";

			if(tNoStrip.leftStr(4)=="jdf:")
				tNoStrip=tNoStrip.rightStr(-4);
			if(tNoStrip.leftStr(7)=="jdftyp:")
				tNoStrip=tNoStrip.rightStr(-7);

			SchemaElement se2=GetDocRoot().GetChildWithAttribute("xs:simpleType","name","",tNoStrip);
			if(!se2.isNull()){
				WString tt=se2.GetElement("xs:restriction").GetAttribute("base");
				if(!tt.empty()){
					return GetCType(bAttrib, thisClass,tt,bEscape);
				}
			}
			cout<<"GetCType attribute not found "<<t<<" --> ";//<<*this;

			return "WString";

		}else{ // if bAttrib
			if(t.empty()){
				t=GetCTName();
			}
			// collision with JDFShape (3 value numlist)
			if(t=="JDF") 
				t="Node";
			if(t=="Shape")
				t="ShapeElement";

			if(t.endsWith(L"ConstraintsPool"))
				t="PreflightConstraintsPool";

			if(t.endsWith(L"CommonConstraintPool"))
				t="PreflightConstraintsPool";

			if(t.endsWith(L"CommonPool"))
				t="PreflightResultsPool";

			if(t.endsWith(L"ResultsPool"))
				t="PreflightResultsPool";

			if(t=="SeparationListFront"||t=="SeparationListBack")
				t="SeparationList";
			if(t=="ColorsUsed")
				t="SeparationList";
			if(t=="CutLines")
				t="SeparationList";

			if(!thisClass.empty()){
				if(t==(WString("JDF")+thisClass.rightStr(-7))){
					t=WString("JDFAuto")+t.rightStr(-3);
					t="";
					//cout<<"recursive call to "<<t<<endl;
				}
			}
			if((!t.empty())&&(t.leftStr(3)!="JDF")||(t=="JDFController")||(t=="JDFService")){
				t="JDF"+t;
				//				cout<< "--------------------> "<<t<<endl;
			}
			return t;
		}

	}

	//////////////////////////////////////////////////////////////////////

	WString GetAttributeEnumType(){
		WString t=GetAttribute("type");
		if(t.leftStr(4)=="jdf:")
			t=t.rightStr(-4);
		if(t.leftStr(7)=="jdftyp:"){
			t=t.rightStr(-7);
			if(t.leftStr(1)=="p"){
				t=GetCType(true);
			}
		}

		SchemaDoc::Escape(t,"-*+","_",-1);


		if(t.leftStr(3)=="xs:")
			t=t.rightStr(-3);
		if(t.leftStr(3)=="JDF")
			t=t.rightStr(-3);
		if(t.rightStr(8)=="_Element"){
			t=t.leftStr(-8);
		}else if(t=="double"){ 
		}else if(t=="Double"){
			t= "double";
		}else if(t=="number"){
			t= "double";
		}else if(t=="DoubleList"){
			t= "NumberList";
		}else if(t=="DoubleRangeList"){
			t= "NumberRangeList";
		}else if(t=="Integer"){
			t= "integer";
		}else if(t=="Integer0To100"){
			t= "integer";
		}else if(t=="int"){
			t= "integer";
		}else if(t=="LongInteger"){
			t= "integer";
		}else if(t=="integer"){
		}else if(t=="boolean"){
		}else if(t=="bool"){
			t="boolean";
		}else if(t=="QName"){
		}else if(t=="NMTOKEN"){
		}else if(t=="NMTOKENS"){
		}else if(t=="WString"){
			t="string";
		}else if(t=="vWString"){
			t="Any";
		}else if(t=="string"){
		}else if(t=="matrix"){
		}else if(t=="rectangle"){
		}else if(t=="dateTime"){
		}else if(t=="duration"){
		}else if(t=="XYPair"){
		}else if(t=="language"){
		}else if(t=="languages"){
		}else if(t=="PDFPath"){
		}else if(t=="NameRangeList"){
		}else if(t=="IntegerRangeList"){
		}else if(t=="IntegerList"){
		}else if(t=="ID"){
		}else if(t=="IDREF"){
		}else if(t=="IDREFS"){
		}else if(t=="XPath"){
		}else if(t=="URL"){
		}else if(t=="URI"){
		}else if(t=="regExp"){
		}else if(t=="shape"){
		}else if(t=="JMFVersions"){
			t="Any";
		}else if(t=="JMFVersion"){
			t="Any";
		}else if(t=="LabColor"){
		}else if(t=="RGBColor"){
		}else if(t=="sRGBColor"){
			t="RGBColor";
		}else if(t=="CMYKColor"){
		}else if(t=="hexBinary"){
		}else if(t=="TransferFunction"){
		}else if(t=="shortString"){
		}else if(t=="longString"){
		}else{
			cout << " unknown attribute datatype "<<t<<endl;
			t="Any";
		}
		t="AttributeType_"+t;
		return t;
	}

	//////////////////////////////////////////////////////////////////////
	SchemaElement GetRef(){
		SchemaElement e;
		WString ref=GetAttribute("ref");
		if(!ref.empty()){
			SchemaElement root=GetDocRoot();
			if(ref[3]==':') ref=ref.rightStr(-4);
			e=GetDocRoot().GetChildWithAttribute("xs:complexContent","name","",ref,0,true);
			if(e.isNull())e=GetDocRoot().GetChildWithAttribute("xs:complexContent","name","",ref+"_",0,true);
			if(e.isNull())e=GetDocRoot().GetChildWithAttribute("xs:complexContent","name","",ref+"_r",0,true);
			if(e.isNull())e=GetDocRoot().GetChildWithAttribute("xs:complexContent","name","",ref+"_re",0,true);
			if(e.isNull())e=GetDocRoot().GetChildWithAttribute("xs:complexContent","name","",ref+"_rp",0,true);
		}else{
			//cout<<"noref getref "<<*this<<endl;
		}
		return e;
	}


	//////////////////////////////////////////////////////////////////////

	WString GetBase(){

		WString name=GetCTName();
		if(name=="BaseElement") return "JDFElement";
		if(name=="Comment_Type") return "JDFElement";
		if(name=="Comment") return "JDFElement";
		if(name=="JDF") return "JDFElement";
		if(name=="Node") return "JDFElement";
		if(name=="Product") return "JDFNodeProcessGroup";
		if(name=="Resource") return "JDFElement";
		if(name=="JMF") return "JDFPool";
		if(name=="CustomerInfo") return "JDFResource";
		if(name=="NodeInfo") return "JDFResource";
		if(name=="Preview") return "JDFResource";
		if(name=="Audit") return "JDFElement";
		if(name=="Notification") return "JDFAudit";
		if(name=="PRGroupOccurrence") 
			return "JDFPRGroupOccurrenceBase";
		if(name=="PROccurrence") 
			return "JDFPRGroupOccurrence";
		if(name=="ArgumentValue") 
			return "JDFPRGroupOccurrenceBase";

		if(name=="Notification") return "JDFAudit";
		if(name=="MarkObject") return "JDFPlacedObject";
		if(name=="ContentObject") return "JDFPlacedObject";
		if(GetResourceList().hasString(name)){
			if(IsIntent(name)) return "JDFIntentResource";
			return "JDFResource";
		}
		if(name.rightStr(4)=="Span") return "";
		if(name=="telem") return "";
		if(name=="EmptyElement") return "";
		if(name=="ResourceElement") return "";
		if(name=="ResourceRef") return "";
		if((name.leftStr(3)=="JDF")&&(name.rightStr(4)=="Node"))
			return "";
		if(name.rightStr(13)=="ForcedComment") return "";

		if(name.rightStr(4)=="Pool") {
			if(name=="ColorPool") 			return"JDFResource";
			if(name=="TransferCurvePool") 			return"JDFResource";
			if(name=="PreflightReportRulePool") 			return"JDFResource";

			return "JDFPool";
		}


		WString base=GetElement("xs:complexContent").GetElement("xs:extension").GetAttribute("base");
		if(base.empty())
			base=GetElement("xs:complexContent").GetElement("xs:restriction").GetAttribute("base");

		if(base=="jdf:Layout_PlacedObject_lr") 
			return "JDFElement";
		if(base.startsWith("jdf:ParameterResource")) 
			return "JDFResource";
		if(base.startsWith("jdf:IntentResource")) 
			return "JDFIntentResource";
		if(base.startsWith("jdf:ConsumableResource") )
			return "JDFResource";
		if(base.startsWith("jdf:QuantityResource") )
			return "JDFResource";
		if(base.startsWith("jdf:PlaceHolderResource") )
			return "JDFResource";
		if(base.startsWith("jdf:HandlingResource") )
			return "JDFResource";
		if(base.startsWith("jdf:ImplementationResource") )
			return "JDFResource";
		if(base.startsWith("jdf:PhysicalResource") )
			return "JDFResource";
		if(base.startsWith("jdf:ResourceElement") )
			return "JDFElement";

		if(base=="jdf:AuditElement") return "JDFAudit";
		if(base=="jdf:TransferCurve") return "";
		if(base=="jdf:Message_")
			return "JDFMessage";

		if(IsMessage()){
			vWString vMesTypes=WString("Command Acknowledge Query Signal Response Registration").Tokenize(" ");
			for(int i=0;i<vMesTypes.size();i++){
				WString typ=vMesTypes[i];
				if(name==typ) return "JDFMessage";

			}
			if(base=="jdf:Command_m") return "JDFCommand";
			if(base=="jdf:Response_m") return "JDFResponse";
			if(base=="jdf:Acknowledge_m") return "JDFAcknowledge";
			if(base=="jdf:Query_m") return "JDFQuery";
			if(base=="jdf:Signal_m") return "JDFSignal";
			if(base=="jdf:Registration_m") return "JDFRegistration";

			if(base=="jdf:JMFAbstractCommand_") return "JDFCommand";
			if(base=="jdf:JMFAbstractResponse_") return "JDFResponse";
			if(base=="jdf:JMFAbstractAcknowledge_") return "JDFAcknowledge";
			if(base=="jdf:JMFAbstractQuery_") return "JDFQuery";
			if(base=="jdf:JMFAbstractSignal_") return "JDFSignal";
			if(base=="jdf:JMFAbstractRegistration_") return "JDFRegistration";

			if(base=="jdf:ResponseBaseType") return "JDFResponse";
			if(base=="jdf:CommandBaseType") return "JDFCommand";
			if(base=="jdf:AcknowledgeBaseType") return "JDFAcknowledge";
			if(base=="jdf:QueryBaseType") return "JDFQuery";
			if(base=="jdf:SignalBaseType") return "JDFSignal";
			if(base=="jdf:RegistrationBaseType") return "JDFRegistration";

			return "JDFMessageElement";

		}

		//				cout<<"getbase unknown for "<<name<<endl;

		return "JDFElement";
	}

	//////////////////////////////////////////////////////////////////////

	vElement GetAttVector(){
		vElement v=GetChildrenByTagName("xs:attribute");
		vElement vv=GetChildrenByTagName("xs:attributeGroup");
		for(int ag=0;ag<vv.size();ag++){
			SchemaElement e=vv[ag];
			WString name=e.GetAttribute("name");
			if(name.rightStr(2)=="_u")
				continue;
			if(name.leftStr(9)=="Partition")
				continue;
			v.AppendUnique(e.Group2Atts());
		}

		WString name=GetCTName();
		if(name!="Part"){
			for(int i=v.size()-1;i>=0;i--){
				WString attName=v[i].GetAttribute("name");
				WString locString;
				if(name!=L"ResourceInfo")
					locString=L" Location";
				if(name!=L"PRGroupOccurrenceBase")
					locString+=L" PageNumber";
				if((locString+WString("Class BlockName DocCopies DocIndex DocRunIndex DocSheetIndex FountainNumber LayerIDs Option PartVersion PreviewType RibbonName Run RunIndex RunTags RunPage Separation SetIndex SheetIndex SheetName Side SignatureName TileID WebName")).HasToken(attName,L" ")){
					if(name!=L"ScreenSelector")
						v.erase(v.begin()+i);
				}
			}
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	vElement Group2Atts(){
		vElement v;
		WString ref=GetAttribute("ref");
		WString refLong=ref;
		while(ref.rightStr(1)=="_")
			ref=ref.leftStr(-1);
		if(ref=="jdf:PartitionAttribs") return v; // handled by JDFPart			
		if(ref=="jdf:PartResourceAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:PartitionKeysAttribsForPreview")  return v; // handled by JDFPart			
		if(ref=="jdf:PartPhysicalResourceAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ResourceAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:PartResourceAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ResourceElementAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:QuantityAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:PlaceHolderAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ParameterAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ResourceElementAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ImplementationAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:HandlingAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ConsumableAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:PhysicalResourceAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:IntentAttribs")  return v; // handled by JDFPart			
		if(ref=="jdf:ResourcePartAttribs")  return v; // handled by JDFPart			

		ref=refLong;
		SchemaElement se;
		if(!ref.empty()){
			ref=ref.rightStr(-4); // zapp jdf:
			if(ref.rightStr(1)=="u"){
				ref=ref.leftStr(-1)+"r"; // replace all optional with the real thing
			}
			se=GetDocRoot().GetChildWithAttribute("xs:attributeGroup","name","",ref,0,false);
		}else{
			se=*this;
		}
		vElement v2=se.GetChildrenByTagName("xs:attribute");
		v.insert(v.end(),v2.begin(),v2.end());
		v2=se.GetChildrenByTagName("xs:attributeGroup");
		for(int i=0;i<v2.size();i++){
			se=v2[i];
			vElement v3=se.Group2Atts();
			v.insert(v.end(),v3.begin(),v3.end());
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	vWString EnumValues(WString name,bool bEscape, bool& bUnknown){
		bUnknown=false;
		SchemaElement se=GetElement("xs:simpleType").GetChildWithAttribute("xs:restriction","base","","xs:NMTOKEN");
		if(se.isNull())
			se=GetRoot().GetChildWithAttribute("xs:simpleType","name","","e"+name+"_");
		vWString v;
		v.push_back("Unknown");
		if(se.isNull()) {
			if(name.empty()) 
				name=GetAttribute("type");
			if (name[3]==':') 
				name=name.rightStr(-4);
			if (name.size()>6 && name[6]==':') 
				name=name.rightStr(-7);
			if(name=="NamedColor") // done by hand
				return v;
			if(name=="Orientation"&&!bDoOrientation) // done by hand
				return v;
			se=GetDocRoot();
			se=se.GetChildWithAttribute("xs:simpleType","name","",name);
			SchemaElement se2=se.GetChildWithAttribute("xs:restriction","base","","xs:NMTOKEN");
			if(se2.isNull()) 
				se2=se.GetChildWithAttribute("xs:restriction","base","","jdftyp:string");
			if(se2.isNull()) 
				se2=se.GetChildWithAttribute("xs:restriction","base","","jdftyp:EnumerationBaseType");

			if(se2.isNull()) {
				se2=se.GetElement("xs:restriction");
				if(!se2.isNull()){
					WString n2=se2.GetAttribute("base");
					if(n2!=name)
						return EnumValues(n2,bEscape,bUnknown);
				}
				cout<<"EnumValues null se: ";//<<*this;
				return v;
			}
			se=se2;
		}

		vElement ve=se.GetChildrenByTagName("xs:enumeration");
		for(int i=0;i<ve.size();i++){
			WString s=ve[i].GetAttribute("value");
			if(s.empty()) {
				cout << "whazzup ";//<<ve[i];
				continue;
			}
			if(s=="Unknown") {
				bUnknown=true;
				continue; // unknown always exists
			}
			if(bEscape)
				SchemaDoc::Escape(s," -*.,","_",-1);
			v.push_back(s);

		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	WString EnumHeader(){
		WString s;
		WString cType=GetCType(true);

		WString name=GetCTName();
		if(cType=="enum"){
			// Status is in too many places -> code by hand
			if((name=="Status"&&!bDoStatus)||(name=="EndStatus")||(name=="UpdatedStatus")||(name=="NodeStatus")||(name=="Orientation"&&!bDoOrientation)) 
				return "";
			if(name=="ModuleDrying") 
				return"";
			WString enumType="";
			if((name=="Type")&&(GetAttribute("type")=="xs:QName")){
				enumType="eMessage_";
			}
			bool bDummy;
			vWString vs=EnumValues(enumType,true,bDummy);
			if(vs.size()>1){
				WString st;
				st.SetvString(vs,","+name+"_",name+"_");
				s+="/**\n* Enumeration for attribute "+name+"\n*/\n";
				s+="\n	enum Enum"+name+"{"+st+"};\n";
			}
		}else if(cType.leftStr(5)=="enums"){
			vWString vs=WString(cType.rightStr(-6)).Tokenize();
			WString st;
			st.SetvString(vs,","+name+"_",name+"_");
			s+="/**\n* Enumeration for attribute "+name+"\n*/\n";
			s+="\n	enum Enum"+name+"{"+st+"};\n";
		}

		return s;
	}

	//////////////////////////////////////////////////////////////////////

	WString AtrValid(){
		WString cType=GetCType(true);
		if(cType.empty()) return ""; // flag for skip
		WString name=GetCTName("");

		WString rName=name;
		if(rName==L"Attribute")
			rName=L"AttributeAttribute";
		WString s="\t\tif(!Valid"+rName+"(level)) {\n\t\t\tvAtts.push_back(atr_";
		s+=name+");\n";
		s+="\t\t\tif(++n>=nMax)\n\t\t\t\treturn vAtts;\n\t\t};\n";
		return s;
	}

	//////////////////////////////////////////////////////////////////////

	bool IsCore(const WString& in){
		WString s=in;
		if((s.leftStr(3)=="JDF")&&(s.size()>3)) 
			s=s.rightStr(-3);

		if(s.rightStr(4)=="Span") {
			return true;
		}
		if(s=="ResourcePool") 
			return true;
		if(s=="RootProcess") 
			return true;
		if(s=="Resources") 
			return true;
		if(s=="ResourcesLeaf") 
			return true;
		if(s.endsWith(L"ResourceLeaf")) 
			return true;
		if(s.startsWith(L"ResourceUpdate")) 
			return true;
		if(s=="BaseElement") 
			return true;
		if(s=="ResourceLinkPool") 
			return true;
		if(s=="AuditPool") 
			return true;
		if(s=="RefElement") 
			return true;
		if(s.rightStr(4)=="Link" && s!="CreateLink" && s!="MoveLink" && s!="RemoveLink") {
			return true;
		}
		if((s.rightStr(8)=="Resource")&&(s.leftStr(3)!="JMF")&&(s!="PlaceHolderResource")&&(s!="MoveResource")&&(s!="RemoveResource")&&(s!="LinkResource")&&(s!="CreateResource")) {
			return true;
		}
		if(s.leftStr(9)=="_Template") {
			return true;
		}
		if(s=="JDF") 
			return true;
		if(s=="Audit") 
			return true;
		if(s=="Node") 
			return true;
		if(s.leftStr(7)=="Generic") 
			return true;
		if(s.leftStr(11)=="JMFAbstract") 
			return true;
		if(s.rightStr(5)=="State") 
			return true;
		if(s.rightStr(7)=="TypeObj") 
			return true;
		if(s=="BaseType") 
			return true;
		if(s=="ChildElements") 
			return true;
		if(s=="GenericProcess") 
			return true;
		if(s=="LROperation") 
			return true;
		if(s=="PlacedObject") 
			return true;
		if(s.empty()) 
			return true;
		if(s.leftStr(8)=="Abstract") 
			return true;
		if(s.endsWith("ResourceElement")) 
			return true;		

		return false;
	}

	//////////////////////////////////////////////////////////////////////
	WString EnumString(const vWString &vs){
		WString enums;
		for(unsigned int i=0;i<vs.size();i+=10){

			int jmax=min((vWString::size_type)(i+10u),vs.size());
			vWString vs2;
			for(int j=i;j<jmax;j++){
				vs2.push_back(vs[j]);
			}
			WString enums2;
			enums2.SetvString(vs2,",");
			enums+=enums2;
			if(i+10<vs.size()){
				enums+="\")\n\t+WString(L\",";
			}			
		}
		return enums;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	SchemaElement GetRootConstraint(WString  thisClass, WString& thisPath){

		thisClass=StripJDF(thisClass);

		if(thisClass=="ApprovalPerson"){
			thisClass="ApprovalParams";
			thisPath="ApprovalPerson/"+thisPath;
		}else if(thisClass=="BundleItem"){
			thisClass="Bundle";
			thisPath="BundleItem/"+thisPath;
		}else if(thisClass=="ColorSpaceSubstitute"){
			thisClass="ColorantControl";
			thisPath="ColorSpaceSubstitute/"+thisPath;
		}else if(thisClass=="ColorSpaceConversionOp"){
			thisClass="ColorSpaceConversionParams";
			thisPath="ColorSpaceConversionOp/"+thisPath;
		}else if(thisClass=="Drop"){
			thisClass="DeliveryParams";
			thisPath="Drop/"+thisPath;
		}else if(thisClass=="DropItem"){
			thisClass="DeliveryParams";
			thisPath="Drop/DropItem/"+thisPath;
		}else if(thisClass=="IconList"){
			thisClass="Device";
			thisPath="IconList/"+thisPath;
		}else if(thisClass=="Icon"){
			thisClass="Device";
			thisPath="IconList/Icon/"+thisPath;

		}else if(thisClass=="EndSheet"){
			thisClass="EndSheetGluingParams";
			thisPath="EndSheet/"+thisPath;

		}else if(thisClass=="Glue"){
			thisClass="GluingParams";
			thisPath="Glue/"+thisPath;

		}else if(thisClass=="Cover"){
			thisClass="IDPrintingParams";
			thisPath="Cover/"+thisPath;

		}else if(thisClass=="Signature"){
			thisClass="Layout";
			thisPath="Signature/"+thisPath;

		}else if(thisClass=="PageCell"){
			thisClass="LayoutPreparationParams";
			thisPath="PageCell/"+thisPath;
			/* tbd
			else if(thisClass=="PreflightResultsPool"){
			thisClass="Layout";
			thisPath="Signature/"+thisPath;
			*/

		}else if(thisClass=="MarkObject"){
			thisClass="Surface";
			thisPath="MarkObject/"+thisPath;

		}else if(thisClass=="PageCell"){
			thisClass="LayoutPreparationParams";
			thisPath="PageCell/"+thisPath;

		}else if(thisClass=="ArtDelivery"){
			thisClass="ArtDeliveryIntent";
			thisPath="ArtDelivery/"+thisPath;

		}else if(thisClass=="BindList"){
			thisClass="BindingIntent";
			thisPath="BindList/"+thisPath;

		}else if(thisClass=="BindItem"){
			thisClass="BindingIntent";
			thisPath="BindList/BindItem/"+thisPath;

		}else if(thisClass=="AdhesiveBinding"){
			thisClass="BindingIntent";
			thisPath="AdhesiveBinding/"+thisPath;

		}else if(thisClass=="BookCase"){
			thisClass="BindingIntent";
			thisPath="BookCase/"+thisPath;

		}else if(thisClass=="ChannelBinding"){
			thisClass="BindingIntent";
			thisPath="ChannelBinding/"+thisPath;

		}else if(thisClass=="CoilBinding"){
			thisClass="BindingIntent";
			thisPath="CoilBinding/"+thisPath;

		}else if(thisClass=="EdgeGluing"){
			thisClass="BindingIntent";
			thisPath="EdgeGluing/"+thisPath;

		}else if(thisClass=="HardCoverBinding"){
			thisClass="BindingIntent";
			thisPath="HardCoverBinding/"+thisPath;

		}else if(thisClass=="PlasticCombBinding"){
			thisClass="BindingIntent";
			thisPath="PlasticCombBinding/"+thisPath;

		}else if(thisClass=="RingBinding"){
			thisClass="BindingIntent";
			thisPath="RingBinding/"+thisPath;

		}else if(thisClass=="SaddleStitching"){
			thisClass="BindingIntent";
			thisPath="SaddleStitching/"+thisPath;

		}else if(thisClass=="SoftCoverBinding"){
			thisClass="BindingIntent";
			thisPath="SoftCoverBinding/"+thisPath;

		}else if(thisClass=="Tape"){
			thisClass="BindingIntent";
			thisPath="Tape/"+thisPath;

		}else if(thisClass=="Tabs"){
			thisClass="BindingIntent";
			thisPath="Tabs/"+thisPath;

		}else if(thisClass=="ThreadSewing"){
			thisClass="BindingIntent";
			thisPath="ThreadSewing/"+thisPath;

		}else if(thisClass=="WireCombBinding"){
			thisClass="BindingIntent";
			thisPath="WireCombBinding/"+thisPath;

		}else if(thisClass=="DropIntent"){
			thisClass="DeliveryIntent";
			thisPath="DropIntent/"+thisPath;

		}else if(thisClass=="DropItemIntent"){
			thisClass="DeliveryIntent";
			thisPath="DropIntent/DropItemIntent/"+thisPath;

		}else if(thisClass=="Pricing"){
			thisClass="DeliveryIntent";
			thisPath="Pricing/"+thisPath;

		}else if(thisClass=="EmbossingItem"){
			thisClass="EmbossingIntent";
			thisPath="EmbossingItem/"+thisPath;

		}else if(thisClass=="InsertList"){
			thisClass="InsertingIntent";
			thisPath="InsertList/"+thisPath;

		}else if(thisClass=="Insert"){
			thisClass="InsertingIntent";
			thisPath="InsertList/Insert/"+thisPath;

		}else if(thisClass=="NumberItem"){
			thisClass="NumberingIntent";
			thisPath="NumberItem/"+thisPath;

		}else if(thisClass=="PageData"){
			thisClass="PageList";
			thisPath="PageData/"+thisPath;

		}else if(thisClass=="ContentData"){
			thisClass="ContentList";
			thisPath="ContentData/"+thisPath;

		}else if(thisClass=="ProofItem"){
			thisClass="ProofingIntent";
			thisPath="ProofItem/"+thisPath;

		}else if(thisClass=="ShapeCut"){
			thisClass="ShapeCuttingIntent";
			thisPath="ShapeCut/"+thisPath;

		}else if(thisClass=="PageCell"){
			thisClass="LayoutPreparationParams";
			thisPath="PageCell/"+thisPath;	

		}else if(thisClass=="Ancestor"){
			thisClass="AncestorPool";
			thisPath="Ancestor/"+thisPath;
		}


		SchemaElement se=GetRoot().GetChildWithAttribute("xs:element","name","",thisClass).GetXPathElement("xs:annotation/xs:appinfo");
		return se;
	}

	//////////////////////////////////////////////////////////////////////
	SchemaElement GetPathConstraint(const WString & thisClass, const WString & thisPathIn){
		WString thisPath=thisPathIn;
		SchemaElement se=GetRootConstraint(thisClass,thisPath);
		vElement v=se.GetChildElementVector("Constraint");

		for(int i=0;i<v.size();i++){
			SchemaElement e=v[i];
			vWString vpath=e.GetAttribute("Path").Tokenize();
			if(vpath.hasString(thisPath))
				return e;
		}
		return SchemaElement();
	}

	//////////////////////////////////////////////////////////////////////
	WString StripJDF(const WString & thisClass)const{
		if(thisClass.leftStr(7)=="JDFAuto")
			return thisClass.rightStr(-7);
		return thisClass;
	}

	//////////////////////////////////////////////////////////////////////
	WString GetTokens(const WString &def=""){
		return GetXPathAttribute("xs:annotation/xs:appinfo/Constraint@Tokens",def);
	}
	//////////////////////////////////////////////////////////////////////
	WString GetUse(const WString &def=""){
		//		if(GetXPathAttribute("xs:annotation/xs:appinfo/Constraint@use","_not_there_")=="_not_there_")
		return GetAttribute("use",WString::emptyStr,def);
		//		return GetXPathAttribute("xs:annotation/xs:appinfo/Constraint@use",def);
	}
	//////////////////////////////////////////////////////////////////////
	WString GetMinOccurs(const WString & thisClass,const WString & thisPath,const WString &def=""){
		SchemaElement e=GetPathConstraint(thisClass,thisPath);
		if(!e.isNull())
			return e.GetAttribute("minOccurs",WString::emptyStr,def);
		SchemaElement parent=GetDeepParent("xs:sequence");
		if(!parent.isNull()){
			WString s=parent.GetAttribute("minOccurs",WString::emptyStr,"foo");
			if(s=="0")
				return s;
		}
		return GetAttribute("minOccurs",WString::emptyStr,def);
	}

	//////////////////////////////////////////////////////////////////////
	WString GetMaxOccurs(const WString & thisClass, const WString & thisPath, const WString &def="unbounded"){
		SchemaElement e=GetPathConstraint(thisClass,thisPath);
		if(!e.isNull())
			return e.GetAttribute("maxOccurs",WString::emptyStr,def);

		SchemaElement parent=GetDeepParent("xs:sequence");
		if(!parent.isNull()){
			WString s=parent.GetAttribute("maxOccurs",WString::emptyStr,"foo");
			if(s=="unbounded")
				return s;
		}
		return GetAttribute("maxOccurs",WString::emptyStr,def);
	}

	//////////////////////////////////////////////////////////////////////

	WString GetEnumType(WString enu){
		vWString vEnu=enu.Tokenize(":");
		if(vEnu.size()<=1)
			return "Enum"+enu;
		return vEnu[0]+"::Enum"+vEnu[1];

	}
	//////////////////////////////////////////////////////////////////////

	WString AtrHeader(int iLoop, WString cName){
		WString s;
		if((iLoop==0)||(iLoop==2))
			return s;
		WString name=GetCTName("");


		if(name.empty()) {
			cout <<"AtrHeader: illegal name in :\n";//<<*this;
			return "";
		}
		WString cType=GetCType(true);
		if(cType.empty()) 
			return ""; // flag for skip

		WString xmlType=GetAttribute("type");
		WString def=GetAttribute("default");
		if(def.empty())
			WString def=GetAttribute("fixed");

		// ancestor attributes have no defaults!
		if(cType==L"Ancestor")
			def="";

		WString defComment;
		WString reqString="false";
		WString NSString=",WString::emptyStr";
		// used for incomplete validation
		WString rName=name;

		allAtts.AppendUnique(name);

		if(rName==L"Attribute")
			rName="AttributeAttribute";
		if(GetUse()=="required")
			reqString="RequiredLevel(level)";


		if(cType=="enum"){
			WString eType=name;
			if(name=="EndStatus" || name=="NodeStatus") 
				eType="JDFElement::Status";
			if((name=="Status")&&(cName=="JDFAutoResourceInfo")) 
				eType="JDFResource::Status";
			if(name=="UpdatedStatus") 
				eType="JDFResource::Status";
			if(name=="ModuleDrying") 
				eType="Drying";
			if(xmlType=="jdf:NamedColor")
				eType="NamedColor";
			if(xmlType=="jdftyp:NamedColor")
				eType="NamedColor";
			if(name.endsWith("Orientation")&&name!="FinishedPageOrientation")
				eType="Orientation";
			if(name=="FoldLay") 
				eType="Orientation";

			if(!def.empty()) {
				defComment="; defaults to "+def;
				def=","+eType+"_"+def;
				NSString=",WString::emptyStr";
			}
			WString enumType="";
			if((name=="Type")&&(GetAttribute("type")=="xs:QName")){
				enumType="eMessage_";
			}

			if(iLoop==1){
				bool bDummy;
				vWString vEnums=EnumValues(enumType,true,bDummy);
				if(vEnums.size()>1){
					WString enums=EnumString(vEnums);

					if((name!="Status" || bDoStatus)&&(name!="EndStatus")&&(name!="NodeStatus")&&(name!="UpdatedStatus")&&(name!="ModuleDrying")&&(eType!="NamedColor")&&(eType!="Orientation"||bDoOrientation)){
						s+="/**\n* Enumeration strings for "+name+"\n* @return const WString& comma separated list of enumerated string values \n*/\n";
						s+="\tstatic const WString& "+name+"String();\n";
						s+="/**\n* Enumeration string for enum value\n* @param Enum"+name+" value the enumeration to translate\n* @return WString the string representation of the enumeration\n*/\n";
						s+="\tstatic WString "+name+"String(Enum"+name+" value);\n";
					}
				}

				s+="/**\n* Set attribute "+name+"\n* @param "+GetEnumType(eType)+" value the value to set the attribute to\n*/\n";
				s+="\tvirtual void Set"+rName+"( "+GetEnumType(eType)+" value);\n\n";
				s+="/**\n* Typesafe enumerated attribute "+name+defComment+"\n* @return Enum"+name+"the enumeration value of the attribute\n*/\n";
				s+="\tvirtual "+GetEnumType(eType)+" Get"+rName+"() const;\n\n";
				s+="/**\n* Typesafe attribute validation of "+name+"\n* @param EnumValidationLevel level element validation level \n* @return bool true if valid\n*/\n";
				s+="\tvirtual bool Valid"+rName+"(EnumValidationLevel level=ValidationLevel_Complete) const;\n";
			}else if(iLoop==3){
				bool bUnknown;
				WString unknownString;

				vWString vEnums=EnumValues(enumType,false,bUnknown);
				if(bUnknown)
					unknownString=",WString::emptyStr,true";

				if(vEnums.size()>1){
					WString enums=EnumString(vEnums);

					if((name!="Status" || bDoStatus)&&(name!="EndStatus")&&(name!="NodeStatus")&&(name!="UpdatedStatus")&&(name!="ModuleDrying")&&(eType!="NamedColor")&&(eType!="Orientation"||bDoOrientation)){
						s+="///////////////////////////////////////////////////////////////////////\n\n";
						s+="\tconst WString& "+cName+"::"+name+"String(){\n\t\tstatic const WString enums=WString(L\""+enums+"\");\n\t\treturn enums;\n\t};\n\n";
						s+="///////////////////////////////////////////////////////////////////////\n\n";
						s+="\tWString "+cName+"::"+name+"String(Enum"+name+" value){\n\t\treturn "+name+"String().Token(value,WString::comma);\n\t};\n\n";
					}
				}

				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tvoid "+cName+"::Set"+rName+"( "+GetEnumType(eType)+" value){\n\tSetEnumAttribute(atr_"+name+",value,"+eType+"String()"+unknownString+");\n};\n";
				s+="/////////////////////////////////////////////////////////////////////////\n";
				if((name!="UpdatedStatus")&&(GetEnumType(eType).Tokenize(L":").size()==1)){
					s+="\t "+cName+"::"+GetEnumType(eType)+" "+cName+":: Get"+rName+"() const {\n\treturn ("+GetEnumType(eType)+") GetEnumAttribute(atr_"+name+","+eType+"String()"+NSString+def+");\n};\n";
				}else{
					s+="\t "+GetEnumType(eType)+" "+cName+"::Get"+rName+"() const {\n\treturn ("+GetEnumType(eType)+") GetEnumAttribute(atr_"+name+","+eType+"String()"+NSString+def+");\n};\n";
				}
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tbool "+cName+"::Valid"+rName+"(EnumValidationLevel level) const {\n\t\treturn ValidEnumAttribute(atr_"+name+","+eType+"String(),"+reqString+unknownString+");\n\t};\n";

			}
		}
		else if(cType.leftStr(5)=="enums")
		{
			WString eType=name;
			if(name=="EndStatus" || name=="NodeStatus") 
				eType="JDFElement::Status";
			if(name=="ModuleDrying") 
				eType="Drying";
			if(!def.empty()) {
				//				cout << "****************\nattention evil defs in "<<name<<"\n*******************"<<endl;
				//				def="";
				defComment="; defaults to "+def;
				def=",(unsigned int)"+eType+"_"+def;
				NSString=",WString::emptyStr";
			}
			WString enumType="";
			if((name=="Type")&&(GetAttribute("type")=="xs:QName")){
				enumType="eMessage_";
			}

			if(iLoop==1){
				vWString vs=WString(cType.rightStr(-6)).Tokenize();
				WString enums=EnumString(vs);
				if((name!="Status" || bDoStatus)&&(name!="EndStatus")&&(name!="NodeStatus")&&(name!="UpdatedStatus")&&(name!="ModuleDrying")&&(eType!="NamedColor")&&(eType!="Orientation"||bDoOrientation)){
					s+="/**\n* Enumeration strings for "+name+"\n* @return const WString& comma separated list of enumerated string values \n*/\n";
					s+="\tstatic const WString& "+name+"String();\n";
					s+="/**\n* Enumeration string for enum value\n* @param Enum"+name+" value the enumeration to translate\n* @return WString the string representation of the enumeration\n*/\n";
					s+="\tstatic WString "+name+"String(Enum"+name+" value);\n";
				}
				s+="/**\n* Append value to the attribute "+name+"\n* @param Enum"+eType+" value the value to set the attribute to\n* @return vint the vector of enumerations that are set - cast to int\n*/\n";
				s+="\tvirtual vint Add"+rName+"( Enum"+eType+" value);\n";
				s+="/**\n* Remove value from the attribute "+name+"\n* @param Enum"+eType+" value the value to set the attribute to\n* @return vint the vector of enumerations that are set - cast to int\n*/\n";
				s+="\tvirtual vint Remove"+rName+"( Enum"+eType+" value);\n";
				s+="/**\n* Typesafe enumerated attribute "+name+defComment+"\n* @return Enum"+name+"the enumeration value of the attribute\n*/\n";
				s+="\tvirtual vint Get"+rName+"() const;\n";
				s+="/**\n* Set value of the attribute "+name+"\n* @param Enum"+eType+" value the value to set the attribute to\n* @return vint the vector of enumerations that are set - cast to int\n*/\n";
				s+="\tvirtual void Set"+rName+"( Enum"+eType+" value);\n";
				s+="/**\n* Set value of the attribute "+name+" to a list\n* @param vint value the value to set the attribute to\n* @return vint the vector of enumerations that are set - cast to int\n*/\n";
				s+="\tvirtual void Set"+rName+"( const vint& value);\n";
				s+="/**\n* Typesafe attribute validation of "+name+"\n* @param EnumValidationLevel level element validation level \n* @return bool true if valid\n*/\n";
				s+="\tvirtual bool Valid"+rName+"(EnumValidationLevel level=ValidationLevel_Complete) const;\n";
			}else if(iLoop==3){
				WString cType2=GetCType(true,"","",false);
				vWString vs=WString(cType2.rightStr(-6)).Tokenize();
				WString enums=EnumString(vs);
				if((name!="Status" || bDoStatus)&&(name!="EndStatus")&&(name!="NodeStatus")&&(name!="UpdatedStatus")&&(name!="ModuleDrying")&&(eType!="NamedColor")&&(eType!="Orientation"||bDoOrientation)){
					s+="///////////////////////////////////////////////////////////////////////\n\n";
					s+="\tconst WString& "+cName+"::"+name+"String(){\n\t\tstatic const WString enums=WString(L\""+enums+"\");\n\t\treturn enums;\n\t};\n\n";
					s+="///////////////////////////////////////////////////////////////////////\n\n";
					s+="\tWString "+cName+"::"+name+"String(Enum"+name+" value){\n\t\treturn "+name+"String().Token(value,WString::comma);\n\t};\n\n";
				}

				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tvint "+cName+"::Add"+rName+"( Enum"+eType+" value){\n\treturn AddEnumerationsAttribute(atr_"+name+",value,"+eType+"String());\n};\n";
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tvint "+cName+"::Remove"+rName+"( Enum"+eType+" value){\n\treturn RemoveEnumerationsAttribute(atr_"+name+",value,"+eType+"String());\n};\n";
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tvint "+cName+"::Get"+rName+"() const {\n\treturn GetEnumerationsAttribute(atr_"+name+","+eType+"String()"+NSString+def+");\n};\n";
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tvoid "+cName+"::Set"+rName+"( Enum"+eType+" value){\n\tSetEnumAttribute(atr_"+name+",value,"+eType+"String());\n};\n";
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tvoid "+cName+"::Set"+rName+"( const vint& value){\n\tSetEnumerationsAttribute(atr_"+name+",value,"+eType+"String());\n};\n";
				s+="/**\n* Typesafe attribute validation of "+name+"\n* @param EnumValidationLevel level element validation level \n* @return bool true if valid\n*/\n";
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tbool "+cName+"::Valid"+rName+"(EnumValidationLevel level) const {\n\t\treturn ValidEnumerationsAttribute(atr_"+name+","+eType+"String(),"+reqString+");\n\t};\n";

			}
		}else{
			if(!def.empty()) {
				defComment="; defaults to "+def;
				NSString=",WString::emptyStr";
			}
			if(iLoop==1){
				if(cType.find(WString("Range"))!=cType.npos){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\tvirtual void Set"+rName+"(const "+cType+"& value);\n";
				}else if((cType=="JDFNumberList")||(cType=="JDFIntegerList")){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\tvirtual void Set"+name+"(const "+cType+"& value);\n";
				}else if(cType=="JDFDate"){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\tvirtual void Set"+rName+"("+cType+" value=JDFDate());\n";
				}else if(cType=="JDFDuration"){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\tvirtual void Set"+rName+"("+cType+" value=JDFDuration());\n";
				}else if((cType=="WString")||(cType=="vWString")||(cType=="JDFRectangle")||(cType=="JDFXYPair")||(cType=="JDFShape")||(cType=="JDFMatrix")||(cType=="JDFLabColor")||(cType=="JDFRGBColor")||(cType=="JDFCMYKColor")){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\tvirtual void Set"+rName+"(const "+cType+"& value);\n";
				}else{
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\tvirtual void Set"+rName+"("+cType+" value);\n";
				}

				if(cType=="int"){
					s+="/**\n* Get integer attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) def=","+def;
					s+="\tvirtual "+cType+" Get"+rName+"() const;\n";
				}else if(cType=="double"){
					s+="/**\n* Get double attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) def=","+def;
					s+="\tvirtual "+cType+" Get"+rName+"() const;\n";
				}else if(cType=="bool"){
					s+="/**\n* Get bool attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) def=","+def;
					s+="\tvirtual "+cType+" Get"+rName+"() const;\n";
				}else if(cType.find(WString("Range"))!=cType.npos){
					s+="/**\n* Get range attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) {
						def=",L\""+def+"\"";
					}
					s+="\tvirtual "+cType+" Get"+rName+"() const;\n";
				}else {
					if(!def.empty()) {
						defComment="; defaults to "+def;
						def=",L\""+def+"\"";
					}
					s+="/**\n* Get string attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					s+="\tvirtual "+cType+" Get"+rName+"() const;\n";
				}
				s+="/**\n* Typesafe attribute validation of "+name+"\n* @param EnumValidationLevel level of attribute validation \n* @return bool true if valid\n*/\n";
				s+="\tvirtual bool Valid"+rName+"(EnumValidationLevel level=ValidationLevel_Complete) const;\n";


			}else if(iLoop==3){
				if(cType.find(WString("Range"))!=cType.npos){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\t void "+cName+"::Set"+rName+"(const "+cType+"& value){\n\tSetAttribute(atr_"+name+",value.GetString());\n};\n";
				}else if((cType=="JDFNumberList")||(cType=="JDFIntegerList")){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\t void "+cName+"::Set"+name+"(const "+cType+"& value){\n\tSetAttribute(atr_"+name+",value.GetString());\n};\n";
				}else if(cType=="JDFDate"){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\t void "+cName+"::Set"+rName+"("+cType+" value){\n\tSetAttribute(atr_"+name+",value.DateTimeISO());\n};\n";
				}else if(cType=="JDFDuration"){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\t void "+cName+"::Set"+rName+"("+cType+" value){\n\tSetAttribute(atr_"+name+",value.DurationISO());\n};\n";
				}else if((cType=="WString")||(cType=="vWString")||(cType=="JDFRectangle")||(cType=="JDFXYPair")||(cType=="JDFShape")||(cType=="JDFMatrix")||(cType=="JDFLabColor")||(cType=="JDFRGBColor")||(cType=="JDFCMYKColor")){
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\t void "+cName+"::Set"+rName+"(const "+cType+"& value){\n\tSetAttribute(atr_"+name+",value);\n};\n";
				}else{
					s+="/**\n* Set attribute "+name+"\n*@param "+cType+" value: the value to set the attribute to\n*/\n";
					s+="\t void "+cName+"::Set"+rName+"("+cType+" value){\n\tSetAttribute(atr_"+name+",WString::valueOf(value));\n};\n";
				}

				if(cType=="int"){
					s+="/**\n* Get integer attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) def=","+def;
					s+="\t "+cType+" "+cName+"::Get"+rName+"() const {\n\treturn GetIntAttribute(atr_"+name+""+NSString+def+");\n};\n";
				}else if(cType=="double"){
					s+="/**\n* Get double attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) def=","+def;
					s+="\t "+cType+" "+cName+"::Get"+rName+"() const {\n\treturn GetRealAttribute(atr_"+name+""+NSString+def+");\n};\n";
				}else if(cType=="bool"){
					s+="/**\n* Get bool attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) def=","+def;
					s+="\t "+cType+" "+cName+"::Get"+rName+"() const {return GetBoolAttribute(atr_"+name+""+NSString+def+");\n};\n";
				}else if(cType.find(WString("Range"))!=cType.npos){
					s+="/**\n* Get range attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					if(!def.empty()) {
						def=",L\""+def+"\"";
					}
					s+="\t "+cType+" "+cName+"::Get"+rName+"() const {\n\treturn GetAttribute(atr_"+name+""+NSString+def+");\n};\n";
				}else {
					if(!def.empty()) {
						defComment="; defaults to "+def;
						def=",L\""+def+"\"";
					}
					s+="/**\n* Get string attribute "+name+"\n* @return "+cType+" the vaue of the attribute "+defComment+"\n*/\n";
					s+="\t "+cType+" "+cName+"::Get"+rName+"() const {\n\treturn GetAttribute(atr_"+name+""+NSString+def+");\n};\n";
				}
				s+="/////////////////////////////////////////////////////////////////////////\n";
				s+="\tbool "+cName+"::Valid"+rName+"(EnumValidationLevel level) const {\n\t\treturn ValidAttribute(atr_"+name+","+GetAttributeEnumType()+","+reqString+");\n\t};\n";
			}
		}


		return s;
	}

	//////////////////////////////////////////////////////////////////////

	WString PPHeader(WString thisClass, int iLoop){ // fill preprocessor
		WString s;
		WString cType=GetCType(false,thisClass);
		//			cout <<thisClass<<" "<<cType<<"\n"<<*this;

		bool bCore=false;
		if (IsCore(cType)){
			bCore=true;
			WString base=GetBase();
			if((base!="JDFResource")&&(cType=="JDFResourceLink"))
				bCore=false;
			if((base!="JDFResource")&&(cType=="JDFResource"))
				bCore=false;
			if(cType=="JDFNode")
				bCore=false;
		}
		if(bCore)
			return "";
		if(cType.rightStr(4)=="Span") return "";
		if(cType.leftStr(7)=="JDFSpan") return "";
		if(cType=="JDFElement") return "";

		if(cType.empty()){
			cType=GetCType(false);
			if(cType=="JDFJDF") return "";
			cout<<"PPHeader ??? ";//<<*this;
		}
		if(iLoop==3){
			s+="#include \"jdf/wrapper/"+cType+".h\"\n";
		}else if(iLoop==1){
			s+="class "+cType+";\n";

		}
		return s;
	}

	//////////////////////////////////////////////////////////////////////

	bool IsResource(){
		if(isNull()) return false;
		WString type=GetAttribute("type");
		if(!type.empty()) {
			if(type[3]==':') type=type.rightStr(-4);
			SchemaElement se=GetDocRoot();
			se=se.GetChildWithAttribute("xs:complexType","name","",type,false);
			return se.IsResource();
		}
		WString name=GetCTName();
		if(name=="CustomerInfo") return false; // base  
		if(name=="BusinessInfo") return false; // base  
		if(name=="AncestorPool") return false; // base  
		if(name=="Ancestor") return false; // base  
		WString base=GetBase();
		if(base.rightStr(8)=="Resource") return true;
		if(base=="JDFResource") return true;
		return false;
	}
	//////////////////////////////////////////////////////////////////////
	bool IsPart(){
		if(!IsResource()) return false;
		WString name=GetCTName();
		if(name=="CustomerInfo") return false; // base  
		if(name=="SeparationSpec") return false; // base  
		if(name=="FileAlias") return false; // base  
		if(name=="FileSpec") return false; // base  
		if(name=="Part") return false; // base  
		if(name=="DynamicInput") return false; // base 
		if(name=="DynamicField") return false; // base 
		WString s=GetAttribute("name");
		SchemaDoc::Escape(s,"-*+","_",-1);
		if(s.empty()){ // recursive call
			SchemaElement se=GetParentNode();
			if(se.isNull()) {
				return false;
			}
			return se.IsPart();
		}
		if(s.rightStr(2)=="_r") {
			//			cout<<"part :"<<name<<endl;
			return true;
		}

		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool IsIntent(WString name){
		if(name.leftStr(7)=="JDFAuto") name=name.leftStr(-7);
		if(name.leftStr(3)=="JDF") name=name.leftStr(-3);
		if(name.rightStr(6)=="Intent") return true;
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	bool IsMessageElement(){
		WString base=GetElement("xs:complexContent").GetElement("xs:extension").GetAttribute("base");
		if(base.empty())
			base=GetElement("xs:complexContent").GetElement("xs:restriction").GetAttribute("base");
		if(base.startsWith(L"jdf:JMFAbstract"))
			return true;

		if(base=="jdf:Registration_m") return true;
		if(base=="jdf:Command_m") return true;
		if(base=="jdf:Response_m") return true;
		if(base=="jdf:Acknowledge_m") return true;
		if(base=="jdf:Query_m") return true;
		if(base=="jdf:Signal_m") return true;
		if(base=="jdf:RegistrationBaseType") return true;
		if(base=="jdf:ResponseBaseType") return true;
		if(base=="jdf:CommandBaseType") return true;
		if(base=="jdf:AcknowledgeBaseType") return true;
		if(base=="jdf:QueryBaseType") return true;
		if(base=="jdf:SignalBaseType") return true;

		return false;
	}
	//////////////////////////////////////////////////////////////////////

	bool IsMessage(){
		WString type=GetAttribute("type");
		if(!type.empty()) {
			if(type[3]==':') type=type.rightStr(-4);
			SchemaElement se=GetDocRoot();
			se=se.GetChildWithAttribute("xs:complexType","name","",type,false);
			return se.IsMessage();
		}
		WString	name=GetCTName("",true);
		if(name.leftStr(7)=="JDFAuto") name = name.rightStr(-7);
		if(name.leftStr(3)=="JDF") name = name.rightStr(-3);
		if(name=="Acknowledge") return true; // base  
		if(name=="JMF") return true; // base  
		if(name=="Message") return true; // base  
		if(name=="Command") return true; // base  
		if(name=="Query") return true; // base  
		if(name=="Response") return true; // base  
		if(name=="Signal") return true; // base  
		if(name=="Registration") return true; // base  
		if(name=="AcknowledgeBaseType") return true; // base  
		if(name=="CommandBaseType") return true; // base  
		if(name=="QueryBaseType") return true; // base  
		if(name=="ResponseBaseType") return true; // base  
		if(name=="SignalBaseType") return true; // base  
		if(name=="RegistrationBaseType") return true; // base  
		if(name.rightStr(2)=="_m") return true;

		return IsMessageElement();
	}

	//////////////////////////////////////////////////////////////////////

	WString ElmHeader(WString thisClass,int iDataTyp, int iLoop){
		WString s;
		WString name=GetCTName("");
		WString namTyp=name;
		//		cout<<"elmh "<<name<<endl;
		if(name=="Resource") 
			return "";
		if(name=="ResourceLink") 
			return "";
		if(name=="Node") 
			name="JDF";
		if(namTyp=="Disposition")
			namTyp="DispositionElem";
		if(name.empty()) {
			cout <<"ElmHeader: illegal name in :\n";//<<*this;
			return "";
		}
		WString cType=GetCType(false,thisClass);
		if(cType.empty()) 
			return "";

		WString mo=GetMaxOccurs(thisClass,name);

		if(iLoop==1){ // autoh
			s+="\n/** Get Element "+name+"\n* \n";
			allElms.AppendUnique(name);

			if(mo=="1"){
				s+="* @return "+cType+" The element\n*/\n";
				s+="\t"+cType+" GetCreate"+namTyp+"();\n\n";
				s+="/**\n* const get element "+name+"\n*@return  "+cType+" The element\n*/\n";
				s+="\t"+cType+" Get"+namTyp+"()const;\n";
				s+="/**\n* Append element "+name+"\n * \n*/\n";
				s+="\t"+cType+" Append"+namTyp+"();\n";
				if(name=="Part"){ 
					s+="//@{\n		/**\n		* get part map vector\n		* @return vector of mAttribute, one for each part\n		*/\n		vmAttribute GetPartMapVector()const;\n		\n		";
					s+="		/**\n		* set part to mPart\n		* @param mAttribute& mPart attribute map for the part to set\n		*/\n	void SetPartMap(const mAttribute & mPart);\n";
					s+="		/**\n		* remove the part defined in mPart\n		* @param mAttribute& mPart attribute map for the part to remove\n		*/\n		void RemovePartMap(const mAttribute & mPart);\n";
					s+="		/**\n		* check whether the part defined in mPart is included\n		* @param mAttribute& mPart attribute map for the part to remove\n		* @return bool if the part exists\n		*/\n		bool HasPartMap(const mAttribute & mPart);\n		//@}\n";
				}
			}else{
				s+="* @param int iSkip number of elements to skip\n";
				s+="* @return "+cType+" The element\n*/\n";
				s+="\t"+cType+" GetCreate"+namTyp+"(int iSkip=0);\n\n";

				s+="/**\n* const get element "+name+"\n";
				s+="* @param int iSkip number of elements to skip\n";
				s+="* @return "+cType+" The element\n*/\n";
				s+="\t"+cType+" Get"+namTyp+"(int iSkip=0)const;\n";				


				s+="/**\n* Append element "+name+"\n */\n";
				s+="\t"+cType+" Append"+namTyp+"();\n";
				if(name=="Part"){ 
					s+="//@{\n		/**\n		* get part map vector\n		* @return vector of mAttribute, one for each part\n		*/\n		vmAttribute GetPartMapVector()const;\n		\n		";
					s+="        /**\n		* set all parts to those define in vParts\n		* @param vmAttribute& vParts vector of attribute maps for the parts\n		*/\n		void SetPartMapVector(const vmAttribute & vParts);\n";
					s+="		/**\n		* set part to mPart\n		* @param mAttribute& mPart attribute map for the part to set\n		*/\n	void SetPartMap(const mAttribute & mPart);\n";
					s+="		/**\n		* remove the part defined in mPart\n		* @param mAttribute& mPart attribute map for the part to remove\n		*/\n		void RemovePartMap(const mAttribute & mPart);\n";
					s+="		/**\n		* check whether the part defined in mPart is included\n		* @param mAttribute& mPart attribute map for the part to remove\n		* @return bool if the part exists\n		*/\n		bool HasPartMap(const mAttribute & mPart);\n		//@}\n";
				}
			}
			// messages don't have refelements
			if(iDataTyp==1) return s; // message
			if(IsResource()){
				s+="/**\n* create inter-resource link to refTarget\n* @param "+cType+"& refTarget the element that is referenced\n*@return JDFRefElement the referenced element\n*/\n";
				s+="\tJDFRefElement Ref"+namTyp+"("+cType+"& refTarget);\n";
			}
		}else if(iLoop==3){ // autoc
			if(mo=="1"){
				s+="\n"+cType+" "+thisClass+"::Get"+namTyp+"()const{\n\t"+cType+" e=GetElement(elm_"+name+");\n\treturn e;\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";
				s+="\n"+cType+" "+thisClass+"::GetCreate"+namTyp+"(){\n\t"+cType+" e=GetCreateElement(elm_"+name+");\n\te.init();\n\treturn e;\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";
				s+="\n"+cType+" "+thisClass+"::Append"+namTyp+"(){\n\t"+cType+" e=AppendElementN(elm_"+name+",1);\n\te.init();\n\treturn e;\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";

				if(name=="Part"){ 
					s+="//////////////////////////////////////////////////////////////////////\n\n	vmAttribute "+thisClass+"::GetPartMapVector()const{\n		return JDFElement::GetPartMapVector();\n	}\n\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	void "+thisClass+"::SetPartMap(const mAttribute & mPart){\n		JDFElement::SetPartMap(mPart);\n	}\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	void "+thisClass+"::RemovePartMap(const mAttribute & mPart){\n		JDFElement::RemovePartMap(mPart);\n	}\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	bool "+thisClass+"::HasPartMap(const mAttribute & mPart){\n		return JDFElement::HasPartMap(mPart);\n	}\n";	
				}
			}else{
				s+="\n"+cType+" "+thisClass+"::Get"+namTyp+"(int iSkip)const{\n\t"+cType+" e=GetElement(elm_"+name+",WString::emptyStr,iSkip);\n\treturn e;\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";
				s+="\n"+cType+" "+thisClass+"::GetCreate"+namTyp+"(int iSkip){\n\t"+cType+" e=GetCreateElement(elm_"+name+",WString::emptyStr,iSkip);\n\te.init();\n\treturn e;\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";
				s+="\n"+cType+" "+thisClass+"::Append"+namTyp+"(){\n\t"+cType+" e=AppendElement(elm_"+name+");\n\te.init();\n\treturn e;\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";
				if(name=="Part"){ 
					s+="//////////////////////////////////////////////////////////////////////\n\n	vmAttribute "+thisClass+"::GetPartMapVector()const{\n		return JDFElement::GetPartMapVector();\n	}\n\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	void "+thisClass+"::SetPartMapVector(const vmAttribute & vParts){\n		JDFElement::SetPartMapVector(vParts);\n	}\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	void "+thisClass+"::SetPartMap(const mAttribute & mPart){\n		JDFElement::SetPartMap(mPart);\n	}\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	void "+thisClass+"::RemovePartMap(const mAttribute & mPart){\n		JDFElement::RemovePartMap(mPart);\n	}\n";
					s+="//////////////////////////////////////////////////////////////////////\n\n	bool "+thisClass+"::HasPartMap(const mAttribute & mPart){\n		return JDFElement::HasPartMap(mPart);\n	}\n";	
				}
			}
			// messages don't have refelements
			if(iDataTyp==1) return s; // message
			if(IsResource()){
				s+="// element resource linking \nJDFRefElement "+thisClass+"::Ref"+namTyp+"("+cType+"& refTarget){\n\treturn RefElement(refTarget);\n};\n";
				s+="/////////////////////////////////////////////////////////////////////\n";
			}
		}

		return s;
	}

	//////////////////////////////////////////////////////////////////////

	WString ElmValid(WString thisClass){
		WString name=GetCTName("");
		if(name.empty()) {
			cout <<"ElmValid: illegal name in :\n";//<<*this;
			return "";
		}
		WString cType=GetCType(false,thisClass);
		if(cType.empty()) return "";

		int iMin=GetMinOccurs(thisClass,name,"0");
		WString s=GetMaxOccurs(thisClass,name,"unbounded");
		if(s.empty()){
			if (GetParentNode().GetNodeName()=="xs:sequence"){
				s=GetParentNode().GetAttribute("maxOccurs","","");
			}
		}

		bool unbound=(s=="unbounded");
		int iMax=-1;
		if(!unbound) {
			iMax=s.empty()?1:s;		
		}
		s="\t\tnElem=NumChildElements(elm_"+name+");\n";
		if(iMin) {
			s+="\t\tif((level>=ValidationLevel_Complete)&&(nElem<"+WString(iMin)+")) {\n\t\tvElem.AppendUnique(elm_"+name+");\n";
			s+="\t\t\tif (++n>=nMax)\n\t\t\treturn vElem;\n\t\t}\n";
		}
		if(!unbound){
			s+="\t\tif(nElem>"+WString(iMax)+"){ //bound error\n\t\t\tvElem.AppendUnique(elm_"+name+");\n";
			s+="\t\t\tif (++n>=nMax)\n\t\t\t\treturn vElem;\n\t\t}";
		}else{
			iMax=999; // flag big
		}

		WString namTyp=name;
		if(namTyp=="Disposition")
			namTyp="DispositionElem";

		if(iMax>1){ 

			s+="\n\t\tfor(i=0;i<nElem;i++){\n";		
			s+="\t\t\tif (!Get"+namTyp+"(i).IsValid(level)) {\n\t\t\t\tvElem.AppendUnique(elm_"+name+");\n\t\t\t\tif (++n>=nMax)\n\t\t\t\t\treturn vElem;\n\t\t\t\tbreak;\n\t\t\t}\n";
			s+="\t\t}\n";
		}else{
			s+="else if(nElem==1){\n\t\t\tif(!Get"+namTyp+"().IsValid(level)) {\n\t\t\t\tvElem.AppendUnique(elm_"+name+");\n\t\t\t\tif (++n>=nMax)\n\t\t\t\t\treturn vElem;\n\t\t\t}\n\t\t}\n";
		}
		return s;

	}

	//////////////////////////////////////////////////////////////////////

	bool IsAbstract(WString &name){
		if(IsCore(name)) return true;
		if(name=="Resource") return true;
		if(name=="ResourceLink") return true;
		if(name=="Part") return true;
		if(name=="BaseElement") return true;
		if(name=="JMF") return true;
		if(name=="JDF") return true;
		if(name.rightStr(8)=="Resource") return true;
		if(name=="Audit") return true;
		if(name=="PRGroupOccurrenceBase") 
			return true;
		return false;

	}
	//////////////////////////////////////////////////////////////////////

	void LicOpen(WString hName, ofstream &h){
		unlink(hName.peekBytes());
		h.open(hName.peekBytes(),ios::out);
		{
			ifstream licFile;
			licFile.open("cip4license.txt",ios::in);
			while(42){
				char b[1024];
				licFile.read(b,1024);
				int i=licFile.gcount();
				if(i<=0) break;
				h.write(b,i);
			}

		}

		h<<"//EndCopyRight\n";
	}

	//////////////////////////////////////////////////////////////////////
	void ToCode(WString schemaFileName){


		SchemaElement content=GetElement("xs:complexContent");
		if(content.isNull()) content=GetElement("xs:simpleContent");
		SchemaElement extension=content.GetElement("xs:extension");
		if(extension.isNull())
			extension=content.GetElement("xs:restriction");
		if(extension.isNull()) 
			extension=*this; // for base elements it's inlined

		SchemaElement elmseq=extension.GetElement("xs:sequence");
		int iDataTyp=0;
		if(IsMessage()) 
			iDataTyp=1;
		WString baseName=GetBase();
		if(baseName=="JDFAudit") iDataTyp=2; // audits

		WString schemaName=GetCTName();
		if(schemaName=="Shape") 
			schemaName="ShapeElement";

		for(int loop=0;loop<4;loop++){
			WString cName;
			WString superName;
			WString superPath;
			if(loop==3){ // autocpp
				cName="JDFAuto"+schemaName;
				superName=baseName;
				superPath="jdf/wrapper/";
			}else if(loop==2){ 
				cName="JDF"+schemaName;
				superName=baseName;
				superPath="jdf/wrapper/AutoJDF/";
			}else if(loop==1){// autoh
				cName="JDFAuto"+schemaName;
				superName=baseName;
				superPath="jdf/wrapper/";
			}else if (loop==0){
				cName="JDF"+schemaName;
				superName="JDFAuto"+schemaName;
				superPath="jdf/wrapper/AutoJDF/";
			}
			WString hName;
			if(loop<=1){
				hName=cName+".h";
			}else{
				hName=cName+".cpp";
			}
			if(loop==0) hName="H/"+hName;
			if(loop==1) hName="AutoH/"+hName;
			if(loop==2) hName="C/"+hName;
			if(loop==3) hName="AutoC/"+hName;
			ofstream h;
			LicOpen(hName,h);			
			h<<"\n\n///////////////////////////////////////////////////////////////////\n\n "<<endl;
			WString saver="_"+cName+"_H_";
			cout<<elmseq<<endl;
			vElement vElm1=elmseq.GetChildrenByTagName("xs:element");
			vElement vGroup=elmseq.GetChildrenByTagName("xs:group");
			for(int gg=0;gg<vGroup.size();gg++){
				KElement gr=vGroup[gg];
				WString ref=gr.GetAttribute("ref");
				if(ref==L"jdf:GenericElements")
					continue;
				if(ref.empty())
					cout<<"inline group: name= "<<gr.GetAttribute("name")<<endl;
				if(ref.leftStr(4)==L"jdf:")
					ref=ref.rightStr(-4);
				if(ref.leftStr(7)==L"jdftyp:")
					ref=ref.rightStr(-7);
				KElement e=GetDocRoot().GetChildWithAttribute("xs:group","name","",ref);
				e=e.GetElement("xs:sequence");
				vElement v=e.GetChildElementVector("xs:element");
				for(int i=0;i<v.size();i++){
					vElm1.push_back(v[i]);
					if((ref!=L"NotificationList")&&ref!=(L"PhysicalResourceList"))
						v[i].SetAttribute("maxOccurs","unbounded");

					//					cout<<ref<<" "<<v[i].GetAttribute("name")<<endl;
				}

			}

			vElement vElm;
			// fix for graham
			for(int ee=0;ee<vElm1.size();ee++){
				if(vElm1[ee].GetAttribute("type")=="jdf:ResourceRef")
					continue;
				if(vElm1[ee].GetAttribute("ref").endsWith(L"Ref"))
					continue;
				SchemaElement se=vElm1[ee];
				WString elmName=se.GetCTName();
				if((elmName==schemaName) && (elmName!=L"Pricing")&& (elmName!=L"DevCap"))
					continue;
				if(elmName.rightStr(6)==L"Update")
					continue;
				if(elmName=="Subscription"){
					if((schemaName!="Query")&&(schemaName!="Registration"))
						continue;
				}
				if(elmName=="Notification"){
					if((schemaName!="Response")&&(schemaName!="Signal")&&(schemaName!="Acknowledge"))
						continue;
				}
				if(elmName=="Trigger"){
					if(schemaName!="Signal")
						continue;
				}
				if(elmName.endsWith(L"TypeObj"))
					continue;
				if(elmName==L"Resource")
					continue;
				if(elmName==L"ResourceLink")
					continue;

				if(elmName==L"NotificationDetails"){
					vElement vvelm=GetRoot().GetChildrenWithAttribute("xs:element","substitutionGroup","","jdf:NotificationDetails");
					for(int iii=0;iii<vvelm.size();iii++){
						vElm.push_back(vvelm[iii]);
					}

					continue;
				}
				if(elmName==L"AbstractTerms"){
					vElement vvelm=GetRoot().GetChildrenWithAttribute("xs:element","substitutionGroup","","jdf:AbstractTerms");
					for(int iii=0;iii<vvelm.size();iii++){
						vElm.push_back(vvelm[iii]);
					}

					continue;
				}
				if(elmName==L"AbstractStates"){
					vElement vvelm=GetRoot().GetChildrenWithAttribute("xs:element","substitutionGroup","","jdf:AbstractStates");
					for(int iii=0;iii<vvelm.size();iii++){
						vElm.push_back(vvelm[iii]);
					}

					continue;
				}

				if(IsResource()){
					if((elmName=="Contact")&&(schemaName!="Company")&&(schemaName!="DigitalDeliveryParams")&&(schemaName!="DeliveryParams")&&(schemaName!="ArtDeliveryIntent")&&(schemaName!="DeliveryIntent")&&(schemaName!="ApprovalSuccess")&&(schemaName!="ApprovalPerson"))
						continue;
					if(elmName=="Location")
						continue;
					if(elmName=="QualityControlResult")
						continue;
					if((elmName=="IdentificationField")&&((schemaName!="DigitalPrintingParams")&&(schemaName!="MarkObject")))
						continue;
					if(elmName=="FoldOperation")
						continue;
				}
				if(elmName=="SourceResource")
					continue;
				if(elmName=="GeneralID")
					continue;
				vElm.push_back(se);
			}

			if(loop>=2){
				if(loop==2){
					h<<"#include \"jdf/wrapper/"<<cName<<".h\"\n";
				}else{
					h<<"#include \"jdf/wrapper/AutoJDF/"<<cName<<".h\"\n";
				}
				if(loop==2) {
					h<<"namespace JDF{\n";
					WString checkName="\t\tif(!IsValid(ValidationLevel_Construct))\n\t\tthrow JDFException(L\"Invalid constructor for "+cName+": \"+other.GetNodeName());\n";
					if(iDataTyp==1) 
						checkName=""; // don't check audits - yet
					if(schemaName=="RefElement") 
						checkName="";
					h<<"/**\n* copy equivalance operator\n*/\n\t"<<cName<<"& "<<cName<<"::operator=(const KElement& other){\n\t\tKElement::operator=(other);\n"+checkName+"\treturn *this;\n};\n";
					h<<"\n\t}; // namespace JDF\n";
					continue;
				}
			}else{
				h<<"#if !defined "<<saver<<"\n#define "<<saver<<"\n#if _MSC_VER >= 1000\n#pragma once\n#endif // _MSC_VER >= 1000\n\n";
				h<<"#include \""<<superPath<<superName<<".h\"\n";
				bool bHasSpan=false;
				bool bHasState=false;
				for(int ii=0;ii<vElm.size();ii++){
					SchemaElement elm=vElm[ii];
					if(elm.GetCType(false).find(L"Span")!=WString::npos){
						bHasSpan=true;
					}
					if(elm.GetCType(false).find(L"State")!=WString::npos){
						bHasState=true;
					}
				}
				if(bHasSpan)
					h<<"#include \"jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h\"\n";
				if(bHasState){
					h<<"#include \"jdf/wrapper/JDFState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFBooleanState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFDateTimeState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFDurationState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFEnumerationState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFIntegerState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFMatrixState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFNameState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFNumberState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFPDFPathState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFRectangleState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFShapeState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFStringState.h\"\n";
					h<<"#include \"jdf/wrapper/JDFXYPairState.h\"\n";
				}
			}

			if(loop==3){
				for(int ele=0;ele<vElm.size();ele++){
					SchemaElement elm=vElm[ele];
					h<<elm.PPHeader(cName,loop);
				}
				if(vElm.size()>0)
					h<<"#include \"jdf/wrapper/JDFRefElement.h\"\n";
			}
			if((loop==1)&&((cName=="JDFAutoPipeParams")||(cName=="JDFAutoResourceInfo"))){
				h<<"#include \"jdf/wrapper/JDFResource.h\"\n";
			}

			h<<"namespace JDF{\n";

			if(loop==1){
				for(int ele=0;ele<vElm.size();ele++){
					SchemaElement elm=vElm[ele];
					h<<elm.PPHeader(cName,loop);
				}
				if(vElm.size()>0){
					h<<"class JDFRefElement;\n";
				}
			}

			h<<"/*\n*********************************************************************\n";
			h<<"class "<<cName<<" : public "<<superName<<"\n\n*********************************************************************\n*/\n";

			if(loop<=1){ // any header

				WString checkName="if(!IsValid(ValidationLevel_Construct)) throw JDFException(L\"Invalid constructor for "+cName+": \"+other.GetNodeName());";
				if(iDataTyp==1) checkName=""; // don't check audits - yet
				if(schemaName=="RefElement") checkName="";
				if(loop==1){
					h<<"/**\n* automatically generated header for "<<cName<<" class\n* \n* Warning! Do not edit! This file may be regenerated\n* The child Class: @see "<<cName.leftStr(3)+cName.rightStr(-7)<<" should be edited instead\n*/\n";
				}else{
					h<<"/**\n* Typesafe resource wrapper class "<<cName<<" \n*\n* This file is hand edited and will not be regenerated\n*/\n";
				}
				h<<"class JDF_WRAPPERCORE_EXPORT "<<cName<<" : public "<<superName<<"{\npublic:\n\n\n// Constructors / Destructors  \n\n\n";
				if(loop==1){
					h<<"protected:\n";
				}
				h<<"/**\n* null ctor\n*/\n";
				h<<"\tinline "<<cName<<"():"<<superName<<"(){};\n";
				h<<"/**\n* copy ctor\n*/\n\tinline "<<cName<<"(const KElement & other):"<<superName<<"(){\n\t*this=other;\n};\n";
				h<<"/**\n* copy equivalance operator\n*/\n\t"<<cName<<" &operator =(const KElement& other);\n";
				h<<"/**\n* dtor\n*/\n\tvirtual ~"<<cName<<"(){};\n";
			}
			if(loop==1){
				h<<"public:\n";

				// h<<"\n/**\n* typesafe validator\n* @param EnumValidationLevel level validation level\n* @return bool true if this is valid\n*/";
				// h<<"\n\tvirtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;\n";

				h<<"\n/**\n* typesafe validator utility\n* @param EnumValidationLevel level validation level\n* @param bool bIgnorePrivate ignore objects in foreign namespaces\n* @param int nMax size of the returned vector\n* @return vWString vector of invalid attribute names\n*/";
				h<<"\n\tvirtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;\n";
				if(vElm.size()>0){
					h<<"\n/**\n* typesafe validator utility\n* @param EnumValidationLevel level validation level\n* @param bool bIgnorePrivate ignore objects in foreign namespaces\n* @param int nMax size of the returned vector\n* @return vWString vector of invalid element names\n*/";
					h<<"\n\tvirtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;\n";
				}
				if(!IsMessageElement()){
					h<<"\nprotected:\n/**\n* typesafe validator utility - list of valid node names for this class \n * @return WString& comma separated list of valid node names\n */\n";
					h<<"\n\tvirtual WString ValidNodeNames()const;\npublic:\n";
				}else{
					h<<"/** \n * Typesafe initialization\n * @return true if succcessful\n*/\n";
					h<<"virtual bool init();\n\n";
				}

				if(!IsAbstract(schemaName)){
					h<<"\n/**\n* Checks if the node is abstract, i.e. is not completely described\n* utility used by GetUnknownElements, GetUnknownAttributes\n* @return boolean: true, if the node is abstract\n*/\n";
					h<<"\tvirtual bool IsAbstract()const;\n\n";
				}

				WString reqAtts="\tvirtual WString RequiredAttributes()const;\n";
				WString optAtts="\tvirtual WString OptionalAttributes()const;\n";
				WString unqElms="\tvirtual WString UniqueElements()const;\n";
				WString reqElms="\tvirtual WString RequiredElements()const;\n";
				WString optElms="\tvirtual WString OptionalElements()const;\n";
				vElement vAtts=extension.GetAttVector();
				h<<"\n/* ******************************************************\n// Attribute Getter / Setter\n****************************************************** */\n\n";
				if(IsResource()&&(baseName!="JDFIntentResource")){
					h<<"/** \n * Typesafe attribute validation of Class\n* @return true if class is valid\n*/\n";
					h<<"virtual bool ValidClass(EnumValidationLevel level) const;\n\n";
					h<<"/** \n * Typesafe initialization\n * @return true if succcessful\n*/\n";
					h<<"virtual bool init();\n\n";
				}

				int ireqatts=0;
				int ioptatts=0;
				int att;
				for(att=0;att<vAtts.size();att++){
					SchemaElement atr=vAtts[att];
					h<<atr.EnumHeader();
					if((atr.GetUse()=="required")){
						ireqatts++;
					}else{
						ioptatts++;
					}

				}

				if(ireqatts) 
					h<<"\n/**\n * definition of required attributes in the JDF namespace\n*/\n"<<reqAtts;
				if(ioptatts) 
					h<<"\n/**\n * definition of optional attributes in the JDF namespace\n*/\n"<<optAtts<<"\n";

				for(att=0;att<vAtts.size();att++){
					SchemaElement atr=vAtts[att];
					h<<atr.AtrHeader(1,cName);
				}


				h<<"\n/* ******************************************************\n// Element Getter / Setter\n**************************************************************** */\n\n";


				vWString vDone;
				vDone.clear();
				int iunqelms=0;
				int ireqelms=0;
				int ioptelms=0;
				for(int ele=0;ele<vElm.size();ele++){
					SchemaElement elm=vElm[ele];
					WString elmName=elm.GetCTName("");
					if (vDone.hasString(elmName)) 
						continue;
					vDone.push_back(elmName);

					h<<elm.ElmHeader(cName,iDataTyp,loop);
					if(elm.GetMaxOccurs(cName,elmName,"unbounded")=="1"){
						iunqelms++;
					}
					if(elm.GetMinOccurs(cName,elmName,"0")!="0"){
						ireqelms++;
					}else{
						ioptelms++;
					}

				}

				//				isValid+="\t\tif(HasUnknownAttributes(KnownAttributes().Tokenize(WString::comma),WString(L\":JDF\").Tokenize(L\":\"))) return false;\n";


				if(iunqelms) 
					h<<"\n/**\n definition of unique elements in the JDF namespace\n*/\n"<<unqElms;
				if(ireqelms) 
					h<<"\n/**\n definition of required elements in the JDF namespace\n*/\n"<<reqElms;
				if(ioptelms) 
					h<<"\n/**\n definition of optional elements in the JDF namespace\n*/\n"<<optElms;
			}


			if((loop==3)){
				WString checkName="\tif(!IsValid(ValidationLevel_Construct))\n\t\tthrow JDFException(L\"Invalid constructor for "+cName+": \"+other.GetNodeName());\n";
				if(iDataTyp==1) 
					checkName=""; // don't check audits - yet
				if(schemaName=="RefElement") 
					checkName="";
				h<<"/**\n* copy equivalance operator\n*/\n"<<cName<<"& "<<cName<<"::operator=(const KElement& other){\n\tKElement::operator=(other);\n"+checkName+"\treturn *this;\n};\n";

				WString isValid;
				isValid+="\n/**\n typesafe validator\n*/\n\tvWString "+cName+"::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {\n";
				isValid+="\t\tvWString vAtts="+superName+"::GetInvalidAttributes(level,bIgnorePrivate,nMax);\n";
				isValid+="\t\tint n=vAtts.size();\n\t\tif(n>=nMax)\n\t\t\treturn vAtts;\n";


				if(!IsAbstract(schemaName)){
					h<<"\n/////////////////////////////////////////////////////\n";
					h<<"\tbool "+cName+"::IsAbstract()const{\n\t\treturn false;\n\t}\n";
				}


				vElement vAtts=extension.GetAttVector();

				if(!IsMessageElement()){
					h<<"\n/**\n* typesafe validator utility - list of valid node names for this class \n * @return WString& comma separated list of valid node names\n */\n";
					if(schemaName=="PlacedObject"){
						h<<"\n\tWString "+cName+"::ValidNodeNames()const{\n\treturn L\"*:,ContentObject,MarkObject\";\n};\n\n";
					}else if(schemaName=="ShapeElement"){
						h<<"\n\tWString "+cName+"::ValidNodeNames()const{\n\treturn L\"*:,Shape\";\n};\n\n";
					}else if(schemaName=="IDPCover"){
						h<<"\n\tWString "+cName+"::ValidNodeNames()const{\n\treturn L\"*:,Cover\";\n};\n\n";
					}else if(schemaName=="PreflightValue"){
						h<<"\n\tWString "+cName+"::ValidNodeNames()const{\n\treturn L\"*:,Value,ConstraintValue\";\n};\n\n";
					}else if(schemaName=="Message"){
						h<<"\n\tWString "+cName+"::ValidNodeNames()const{\n\treturn L\"*:,Query,Command,Response,Acknowledge,Signal,Registration\";\n};\n\n";
					}else{
						h<<"\n\tWString "+cName+"::ValidNodeNames()const{\n\treturn L\"*:,"+schemaName+"\";\n};\n\n";
					}
					if(IsResource()&&(baseName!="JDFIntentResource")){
						WString getClass="bool "+cName+"::ValidClass(EnumValidationLevel level) const {\n\tif(!HasAttribute(atr_Class))\n\t\treturn !RequiredLevel(level);\n";
						mAttribute::iterator it=classMap.find(cName.rightStr(-7));
						if(it==classMap.end()){
							cout <<"missing class for "<<cName<<endl;
						}else{

							getClass+="\treturn GetClass()=="+it->second()+";\n};\n\n";
							h<<getClass;
							h<<"bool "+cName+"::init(){\n";
							h<<"\tbool bRet="+superName+"::init();\n";
							h<<"\tSetClass("+it->second()+");\n";
							h<<"\treturn bRet;\n};\n";

						}				
					}
				}else{
					h<<"bool "+cName+"::init(){\n";
					h<<"\tbool bRet="+superName+"::init();\n";
					if(cName.leftStr(10)=="JDFAutoJMF"){
						h<<"\tSetEnumType(Type_"+cName.rightStr(-11)+");\n";
					}
					h<<"\treturn bRet;\n};\n";
				}

				WString reqAtts="\tWString "+cName+"::RequiredAttributes()const{\n\t\treturn "+superName+"::RequiredAttributes()+L\"";
				WString optAtts="\tWString "+cName+"::OptionalAttributes()const{\n\t\treturn "+superName+"::OptionalAttributes()+WString(L\"";
				WString unqElms="\tWString "+cName+"::UniqueElements()const{\n\t\treturn "+superName+"::UniqueElements()+L\"";
				WString reqElms="\tWString "+cName+"::RequiredElements()const{\n\t\treturn "+superName+"::RequiredElements()+L\"";
				WString optElms="\tWString "+cName+"::OptionalElements()const{\n\t\treturn "+superName+"::OptionalElements()+L\"";
				h<<"\n/* ******************************************************\n// Attribute Getter / Setter\n****************************************************** */\n\n";
				int ireqatts=0;
				int ioptatts=0;
				int att;
				for(att=0;att<vAtts.size();att++){
					SchemaElement atr=vAtts[att];
					//					if((atr.GetUse()=="required")||(atr.HasAttribute("fixed"))){
					if(atr.GetUse()=="required"){
						reqAtts+=","+atr.GetCTName("");
						ireqatts++;
					}else{			
						optAtts+=","+atr.GetCTName("");
						ioptatts++;
						if(!(ioptatts%19)){
							optAtts+=L"\")\n\t+WString(L\"";
						}
					}

				}

				if(ireqatts) h<<"\n/**\n definition of required attributes in the JDF namespace\n*/\n"<<reqAtts+"\";\n};\n";
				if(ioptatts) h<<"\n/**\n definition of optional attributes in the JDF namespace\n*/\n"<<optAtts+"\");\n};\n";



				for( att=0;att<vAtts.size();att++){
					SchemaElement atr=vAtts[att];
					isValid+=atr.AtrValid();
				}

				isValid+="\t\treturn vAtts;\n\t};\n\n";

				h<<isValid;

				for(att=0;att<vAtts.size();att++){
					SchemaElement atr=vAtts[att];
					h<<atr.AtrHeader(3,cName);
				}

				int ele;
				vWString vDone;
				isValid="";
				if(vElm.size()>0){
					h<<"\n/* ******************************************************\n// Element Getter / Setter\n**************************************************************** */\n\n";

					isValid="\n/**\n typesafe validator\n*/\n\tvWString "+cName+"::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{\n";
					isValid+="\t\tint nElem=0;\n\t\tint i=0;\n\t\tvWString vElem="+superName+"::GetInvalidElements(level, bIgnorePrivate, nMax);\n";
					isValid+="\t\tint n=vElem.size();\n";
					isValid+="\t\tif(n>=nMax)\n\t\t\t return vElem;\n";
					vDone.clear();
					for(ele=0;ele<vElm.size();ele++){
						SchemaElement elm=vElm[ele];
						WString elmName=elm.GetCTName("");
						if (vDone.hasString(elmName)) 
							continue;

						vDone.push_back(elmName);

						h<<elm.ElmHeader(cName,iDataTyp,loop);

						if(!elmName.endsWith("State")&&IsAbstract(elmName))
							continue;

						isValid+=elm.ElmValid(cName);

					}

					//				isValid+="\t\tif(HasUnknownAttributes(KnownAttributes().Tokenize(WString::comma),WString(L\":JDF\").Tokenize(L\":\"))) return false;\n";

					//					isValid+="\t\tif(level>=ValidationLevel_Complete)vElem.AppendUnique(GetMissingElements(nMax));\n";
					//					if(!IsAbstract(schemaName)) isValid+="\t\tvElem.AppendUnique(GetUnknownElements(bIgnorePrivate,nMax));\n";
					isValid+="\t\treturn vElem;\n\t};\n\n";
				}				

				h<<isValid;


				vDone.clear();
				int iunqelms=0;
				int ireqelms=0;
				int ioptelms=0;
				for(ele=0;ele<vElm.size();ele++){
					SchemaElement elm=vElm[ele];
					WString elmName=elm.GetCTName("");
					if (vDone.hasString(elmName)) continue;
					if(elmName==schemaName) continue;
					vDone.push_back(elmName);
					if(elm.GetMaxOccurs(cName,elmName,"unbounded")=="1"){
						unqElms+=","+elm.GetCTName("",true,true);
						iunqelms++;
					}
					if(elm.GetMinOccurs(cName,elmName,"0")!="0"){
						reqElms+=","+elm.GetCTName("",true,true);
						ireqelms++;
					}else{
						optElms+=","+elm.GetCTName("",true,true);
						ioptelms++;
					}

				}
				if(iunqelms) h<<"\n/**\n definition of required elements in the JDF namespace\n*/\n"<<unqElms+"\";\n\t};\n";
				if(ireqelms) h<<"\n/**\n definition of required elements in the JDF namespace\n*/\n"<<reqElms+"\";\n\t};\n";
				if(ioptelms) h<<"\n/**\n definition of optional elements in the JDF namespace\n*/\n"<<optElms+"\";\n\t};\n";
			}



			if(loop<=1){
				h<<"}; // end" <<cName<<"\n\n// ******************************************************\n";
			}
			h<<"}; // end namespace JDF\n";
			if(loop<=1){
				h<<"#endif //"<<saver<<endl;
			}
			h.close();
		}

	};

	///////////////////////////////////////////////////////////////////////
	vWString ToEnumerationSpan(){
		vWString v;
		WString s;
		WString cName=L"JDF"+GetSpanName();
		v.push_back(cName);
		WString superName="JDFEnumerationSpan";
		WString checkName="if(!IsValid(ValidationLevel_Construct)) throw JDFException(L\"Invalid constructor for "+cName+": \"+other.GetNodeName());";

		vWString vTokens;

		WString tokens;
		s+"/**\n* EnumerationSpan class "+cName+"\n*/\n";
		s+="class JDFTOOLS_EXPORT "+cName+" : public "+superName+"{\npublic:\n";
		s+="/**\n* null ctor\n*/\n";
		s+="\tinline "+cName+"():"+superName+"(){};\n";
		s+="/**\n* copy ctor\n*/\n\tinline "+cName+"(const KElement & other):"+superName+"(){\n\t*this=other;\n};\n";
		s+="/**\n* copy equivalance operator\n*/\n\tinline "+cName+" &operator =(const KElement& other){KElement::operator=(other);"+checkName+" return *this;};\n";
		s+="/**\n* dtor\n*/\n\tvirtual ~"+cName+"(){};\n";


		if((cName=="JDFSpanNamedColor")||(cName=="Orientation")||(cName=="JDFSpanHoleType")){
			// nop - take what we have
		}else{
			//			vTokens.push_back("Unknown");
			bool bDummy;
			vWString vTokenss=EnumValues(cName.rightStr(-7),true,bDummy);
			vTokens.insert(vTokens.end(),vTokenss.begin(),vTokenss.end());
			s+="/**\n* enumeration type for "+cName.rightStr(-7)+"\n*/\n";
			WString name=cName.rightStr(-3);
			tokens.SetvString(vTokens,","+name+"_",name+"_");
			s+="enum Enum"+name+"{"+tokens+"};\n\n";
		}


		s+="public:\n/**\n* Returns the list of valid strings\n*/\n";
		s+="\t virtual WString AllowedValues()const;\n};\n\n";
		s+="///////////////////////////////////////////////////////////////\n\n";
		v.push_back(s);

		s="\n\n///////////////////////////////////////////////////////////////\n";
		s+="\t WString "+cName+"::AllowedValues()const{\n";
		if(cName=="JDFSpanNamedColor"){
			s+="\t\treturn JDFElement::NamedColorString();\n";
		}else if(cName=="JDFSpanHoleType"){
			s+="\t\treturn JDFHoleMakingParams::HoleTypeString();\n";
		}else{
			tokens=EnumString(vTokens);
			s+="\t\treturn WString(L\""+tokens+"\");\n";
		}
		s+="\t}\n";
		v.push_back(s);

		return v;

	}
	///////////////////////////////////////////////////////////////////////
};

///////////////////////////////////////////////////////////////////////

int main(int argC, char* argV[]){

	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	// trivial argument handling
	MyArgs args(argC,argV,"psf","c");
	WString fn=args.Argument();
	WString classString=args.ParameterString('c').c_str();
	// Watch for special case help request
	WString usage="JDFSchema <arg>\nschema .xsd file is input argument\n";
	usage+="-c<class> class to generate\n";
	usage+="-p generate processes\n";
	usage+="-s strip the schema\n";
	usage+="-f ???\n";
	if ((argC>1)&&(strcmp(argV[1], "-?") == 0)){
		std::cerr<< args.Usage(usage).c_str();
		return 0;
	}

	SchemaDoc doc;
	if(fn.empty()){
		doc.Parse("JDFCore.xsd",false,true);
		KElement e=doc.GetRoot();
		XMLDoc d2;
		d2.Parse("JDFTypes.xsd",false,true);
		doc.MergeDoc(d2);
		d2.Parse("JDFResource.xsd",false,true);
		doc.MergeDoc(d2);
		d2.Parse("JDFResourceElements.xsd",false,true);
		doc.MergeDoc(d2);
		d2.Parse("JDFMessage.xsd",false,true);
		doc.MergeDoc(d2);
		d2.Parse("JDFCapability.xsd",false,true);
		doc.MergeDoc(d2);

	}else{
		doc.Parse(fn,false,true);
		doc.schemaFileName=fn;
	}

#if 1	
	if(args.BoolParameter('s')){
		doc.Strip();
		doc.Write2File("StripSchema.xsd");
	}else if(args.BoolParameter('f')){
		doc.MakeCC();
	}else if(args.BoolParameter('p')){
		doc.MakeCProc();
	}else{
		doc.MakeC(classString);
	}
#endif
#if 0
	// aufrufen mit jdfschema graham myoldfile
	WString fn2=args.Argument(1);
	SchemaDoc inDoc;
	inDoc.Parse(fn2,false,true);
	doc.MoveJDF(inDoc);
	XMLIndent(2,true);
	doc.Write2File("outSchema.doc");
#endif

	return 0;
}

//////////////////////////////////////////////////////////////////////
void SchemaDoc::MergeRes(const WString &name,WString nameNoStrip){
	SchemaElement se=GetRoot().GetChildWithAttribute("xs:complexType","name","",nameNoStrip,0,false);
	if(nameNoStrip.leftStr(7)=="Generic"){
		nameNoStrip=nameNoStrip.rightStr(-7);		
		//			cout<<"generic 2 "<<nameNoStrip<<endl;
	}

	vWString vExt=WString("_lr __ _re _r _rp BaseType").Tokenize();
	SchemaElement content=se.GetElement("xs:complexContent");
	SchemaElement extension=content.GetElement("xs:extension");
	if(extension.isNull())
		extension=content.GetElement("xs:restriction");
	SchemaElement elmseq=extension.GetElement("xs:sequence");
	vElement vElm=elmseq.GetChildrenByTagName("xs:element");
	//	cout<<extension;
	vElement vAtts=extension.GetAttVector();
	for(int i=0;i<vExt.size();i++){

		if(name+vExt[i]==nameNoStrip){
			continue;
		}

		SchemaElement se_=GetRoot().GetChildWithAttribute("xs:complexType","name","",name+vExt[i],0,false);
		if(se.isNull()) 
			continue;
		SchemaElement content_=se_.GetElement("xs:complexContent");
		SchemaElement extension_=content_.GetElement("xs:extension");
		if(extension_.isNull())
			extension_=content_.GetElement("xs:restriction");
		SchemaElement elmseq_=extension_.GetElement("xs:sequence");
		vElement vElm_=elmseq_.GetChildrenByTagName("xs:element");
		int i1;
		for(i1=0;i1<vElm_.size();i1++){
			WString name=vElm_[i1].GetAttribute("name");
			if(name.rightStr(6)=="Update")
				continue;
			bool bFound=false;
			for(int j=0;j<vElm.size();j++){
				if(vElm[j].GetAttribute("name")==name){
					bFound=true;
					break;
				}
			}
			if(!bFound){
				cout <<"copying element "<<name<<endl;
				elmseq.CopyElement(vElm_[i1]);
				vElm.AppendUnique(vElm_[i1]);
			}
		}

		vElement vAtts_=extension_.GetAttVector();
		for(i1=0;i1<vAtts_.size();i1++){
			WString name=vAtts_[i1].GetAttribute("name");
			bool bFound=false;
			if(WString("BlockName DocCopies DocIndex DocRunIndex DocSheetIndex FountainNumber LayerIDs Location Option PageNumber PartVersion PreviewType RibbonName Run RunIndex RunTags RunPage Separation SetIndex SheetIndex SheetName Side SignatureName TileID WebName").Tokenize().hasString(name))
				continue;
			for(int j=0;j<vAtts.size();j++){
				if(vAtts[j].GetAttribute("name")==name){
					bFound=true;
					break;
				}
			}
			if(!bFound){
				cout <<"copying attribute "<<name<<endl;
				extension.CopyElement(vAtts_[i1]);
				vAtts.AppendUnique(vAtts_[i1]);
			}
		}

	}

}
//////////////////////////////////////////////////////////////////////

int SchemaDoc::Strip(){
	int i;
	vElement inAtts=GetRoot().GetChildrenByTagName("xs:attribute", WString::emptyStr, mAttribute(),false);
	for(i=0;i<inAtts.size();i++){
		inAtts[i].RemoveAttribute("jdfP:use");

	}
	inAtts=GetRoot().GetChildrenByTagName("xs:element", WString::emptyStr, mAttribute(),false);
	for(i=0;i<inAtts.size();i++){
		inAtts[i].RemoveAttribute("jdfP:Tokens");
	}

	return 0;	

}
//////////////////////////////////////////////////////////////////////

int SchemaDoc::MoveJDF(SchemaDoc inDoc){
	int i;
	vElement inAtts=inDoc.GetRoot().GetChildrenByTagName("xs:attribute", WString::emptyStr, mAttribute(),false);
	for(i=0;i<inAtts.size();i++){
		WString name=inAtts[i].GetAttribute("name");
		if(name.empty()) continue;
		if(!inAtts[i].HasAttribute("jdfP:use")) continue;
		mAttribute ma;
		ma.AddPair("name",name);
		vElement myAtts=GetRoot().GetChildrenByTagName("xs:attribute", WString::emptyStr, ma,false);
		cout <<i<<" "<<name<<" "<<myAtts.size()<<endl;
		for(int j=0;j<myAtts.size();j++){
			myAtts[j].CopyAttribute("jdfP:use",inAtts[i]);
			myAtts[j].SetAttribute("use","optional");
		}

	}
	inAtts=inDoc.GetRoot().GetChildrenByTagName("xs:element", WString::emptyStr, mAttribute(),false);
	for(i=0;i<inAtts.size();i++){
		WString name=inAtts[i].GetAttribute("name");
		if(name.empty()) continue;
		if(!inAtts[i].HasAttribute("jdfP:Tokens")) {
			mAttribute ma;
			ma.AddPair("name",name);
			vElement myAtts=GetRoot().GetChildrenByTagName("xs:element", WString::emptyStr, ma,false);
			cout <<i<<" "<<name<<" "<<myAtts.size()<<endl;
			for(int j=0;j<myAtts.size();j++){
				myAtts[j].CopyAttribute("jdfP:Tokens",inAtts[i]);
			}
		}

	}

	return 0;	
}

//////////////////////////////////////////////////////////////////////
int SchemaDoc::ToProcCode2(const WString & typeName,vWString vName,vWString vInfo, WString schemaFileName){
	static int n=0;
	n++;
	if(!(n%10))
		typeNames+="\n";
	typeNames+=L",Type_"+typeName;
	if(!(n%10)){
		typeNameString+="\")\n+WString(L\"";
		cout<<typeNames<<endl<<endl;
	}
	typeNameString+=L","+typeName;
	linkNames+=L"case Type_"+typeName+":{\n\t\treturn GenericLinkNames()+L\""+vName.GetString(",",",")+"\";\nbreak;\n};\n";
	linkInfo+= L"case Type_"+typeName+":{\n\t\treturn GenericLinkInfo()+L\""+vInfo.GetString(",",",")+"\";\nbreak;\n};\n";
	return 0;
}
//////////////////////////////////////////////////////////////////////

int SchemaDoc::ToProcCode(const WString & schemaName,vWString vName,vWString vInfo, WString schemaFileName){
	vWString myTypes;
	WString procType=schemaName.rightStr(-4);
	//	cout<<"if(typ==L\""<<procType<<"\")\nreturn new JDFNode"<<procType<<"(part);\n"<<endl;
	cout<<procType<<",";

	WString baseName="JDFNode";
	if(schemaName=="NodeProduct")
		baseName="JDFNodeProcessGroup";

	for(int loop=0;loop<4;loop++){
		WString cName;
		WString superName;
		WString superPath;
		if(loop==3){ // autocpp
			cName="JDFAuto"+schemaName;
			superName=baseName;
			superPath="";
		}else if(loop==2){ 
			cName="JDF"+schemaName;
			superName=baseName;
			superPath="";
		}else if(loop==1){// autoh
			cName="JDFAuto"+schemaName;
			superName=baseName;
			superPath="";
		}else if (loop==0){
			cName="JDF"+schemaName;
			superName="JDFAuto"+schemaName;
			superPath="AutoJDF/";
		}
		WString hName;
		if(loop<=1){
			hName=cName+".h";
		}else{
			hName=cName+".cpp";
		}
		if(loop==0) hName="H/"+hName;
		if(loop==1) hName="AutoH/"+hName;
		if(loop==2) hName="C/"+hName;
		if(loop==3) hName="AutoC/"+hName;
		ofstream h;

		SchemaElement().LicOpen(hName,h);			
		h<<"\n\n";
		WString saver="_"+cName+"_H_";
		if(loop>=2){
			h<<"#include \""<<cName<<".h\"\n";
			if(loop==2) {
				h<<"namespace JDF{\n}; // namespace JDF\n";
				continue;
			}
		}else{
			h<<"#if !defined "<<saver<<"\n#define "<<saver<<"\n#if _MSC_VER >= 1000\n#pragma once\n#endif // _MSC_VER >= 1000\n\n";
			h<<"#include \""<<superPath<<superName<<".h\"\n";
		}

		if(loop==3){
			h<<"#include \""<<superPath<<"JDFResourceLink.h\"\n";
			for(int ele=0;ele<vName.size();ele++){
				if(vName[ele]==L"*")
					continue;
				h<<"#include \""<<superPath<<"JDF"<<vName[ele]<<".h\"\n";
			}
		}
		h<<"namespace JDF{\n";
		if(loop==1){
			h<<"class JDFResourceLink;\n";
			for(int ele=0;ele<vName.size();ele++){
				if(vName[ele]==L"*")
					continue;
				h<<"class "<<"JDF"<<vName[ele]<<";\n";
			}
		}
		h<<"/*\n*********************************************************************\n";
		h<<"class "<<cName<<" : public "<<superName<<"\n\n*********************************************************************\n*/\n";



		if(loop<=1){ // any header

			WString checkName="if(!IsValid(ValidationLevel_Construct)) throw JDFException(L\"Invalid constructor for "+cName+": \"+other.GetNodeName());";
			if(loop==1){
				h<<"/**\n* automatically generated header for "<<cName<<" class\n* \n* Warning! Do not edit! This file may be regenerated\n* The child Class: @see "<<cName.leftStr(3)+cName.rightStr(-7)<<" should be edited instead\n*/\n";
			}else{
				h<<"/**\n* Typesafe Node wrapper class "<<cName<<" \n*\n* This file is hand edited and will not be regenerated\n*/\n";
			}
			h<<"class JDFTOOLS_EXPORT "<<cName<<" : public "<<superName<<"{\npublic:\n\n\n// Constructors / Destructors  \n\n\n";
			if(loop==1){
				h<<"protected:\n";
			}
			h<<"/**\n* null ctor\n*/\n";
			h<<"\tinline "<<cName<<"():"<<superName<<"(){};\n";
			h<<"/**\n* copy ctor\n*/\n\tinline "<<cName<<"(const KElement & other):"<<superName<<"(){*this=other;};\n";
			h<<"/**\n* copy equivalance operator\n*/\n\tinline "<<cName<<" &operator =(const KElement& other){\nKElement::operator=(other);\n"+checkName+" \nreturn *this;\n};\n";
			h<<"/**\n* dtor\n*/\n\tvirtual ~"<<cName<<"(){};\n";
			if(loop==1){
				h<<"public:\n";
			}

		}


		if(loop==1){


			h<<"\n/* ******************************************************\n// Resource (Link) Getter / Setter\n**************************************************************** */\n\n";

			h<<"\n/**\n * definition of resource link names in the JDF namespace\n";
			h<<" * @return WString list of resource names that may be linked\n*/\n";
			h<<"\tvirtual WString LinkNames()const;\n";
			h<<"\n/**\n * definition of resource link meta data in the JDF namespace\n";
			h<<" * @return WString list of resource usage, cardinality and process usages that may be linked\n*/\n";
			h<<"\tvirtual WString LinkInfo()const;\n";
			h<<"/**\n	* definition of the length of LinkNames, LinkInfo for subclassed JDF nodes\n	* @return int length of the subclassed (JDFProduct:: etc.) link string functions,\n	*/\n";
			h<<"virtual int GetLinksLength()const;\n";
			h<<"/**\n * Node types to initialize the node\n * @return WString the string of valid node types\n */\n";
			h<<"virtual WString TypeString()const;\n\n";

			for(int nu=0;nu<vName.size();nu++){
				WString nam=vName[nu];
				if(nam==L"*")
					continue;

				int maxLinks=0;
				vWString namProcs=WString("Unknown AnyInput AnyOutput Any").Tokenize();
				bool hasInput=false;
				bool hasOutput=false;
				bool hasPU=false;
				vWString info=vInfo[nu].Tokenize();
				int nMax=0;
				int ioFlag=0;
				for(int i=0;i<info.size();i++){
					hasInput=hasInput||(info[i][0]==L'i');
					hasOutput=hasOutput||(info[i][0]==L'o');
					if(hasInput) ioFlag+=1;
					if(hasOutput) ioFlag+=2;
					nMax+=((info[i][1]==L'_')||(info[i][1]==L'?')) ? 1 : 999;
					if(info[i].size()>2){
						namProcs.push_back(info[i].rightStr(-2));
						ioFlag+=3;
					}
				}
				bool bHasEnum=ioFlag>2;


				h<<"/* Resource Link "<<nam<<" */\n";

				WString eType="EnumProcessUsage";

				if(namProcs.size()>4){
					hasPU=true;
					eType="Enum"+nam+"ProcessUsage";
					h<<"/**\n* Enumeration for accessing typesafe "<<nam<<"\n*/\n";
					h<<"enum "+eType+"{"+namProcs.GetString(","+nam+L"ProcessUsage_",nam+L"ProcessUsage_")+"};\n";

				}

				WString headerGet="/**\n* TypeSafe Resource getter for "+nam+"\n";
				headerGet+="* @param "+eType+" usage process usage of the link to get\n";
				WString headerGetLink="/**\n* TypeSafe ResourceLink getter for "+nam+"\n";
				headerGetLink+="* @param "+eType+" usage process usage of the link to get\n";
				WString headerRem="/**\n* TypeSafe Resource removal for "+nam+"\n";
				headerRem+="* @param "+eType+" usage process usage of the link to remove\n";
				WString headerApp="/**\n* TypeSafe Resource Append for "+nam+"\n";
				headerApp+="* @param "+eType+" usage process usage of the link to append\n";
				WString headerLink="/**\n* TypeSafe Resource Link for "+nam+"\n";
				headerLink+="* @param "+eType+" usage process usage of the link to append\n";

				if(nMax>1){
					headerGetLink+="* @param int iSkip number of matching links to skip\n";
					headerGet+="* @param int iSkip number of matching links to skip\n";
					headerRem+="* @param int iSkip number of matching links to skip\n";
				}

				headerRem+="* @param bool bRemoveResource remove the resource if it is legal to do so\n";
				headerApp+="* @param JDFNode resourceRoot the node where the resource should be stored\n";
				headerLink+="* @param JDF"+nam+" resource the resource to link to\n";

				headerGet+="* @return JDF"+nam+" the resource that is linked by this\n*/\n";
				headerGetLink+="* @return JDFResourceLink the resource link that defined by this\n*/\n";
				headerRem+="* @return bool true if successful\n*/\n";
				headerApp+="* @return JDF"+nam+"the appended resource\n*/\n";
				headerLink+="* @return JDFResource the newly created resource link null if unsuccessful\n*/\n";

				WString eTypeUse=eType;
				if(bHasEnum){
					eTypeUse+=L" usage";
				}else{
					if(ioFlag==1){
						eTypeUse+=L" usage=ProcessUsage_AnyInput";
					}else{
						eTypeUse+=L" usage=ProcessUsage_AnyOutput";
					}
				}
				headerGet +="JDF"+nam+" Get"+nam+"("+eTypeUse;
				headerGet+=", const mAttribute &partMap=mAttribute::emptyMap";
				headerGetLink +="JDFResourceLink Get"+nam+"Link("+eTypeUse;
				headerRem +="bool Remove"+nam+"("+eTypeUse;
				headerRem+=", bool bRemoveResource=false";
				headerApp +="JDF"+nam+" Append"+nam+"("+eTypeUse;
				headerApp+=", const JDFNode &resourceRoot=JDFNode());\n";
				headerLink +="JDFResourceLink Link"+nam+"(const JDF"+nam+"& resource,"+eTypeUse;
				headerLink +=", const mAttribute &partMap=::emptyMap);\n";

				if(nMax>1){
					headerGet+=", int iSkip=0";
					headerGetLink+=", int iSkip=0";
					headerRem+=", int iSkip=0";
				}

				headerGet+=")const;\n";
				headerGetLink+=")const;\n";
				headerRem+=");\n";

				h<<headerGet;
				h<<headerGetLink;
				h<<headerApp;
				h<<headerRem;
				h<<headerLink;

				h<<"/**\n* TypeSafe Resource Check for "+nam+"\n*/\n";
				h<<"inline bool Has"+nam+"("+eTypeUse+"){\n";
				h<<"\treturn NumMatchingLinks(GetGenericLinksLength()+"+WString::valueOf(nu)+",false,(int)usage)>0;\n};\n";
				h<<"/**\n* TypeSafe Resource counter for "+nam+"\n*/\n";
				h<<"inline int Num"+nam+"s("+eTypeUse+"){\n";
				h<<"\treturn NumMatchingLinks(GetGenericLinksLength()+"+WString::valueOf(nu)+",false,(int)usage);\n};\n";
			}
		}


		if(loop==3){

			h<<"\tWString "+cName+L"::LinkNames()const{\n\t\treturn "+superName+L"::LinkNames()+L\""+vName.GetString(",",",")+"\";\n};\n";
			h<<"\n/////////////////////////////////////////////////////////////////////////\n\n";
			h<<"\tWString "+cName+L"::LinkInfo()const{\n\t\treturn "+superName+L"::LinkInfo()+L\""+vInfo.GetString(",",",")+"\";\n};\n";
			h<<"\n/////////////////////////////////////////////////////////////////////////\n\n";
			h<<" int "+cName+L"::GetLinksLength()const{\n	 return GetGenericLinksLength()+"+WString::valueOf(vName.size())+L";\n};\n";
			h<<"\n/////////////////////////////////////////////////////////////////////////\n\n";
			h<<" WString "+cName+L"::TypeString()const{\n\treturn L\""+procType+"\";\n};\n";
			h<<"\n/////////////////////////////////////////////////////////////////////////\n\n";

			for(int nu=0;nu<vName.size();nu++){
				WString nam=vName[nu];
				if(nam==L"*")
					continue;

				int maxLinks=0;
				vWString namProcs=WString("Unknown AnyInput AnyOutput Any").Tokenize();
				bool hasInput=false;
				bool hasOutput=false;
				bool hasPU=false;
				vWString info=vInfo[nu].Tokenize();
				int nMax=0;
				int ioFlag=0;
				for(int i=0;i<info.size();i++){
					hasInput=hasInput||(info[i][0]==L'i');
					hasOutput=hasOutput||(info[i][0]==L'o');
					if(hasInput) ioFlag+=1;
					if(hasOutput) ioFlag+=2;
					nMax+=((info[i][1]==L'_')||(info[i][1]==L'?')) ? 1 : 999;
					if(info[i].size()>2){
						namProcs.push_back(info[i].rightStr(-2));
						ioFlag+=3;
					}
				}
				bool bHasEnum=ioFlag>2;


				h<<"/* Resource Link "<<nam<<" */\n";

				WString eType="EnumProcessUsage";

				if(namProcs.size()>4){
					hasPU=true;
					eType="Enum"+nam+"ProcessUsage";
				}
				WString headerGetLink="/////////////////////////////////////////////////////////\n\n";
				WString headerGet="/////////////////////////////////////////////////////////\n\n";
				WString headerRem="/////////////////////////////////////////////////////////\n\n";
				WString headerApp="/////////////////////////////////////////////////////////\n\n";
				WString headerLink="/////////////////////////////////////////////////////////\n\n";

				WString eTypeUse=eType;
				eTypeUse+=L" usage";

				headerGet +="JDF"+nam+" "+cName+"::Get"+nam+"("+eTypeUse+", const mAttribute &partMap";
				headerGetLink +="JDFResourceLink "+cName+"::Get"+nam+"Link("+eTypeUse;
				headerRem +="bool "+cName+"::Remove"+nam+"("+eTypeUse+", bool bRemoveResource";
				headerApp +="JDF"+nam+" "+cName+"::Append"+nam+"("+eTypeUse+", const JDFNode &resourceRoot";
				headerLink +="JDFResourceLink "+cName+"::Link"+nam+"(const JDF"+nam+"& resource, "+eTypeUse;

				if(nMax>1){
					headerGet+=", int iSkip";
					headerGetLink+=", int iSkip";
					headerRem+=", int iSkip";
				}
				WString argUsage=", (int)usage";
				headerGet+=")const{\n\treturn GetMatchingResource(GetGenericLinksLength()+"+WString::valueOf(nu)+argUsage+", partMap";
				headerGetLink+=")const{\n\treturn GetMatchingLink(GetGenericLinksLength()+"+WString::valueOf(nu)+argUsage;
				headerRem+="){\n\treturn RemoveMatchingLink(GetGenericLinksLength()+"+WString::valueOf(nu)+argUsage+", bRemoveResource";
				headerApp+="){\n\treturn AppendMatchingResource(GetGenericLinksLength()+"+WString::valueOf(nu)+argUsage;
				headerLink+=", const mAttribute &partMap){\n\treturn LinkMatchingResource(GetGenericLinksLength()+"+WString::valueOf(nu)+",resource"+argUsage;
				if(nMax>1){
					headerGet+=",iSkip";
					headerGetLink+=",iSkip";
					headerRem+=",iSkip";
				}else{
					headerGet+=",0";
				}

				headerGet+=");\n};\n";
				headerGetLink+=");\n};\n";
				headerRem+=");\n};\n";
				headerApp+=",resourceRoot);\n};\n";
				headerLink+=", partMap);\n};\n";
				h<<headerGet;
				h<<headerGetLink;
				h<<headerApp;
				h<<headerRem;
				h<<headerLink;
				h<<"\n////////////////////////////////////////////////////////////////////////\n";
			}
		}



		if(loop<=1){
			h<<"}; // end" <<cName<<"\n\n// ******************************************************\n";
		}
		h<<"}; // end namespace JDF\n";
		if(loop<=1){
			h<<"#endif //"<<saver<<endl;
		}
		h.close();


	}
	return 0;
}
//////////////////////////////////////////////////////////////////////

int SchemaDoc::MakeCProc(){
	KElement r=GetRoot();
	vElement e=r.GetChildrenByTagName("xs:complexType","",MapWString(),false);
	vWString doneList;
	vWString names;
	vElement vPools;

	typeNames = "enum EnumType{Type_Unknown"; 
	typeNameString = "const WString TypeString(){\nWString s=L\"Type_Unknown" ;
	linkNames = "WString JDFNode::LinkNames(EnumType typeNum){\nswitch(typeNum):\n{\n"; 
	linkInfo = "WString JDFNode::LinkInfo(EnumType typeNum){\nswitch(typeNum):\n{\n"; 

	for(int i=0;i<e.size();i++){
		SchemaElement seProc=e[i];
		if (e[i].GetXPathAttribute("xs:complexContent/xs:extension@base")!="jdf:JDFAbstractNode")
			continue;

		WString name=seProc.GetCTName("",true);
		cout<<name<<endl;

		//		if(name!=L"PreviewGeneration")			continue;

		names.push_back(name);
		vWString vName;
		vWString vInfo;

		WString RseLinkPoolType;

		KElement ERLP=seProc.GetXPathElement("xs:complexContent/xs:extension/xs:sequence");
		KElement RLPRef=ERLP.GetChildWithAttribute("xs:element","name","","ResourceLinkPool");
		WString resLinkPoolType=RLPRef.GetAttribute("type").rightStr(-4);
		KElement se=r.GetChildWithAttribute("xs:complexType","name","",resLinkPoolType);


		vElement vE=se.GetXPathElement("xs:complexContent/xs:extension/xs:sequence").GetChildElementVector("xs:element");
		vElement vAppInfo=r.GetChildWithAttribute("xs:complexType","name","",name).GetXPathElement("xs:annotation/xs:appinfo").GetChildElementVector("Constraint");
		//		cout<<r.GetChildWithAttribute("xs:complexType","name","",name)<<endl;
		vWString vResName;
		vWString vResTyp;
		if(vE.size()==1){
			SchemaElement s=vE[0];

			WString resName=s.GetAttribute("name");
			if(resName.empty()&&s.GetAttribute("ref")=="jdf:ResourceLink"){
				for(int jj=vAppInfo.size()-1;jj>=0;jj--){
					SchemaElement constraint=vAppInfo[jj];
					//									cout<<constraint;
					WString resName2=constraint.GetAttribute("Path");
					resName2=resName2.rightStr(-17);
					if(WString(L"ApprovalSuccess,Device,Employee,Tool,Preview,PreflightReport").find(resName2.leftStr(-4))!=WString::npos){
						if(constraint.GetAttribute("Usage")=="Input")
							continue;
					}

					vResName.AppendUnique(resName2);
					vResTyp.push_back("ResourceLink");

				}

			}


		}else{
			for(int j=0;j<vE.size();j++){
				SchemaElement s=vE[j];
				WString resName=s.GetAttribute("name");

				if(resName.empty()){
					resName=s.GetAttribute("ref");
					if(resName=="jdf:ResourceLink"){
						resName="*";
					}else{
						resName=resName.rightStr(-4);
					}
				}

				if(resName.empty()&&s.GetAttribute("ref")=="jdf:ResourceLink")
					resName="*";


				vResName.push_back(resName);
				vResTyp.push_back(s.GetAttribute("type"));
			}
		}

		for(int j=0;j<vResName.size();j++){
			vWString vType;
			WString resName=vResName[j];


			bool hasConstraint=false;
			for(int jj=vAppInfo.size()-1;jj>=0;jj--){
				SchemaElement constraint=vAppInfo[jj];
				//				cout<<constraint;
				WString resName2=constraint.GetAttribute("Path");
				if(resName2!="ResourceLinkPool/"+resName)
					continue;

				hasConstraint=true;
				WString myType=(constraint.GetAttribute("Usage")=="Input")?"i":"o";
				WString mino=constraint.GetAttribute("minOccurs","",0);
				WString maxo=constraint.GetAttribute("maxOccurs","",1);
				if((mino=="0")&&(maxo=="1")){
					myType+="?";
				}else if((mino=="1")&&(maxo=="1")){
					myType+="_";
				}else if((mino=="1")&&(maxo=="unbounded")){
					myType+="+";
				}else if((mino=="0")&&(maxo=="unbounded")){
					myType+="*";
				}else{
					cout <<"ToProcCode illegal cardinality:"<<mino<<" - "<<maxo<<endl;
					myType+="_";
				}
				WString pu=constraint.GetAttribute("ProcessUsage");
				if(!pu.empty())
					processUsages.AppendUnique(pu);

				myType+=pu;
				vType.push_back(myType);	
			}
			if(resName.rightStr(4)=="Link"){				
				vName.push_back(resName.leftStr(-4)); // fill missing with name
			}else{
				vName.push_back(resName);
			}
			if(hasConstraint){
				vInfo.push_back(vType.GetString());
			}else{
				WString typ=vResTyp[j];
				if(typ.endsWith(L"In")){
					vInfo.push_back("i?");
				}else if (typ.endsWith(L"Out")){
					vInfo.push_back("o?");
				}else if (typ.endsWith(L"Link")){
					vInfo.push_back("i? o?");
				}else{
					cout <<endl << "No constraint for node "<<name<<" link: "<<resName<<endl;
					vInfo.push_back("i? o?");
				}

			}
		}

		if(vAppInfo.size()){
			for(int i=0;i<vAppInfo.size();i++){
				SchemaElement constraint=vAppInfo[i];
				//				cout<<constraint;
				WString resName2=constraint.GetAttribute("Path");
				if(WString("ResourceLinkPool/Device ResourceLinkPool/DeviceLink ResourceLinkPool/ApprovalSuccessLink ResourceLinkPool/EmployeeLink").find(resName2)!=WString::npos)
					continue;
				//				cout<<"--> "<<vAppInfo[i]<<endl;
			}
		}
		//		ToProcCode("Node"+name,vName,vInfo,schemaFileName);
		ToProcCode2(name,vName,vInfo,schemaFileName);
	}
	linkNames+="}\n return GenericLinkNames();\n}\n";
	linkInfo+="}\n return GenericLinkInfo();\n}\n";
	typeNames+="}\n";
	typeNameString+="\");\nreturn s;\n}\n";

	ofstream procList("ProcList.txt");
	WString pus="enum EnumProcessUsage{ProcessUsage_Unknown,ProcessUsage_AnyInput,ProcessUsage_AnyOutput,ProcessUsage_Any";
	WString pustr="WString ProcessUsageString=L\"Unknown,AnyInput,AnyOutput,Any";
	for(int ipu=0;ipu<processUsages.size();ipu++){
		pus+=",ProcessUsage_"+processUsages[ipu];
		pustr+=","+processUsages[ipu];

	}
	pus+="};\n";
	pustr+="\";\n";
	procList<<pus<<endl;
	procList<<"\n**********************************************************\n";
	procList<<pustr<<endl;
	procList<<"\n**********************************************************\n";
	procList<<typeNames<<endl;
	procList<<"\n**********************************************************\n";
	procList<<typeNameString<<endl;
	procList<<"\n**********************************************************\n";
	procList<<linkNames<<endl;
	procList<<"\n**********************************************************\n";
	procList<<linkInfo<<endl;
	procList<<"\n**********************************************************\n";

	procList.close();
	return 0;
}
//////////////////////////////////////////////////////////////////////

int SchemaDoc::MakeC(const WString& classString){
	KElement r=GetRoot();

	vElement e=r.GetChildrenByTagName("xs:complexType","",MapWString(),false);
	vWString doneList;
	vWString names;
	WString AllResStringsC;
	WString AllResStringsH;

	int i;
	for(i=0;i<e.size();i++){
		SchemaElement se=e[i];
		WString nameNoStrip=se.GetCTName("",false);
		names.push_back(nameNoStrip);

		if(nameNoStrip.rightStr(2)=="_r"||nameNoStrip.rightStr(3)=="_re"){
			WString name=se.GetCTName();
			if(name=="Shape") 
				name="ShapeElement";

			KElement e=r.GetChildWithAttribute("xs:complexType","name","",nameNoStrip);
			vElement v=e.GetChildrenWithAttribute("xs:attributeGroup","ref","","*",false);
			bool bFound=false;
			for(int i=0;i<v.size();i++){
				WString s=v[i].GetAttribute("ref");
				if(s.startsWith("jdf:ParameterAttribs")){
					classMap.AddPair(name,"Class_Parameter");
					bFound=true;
				}else if(s.startsWith("jdf:HandlingAttribs")){
					classMap.AddPair(name,"Class_Handling");
					bFound=true;
				}else if(s.startsWith("jdf:ConsumableAttribs")){
					classMap.AddPair(name,"Class_Consumable");
					bFound=true;
				}else if(s.startsWith("jdf:QuantityAttribs")){
					classMap.AddPair(name,"Class_Quantity");
					bFound=true;
				}else if(s.startsWith("jdf:PlaceHolderAttribs")){
					classMap.AddPair(name,"Class_PlaceHolder");
					bFound=true;
				}else if(s.startsWith("jdf:Selector")){
					classMap.AddPair(name,"Class_Selector");
					bFound=true;
				}else if(s.startsWith("jdf:ImplementationAttribs")){
					classMap.AddPair(name,"Class_Implementation");
					bFound=true;
				}else if(s=="jdf:IntentAttribs"){
					// do nothing!
					bFound=true;
				}



				if(names.hasString(nameNoStrip.leftStr(-1)+"_")) 
					continue;
				if(names.hasString(nameNoStrip+"p")) 
					continue;
			}
			if(!bFound){
				KElement e1=e.GetElement("xs:complexContent");
				KElement ext=e1.GetElement("xs:extension");
				if(ext.isNull()) 
					ext=e1.GetElement("xs:restriction");
				WString base=ext.GetAttribute("base");
				if(!base.empty()){
					if(base=="jdf:ParameterResourceForcedComment"){
						classMap.AddPair(name,"Class_Parameter");
					}else if(base.startsWith("jdf:ParameterResource")){
						classMap.AddPair(name,"Class_Parameter");
					}else if(base.startsWith("jdf:PartParameterResource")){
						classMap.AddPair(name,"Class_Parameter");
					}else if(base=="jdf:PreflightResultsPool"){
						classMap.AddPair(name,"Class_Parameter");
					}else if(base.startsWith("jdf:HandlingResource")){
						classMap.AddPair(name,"Class_Handling");
					}else if(base.startsWith("jdf:ConsumableResource")){
						classMap.AddPair(name,"Class_Consumable");
					}else if(base.startsWith("jdf:QuantityResource")){
						classMap.AddPair(name,"Class_Quantity");
					}else if(base.startsWith("jdf:PlaceHolderResource")){
						classMap.AddPair(name,"Class_PlaceHolder");
					}else if(base.startsWith("jdf:ImplementationResource")){
						classMap.AddPair(name,"Class_Implementation");
					}else if(base.startsWith("jdf:ResourceElement")){
						classMap.AddPair(name,"Class_Parameter");
					}else if(base.startsWith("jdf:PhysicalResourceElement")){
						classMap.AddPair(name,"Class_Parameter");
					}else if(base.startsWith("jdf:IntentResource")){
						// do nothing
					}else{
						cout << "whazzup classmap??? "<<base<<endl<<e;
					}
				}else{
					cout << "whazzup 2??? ";//<<base<<endl<<e;
				}				
			}
		}
	}


	for(i=0;i<e.size();i++){
		SchemaElement se=e[i];
		WString name=se.GetCTName();
		WString _type=se.GetAttribute("type");
		if(name=="Shape") 
			name="ShapeElement";

		if(name.find(classString)==name.npos) 
			continue;
		if(name=="NotificationDetails")
			continue;

		//			if(name==L"SeparationList")
		//			continue;
		if(name.find(L"ResultsPool")!=name.npos)
			continue;
		if(name.find(L"ConstraintsPool")!=name.npos)
			continue;
		if(name.find("PartAmount")!=name.npos) 
			continue;

		if(name.find(L"PreflightCommon")!=_type.npos)
			continue;
		if(name.endsWith(L"Evaluation"))
			continue;
		/*
		if(_type.find(L"Preflight")!=_type.npos)
		continue;
		*/
		WString nameNoStrip=se.GetCTName("",false);
		if(nameNoStrip=="NodeInfo_" || nameNoStrip=="CustomerInfo_")
			continue; // take resources, not the deprecated sub elements

		if(nameNoStrip.rightStr(3)=="_ru") 
			continue;
		if(nameNoStrip.rightStr(4)=="_rue") 
			continue;
		if(nameNoStrip.rightStr(2)=="_u") 
			continue;
		if(nameNoStrip.rightStr(3)=="_lu") 
			continue;
		if(nameNoStrip.rightStr(3)=="_me") 
			continue;

		if(nameNoStrip.rightStr(3)=="_rp"){
			if(names.hasString(nameNoStrip.leftStr(-2)+"re")) 
				continue;
			if(names.hasString(nameNoStrip.leftStr(-2)+"r")) 
				continue;
		}
		if(nameNoStrip.rightStr(3)=="_re"){
			if(names.hasString(nameNoStrip.leftStr(-1))) 
				continue;
		}
		if(nameNoStrip.rightStr(8)=="BaseType"){
			if(names.hasString(nameNoStrip.leftStr(-8))) 
				cout<<"gotcha ! " <<nameNoStrip;
			continue;
		}
		// 080702 RP added QueueEntry
		bDoStatus=(name=="Resource")||(name=="Queue")||(name=="QueueEntry")||(name.startsWith(L"Preflight"));
		bDoOrientation=(name=="SignatureCell");
		//		if(se.IsMessage()) 
		//			continue;
		if(se.IsCore(name)) 
			continue;
		WString base=se.GetBase();
		if(base.empty()) 
			continue;
		if(base=="JDFSignal"||base=="JDFCommand"||base=="JDFQuery"||base=="JDFResponse"||base=="JDFAcknowledge"||base=="JDFRegistration")
			continue;

		if (doneList.hasString(name)){
			cout<<" done name: "<<name<< " not done: "<<nameNoStrip<<endl;
			//			cout<<se;
			continue;
		}
		if("JDF"+name==base) {
			cout<<"recursion in "<<name<<endl;
			continue;
		}
		if(name=="Selector") 
			continue;  // all dead!
		cout<<">>>>>>>>>>>>>>> JDF "<<name<<endl;
		doneList.AppendUnique(name);

		if((name=="MarkObject")||(name=="ContentObject")){
			MergeRes("Layout_PlacedObject","Layout_"+name+"_lr");
		}

		se.ToCode(schemaFileName);
		//		if(base=="JDFResource"){
		allElms.AppendUnique(name);
		//		}
	}
	int iA;
	for(iA=0;iA<allElms.size();iA++){
		WString name=allElms[iA];
		AllResStringsC+=L"const WString JDFElement::elm_"+name+L"=L\""+name+L"\";\n";
		AllResStringsH+=L"static const WString elm_"+name+L";\n";
	}
	AllResStringsC+=L"\n//////////////////////////////////////////////////////////\n";
	AllResStringsH+=L"\n//////////////////////////////////////////////////////////\n";
	for(iA=0;iA<allAtts.size();iA++){
		WString name=allAtts[iA];
		AllResStringsC+=L"const WString JDFElement::atr_"+name+L"=L\""+name+L"\";\n";
		AllResStringsH+=L"static const WString atr_"+name+L";\n";
	}

	ofstream resList("ResList.txt"); 
	resList<<AllResStringsC;
	resList<<endl<<"*************************************\n\n"<<AllResStringsH;
	resList.close();


	// create typesafe enumerationspans
	/*
	e=r.GetChildrenWithAttribute("xs:element", "type", WString::emptyStr, "jdf:EnumerationSpan", false);
	SchemaElement se;
	ofstream h;
	se.LicOpen("AutoH/JDFAutoEnumerationSpan.h",h);
	h<<"#ifndef _JDFAutoEnumerationSpan_H_\n#define _JDFAutoEnumerationSpan_H_\n#include \"JDFSpan.h\"\nnamespace JDF{\n";
	ofstream hc;
	se.LicOpen("AutoC/JDFAutoEnumerationSpan.cpp",hc);
	hc<<"#include \"JDFAutoEnumerationSpan.h\"\n#include \"JDFHoleMakingParams.h\"\nnamespace JDF{\n";
	doneList.clear();
	for(i=0;i<e.size();i++){
	SchemaElement se=e[i];
	vWString v=se.ToEnumerationSpan();
	if(doneList.hasString(v[0])) 
	continue;
	doneList.AppendUnique(v[0]);
	cout<<" ToEnumerationSpan "<<v[0]<<endl;
	h<<v[1];
	hc<<v[2];
	}
	h<<"}\n#endif //_JDFAutoEnumerationSpan_H_\n";
	h.close();
	hc<<"}\n";
	hc.close();
	*/
	return 0;
}

//////////////////////////////////////////////////////////////////////

int SchemaDoc::MakeCC(){
	int i;
	KElement r=GetRoot();
	vElement e=r.GetChildrenByTagName("xs:complexType","",MapWString(),false);
	vWString doneList;
	vWString allL;
	e=r.GetChildrenByTagName("xs:complexType","",MapWString(),false);
	e.AppendUnique(r.GetChildrenWithAttribute("xs:element","type","","jdf:EnumerationSpan",false));
	for(i=0;i<e.size();i++){
		SchemaElement se=e[i];
		WString name=se.GetCTName();
		if(name.leftStr(1)=="_") 
			continue;
		if(se.IsCore(name)) 
			continue;
		WString base=se.GetBase();
		if(base.empty()) 
			continue;
		doneList.AppendUnique(name);
	}
	for(int j=0;j<2;j++){
		for(int i=0;i<doneList.size();i++){
			WString name=doneList[i];
			if(name.find(L"_")!=name.npos)
				continue;
			if(j==0) {
				//				cout<<"\tstatic JDF"<<name<<" member"<<i<<";"<<endl;
			}else{
				cout<<"if(resName==elm_"+name+"){\n\treturn new JDF"<<name<<"(part);\n};\n";			

			}
		}
	}
	vWString SpanTypes=WString("IntegerSpan NameSpan NumberSpan OptionSpan XYPairSpan StringSpan TimeSpan ShapeSpan DurationSpan").Tokenize();

	for(int ss=0;ss<SpanTypes.size();ss++){
		e=r.GetChildrenWithAttribute("xs:element","type","","jdf:"+SpanTypes[ss],false);
		vWString v;
		for(i=0;i<e.size();i++){
			v.AppendUnique(e[i].GetAttribute("name"));
		}
		cout<<"if(WString(L\""<<v.GetString(",")<<"\").Tokenize(WString::comma).hasString(resName)){\n\treturn new JDF"<<SpanTypes[ss]<<"(part);\n};\n";
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
