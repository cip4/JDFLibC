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

#include "Unicode.h"
#include <xercesc/util/XMLUniDefs.hpp>

XERCES_CPP_NAMESPACE_USE

namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 


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

const JDFCh Unicode::THROWABLE_NAME[] = 
{
	chLatin_T, chLatin_h, chLatin_r, chLatin_o, chLatin_w, chLatin_a, chLatin_b, chLatin_l,
	chLatin_e,chNull
};

const JDFCh Unicode::EXCEPTION_NAME[] = 
{
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p, chLatin_t, chLatin_i, chLatin_o,
	chLatin_n, chNull
};

const JDFCh Unicode::ERROR_NAME[] = 
{
	chLatin_E, chLatin_r, chLatin_r, chLatin_o, chLatin_r,chNull
};

const JDFCh Unicode::RUNTIMEEXCEPTION_NAME[] = 
{
	chLatin_R, chLatin_u, chLatin_n, chLatin_t, chLatin_i, chLatin_m, chLatin_e, chLatin_E, 
	chLatin_x, chLatin_c, chLatin_e, chLatin_p, chLatin_t, chLatin_i, chLatin_o,
	chLatin_n, chNull
};

const JDFCh Unicode::ILLEGALARGUMENTEXCEPTION_NAME[] =
{
	chLatin_I, chLatin_l, chLatin_l, chLatin_e, chLatin_g, chLatin_a, chLatin_l, chLatin_A, 
	chLatin_r, chLatin_g, chLatin_u, chLatin_m, chLatin_e, chLatin_n, chLatin_t,
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p, chLatin_t, chLatin_i,
	chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::NULLPOINTEREXCEPTION_NAME[] =
{
	chLatin_N, chLatin_u, chLatin_l, chLatin_l, chLatin_P, chLatin_o, chLatin_i, chLatin_n, 
	chLatin_t, chLatin_e, chLatin_r, chLatin_E, chLatin_x, chLatin_c, chLatin_e,
	chLatin_p, chLatin_t, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::INTERNALERROR_NAME[] =
{
	chLatin_I, chLatin_n, chLatin_t, chLatin_e, chLatin_r, chLatin_n, chLatin_a, chLatin_l, 
	chLatin_E, chLatin_r, chLatin_r, chLatin_o, chLatin_r, chNull
};

const JDFCh Unicode::OUTOFMEMORYERROR_NAME[] =
{
	chLatin_O, chLatin_u, chLatin_t, chLatin_O, chLatin_f, chLatin_M, chLatin_e, chLatin_m, 
	chLatin_o, chLatin_r, chLatin_y, chLatin_E, chLatin_r, chLatin_r, chLatin_o, 
	chLatin_r, chNull
};

const JDFCh Unicode::ILLEGALACCESSERROR_NAME[] =
{
	chLatin_I, chLatin_l, chLatin_l, chLatin_e, chLatin_g, chLatin_a, chLatin_l, chLatin_A, 
	chLatin_c, chLatin_c, chLatin_e, chLatin_s, chLatin_s, chLatin_E, chLatin_r, 
	chLatin_r, chLatin_o, chLatin_r, chNull
};

const JDFCh Unicode::ILLEGALSTATEEXCEPTION_NAME[] =
{
	chLatin_I, chLatin_l, chLatin_l, chLatin_e, chLatin_g, chLatin_a, chLatin_l, chLatin_S, 
	chLatin_t, chLatin_a, chLatin_t, chLatin_e, chLatin_E, chLatin_x, chLatin_c, 
	chLatin_e, chLatin_p, chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::INDEXOUTOFBOUNDSEXCEPTION_NAME[] =
{
	chLatin_I, chLatin_n, chLatin_d, chLatin_e, chLatin_x, chLatin_O, chLatin_u, chLatin_t, 
	chLatin_O, chLatin_f, chLatin_B, chLatin_o, chLatin_u, chLatin_n, chLatin_d, 
	chLatin_s, chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p, 
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::ARRAYINDEXOUTOFBOUNDSEXCEPTION_NAME[] =
{
	chLatin_A, chLatin_r, chLatin_r, chLatin_a, chLatin_y,
	chLatin_I, chLatin_n, chLatin_d, chLatin_e, chLatin_x, chLatin_O, chLatin_u, chLatin_t, 
	chLatin_O, chLatin_f, chLatin_B, chLatin_o, chLatin_u, chLatin_n, chLatin_d, 
	chLatin_s, chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p, 
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::IOEXCEPTION_NAME[] =
{
	chLatin_I, chLatin_O, chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};


const JDFCh Unicode::INTERRUPTEDIOEXCEPTION_NAME[] =
{
	chLatin_I, chLatin_n, chLatin_t, chLatin_e, chLatin_r, chLatin_r, chLatin_u, 
	chLatin_p, chLatin_t, chLatin_e, chLatin_d, chLatin_I, chLatin_O, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::FILENOTFOUNDEXCEPTION_NAME[] =
{
	chLatin_F, chLatin_i, chLatin_l, chLatin_e, chLatin_N, chLatin_o, chLatin_t, 
	chLatin_F, chLatin_o, chLatin_u, chLatin_n, chLatin_d, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};


const JDFCh Unicode::EOFEXCEPTION_NAME[] =
{
	chLatin_E, chLatin_O, chLatin_F, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::CESTREAMEXHAUSTED_NAME[] =
{
	chLatin_C, chLatin_E, chLatin_S, chLatin_t, chLatin_r, chLatin_e, chLatin_a, 
	chLatin_m, chLatin_E, chLatin_x, chLatin_h, chLatin_a, chLatin_u, 
	chLatin_s, chLatin_t, chLatin_e, chLatin_d,
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::CEFORMATEXCEPTION_NAME[] =
{
	chLatin_C, chLatin_E, chLatin_S, chLatin_t, chLatin_r, chLatin_e, chLatin_a, 
	chLatin_m, chLatin_F, chLatin_o, chLatin_r, chLatin_m, chLatin_a, 
	chLatin_t, chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::SOCKETEXCEPTION_NAME[] =
{
	chLatin_S, chLatin_o, chLatin_c, chLatin_k, chLatin_e, chLatin_t, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::PIPEEXCEPTION_NAME[] =
{
	chLatin_P, chLatin_i, chLatin_p, chLatin_e, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::BINDEXCEPTION_NAME[] =
{
	chLatin_B, chLatin_i, chLatin_n, chLatin_d, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::CONNECTEXCEPTION_NAME[] =
{
	chLatin_C, chLatin_o, chLatin_n, chLatin_n, chLatin_e, chLatin_c, chLatin_t, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::NOROUTETOHOSTEXCEPTION_NAME[] =
{
	chLatin_N, chLatin_o, chLatin_R, chLatin_o, chLatin_u, chLatin_t, chLatin_e, 
	chLatin_T, chLatin_o, chLatin_H, chLatin_o, chLatin_s, chLatin_t, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::UNKNOWNHOSTEXCEPTION_NAME[] =
{
	chLatin_U, chLatin_n, chLatin_k, chLatin_n, chLatin_o, chLatin_w, chLatin_n, 
	chLatin_H, chLatin_o, chLatin_s, chLatin_t, chLatin_E, chLatin_x, chLatin_c, 
	chLatin_e, chLatin_p, chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::MALFORMEDURLEXCEPTION_NAME[] =
{
	chLatin_M, chLatin_a, chLatin_l, chLatin_f, chLatin_o, chLatin_r, chLatin_m, 
	chLatin_e, chLatin_d, chLatin_U, chLatin_R, chLatin_L, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::DIGESTEXCEPTION_NAME[] =
{
	chLatin_D, chLatin_i, chLatin_g, chLatin_e, chLatin_s, chLatin_t, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::PROTOCOLEXCEPTION_NAME[] =
{
	chLatin_P, chLatin_r, chLatin_o, chLatin_t, chLatin_o, chLatin_c, chLatin_o, 
	chLatin_l, chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::UNKNOWNSERVICEEXCEPTION_NAME[] =
{
	chLatin_U, chLatin_n, chLatin_k, chLatin_n, chLatin_o, chLatin_w, chLatin_n, 
	chLatin_S, chLatin_e, chLatin_r, chLatin_v, chLatin_i, chLatin_c, chLatin_e,
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::NOSUCHELEMENTEXCEPTION_NAME[] =
{
	chLatin_N, chLatin_o, chLatin_s, chLatin_u, chLatin_c, chLatin_h, chLatin_E, 
	chLatin_l, chLatin_e, chLatin_m, chLatin_e, chLatin_n, chLatin_t, chLatin_E,
	chLatin_x, chLatin_c,  chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::PLATFORMUTILSEXCEPTION_NAME[] =
{
	chLatin_P, chLatin_l, chLatin_a, chLatin_t, chLatin_f, chLatin_o, chLatin_r, 
	chLatin_m, chLatin_U, chLatin_t, chLatin_i, chLatin_l, chLatin_s, chLatin_E,
	chLatin_x, chLatin_c,  chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};

const JDFCh Unicode::MIMEEXCEPTION_NAME[] =
{
	chLatin_M, chLatin_I, chLatin_M, chLatin_E, 
	chLatin_E, chLatin_x, chLatin_c, chLatin_e, chLatin_p,
	chLatin_T, chLatin_i, chLatin_o, chLatin_n, chNull
};



const JDFCh Unicode::MIMECONTENTTYPETEXT[] =
{
	chLatin_T, chLatin_e, chLatin_x, chLatin_t, chNull
};

const JDFCh Unicode::MIMECONTENTTYPEAUDIO[] =
{
	chLatin_A, chLatin_u, chLatin_d, chLatin_i, chLatin_o, chNull
};

const JDFCh Unicode::MIMECONTENTTYPEIMAGE[] =
{
	chLatin_I, chLatin_m, chLatin_a, chLatin_g, chLatin_e, chNull
};

const JDFCh Unicode::MIMECONTENTTYPEVIDEO[] =
{
	chLatin_V, chLatin_i, chLatin_d, chLatin_e, chLatin_o, chNull
};

const JDFCh Unicode::MIMECONTENTTYPEAPPLICATION[] =
{
	chLatin_A, chLatin_p, chLatin_p, chLatin_l, chLatin_i, 
	chLatin_c, chLatin_a, chLatin_t, chLatin_i, chLatin_o, chLatin_n,
	chNull
};

const JDFCh Unicode::MIMEENCODINGBASE64[] =
{
	chLatin_b, chLatin_a, chLatin_s, chLatin_e,  
	chDigit_6, chDigit_4, chNull
};

const JDFCh Unicode::MIMEENCODINGQP[] =
{
	chLatin_q, chLatin_u, chLatin_o, chLatin_t, chLatin_e, 
	chLatin_d, chDash, chLatin_p, chLatin_r, chLatin_i, chLatin_n,
	chLatin_t, chLatin_a, chLatin_b, chLatin_l, chLatin_e,
	chNull
};

const JDFCh Unicode::MIMEENCODING7BIT[] =
{
	chDigit_7, chLatin_b, chLatin_i, chLatin_t, chNull
};

const JDFCh Unicode::MIMEENCODING8BIT[] =
{
	chDigit_8, chLatin_b, chLatin_i, chLatin_t, chNull
};

const JDFCh Unicode::MIMEENCODINGBINARY[] =
{
	chLatin_b, chLatin_i, chLatin_n, chLatin_a, chLatin_r, 
	chLatin_y, chNull
};

const JDFCh Unicode::MIMEDISPATTACHMENT[] =
{
	chLatin_A, chLatin_t, chLatin_t, chLatin_a, chLatin_c, 
	chLatin_h, chLatin_m, chLatin_e, chLatin_n, chLatin_t, 
	chNull
};

const JDFCh Unicode::MIMEDISPINLINE[] =
{
	chLatin_I, chLatin_n, chLatin_l, chLatin_i, chLatin_n, 
	chLatin_e, chNull
};

const JDFCh Unicode::MIMEMESSAGE[] =
{
	chLatin_M, chLatin_e, chLatin_s, chLatin_s, chLatin_a, 
	chLatin_g, chLatin_e, chNull
};

const JDFCh Unicode::MIMEMULTIPART[] =
{
	chLatin_M, chLatin_u, chLatin_l, chLatin_t, chLatin_i, 
	chLatin_P, chLatin_a, chLatin_r, chLatin_t, chNull
};

const JDFCh Unicode::URLCONTENTENCODING[] =
{
	chLatin_c, chLatin_o, chLatin_n, chLatin_t, chLatin_e, 
	chLatin_n, chLatin_t, chDash, chLatin_e, chLatin_n, 
	chLatin_c, chLatin_o, chLatin_d, chLatin_i, chLatin_n,
	chLatin_g, chNull
};

const JDFCh Unicode::URLCONTENTLENGTH[] =
{
	chLatin_c, chLatin_o, chLatin_n, chLatin_t, chLatin_e, 
	chLatin_n, chLatin_t, chDash, chLatin_l, chLatin_e, 
	chLatin_n, chLatin_g, chLatin_t, chLatin_h, 
	chNull
};

const JDFCh Unicode::URLCONTENTTYPE[] =
{
	chLatin_c, chLatin_o, chLatin_n, chLatin_t, chLatin_e, 
	chLatin_n, chLatin_t, chDash, chLatin_t, chLatin_y, 
	chLatin_p, chLatin_e, chNull
};

const JDFCh Unicode::URLCONTENTTYPEHTML[] =
{
	chLatin_t, chLatin_e, chLatin_x, chLatin_t, chForwardSlash, 
	chLatin_h, chLatin_t, chLatin_m, chLatin_l, chNull
};


} // namespace JDF
