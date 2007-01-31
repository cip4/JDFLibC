/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
* Processes in  Prepress, Press and Postpress (CIP4).  All rights 
* reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer. 
*
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*
* 3. The end-user documentation included with the redistribution,
*    if any, must include the following acknowledgment:  
*       "This product includes software developed by the
*        The International Cooperation for the Integration of 
*        Processes in  Prepress, Press and Postpress (www.cip4.org)"
*    Alternately, this acknowledgment may appear in the software itself,
*    if and wherever such third-party acknowledgments normally appear.
*
* 4. The names "CIP4" and "The International Cooperation for the Integration of 
*    Processes in  Prepress, Press and Postpress" must
*    not be used to endorse or promote products derived from this
*    software without prior written permission. For written 
*    permission, please contact info@cip4.org.
*
* 5. Products derived from this software may not be called "CIP4",
*    nor may "CIP4" appear in their name, without prior written
*    permission of the CIP4 organization
*
* Usage of this software in commercial products is subject to restrictions. For
* details please consult info@cip4.org.
*
* THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED.  IN NO EVENT SHALL THE INTERNATIONAL COOPERATION FOR
* THE INTEGRATION OF PROCESSES IN PREPRESS, PRESS AND POSTPRESS OR
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
* ====================================================================
*
* This software consists of voluntary contributions made by many
* individuals on behalf of the The International Cooperation for the Integration 
* of Processes in Prepress, Press and Postpress and was
* originally based on software 
* copyright (c) 1999-2001, Heidelberger Druckmaschinen AG 
* copyright (c) 1999-2001, Agfa-Gevaert N.V. 
*  
* For more information on The International Cooperation for the 
* Integration of Processes in  Prepress, Press and Postpress , please see
* <http://www.cip4.org/>.
*  
* 
*/

//EndCopyRight
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 040900 RP renamed JDFProcess to JDFSimulator
//
// JDFSimulator.cpp: implementation of the JDFSimulator class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFSimulator.h"
#include "jdf/wrapper/JDFAuditPool.h"
#include "jdf/wrapper/JDFAudit.h"
#include "jdf/wrapper/JDFResourceLink.h"
#include "jdf/wrapper/JDFResourceLinkPool.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFPhaseTime.h"
#include "jdf/wrapper/JDFProcessRun.h"

#include <iostream>
#include <fstream>

