#if !defined(_JDFResourceLink_H__)
#define _JDFResourceLink_H__

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 120700 RP added Get/SetProcessUsage
// 180700 RP MyString -> WString : all strings now 16 bit
// 030501 RP now inherits from JDFElement
// 161101 RP GetProcessUsage and GetLinkedResourceName are now 2 sepaarte functions
// 061201 RP completely removed selector handling
// 070102 RP HasResourcePartMap bug fix if no parts in this - now returns true for no parts in this
// 150302 RP removed JDFResource GetPartition(bool bCreate=false, int i=0);
//        RP added AppendPart
//        RP added CombinedProcessIndex, PipeProtocol support
//        RP added AmountPool
//        RP added Transformation + Orientation support
//        RP removed GetAmount(bool bSelector)
//        RP removed GetPartTarget(int iPart=0,int iSelector=-1);
// 030502 RP modified GetNamedProcessUsage to default to xxx:Input / xxx:Output respectively
// 080502 RP SetPartition() now uses JDFResource::EnumPartIDKey
// 160502 RP added GetTarget
// 160502 RP GetTargetVector is now const
// 050602 RP added GetTarget()
// 200602 RP GetNamedProcessUsage() bugfix for processusage
// 200602 RP GetInvalidElements() added AmountPool check
//        RP OptionalAttributes(),GetInvalidAttributes: added support for implementation resources
//        RP added support for Recommendation,Start,StartOffset,Duration
// 260602 RP changed implementation of GetPartMapVector()
//        RP init() removed call to SetInput() 
//        RP SetInput(), IsInput() removed - Use Get/SetUsage() instead
// 050702 RP IsValid() added factory for recursive chack; added call to ValidResourcePosition()
//        RP added ValidResourcePosition()
//        RP IsLocal() cleanup
// 080702 RP IsValid() bug fix for dangling links
// 150802 RP GetTarget now based on GetTargetVector
//        RP GetTargetVector modified to evaluate PartUsage and added nMax
// 260802 RP GetStatus() now uses GetTarget()
// 260802 RP SetStatus() now uses GetTargetVector()
//        RP IsResourceSelected() added
// 120902 RP GetResourceLinkPool() added
// 260902 RP ReduceParts() added
// 051102 RP GetLinkRoot() modified so that only resources in pools within the legal search path are searched
// 120803 RP IsExecutable() added bCheckChildren
// 211003 RP IsExecutable() fixed bCheckChildren
// 211003 RP GetTarget() now returns the lowest common denominator resource if all leaves are available
// 250906 NB fixed SetProcessUsage()
// 041206 NB fixed GetMinStatus()
// 051206 NB fixed GetAmount()
//
//
// JDFResourceLink.h: interface for the JDFResourceLink class.
//
// tbd get correct default matrix for orientation
// tbd some facades for AmountPool
//
// ////////////////////////////////////////////////////////////////////

#include "JDFResource.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


namespace JDF{
	
	class JDFPart;
	class JDFResource;
	class JDFAmountPool;
	class JDFResourceLinkPool;
	
	/**
	* mother of all resource links
	*/
	class JDF_WRAPPERCORE_EXPORT JDFResourceLink : public JDFElement{
	public:
		
	/**
	* null construction 
		*/
		inline JDFResourceLink():JDFElement(){};
		/**
		* copy ctor
		*/
		
		inline JDFResourceLink(const KElement & other):JDFElement(){
			*this=other;
		};
		
		/**
		* yacctor
		*/
		JDFResourceLink& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFResourceLink(){};
		
		/**
		* Get the parent ResourceLinkPool
		* @return JDFResourceLinkPool the parent ResourceLinkPool
		* @deprecated use GetResourceLinkPool
		*/
		JDFResourceLinkPool GetPool() const;
		
		/**
		* Get the parent ResourceLinkPool
		* @return JDFResourceLinkPool the parent ResourceLinkPool 
		*/
		JDFResourceLinkPool GetResourceLinkPool() const;
		
		/**
		* shorthand if only one part is required and should be set to kay = value
		* @param JDFResource::EnumPartIDKey key the partition key
		* @param WString value the partition value
		*/
		void SetPartition(JDFResource::EnumPartIDKey key, const WString& value);
		
