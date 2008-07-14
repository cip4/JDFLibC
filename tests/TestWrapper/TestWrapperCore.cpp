//#define _STLP_USE_NEW_IOSTREAMS 1
//#include "windows.h"

#include "jdf/WrapperCore/XMLDoc.h"
#include "jdf/Wrapper/JDFNumTypeList.h"
#include "jdf/Wrapper/JDFNumberRangeList.h"
#include <jdf/util/PlatformUtils.h>
#include <xercesc/util/PlatformUtils.hpp>
#include "jdf/WrapperCore/KElement.h"
#include "jdf/lang/Exception.h"
#include "jdf/lang/VoidSet.h"
#include "jdf/lang/SetWString.h"
#include <iostream>
#include "jdf/WrapperCore/MyDate.h"
#include <jdf/WrapperCore/JDFParser.h> 
#include <jdf/WrapperCore/XMLDocUserData.h>
#include <jdf/mime/MIMEMessage.h>
#include <jdf/io/FileOutputStream.h>
#include <jdf/io/File.h>
#include <jdf/net/URI.h>

//#include "DebugTrace.h"
#include <iterator>
//#include <stl/_limits.h>
using namespace std;
#include <wchar.h>
#include<io.h>
#include "MyTime.h"
#include "jdf/Wrappercore/StringUtil.h"
#define assertEquals(a,b)if(a!=b)cout<<"bad\n"<<a<<endl<<b;
#define assertTrue(a)if(!a)cout<<"bad True\n"<<a<<endl;
#define assertFalse(a)if(a)cout<<"bad False\n"<<a<<endl;


using namespace JDF;

XERCES_CPP_NAMESPACE_USE



int main(int argc, char* argv[]){
	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		cout<<"oops"<<endl;
		return 1;
	}

	MyTime t("total");
	// these braces are important due to scoping of doc and terminate...
	if(!false)
	{
		File dir(L"//KIE-PROSIRAI-LG/gimmedat/FileDir");
		assertTrue(dir.mkdir());
		XMLDoc d("foobar");
		KElement e=d.GetRoot();
		for(int j=0;j<100000;j++)
		{
			cout<<j<<" ";
			for(int i=0;i<100;i++)
			{
				cout<<".";
				e.AppendElement(WString("bar")+i);
				File file(dir,WString("File")+i+".txt");
				file.remove();
				assertTrue(file.createNewFile());
				if(!d.Write2File(file))
				{
					cout<<" ---  snafu! "<<endl;
					return 1;
				}
			}
		cout<<endl;
		}
	}
	else
	{

		XMLDoc doc("abc");
		for(int i=0;i<2;i++)
		{
			try
			{
				doc.Write2File(0);
				doc.Write2URL("http://aa");
			}
			catch(...)
			{
				cout<<"cot"<<i<<endl;
			}
		}
		doc.StringParse("<a/>");
		cout<<doc<<endl;
		try
		{
			doc.StringParse("<a");
		}
		catch(...)
		{
			cout<<"cotttt"<<endl;

		}
		WString s="abc";
		assertTrue(s.matches("abc"));
		assertFalse(s.matches("ab"));
		assertFalse(s.matches("c"));
		assertFalse(s.matches("(.)?"));
		assertTrue(s.matches("ab(.)?"));
	}

	JDF::PlatformUtils::Terminate();
	cout<<"end"<<endl;
	return 0;
}

