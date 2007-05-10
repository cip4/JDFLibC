

#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFState.h"
#include "jdf/wrapper/JDFValue.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"
#include "jdf/wrapper/JDFEnumerationEvaluation.h"
#include "jdf/wrapper/JDFIntegerEvaluation.h"
#include "jdf/wrapper/JDFNameEvaluation.h"
#include "jdf/wrapper/JDFDeviceCap.h"
#include "jdf/wrapper/JDFDevCaps.h"
#include "jdf/wrapper/JDFDevCap.h"
#include "jdf/wrapper/JDFDeviceList.h"
#include "jdf/wrapper/JDFDeviceInfo.h"
#include "jdf/wrapper/JDFDevice.h"
#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>
#include <math.h>
#include "MyArgs.h"


XERCES_CPP_NAMESPACE_USE
using namespace std;
using namespace JDF;


void main(int argc, char* argv[]){

	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return ;
	}

	/*	
	JDFDoc jdfDoc(0); //0 - JDF
	JDFNode root   = jdfDoc.GetJDFRoot();

	if(!root.isNull())
	{
	*/	
	/*   
	JDFNumberRangeList nr("0~2.3 3~-INF"); // with -INF it has to be false, but OK. Have we realy -INF?
	JDFNumberRangeList pnr("1~6");

	JDFNumberState k = root.AppendElement("NumberState");	
	k.SetAllowedValueList(nr);

	JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedRangeList;
	k.SetListType(lt);

	JDFXYPair xy("0.9 0.1");
	k.SetAllowedValueMod(xy);

	cout << "Name of State is " << k.GetNodeName() << endl;

	WString value="1";


	//double n = ((1-0.9*(int)(1/0.9))-0.1); // example from ValueMod = "0.9 0.1"
	//cout << "URA!!!!!, Modul n=" << fabs(n) << endl;


	bool bFits	= k.FitsValue(value);

	k.SetPresentValueList(pnr);

	value="2.5 3~6";		


	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;
	bool bFits2	= k.FitsValue(value, valuelist);						

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "First value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}

	*/
	/*		  
	try {	
	//JDFIntegerRangeList nr("0~INF");
	JDFIntegerRangeList nr("2 12 22");
	JDFXYPair xy("10 2");

	JDFIntegerRangeList pnr("32~64");
	//pnr.SetDef(64);

	JDFIntegerState k = root.AppendElement("IntegerState");	


	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList;
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_RangeList;
	k.SetListType(lt);

	k.SetAllowedValueList(nr);
	//k.SetAllowedValueMod(xy);


	cout << "Name of State is " << k.GetNodeName() << endl; 


	WString value="2 12"; 
	bool bFits	= k.FitsValue(value); 

	k.SetPresentValueList(pnr); 

	value="32~-2";
	JDFIntegerRangeList rl(value);
	if (rl.at(rl.size()-1).GetRight()<0) {
	rl.SetDef(pnr.at(rl.size()-1).GetRight()); // we do it in JDFIntegerState::FitsValueList
	}

	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;

	bool bFits2	= k.FitsValue(value, valuelist); // value is "32~-2"


	cout << "Value as a vector of ranges" << endl;
	for (int i=0; i<rl.size(); i++)
	{
	cout << rl.at(i) << endl;
	}
	cout << endl;


	cout << "Value as a vector of int, that we received" << endl;
	vint vintrl=rl.ToVInt();
	for (int j=0; j<vintrl.size(); j++)
	{
	cout << vintrl[j] << endl;
	}
	cout << endl;


	if (bFits==true)
	cout << "First value - it's OK\n" <<endl;
	else {
	cout << "First value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value - It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}
	}
	catch (JDFException e){
	cout<<"Caught Exception "<<e.getType()<<" "<<e.getMessage()<<endl;
	}
	*/
	/*		JDFIntegerRangeList list("-10~INF");
	JDFXYPair xy("10 2");

	JDFIntegerRangeList list2("-8~-1");
	list2.SetDef(32);


	cout << "Value as a vector of ranges" << endl;
	for (int i=0; i<list2.size(); i++)
	{
	cout << list2.at(i) << endl;
	}
	cout << endl;


	cout << "Value as a vector of int" << endl;
	vint vintlist2=list2.ToVInt();
	for (int j=0; j<vintlist2.size(); j++)
	{
	cout << vintlist2[j] << endl;
	}
	cout << endl;


	JDFIntegerEvaluation k = root.AppendElement("IntegerEvaluation");	
	cout << "Name of Evaluation is " << k.GetNodeName() << endl; 

	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_RangeList;
	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);

	k.SetValueList(list);
	//k.SetValueMod(xy);


	WString value="2 72 102";

	bool bFits	= k.FitsValue(value); 





	k.SetValueList(list2);

	value="-8~-1";

	JDFIntegerRangeList rl(value);
	rl.SetDef(64);


	bool bFits2	= k.FitsValue(value); // FitsValue "eats" value as a String without xDef

	cout << "Value as a vector of ranges" << endl;
	for (int l=0; l<rl.size(); l++)
	{
	cout << rl.at(l) << endl;
	}
	cout << endl;


	cout << "Value as a vector of int" << endl;
	vint vintrl=rl.ToVInt();
	for (int m=0; m<vintrl.size(); m++)
	{
	cout << vintrl[m] << endl;
	}
	cout << endl;


	if (bFits==true)
	cout << "First value - it's OK\n" <<endl;
	else {
	cout << "First value doesn't fit this Evaluation\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value - It's OK\n" <<endl;
	else {
	cout << "Second value doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*
	JDFShapeRangeList nr("0 0 0~2.3 3 3.3 5 5 5~5.3 7 9");
	JDFNumberRangeList xr("0~2.3 3~5.3");
	JDFNumberRangeList yr("0~3.3 6");
	JDFNumberRangeList zr("0~3.3 9");
	JDFShapeRangeList pnr("1.7 1.9 2.6 2 6 9 3 6 9");

	JDFShapeState k = root.AppendElement("ShapeState");	

	k.SetAllowedValueList(nr);

	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList;
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_SingleValue;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedRangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedRangeList;
	k.SetListType(lt);

	k.SetAllowedX(xr);
	k.SetAllowedY(yr);
	k.SetAllowedZ(zr);


	cout << "Name of State is " << k.GetNodeName() << endl;

	WString value="1 1 1~1.5 3 3 5 6 9";


	bool bFits	= k.FitsValue(value);

	k.SetPresentValueList(pnr);

	value="1.7 1.9 2.6 3 6 9 2 6 9";
	WString value3="2 6 9";


	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;
	bool bFits2	= k.FitsValue(value, valuelist);						

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}
	*/

	/*		JDFShapeRangeList list("0 0 0~2.3 3 3.3 5 5 5~5.3 7 9");
	JDFShapeRangeList list2("1.7 1.9 2.6 2 6 9 3 6 9");	
	JDFXYPair tol("0.001 0.001");
	JDFNumberRangeList xr("0~2.3 3~5.3");
	JDFNumberRangeList yr("0~3.3 6");
	JDFNumberRangeList zr("0~3.3 9");


	JDFShapeEvaluation k = root.AppendElement("ShapeEvaluation");	

	k.SetValueList(list);
	k.SetTolerance(tol);
	k.SetX(xr);
	k.SetY(yr);
	k.SetZ(zr);


	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_RangeList;

	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);



	cout << "Name of Evaluation is " << k.GetNodeName() << endl;

	WString value="1 1 1~1.5 3.001 3 5 5.999 9";

	bool bFits	= k.FitsValue(value);


	k.SetValueList(list2);
	value="1.7 1.9 2.6 3 6 9 2 6 9";
	WString value3="2 6 9.001";

	bool bFits2	= k.FitsValue(value);						

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*		WString value1=L"blam";
	WString value2=L"trpympym blaaaablabla";
	WString regExp=L"bl";


	JDFIntegerRange ir("0~22");

	JDFStringState k = root.AppendElement("StringState");	

	k.SetAllowedLength(ir);
	k.SetAllowedRegExp(regExp);

	k.AppendValue();
	k.SetValueValueUsage(0, JDFStateBase::FitsValue_Allowed);
	k.SetValueAllowedValue(0, value2);

	k.AppendValue();
	//k.SetValueValueUsage(1, JDFStateBase::FitsValue_Present);
	k.SetValueAllowedValue(1, value1);

	cout << "Name of State is " << k.GetNodeName() << endl;

	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;

	bool bFits	= k.FitsValue(value1);



	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}

	*/
	/*		WString value1=L"blam";
	WString value2=L"trpympym blaaaablabla";

	WString regExp=L"bl";
	JDFIntegerRange ir("0~12");

	JDFStringEvaluation k = root.AppendElement("StringEvaluation");	

	k.SetLength(ir);
	k.SetRegExp(regExp);

	k.AppendValue();
	k.SetValueValue(0, value2);

	k.AppendValue();
	k.SetValueValue(1, value1);

	cout << "Name of Evaluation is " << k.GetNodeName() << endl;


	bool bFits	= k.FitsValue(value2);


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*
	WString value1=L"blam";
	WString value2=L"blammbamblam";

	JDFIntegerRange ir("0~12");

	JDFPDFPathState k = root.AppendElement("PDFPathState");

	cout << "Name of State is " << k.GetNodeName() << endl;

	k.SetAllowedLength(ir);

	k.AppendValue();
	k.SetValueValueUsage(0, JDFStateBase::FitsValue_Allowed);
	k.SetValueAllowedValue(0, value2);

	k.AppendValue();
	k.SetValueValueUsage(1, JDFStateBase::FitsValue_Present);
	k.SetValueAllowedValue(1, value1);

	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;

	bool bFits	= k.FitsValue(value2,valuelist);


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	*/
	/*		WString value1=L"blam";
	WString value2=L"blammbamblam";
	WString value3=L"mmmblam";

	JDFIntegerRange ir("0~12");

	JDFPDFPathEvaluation k = root.AppendElement("PDFPathEvaluation");

	cout << "Name of Evaluation is " << k.GetNodeName() << endl;

	k.SetLength(ir);

	k.AppendValue();
	k.SetValueValue(0, value2);

	k.AppendValue();
	k.SetValueValue(1, value1);


	bool bFits	= k.FitsValue(value1);


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*		JDFRectangleRangeList nr("0 0 1 1~0 0 3 3");

	JDFElement::EnumXYRelation hwrel=JDFElement::XYRelation_le;

	JDFRectangleRangeList pnr("0 0 1 1 0 0 3 3 0 0 2 2");


	JDFRectangleState k = root.AppendElement("RectangleState");	

	k.SetAllowedValueList(nr);
	//k.SetAllowedHWRelation(hwrel);

	JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedRangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_Unknown; // value 3 -true,value 1-false
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_RangeList; // true
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_List; // true
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList; // value 2 k valuelist1 - true
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList; // true - value2 k valuelist2 -rokirovka ordered
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList; // false - value2 k valuelist2, ispravit
	k.SetListType(lt);


	cout << "Name of State is " << k.GetNodeName() << endl;

	WString value="0 0 1 1 0 0 2 2 0 0 3 3 "; 




	bool bFits	= k.FitsValue(value);


	//k.SetPresentValueList(pnr);

	value="0 0 1 1";		

	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;


	bool bFits2	= k.FitsValue(value, valuelist);	


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}

	*/
	/*		JDFRectangleRangeList nr("0 0 1 1~0 0 3 3");
	JDFXYPair tol("0.001 0.001");
	JDFElement::EnumXYRelation hwrel=JDFElement::XYRelation_le;

	JDFRectangleRangeList pnr("0 0 1 1 0 0 3 3 0 0 2 2");


	JDFRectangleEvaluation  k = root.AppendElement("RectangleEvaluation");	

	k.SetValueList(nr);
	//k.SetHWRelation(hwrel);
	k.SetTolerance(tol);


	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueOrderedRangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; // value 3 -true,value 1-false
	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_RangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List; // true
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_ContainedList; // value 2 k valuelist1 - true
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_CompleteList; // true - value2 k valuelist2 -rokirovka ordered
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_CompleteOrderedList; // false - value2 k valuelist2, ispravit
	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);



	cout << "Name of Evaluation is " << k.GetNodeName() << endl;

	WString value="0 0 1 1 0 0 2 2 0 0 3 3"; 

	bool bFits	= k.FitsValue(value);



	value="0 0 1 1";		

	bool bFits2	= k.FitsValue(value);	


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*		JDFXYPairRangeList nr("0 0 1 1~3 3");

	JDFElement::EnumXYRelation xyrel=JDFElement::XYRelation_le;

	JDFXYPairRangeList pnr("0 0 1 1 2 2");


	JDFXYPairState k = root.AppendElement("XYPairState");	

	k.SetAllowedValueList(nr);
	k.SetAllowedXYRelation(xyrel);

	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedRangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_Unknown; // value 3 -true,value 1-false
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_RangeList; // true
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_List; // true
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList; // value 2 k valuelist1 - true
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList; // true - value2 k valuelist2 -rokirovka ordered
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList; // false - value2 k valuelist2, ispravit
	k.SetListType(lt);


	cout << "Name of State is " << k.GetNodeName() << endl;

	WString value="0 0 2 3.001 0 0 2 2 0 0 3 3 "; 

	bool bFits	= k.FitsValue(value);


	//k.SetPresentValueList(pnr);

	value="0 0 1 1";		

	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;


	bool bFits2	= k.FitsValue(value, valuelist);	


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}

	*/
	/*		JDFXYPairRangeList nr("0 0 1 1~3 3");
	JDFXYPair tol("0.001 0.001");
	JDFElement::EnumXYRelation xyrel=JDFElement::XYRelation_le;

	JDFXYPairRangeList pnr("0 0 1 1 2 2 3 3");


	JDFXYPairEvaluation  k = root.AppendElement("XYPairEvaluation");	

	k.SetValueList(nr);
	k.SetXYRelation(xyrel);
	k.SetTolerance(tol);


	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueOrderedRangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; // value 3 -true,value 1-false
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_RangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List; // true
	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);



	cout << "Name of Evaluation is " << k.GetNodeName() << endl;

	WString value="0 0 3.001 3.001 0 0 2 2 0 0 3 3 "; 

	bool bFits	= k.FitsValue(value);



	value="0 0.001 1 1";		

	bool bFits2	= k.FitsValue(value);	


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this Evaluation\n" <<endl;
	}
	*//*
	try{

	JDFMatrix matrix1=L"1 0 0 1 3.14 21631.3";
	JDFMatrix matrix2=L"0 1 1 0 2 21000";
	JDFMatrix matrix3=L"1 0 0 1 1 1";

	vint transforms;
	transforms.push_back(3);
	transforms.push_back(4);
	transforms.push_back(5);
	JDFRectangle shift("2 4 20000 23000");


	WString value1=L"1 0 0 1 3.14 21631.3";
	WString value2=L"1 0 0 1 3.14 21631.3 0 1 1 0 2 21000";

	JDFMatrixState k = root.AppendElement("MatrixState");	


	k.AppendValue();
	cout << k << endl;
	k.SetValueValueUsage(0, JDFStateBase::FitsValue_Allowed);
	k.SetValueAllowedValue(0, matrix2);

	k.AppendValue();
	//k.SetValueValueUsage(1, JDFStateBase::FitsValue_Present);
	k.SetValueAllowedValue(1, matrix1);


	cout << "\nName of State is " << k.GetNodeName() << endl;

	k.SetAllowedTransforms(transforms);
	k.SetAllowedShift(shift);
	k.SetAllowedRotateMod(15); 


	JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList; 
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_Unknown; 
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_List; // true
	k.SetListType(lt);


	bool bFits	= k.FitsValue(value2);

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}


	WString value="1 2 3 4 5 6 7 8 9 10 11 12 3 4 5 6 7 8";

	vWString vs=value.Tokenize();
	if (vs.size()%6!=0) {
	cout << "\nIt is not a Matrix\n" <<endl;
	}
	else {
	vWString matrixList;
	int i=0;
	WString s=vs[i];
	while ((i+1)<vs.size())
	{
	do  {
	s+=WString::blank;
	i++;
	s+=vs[i];
	}
	while ((i+1)%6!=0) ;
	matrixList.push_back(s);
	if ((i+1)<vs.size())
	{ 
	i++;
	s=vs[i];
	}
	}
	for (int z=0; z<matrixList.size(); z++)
	{
	cout << matrixList.at(z) <<endl;
	}

	}
	}
	catch (JDFException e){
	cout<<"Caught Exception "<<e.getType()<<" "<<e.getMessage()<<endl;
	}
	*/
	/*		JDFMatrix matrix1=L"0 1 1 0 3.14 21631.3";
	JDFMatrix matrix2=L"1 0 0 1 2 21000";
	JDFMatrix matrix3=L"1 0 0 1 1 1";

	vint transforms;
	transforms.push_back(8);
	transforms.push_back(4);
	transforms.push_back(5);
	JDFRectangle shift("2 4 20000 23000");
	JDFXYPair tol("0.001 0.001");


	WString value1=L"0 1 1 0 3.14 21631.3";
	WString value2=L"1 0 0 1 3.14 21631.3 1 0 0 1 2 21000";

	JDFMatrixEvaluation k = root.AppendElement("MatrixEvaluation");	


	k.AppendValue();
	k.SetValueValue(0, matrix2);

	k.AppendValue();
	k.SetValueValue(1, matrix1);

	cout << "Name of Evaluation is " << k.GetNodeName() << endl;

	k.SetTolerance(tol);
	k.SetTransforms(transforms);
	k.SetShift(shift);
	k.SetRotateMod(15); 


	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List; 

	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);


	bool bFits	= k.FitsValue(value1);

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*		WString value1=L"laaa";
	WString value2=L"blaaaablabla blaaaa laaa";

	WString regExp=L"laaa";

	WString strList = L"blaaaa laaa blaaaablabla";
	vWString valuelist=strList.Tokenize();


	JDFNameState k = root.AppendElement("NameState");	


	k.SetAllowedRegExp(regExp);

	k.SetAllowedValueList(valuelist);


	cout << "\nName of State is " << k.GetNodeName() << endl;

	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_Unknown; 
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_List; 
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList; 
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList; 
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList; 
	k.SetListType(lt);



	//JDFStateBase::EnumFitsValue list=JDFStateBase::FitsValue_Present;

	bool bFits	= k.FitsValue(value2); 



	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	*/
	/*		WString value1=L"laaa";
	WString value2=L"blaaaablabla blaaa laaa";

	WString regExp=L"laaa";

	WString strList = L"blaaa laaa blaaaablabla";
	vWString valuelist=strList.Tokenize();


	JDFNameEvaluation k = root.AppendElement("NameEvaluation");	


	k.SetRegExp(regExp);

	k.SetValueList(valuelist);

	cout << "\nName of Evaluation is " << k.GetNodeName() << endl;

	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List; 
	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_ContainedList; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_CompleteList; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_CompleteOrderedList; 
	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);



	//JDFStateBase::EnumFitsValue list=JDFStateBase::FitsValue_Present;

	bool bFits	= k.FitsValue(value1); 

	bool bFits2	= k.FitsValue(value2);				

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}

	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value doesn't fit this State\n" <<endl;
	}
	*/
	/*		WString value1=L"blaaaablabla blam";
	WString value2=L"blammmmm blam";
	WString value3=L"blam";


	WString strList1 =L"blaaaablabla blam";

	WString strList2 =L"blam blammmmm";

	vWString valuelist1=strList1.Tokenize();

	vWString valuelist2=strList2.Tokenize();



	JDFEnumerationState k = root.AppendElement("EnumerationState");	

	k.SetAllowedValueList(valuelist1);


	cout << "\nName of State is " << k.GetNodeName() << endl;

	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_Unknown; // value 3 -true,value 1-false
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_List; // true
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList; // value 2 k valuelist1 - true
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList; // true - value2 k valuelist2 -rokirovka ordered
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList; // false - value2 k valuelist2, ispravit
	k.SetListType(lt);


	bool bFits	= k.FitsValue(value3);


	k.SetPresentValueList(valuelist2);
	JDFStateBase::EnumFitsValue presentList=JDFStateBase::FitsValue_Present;

	bool bFits2	= k.FitsValue(value2,presentList);


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}

	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value doesn't fit this State\n" <<endl;
	}
	*/
	/*
	WString value1=L"blaaaablabla blam";
	WString value2=L"blammmmm blam";
	WString value3=L"blam";


	WString strList1 =L"blaaaablabla blam";

	WString strList2 =L"blam blammmmm";

	vWString valuelist1=strList1.Tokenize();

	vWString valuelist2=strList2.Tokenize();



	JDFEnumerationEvaluation k = root.AppendElement("EnumerationEvaluation");	

	k.SetValueList(valuelist1);


	cout << "\nName of Evaluation is " << k.GetNodeName() << endl;

	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_ContainedList; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_CompleteList; 
	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_CompleteOrderedList; 
	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);


	bool bFits	= k.FitsValue(value1);


	k.SetValueList(valuelist2);

	bool bFits2	= k.FitsValue(value2);// if ListType is not specified default=SingleValue -> false


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}

	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*		JDFDurationRangeList list("P1Y2M3DT10H30M~P1Y2M3DT10H35M P1Y2M3DT10H40M");
	JDFDurationRangeList list2("P2M3DT10H P2M3DT25H PT10H35M PT10H40M");

	JDFDurationState k = root.AppendElement("DurationState");	

	k.SetAllowedValueList(list);

	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_RangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_RangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_SingleValue;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedRangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedList;
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedRangeList;
	k.SetListType(lt);


	cout << "Name of State is " << k.GetNodeName() << endl;

	WString value="P1Y2M3DT10H30M~P1Y2M3DT10H35M P1Y2M3DT10H35M";
	//WString value="P1Y2M3DT10H32M30.5S";

	bool bFits	= k.FitsValue(value);


	k.SetPresentValueList(list2);

	//value="P1Y2M3DT10H";
	//value="P2M3DT12H PT10H40M";
	value="P2M3DT10H PT10H40M PT10H35M";

	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;

	bool bFits2	= k.FitsValue(value, valuelist);						

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}
	*/
	/*
	JDFDurationRangeList list("P1Y2M3DT10H00M~P1Y2M3DT10H35M P1Y1M2DT10H40M");
	MyDate m("P1Y2M3DT10H30M");
	cout<<m.DurationISO()<<endl;
	JDFDurationRangeList list2("PT10H~PT15H");

	JDFDurationEvaluation k = root.AppendElement("DurationEvaluation");	

	k.SetValueList(list);


	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueOrderedRangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueOrderedList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_OrderedRangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_OrderedList;
	JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_UniqueList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_Unknown; 
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_RangeList;
	//JDFBasicPreflightTest::EnumListType lt=JDFBasicPreflightTest::ListType_List; 

	k.AppendBasicPreflightTest();
	k.GetBasicPreflightTest().SetListType(lt);


	cout << "Name of Evaluation is " << k.GetNodeName() << endl;

	//WString value="P2Y2M3DT10H32M";
	WString value="P1Y2M3DT10H32M";

	bool bFits	= k.FitsValue(value);


	k.SetValueList(list2);

	value="PT10H20M33.3S";
	//value="P1Y2M3DT10H P1Y1M2DT10H40M";

	bool bFits2	= k.FitsValue(value);	


	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this Evaluation\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this Evaluation\n" <<endl;
	}
	*/
	/*		MyDate md((time_t)0);
	int sec = md.GetSecondsSince1970();

	cout<<"sec " <<sec<<endl<<endl;

	JDFDateTimeRangeList list("1999-05-31T18:20:00Z~2001-05-31T18:25:00Z");
	JDFDateTimeRangeList list2("1999-05-31T18:20:00Z~1999-08-31T18:20:00Z");

	JDFDateTimeState k = root.AppendElement("DateTimeState");	

	k.SetAllowedValueList(list);

	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_RangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_ContainedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_CompleteOrderedList;
	JDFStateBase::EnumListType lt=JDFStateBase::ListType_SingleValue;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_OrderedRangeList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedList;
	//JDFStateBase::EnumListType lt=JDFStateBase::ListType_UniqueOrderedRangeList;
	k.SetListType(lt);

	WString value;
	bool bFits;
	cout << "Name of State is " << k.GetNodeName() << endl;
	try {
	value="PT20M";
	//"2001-05-30T18:00:00Z";

	bFits	= k.FitsValue(value);
	}
	catch (JDFException e)
	{
	cout<<"Caught Exception "<<e.getType()<<" "<<e.getMessage()<<endl;
	}

	k.SetPresentValueList(list2);

	value="1999-05-31T18:20:00Z~1999-06-31T18:20:00Z";
	//value="2002-05-31T18:25:00Z";


	JDFStateBase::EnumFitsValue valuelist=JDFStateBase::FitsValue_Present;

	bool bFits2	= k.FitsValue(value, valuelist);						

	if (bFits==true)
	cout << "\nFirst value: It's OK\n" <<endl;
	else {
	cout << "\nFirst value doesn't fit this State\n" <<endl;
	}
	if (bFits2==true)
	cout << "Second value: It's OK\n" <<endl;
	else {
	cout << "Second value " <<value<< " doesn't fit this State\n" <<endl;
	}
	*/
	/*
	JDFor or1 = root.AppendElement("or");

	//append enumeration evaluation and set its ValueList and BasicPreflightTest element 
	JDFEnumerationEvaluation enumEval = or1.AppendEnumerationEvaluation();
	JDFBasicPreflightTest bpTest1 = enumEval.AppendBasicPreflightTest();
	bpTest1.SetName(L"TrappedKey");
	bpTest1.SetListType(JDFBasicPreflightTest::ListType_List);

	WString enumValueList=L"true false";
	//WString enumValueList=L"Unknown true false";
	vWString enumList=enumValueList.Tokenize();
	enumEval.SetValueList(enumList);

	//append name evaluation and set its ValueList and BasicPreflightTest element 	
	JDFNameEvaluation nameEval = or1.AppendNameEvaluation();
	JDFBasicPreflightTest bpTest2 = nameEval.AppendBasicPreflightTest();
	bpTest2.SetName(L"OutputIntentColorSpace");
	bpTest2.SetListType(JDFBasicPreflightTest::ListType_List);

	WString nameValueList=L"CMYK";
	//WString nameValueList=L"None CMYK Gray RGB";
	vWString nameList=nameValueList.Tokenize();
	nameEval.SetValueList(nameList);

	//create a map of key-value pairs.
	mAttribute m;
	m.AddPair("OutputIntentColorSpace","Gray");
	m.AddPair("TrappedKey","true");


	bool bFitsMap = or1.FitsMap(m);

	if (bFitsMap==true)
	cout << "\nResult of FitsMap: It's OK\n" <<endl;
	else {
	cout << "\nResult of FitsMap: Map doesn't fit this Term\n" <<endl;
	}
	*/
	/*	// !!! just a test - without sense

	JDFand and = root.AppendElement("and");

	//append integer evaluation and set its ValueList and BasicPreflightTest element 
	JDFIntegerEvaluation integEval = and.AppendIntegerEvaluation();
	JDFBasicPreflightTest bpTest1 = integEval.AppendBasicPreflightTest();
	bpTest1.SetName(L"FileSize");

	JDFIntegerRangeList integValueList=L"2560000~10240000";
	integEval.SetValueList(integValueList);


	JDFor or = and.AppendElement("or");

	//append enumeration evaluation and set its ValueList and BasicPreflightTest element 
	JDFEnumerationEvaluation enumEval = or.AppendEnumerationEvaluation();
	JDFBasicPreflightTest bpTest2 = enumEval.AppendBasicPreflightTest();
	bpTest2.SetName(L"TrappedKey");
	bpTest2.SetListType(JDFBasicPreflightTest::ListType_List);

	WString enumValueList=L"false";
	//Alowed values are: WString enumValueList=L"Unknown true false";
	vWString enumList=enumValueList.Tokenize();
	enumEval.SetValueList(enumList);


	//append not term  	
	JDFnot not = or.Appendnot();
	//append name evaluation and set its ValueList and BasicPreflightTest element 
	JDFNameEvaluation nameEval = not.AppendNameEvaluation();
	JDFBasicPreflightTest bpTest3 = nameEval.AppendBasicPreflightTest();
	bpTest3.SetName(L"OutputIntentColorSpace");
	bpTest3.SetListType(JDFBasicPreflightTest::ListType_List);

	WString nameValueList=L"CMYK";
	//WString nameValueList=L"None CMYK Gray RGB";
	vWString nameList=nameValueList.Tokenize();
	nameEval.SetValueList(nameList);


	//create a map of key-value pairs.
	mAttribute m;
	m.AddPair("OutputIntentColorSpace","Gray");
	m.AddPair("TrappedKey","true");
	m.AddPair("FileSize","2560000");


	bool bFitsMap = and.FitsMap(m);

	if (bFitsMap==true)
	cout << root<<endl<<"\nResult of FitsMap: It's OK\n" <<endl;
	else {
	cout << "\nResult of FitsMap: Map doesn't fit this Term\n" <<endl;
	}


	else
	{
	throw JDFException("JDFNode == null cant start Test");
	}
	*/															


	JDFParser parser;


	MyArgs args(argc,argv,"","t");
	WString devCapFile=args.ParameterString('t').c_str();

	for(int arg=0;arg<args.NArgs();arg++){
		WString testFile =args.ArgumentString(arg);
		JDFDoc docDevCap;
		JDFDoc docTest;
		try{
			if(!devCapFile.empty()) {
				parser.Parse(devCapFile,false);
				docDevCap=parser.GetRoot();
			}

			JDFJMF jmfRoot=docDevCap.GetJMFRoot();
			// ich bin jetzt in JMF -> muss elm_DeviceCap finden.

			if(devCapFile.empty()) {
				jmfRoot.Flush();
				jmfRoot.init();
			}
			if (jmfRoot.isNull()) {
				throw JDFException("JMFNode == null cant start Test");
			}


			if(!testFile.empty()) {
				parser.Parse(testFile,false);
				docTest=parser.GetRoot();
			}
			JDFNode jdfRoot=docTest.GetRoot();

			if(testFile.empty()) {
				if(jdfRoot.IsJDFNode()){
					JDFNode JDFNode=docTest.GetRoot();
					JDFNode.init(true);
				}else if(jdfRoot.GetLocalName()==L"JMF"){
					JDFJMF jmfR=docTest.GetRoot();
					jmfR.Flush();
					jmfR.init();
				}
			}
			if (jdfRoot.isNull()) {
				throw JDFException("JDFNode == null cant start Test");
			}

			JDFDeviceCap deviceCap = jmfRoot.GetDeepElement("DeviceCap");

			JDFElement::EnumFitsValue testlists = JDFElement::FitsValue_Allowed; 

			cout << jdfRoot<<endl<<endl;
			cout << jmfRoot<<endl<<endl;

			KElement::EnumValidationLevel level = KElement::ValidationLevel_Complete;

			vElement vExecNodes = deviceCap.GetExecutableJDF(jdfRoot, testlists, level);

			if (!vExecNodes.empty()) { 
				cout << "Executable Nodes are" << endl;
				for (int j=0; j<vExecNodes.size(); j++) {
					cout << vExecNodes[j] << endl << endl;
				}
				cout <<endl << endl;
			}
			else 
				cout << "No executable nodes" << endl<< endl;


			XMLDoc testResult = deviceCap.GetBadJDFInfo(jdfRoot,testlists,level);

				cout << "\nResult of GetBadJDFInfo: The error messages are:" <<endl;
				cout <<testResult<< endl <<endl;

		}catch (JDFException e){
			cout<<"Caught Exception "<<e.getType()<<" "<<e.getMessage()<<endl;
		}
	}	
}
