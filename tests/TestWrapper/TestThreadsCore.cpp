#include <iostream>
#include <process.h>
#include <time.h>
#include <windows.h>
#include "jdf/WrapperCore/KElement.h"
#include "jdf/WrapperCore/XMLDoc.h"
#include "jdf/lang/Exception.h"
#include <jdf/util/PlatformUtils.h>
#include <jdf/io/File.h>

using namespace std;

unsigned __stdcall threadproc1 (void* p);
unsigned __stdcall threadproc2 (void* p);
unsigned __stdcall threadproc3 (void* p);
unsigned __stdcall threadproc4 (void* p);

#define assertEquals(a,b)if(a!=b)cout<<"bad\n"<<a<<endl<<b;
#define assertTrue(a)if(!a)cout<<"bad True\n"<<a<<endl;
#define assertFalse(a)if(a)cout<<"bad False\n"<<a<<endl;


using namespace JDF;

KElement eee;

void main()
{
	unsigned threadID;
	unsigned long threadHandle;

	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return;
	}
	XMLDoc d("ABC");
	eee=d.GetRoot();
	cout<<eee;
	int stat1 = 0;
	threadHandle = _beginthreadex (NULL, 0, threadproc1, (void*) &stat1, 0, &threadID);

	if (threadHandle == 0)
	{
		cout << "error starting thread1" << endl;
		stat1 = -1;
	}

	int stat2 = 0;
	threadHandle = _beginthreadex (NULL, 0, threadproc2, (void*) &stat2, 0, &threadID);

	if (threadHandle == 0)
	{
		cout << "error starting thread2" << endl;
		stat2 = -1;
	}

	int stat3 = 0;
	threadHandle = _beginthreadex (NULL, 0, threadproc3, (void*) &stat3, 0, &threadID);

	if (threadHandle == 0)
	{
		cout << "error starting thread3" << endl;
		stat3 = -1;
	}

	int stat4 = 0;
	threadHandle = _beginthreadex (NULL, 0, threadproc4, (void*) &stat4, 0, &threadID);

	if (threadHandle == 0)
	{
		cout << "error starting thread4" << endl;
		stat4 = -1;
	}

	while (stat1 == 0 || stat2 == 0 || stat3 == 0 || stat4 == 0)
	{
		Sleep(500);
	}

	JDF::PlatformUtils::Terminate();
	cout << "alles klar" << endl;
}



unsigned __stdcall threadproc11 (void* p)
{
	int* pi = (int*) p;

	time_t duration = 10;   // wait 60 seconds on Engine init

	time_t start_time, current_time;
	time (&start_time);

	current_time = start_time;
	cout<<11<<endl;
	mAttribute mp;
	while (current_time - start_time <= duration)
	{
		for(int i=0;i<10;i++){
			WString w=L"a"+WString(i);;
			w=L"b"+WString(i);;
			mp.AddPair("A1","1");
			mp.AddPair("B1","2");
			mp.AddPair("B1","3");
			WString::GetUID();

			for(int j=0;j<100;j++){
				XMLDoc doc;
				if(!doc.Parse(L"D:\\local\\bin\\snafu"+WString(i)+L".jdf",false))
					cout << i<<" "<<j<<" snafu!"<<endl;
				XMLDoc d2=eee.GetOwnerDocument();
				WString * www[70000];
				int ii;
				for(ii=0;ii<300;ii++)
					www[ii]=new WString(WString::star);
				for(ii=00;ii<300;ii++){
					delete www[ii];
				}
				cout<<i<<" A "<<WString::star<<endl;

			}
			time (&current_time);
		}
	}

	cout<<12<<mp<<endl;
	*pi = 1;

	_endthreadex(0);
	return 0;
}



unsigned __stdcall threadproc22(void* p)
{
	int* pi = (int*) p;

	time_t duration = 10;   // wait 60 seconds on Engine init

	time_t start_time, current_time;
	time (&start_time);

	current_time = start_time;
	cout<<21<<endl;

	while (current_time - start_time <= duration)
	{
		int i=0;
		for(i=0;i<10;i++){
			WString w=L"a"+WString(i);;
			w=L"b"+WString::star;;
			mAttribute mp;
			mp.AddPair("A2","1");
			mp.AddPair("B2","2");
			mp.AddPair("B2","3");
			WString::GetUID();
			for(int j=0;j<100;j++){
				XMLDoc doc;
				if(!doc.Parse(L"D:\\local\\bin\\snafu"+WString(i+10)+L".jdf",false))
					cout << i<<" "<<j<<" snafu!"<<endl;
				XMLDoc d2=eee.GetOwnerDocument();
				WString * www[70000];
				int ii;
				for(ii=0;ii<300;ii++)
					www[ii]=new WString(WString::star);
				for(ii=00;ii<300;ii++){
					delete www[ii];
				}
				cout<<i<<" B "<<WString::star<<endl;

			}
		}
		time (&current_time);
		cout<<i<<" B "<<WString::star<<endl;
	}
	*pi = 1;
	cout<<22<<endl<<WString::star<<endl;

	_endthreadex(0);
	return 0; 
}



