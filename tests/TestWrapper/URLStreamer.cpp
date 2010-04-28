#include <jdf/util/PlatformUtils.h>

#include "JDFSimulator.h"
#include <xercesc/util/PlatformUtils.hpp>

#include <jdf/net/URLConnection.h>
#include <jdf/net/HttpURLConnection.h>
#include <jdf/net/HttpClient.h>

#include <jdf/io/FileInputStream.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/BufferedOutputStream.h>
#include <jdf/io/File.h>

#include "MyArgs.h"
#include <iostream>

XERCES_CPP_NAMESPACE_USE

using namespace std;
using namespace JDF;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

int main(int argC, char* argV[]){
	// Initialize the JDFTools system
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return 1;
	}

	// trivial argument handling
	MyArgs args(argC,argV,"v","fhiprtu");

	// Watch for special case help request
	WString usage="URLStreamer; Send a file stream to a URL\nArguments:\n";
	usage.append("-u: url to send to \n");
	usage.append("-f: File to be opaquely sent\n");
	usage.append("-t: content type of the file to be sent (default=text/plain);\n");
	usage.append("-r: output file name\n");
	usage.append("-h: proxy host name\n-p: proxy port name\n");
	usage.append("-v: flag for verbose output\n");
	if ((argC>1)&&(strcmp(argV[1], "-?") == 0)){
		cerr<< args.Usage(usage);
		return 1;
	}
	bool bVerbose=args.BoolParameter('v');
	WString proxyHost = args.ParameterString('h');
	WString proxyPort = args.ParameterString('p');
	WString contentType = args.ParameterString('t');
	if(contentType.empty())
		contentType="text/plain";

	if(!proxyHost.empty()){
		JDF::PlatformUtils::setProperty("http.proxyHost",proxyHost);
		if(proxyPort.empty())
			proxyPort=L"8080";
		JDF::PlatformUtils::setProperty("http.proxyPort",proxyPort);
	}


	WString url=args.ParameterString('u');
	if(url.empty()){
		cerr<<"url is required: supply -u parameter\n"<<args.Usage(usage);
		return 1;
	}
	URL theURL;
	try
	{
		theURL=url;
	}
	catch(MalformedURLException x)
	{
		cerr<<"Malformed url: "<<url<<std::endl;
		return 1;
	}

	WString file=args.ParameterString('f');
	if(file.empty())
	{
		cerr<<"Input File is required: "<<std::endl;
		return 1;
	}

	File f(file);
	if(!f.canRead())
	{
		cerr<<L"cannot read file: "+file;
		return -1;
	}
	FileInputStream fis(f);
	URLConnection* pURLConnection=theURL.openConnection();


	pURLConnection->setDoOutput(true);
	pURLConnection->setRequestProperty(L"Connection", L"keep-alive" );
	pURLConnection->setRequestProperty(L"Content-Type", contentType);
	BufferedOutputStream os(pURLConnection->getOutputStream());
	int n=0;
	while(true)
	{
		int b=fis.read();
		if(b==-1)
		{
			os.flush();
			os.close();
			break;
		}
		os.write(b);
		n++;
	}
	if(bVerbose)
		std::cout<<"bytes read from file: "<<n<<std::endl;
	InputStream& urlIS=pURLConnection->getInputStream();

	WString outFile=args.ParameterString('r');
	if(!outFile.empty())
	{
		n=0;
		File of(outFile);
		if(bVerbose)
			cout<<"Writing to file: "<<of.getAbsolutePath()<<endl;
		of.remove();
		of.createNewFile();
		if(of.canWrite())
		{
			FileOutputStream fos2(of);
			BufferedOutputStream os2(fos2);
			while(true)
			{
				int b=urlIS.read();
				if(b==-1)
				{
					os2.flush();
					os2.close();
					break;
				}
				os2.write(b);
				n++;
			}
			if(bVerbose)
				std::cout<<"bytes read from URL: "<<n<<std::endl;

		}
	}


	JDF::PlatformUtils::Terminate();
	return 0;
}

