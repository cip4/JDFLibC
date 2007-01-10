#pragma warning( disable : 4786 ) // long debug names from stl
#pragma warning( disable : 4804 ) // bool checking


#include "MyArgs.h"
#include "MyTime.h"
#include "jdf/wrapper/JDFFactory.h"
#include "jdf/wrapper/JDF.h"
#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/ErrorHandler.hpp>
#include <xercesc/sax/SAXParseException.hpp>

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
* internal error handler class that does NOT ignore foreign namespaces
*
*/
class MyErrorHandler : public ErrorHandler {
public:
	MyErrorHandler():ErrorHandler(){};
	void warning(const SAXParseException& exception){
		std::cout << "warning " << exception.getMessage() << std::endl;
	}
	void error(const SAXParseException& exception){
		// print out all parser errors except undefined variables for non-JDF stuff
		WString er(exception.getMessage());
		std::cout <<"error " << er <<std::endl;
	}
	void fatalError(const SAXParseException& exception){
		std::cout << "fatalError " << exception.getMessage() <<std::endl;
		throw JDFException("Fatal error in the Parser:" + WString(exception.getMessage()));
	}
	void resetErrors(){}

};
/**
* the subroutine to print out invalid parts of a jdf.
* @param JDFElement &jdfElement the element to print
* @param bool bQuiet flag what to do with valid elements; shut up if true
* @param KElement::EnumValidationLevel level validation level of the element
*/

