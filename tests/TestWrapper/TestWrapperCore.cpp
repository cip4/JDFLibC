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
	if(false)
	{

        XMLDoc  jdfDoc("JDF");
        KElement root   = jdfDoc.GetRoot();

        root.SetXPathAttribute("/JDF/a[2]/@foo", "v2");
		cout<<root<<endl;
        root.SetXPathAttribute("/JDF/a[3]/@foo", "v3");
		cout<<root<<endl;
		root.AppendElement("AuditPool").AppendElement("Created");
        assertEquals(root.GetXPathElement("/JDF/a[2]"), root.GetXPathElement("/JDF/a[@foo=\"v2\"]"));
        assertEquals(root.GetXPathElement("/JDF/a[3]"), root.GetXPathElement("/JDF/a[@foo=\"v3\"]"));

        WString nodeName = "Created";
        KElement kElem = root.GetXPathElement("AuditPool/"+nodeName);
        assertEquals(kElem.GetNodeName(),nodeName);
        assertTrue(kElem.matchesPath("Created",false));
        assertTrue(kElem.matchesPath("/JDF/AuditPool/Created",false));
        assertTrue(kElem.matchesPath("JDF/AuditPool/Created",false));
        assertFalse(kElem.matchesPath("/Created",false));

        nodeName = "notFound";
        kElem    = root.GetXPathElement("AuditPool/"+nodeName);
        XMLDoc d2("doc","");
        KElement root2=d2.GetRoot();
        for(int i=0;i<10;i++)
        {
            KElement e=root2.AppendElement("e");
            assertEquals(root2.GetXPathElement(WString("e[")+(i+1)+"]"), e);
            assertEquals(root2, e.GetXPathElement("../"));
            assertEquals(root2, e.GetXPathElement(".."));
            assertEquals(root2, e.GetXPathElement(".././."));
        }
        KElement e=root2.GetCreateElement("foo.bar");
        assertEquals(e.GetNodeName(), "foo.bar");
        assertEquals(root2.GetXPathElement("foo.bar"), e);
        assertEquals(root2.GetCreateXPathElement("foo.bar"), e);
        root.SetXPathAttribute("/JDF/ee[2]/@a", "2");
        root.SetXPathAttribute("/JDF/ee[1]/@a", "2");
        root.SetXPathAttribute("/JDF/ee[2]/ff/@b", "3");
        assertEquals(root.GetXPathAttribute("/JDF/ee/ff/@b"), "3");
        assertEquals(root.GetXPathAttribute("/JDF/ee[@a=\"2\"]/ff/@b"), "3");
        assertEquals(root.GetXPathAttribute("//ee[@a=\"2\"]/ff/@b"), "3");
        assertEquals(root.GetXPathAttribute("/JDF/ee[1]/ff/@b"),"");	
	}
	else
	{
		
		File f("\\\\abs\\foo\\abc.dir");
		cout <<f.toURI().toString()<<endl;
		File f2("\\\\kie-prosirai-lg\\gimmedat\\abc.dir");
		cout <<f2.toURI().toString()<<endl;
		return 0;


		WString s="abc";
		assertTrue(s.matches("abc"));
		assertFalse(s.matches("ab"));
		assertFalse(s.matches("c"));
		assertFalse(s.matches("(.)?"));
		assertTrue(s.matches("ab(.)?"));
	}

	JDF::PlatformUtils::Terminate();

	return 0;
}