		/**
		* get the vector of part elements;
		* note that a resource link with multiple part elements is effectively an OR of these parts
		* @return vElement vector of part objects
		*/
		vElement GetParts()const;
		
		/**
		* reduce the parts to the canonical representation
		* if all children of a parent node are in defined in parts, they are replaced by their parent
		* for example the canonical representation of all leaves is the root
		*/
		void ReduceParts();
		
		/**
		* does the resource live in the same node or an ancestor node of the link
		* @return bool true if the linked resource resides in a legal node
		*/
		bool ValidResourcePosition()const;
		
		/**
		* does the resource live in the same node as the link?
		* @return bool true if the linked resource resides in the same node
		*/
		bool IsLocal()const;
		
		/**
		* returns the attribute occurrence in PartAmount or the Link itself
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param mAttribute mPart which part of this ResourceLink the Amount belongs to, if empty get the ResourceLink root attribute
		* @return WString: value of attribute found
		* @since 071103 
		*/
		WString GetAmountPoolAttribute(const WString & attrib,const WString & nameSpaceURI,const mAttribute& mPart)const;
		
		/**
		* returns true if the attribute occurrs in PartAmount 
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param mAttribute mPart which part of this ResourceLink the Amount belongs to, if empty get the ResourceLink root attribute
		* @return bool: true if an attribute exists in the link or the amountpool
		* @since 050705 
		*/
		bool HasAmountPoolAttribute(const WString & attrib,const WString & nameSpaceURI,const mAttribute& mPart)const;
		
		/**
		* sets  the  attribute occurrence in PartAmount 
		* @param WString attrib: the attribute name
		* @param WString value: value to set in string form.
		* @param WString nameSpaceURI: the XML-namespace
		* @param mAttribute mPart which part of this ResourceLink the Amount belongs to, if empty set the ResourceLink root attribute
		* @return WString: value of attribute found, value of def if not available
		* @since 071103 
		*/
		void SetAmountPoolAttribute(const WString & attrib,const WString & value, const WString & nameSpaceURI, const mAttribute& mPart);

		/** 
		* sets  the  attribute occurence in PartAmount 
		* 
		* @param attrib        the attribute name
		* @param value         value to set in string form.
		* @param nameSpaceURI  the XML-namespace
		* @param vPart         defines which part of this ResourceLink the Amount belongs to, 
		*                      if empty set the ResourceLink root attribute.
		* @since 061122
		*/
		void SetAmountPoolAttribute(const WString & attrib,const WString & value,const WString & nameSpaceURI, const vmAttribute& vPart);
		
		/**
		* Get the status of the Resource that is linked by this link
		*/
		JDFResource::EnumStatus GetStatus()const;
		
		/**
		* Set the status of the Resource that is linked by this link
		*/
		void SetStatus(JDFResource::EnumStatus s)const;
		
		/**
		* default validator
		* @param EnumValidationLevel ValidationLevel to validate at
		* @return bool true if valid
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;
		
		/**
		* Version fixing routine
		*
		* swaps MinStatus/MinLateStatus and DraftOK, depending on version
		*
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);

		/**
		* Gets the root resource of the target
		* returns a null JDFElement if it does not exist or the name mangling is illegal
		* @return JDFResource the resource root of the resource referenced by this resource link
		*/
		JDFResource GetLinkRoot()const;
		
		/**
		* Gets the  resource nodes that this resourcelink refers to
		* skips links that do not exist or where the name mangling is illegal<br>
		* the behavior varies according to the value of PartUsage of the referenced resource:<br>
		* if PartUsage="Explicit", all elements that are referenced in PartIDKeys and the ResourceLink must exist and fit<br>
		* if PartUsage="Implicit", the best fitting intermediate node of the partitioned resource is returned<br>
		* attributes in the Part elements that are not referenced in PartIDKeys are assumed to be logical attributes 
		* (e.g. RunIndex of a RunList) and ignored when searching the part
		*
		* @param int nMax maximum number of requested resources; -1= all
		* @return vElement the set of leaves that are referenced by this ResourceLink 
		*/
		vElement GetTargetVector(int nMax=-1)const;
		
