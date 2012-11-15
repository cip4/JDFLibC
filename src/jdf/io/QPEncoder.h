/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_QPENCODER_H
#define I_JDF_QPENCODER_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "CharacterEncoder.h"


namespace JDF
{
	class QPDecoder;

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

/**
 * A Quoted-Printable encoder. Quoted-Printable is a simple encoding
 * defined by the IETF as part of the MIME specification as published in
 * RFC 1521.
 * <p>
 * @varbatim
 *	RFC 1521                          MIME                    September 1993
 *
 * 5.1.  Quoted-Printable Content-Transfer-Encoding
 * 
 * The Quoted-Printable encoding is intended to represent data that
 *   largely consists of octets that correspond to printable characters in
 *   the ASCII character set.  It encodes the data in such a way that the
 *   resulting octets are unlikely to be modified by mail transport.  If
 *   the data being encoded are mostly ASCII text, the encoded form of the
 *   data remains largely recognizable by humans.  A body which is
 *   entirely ASCII may also be encoded in Quoted-Printable to ensure the
 *   integrity of the data should the message pass through a character-
 *   translating, and/or line-wrapping gateway.
 *
 *   In this encoding, octets are to be represented as determined by the
 *   following rules:
 *
 *      Rule #1: (General 8-bit representation) Any octet, except those
 *      indicating a line break according to the newline convention of the
 *      canonical (standard) form of the data being encoded, may be
 *      represented by an "=" followed by a two digit hexadecimal
 *      representation of the octet's value.  The digits of the
 *      hexadecimal alphabet, for this purpose, are "0123456789ABCDEF".
 *      Uppercase letters must be used when sending hexadecimal data,
 *      though a robust implementation may choose to recognize lowercase
 *      letters on receipt.  Thus, for example, the value 12 (ASCII form
 *      feed) can be represented by "=0C", and the value 61 (ASCII EQUAL
 *      SIGN) can be represented by "=3D".  Except when the following
 *      rules allow an alternative encoding, this rule is mandatory.
 *
 *      Rule #2: (Literal representation) Octets with decimal values of 33
 *      through 60 inclusive, and 62 through 126, inclusive, MAY be
 *      represented as the ASCII characters which correspond to those
 *      octets (EXCLAMATION POINT through LESS THAN, and GREATER THAN
 *      through TILDE, respectively).
 *
 *      Rule #3: (White Space): Octets with values of 9 and 32 MAY be
 *      represented as ASCII TAB (HT) and SPACE characters, respectively,
 *      but MUST NOT be so represented at the end of an encoded line. Any
 *      TAB (HT) or SPACE characters on an encoded line MUST thus be
 *      followed on that line by a printable character.  In particular, an
 *      "=" at the end of an encoded line, indicating a soft line break
 *      (see rule #5) may follow one or more TAB (HT) or SPACE characters.
 *      It follows that an octet with value 9 or 32 appearing at the end
 *      of an encoded line must be represented according to Rule #1.  This
 *      rule is necessary because some MTAs (Message Transport Agents,
 *      programs which transport messages from one user to another, or
 *      perform a part of such transfers) are known to pad lines of text
 *      with SPACEs, and others are known to remove "white space"
 *      characters from the end of a line.  Therefore, when decoding a
 *      Quoted-Printable body, any trailing white space on a line must be
 *      deleted, as it will necessarily have been added by intermediate
 *      transport agents.
 *
 *      Rule #4 (Line Breaks): A line break in a text body, independent of
 *      what its representation is following the canonical representation
 *      of the data being encoded, must be represented by a (RFC 822) line
 *      break, which is a CRLF sequence, in the Quoted-Printable encoding.
 *      Since the canonical representation of types other than text do not
 *      generally include the representation of line breaks, no hard line
 *      breaks (i.e.  line breaks that are intended to be meaningful and
 *      to be displayed to the user) should occur in the quoted-printable
 *      encoding of such types.  Of course, occurrences of "=0D", "=0A",
 *      "0A=0D" and "=0D=0A" will eventually be encountered.  In general,
 *      however, base64 is preferred over quoted-printable for binary
 *      data.
 *
 *      Note that many implementations may elect to encode the local
 *      representation of various content types directly, as described in
 *      Appendix G.  In particular, this may apply to plain text material
 *      on systems that use newline conventions other than CRLF
 *      delimiters. Such an implementation is permissible, but the
 *      generation of line breaks must be generalized to account for the
 *      case where alternate representations of newline sequences are
 *      used.
 *
 *      Rule #5 (Soft Line Breaks): The Quoted-Printable encoding REQUIRES
 *      that encoded lines be no more than 76 characters long. If longer
 *      lines are to be encoded with the Quoted-Printable encoding, 'soft'
 *      line breaks must be used. An equal sign as the last character on a
 *      encoded line indicates such a non-significant ('soft') line break
 *      in the encoded text. Thus if the "raw" form of the line is a
 *      single unencoded line that says:
 *
 *          Now's the time for all folk to come to the aid of
 *          their country.
 *
 *      This can be represented, in the Quoted-Printable encoding, as
 *
 *          Now's the time =
 *          for all folk to come=
 *           to the aid of their country.
 *
 *      This provides a mechanism with which long lines are encoded in
 *      such a way as to be restored by the user agent.  The 76 character
 *      limit does not count the trailing CRLF, but counts all other
 *      characters, including any equal signs.
 *
 *   Since the hyphen character ("-") is represented as itself in the
 *   Quoted-Printable encoding, care must be taken, when encapsulating a
 *   quoted-printable encoded body in a multipart entity, to ensure that
 *   the encapsulation boundary does not appear anywhere in the encoded
 *   body.  (A good strategy is to choose a boundary that includes a
 *   character sequence such as "=_" which can never appear in a quoted-
 *   printable body.  See the definition of multipart messages later in
 *   this document.)
 *
 *      NOTE: The quoted-printable encoding represents something of a
 *      compromise between readability and reliability in transport.
 *      Bodies encoded with the quoted-printable encoding will work
 *      reliably over most mail gateways, but may not work perfectly over
 *      a few gateways, notably those involving translation into EBCDIC.
 *      (In theory, an EBCDIC gateway could decode a quoted-printable body
 *      and re-encode it using base64, but such gateways do not yet
 *      exist.)  A higher level of confidence is offered by the base64
 *      Content-Transfer-Encoding.  A way to get reasonably reliable
 *      transport through EBCDIC gateways is to also quote the ASCII
 *      characters
 *
 *             !"#$@[\]^`{|}~
 *
 *      according to rule #1.  See Appendix B for more information.
 *
 *   Because quoted-printable data is generally assumed to be line-
 *   oriented, it is to be expected that the representation of the breaks
 *   between the lines of quoted printable data may be altered in
 *   transport, in the same manner that plain text mail has always been
 *   altered in Internet mail when passing between systems with differing
 *   newline conventions.  If such alterations are likely to constitute a
 *   corruption of the data, it is probably more sensible to use the
 *   base64 encoding rather than the quoted-printable encoding.
 *
 *   WARNING TO IMPLEMENTORS: If binary data are encoded in quoted-
 *   printable, care must be taken to encode CR and LF characters as "=0D"
 *   and "=0A", respectively.  In particular, a CRLF sequence in binary
 *   data should be encoded as "=0D=0A".  Otherwise, if CRLF were
 *   represented as a hard line break, it might be incorrectly decoded on
 *   platforms with different line break conventions.
 *
 *   For formalists, the syntax of quoted-printable data is described by
 *   the following grammar:
 *
 *   quoted-printable := ([*(ptext / SPACE / TAB) ptext] ["="] CRLF)
 *        ; Maximum line length of 76 characters excluding CRLF
 *
 *   ptext := octet /<any ASCII character except "=", SPACE, or TAB>
 *        ; characters not listed as "mail-safe" in Appendix B
 *        ; are also not recommended.
 *
 *   octet := "=" 2(DIGIT / "A" / "B" / "C" / "D" / "E" / "F")
 *        ; octet must be used for characters > 127, =, SPACE, or TAB,
 *        ; and is recommended for any characters not listed in
 *        ; Appendix B as "mail-safe".
 * @endverbatim
 * @author Nico Verboven
 * @see CharacterEncoder
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT QPEncoder : public CharacterEncoder
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	QPEncoder();

/*@}*/

    /**
     * Encode bytes from the input stream, and write them as text characters
     * to the output stream.
	 * Overwritten from the base classe.
     */
	void encodeBuffer(InputStream& in, OutputStream& out);

protected:

   /** 
	* Added for compatibility
	* Returns two
	*/
 
	size_t bytesPerAtom();

   /** 
	* Added for compatibility
	* Returns 80.
	*/

	size_t bytesPerLine();

	/**
	 * Not implemented
	 */
    void encodeAtom(OutputStream& aStream,char* someBytes, size_t len,size_t anOffset, size_t aLength);
private:

	static char basis_hex[];
	static int index_hex[];

	static char hexmap[];

	friend class QPDecoder;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_QPENCODER_H */
