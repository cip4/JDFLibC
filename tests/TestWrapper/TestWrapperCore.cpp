//#define _STLP_USE_NEW_IOSTREAMS 1
//#include "windows.h"

#include "jdf/WrapperCore/XMLDoc.h"
#include "jdf/Wrapper/JDFNumTypeList.h"
#include "jdf/Wrapper/JDFNumberRangeList.h"
#include <jdf/util/PlatformUtils.h>
#include <jdf/WrapperCore/StringUtil.h>
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
	if(false)
	{
		cout<<StringUtil::urlToFile("file://foo€Bar%20/44%e2%82%ac.txt");
		assertEquals(StringUtil::urlToFile("file://foo€Bar%20/44%e2%82%ac.txt"), "//foo€Bar /44€.txt");
		cout<<endl<<StringUtil::fileToUrl("//foo€Bar /44€.txt",true);
		assertEquals(StringUtil::fileToUrl("\\foo€Bar \\44€.txt",true).toUpperCase(),WString(L"file:/foo%e2%82%acBar%20/44%e2%82%ac.txt").toUpperCase());
		cout<<endl<<StringUtil::urlToFile("file:/gr%fcn.txt");
		assertEquals(StringUtil::urlToFile("file://gr%fcn.txt").toUpperCase(),WString(L"/grün.txt").toUpperCase());

	}
	else if(false)
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
		char buf[2];
		buf[1]=0;
		XMLDoc doc("abc");
		for(int i=0;i<255;i++)
		{
			*buf=(char)i;
			KElement e=doc.GetRoot();
			e.SetAttribute(WString(L"a")+i,WString(buf));
			XMLDoc doc2("abc");
			KElement e2=doc2.GetRoot();
			e2.SetAttribute(WString(L"a")+i,WString(buf));
			WString w;
			doc2.Write2String(w);
			JDFParser p;
			bool b=p.StringParse(w);
			XMLDoc d3=p.GetRoot();
			if(strchr(w.GetUTF8Bytes(),i))
				cout<<" found "<<" "<<hex<<i<<dec<<" "<<w<<strlen(WString(buf).GetUTF8Bytes())<<endl;
			if(!b || d3.isNull())
				cout<<" failed "<<b<<" "<<i<<endl;

		}
		doc.Write2File("chars.xml");
	}

	JDF::PlatformUtils::Terminate();
	cout<<"end"<<endl;
	return 0;
}

