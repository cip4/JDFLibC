#include "jdf/wrapper/JDF.h"

#include "MyArgs.h"
#include <jdf/util/PlatformUtils.h>
#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMEMultiPart.h>


#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>
#include <map>

XERCES_CPP_NAMESPACE_USE

using namespace std;

//////////////////////////////////////////////////////////////////
namespace JDF{

	JDFParser* parser=0; // global reusable parser

/**
* document that is derived from JDFDoc and contains the example routines
	*/
	class  ExampleDoc :public JDFDoc{
	public:
		ExampleDoc(int docType):JDFDoc(docType){};
		ExampleDoc(const XMLDoc & d):JDFDoc(d){};
		~ExampleDoc(){};
		int DoExample(WString action, WString infile, WString outFile);
		bool bQuiet;

	protected:
		//  list of individual example routines
		int CreateRIP();
		int CreateSimple();
		int CreateBrochure();
		int ParseNodes();
		int DoRunList();
		int DoAudit();
		int DoValid();
		int DoAll();
		int CreateImposition();
		int CreateDigitalPrinting();
		int CreateConventionalPrinting();
		int CreatePartVersion();
		int DoAuditCP();
		int DoSpawnMergeCP();
		int Reprint();
		int StripPrivate();
		int SubContract();
		int CreateVersion();
		WString WriteMessage();
		int ProcessMessage(WString &messageString);
		int WriteSignal();
		int WriteSubmitQueueEntry();
		int UpdateVersion(JDFElement::EnumVersion ver);

	};
	
	
	/////////////////////////////////////////////////////////////////////////////
	/**
	* dispatcher to the individual example tasks
	* @param WString action the routine to call
	* @param WString infile name of the input JDF file to parse
	* @param WString outfile name of the output JDF file to write
	* @return >=0 if successful
	*/
	int ExampleDoc::DoExample(WString action,WString inFile,WString outFile){
		// parse the input, if it exists
		if(!inFile.empty()) {
			parser->Parse(inFile,false);
			*this=parser->GetRoot();
		}

		JDFElement root=GetRoot();
		
		// clean root if it was not parsed
		if(inFile.empty()) {
			if(root.IsJDFNode()){
				JDFNode JDFNode=GetRoot();
				JDFNode.init(true);
			}else if(root.GetLocalName()==L"JMF"){
				JDFJMF jmfRoot=GetRoot();
				jmfRoot.Flush();
				jmfRoot.init();
			}
		}
		
		int iReturn=-1;
//		try{
			// select subroutine depending on action
			if(action=="CreateSimple") {
				iReturn=CreateSimple();
			} else if(action=="CreateBrochure") {
				iReturn=CreateBrochure();
			} else if(action=="CreateRIP") {
				iReturn=CreateRIP();
			} else if(action=="Reprint") {
				iReturn=Reprint();
			} else if(action=="CreateDigitalPrinting") {
				iReturn=CreateDigitalPrinting();
			} else if(action=="CreateConventionalPrinting") {
				iReturn=CreateConventionalPrinting();
			} else if(action=="CreateImposition") {
				iReturn=CreateImposition();
			} else if(action=="ParseNodes") {
				iReturn=ParseNodes();
			} else if(action=="DoRunList") {
				iReturn=DoRunList();
			} else if(action=="DoAudit") {
				iReturn=DoAudit();
			} else if(action=="DoAuditCP") {
				iReturn=DoAuditCP();
			} else if(action=="DoSpawnMergeCP") {
				iReturn=DoSpawnMergeCP();
			} else if(action=="DoValid") {
				iReturn=DoValid();
			} else if(action=="StripPrivate") {
				iReturn=StripPrivate();
			} else if(action=="ProcessMessage") {
				iReturn=ProcessMessage(WriteMessage());
			} else if(action=="WriteSignal") {
				iReturn=WriteSignal();
			} else if(action=="WriteSubmitQueueEntryMessage") {
				iReturn=WriteSubmitQueueEntry();
			} else if(action=="SubContract") {
				iReturn=SubContract();
			} else if(action=="CreatePartVersion") {
				iReturn=CreatePartVersion();
			} else if(action=="UpdateVersion") {
				iReturn=UpdateVersion(JDFElement::Version_1_3);
			} else if(action=="DoAll") {
				iReturn=DoAll();
			} else {
				// oops we don't know this one
				cout << "ExampleDoc: unknown action "<<action<<endl;
				return -1;
			}
			
//		}catch (JDFException e){
//			cout <<"Caught a JDF exception :"<<e.getMessage()<<endl;			
//		}
		
		// write to output if requested
		if(!outFile.empty()){
			// remove whitespace only nodes before writing
			root.EraseEmptyNodes();
			// remove any existing output file prior to overwriting
			remove(outFile.peekBytes());			
			// write the output file
			Write2File(outFile.peekBytes());
		}
		else if(!bQuiet)
		{
			// no output file -> Send to console
			cout<<">>>>>>>>>>>>>>> output of "<<action<<endl<<endl;
	//		std::cout<<ToString();
		}
		return iReturn;
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	
	/** 
	* Example 0:
	* call all other examples
	*/
	int ExampleDoc::DoAll(){
		ExampleDoc doc1(0);
		doc1.DoExample("CreateSimple","","Simple.jdf");
		doc1.DoExample("CreateRIP","","RIP.jdf");
		doc1.DoExample("Reprint","RIP.jdf","Reprint.jdf");
		doc1.DoExample("CreateBrochure","","Brochure.jdf");
		doc1.DoExample("SubContract","Brochure.jdf","SubContract.jdf");
		doc1.DoExample("ParseNodes","Brochure.jdf","");
		doc1.DoExample("DoRunList","","RunList.jdf");
		doc1.DoExample("DoAudit","RunList.jdf","RunlistAudit.jdf");
		doc1.DoExample("DoValid","RunList.jdf","");
		doc1.DoExample("CreateImposition","","Impose.jdf");
		doc1.DoExample("CreateDigitalPrinting","","DigitalPrinting.jdf");
		doc1.DoExample("CreateConventionalPrinting","","ConventionalPrinting.jdf");
		doc1.DoExample("CreatePartVersion","","PartVersion.jdf");
		doc1.DoExample("DoAuditCP","ConventionalPrinting.jdf","ConventionalPrintingAudit.jdf");
		doc1.DoExample("DoSpawnMergeCP","","ConventionalPrintingSM.jdf");
		doc1.DoExample("StripPrivate","ConventionalPrinting.jdf","ConventionalPrintingStripped.jdf");
		ExampleDoc docJMF(1);
		docJMF.DoExample("ProcessMessage","","ProcessMessage.jdf");
		docJMF.DoExample("WriteSignal","","StatusSignal.jdf");
		docJMF.DoExample("WriteSubmitQueueEntryMessage","","");
		
		return 0;
	}
	// the actual examples start here
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 1:
	* create an incomplete product node for a simple 8.5 * 11 brochure
	* from scratch
	*/
	int ExampleDoc::CreateSimple(){
		
		// get the JDF document root element
		JDFNode productNode=GetRoot();
		productNode.init();
		productNode.SetEnumType(productNode.Type_Product);
		productNode.SetStatus(JDFNode::Status_Waiting);
		
		//Add an intent resource
		JDFLayoutIntent layoutIntent=productNode.AppendMatchingResource(JDFElement::elm_LayoutIntent,JDFNode::ProcessUsage_AnyInput);
				
		// set some span elements in the intent resource
		JDFIntegerSpan pages=layoutIntent.AppendPages();
		pages.SetPreferred(16);
		
		JDFShapeSpan dimensions=layoutIntent.AppendFinishedDimensions();
		dimensions.SetPreferred(8.5*72.,11.*72.,0);
		
		
		return 1; 
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 2:
	* create a brochure structure with cover and insert
	* from scratch
	*/
	
	int ExampleDoc::CreateBrochure(){
		// set up the root process
		JDFNode productNode=GetRoot();
		productNode.init();
		productNode.SetEnumType(JDFNode::Type_Product);
		productNode.SetStatus(JDFNode::Status_Waiting);
		
		productNode.SetJobPartID("Part1");
		// define the complete output component (false -> Usage=output
		JDFComponent compBrochure=productNode.AppendMatchingResource(JDFElement::elm_Component,productNode.ProcessUsage_AnyOutput);
		compBrochure.SetComponentType(JDFComponent::ComponentType_FinalProduct);
		compBrochure.SetDescriptiveName("complete 16-page Brochure");
		// set the amount of the output component
		compBrochure.SetAmount(10000);
		
		// you can now add all kinds of attributes to bindingIntent
		JDFBindingIntent bindingIntent=productNode.AppendMatchingResource(JDFElement::elm_BindingIntent,JDFNode::ProcessUsage_AnyInput);
		
		// add the component for the cover
		JDFNode prodCover=productNode.AddProduct();
		prodCover.SetDescriptiveName(L"Cover");
		prodCover.SetJobPartID("Part2");

		// Add a component for the cover that resides in the ResourceLinkPool of productNode
		JDFComponent compCover=prodCover.AppendMatchingResource(JDFElement::elm_Component,productNode.ProcessUsage_AnyOutput,productNode);
		compCover.SetDescriptiveName("Cover Component");
		compCover.SetComponentType(JDFComponent::ComponentType_PartialProduct);
		compCover.SetProductType("Cover");
		
		// Add an ArtDeliveryIntent to define the input files for the cover
		JDFArtDeliveryIntent artDeliveryIntent= prodCover.AppendMatchingResource(JDFElement::elm_ArtDeliveryIntent,productNode.ProcessUsage_AnyInput);
		JDFArtDelivery artDeliveryCover= artDeliveryIntent.AppendArtDelivery();
		artDeliveryCover.SetEnumArtDeliveryType(JDFArtDelivery::ArtDeliveryType_DigitalNetwork);
		JDFRunList runListCover=artDeliveryCover.AppendRunList();
		JDFFileSpec fileSpec=runListCover.AppendLayoutElement().AppendFileSpec();
		fileSpec.SetURL("File:./cover.pdf");
		fileSpec.SetApplication("Acrobat");
		
		// link the cover to the brochure node as input
		productNode.LinkMatchingResource(compCover,productNode.ProcessUsage_AnyInput);
		JDFLayoutIntent layoutIntent=prodCover.AppendMatchingResource(JDFElement::elm_LayoutIntent,productNode.ProcessUsage_AnyInput);
		layoutIntent.SetNumberUp(JDFXYPair(1,1));
		layoutIntent.SetSides(JDFLayoutIntent::Sides_OneSided);
		prodCover.AppendMatchingResource(JDFElement::elm_ColorIntent,productNode.ProcessUsage_AnyInput);
		
		// Add a component for the insert that resides in the ResourceLinkPool of productNode
		JDFNode prodInsert=productNode.AddProduct();		
		prodInsert.SetDescriptiveName("Insert");
		prodInsert.SetJobPartID("Part3");
		
		// link the insert to the brochure node as input
		JDFComponent compInsert=prodInsert.AppendMatchingResource(JDFElement::elm_Component,productNode.ProcessUsage_AnyOutput,productNode);
		compInsert.SetDescriptiveName("Insert Component");
		compInsert.SetComponentType(JDFComponent::ComponentType_PartialProduct);
		compInsert.SetProductType("Body");

		productNode.LinkMatchingResource(compInsert,productNode.ProcessUsage_AnyInput);
		
		// add some intent resources to be filled in later
		JDFLayoutIntent insertLayoutIntent=prodInsert.AppendMatchingResource(JDFElement::elm_LayoutIntent,productNode.ProcessUsage_AnyInput);
		insertLayoutIntent.SetNumberUp(JDFXYPair(1,1));
		insertLayoutIntent.SetSides(JDFLayoutIntent::Sides_TwoSidedHeadToHead);
		JDFColorIntent insertColorIntent = prodInsert.AppendMatchingResource(JDFElement::elm_ColorIntent,productNode.ProcessUsage_AnyInput);
		
		// Add an ArtDeliveryIntent to define the input files for the inser
		artDeliveryIntent= prodInsert.AppendMatchingResource(JDFElement::elm_ArtDeliveryIntent,productNode.ProcessUsage_AnyInput);
		JDFArtDelivery artDeliveryInsert= artDeliveryIntent.AppendArtDelivery();
		artDeliveryInsert.SetArtDeliveryType(JDFArtDelivery::ArtDeliveryType_DigitalNetwork);
		JDFRunList runListInsert=artDeliveryInsert.AppendRunList();
		JDFFileSpec insertFileSpec=runListInsert.AppendLayoutElement().AppendFileSpec();
		insertFileSpec.SetURL("File:./insert.pdf");
		insertFileSpec.SetApplication("Acrobat");
		
		return 0;
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 3:
	* parse a JDF or PrintTalk and print the node type + ID
	*
	*/
	
	int ExampleDoc::ParseNodes(){
		// set up the root process
		JDFNode root=GetJDFRoot();
		// get a vector of all JDF nodes
		vJDFNode vNode=root.GetvJDFNode();
		// print summary
		cout<<"ParseNodes found "<<vNode.size()<<" Nodes"<<endl;
		// loop over all nodes and print
		for(int i=0;i<vNode.size();i++){
			JDFNode node=vNode[i];
			cout <<"JFD Node type: "<<node.GetType()<<" ID:"<<node.GetID()<<endl;
		}

// generate a map of nodename vs. occurences
		typedef map<WString,int> intMap;
		intMap mapNames;
		intMap mapSizes;
		intMap mapAttSizes;
		intMap mapAttNames;
		vElement allElements=root.GetChildrenByTagName(WString::star,WString::star,MapWString::emptyMap,false);
		allElements.push_back(root);
		vElement zappElems;
		cout<<"parseNodes: # of elements:"<<allElements.size()<<endl<<endl<<endl;

		// loop over all elements
		for(int j=0;j<allElements.size();j++){
			if((j%1000)==999)
				cout<<".";
			if((j%50000)==49999)
				cout<<endl;

			WString name=allElements[j].GetNodeName();
			intMap::iterator it=mapNames.find(name);
			intMap::iterator its=mapSizes.find(name);
			if(it!=mapNames.end()){
				(*it).second++; // increment existing entry
			}else{
				mapNames.insert(intMap::value_type(name,1)); // insert new entry with 1 occurrence (this one)
				mapSizes.insert(intMap::value_type(name,0)); // insert new entry with 1 occurrence (this one)
				its=mapSizes.find(name);
			}

			WString bigString=allElements[j].ToString();
			if(allElements[j].GetNodeName()!=allElements[j].GetParentNode().GetNodeName()){
				its->second+=bigString.size();
			}
			mAttribute attMap=allElements[j].GetAttributeMap();
			for(mAttribute::iterator i2=attMap.begin();i2!=attMap.end();i2++)
			{
				WString attPath=allElements[j].GetNodeName()+WString(L"/@")+WString(i2->first());
				intMap::iterator its=mapAttSizes.find(attPath);
				intMap::iterator itn=mapAttNames.find(attPath);
				if(its==mapAttSizes.end()){
					mapAttSizes.insert(intMap::value_type(attPath,0)); // insert new entry with 1 occurrence (this one)
					mapAttNames.insert(intMap::value_type(attPath,0)); // insert new entry with 1 occurrence (this one)
					its=mapAttSizes.find(attPath);
					itn=mapAttNames.find(attPath);
				}
				(*its).second+=4+i2->first().length()+i2->second().length();
				(*itn).second++;
			}

//			if(WString("ColorPool Spawned Merged HDM:FilePage RunList Notification Comment PartStatus ProcessRun").HasToken(name)){
			if(0){
				if(name!="RunList"||allElements[j].GetParentNode().GetNodeName()!="RunList"){
					zappElems.push_back(allElements[j]);
				}
			}
		}
		cout<<endl;
		int s=mapNames.size();
		
		int ipos=42; // for formatting

		// map has no sort - let's just use brute force...
		for(int k=0;k<s;k++){
			intMap::iterator it1;
			int n=0;
			for(intMap::iterator it=mapSizes.begin();it!=mapSizes.end();it++){
				// highest # of occurence
				if((*it).second>n){
					it1=it;
					n=(*it).second;
				}
			};
			// beautify the output
			if(k==10)
				ipos--;
			if(k==100)
				ipos--;
			if(k==1000)
				ipos--;

			intMap::iterator its=mapNames.find(it1->first);
			cout<<k<<" "<<
				WString((*it1).first+L"                                               ").leftStr(ipos)<<
				(*it1).second<<" "<<its->second<<endl;
			mapSizes.erase(it1);
		}

				cout<<endl;
		s=mapAttSizes.size();
		
		ipos=42; // for formatting

		// map has no sort - let's just use brute force...
		for(int k=0;k<s;k++){
			intMap::iterator it1;
			int n=0;
			for(intMap::iterator it=mapAttSizes.begin();it!=mapAttSizes.end();it++){
				// highest # of occurence
				if((*it).second>n){
					it1=it;
					n=(*it).second;
				}
			};
			// beautify the output
			if(k==10)
				ipos--;
			if(k==100)
				ipos--;
			if(k==1000)
				ipos--;

			intMap::iterator its=mapAttNames.find(it1->first);
				cout<<k<<" "<<
				WString(it1->first+L"                                               ").leftStr(ipos)<<
				it1->second<<" "<<its->second<<endl;
			mapAttSizes.erase(it1);
		}

		for(int jj=0;jj<zappElems.size();jj++){
			zappElems[jj].DeleteNode();
		}

		
		cout<<"end ParseNodes"<<endl;
		return 0;
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/**
	* Example 4:
	* create an  Imposition process node with a runlist
	* the Runlist has various separated, combined and referenced files
	*/
	
	int ExampleDoc::DoRunList(){
		// set up the root process node, which is an imposition node
		JDFNode impositionNode=GetJDFRoot();
		impositionNode.init();
		impositionNode.SetEnumType(JDFNode::Type_Imposition);
		impositionNode.SetStatus(JDFNode::Status_Waiting);
		// add the runlist
		JDFRunList runList=impositionNode.AppendMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_Document);
		//set Npage to 10
		runList.SetNPage(10);
		// separation names
		WString separationList="Cyan Magenta Yellow Black SpotGreen";
		// runPart is used to reference the partitioned runlist leaves
		JDFRunList runPart=runList.AddSepRun("Cyan.pdf Magenta.pdf Yellow.pdf Black.pdf Green.pdf",separationList,0,1,true," ");
		// add a JDF Comment
		runPart.InsertAt("Comment",0).AppendText("Preseparated Runs in multiple files\nAll LayoutElements are inline resources");
		
		// add a LayoutElement that will be referenced from the RunList
		// TBD this still has to be made typesafe
		JDFLayoutElement layoutelem=impositionNode.AddParameter("LayoutElement",true,impositionNode,false);
		JDFFileSpec fileSpec=layoutelem.AppendFileSpec();
		fileSpec.SetURL("PreSepCMYKG.pdf");
		// add a preseparated run
		runPart=runList.AddSepRun(layoutelem,separationList,0,2,true," ");
		runPart.InsertAt("Comment",0).AppendText("Preseparated Runs in one file CMYKGCMYKG\nLayoutElements are inter-resource links");
		
		// add a preseparated run
		runPart=runList.AddSepRun(layoutelem,"Cyan Yellow Black Green",10,1,true," ");
		runPart.InsertAt("Comment",0).AppendText("No Magenta, the missing sep does not exist as a page");
		
		// add a preseparated run
		runPart=runList.AddSepRun(layoutelem,separationList,14,2,true," ");
		runPart.InsertAt("Comment",0).AppendText("Continuation of Preseparated Runs in one file CMYKGCMYKG - the missing sep of the previous page does not exist as a page");
		
		
		layoutelem=impositionNode.AddParameter("LayoutElement",true,impositionNode,false);
		fileSpec=layoutelem.GetCreateFileSpec();	
		fileSpec.SetURL("PreSepCCMMYYKKGG.pdf");

		// add a preseparated run
		runPart=runList.AddSepRun(layoutelem,separationList,0,2,false," ");
		runPart.InsertAt("Comment",0).AppendText("Preseparated Runs in one file CCMMYYKKGG");
		
		runPart=runList.AddRun("Combined.pdf",0,1);
		runPart.InsertAt("Comment",0).AppendText("Combined Runs in one file ");
		return 0;
		
	}
	
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 5:
	* parse a JDF and simulate processing it
	* also add some audit elements
	*
	*/
	
	int ExampleDoc::DoAudit(){
		// set up the root process
		JDFNode root=GetJDFRoot();
		// get the node audit pool
		JDFAuditPool auditPool=root.GetCreateAuditPool();
		/// do something between these calls
		auditPool.SetPhase(root.Status_Setup);
		auditPool.SetPhase(root.Status_InProgress);
		auditPool.SetPhase(root.Status_Cleanup);
		// get the input runlist
		JDFRunList rl=root.GetResourceLinkPool().GetInOutLinks(true,false,"RunList")[0];
		// pretend that cleanup modifies a resource and create a ResourceAudit
		JDFResourceAudit resourceAudit=	auditPool.AddResourceAudit();
		resourceAudit.AddNewLink(rl,true);
		resourceAudit.SetContentsModified(true);
		auditPool.SetPhase(root.Status_Completed);
		/// fill the processrun
		auditPool.AddProcessRun(root.Status_Completed);
		
		return 0;
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 6:
	* parse a JDF and validate the runlist
	*
	*/
	
	int ExampleDoc::DoValid(){
		cout<<"start DoValid"<<endl;
		// set up the root process
		JDFNode root=GetJDFRoot();
		// get the input runlist
		JDFRunList rl=root.GetResourceLinkPool().GetInOutLinks(true,false,"RunList")[0];
		//is the Runlist Valid?
		bool bValid=rl.IsValid(rl.ValidationLevel_Complete);
		// print out validity information
		cout << "DoValid runlist is "<<WString(bValid?"":"in")<<"valid !"<<endl;
		// cross check with an artificially invalidated runlist
		rl.SetAttribute("InvalidAttribute","Something really Invalid");
		// recheck
		bValid=rl.IsValid(rl.ValidationLevel_Complete);
		// print out new validity information
		cout << "DoValid runlist is "<<WString(bValid?"":"in")<<"valid !"<<endl;
		cout <<"the following attributes are inValid: "<<endl;
		// get the vector of invalid attributes
		vWString vInvalidAttributes=rl.GetInvalidAttributes();
		// print out the details
		for(int i=0;i<vInvalidAttributes.size();i++)
			cout<<"key: "<<vInvalidAttributes[i]<<" value: "<<rl.GetAttribute(vInvalidAttributes[i])<<endl;
		cout<<"end DoValid"<<endl;
		return 0;
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 7:create an imposition node from from scratch
	*/
	
	int ExampleDoc::CreateImposition(){
		// set up the root process node, which is an imposition node
		JDFNode impositionNode=GetJDFRoot();
		impositionNode.init();
		impositionNode.SetEnumType(JDFNode::Type_Imposition);
		impositionNode.SetStatus(JDFNode::Status_Waiting);
		
		// add the appropriate resources
		JDFLayout layout=impositionNode.AppendMatchingResource(JDFElement::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		JDFSignature signature=layout.AppendSignature();
		JDFSheet sheet=signature.AppendSheet();
		// set the surfac contents box
		sheet.SetSurfaceContentsBox((WString)"0.0 0.0 1842.5197 1417.322800");
		// Add the front Surface
		JDFSurface surface=sheet.AppendFrontSurface();
		
		// append a markobject and set some default values
		JDFMarkObject markObject=surface.AppendMarkObject();
		markObject.SetCTM(JDFMatrix("1 0 0 1 0 0"));
		markObject.SetOrd(0);
		markObject.init();
		
		// append a contentobject
		JDFContentObject contentObject=surface.AppendContentObject();
		contentObject.SetCTM(JDFMatrix("1 0 0 1 0 0"));
		contentObject.SetOrd(0);
		contentObject.init();
		
		
		// add the document runlist
		JDFRunList docList=impositionNode.AppendMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_Document);
		JDFRunList run=docList.AddRun("Document1.pdf");
		
		run=docList.AddRun("Document2.pdf");
		
		// separation names
		WString separationList="Cyan Magenta Yellow Black";
		// runPart is used to reference the partitioned runlist leaves
		JDFRunList runPart=docList.AddSepRun("Cyan.pdf Magenta.pdf Yellow.pdf Black.pdf",separationList,0,1,true," ");
		
		
		// add the marks runlist
		JDFRunList markList=impositionNode.AppendMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_Marks);
		//Append a LayoutElement to the marks runlist
		JDFLayoutElement markle=markList.AppendLayoutElement();
		//Append a FileSpec to the marks LayoutElement
		JDFFileSpec markfilespec=markle.AppendFileSpec();
		// set some parameters
		markfilespec.SetURL("marks.pdf");
		
		// add the output runlist
		JDFRunList outList=impositionNode.AppendMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_AnyOutput);
		//Append a LayoutElement to the output runlist
		JDFLayoutElement outle=outList.AppendLayoutElement();
		//Append a FileSpec to the output LayoutElement
		JDFFileSpec outfilespec=outle.AppendFileSpec();
		// set some parameters
		outfilespec.SetURL("output.pdf");
		
		// append an empty generic ApprovalSuccess
		JDFApprovalSuccess approvalSuccess=impositionNode.AppendMatchingResource(JDFElement::elm_ApprovalSuccess,JDFNode::ProcessUsage_AnyInput);
		
		return 0;
		
	}
	
	/** 
	* Example 7.5:
	* create an combined RIP node for 
	* from scratch
	*/
	int ExampleDoc::CreateRIP(){
		
		// get the JDF document root element
		JDFNode ripNode=GetRoot();
		ripNode.init();
		ripNode.SetTypes(vWString(L"Interpreting Rendering ImageSetting"));
		ripNode.SetEnumType(JDFNode::Type_Combined);
		ripNode.SetStatus(JDFNode::Status_Waiting);
		
		// now append the various resources
		// cast to the individual node types and append the appropriate resources
		JDFInterpretingParams interpretingParams=ripNode.AppendMatchingResource(JDFElement::elm_InterpretingParams,JDFNode::ProcessUsage_AnyInput);
		JDFRunList inRunList=ripNode.AppendMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_AnyInput);
		inRunList.AddRun(L"File:///File1.pdf",0,1);
		inRunList.AddRun(L"File:///File2.pdf",0,1);
		
		JDFColorantControl colorantControl=ripNode.AppendMatchingResource(JDFElement::elm_ColorantControl,JDFNode::ProcessUsage_AnyInput);
		colorantControl.SetProcessColorModel("DeviceCMYK");
		
		JDFRenderingParams renderingParams=ripNode.AppendMatchingResource(JDFElement::elm_RenderingParams,JDFNode::ProcessUsage_AnyInput);
		
		JDFImageSetterParams imageSetterParams=ripNode.AppendMatchingResource(JDFElement::elm_ImageSetterParams,JDFNode::ProcessUsage_AnyInput);
		
		// set up the media
		JDFMedia media=ripNode.AppendMatchingResource(JDFElement::elm_Media,JDFNode::ProcessUsage_AnyInput);
		media.SetStatus(media.Status_Available);
		JDFResourceLink mediaLink=ripNode.GetLink(media,true);
		mediaLink.SetAmount(4*4); // 4 seps * 8 pages
		
		// set up the expose output media
		JDFExposedMedia exposedMedia=ripNode.AppendMatchingResource(JDFElement::elm_ExposedMedia,JDFNode::ProcessUsage_AnyOutput);
		media=ripNode.AddConsumable(JDFElement::elm_Media,true,ripNode,false);
		// set up one partition / page
		vResource vExposedMediaPages=exposedMedia.AddPartitions(exposedMedia.PartIDKey_RunIndex,vWString(L"0 1 2 3"));
		vResource vMediaPages=media.AddPartitions(media.PartIDKey_RunIndex,vWString(L"0 1 2 3"));
		for(int iPage=0;iPage<vExposedMediaPages.size();iPage++){
			// now 4 separations per page
			JDFExposedMedia exposedMediaPage=vExposedMediaPages[iPage];
			JDFMedia mediaPage=vMediaPages[iPage];
			exposedMediaPage.RefElement(mediaPage);
			exposedMediaPage.AddPartitions(exposedMedia.PartIDKey_Separation,vWString(L"Cyan Magenta Yellow Black"));
			
		}
		
		
		
		return 1; 
	}
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 7.7:
	* modify a combined RIP node for reprint of one plate
	* from scratch
	*/
	int ExampleDoc::Reprint(){
		
		// get the JDF document root element
		JDFNode ripNode=GetRoot();
		
		JDFResourceLink inRunListLink=ripNode.GetMatchingLink(JDFElement::elm_RunList,JDFNode::ProcessUsage_AnyInput);
		
		JDFResource rr=ripNode.GetMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_AnyInput);;
//		int i;
//		cout<<inRunListLink.GetTarget();
//		for(i=0;i<inRunListLink.GetTargetVector().size();i++)
//			cout<<endl<<i<<endl<<inRunListLink.GetTargetVector()[i]<<endl;
		
		// set up the input resource link for the run list
		mAttribute partMap;
		partMap.AddPair(JDFElement::atr_Run,"Run0012");
		partMap.AddPair(JDFElement::atr_RunIndex,"3");
		partMap.AddPair(JDFElement::atr_Separation,"Cyan");
		inRunListLink.SetPartMap(partMap);
//		cout<<inRunListLink.GetTarget();
//		for(i=0;i<inRunListLink.GetTargetVector().size();i++)
//			cout<<endl<<i<<endl<<inRunListLink.GetTargetVector()[i]<<endl;
		
		rr.SetPartUsage(rr.PartUsage_Implicit);
		
//		cout<<inRunListLink.GetTarget();
//		for(i=0;i<inRunListLink.GetTargetVector().size();i++)
//			cout<<endl<<i<<endl<<inRunListLink.GetTargetVector()[i]<<endl;
		cout<<ripNode;

		JDFResourceLink exposedMediaLink=ripNode.GetMatchingLink(JDFElement::elm_ExposedMedia,JDFNode::ProcessUsage_AnyOutput);
		exposedMediaLink.SetPartMap(partMap);
		
		partMap.clear();
		partMap.AddPair(JDFElement::atr_Separation,"Cyan");
		
		JDFResourceLink colorantControlLink=ripNode.GetMatchingLink(JDFElement::elm_ColorantControl,JDFNode::ProcessUsage_AnyInput);
		colorantControlLink.SetPartMap(partMap);
		return 1; 
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 8:write a JMF message from scratch and fill it with various signals, queries and commands
	* return the message as a WString
	* this simulates the JMF post input within an http server
	*/
	
	WString ExampleDoc::WriteMessage(){
		// set up the root process
		JDFJMF jmf=GetRoot(); 
		jmf.init();
		jmf.SetSenderID("MessageSender");
		// append a generic query to root and cast to its type
		JDFQuery queryKnownDevices=jmf.AppendQuery(JDFQuery::Type_KnownDevices);
		JDFDeviceFilter deviceFilter=queryKnownDevices.AppendDeviceFilter();
		JDFDevice device=deviceFilter.AppendDevice();
		device.SetDeviceID("DeviceID1");
		
		// serialize this document to a WString
		WString outString;
		Write2String(outString);
		return outString;
		
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 9:read the JMF message from example 8 and create the appropriate responses and acknowledges
	*/
	
	int ExampleDoc::ProcessMessage(WString & inputMessage){
		// parse the message into a document
		parser->StringParse(inputMessage,false);
		
		// set up the root process
		ExampleDoc inMessageDoc(parser->GetRoot());

		// get the input document root element
		JDFJMF jmfIn=inMessageDoc.GetRoot();
		// get the output document root element
		JDFJMF jmfOut=GetRoot();
		// get all queries as a vector of elements
		vElement vMessages=jmfIn.GetMessageVector(JDFMessage::Family_Query);
		// loop over all queries
		for(int i=0;i<vMessages.size();i++){
			
			JDFQuery query=vMessages[i];
			// append a response to this docoment
			JDFResponse response=jmfOut.AppendResponse(JDFMessage::Type_Unknown);
			// set the appropriate query information to the response
			response.SetQuery(query);
			WString typ=query.GetType();
			// fill in the response according to query type. -> example only
			if(typ=="KnownDevices"){
				// read in the data of the query
				JDFDeviceFilter deviceFilter=query.GetDeviceFilter();
				JDFDevice deviceIn=deviceFilter.GetDevice();
				
				// modify the response
				JDFDeviceList deviceListOut=response.AppendDeviceList();
				JDFDeviceInfo deviceInfo=deviceListOut.AppendDeviceInfo();
				JDFDevice deviceOut=deviceInfo.AppendDevice();
				deviceOut.SetDeviceID(deviceIn.GetDeviceID());
				deviceOut.SetDeviceType("Coffee Machine");
				JDFCostCenter cs=deviceOut.AppendCostCenter();
				cs.SetCostCenterID("1234");
				cs.SetName("Java Bean Cost Center");
				// ...
			}else{
				// query not implemented!
				response.SetAttribute("ReturnCode",5);
				JDFNotification note=response.AppendNotification();
				note.SetClass(note.Class_Error);
				response.SetReturnCode(5);
			}
		}
		WString outString;
		Write2String(outString);
		cout<< outString;
		return 0;
		
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 10:create a DigitalPrinting node from from scratch
	*/
	
	int ExampleDoc::CreateDigitalPrinting(){
		// set up the root process node, which is an imposition node
		JDFNode printNode=GetJDFRoot();
		printNode.init();
		printNode.SetEnumType(JDFNode::Type_DigitalPrinting);
		printNode.SetStatus(JDFNode::Status_Waiting);
		// add the appropriate resources
		JDFMedia media=printNode.AppendMatchingResource(JDFElement::elm_Media,JDFNode::ProcessUsage_AnyInput);
		// partition for Runindex=cover and RunIndex=insert
		media.AddPartitions(JDFResource::PartIDKey_RunIndex,WString(L"0 -1,1~-2").Tokenize(L","));
		JDFResourceLink mediaLink=printNode.GetMatchingLink(JDFElement::elm_Media,JDFNode::ProcessUsage_AnyInput);
		JDFAmountPool aPool=mediaLink.AppendAmountPool();
		mAttribute mapParts;
		mapParts.AddPair(JDFResource::PartIDKeyString(JDFResource::PartIDKey_RunIndex),"0 -1");
		JDFPartAmount partAmount=aPool.AppendPartAmount(mapParts);
		partAmount.SetOrientation(JDFResourceLink::Orientation_Flip180);
		mapParts.clear();
		mapParts.AddPair(JDFResource::PartIDKeyString(JDFResource::PartIDKey_RunIndex),"1~-2");
		partAmount=aPool.AppendPartAmount(mapParts);
		partAmount.SetOrientation(JDFResourceLink::Orientation_Rotate0);
		
		// get the MediaLink and set the attributes
		
		JDFDigitalPrintingParams dpp=printNode.AppendMatchingResource(JDFElement::elm_DigitalPrintingParams,JDFNode::ProcessUsage_AnyInput);
		dpp.AddPartitions(JDFResource::PartIDKey_RunIndex,WString(L"0 -1,1~-2").Tokenize(L","));
		JDFDigitalPrintingParams dppLeaf=dpp.GetPartition(JDFResource::PartIDKey_RunIndex,"0 -1");
		dppLeaf.RefElement(media.GetPartition(JDFResource::PartIDKey_RunIndex,"0 -1"));
		dppLeaf=dpp.GetPartition(JDFResource::PartIDKey_RunIndex,"1~-2");
		dppLeaf.RefElement(media.GetPartition(JDFResource::PartIDKey_RunIndex,"1~-2"));
		
		// add the input runlist
		JDFRunList runList=printNode.AppendMatchingResource(JDFElement::elm_RunList,JDFNode::ProcessUsage_AnyInput);
		JDFRunList rlRun=runList.AddRun("File:///File1.pdf",0,5);
		rlRun.AddPartitions(JDFResource::PartIDKey_RunPage,vWString(L"0 1 2 3 4"));
		rlRun=runList.AddRun("File:///File2.pdf",0,7);
		rlRun.AddPartitions(JDFResource::PartIDKey_RunPage,vWString(L"0 1 2 3 4 5 6"));
		
		return 0;
		
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 10:create a ConventionalPrinting node from from scratch
	*/
	
	int ExampleDoc::CreateConventionalPrinting(){
		// set up the root process node, which is an imposition node
		JDFNode printNode=GetJDFRoot();
		printNode.init();
		printNode.SetEnumType(JDFNode::Type_ConventionalPrinting);
		printNode.SetStatus(JDFNode::Status_Waiting);
		printNode.SetJobID("PrintTest");
		printNode.SetJobPartID("1");

		
		// add the appropriate resources
		JDFMedia media=printNode.AppendMatchingResource(JDFElement::elm_Media,JDFNode::ProcessUsage_AnyInput);

		JDFExposedMedia exposedMedia=printNode.AppendMatchingResource(JDFElement::elm_ExposedMedia,printNode.ProcessUsage_Plate);

		JDFInk ink=printNode.AppendMatchingResource(JDFElement::elm_Ink,printNode.ProcessUsage_AnyInput);
		JDFConventionalPrintingParams cpp=printNode.AppendMatchingResource(JDFElement::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_AnyInput);
		JDFComponent component=printNode.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		
		// Set up partitioning
		vWString sheetNames=WString(L"Sheet1 Sheet2 Sheet3").Tokenize();
		vWString separations=WString(L"Cyan Magenta Yellow Black").Tokenize();
		vWString sides=WString(L"Front Back").Tokenize();
		
		ink.AddPartitions(JDFResource::PartIDKey_Separation,separations);
		vResource vExposedMedia=exposedMedia.AddPartitions(exposedMedia.PartIDKey_SheetName,sheetNames);
		vResource vComponent=component.AddPartitions(exposedMedia.PartIDKey_SheetName,sheetNames);
		
		// get the link to the output component
		JDFResourceLink componentLink=printNode.GetLink(component,false);

		// do lower level partitioning
		for(int iPage=0;iPage<vExposedMedia.size();iPage++){
			mAttribute nameMap;
			nameMap.AddPair(L"SheetName",sheetNames[iPage]);

			JDFExposedMedia mp=vExposedMedia[iPage];
			vResource vSide=mp.AddPartitions(exposedMedia.PartIDKey_Side,sides);
			
			for(int iSide=0;iSide<vSide.size();iSide++){
				JDFExposedMedia msep=vSide[iSide];
				vResource vSep=msep.AddPartitions(exposedMedia.PartIDKey_Separation,separations);			
			}

			JDFComponent c=vComponent[iPage];
			componentLink.SetAmount(12345,nameMap);
		}
		return 0;
		
	}
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 10.a:add versions to a ConventionalPrinting node 
	*/
	
	int ExampleDoc::CreatePartVersion(){
		int iRet=CreateConventionalPrinting();
		int i;
		JDFNode root=GetJDFRoot();
		JDFExposedMedia xm=root.GetMatchingResource(JDFElement::elm_ExposedMedia);
		JDFComponent comp=root.GetMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		mAttribute partMap;
		partMap.AddPair(JDFExposedMedia::atr_SheetName,L"Sheet1");

		vElement vxmPart=xm.GetPartitionVector(partMap,JDFResource::PartUsage_Explicit);
		vElement vxmPartAll;
		vElement vcompPart=comp.GetPartitionVector(partMap,JDFResource::PartUsage_Explicit);
		vElement vcompPartAll;
		for(i=0;i<vxmPart.size();i++){
			JDFExposedMedia xmp=vxmPart[i];
			vxmPartAll.AppendUnique(xmp.GetLeaves());
			JDFComponent compp=vcompPart[i];
			vcompPartAll.AppendUnique(compp.GetLeaves());
		}
		for(i=0;i<vxmPartAll.size();i++){
			JDFExposedMedia xmp=vxmPartAll[i];
			xmp.AddPartition(JDFResource::PartIDKey_PartVersion,L"German");
			xmp.AddPartition(JDFResource::PartIDKey_PartVersion,L"English");
			xmp.AddPartition(JDFResource::PartIDKey_PartVersion,L"French");
		}
		for(i=0;i<vcompPartAll.size();i++){
			JDFComponent compp=vcompPartAll[i];
			compp.AddPartition(JDFResource::PartIDKey_PartVersion,L"German");
			compp.AddPartition(JDFResource::PartIDKey_PartVersion,L"English");
			compp.AddPartition(JDFResource::PartIDKey_PartVersion,L"French");
		}
	
		return iRet;
	}	
	
	/////////////////////////////////////////////////////////////////////////////

	int ExampleDoc::DoAuditCP(){
		// set up the root process
		JDFNode root=GetJDFRoot();
		JDFEmployee printer1=root.AppendMatchingResource(JDFElement::elm_Employee,JDFNode::ProcessUsage_AnyInput);
		printer1.SetPersonalID(L"007");
		JDFPerson person=printer1.AppendPerson();
		person.SetFamilyName(L"Bond");
		person.SetFirstName(L"James");
		person.SetJobTitle(L"Senior Printer");
		
		JDFEmployee printer2=root.AppendMatchingResource(JDFElement::elm_Employee,JDFNode::ProcessUsage_AnyInput);
		printer2.SetPersonalID(L"009");
		person=printer2.AppendPerson();
		person.SetFamilyName(L"Stift");
		person.SetFirstName(L"John");
		person.SetJobTitle(L"Junior Printer");
		
		// get the node audit pool
		JDFAuditPool auditPool=root.GetCreateAuditPool();
		/// do something between these calls
		JDFPhaseTime phaseTime=auditPool.SetPhase(root.Status_Setup);
		phaseTime.SetStatusDetails("GeneralSetup");
		phaseTime.RefElement(printer1);
		
		
		auditPool.SetPhase(root.Status_InProgress);
		auditPool.SetPhase(root.Status_Cleanup);
		auditPool.SetPhase(root.Status_Completed);
		/// fill the processrun
		auditPool.AddProcessRun(root.Status_Completed);
		
		return 0;
	}
	/////////////////////////////////////////////////////////////////////////////
	int ExampleDoc::DoSpawnMergeCP(){
		int iRet=CreateConventionalPrinting();
		Write2File("CP1.jdf");
		// set up the root process
		JDFNode root=GetJDFRoot();
				
		vKString vRWRes=WString("Output").Tokenize(L",");
		
		for(int ii=1;ii<11;ii++){
			cout<<"Spawn + Merge Test # "<<ii<<endl;
		for(int i=1;i<4;i++){
			vmAttribute vMap;
			mAttribute m;
			m.AddPair(root.atr_SheetName,WString("Sheet")+i);
			vMap.push_back(m);
			JDFDoc docSpawn = root.Spawn("Job.jdf", "Spawn.jdf", vRWRes, vMap ,false,true,true);

			// this is the part that an external processor, i.e. the press would be doing
			JDFNode spawnRoot=docSpawn.GetJDFRoot();
			spawnRoot.SetStatus(JDFNode::Status_Completed);
			JDFComponent r=spawnRoot.GetMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput);
			r.SetStatus(r.Status_Available);
			// get the node audit pool
			JDFAuditPool auditPool=spawnRoot.GetCreateAuditPool();
			/// do something between these calls
			JDFPhaseTime phaseTime=auditPool.SetPhase(root.Status_Setup,"Print Emulater",vMap);
			phaseTime.SetStatusDetails("GeneralSetup");	
			
			auditPool.SetPhase(root.Status_InProgress,"Print Emulater",vMap);
			auditPool.SetPhase(root.Status_Cleanup,"Print Emulater",vMap);
			auditPool.SetPhase(root.Status_Completed,"Print Emulater",vMap);
			/// fill the processrun
			auditPool.AddProcessRun(root.Status_Completed,"Print Emulater",vMap);
			
			
			docSpawn.Write2File("Spawn.jdf");
			root.MergeJDF(spawnRoot,"Spawn.jdf",(JDFNode::EnumCleanUpMerge)1,(JDFResource::EnumAmountMerge)2);
		}
		}
		return iRet;
	}

	
	/////////////////////////////////////////////////////////////////////////////

	int ExampleDoc::StripPrivate(){
		// set up the root process
		JDFNode root=GetJDFRoot();
		// get all children including grand, grandgrand etc.
		vElement vElms=root.GetChildrenByTagName(L"*", L"", mAttribute(),false);

		// loop over all children
		for(int i=0;i<vElms.size();i++){
			JDFElement jdfElm=vElms[i];
			// if the element is in the namespace, remove all private attributes
			if(jdfElm.IsInJDFNameSpace()){
				vWString attributes=jdfElm.GetAttributeVector();
				// loop over all attributes and zapp the privates
				for(int j=0;j<attributes.size();j++){
					WString nsPrefix=KElement::XMLNameSpace(attributes[j]);
					if(!nsPrefix.empty()&&nsPrefix.toUpperCase()!=L"JDF"){
						jdfElm.RemoveAttribute(attributes[j]);
					}
				}
			}else{
				jdfElm.DeleteNode();
			}
		}

		return 0;
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example :write a JMF Signal message from scratch and fill it with various stutus information
	* return the message as a WString
	* this simulates the JMF post input within an http server
	*/
	
	int ExampleDoc::WriteSignal(){
		// set up the root process
		JDFJMF jmf=GetRoot(); 
		jmf.init();
		jmf.SetSenderID("MessageSenderDevice");
		// append a generic query to root and cast to its type
		JDFSignal signalStatus=jmf.AppendSignal(JDFSignal::Type_Status);
		JDFDeviceInfo deviceInfo=signalStatus.AppendDeviceInfo();
		deviceInfo.SetDeviceStatus(JDFDeviceInfo::DeviceStatus_Running);
		JDFJobPhase phase=deviceInfo.AppendJobPhase();
		phase.SetJobID("Job 1");
		phase.SetJobPartID("PressRun");
		phase.SetAmount(4242);
		mAttribute mapPart;
		mapPart.AddPair(JDFElement::atr_SheetName,"Sheet 7");
		phase.SetPartMap(mapPart);
		phase.SetStatus(JDFNode::Status_InProgress);
		JDFNotification notification=signalStatus.AppendNotification();
		notification.SetClass(JDFNotification::Class_Event);
		notification.SetType("Event");
		JDFElement event =notification.AppendElement("Event");
		event.SetDescriptiveName("Status description of this phase");
		event.SetAttribute("EventID","4711");
		return 0;		
		
	}
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example :write a Mime JMF File with a submitqueueentry and attached pdf files
	*/
	
	int ExampleDoc::WriteSubmitQueueEntry(){

		JDFJMF jmf=GetRoot(); 
		jmf.init();
		jmf.SetSenderID("MessageSenderDevice");
		// append a generic query to root and cast to its type
		JDFCommand commandSQE=jmf.AppendCommand(JDFCommand::Type_SubmitQueueEntry);
		JDFQueueSubmissionParams qsp=commandSQE.AppendQueueSubmissionParams();
		qsp.SetURL(L"cid:internalJDF.jdf");
		MIMEMessage* mm=CreateMIMEMessage();

		MIMEMultiPart*mmp=(MIMEMultiPart*)mm->getBody(false);
		
		// add a jdf
		ExampleDoc docJDF(0);
		docJDF.CreateRIP(); // just to have a rip node
		JDFNode n=docJDF.GetJDFRoot();
		JDFRunList rl=n.GetMatchingResource(JDFElement::elm_RunList);
		vResource vr=rl.GetLeaves();

		// fix the URLs to cid
		int i;
		vWString vPDFFiles;
		for(i=0;i<vr.size();i++){
			JDFRunList rl=vr[i];
			WString pdfFile=rl.GetFileURL();
			rl.SetFileURL(L"cid:internalPDF"+WString(i));
			vPDFFiles.push_back(pdfFile);
		}

		// append the JDF
		MIMEBasicPart *mbp = docJDF.CreateMIMEBasicPart();
		mbp->setContentID(L"cid:internalJDF.jdf");
		mmp->addBodyPart(mbp,false);

		// append the pdf files to the mime
		for(i=0;i<vr.size();i++){
			WString pdfFile=vPDFFiles[i];
			int iPDFPart=mmp->addBodyPart(pdfFile.substr(8),MIMEBodyPart::BASE64);
			MIMEBodyPart *mbpdf=mmp->getBodyPart(iPDFPart,false);
			mbpdf->setContentID(L"cid:internalPDF"+WString(i));
		}

		// write to a url
		mm->Write2URL("File:///test.mjm");
		delete mm;

		return 0;		
		
	}
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 
	* create a node for subcontracting based on KDI Spec
	* from scratch
	*/
	int ExampleDoc::SubContract(){
		
		// get the JDF document root element
		JDFNode productNode=GetRoot();
		// Get the cover product node
		JDFNode coverNode=productNode.GetProduct("Cover");
		//create a ConventionalPrinting Gray Box 
		JDFNode nodeSubContractGrayBox=coverNode.AddProcessGroup();
		nodeSubContractGrayBox.SetTypes(vWString(L"ConventionalPrinting Palletizing Delivery"));

		
		
		return 1; 
	}
	
	/////////////////////////////////////////////////////////////////////////////
	/** 
	* Example 
	* Update a version to JDF 1.3
	* from scratch
	*/
	int ExampleDoc::UpdateVersion(JDFElement::EnumVersion vers){
		
		// get the JDF document root element
		JDFNode n=GetRoot();
		// update to 1.3
		bool ok= n.FixVersion(vers);		
		return 1; 
	}
	
}	/////////////////////////////////////////////////////////////////////////////

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
	// Initialize the XML4C2 system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	
	// these brackets are necessary because otherwise the document goes out of scope after Terminate and causes an exception
	{
		// trivial argument handling
		MyArgs args(argC,argV,"q","aio");
		
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
		
		// need at least one instance of a parser to hold the trees
		parser=new JDFParser();
		
		// create a JDF Doc
		// use ExampleDoc as a container that holds the various example routines
		// 0=JDF document root
		int iDoc=0;
		// 1= JMF  document root
		if(action.rightStr(7)=="Message")
			iDoc=1;
		ExampleDoc doc(iDoc);
		doc.bQuiet=args.BoolParameter('q',false);
		// do the specified example
		doc.DoExample(action,inFile,outFile);

		// zapp the parser
		delete parser;
	} // end of doc scope before terminate!
	
	// clean up
	JDF::PlatformUtils::Terminate();
	return 0;
}

