#include <jdf/util/PlatformUtils.h>

#include "jdf/wrapper/JDF.h"
#include "JDFSimulator.h"
#include <xercesc/util/PlatformUtils.hpp>

#include "MyArgs.h"
#include <iostream>

XERCES_CPP_NAMESPACE_USE

using namespace std;
using namespace JDF;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

/**
*  a simple generic main routine for a dumb console app
*
*  switches:
* 
*/

///////////////////////////////////////////////////////////////////

int AppendCommand(const WString& command, JDFDoc d){
	if(command.empty())
		return 0;

	int iMess=0;
	JDFJMF jmf=d.GetJMFRoot();
	
	if(command=="HoldQueue"){
		iMess++;
		jmf.AppendCommand(JDFCommand::Type_HoldQueue);
	}
	if(command=="ResumeQueue"){
		iMess++;
		jmf.AppendCommand(JDFCommand::Type_ResumeQueue);
	}
	if(command=="SubmitQueueEntry"){
		iMess++;
		JDFCommand c=jmf.AppendCommand(JDFCommand::Type_SubmitQueueEntry);
		JDFQueueSubmissionParams qsp=c.AppendQueueSubmissionParams();
		qsp.SetURL("file:///test.jdf");


	}
	return iMess;

}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

int AppendQuery(const WString& query, JDFDoc d){
	if(query.empty())
		return 0;

	int iMess=0;
	JDFJMF jmf=d.GetJMFRoot();
	
	if(query=="KnownMessages"){
		iMess++;
		jmf.AppendQuery(JDF::JDFQuery::Type_KnownMessages);
	}
	if(query=="KnownDevices"){
		iMess++;
		jmf.AppendQuery(JDF::JDFQuery::Type_KnownDevices);
	}
	return iMess;

}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

int AppendSignal(const WString& signal, JDFDoc d){
	if(signal.empty())
		return 0;

	int iMess=0;
	JDFJMF jmf=d.GetJMFRoot();
	
	if(signal=="KnownMessages"){
		iMess++;
		jmf.AppendSignal(JDFSignal::Type_KnownMessages);
	}
	return iMess;

}

///////////////////////////////////////////////////////////////////
int main(int argC, char* argV[]){
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}
	
	// trivial argument handling
	MyArgs args(argC,argV,"","chiIlnopqsu");
	
	// Watch for special case help request
	WString usage="JDFMessenger; example usages of the JDF Library for sending messages.\nArguments: -u: URL to send to \n";
	usage.append("-i input xml file to send; if -i is specified no other switches except\n");
	usage.append("-I file name where a copy of the sent message is to be stored\n");
	usage.append("-u are processed.\n-c command type to send\n-q query type to send\n-s signal type to send\n-l location of the schema\n-n number of repititions <1>\n -o output file name");
	usage.append("\n-h proxy host name\n-p proxy port name\n");
	if ((argC>1)&&(strcmp(argV[1], "-?") == 0)){
		cerr<< args.Usage(usage);
		return 1;
	}
	bool bValidate=false;
	KString schemaLocation=args.ParameterString('l').c_str();
	if(!schemaLocation.empty()){
		schemaLocation="http://www.CIP4.org/JDFSchema_1_1 "+schemaLocation;
		bValidate=true;

	}
	WString proxyHost = args.ParameterString('h');
	WString proxyPort = args.ParameterString('p');
	if(!proxyHost.empty()){
		JDF::PlatformUtils::setProperty("http.proxyHost",proxyHost);
		if(proxyPort.empty())
			proxyPort=L"8080";
		JDF::PlatformUtils::setProperty("http.proxyPort",proxyPort);
	}


	WString URL=args.ParameterString('u');
	if(URL.empty()){
		cerr<<"URL is required: supply -u parameter\n"<<args.Usage(usage);
		return 1;
	}

	WString inFile=args.ParameterString('i');

	{
		
		JDFDoc messageDoc(1);
		int msgs=0;
		
		if(inFile.empty()){
			JDFJMF jmf=messageDoc.GetJMFRoot();
			jmf.init();
			jmf.SetSenderID(L"CIP4JDFMessengerTestApp");
			
			WString command=args.ParameterString('c');
			msgs+=AppendCommand(command,messageDoc);
			
			WString query=args.ParameterString('q');
			msgs+=AppendQuery(query,messageDoc);
			
			WString signal=args.ParameterString('s');
			msgs+=AppendSignal(signal,messageDoc);
		}else{
			try{
				if(messageDoc.Parse(inFile.c_str(),true,true,true,0,schemaLocation.c_str()))
				msgs=1;
			}catch(JDFException x){
				cout <<"error parsing :"+inFile<<endl;
			}
		}
		int nReps=args.IntParameter('n',1);
		
		WString outFile=args.ParameterString('o');
		WString inCopyFile=args.ParameterString('I');
		if(!inCopyFile.empty()){
			messageDoc.Write2File(inCopyFile);
		}
		if(msgs){
			for(int i=0;i<nReps;i++){
				JDFDoc response;
				try{
					response=messageDoc.Write2URL(URL,schemaLocation);
				}catch(JDFException x){
					cout<<"error writing to :"+URL<<endl;
					cout<<x.getMessage()<<endl;
					continue;
				}
				if(outFile.empty()){
					cout<<response<<endl;
				}else{
					if(i){
						response.Write2File(outFile+L'_'+WString::valueOf(i));
					}else{
						response.Write2File(outFile);
					}
				}
			}
		}else{		
			cerr<<"One of Command, Query or Signal is required: supply -c, -q and/or -s parameter\n"<<args.Usage(usage);
		}

	}


	JDF::PlatformUtils::Terminate();
	return 0;
}