using namespace std;
namespace JDF{
	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFSimulator::init(){
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFSimulator::DoTask(){
		if(!IsValid()) return false;
		JDFAuditPool h=GetCreateAuditPool();
		//	if(!IsExecutable(true)) return false;
		EnumStatus st=GetStatus();
		if(st==Status_Waiting){
			
			WString nodeType=GetType();
			if(nodeType=="Scan"){
				DoScan();
			}else if(nodeType=="Layout"){
				DoLayOut();
			}else if(nodeType=="Trapping"){
				DoTrapping();
			}else if(nodeType=="Impose"){
				DoImpose();
			}else if(nodeType=="PlateMaking"){
				DoDefault();
			}else if(nodeType=="ImageSetting"){
				DoDefault();
			}else if(nodeType=="Combined"){
				DoDefault();
			}else if(nodeType=="Folding"){
				DoDefault();
			}else if(nodeType=="Cutting"){
				DoDefault();
			}else if(nodeType=="ConventionalPrinting"){
				DoDefault();
			}else if(nodeType=="ColorSpaceConversion"){
				DoDefault();
			}else{
				WString s="DoTask: Invalid Task Node: ";
				s+=nodeType;
				GetCreateAuditPool().AddNotification(JDFNotification::Class_Warning,s);
			}
		}else{
			WString s="DoTask: Invalid Task Status: ";
			s+=GetAttribute("Status");
			GetCreateAuditPool().AddNotification(JDFNotification::Class_Warning,s);
		}
		UpDateStatus();
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFSimulator::DoScan(){
		SetStatus(Status_InProgress);
		vElement nl=GetResourceLinks();
		if(nl.size()>=1){
			JDFElement e=nl[0];
			e=e.GetTarget("","");
			if(e.GetNodeName()=="File"){
				WString nam=e.GetAttribute("name");
				if(!nam.empty()){
					WString s="File scanned: ";
					GetCreateAuditPool().AddNotification(JDFNotification::Class_Information,s+nam);
					ofstream fs(nam.peekBytes(),ios::out|ios::app);
					fs<<s+nam<<endl;
				}
			}
		}
		
		SetStatus(Status_Completed);
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFSimulator::DoDefault(){
		JDFAuditPool ap=GetAuditPool();
		SetStatus(Status_InProgress);
		
		JDFResourceLinkPool rp=GetResourceLinkPool();
		vmAttribute vMap=rp.GetPartMapVector(false);
		// want at least one default empty part
		if(vMap.empty()) vMap.push_back(mAttribute());
		vElement inLinks=rp.GetInOutLinks(true);
		vElement outLinks=rp.GetInOutLinks(false);
		for(int mm=0;mm<vMap.size();mm++){
			mAttribute partMap=vMap[mm];
			cout<<" DoDefault map: "<<mm<<" "<<partMap<<endl;
			int i;
			for(i=0;i<inLinks.size();i++){
				JDFResourceLink rl=inLinks[i];
				JDFResource r=rl.GetLinkRoot();
				r=r.GetPartition(partMap);
				if((r.GetClass()!=JDFResource::Class_Consumable)&&(r.GetClass()!=JDFResource::Class_Handling)) continue;
				JDFResourceAudit aRes=ap.AddResourceAudit("DoDefault simulator");
				aRes.CopyElement(rl);
				if(!partMap.empty()){
					JDFElement part=aRes.AppendElement("Selector").AppendElement("Part");
					part.SetAttributes(partMap);
				}			
			}
			
			for(i=0;i<outLinks.size();i++){
				JDFResourceLink rl=outLinks[i];
				JDFResource r=rl.GetLinkRoot();
				r=r.GetPartition(partMap);
				r.SetAvailable();
				JDFAudit aRes=ap.AddResourceAudit("DoDefault simulator");
				aRes.CopyElement(outLinks[i]);
				if(!partMap.empty()){
					JDFElement part=aRes.AppendElement("Selector").AppendElement("Part");
					part.SetAttributes(partMap);
				}			
			}
			vmAttribute vpm;
			vpm.push_back(partMap);
			ap.SetPhase(JDFAutoPhaseTime::Status_Setup,WString(),vpm);
			ap.SetPhase(JDFAutoPhaseTime::Status_InProgress,WString(),vpm);
			ap.SetPhase(JDFAutoPhaseTime::Status_Cleanup,WString(),vpm);
			ap.SetPhase(JDFAutoPhaseTime::Status_Cleanup,WString(),vpm); // the second redoes the end tag
			
		}
		
		ap.AddProcessRun(JDFNode::Status_Completed);
		SetStatus(Status_Completed);
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFSimulator::DoRip(){
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFSimulator::DoLayOut(){
		SetStatus(Status_InProgress);
		vElement nl=GetResourceLinks();
		if(nl.size()>=1){
			WString s="File Layout using: ";
			WString outFile;
			for(int i=0;i<nl.size();i++){
				JDFResourceLink l=nl[i];
				bool isInput=l.GetUsage()==l.Usage_Input;
				JDFResource e=l.GetLinkRoot();
				if(e.GetNodeName()=="File"){			
					WString nam=e.GetAttribute("name");
					if(isInput){
						s+=nam+WString(" ");
					}else{
						outFile=nam;
					}
				}else{
					continue;
				}
			}
			if(!outFile.empty()){
				GetCreateAuditPool().AddNotification(JDFNotification::Class_Information,s);
				ofstream fs(outFile.peekBytes(),ios::out|ios::app);
				fs<<s<<endl;
			}
		}
		SetStatus(Status_Completed);
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	
	bool JDFSimulator::DoTrapping(){
		SetStatus(Status_InProgress);
		vElement nl=GetResourceLinks();
		if(nl.size()>=1){
			WString s,tp,nam;
			for(int i=0;i<nl.size();i++){
				JDFElement e=nl[i];
				e=e.GetTarget("","");
				if(e.GetNodeName()=="traps"){
					tp=e.GetAttribute("TrapPixels");
				}
				if(e.GetNodeName()=="File"){
					nam=e.GetAttribute("name");
				}
			}
			if(!nam.empty()){
				s=WString("File trapped: ")+nam;
				s+=", pixels= : ";
				s+=tp+WString(" ");
				GetCreateAuditPool().AddNotification(JDFNotification::Class_Information,s);
				ofstream fs(nam.peekBytes(),ios::out|ios::app);
				fs<<s<<endl;
			}
		}
		
		SetStatus(Status_Completed);
		return true;
		
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFSimulator::DoImpose(){
		SetStatus(Status_InProgress);
		vElement nl=GetResourceLinks();
		WString nam,style;
		
		for(int i=0;i<nl.size();i++){
			JDFElement e=nl[i];
			e=e.GetTarget();
			if(e.GetNodeName()=="Sheet"){
				vElement  v=e.GetChildElementVector("Surface");
				int l=v.size();
				switch (l){
				case 1: style="Simplex"; break;
				case 2:style="Duplex"; break;
				default: style="Non-Euclidian";
				}
			}
			if(e.GetNodeName()=="File"){
				nam=e.GetAttribute("name");
			}
		}
		if(!nam.empty()){
			WString s="File imposed: ";
			s+=nam;
			s+="; Style is ";
			s+=style;
			
			GetCreateAuditPool().AddNotification(JDFNotification::Class_Information,s);
			ofstream fs(nam.peekBytes(),ios::out|ios::app);
			fs<<s<<endl;
		}
		
		SetStatus(Status_Completed);
		return true;
		
	}
	
	//////////////////////////////////////////////////////////////////////
	
}
