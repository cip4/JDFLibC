#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp> 

#include "jdf/wrapper/JDFSpan.h"
#include "jdf/wrapper/JDF.h"
#include "MyArgs.h"
#include <iostream>

XERCES_CPP_NAMESPACE_USE

using namespace std;
using namespace JDF;
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
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}

	// global variable for ostream
	MyArgs args(argC,argV,"qe","i");
	
    // Watch for special case help request
	WString usage="BookJDF: JDF creator simulation;\nArgument: output JDF;\n -q: add some random quote objects\n";
    if ((argC>1)&&(strcmp(argV[1], "-?") == 0)|| (argC==1)){
        cerr<< args.Usage(usage);
        return 0;
    }
	
	JDFDoc gdoc(0);
	JDFNode rootProduct=gdoc.GetRoot();
	rootProduct.init(true);
	rootProduct.SetJobPartID(L"Product");
	rootProduct.SetEnumType(JDFNode::Type_Product);
	JDFNode teachEd=rootProduct.AddProduct();
	teachEd.SetDescriptiveName("Teacher's Edition");

	JDFComponent rTeachBook=teachEd.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput,rootProduct);
	rTeachBook.SetDescriptiveName("Teacher's Edition Component");
	rTeachBook.SetComponentType(JDFComponent::ComponentType_FinalProduct);

	JDFNode pCover=rootProduct.AddProduct();
	pCover.SetDescriptiveName("Cover");
	JDFComponent rCover=pCover.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput);
	rCover.SetComponentType(JDFComponent::ComponentType_PartialProduct);
	rCover.SetAmount(2000);
	JDFSizeIntent sI=pCover.AppendMatchingResource(JDFElement::elm_SizeIntent,JDFNode::ProcessUsage_AnyInput);
	
	JDFXYPairSpan xI=sI.GetCreateDimensions();
	xI.SetPreferred(72*8.5, 72*11);
	xI.AddRange(72*8, 72*10.5, 72*9, 72*11.5);

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Now for the quote elements nodes
//////////////////////////////////////////////////////////////////////////////////////////////////////


	JDFNode pTeachInsert=teachEd.AddProduct();
	pTeachInsert.SetDescriptiveName("Teacher's Insert");

	sI=pTeachInsert.AppendMatchingResource(JDFElement::elm_SizeIntent,JDFNode::ProcessUsage_AnyInput);
	xI=sI.GetCreateDimensions();
	xI.SetPreferred(72*8.5, 72*11);
	xI.AddRange(72*8, 72*10.5, 72*9, 72*11.5);

	JDFIntegerSpan nII=sI.GetCreatePages();
	nII.SetPreferred(240);

	JDFComponent rTeachInsert=pTeachInsert.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput,rootProduct);
	rTeachInsert.SetComponentType(JDFComponent::ComponentType_PartialProduct);
	rTeachInsert.SetDescriptiveName("Insert");
	teachEd.LinkMatchingResource(rTeachInsert,JDFNode::ProcessUsage_AnyInput);

	JDFNode studEd=rootProduct.AddProduct();
	studEd.SetDescriptiveName("Student's Edition");
	JDFComponent rStudBook=studEd.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput,rootProduct);
	rStudBook.SetDescriptiveName("Student's Book");
	rStudBook.SetComponentType(JDFComponent::ComponentType_FinalProduct);

	JDFNode pStudInsert=studEd.AddProduct();
	pStudInsert.SetDescriptiveName("Student's Insert");
	JDFComponent rStudInsert=pStudInsert.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput,rootProduct);
	rStudInsert.SetDescriptiveName("Student's Insert");
	rStudInsert.SetComponentType(JDFComponent::ComponentType_PartialProduct);
	
	sI=pStudInsert.AppendMatchingResource(JDFElement::elm_SizeIntent,JDFNode::ProcessUsage_AnyInput);
	xI=sI.GetCreateDimensions();
	xI.SetPreferred(72*8.5, 72*11);
	xI.AddRange(72*8, 72*10.5, 72*9, 72*11.5);
	nII=sI.GetCreatePages();
	nII.SetPreferred(198);

	studEd.LinkMatchingResource(rStudInsert,JDFNode::ProcessUsage_AnyInput);
	studEd.LinkMatchingResource(rCover,JDFNode::ProcessUsage_Cover);
	rCover.RefElement(sI);

	rTeachInsert.SetAmount(100);
	rStudInsert.SetAmount(1000);
	rStudBook.SetAmount(1000);
	rTeachBook.SetAmount(100);

	JDFDeliveryIntent deliv=rootProduct.AppendMatchingResource(JDFElement::elm_DeliveryIntent,rootProduct.ProcessUsage_AnyInput);
	JDFDropIntent di=deliv.AppendDropIntent();
	JDFDropItemIntent dii=di.AppendDropItemIntent();
	dii.RefElement(rTeachBook);
	dii.SetAmount(50);
	dii=di.AppendDropItemIntent();
	dii.RefElement(rStudBook);
	dii.SetAmount(500);
	
	di=deliv.AppendDropIntent();
	dii=di.AppendDropItemIntent();
	dii.RefElement(rTeachBook);
	dii.SetAmount(50);
	dii=di.AppendDropItemIntent();
	dii.RefElement(rStudBook);
	dii.SetAmount(500);


	rootProduct.EraseEmptyNodes();
	WString outFile=args.ArgumentString(0);
	gdoc.Write2File(outFile);
	return 0;
}

