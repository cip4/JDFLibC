/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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

/******************************************************************************
 *                     Copyright 1998 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
#include <windows.h>
#include <resource.h>
#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/WString.h>
#include <jdf/lang/Janitor.h>

/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

static JDF::WString user_name;
static JDF::WString user_passwd;
static JDF::WString user_realm;
static JDF::WString user_site;

static bool user_ok;

LONG FAR PASCAL  PasswdDiaProc(HWND hdlg, UINT msg,
			 WPARAM wParam, LPARAM lParam)
{
	switch (msg) {

	case WM_INITDIALOG:
		{
			HWND hwnd = GetDlgItem(hdlg, IDC_REALM);
			char* realmBytes    = user_realm.getBytes();
			char* usersiteBytes = user_site.getBytes();
			JDF::ArrayJanitor<char> realmJanitor(realmBytes);
			JDF::ArrayJanitor<char> usersiteJanitor(usersiteBytes);
			SetWindowText(hwnd,realmBytes);
			hwnd = GetDlgItem(hdlg, IDC_FIREWALL);
			SetWindowText(hwnd,usersiteBytes);
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hdlg);
		break;

	case WM_DESTROY:
		PostQuitMessage (0) ;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			{
			HWND hwnd = GetDlgItem(hdlg, IDC_PASSWORD);
			char buf[255];
			int cnt = GetWindowText(hwnd,buf, 255);
			user_passwd = JDF::WString(buf,cnt);
			hwnd = GetDlgItem(hdlg, IDC_USERNAME);
			cnt = GetWindowText(hwnd,buf, 255);
			user_name = JDF::WString(buf,cnt);
			user_ok = true;
			DestroyWindow(hdlg);

			return FALSE;
			}
			break;
		case IDCANCEL:
			DestroyWindow(hdlg);
			user_ok = false;
			return FALSE;
			break;
		default:
			return FALSE;
	}
	default: return FALSE;
	}
	return TRUE;
}


bool getUserNameAndPassword(JDF::WString& userName, JDF::WString& passwd, JDF::WString realm, JDF::WString site)
{
	  static char szAppName [] = "passwdwindow" ;
	  HWND        hwnd ;
	  MSG         msg;
	  static FARPROC fpfnPasswdDiaProc;

	  user_realm = realm;
	  user_site  = site;
	  fpfnPasswdDiaProc = MakeProcInstance((FARPROC)
						PasswdDiaProc,NULL);
						//hInstance);


	  //createtmp();

	  hwnd = CreateDialog (GetModuleHandle(NULL),(LPSTR)MAKEINTRESOURCE(IDD_PASSWORD_DIALOG), 0, (DLGPROC)fpfnPasswdDiaProc) ;
	  DWORD err = GetLastError();

	  ShowWindow(hwnd, SW_SHOW);

	  while (GetMessage (&msg, NULL, 0, 0))
	  {
		 // important: if we don't check to see if it is a dialog message
		 // then accelerator input keys are lost, e.g. the TAB key will not
				// work

		 if (!IsDialogMessage(hwnd,&msg)) {
		  TranslateMessage (&msg) ;
		  DispatchMessage (&msg) ;
		 }
	  }
	  if (user_ok)
	  {
		userName = user_name;
		passwd   = user_passwd;
		return true;
	  }
	  else
		  return false;
}
