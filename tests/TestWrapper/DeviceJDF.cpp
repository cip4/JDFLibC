
#include "JDF.h"
#include "JDFState.h"

#include <jdf/util/PlatformUtils.h>
#include "MyArgs.h"

using namespace std;
using namespace JDF;

JDFDoc ConventionalPrinting(){
	JDFDoc doc;
	JDFRoot root=doc.GetJDFRoot();
	JDFNode rootNode=root;
	JDFDevice dev=rootNode.AppendDevice();
	return doc;
}



JDFDoc Scanning(){
	JDFDoc gd;
	JDFRoot root=gd.GetJDFRoot();
	JDFDevice dev=root.AddImplementation("Device");
	JDFElement dc=dev.AppendElement("DeviceCap");
	dc.SetAttribute("Types","Scanning");
	JDFElement rcs=dc.AppendElement("DevCaps");
	rcs.SetAttribute("Name","NodeInfo");
	{
		// NodeInfo
		JDFElement rc=rcs.AppendElement("DevCap");
		rc.GetComment(true)<<"NodeInfo restrictions";
		JDFBooleanState oState=rc.AppendElement("BooleanState");
		oState.SetName("MergeTarget");
		oState.SetSupported(false);
		rc.GetComment(true,666)<<"JMF not supported";
		JDFElement e=rc.AppendElement("DevCap");
		e.SetAttribute("Name","JMF");
		e.SetAttribute("Supported",false);
	}
	
	rcs=dc.GetElement("DevCaps",true,L"",999);
	rcs.SetAttribute("Name","ExposedMedia");
	{
		// NodeInfo
		JDFElement rc=rcs.AppendElement("DevCap");
		rc.GetComment(true)<<"ExposedMedia restrictions";
		JDFElement e=rc.AppendElement("DevCap");
		e.SetAttribute("Name","Media");
		JDFNameState enState=e.AppendElement("NameState");
		enState.SetName(L"MediaUnit");
		enState.SetDefaultValue(L"Sheet");
		JDFXYPairState xyState=e.AppendElement("XYPairState");
		xyState.SetName(L"Dimension");
		xyState.SetAllowedValueMin(JDFXYPair(0,0));
		xyState.SetAllowedValueMax(JDFXYPair(600,1200));
	}
	
	rcs=dc.GetElement("DevCaps",true,L"",999);
	rcs.SetAttribute("Name","ScanParams");
	{
		// bw
		JDFElement rc=rcs.AppendElement("DevCap");
		rc.GetComment(true)<<"Black and white 1 bit mode";
		JDFIntegerState iState=rc.AppendElement("IntegerState");
		iState.SetName(L"BitDepth");
		iState.SetDefaultValue(1);
		
		JDFEnumerationState enState=rc.AppendElement(L"EnumerationState");
		enState.SetName(L"CompressionFilter");
		enState.SetAllowedValueList(KString(L"CCITTFaxEncode None").Tokenize());
		
		JDFNumberState numState=rc.AppendElement(L"NumberState");
		numState.SetName("Magnification");
		numState.SetAllowedValueMin(0.01);
		numState.SetAllowedValueMax(100);
		
		enState=rc.AppendElement(L"EnumerationState");
		enState.SetName(L"OutputColorSpace");
		enState.SetAllowedValueList(KString(L"GrayScale").Tokenize());
		
		JDFXYPairState xyState=rc.AppendElement(L"XYPairState");
		xyState.SetName("OutputResolution");
		xyState.SetDefaultValue(JDFXYPair(75,2400));
		
		rc=rc.GetElement("DevCap",true);
		rc.SetAttribute("Name","ScanProfile");
		rc.SetAttribute("Supported",false);
	}
	{
		// gray
		JDFElement rc=rcs.AppendElement("DevCap");
		rc.GetComment(true)<<"Grayscale 12 bit mode";
		JDFIntegerState iState=rc.AppendElement("IntegerState");
		iState.SetName(L"BitDepth");
		iState.SetDefaultValue(8);
		iState.SetAllowedValueMin(1);
		iState.SetAllowedValueMax(12);
		
		JDFEnumerationState enState=rc.AppendElement(L"EnumerationState");
		enState.SetName(L"CompressionFilter");
		enState.SetAllowedValueList(KString(L"FlateEncode DCTEncode None").Tokenize());
		
		JDFNumberState numState=rc.AppendElement(L"NumberState");
		numState.SetName("Magnification");
		numState.SetAllowedValueMin(0.01);
		numState.SetAllowedValueMax(100);
		
		enState=rc.AppendElement(L"EnumerationState");
		enState.SetName(L"OutputColorSpace");
		enState.SetAllowedValueList(KString(L"GrayScale").Tokenize());
		
		JDFXYPairState xyState=rc.AppendElement(L"XYPairState");
		xyState.SetName("OutputResolution");
		xyState.SetAllowedValueMin(JDFXYPair(100,100));
		xyState.SetAllowedValueMax(JDFXYPair(2400,2400));
		xyState.SetDefaultValue(JDFXYPair(600,600));
		
		rc=rc.GetElement("DevCap",true);
		rc.SetAttribute("Name","ScanProfile");
		rc.SetAttribute("Supported",false);
	}
	{
		// color
		JDFElement rc=rcs.AppendElement("DevCap");
		rc.GetComment(true)<<"Color 10 bit mode";
		JDFIntegerState iState=rc.AppendElement("IntegerState");
		iState.SetName(L"BitDepth");
		iState.SetDefaultValue(8);
		iState.SetAllowedValueMin(1);
		iState.SetAllowedValueMax(10);
		
		JDFEnumerationState enState=rc.AppendElement(L"EnumerationState");
		enState.SetName(L"CompressionFilter");
		enState.SetAllowedValueList(KString(L"FlateEncode DCTEncode None").Tokenize());
		
		JDFNumberState numState=rc.AppendElement(L"NumberState");
		numState.SetName("Magnification");
		numState.SetAllowedValueMin(0.01);
		numState.SetAllowedValueMax(10);
		
		enState=rc.AppendElement(L"EnumerationState");
		enState.SetName(L"OutputColorSpace");
		enState.SetAllowedValueList(KString(L"CMYK RGB LAB").Tokenize());
		
		JDFXYPairState xyState=rc.AppendElement(L"XYPairState");
		xyState.SetName("OutputResolution");
		xyState.SetAllowedValueMin(JDFXYPair(100,100));
		xyState.SetAllowedValueMax(JDFXYPair(2400,2400));
		xyState.SetDefaultValue(JDFXYPair(600,600));
		
		rc=rc.GetElement("DevCap",true);
		rc.SetAttribute("Name","ScanProfile");
		rc.SetAttribute("Supported",false);
	}
	cout <<gd;
	gd.Write2File("DevCap.jdf");

	gd=JDFDoc(0);
	root=gd.GetJDFRoot();
	root.SetType("Scanning");
	JDFScanParams scanParams=root.AddParameter("ScanParams");
	scanParams.SetBitDepth(8);
	scanParams.SetOutputColorSpace(scanParams.OutputColorSpace_RGB);
	scanParams.SetOutputResolution(JDFXYPair(600,600));

	JDFExposedMedia exposedMedia=root.AddHandling("ExposedMedia");
	exposedMedia.SetAvailable();
	JDFMedia media=exposedMedia.AppendMedia();
	media.SetDimensionCM(JDFXYPair(15,20));
	cout<<gd;
	gd.Write2File("goodscan.jdf");

	gd=JDFDoc(0);
	root=gd.GetJDFRoot();
	root.SetType("Scanning");
	scanParams=root.AddParameter("ScanParams");
	scanParams.SetBitDepth(8);
	scanParams.SetOutputColorSpace(scanParams.OutputColorSpace_RGB);
	scanParams.SetOutputResolution(JDFXYPair(600,600));
	scanParams.SetMagnification(JDFXYPair(1000,1000));

	exposedMedia=root.AddHandling("ExposedMedia");
	exposedMedia.SetAvailable();
	media=exposedMedia.AppendMedia();
	media.SetDimensionCM(JDFXYPair(15,20));
	return gd;
	}
int main(int argc, char* argv[]){
    // Initialize the XML4C2 system 
	// Initialize the JDFTools system
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
	
	MyArgs args(argc,argv,"ev","i");
	string usage="DeviceJDF: JDF device definition output JDF;\n";
	JDFDoc gd(0);

	XMLIndent(2,true);
	gd=Scanning();
	gd=ConventionalPrinting();
	cout<<gd;
	gd.Write2File("badscan.jdf");
	return 0;
}