		/**
		* Gets the 1st resource leaf that this resourcelink refers to
		* for details, see the description of @see GetTargetVector
		*
		* @since 102103 GetTarget returns the lowest common denominator if all children of a resource are referenced
		* @return JDFResource the first leaf that is referenced by this ResourceLink 
		*/
		virtual JDFResource GetTarget()const;
		
		/**
		* Sets the link to the target defined by partLeaf. Automatically generates a Part subelement, if partleaf is a leaf
		* @param JDFResource partLeaf the resource or resource partition that the resourceLink will refer to
		*
		* @return bool true if successful
		*/
		bool SetTarget(const JDFResource& partLeaf);
		
		/**
		*  Check if a resource is selected by a ResourceLink A resource is selected if all (partition) leaves are selected by the resource link
		* @param JDFResource &ResourceToCheck    The resource which may be selected by the ResourceLink. This ResourceLink must always be the 
		*   full ResourceLink, i.e. Part Elements are not allowed as parameters
		* @return bool  true, if the resource link selects the resource
		*/
		bool IsResourceSelected (const JDFResource &ResourceToCheck)const;
		

		/**
		* Expand the target resource to contain all parts specified in AmountPool
		* If PartUsage==Explicit or bForce==true, also loop over all part elements
		* @attrib bForce if true, implicit partitions are also expanded
		*/
		void ExpandTarget(bool bForce=false) const;

		//@{
		/**
		* get part map vector
		* @return vector of mAttribute, one for each part
		*/
		vmAttribute GetPartMapVector()const;
		
		/**
		* set all parts to those define in vParts
		* @param vmAttribute& vParts vector of attribute maps for the parts
		*/
		void SetPartMapVector(const vmAttribute & vParts);
		
		/**
		* set all parts to those define in vParts
		* @param mAttribute& mPart attribute map for the part to set
		*/
		void SetPartMap(const mAttribute & mPart);
		
		/**
		* remove the part defined in mPart
		* @param mAttribute& mPart attribute map for the part to remove
		*/
		void RemovePartMap(const mAttribute & mPart);
		
		/**
		* check whether the part defined in mPart is included
		* @param mAttribute& mPart attribute map for the part to remove
		* @return bool if the part exists
		*/
		bool HasPartMap(const mAttribute & mPart);
		//@}
		
		/**
		* get part map vector as defined by the linked resource
		* this returns the vector of leaves that would be returned
		* @return vector of mAttribute, one for each part
		*/
		vmAttribute GetResourcePartMapVector()const;
		
		/**
		* checks whether a given partMap is compatible with the this link
		* i.e. whether this link will 
		* @param mAttribute partMap the map of parts that this link is compared to
		* @param bool bCheckResource if true also recurse into the resource and check if the parts exist
		* @return bool true if this is compatible with partMap
		*/
		bool HasResourcePartMap(const mAttribute& partMap, bool bCheckResource=false)const;
		
		/**
		* standard initialization
		* @return true if successful
		*/
		bool init();
		
		/**
		* Is it a link to a Physical  Resource ?
		* note that it only works on links to resources that have a valid "Class" attribute
		* @return bool true if the link links to a physical resource
		*/
		bool IsPhysical() const;
		
		/**
		* checks whether the resource link links to a resource that is in a state that will allow a node to execute
		* @param mAttribute partMap: the Attribute map of parts
		* @param bool bCheckChildren if true, calculates the availability Status of a resource from all child partition leaves, 
		* else the Status is taken from the appropriate leaf itself
		* @return bool: true if the node executable, false if not
		*/
		bool IsExecutable(const mAttribute& partMap=mAttribute::emptyMap, bool bCheckChildren=true)const;
		
		/**
		*typesafe validator
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;
		
		/**
		*typesafe validator
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* Enumeration for attribute Usage
		*/
		
		enum EnumUsage{Usage_Unknown,Usage_Input,Usage_Output};
		
