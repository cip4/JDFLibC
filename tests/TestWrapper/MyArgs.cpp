//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// MyArgs.cpp: implementation of the MyArgs class.
//
//////////////////////////////////////////////////////////////////////

#include "MyArgs.h"
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyArgs::MyArgs(int argc, char** argv, char*param0string,char*param1string,char*paramreqstring){
	argC=argc;
	argV=argv;
	nArgs=-1;
	onlyArgs=new char*[argC];
	if(param0string){
		param0String=new char[strlen(param0string)+1];
		strcpy(param0String,param0string);
	}else{
		param0String=new char[1];
		*param0String=0; 
	}
	if(param1string){
		param1String=new char[strlen(param1string)+1];
		strcpy(param1String,param1string);
	}else{
		param1String=new char[1];
		*param1String=0;
	}
	if(paramreqstring){
		paramReqString=new char[strlen(paramreqstring)+1];
		strcpy(paramReqString,paramreqstring);
	}else{
		paramReqString=new char[1];
		*paramReqString=0;
	}
}

//////////////////////////////////////////////////////////////////////

MyArgs::~MyArgs(){
	if(param0String) delete[] param0String;
	if(param1String) delete[] param1String;
	if(paramReqString) delete[] paramReqString;
	delete[] onlyArgs;
}

//////////////////////////////////////////////////////////////////////

int MyArgs::NArgs(){
	if(nArgs>=0) return nArgs;
	int n=0;
	for(int i=1;i<argC;i++){
		if (*(argV[i])=='-'){
			if(argV[i][1]&&!argV[i][2]){
				// parameter takes and argument and has a blank
				if (strchr(param1String,argV[i][1])) i++;
			}
		}else{
			onlyArgs[n]=argV[i];
			n++;
		}
	}
	nArgs=n;
	return n;
}

//////////////////////////////////////////////////////////////////////

char* MyArgs::Argument(int m){
	if(nArgs<0) NArgs();
	if(m>=nArgs) return 0;
	return onlyArgs[m];
}

//////////////////////////////////////////////////////////////////////

char* MyArgs::Parameter(char c){
	if(!strchr(param0String,c)&&!strchr(param1String,c)) return 0;
	int n;
	char*pc;
	for(int i=1;i<argC;i++){
		if (*(argV[i])=='-'){
			n=1;
			pc=argV[i];
			while (pc[n]){
				if (pc[n]==c){
					if(strchr(param0String,pc[n])) return "t"; // true
					if(strchr(param1String,pc[n])){
						if(pc[++n]){
							return pc+n; // no blank
						}else{
							return argV[++i];
						}
					}
				}else{
					if(strchr(param1String,pc[n])) {
						if(!pc[++n]) i++; // takes argument --> next argv is a parameter argument
						break;
					}
					n++;
				}
			}
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////

int MyArgs::IntParameter(char c, int idef, int radix){
	char*pc=Parameter(c);
	char*pce;
	if(!pc) return idef;
	int l=strtol(pc,&pce,radix);
	if (pce==pc) return idef;
	return l;
}

//////////////////////////////////////////////////////////////////////

double MyArgs::FloatParameter(char c, double def){
	char*pc=Parameter(c);
	if(!pc) return def;
	if ((*pc>='0'&&*pc<='9')||(*pc=='.')){
		return atof(pc);
	}else{
		return def;
	}

}

//////////////////////////////////////////////////////////////////////

bool MyArgs::BoolParameter(char c, bool def){
	char*pc=Parameter(c);
	if(pc) return true;
	return def;
}

//////////////////////////////////////////////////////////////////////

JDF::WString MyArgs::Usage(JDF::WString pc){
	sBuf="usage: ";
	sBuf+=argV[0];
	if(*param0String) sBuf+=JDF::WString(" switches: -")+param0String;
	if(*param1String) sBuf+=JDF::WString(" Parameters: -")+param1String;
	if(*paramReqString) sBuf+=JDF::WString(" Required: -")+paramReqString;
	sBuf+=" Argument(s)\n";
	if(pc!="") sBuf+=pc+"\n";
	return sBuf;
}
//////////////////////////////////////////////////////////////////////
