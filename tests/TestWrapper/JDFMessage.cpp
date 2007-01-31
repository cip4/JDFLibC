// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <jdf/util/PlatformUtils.h>
#include <jdf/io/ByteArrayOutputStream.h>
#include <jdf/io/ByteArrayInputStream.h>
#include "JDF.h"

#include "XMLstrm.h"
#include "MyArgs.h"
#include "JDFQuery.h"
using namespace std;

namespace JDF{
class MyResponse:public JDFResponse{
public:
	MyResponse(DOM_Element o):JDFResponse(o){};
	MyResponse():JDFResponse(){};
	~MyResponse(){};
	virtual bool MyResponse::IsQueryImplemented(JDFQuery q){
		KString s=q.GetType();
		if(!s.compare(L"Circus:ListClowns")) return true;
		if(!s.compare(L"Circus:IsClownHappy")) return true;
		return false;
	}
};
}

////////////////////////////////////////////////////////////////////////////////////
using namespace JDF;
void DoResponse(JDFJMF& mIn, JDFJMF& m){
	for(int i=0;42;i++){
		JDF::JDFQuery query=mIn.GetQuery(i);
		if(query.isNull()) break;
		MyResponse Response=m.AppendResponse();
		Response.SetType(query.GetType());
		if(Response.SetQuery(query)){
			if(Response.GetType()=="KnownQueries"){
				Response.AppendElement("KnownQuery").SetAttribute("Type","KnownQueries");
				Response.AppendElement("KnownQuery").SetAttribute("Type","KnownProtocols");
				Response.AppendElement("KnownQuery").SetAttribute("Type","Progress");
				Response.AppendElement("KnownQuery").SetAttribute("Type","Startup");
				Response.AppendElement("KnownQuery").SetAttribute("Type","ShutDown");
				Response.AppendElement("KnownQuery").SetAttribute("Type","Circus:ListClowns");
				Response.AppendElement("KnownQuery").SetAttribute("Type","Circus:IsClownHappy");
			}else if(Response.GetType()=="Circus:ListClowns"){
				JDFElement r=Response.AppendElement("Clown");
				r.SetAttribute("Name","Joe");
				r.SetAttribute("Expression","happy");
				r=Response.AppendElement("Clown");
				r.SetAttribute("Name","Ann");
				r.SetAttribute("Expression","grumpy");
			}else if(Response.GetType()=="Circus:IsClownHappy"){
				KString name=query.GetAttribute("Name");
				if(name=="Joe") Response.SetAttribute("Happy","true");
				if(name=="Ann") Response.SetAttribute("Happy","false");
			} 
		}else{
			Response.SetErrorText(KString("Query: ")+query.GetType()+KString(" is unknown"));
		}
	}
}
void DoFrank(KString s){
	// the input doc
	JDFDoc inputMessageDoc;
	inputMessageDoc.StringParse(s,true,true,true);
	JDFJMF inputMessageJMF=inputMessageDoc.GetRoot();

	// the output doc
	JDFDoc outputMessageDoc(1);	
	JDFJMF outputMessageJMF=outputMessageDoc.GetRoot();
	outputMessageJMF.init();
	string sID="JDFMessageServer";
	outputMessageJMF.SetSenderID(sID);
	DoResponse(inputMessageJMF,outputMessageJMF);

	KString outString;
	outputMessageDoc.Write2String(outString);

	cout<<outString;

}


int main(int argc, char* argv[]){
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
	MyArgs args(argc,argv,"chqQrSF","ios");
	string usage="JDFMessage: JDF consumer simulation;\n-c: console io\n-h: HTML header included\n-i: input JDF;\n-o: output JDF;\n-R(eply) -Q(uery)\n-s Sender ID; -F(ranks test)\n";
	KString outFile=args.ParameterString('o');
	if(outFile.empty()) outFile="Message.jmf";

	JDFDoc gd(1);	
	JDFJMF m=gd.GetRoot();
	m.init();
	string sID=args.ParameterString('s');
	if(sID.empty()) 
		sID="JDFMessenger";
	m.SetSenderID(sID);
	if(args.BoolParameter('r')){
		string xmlFile;

		if (args.BoolParameter('c')){
			xmlFile="_STDIN_";
		}else{
			xmlFile=args.ParameterString('i');
		}
		JDFDoc gdIn(1);
		if(xmlFile.empty()||(gdIn.Parse(xmlFile,args.BoolParameter('v'))==false)){
			cerr<<args.Usage(usage)<<endl;
			return 1;
		}
		JDFJMF mIn=gdIn.GetRoot();
		DoResponse(mIn,m);
	}else if(args.BoolParameter('q')){
		JDF::JDFQuery query=m.AppendQuery();
		query.SetType("KnownQueries");
		query=m.AppendQuery();
		query.SetType("KnownProtocols");
	}else if(args.BoolParameter('Q')){
		JDF::JDFQuery query=m.AppendQuery();
		query.SetType("Circus:ListClowns");
		query.SetAttribute("Name","Joe");
		query.SetType("Circus:IsClownHappy");
	}else if(args.BoolParameter('S')){
		JDFSignal sig=m.AppendSignal();
		sig.SetType("Status");
		JDFStatusQuParams sqp=sig.GetElement("StatusQuParams",true);
		sqp.SetJobDetails(sqp.JobDetails_MIS);
		sqp.SetJobID("PrintJobID");
		JDFDeviceInfo di=sig.GetElement("DeviceInfo",true);
		di.SetDeviceStatus(di.DeviceStatus_Idle);
		JDFJobPhase jp=di.GetJobPhase(true);
		jp.SetAmount(42);
		jp.SetJobID("PrintJobID");
		jp.SetStatus(jp.Status_Completed);
		sig=m.AppendSignal();
		sig.SetType("Events");
		JDFNotificationDef nd=sig.GetElement("NotificationDef",true);
		nd.SetClasses(vKString("Warning"));
		nd.SetType("HDM:ColorTableError");
		JDFComment com=nd.GetComment(true);
		com<<"das ist ein Kommentar";
		com.SetLanguage("de");
	}else if(args.BoolParameter('F')){
		// this sets your message
		JDF::JDFQuery query=m.AppendQuery();
		query.SetType("KnownQueries");
		query=m.AppendQuery();
		query.SetType("KnownProtocols");
	ByteArrayOutputStream myByteStream;
	gd.Write2Stream(myByteStream);
	KString inputQuery=myByteStream.toString();

		DoFrank(inputQuery);
	}
	// 
	if(args.BoolParameter('h')) cout<<"Content-type: text/xml"<<endl<<endl;
	XMLIndent(2,true);
	gd.Write2File(outFile);

    return 0;
}