void PrintBad(const JDFElement &jdfElement, bool bQuiet, KElement::EnumValidationLevel level, int indent, bool bPrintNameSpace){
	int j;
	
	static vWString foundNameSpaces;
	static vWString foundNameSpaceURIs;
	
	bool isJDFNS=jdfElement.IsInJDFNameSpace();
	WString prefix=jdfElement.GetPrefix();
	WString nsURI=jdfElement.GetNamespaceURI();
	if(!isJDFNS){
		WString nsURIU=nsURI.toUpperCase();
		bool bTryIt=(prefix.empty()&&(nsURIU.find(L"CIP4")!=nsURI.npos)) || !prefix.compareToIgnoreCase(L"JDF");
		
		if(bPrintNameSpace && !foundNameSpaceURIs.hasString(nsURI)){
			foundNameSpaceURIs.push_back(nsURI);
			cout << Indent(indent+2);
			if(bTryIt){
				cout<<"Testing ";
			}else{
				cout<<"Skipping ";
			}
			cout<<"Element that is not in JDF nameSpace: <"<<jdfElement.GetNodeName()<<"> namespace: "<<prefix<<" uri: "<<nsURI<<endl;
		}
		if(!bTryIt)
			return;
		
	}
	
	JDFRefElement refEl;
	JDFFactory f(jdfElement);
	// get a reference to a factory object, i.e. a fully qualified JDF leaf element such as a JDFRunList etc.
	//	JDFElement &part=f.GetRef();
	JDFElement *pPart;
	if(jdfElement.IsRefElement()){
		refEl=jdfElement;
		pPart=&refEl;
	}else{
		pPart=&(f.GetRef());
	}
	
	JDFElement &part=*pPart;
	
	// found an unknown element
	if(part.isNull()){
		cout <<Indent(indent)<<"Factory unknown: "<<jdfElement.GetNodeName()<<endl;
		part=jdfElement;
		//		return;
	}
	bool bIsValid;
	WString nam=part.GetNodeName();
	
	bIsValid=part.IsValid(level);
	bIsValid=part.IsValid(level);
	
	vWString privateAttributes=part.GetUnknownAttributes(false);
	vWString unknownAttributes=part.GetUnknownAttributes(true);
	privateAttributes.RemoveStrings(unknownAttributes);
	
	vWString privateElements=part.GetUnknownElements(false);
	vWString unknownElements=part.GetUnknownElements(true);
	privateElements.RemoveStrings(unknownElements);
	if(bPrintNameSpace){
		if(!privateAttributes.empty()||!privateElements.empty()){
			cout <<Indent(indent)<<"Element with private contents:   "<<part.GetXPath()<<" "<<part.GetID()<<endl;
		}
		for( j=0;j<privateAttributes.size();j++){ 
			WString privateAttribute=privateAttributes[j];
			WString prefix=privateAttribute.Token(0,":");
			WString localname=privateAttribute.Token(1,":");
			if(prefix=="xmlns"){
				if(!foundNameSpaces.hasString(privateAttribute)){
					cout<<Indent(indent+2)<<"Foreign namespace found: "<<localname<<" "<<part.GetAttribute(privateAttribute)<<endl;
					foundNameSpaces.push_back(privateAttribute);
				}
			}else{					
				cout<<Indent(indent+2)<<"Private Attribute:\t\t"<<prefix<<" "<<localname<<" = "<<part.GetAttribute(privateAttribute)<<endl;			
			}
		}
		for( j=0;j<privateElements.size();j++) 
			cout<<Indent(indent+2)<<"Private Element: "<<privateElements[j]<<endl;			
	}
	
	if(bIsValid){
		// print out validity if not quiet
		if(!bQuiet) 
			cout <<Indent(indent)<<"--- Valid:   "<<part.GetXPath()<<" "<<part.GetID()<<endl;
		
	}else{
		// this one is bad -> recurse to find reason
		cout <<Indent(indent)<<"!!! InValid Element: "<<jdfElement.GetXPath()<<" "<<jdfElement.GetID()<<" !!! "<<endl;
		
		if(part.IsRefElement()){
			JDFRefElement re=part;
			// this was already calculated a few lines up and is still valid here
			if(!re.IsValid(level)){
				if(re.ValidResourcePosition()){
					cout<<Indent(indent+2)<<"Invalid Reference: "<<re.GetNodeName()<<" rRef="<<re.GetrRef()<<endl;	
				}else{
					cout<<Indent(indent+2)<<"Invalid Reference location: "<<re.GetNodeName()<<" rRef="<<re.GetrRef()<<endl;	
				}				
			}
			return;
		}
		
		
		bool printMissElms=true;
		if(part.IsResource()&&(((JDFResource&)part).GetStatus()==JDFResource::Status_Incomplete)||(!((JDFResource&)part).IsLeaf()&&(((JDFResource&)part).GetPartUsage()!=JDFResource::PartUsage_Implicit))){
			const JDFResource& r=part;
			printMissElms=false;
		}
		
		// get a list of missing and invalid attribute and element names
		vWString invalidAttributes=part.GetInvalidAttributes(level);
		vWString missingAttributes;
		vWString missingElements;
		vWString invalidElements=part.GetInvalidElements(level);
		vWString swapElem;
		vWString swapAtt;
		vWString vTmp=part.KnownElements().Tokenize(",");
		// compare missing elements with unknown attributes to find elem <-> attrib swaps
		for(j=0;j<unknownAttributes.size();j++){
			if(vTmp.hasString(unknownAttributes[j])){
				swapAtt.AppendUnique(unknownAttributes[j]);
			}
			
		}
		
		// compare missing attributes with unknown elements to find elem <-> attrib swaps
		vTmp=part.KnownAttributes().Tokenize(",");
		for(j=0;j<unknownElements.size();j++){
			if(vTmp.hasString(unknownElements[j])){
				swapElem.AppendUnique(unknownElements[j]);
			}
			
		}
		// unknown attributes are also invalid -> remove them from the print list
		invalidAttributes.RemoveStrings(unknownAttributes);
		// unknown elements are also invalid -> remove them from the print list
		invalidElements.RemoveStrings(unknownElements);
		// swapped elements are also invalid -> remove them from the print list
		unknownElements.RemoveStrings(swapElem);
		// swapped attributes are also invalid -> remove them from the print list
		unknownAttributes.RemoveStrings(swapAtt);
		
		// find missing elements and attributes
		if(level>=KElement::ValidationLevel_Complete){
			missingAttributes=part.GetMissingAttributes();
			// missing attributes are also invalid -> remove them from the print list
			invalidAttributes.RemoveStrings(missingAttributes);
			missingElements=part.GetMissingElements();
			// missing elements are also invalid -> remove them from the print list
			invalidElements.RemoveStrings(missingElements);
		}
		
		// remove all double entries before printing
		unknownAttributes.Unify();
        unknownElements.Unify();
        invalidAttributes.Unify();
        invalidElements.Unify();
        missingAttributes.Unify();
        missingElements.Unify();
		
		
		// print the various snafus
		for( j=0;j<unknownAttributes.size();j++) 
			cout<<Indent(indent+2)<<"Unknown Attribute: "<<unknownAttributes[j]<<" = "<<part.GetAttribute(unknownAttributes[j])<<endl;			
		for( j=0;j<invalidAttributes.size();j++) 
			cout<<Indent(indent+2)<<"Invalid Attribute: "<<invalidAttributes[j]<<" = "<<part.GetAttribute(invalidAttributes[j])<<endl;				
		if(printMissElms){
			for( j=0;j<missingAttributes.size();j++) 
				cout<<Indent(indent+2)<<"Missing Attribute: "<<missingAttributes[j]<<endl;				
		}
		for( j=0;j<swapElem.size();j++) 
			cout<<Indent(indent+2)<<"Attribute is written as Element: "<<swapElem[j]<<endl;				
		for( j=0;j<swapAtt.size();j++) 
			cout<<Indent(indent+2)<<"Element is written as Attribute: "<<swapAtt[j]<<endl;				
		if(printMissElms){
			for( j=0;j<missingElements.size();j++) 
				cout<<Indent(indent+2)<<"Missing Element: "<<missingElements[j]<<endl;
		}
		for( j=0;j<unknownElements.size();j++) 
			cout<<Indent(indent+2)<<"Unknown Element: "<<unknownElements[j]<<endl;				
		
		for( j=0;j<invalidElements.size();j++){ 
			if(part.NumChildElements(invalidElements[j])>1)
				cout<<Indent(indent+2)<<"Invalid Element - (potential duplicate): "<<invalidElements[j]<<endl;
			KElement ePart=part;
			KElement eInv=ePart.GetElement(invalidElements[j]);
			if(eInv.isNull()){
				eInv=ePart.GetElement(invalidElements[j]+"Ref");
				if(!eInv.isNull())
					cout<<Indent(indent+2)<<"Invalid Element - (potential reference to invalid element): "<<invalidElements[j]+"Ref"<<endl;
			}
		}
		
		if(part.IsResource()&&!((JDFResource&)part).IsLeaf()){
			vElement vr=((JDFResource&)part).GetLeaves();
			for(int i=0;i<vr.size();i++){
				PrintBad(vr.at(i),bQuiet,level,indent+2,bPrintNameSpace);
			}
		}
		
		// check typesafe node links
		if(KElement::XMLNSLocalName(nam.c_str())==L"JDF"){
			
			JDFNode &e=(JDFNode&)part;
			cout<<Indent(indent)<<"Node Type= "<<e.GetType();
			if(e.HasAttribute("Types"))
				cout<<" - "<<e.GetAttribute("Types");
			cout<<endl;
			
			if(e.IsProduct()){
				JDFNode n=e.GetParentJDFNode();
				if(!n.isNull()){
					if(n.GetType()!=L"Product"){
						cout <<Indent(indent)<< "Invalid Parent for JDF Product: Type= "<<n.GetType()<<endl;
					}
				}
			}
			
			JDFResourceLinkPool linkPool=e.GetResourceLinkPool();
			vint foundSingleNamLinks;
			vint foundSingleIndexLinks;
			vWString vMissingElem=e.GetMissingLinks();
			if(!linkPool.isNull()){ 
				vElement vLinks=linkPool.GetLinks();
				for(int i=vLinks.size()-1;i>=0;i--){
					JDFResourceLink rl=vLinks[i];
					if(!e.IsValidLink(level,rl,foundSingleNamLinks,foundSingleIndexLinks)){
						cout <<Indent(indent)<< "Invalid "<<rl.GetAttribute("Usage")<<" ResourceLink "<<rl.GetNodeName().leftStr(-4)<<" rRef="<<rl.GetrRef();
						if(rl.HasAttribute(rl.atr_ProcessUsage)){
							cout<<rl.GetProcessUsage();
						}else{
							for(int i=0;i<vMissingElem.size();i++){
								vWString vs=vMissingElem[i].Tokenize(":");
								if(vs.size()==2){
									if(vs[0]==rl.GetNodeName()){
										cout<<"potential missing ProcessUsage: " <<vs[1]<<endl;
									}
								}
							}
						}
						cout<< endl;
						
					}
				}
			}
			
			if((level==JDFElement::ValidationLevel_Complete)||(level==JDFElement::ValidationLevel_RecursiveComplete)){
				vWString vElem=e.GetMissingLinks();
				for(int i=0;i<vElem.size();i++){
					cout <<Indent(indent)<<"Missing ResourceLink "<<vElem[i]<<endl;
				}
			}		
		}
	}
	vElement ve=part.GetChildElementVector();
	for(int i=0;i<ve.size();i++) 
		PrintBad(JDFElement(ve[i]),bQuiet,level,indent+2,bPrintNameSpace);
	
}

