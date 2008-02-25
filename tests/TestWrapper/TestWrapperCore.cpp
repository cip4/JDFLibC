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

//#include "DebugTrace.h"
#include <iterator>
//#include <stl/_limits.h>
using namespace std;
#include <wchar.h>
#include<io.h>
#include "MyTime.h"
#include "jdf/Wrappercore/StringUtil.h"


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
	{

			WString ww(1.0);
		cout<<ww<<endl;
			WString ww2(0.9999999999);
			WString ww3(1.0000000001);
		cout<<ww2<<endl<<ww3<<endl;
		cout <<StringUtil::formatDouble(0.9999999999)<<endl;
	}

	JDF::PlatformUtils::Terminate();

	return 0;
}