		/**
		* definition of required attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;
		
		/**
		definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;
		
		/**
		* Set attribute CombinedProcessType
		* @deprecated
		*/
		void SetCombinedProcessType(const WString& value);
		/**
		* Get string attribute CombinedProcessType
		* @deprecated
		*/
		WString GetCombinedProcessType() const;
		/**
		* Typesafe attribute validation of CombinedProcessType
		* @deprecated
		*/
		virtual bool ValidCombinedProcessType(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute CombinedProcessIndex
		*/
		void SetCombinedProcessIndex(const JDFIntegerList& value);
		/**
		Get string attribute CombinedProcessIndex
		*/
		JDFIntegerList GetCombinedProcessIndex() const;
		/**
		Typesafe attribute validation of CombinedProcessIndex
		*/
		virtual bool ValidCombinedProcessIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute DraftOK
		*/
		void SetDraftOK(bool value);

		/**
		* Get boolean attribute DraftOK; defaults to false
		* @since 050628 also return true if no DraftOKflag is set,
		* MinStatus is set and <= Draft 
		*/
		bool GetDraftOK() const;
		
		/**
		Typesafe attribute validation of DraftOK
		*/
		virtual bool ValidDraftOK(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* Get the MinStatus, 
		* return Draft if not set, but DraftOK=true
		*/
		JDFResource::EnumStatus GetMinStatus()const;
		
		/**
		* Set the Minimum status 
		*/
		void SetMinStatus(JDFResource::EnumStatus value);

		/**
		Typesafe attribute validation of MinStatus
		*/
		virtual bool ValidMinStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Get the MinStatus 
		*/
		JDFResource::EnumStatus GetMinLateStatus()const;
		
		/**
		* Set the minimum late status 
		*/
		void SetMinLateStatus(JDFResource::EnumStatus value);
		
		/**
		Typesafe attribute validation of MinLateStatus
		*/
		virtual bool ValidMinLateStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute Duration
		* @param JDFDuration value: the value to set the attribute to
		*/
		virtual void SetDuration(JDFDuration value=JDFDuration());

		/**
		* Get string attribute Duration
		* @return JDFDuration the vaue of the attribute 
		*/
		virtual JDFDuration GetDuration() const;
		/**
		* Typesafe attribute validation of Duration
		* @param EnumValidationLevel level of attribute validation 
		* @return bool true if valid
		*/
		virtual bool ValidDuration(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute PipeProtocol
		*/
		void SetPipeProtocol(const WString& value);
		/**
		Get string attribute PipeProtocol
		*/
		WString GetPipeProtocol() const;
		/**
		Typesafe attribute validation of PipeProtocol
		*/
		virtual bool ValidPipeProtocol(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute PipeURL
		*/
		virtual void SetPipeURL(const WString& value);
		/**
		Get string attribute PipeURL
		*/
		virtual WString GetPipeURL() const;
		/**
		Typesafe attribute validation of PipeURL
		*/
		virtual bool ValidPipeURL(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute ProcessUsage
		*/
		void SetProcessUsage(const WString& value);
		/**
		* Get string attribute ProcessUsage
		* defaults to empty string
		*/
		WString GetProcessUsage() const;
		/**
		* Get the expected name of the linked resource
		* defaults to the nodename w/o the Link suffix
		*/
		WString GetLinkedResourceName() const;
		/**
		* Get the expected name of the linked resource and an optional processusage in name:usage format
		* if no processusage is available, return GetLinkedResourceName:input / GetLinkedResourceName:output respectively <br>
		* defaults to the nodename with  the Link Usage suffix
		*/
		WString GetNamedProcessUsage() const;
		
		/**
		Typesafe attribute validation of ProcessUsage
		*/
		virtual bool ValidProcessUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute rRef
		*/
		void SetrRef(const WString& value);
		/**
		Get string attribute rRef
		*/
		WString GetrRef() const;
		/**
		Typesafe attribute validation of rRef
		*/
		virtual bool ValidrRef(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute rSubRef
		* @deprecated
		*/
		void SetrSubRef(const WString& value);
		/**
		* Get string attribute rSubRef
		* @deprecated
		*/
		WString GetrSubRef() const;
		/**
		* Typesafe attribute validation of rSubRef
		* @deprecated
		*/
		virtual bool ValidrSubRef(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute Amount
		* @param mAttribute mPart map of parts that this Amount is valid for.
		* @param double value the Amount to set
		*/
		virtual void SetAmount(double value,const mAttribute&mPart=mAttribute::emptyMap);
		
		/**
		* Get double attribute Amount either from the link itself or the PartAmount defined by mPart
		* @param mAttribute& mPart map of parts that this Amount is valid for.
		* @return the returned Amount
		*/
		virtual double GetAmount(const mAttribute&mPart=mAttribute::emptyMap) const;
		
		/**
		Typesafe attribute validation of Amount
		*/
		virtual bool ValidAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute MaxAmount
		* @param mAttribute mPart map of parts that this Amount is valid for.
		* @param double value the Amount to set
		*/
		virtual void SetMaxAmount(double value,const mAttribute&mPart=mAttribute::emptyMap);
		
		/**
		* Get double attribute Amount either from the link itself or the PartAmount defined by mPart
		* @param mAttribute& mPart map of parts that this Amount is valid for.
		* @return the returned Amount
		*/
		virtual double GetMaxAmount(const mAttribute&mPart=mAttribute::emptyMap) const;
		
		/**
		Typesafe attribute validation of Amount
		*/
		virtual bool ValidMaxAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
		
				/**
		* Set attribute MinAmount
		* @param mAttribute mPart map of parts that this Amount is valid for.
		* @param double value the Amount to set
		*/
		virtual void SetMinAmount(double value,const mAttribute&mPart=mAttribute::emptyMap);
		
		/**
		* Get double attribute Amount either from the link itself or the PartAmount defined by mPart
		* @param mAttribute& mPart map of parts that this Amount is valid for.
		* @return the returned Amount
		*/
		virtual double GetMinAmount(const mAttribute&mPart=mAttribute::emptyMap) const;
		
		/**
		Typesafe attribute validation of Amount
		*/
		virtual bool ValidMinAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute ActualAmount
		* @param double value the ActualAmount to set
		* @param mAttribute mPart map of parts that this Amount is valid for.
		*/
		virtual void SetActualAmount(double value, const mAttribute&mPart=mAttribute::emptyMap);
		
		/**
		* Get double attribute ActualAmount
		* @param mAttribute& mPart map of parts that this Amount is valid for.
		* @return the returned ActualAmount
		*/
		virtual double GetActualAmount(const mAttribute&mPart=mAttribute::emptyMap) const;
		
		/**
		Typesafe attribute validation of ActualAmount
		*/
		virtual bool ValidActualAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute Transformation
		* @param JDFMatrix value: the value to set the attribute to
		*/
		virtual void SetTransformation(JDFMatrix value);
		/**
		* Get string attribute Transformation
		* @return JDFMatrix the vaue of the attribute 
		*/
		virtual JDFMatrix GetTransformation() const;
		/**
		* Typesafe attribute validation of Transformation
		* @param EnumValidationLevel level of attribute validation 
		* @return bool true if valid
		*/
		virtual bool ValidTransformation(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute PipePause
		*/
		virtual void SetPipePause(double value);
		/**
		Get double attribute PipePause
		*/
		virtual double GetPipePause() const;
		/**
		Typesafe attribute validation of PipePause
		*/
		virtual bool ValidPipePause(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute PipeResume
		*/
		virtual void SetPipeResume(double value);
		/**
		Get double attribute PipeResume
		*/
		virtual double GetPipeResume() const;
		/**
		Typesafe attribute validation of PipeResume
		*/
		virtual bool ValidPipeResume(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute Recommendation
		* @deprecated
		*/
		virtual void SetRecommendation(bool value);
		/**
		* Get boolean attribute Recommendation; defaults to false
		* @deprecated
		*/
		virtual bool GetRecommendation() const;
		/**
		* Typesafe attribute validation of Recommendation
		* @deprecated
		*/
		virtual bool ValidRecommendation(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute RemotePipeEndPause
		*/
		virtual void SetRemotePipeEndPause(double value);
		/**
		Get double attribute RemotePipeEndPause
		*/
		virtual double GetRemotePipeEndPause() const;
		/**
		Typesafe attribute validation of RemotePipeEndPause
		*/
		virtual bool ValidRemotePipeEndPause(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		Set attribute RemotePipeEndResume
		*/
		virtual void SetRemotePipeEndResume(double value);
		/**
		Get double attribute RemotePipeEndResume
		*/
		virtual double GetRemotePipeEndResume() const;
		/**
		Typesafe attribute validation of RemotePipeEndResume
		*/
		virtual bool ValidRemotePipeEndResume(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* Set attribute Start
		*@param JDFDate value: the value to set the attribute to
		*/
		virtual void SetStart(JDFDate value=JDFDate());
		/**
		* Get string attribute Start
		* @return JDFDate the vaue of the attribute 
		*/
		virtual JDFDate GetStart() const;
		/**
		* Typesafe attribute validation of Start
		* @param EnumValidationLevel level of attribute validation 
		* @return bool true if valid
		*/
		virtual bool ValidStart(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		/**
		* set attribute StartOffset
		* @param JDFDuration value - value to set attribute to  
		*/
		virtual void SetStartOffset(JDFDuration value=JDFDuration());

    	/**
		* Get string attribute StartOffset
		* @return JDFDuration the vaue of the attribute 
		*/
		virtual JDFDuration GetStartOffset() const;
		/**
		* Typesafe attribute validation of StartOffset
		* @param EnumValidationLevel level of attribute validation 
		* @return bool true if valid
		*/
		virtual bool ValidStartOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		
		/** 
		* Append Element Part
		*/
		JDFPart AppendPart();

		/** 
		* Get Element Part, create it if it does not exist
		* @param int iSkip number of elements to skip
		* @return JDFPart The element
		*/
		JDFPart GetCreatePart(int iSkip=0);
		/**
		* const get first Part element 
		* @param int iSkip number of elements to skip
		*/
		JDFPart GetPart(int iSkip=0)const;
		

		/** Get Element AmountPool 
		* @return JDFAmountPool  The element
		*/
		JDFAmountPool  GetCreateAmountPool ();
		
		/**
		* Append element AmountPool 
		* return the existing element, if it already exists
		*/
		JDFAmountPool  AppendAmountPool();

		/**
		* const get first element AmountPool 
		*@return  JDFAmountPool  The element
		*/
		JDFAmountPool  GetAmountPool()const;
		
	//////////////////////////////////////////////////////////////////////
	
	JDFPart AppendLot();
	//////////////////////////////////////////////////////////////////////
	
	JDFPart JDFResourceLink::GetCreateLot(int iSkip);
	
	///////////////////////////////////////////////////////////////////////
	JDFPart JDFResourceLink::GetLot( int iSkip)const;
	//////////////////////////////////////////////////////////////////////
		/**
		definition of optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;
		
		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;
		
		/**
		Enumeration strings for Usage
		*/
		static const WString& UsageString();
		/**
		Enumeration string for enum value
		*/
		static WString UsageString(EnumUsage value);
		/**
		Set attribute Usage
		*/
		void SetUsage(EnumUsage value);
		/**
		Typesafe enumerated attribute Usage
		*/
		JDFResourceLink::EnumUsage GetUsage() const;
		/** 
		* Typesafe attribute validation of Usage
		*/
		virtual bool ValidUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
		
		
		
		/**
		Set attribute Orientation
		*/
		virtual void SetOrientation( JDFElement::EnumOrientation value);
		/**
		Get attribute Orientation
		*/
		virtual JDFElement::EnumOrientation GetOrientation() const ;
		/** 
		* Typesafe attribute validation of Orientation
		*/
		virtual bool ValidOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;

		
		/**
		Set attribute PipePartIDKeys
		*/
		//void SetPipePartIDKeys(vint keys);
		
		/**
		Get attribute PipePartIDKeys
		*/
		//vint GetPipePartIDKeys();

		bool overlapsResourcePartMap(JDFAttributeMap partMap);

private:
		/**
		* Gets the  resource nodes that this resourcelink refers to
		* skips links that do not exist or where the name mangling is illegal<br>
		* the behavior varies according to the value of PartUsage of the referenced resource:<br>
		* if PartUsage="Explicit", all elements that are referenced in PartIDKeys and the ResourceLink must exist and fit<br>
		* if PartUsage="Implicit", the best fitting intermediate node of the partitioned resource is returned<br>
		* attributes in the Part elements that are not referenced in PartIDKeys are assumed to be logical attributes 
		* (e.g. RunIndex of a RunList) and ignored when searching the part
		*
		* @param vmAttribute vmParts target map to use
		* @param int nMax maximum number of requested resources; -1= all
		* @return vElement the set of leaves that are referenced by this ResourceLink 
		*/
		vElement GetMapTargetVector(vmAttribute vmParts, int nMax)const;
	
	};
};

#endif // !defined(_JDFResourceLink_H__)
