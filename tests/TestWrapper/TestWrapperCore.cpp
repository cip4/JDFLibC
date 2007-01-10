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

//#include "DebugTrace.h"
#include <iterator>
//#include <stl/_limits.h>
using namespace std;
#include <wchar.h>
#include<io.h>
	#include "MyTime.h"


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
	if(0){
WString sss111(L"abc");
JDFDate dt = JDFDate( "1975-01-01T20:00:10+00:00" ); 
		WString str0 = dt.DateTimeISO(); 
		cout<<str0.peekBytes()<<endl; 
		dt = JDFDate( "1975-01-01T20:00:10Z" ); 
		cout<<str0.peekBytes()<<endl; 
		dt.AddTime( 0, 0, 10 ); 
		WString str1 = dt.DateTimeISO(); 
		cout<<str1<<endl;
		return 0;

		XMLDoc doc;
		doc.Parse("unicode.xml");
		WString sss;
		doc.Write2String(sss);
		

		const char* foo=sss.GetUTF8Bytes();
		const char* snafu=sss.getBytes();
		FILE* ff=fopen("fileout.xml","w+");
		fwrite(foo,strlen(foo),1,ff);
		fclose(ff);
		ff=fopen("filesnafu.xml","w+");
		fwrite(snafu,strlen(snafu),1,ff);
		fclose(ff);

		WString sss2;
		sss2.SetUTF8Bytes(foo);

		XMLDoc doc2;
		doc2.StringParse(sss2);

		cout<<"1"<<doc;
		KElement e=doc2.GetRoot();
		WString s=e.GetXPathAttribute("./Response/Queue/QueueEntry/@DescriptiveName");
		s=s+"_ö_"+s;

		e.SetXPathAttribute("./Response/Queue/QueueEntry/@DescriptiveName2",s);
		JDFCh xc[1001];
		xc[1000]=0;
		for(int i=0;i<1000;i++)
			xc[i]=1000+37*i;
		e.SetText(WString(xc));
		doc2.Write2File("philp_out.jmf");
		XMLDoc doc3;
		doc3.Parse("philp_out.jmf");
		doc2.Write2File("philp_out2.jmf");

		doc2.Write2String(sss);


		const char* foo2=sss.GetUTF8Bytes();
		const char* snafu2=sss.getBytes();
		FILE* ff2=fopen("fileout2.xml","w+");
		fwrite(foo2,strlen(foo2),1,ff);
		fclose(ff2);
		ff2=fopen("filesnafu2.xml","w+");
		fwrite(snafu2,strlen(snafu2),1,ff2);
		fclose(ff2);

		sss2.SetUTF8Bytes(snafu);
		doc2.StringParse(sss2);
		doc2.Write2File("philp_out_snafu.jmf");
		doc3.Parse("philp_out_snafu.jmf");

	}
	else if(1)
	{
		XMLDoc d1("x1");
		KElement e=d1.GetRoot();
		XMLDoc d2("x2");
		KElement e2=d2.GetRoot();
		KElement foo=e2.AppendElement("foo:bar");
		cout<<foo.getPrefixLength()<<endl;
		foo.SetAttribute("foo:at","42");
		cout<<foo.GetAttribute("at")<<" | "<<foo.GetAttribute("foo:at")<<endl;

		foo.ReplaceElement(e);
		e.SetAttribute("foo:at","42");
		cout<<e.GetAttribute("at")<<" | "<<e.GetAttribute("foo:at")<<endl;

		cout<<d2<<endl;
		cout<<e2<<endl;
		cout<<foo<<endl;
		VoidSet vs;
		vs.add((void*)4);
		cout<<4<<vs.contains((void*)4)<<5<<vs.contains((void*)5)<<endl;
		vs.resetIterator();
		while (vs.hasNext())
			cout<<vs.next()<<endl;
		SetWString ss;
		ss.add("a");
		ss.add("b");
		ss.add("a");
		ss.resetIterator();
		cout<<"a"<<ss.contains("a")<<"d"<<ss.contains("d")<<endl;
		while (ss.hasNext())
			cout<<ss.next()<<endl;


	}
	else if(0)
	{

		XMLDoc::setDefaultIgnoreNS(true);
		XMLDoc doc;
		doc.Parse(L"C:\\local\\bin\\foo.xml",false,true,false);
		KElement ManufacturingCapabilities=doc.GetRoot().GetElement("Response").GetElement("ManufacturingCapabilities");
		ManufacturingCapabilities.SetAttribute("newAtt","wattAuchImmer");
		JDF::XMLDoc CapXmlDoc("ManufacturingCapabilities");
		KElement RootElement = CapXmlDoc.GetRoot();
		
		RootElement.ReplaceElement(ManufacturingCapabilities);
		cout<<"xmlns= "<<RootElement.GetAttribute("xmlns")<<endl;
		cout<<"xmlns2= "<<RootElement.GetNamespaceURI()<<endl;
		RootElement.RemoveAttribute("xmlns",KElement::atr_xmlnsURI);
		cout<<"xmlns= "<<RootElement.GetAttribute("xmlns")<<endl;
		cout<<"xmlns2= "<<RootElement.GetNamespaceURI()<<endl;
		CapXmlDoc.Write2File("C:\\local\\bin\\foo2.xml");

	}else if(0){
		for(int kkk=0;kkk<100;kkk++){
			XMLDoc doc2;
			XMLDoc doc21;
			XMLDoc doc22;
			JDFParser p;
			doc2.Parse(L"C:\\local\\bin\\sb.jdf",false);
			p.Parse(L"C:\\local\\bin\\sb.jdf",false);
			WString w=doc2.GetRoot().GetXPathAttribute("ResourcePool/RunList/RunList/LayoutElement/FileSpec/@URL");
			wcout<<doc2.GetRoot().GetLocalName()<<endl<<w<<endl;
			cout<<w<<endl;
			WString  w2=w.UnEscape(L'%',16,2);
			cout<<1<<w.GetUTF8Bytes()<<endl;
			cout<<2<<w2.GetUTF8Bytes()<<endl;
			cout<<3<<w2<<endl;
			KElement e=doc2.GetRoot().GetXPathElement("ResourcePool/RunList/RunList/LayoutElement/FileSpec");
			cout<<e<<endl;
			doc21=doc2;
			doc22=p.GetRoot();
		}
	}else if(0){
		for(int i=0;i<1;i++){
			for (wchar_t c=L'a';c<L'e';c++){
				WString w="p"+WString(i);
				if(c!=L'd')
					w+=c;
				w+=L".jdf";
				if(!_access(w.peekBytes(),0)){
					XMLDoc d;
					cout<<w<<endl;
					d.Parse(w,false);
					d.Write2File("_"+w);
				}
			}
		}

	}else{
		
		WString s="ÄÖÜ%20grüün";
		if(s=="ÄÖÜgrüün")
			cout <<"yuhu"<<endl;
		const char*pu=s.GetUTF8Bytes();
		WString s2;
		s2.SetUTF8Bytes(pu);
		cout<<s2<<endl;
		if(s2=="ÄÖÜgrüün")
			cout <<"yuhu"<<endl;
		WString s3=s2.GetUTF8String();
		s3=s3.UnEscape(L'%',16,2);
		WString s4;
		s4.SetUTF8String(s3);
			cout <<s4<<endl;

		return 0;

		WString * www[70000];
		MyDate md("T19:30:30A");
		cout<<endl<<md.DateTimeISO()<<endl;
		md=L"2000-01-01";
		cout<<endl<<md.DateTimeISO()<<endl;
		md=L"2000-01-01T19:30:30X";
		cout<<endl<<md.DateTimeISO()<<endl;
		JDFShape fs(1,2,3);
		JDFShape fs2;
		fs2=fs;
		
		
		int i;
		for(i=0;i<10;i++){
			XMLDoc doc("newEnvelope");
			KElement e=doc.GetRoot();
			KElement e1=e.AppendElement("e1");
			e1=e.AppendElement("e1");

			doc=doc;
			doc=XMLDoc("dw2");
			//		cout<<e<<endl;
			KElement r=doc.GetRoot();
			for(int j=0;j<100;j++){
			JDFXYPair xyp;
			JDFNumberRangeList nrl;
			nrl=L"1.2 2.0 3~4 3.0000001~4.0";
			KElement e=r.AppendElement("ElementWithBigLongName"+WString(j));
			
			xyp.SetX(22);
			e.SetAttribute("xyp",xyp);
			e.SetAttribute("nrl",nrl.GetString());
			e.AppendText("1 a\n");
			e.RemoveAttribute("schnarch");
			e.AppendText(" 2  a\n");
			e.AppendText("\t3   a\n");
			e.AppendText("\n 1\n 2\n 3\n 4\n 5\n \n \n 6\n");
			e.AppendText("\n  \n  \n  \n  44\n  \n \n \n  \n");
			}
			doc.Write2File(L"C:\\local\\bin\\snafu"+WString(i)+L".jdf");
			XMLDoc doc2;
			doc2.Parse(L"C:\\local\\bin\\snafu"+WString(i)+L".jdf",false);
			doc2.Write2File(L"C:\\local\\bin\\snafu_"+WString(i)+L".jdf");
			
		}
		
		for(int j=0;j<10;j++){
			cout<<j<<endl;
			for(int i=0;i<10;i++){
				XMLDoc doc;
				if(!doc.Parse(L"C:\\local\\bin\\snafu"+WString(i)+L".jdf",false))
					cout << i<<" "<<j<<" snafu!"<<endl;
				
			}
		}
		
		
	}
	JDF::PlatformUtils::Terminate();
	
	
	return 0;
}

