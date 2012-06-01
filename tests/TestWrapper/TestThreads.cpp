#include <iostream>
#include <process.h>
#include <time.h>
#include <windows.h>
#include <jdf/wrapper/JDF.h>
#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Mutex.h>
#include <jdf/lang/Synchronized.h>

using namespace std;

unsigned __stdcall threadproc1 (void* p);
unsigned __stdcall threadproc2 (void* p);
unsigned __stdcall threadproc3 (void* p);
unsigned __stdcall threadproc4 (void* p);


using namespace JDF;
	Mutex* mutex;
	Mutex* mutex2;

void main()
{
    unsigned threadID;
    unsigned long threadHandle;

	try	{
		JDF::PlatformUtils::Initialize();
	} catch (const JDF::Exception&)	{
		return;
	}
	mutex=new Mutex();
//	mutex2=new Mutex();
	mutex2=mutex;

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



unsigned __stdcall threadproc1 (void* p)
{
	{
	Synchronized sync(*mutex);
    int* pi = (int*) p;
    time_t duration = 10;   // wait 60 seconds on Engine init

    time_t start_time, current_time;
    time (&start_time);

    current_time = start_time;
	JDFDoc d;
	d.Parse("c:\\data\\JDF\\spawn.jdf",false);    
		JDFNode n=d.GetJDFRoot();
		JDFResource rl=n.GetXPathElement("ResourcePool/NodeInfo");	
		cout<<rl.GetPartIDKeys()<<rl<<endl;
	cout<<11<<endl;
	while (current_time - start_time <= duration)
    {
		WString w="aa,*,ab,bc,*";
		int j=0;
		for(int i=0;i<100;i++){
//			d.GetJDFRoot().UpDaterRefs();
			j+=1+w.PosOfToken(WString::star,WString::comma);
			WString www=WString::star+L"_"+WString::star+"_";
			www+=WString(42)+WString('b');
			delete(WString::star.getBytes());
		}
		cout<<10<<current_time - start_time<<" "<<WString::star<<" "<<j<<endl;
        time (&current_time);
        time (&current_time);
    }

    cout<<12<<endl;
    *pi = 1;
	}
    _endthreadex(0);
    return 0;
}



unsigned __stdcall threadproc2 (void* p)
{
	{
	Synchronized sync(*mutex);
    int* pi = (int*) p;

    time_t duration = 10;   // wait 60 seconds on Engine init

    time_t start_time, current_time;
    time (&start_time);

    current_time = start_time;
	JDFDoc d;
	d.Parse("c:\\data\\JDF\\spawn.jdf",false);    
 		JDFNode n=d.GetJDFRoot();
		JDFResource rl=n.GetXPathElement("ResourcePool/NodeInfo");	
		cout<<rl.GetPartIDKeys()<<rl<<endl;
   cout<<21<<endl;

		WString w="aa,*,ab,bc,*";
		int j=0;
    while (current_time - start_time <= duration)
    {
		for(int i=0;i<100;i++){
//			d.GetJDFRoot().UpDaterRefs();
					j+=1+w.PosOfToken(WString::star,WString::comma);
			WString www=WString::star+L"_"+WString::star+"_";
			www+=WString(42)+WString('b');
			delete(WString::star.getBytes());
		}
	    cout<<20<<current_time - start_time<<" "<<WString::star<<" "<<j<<endl;
        time (&current_time);
        time (&current_time);
    }

    *pi = 1;
    cout<<22<<endl;
	}
    _endthreadex(0);
    return 0;
}



unsigned __stdcall threadproc3 (void* p)
{
	{
	Synchronized sync(*mutex2);
	
    int* pi = (int*) p;

    time_t duration = 10;   // wait 60 seconds on Engine init

    time_t start_time, current_time;
    time (&start_time);

    current_time = start_time;
	JDFDoc d;
	d.Parse("c:\\data\\JDF\\spawn.jdf",false);    
		JDFNode n=d.GetJDFRoot();
		JDFResource rl=n.GetXPathElement("ResourcePool/NodeInfo");	
		cout<<rl.GetPartIDKeys()<<rl<<endl;
    cout<<31<<endl;

    while (current_time - start_time <= duration)
    {
		for(int i=0;i<100;i++){
//			d.GetJDFRoot().UpDaterRefs();
			WString www=WString::star+L"_"+WString::star+"_";
			www+=WString(42)+WString('b');
			delete(WString::star.getBytes());
			cout<<".";
		}
	    cout<<30<<current_time - start_time<<" "<<WString::star<<endl;
        time (&current_time);
        time (&current_time);
    }
    cout<<32<<endl;

    *pi = 1;
	}
    _endthreadex(0);
    return 0;
}



unsigned __stdcall threadproc4 (void* p)
{
	{
	Synchronized sync(*mutex2);
    int* pi = (int*) p;

    time_t duration = 10;   // wait 60 seconds on Engine init

    time_t start_time, current_time;
    time (&start_time);

	current_time = start_time;
	JDFDoc d;
	d.Parse("c:\\data\\JDF\\spawn.jdf",false);    
		JDFNode n=d.GetJDFRoot();
		JDFResource rl=n.GetXPathElement("ResourcePool/NodeInfo");	
		cout<<rl.GetPartIDKeys()<<rl<<endl;
	cout<<41<<endl;
	WString www;
	while (current_time - start_time <= duration)
	{
		for(int i=0;i<100;i++){
			//d.GetJDFRoot().UpDaterRefs();
			www=WString::star+L"_"+WString::star+"_";
			www+=WString(42)+WString('b');
			cout<<",";
		}
		cout<<www<<40<<current_time - start_time<<" "<<WString::star<<endl;
		time (&current_time);
	}
    cout<<42<<endl;

    *pi = 1;
	}
    _endthreadex(0);
    return 0;
}