//////////////////////////////////////////////////////////////////////////////

void PrintDevCap(JDFElement jdfRoot, const WString& devCapFile, JDFElement::EnumFitsValue testlists, KElement::EnumValidationLevel level){
	
	if(devCapFile.empty()) {
		return;
	}
	JDFDoc docDevCap;
	docDevCap.Parse(devCapFile,false);
	
	JDFJMF jmfRoot=docDevCap.GetJMFRoot();
	
	if (jmfRoot.isNull()) {
		throw JDFException("JMFNode == null --> can't start Test");
	}
		
	JDFDeviceCap deviceCap = jmfRoot.GetDeepElement("DeviceCap");
	if (deviceCap.isNull()) {
		throw JDFException("No DeviceCap element found --> can't start Test");
	}
	
	vElement vExecNodes = deviceCap.GetExecutableJDF(jdfRoot, testlists, level);
	
	if (!vExecNodes.empty()) { 
		cout << "\nExecutable Nodes are" << endl;
		for (int j=0; j<vExecNodes.size(); j++) {
			cout << vExecNodes[j].GetXPath() << "   ID= "<<vExecNodes[j].GetAttribute(JDFElement::atr_ID)<<endl << endl;
		}
		cout <<endl << endl;
	}
	else 
		cout << "No executable nodes that fit device capabilities were found" << endl<< endl;
	

	XMLDoc testResult = deviceCap.GetBadJDFInfo(jdfRoot, testlists,level);
	if (testResult.isNull()) {
		cout << "Result of Device capability check: It's OK. No bad JDF are found\n" <<endl;
	}
	else {
		WString outputFileName = L"_BugReport_CheckJDF.xml";
		cout << "Result of GetBadJDFInfo you can find in " + outputFileName <<endl;
		
		testResult.Write2File(outputFileName);
		
	}
	
}	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]){
    // Initialize the XML4C2 system 
	int i;
    try{
        XMLPlatformUtils::Initialize();
    }catch(const XMLException& toCatch){
        cout << "Error during XML4C2 Initialization.\n"
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
	
	MyArgs args(argc,argv,"?cqvVnt","dlLuhp");
	
	WString version="CheckJDF: JDF validator; -- (c) 2001-2005 CIP4\n JDF 1.3 compatible version\n";
	version+="\n Code based on schema JDF_1.3.xsd alpha Candidate 001\n";
	version+="Build version "+JDFAudit::Software();
	
	WString usage=L"\n\nUsage: <input JDF files> \n"; 
    usage+="-V(ersion)  -q(uiet)  -c(omplete)  -n(amespace)  -v(alidate)  -t(ime)\n";
    usage+="-u(RL)<URL>  -h(ost)  -p(ort)  \n";
	usage+="-L(ocation)<schemaLocation> -l(ocation)<privateSchemaLocation> \n"; 
    usage+="-d(eviceCapabilities)<input JDM file>  -P(resentValueLists) \n\n";
                
	usage+="-? usage info\n";
	usage+="-c requires all required elements and attributes to exist, else incomplete JDF is OK\n";
	usage+="-d location of a device capabilities file to test against\n";
	usage+="-h proxy host name\n";
	usage+="-l location of additional private schema for validation in the same format as xsi:schemaLocation\n\texcept that multiple schema and schema/namespace pairs are separated by commas ',' not blanks ' '\n\tThe JDF schema specified in the -L switch should not be included in this list\n";
	usage+="-L location of the schema for the Namespace \"http://www.CIP4.org/JDFSchema_1_1\"\n\tNote that blanks ' ' are invalid in the file names\n";
	usage+="-n will report all elements from foreign name spaces. \n\tIf -n is not set, validating parser errors will also be ignored.\n";
	usage+="-q is quiet for valid files\n";
	usage+="-P device capabilities parameter. Use present value lists, otherwise allowed value lists\n";
	usage+="-p proxy port name\n";
	usage+="-t print out Timing information\n";
	usage+="-u URL to send the JMF to. In this case, checkJDF will validate the response from the URL\n";
	usage+="-v validate using XML Schema validation;\n\tthe Schema can be defined in the xsi:schemaLocation tag in the JDF or using the -l or -L switch\n";
	usage+="-V Always print a version stamp, even in quiet mode (-q)\n";
	
	if(args.BoolParameter('?')){
		cout<<"checkJDF:\n"<<version<<usage;
		return 0;
	}
	
	bool bQuiet=args.BoolParameter('q');
	bool bVersion=!bQuiet||args.BoolParameter('V');
	bool bPrintName=args.BoolParameter('n');
	MyErrorHandler errorHandler;
	ErrorHandler* pErrHandle=bPrintName ? &errorHandler : 0; // print parser errors if '-n' is selected
	
	
	if(bVersion)
		cout<<endl<<version<<endl<<endl;
	
	KElement::EnumValidationLevel level=args.BoolParameter('c')?KElement::ValidationLevel_Complete:KElement::ValidationLevel_Incomplete;
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
		schemaLocation+=WString::blank+schemaLocation0;
	}
	
	
	bool bValidate=(args.BoolParameter('v'))||(!schemaLocation.empty());
	if(!args.NArgs()){
		cout<<args.Usage(usage)<<endl;
		return 2;
	}

	WString URL=args.ParameterString('u');
	for(int arg=0;arg<args.NArgs();arg++){
		
		WString xmlFile=args.ArgumentString(arg);
		if(!bQuiet) 
			cout<<"\n*** Checking "<<xmlFile<<" *** "<<URL<<endl;
		
		JDFDoc gd;
		MyTime * pTime=0;
		MyTime * pTime1=0;
		MyTime * pTime2=0;
		// I prefer catching exceptions in the debugger
		try{		
			if(args.BoolParameter('t')){
				pTime=new MyTime("All");
				pTime1=new MyTime("Parse");
				pTime2=new MyTime("Internal CheckJDF",false);
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
				bSnafu=!parser.Parse(xmlFile.c_str(),bValidate,true,true,pErrHandle,schemaLocation.c_str());
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
				if(!URL.empty()){					
					try{
						WString proxyHost = args.ParameterString('h');
						WString proxyPort = args.ParameterString('p');
						if(!proxyHost.empty()){
							JDF::PlatformUtils::setProperty("http.proxyHost",proxyHost);
							if(proxyPort.empty())
								proxyPort=L"8080";
							JDF::PlatformUtils::setProperty("http.proxyPort",proxyPort);
						}

						gd=gd.Write2URL(URL,schemaLocation);
					}catch(JDFException x){
						cout<<"error writing to :"+URL<<endl;
						cout<<x.getMessage()<<endl;
						continue;
					}
					
				}
			}catch(JDFException x){
				cout <<"error parsing :"+xmlFile<<endl;
				continue;
			}
			if(bValidate){
				cout<<"\n\n**********************************************************\n\n";
				cout<<"Output of checkJDF proper follows:\n";
			}
			
			if(args.BoolParameter('t')){
				pTime1->Stop();
				pTime2->Start();
			}
			
			// enable link search caching
			gd.GetCreateXMLDocUserData();
			
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
			if(root.isNull()){ // no jdf, maybe jmf
				PrintBad(jmf,bQuiet,level,0,bPrintName);
			}else{
				vElement vProcs=root.GetvJDFNode(WString::star);
				vElement vResources;
				vElement vLinkedResources;
				vElement vBadResourceLinks;
				// loop over all jdf nodes
				
				for(i=0;i<vProcs.size();i++){
					int j;
					JDFNode n=vProcs[i];
					vLinkedResources.AppendUnique(n.GetLinkedResources(mAttribute(),true));
					JDFResourceLinkPool rlp=n.GetResourceLinkPool();
					JDFResourcePool rp=n.GetResourcePool();
					vElement resources=rp.GetPoolChildren();
					vResources.AppendUnique(resources);
					for(j=0;j<resources.size();j++){
						vResources.AppendUnique(JDFResource(resources[j]).GetvHRefRes(true));
					}
					vElement resLinks=rlp.GetLinks();
					for(j=0;j<resLinks.size();j++){
						JDFResourceLink rl=resLinks[j];
						if (!rl.IsValid(KElement::ValidationLevel_Complete)) 
							vBadResourceLinks.AppendUnique(rl);
					}
					
				}
				vElement vr;
				for(i=0;i<vResources.size();i++){
					vr.AppendUnique(JDFResource(vResources.at(i)).GetResourceRoot());
				}
				vResources=vr;
				
				vr.clear();
				for(i=0;i<vLinkedResources.size();i++){
					vr.AppendUnique(JDFResource(vLinkedResources.at(i)).GetResourceRoot());
				}
				vLinkedResources=vr;
				
				vElement vUnlinkedRes;
				for(i=0;i<vResources.size();i++){
					JDFResource r=vResources[i];
					if(!vLinkedResources.hasElement(r)){
						cout << "unlinked resource: "<<" "<<r.GetNodeName()<<" "<<r.GetID()<<endl;
						vUnlinkedRes.push_back(r);
					}
				}
				
				for(i=0;i<vBadResourceLinks.size();i++){
					JDFResourceLink rl=vBadResourceLinks[i];
					JDFElement ele=JDFElement(rl).GetTarget();
					if(ele.isNull()){
						cout <<"dangling ResLink: "<<rl.GetXPath();
					}else{
						cout <<"invalid  ResLink: "<<rl.GetXPath()<<"... Points to: "<<ele.GetNodeName()<<endl;
						if(!rl.ValidResourcePosition()){
							cout<<"\tinvalid Resource Context, Resource node ID="<<ele.GetParentJDF().GetID()<<" is not an ancestor of ResourceLink node ID="<<rl.GetParentJDF().GetID()<<"!"<<endl;
						}
					}
				}
				
				// find multiple IDS
				vWString vIDs;
				if(root.HasAttribute(root.atr_ID))
					vIDs.push_back(root.GetID());
				
				vWString vSeparations;
				vWString vSeparations2;
				vWString vColorPoolSeparations;
				
				// find all refElements that point to nirvana
				vElement vAllElm=root.GetChildrenByTagName(L"*",L"",mAttribute(),false);
				for(i=0;i<vAllElm.size();i++){
					JDFElement e=vAllElm[i];
					if(e.IsRefElement()){
						JDFRefElement r(e);
						if(!r.IsValid()){
							JDFResource rr=r.GetTarget();
							cout<<"invalid  RefElement: "<<r.GetXPath()<<" rRef="<<r.GetrRef()<<(r.HasAttribute(JDFElement::atr_rSubRef)? WString(L" rSubRef=")+r.GetrSubRef():WString(L""))<<" --> "<<r.GetRefNodeName()<<" ID="<<e.GetTarget().GetID()<<endl;
							if((rr.GetPartUsage()!=JDFResource::PartUsage_Implicit)&&!rr.IsLeaf()){					
								cout<<"\tinvalid RefElement pointer, RefElement ID does not point to a resource leaf!"<<endl;
							}else if(!r.ValidResourcePosition()){
								cout<<"\tinvalid RefElement Context, Resource node ID="<<JDFElement(r).GetTarget().GetParentJDF().GetID()<<" is not an ancestor of RefElement node ID="<<r.GetParentJDF().GetID()<<"!"<<endl;
							}
						}
					}
					if(e.HasAttribute(e.atr_ID)){
						WString id=e.GetID();
						if(vIDs.hasString(id)){
							cout<<"\tmultiply defined ID \""<<id<<"\" in "<<e.GetXPath()<<endl;						
						}else{
							vIDs.push_back(id);
						}						
					}
					if(e.HasAttribute(e.atr_Separation)){
						if(e.GetAttribute(e.atr_Separation)!=""){
							vSeparations.AppendUnique(e.GetAttribute(e.atr_Separation));
						}
					}
					if(e.GetLocalName()==e.elm_SeparationSpec){
						if(e.GetParentNode().GetLocalName()!=L"ColorantAlias"){
							vSeparations.AppendUnique(e.GetAttribute(e.atr_Name));
						}
					}
					if(e.GetLocalName()==e.elm_Color){
						if(e.GetParentNode().GetLocalName()==e.elm_ColorPool){
							vColorPoolSeparations.AppendUnique(e.GetAttribute(e.atr_Name));
						}
					}
				}
				if(!bQuiet){
					for(i=0;i<vSeparations.size();i++){
						cout<<"Separation Name: "<<vSeparations[i]<<endl;
					}
				}

				vSeparations2=vSeparations;
				vSeparations.RemoveStrings(vColorPoolSeparations);
				vColorPoolSeparations.RemoveStrings(vSeparations2);
				
				for(i=0;i<vSeparations.size();i++){
					cout<<"Warning: Separation Name not in ColorPool: "<<vSeparations[i]<<endl;
				}
				for(i=0;i<vColorPoolSeparations.size();i++){
					cout<<"Warning: Unreferenced Separation Name    : "<<vColorPoolSeparations[i]<<endl;
				}

				PrintBad(root,bQuiet,level,0,bPrintName);
		
				// check against devcaps
				WString devCapFile=args.ParameterString('d');

				JDFElement::EnumFitsValue testlists = JDFElement::FitsValue_Allowed;
				if(args.BoolParameter('P')) {
					testlists = JDFElement::FitsValue_Present;
				}

				if(!devCapFile.empty()){
					PrintDevCap(root, devCapFile, testlists, level);
				}
			}
			
		}catch (JDFException e){
			gd.DeleteUserData();
			cout<<"Caught Exception "<<e.getType()<<" "<<e.getMessage()<<endl;
		}
		
		
		delete(pTime);
		delete(pTime1);
		delete(pTime2);
		
	}
	
	JDF::PlatformUtils::Terminate();
	XMLPlatformUtils::Terminate();
	return 0;
}