unsigned __stdcall threadproc3 (void* p)
{
	int* pi = (int*) p;

	time_t duration = 10;   // wait 60 seconds on Engine init

	time_t start_time, current_time;
	time (&start_time);

	current_time = start_time;
	cout<<41<<endl;

	File dir(L"//KIE-PROSIRAI-LG/gimmedat/FileDir");
	assertTrue(dir.mkdir());
	XMLDoc d("foobar");
	KElement e=d.GetRoot();
	for(int j=0;j<100000;j++)
	{
		cout<<"3 "<<j<<" ";
		for(int i=0;i<100;i++)
		{
			cout<<".";
			for(int j=0;j<1;j++)
				e.AppendElement(WString("bar")+i+100*j);
			e.AppendElement(WString("bar")+i);
			File file(dir,(WString("File")+*pi)+"_3_"+i+".txt");
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
	cout<<42<<endl;

	*pi = 1;

	_endthreadex(0);
	return 0;
}

unsigned __stdcall threadproc2 (void* p)
{
	int* pi = (int*) p;

	time_t duration = 10;   // wait 60 seconds on Engine init

	time_t start_time, current_time;
	time (&start_time);

	current_time = start_time;
	cout<<41<<endl;

	File dir(L"//KIE-PROSIRAI-LG/gimmedat/FileDir");
	assertTrue(dir.mkdir());
	XMLDoc d("foobar");
	KElement e=d.GetRoot();
	for(int j=0;j<100000;j++)
	{
		cout<<"2 "<<j<<" ";
		for(int i=0;i<100;i++)
		{
			cout<<".";
			for(int j=0;j<1;j++)
				e.AppendElement(WString("bar")+i+100*j);
			File file(dir,(WString("File")+*pi)+"_2_"+i+".txt");
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
	cout<<42<<endl;

	*pi = 1;

	_endthreadex(0);
	return 0;
}

unsigned __stdcall threadproc4 (void* p)
{
	int* pi = (int*) p;

	time_t duration = 10;   // wait 60 seconds on Engine init

	time_t start_time, current_time;
	time (&start_time);

	current_time = start_time;
	cout<<41<<endl;

	File dir(L"//KIE-PROSIRAI-LG/gimmedat/FileDir");
	assertTrue(dir.mkdir());
	XMLDoc d("foobar");
	KElement e=d.GetRoot();
	for(int j=0;j<100000;j++)
	{
		cout<<"4 "<<j<<" ";
		for(int i=0;i<100;i++)
		{
			cout<<".";
			for(int j=0;j<1;j++)
				e.AppendElement(WString("bar")+i+100*j);
			File file(dir,(WString("File")+*pi)+"_4_"+i+".txt");
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
	cout<<42<<endl;

	*pi = 1;

	_endthreadex(0);
	return 0;
}

unsigned __stdcall threadproc1 (void* p)
{
	int* pi = (int*) p;

	time_t duration = 10;   // wait 60 seconds on Engine init

	time_t start_time, current_time;
	time (&start_time);

	current_time = start_time;
	cout<<41<<endl;

	File dir(L"//KIE-PROSIRAI-LG/gimmedat/FileDir");
	assertTrue(dir.mkdir());
	XMLDoc d("foobar");
	KElement e=d.GetRoot();
	for(int j=0;j<100000;j++)
	{
		cout<<"1 "<<j<<" ";
		for(int i=0;i<100;i++)
		{
			cout<<".";
			for(int j=0;j<1;j++)
				e.AppendElement(WString("bar")+i+100*j);
			File file(dir,(WString("File")+*pi)+"_1_"+i+".txt");
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
	cout<<42<<endl;

	*pi = 1;

	_endthreadex(0);
	return 0;
}
