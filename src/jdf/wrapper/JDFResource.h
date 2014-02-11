#if !defined(__JDFRESOURCE_H__)
#define __JDFRESOURCE_H__
/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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
//
// 11.07.00 | RP | Added CloneResourceElement
// 11.07.00 | RP | Added enum elements ClassPlaceHolder,ClassSelector 
// 180700 RP MyString -> WString : all strings now 16 bit
// 120900 RP add Spawn attribute instead of status
// 090102 RP added SpawnIDs manipulation
// 230302 RP modifid GetCreator return value to vElement
// 150302 RP added ResourceUpdate handling
// 150302 RP remove SetDraft, IsPrepared
// 180302 RP added GetValidNodeNames
// 230302 RP added GetChildElementVector
// 300402 RP modified IsValid to include the factory call for GetLeaves
// 300402 RP added new JDF 1.1 routines: UpdateID, PartUsage, PartID enumeration handling
// 300402 RP removed GetPartition (int i)
// 060502 RP removed GetAllAttributeVector()
// 060502 RP removed GetMissingAttributeVector()
// 060502 RP removed GetUnknownAttributeVector()
// 060502 RP removed RequiredElements()
// 060502 RP added RequiredRootAttributes()
// 060502 RP added OptionalRootAttributes()
// 060502 RP added PartAttributes()
// 060502 RP put back HasAttribute()
// 080502 RP GetPartition(), GetPartValues() also use enumerated PartIDKeys
// 270502 RP AddPartition() - modified to simply call GetPartition
// 070602 RP mofified calls to AppendAttribut("PartIDKey") to have bUnique=true.
// 070602 RP changed return value of AddPartIDKey to void
// 070602 RP replaced all IsValid and ValidElement() entries with those from the JDF 1.1 generator
// 140602 RP GetInvalidAttributes() added consistency check with PartIDKeys
// 140602 RP added virtual ConsistentPartIDKeys()
// 190602 RP GetLeaves() added throwNull check
//           Collapse() / Expand() added element support
//           MergePartition added Collapse / Expand 
// 200602 RP Collapse() modified handling of non-identical elements
// 210602 RP Collapse() modified handling of non-identical elements
// 260602 RP RefElement(removed) The JDFElement version is sufficient
// 270602 RP GetElement --> GetCreateElement for non const version
// 270602 RP GetDeepPart / GetPartition removed bCreate and added GetCreateDeepPart, GetCreatePartition
// 020702 RP Collapse() Bug fix for ResourceRefs
// 050802 RP AddPartition() Bug Fix
// 140802 RP Collapse() added bool bCollapseToNode option
//        RP Expand() added bool bDeleteFromNode option
// 150802 RP GetDeepPart() now returns the last matching node if bIncomplete=true
//        RP GetPartUsage() now defaults to PartUsage_Explicit
//        RP GetSpawnStatus() now defaults to SpawnStatus_NotSpawned
// 160802 RP MergePartition() Gracefully handle implied partitions
// 030902 RP GetDeepPartVector() GetPartitionVector() added routines
//        RP GetDeepPart now internally calls GetDeepPartVector()
// 040902 RP SpawnPart(const WString & SpawnID, const vmAttribute& vParts) added
// 040902 RP UnSpawnPart(const WString & SpawnID) added
// 040902 RP GetNodesWithSpawnID() added
// 050902 RP GetDeepPartVector() fixes for really weird configurations...
// 050902 RP MergePartition() fixes for really weird configurations...
// 050902 RP GetNodesWithSpawnID() added
// 060902 RP moved all remaining refElement handling from JDFResource to JDFElement and cleaned up refElement
// 060902 RP MakeRootResource cosmetics for link names
// 120902 RP GetResourcePool() added
// 160902 RP GetDeepPartVector() slightly modified algorithm for finding the closest next element
// 180902 RP MergePartition made parameters const
// 240902 RP MergePartition changed 2. Parameter from vParts to SpawnID
// 250902 RP GetLeaves() added bIntermediate
// 250902 RP GetPartMapVector() added 
// 260902 RP ReducePartVector() added 
// 260902 RP MergeSpawnIDs(const JDFResource& resToMerge) added
// 221002 RP NumAttributes() added
// 061102 RP MakeRootResource() gaurantee correct class if it is known
// 061102 RP SetClass check() that the element is a root resource
// 211102 RP NewModifiedID() added;
// 220104 RP removed RequiredRootAttributes()
// 220104 RP removed OptionalRootAttributes()
// 260804 RP removed class vResource, use vElement instead
// 010906 NB added setPartIDKeys()
// 060906 NB fixed GetPartValues(), GetLeaves()
// 070906 NB added validResourceClass()
// 070906 NB fixed GetInvalidAttributes(), GetCreatePartition()
// 080906 NB fixed GetResourceRoot()
// 150906 NB fixed GetLeaves()
// 250906 NB fixed GetPartMap, AddPartIDKey(), Expand()
// 041206 NB fixed GetChildElementVector()
// 051206 NB added reorderPartKeys()
// 131206 NB SetPartIDKey(): removed waste attribute for JDFComponent
// 151206 NB added cleanResourceAttributes()
//
// JDFResource.h: interface for the JDFResource class.
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFPart.h"
#include "JDFNumTypeList.h"
#include "JDFIntegerRangeList.h"
#include "JDFNameRangeList.h"
#include "JDFNumberRangeList.h"

namespace JDF{

	class JDFNode;
	class vElement;
	class JDFContact;
	class JDFSourceResource;
	class JDFLocation;
	class JDFQualityControlResult;
	class JDFIdentificationField;
	class JDFGeneralID;
	class JDFResourcePool;
	class JDFResourceLink;
	class JDFResourceLinkPool;
	class JDFResourceAudit;

	/**
	* mother of all JDF resource classes
	* also abstracts partitioning, i.e calls to GetElement, GetAttribute etc. 
	* include searches throught the appropriate branches of a partition tree
	*/

	class JDF_WRAPPERCORE_EXPORT JDFResource : public JDFElement{

		friend class JDFResourcePool;
		friend class JDFResourceLink;
		friend class JDFResourceLinkPool;
		friend class JDFResourceAudit;


	public:
		static const JDFResource DefJDFResource; 
		/**
		* Construction / destruction
		*/
		//@{
		/**
		* Empty constructor
		*/
		inline JDFResource():JDFElement(){};

		/** 
		* Conversion copy constructor <br>
		* Converts the KElement object 'other' into a JDFResource object
		*
		* @param KElement & other: KElement object to copy <br>
		*/
		JDFResource(const KElement & other);

		/**
		* Assignment of KElement object 'other' to the current JDFResource object
		*
		* @param KElement& other: KElement object to assign
		* @throws JDFException if constructor for JDFResource is invalid
		*/
		JDFResource& operator=(const KElement& other);

		/** 
		* Destructor
		*/
		virtual ~JDFResource(){};
		//@}

		/**
		* Enumeration for partition keys
		*/
		enum EnumPartIDKey{PartIDKey_Unknown,PartIDKey_BinderySignatureName,PartIDKey_BlockName,PartIDKey_BundleItemIndex,
			PartIDKey_CellIndex,PartIDKey_Condition,PartIDKey_DocCopies,PartIDKey_DocIndex,PartIDKey_DocRunIndex,PartIDKey_DocSheetIndex,
			PartIDKey_ItemNames,PartIDKey_FountainNumber,PartIDKey_LayerIDs,PartIDKey_Location,PartIDKey_Option,PartIDKey_PageNumber,
			PartIDKey_PartVersion,PartIDKey_PreflightRule,PartIDKey_PreviewType,PartIDKey_RibbonName,PartIDKey_Run,PartIDKey_RunIndex,
			PartIDKey_RunTags,PartIDKey_RunPage,PartIDKey_Separation,PartIDKey_SectionIndex,PartIDKey_SetDocIndex,PartIDKey_SetIndex,
			PartIDKey_SetRunIndex,PartIDKey_SetSheetIndex,PartIDKey_SheetIndex,PartIDKey_SheetName,PartIDKey_Side,PartIDKey_SignatureName,PartIDKey_TileID,PartIDKey_WebName,
			PartIDKey_DeliveryUnit0,PartIDKey_DeliveryUnit1,PartIDKey_DeliveryUnit2,PartIDKey_DeliveryUnit3,PartIDKey_DeliveryUnit4,PartIDKey_DeliveryUnit5,PartIDKey_DeliveryUnit6,PartIDKey_DeliveryUnit7,PartIDKey_DeliveryUnit8,PartIDKey_DeliveryUnit9,
			PartIDKey_DocTags,PartIDKey_Edition,PartIDKey_EditionVersion,PartIDKey_PageTags,PartIDKey_PlateLayout,PartIDKey_RunSet,PartIDKey_SetTags,PartIDKey_SubRun,PartIDKey_WebProduct,PartIDKey_WebSetup
		};

		/**
		* Enumeration strings for attribute PartIDKeys
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& PartIDKeyString();

		/**
		* Enumeration string for PartIDKeys enum value
		* Converts the value of type EnumPartIDKey into corresponding string value,  
		* f.e. for EnumPartIDKey with value 'PartIDKey_BlockName' returns 'BlockName' 
		*
		* @param EnumPartIDKey value: PartIDKey enumeration value to convert
		* @return WString: PartIDKey string value
		*/
		static WString PartIDKeyString(EnumPartIDKey value);



		/**
		* Enumeration for attribute SpawnStatus
		*/
		enum EnumSpawnStatus{SpawnStatus_Unknown,SpawnStatus_NotSpawned,SpawnStatus_SpawnedRO,SpawnStatus_SpawnedRW};

		/**
		* Enumeration for attribute PartUsage
		*/
		enum EnumPartUsage{PartUsage_Unknown,PartUsage_Explicit,PartUsage_Sparse,PartUsage_Implicit};

		/**
		* Enumeration for attribute Status
		*/
		enum EnumStatus{Status_Unknown,Status_Incomplete,Status_Rejected,Status_Unavailable,Status_InUse,Status_Draft,Status_Complete,Status_Available};

		/** 
		* access to Class enumerations
		*/
		enum EnumClass{Class_Unknown,Class_Parameter,Class_Handling,Class_Consumable,Class_Quantity,Class_Implementation,Class_PlaceHolder,Class_Intent};

		/**
		* access to LotControl enumerations
		*/
		enum EnumLotControl{LotControl_Unknown,LotControl_Controlled,LotControl_NotControlled};

		/**
		* Checks, whether the resource is one of the physical resource classes
		*
		* @return bool: true, if the resource is one of the physical resource classes
		*/
		bool IsPhysical()const;

		/**
		* Checks, whether the resource is one a parameter resource
		*
		* @return bool: true, if the resource is a parameter resource (Class_Parameter)
		*/
		bool IsParameter()const;

		/**
		* comma separated list of physical resources
		* @return WString list of physical resources
		*/
		static const WString& PhysicalResources();

		/**
		* Tests whether Status of resource is Available 
		*
		* @param  bool bRecurseRefs: if bRecurseRefs is set to true, also recurses into all resources 
		* linked by rRefs and returns true if the minimum Status is Status_Available 
		* @return bool: true, if Status is Available
		*/
		bool IsAvailable(bool bRecurseRefs=false)const;

		/**
		* Status related shorthand for really lazy people
		* Sets Status of resource as Available if bAvailable=true 
		* or as Unavailable if bAvailable=false
		*
		* @param bool bAvailable: defaults to true
		*/
		void SetAvailable(bool bAvailable=true);

		/**
		* Clone the resource element oldRes and merge it with this resource
		*
		* @param JDFResource oldRes: the resource element to clone and to merge with this resource
		* @return JDFResource: merged resource
		*/
		JDFResource MergeCloneResource(JDFResource oldRes);

		/**
		* Gets from all referenced resources the int cast of the minimum value of enumerated attribute
		* e.g. used in IsAvailable()/GetStatus() to find in all referenced resources Status, which is the minimum
		*
		* @param WString & key: attribute name you are searching for
		* @param WString& allowedValues: string of allowed values in case of an enumerated attribute
		* @param unsigned int def: default value, if no explicit value exists
		* @param WString & nameSpaceURI: namespace of attribute key
		* @return unsigned int: the int cast of the minimum referenced value
		*/
		unsigned int GetMinRefAttribute(const WString & key, const WString& allowedValues, unsigned int def=0,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Gets from all referenced resources the int cast of the maximum value of enumerated attribute
		*
		* @param WString & key: attribute name you are searching for
		* @param WString& allowedValues: string of allowed values in case of an enumerated attribute
		* @param unsigned int def: default value, if no explicit value exists
		* @param WString & nameSpaceURI: namespace of attribute key
		* @return unsigned int: the int cast of the maximum referenced value
		*/
		unsigned int GetMaxRefAttribute(const WString & key, const WString& allowedValues,  unsigned int def=0,const WString & nameSpaceURI=WString::emptyStr)const;

		/**
		* Gets all elements with name linkName, which contain resource links that point to this resource
		*
		* @param WString & linkName: defaults to any 
		* @param WString& nameSpaceURI: attribute namespace you are searching in
		* @return vElement: vector of all found elements
		*/
		virtual vElement GetLinks(const WString& linkName=WString::star, const WString& nameSpaceURI=WString::emptyStr) const;


		/**
		* Gets the creators (bCreate=true) or consumers (bCreate=false) of this resource
		* 
		* @param bool bCreate: switcher for getter: if true gets creators, otherwise gets consumers
		* @return vElement: list of JDF nodes that create or consume this resource
		*/
		vElement GetCreator(bool bCreate=true)const;

		/**
		* Checks, whether this resourse is a quantity resource 
		* for quantity resource the class of 'this' must be either Class_Quantity or Class_Consumable
		*
		* @param bool: true, if 'this' is a quantity resource
		*/
		bool IsQuantity()const;

		/**
		* Call this function to get information about the node name of the 'this' resource
		*
		* @return WString: the node name of 'this' resource
		*/		
		WString GetResourceType()const;

		/**
		* Gets the resourcepool that 'this' lives in
		*
		* @return JDFResourcePool: the ResourcePool where 'this' lives
		*
		* @deprecated use GetResourcePool instead <br>
		* TBD: Return typ in jave is JDFPool
		*/
		JDFResourcePool GetPool()const;

		/**
		* Gets the resourcepool that 'this' lives in
		*
		* @return JDFResourcePool: the ResourcePool where 'this' lives<br>
		*
		* TBD: Return typ in jave is JDFPool
		*/
		JDFResourcePool GetResourcePool()const;

		/**
		* default initialization
		*
		* @return bool: true, if successful
		*/	
		bool init();

		/**
		* Makes from 'this' resource subelement a root resource element (direct child) of the specified parentPool
		* or (in default case) of ResourcePool, where it lives. <br>
		* The Status and SpawnStatus attribute values of the new root resource are taken from the old root resource.
		*
		* @param WString & id: id attribute of the newly created resource
		* @param JDFElement& parentPool: the pool where the newly created resource is stored <br> 
		* if null the local pool is used. Must use JDFElement for the pool because of recursive #defines
		* @param bool bLinkHere: if true, creates a refelement (link) to the newly created resource 
		* at the position where 'this' originally resided.
		* @return JDFRefElement: link to the newly created resource from the position were it originally resided
		*/
		JDFRefElement MakeRootResource(const WString & id=WString::emptyStr,const JDFElement& parentPool=JDFElement(), bool bLinkHere=true);

		/**
		* Gets the root resource of 'this'
		*
		* @return JDFResource: the root resource element
		*
		* @throws JDFException if GetResourceRoot ran into the JDF node while searching
		*/		
		JDFResource GetResourceRoot()const;

		/**
		* Spawns a given partition for a given SpawnID
		*
		* @param WString & spawnID: the SpawnID that it was spawned with 
		* @param EnumSpawnStatus spawnStatus: SpawnStatus to spawn this resource with
		* @param vmAttribute& vParts: vector of partitions that it was spawned with
		* @param bool bStayInMain: if true, the function is applied to the main JDF, else to the spawned JDF
		*/
		void SpawnPart(const WString & spawnID, EnumSpawnStatus spawnStatus, const vmAttribute& vParts, bool bStayInMain);

		/**
		* Find the appropriate partition for a given SpawnID and undo the spawn procedure
		*
		* @param WString & spawnID: the SpawnID that it was spawned with
		* @param EnumSpawnStatus spawnStatus: SpawnStatus this resource was spawned with
		*/
		void UnSpawnPart(const WString & spawnID, EnumSpawnStatus spawnStatus);

		/** 
		* Gets of 'this' all leaves and intermediate nodes that have an explicit spawnID set
		*
		* @param WString& spawnID: the spawnID to look for
		* @return vElement: the vector of nodes or leaves of 'this' that contain spawnID
		*/
		vElement GetNodesWithSpawnID(const WString& spawnID) const;

		/**
		* Typesafe validator. Gets a vector of invalid element names
		*
		* @param EnumValidationLevel level: validation level
		* @param bool bIgnorePrivate: if true, do not validate elements in private name spaces
		* @param int nMax: maximum size of the returned vector. Stop validation after nMax invalid elements
		* @return vWString: a vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

		/**
		* Typesafe validator. Gets a vector of invalid attributes
		*
		* @param EnumValidationLevel level: flag whether incomplete elements are valid 
		* @param bool bIgnorePrivate: if true, do not validate attributes in private name spaces 
		* @param int nMax: maximum size of the returned vector. Stop validation after nMax invalid attributes
		* @return vWString: a vector of invalid attributes
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

		/**
		* Definition of optional attributes in the JDF namespace
		*
		* @return WString: list of optional attributes
		*/
		virtual WString OptionalAttributes()const;

		/**
		* Definition of required attributes in the JDF namespace
		*
		* @return WString: list of required attributes
		*/
		virtual WString RequiredAttributes()const;

		/**
		* list of part attributes
		*
		* @return WString: list of part attributes
		*/
		virtual WString PartAttributes()const;


		/**
		* Definition of optional elements in the JDF namespace
		*
		* @return WString: list of optional elements
		*/
		virtual WString OptionalElements()const;

		//@{
		/**
		* Typesafe attribute validation of PartIDKeys
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidPartIDKeys(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		//@{
		/**
		* Typesafe attribute validation of PipePartIDKeys
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidPipePartIDKeys(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute AgentName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetAgentName(const WString& value);

		/**
		* Gets string attribute AgentName
		*
		* @return WString: the attribute value
		*/
		virtual WString GetAgentName() const;

		/**
		* Typesafe attribute validation of AgentName
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAgentName(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		//@{
		/**
		* Sets attribute AgentVersion
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetAgentVersion(const WString& value);

		/**
		* Gets string attribute AgentVersion
		*
		* @return WString: the attribute value
		*/
		virtual WString GetAgentVersion() const;

		/**
		* Typesafe attribute validation of AgentVersion
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAgentVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		//@{
		/**
		* Sets attribute Author
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetAuthor(const WString& value);

		/**
		* Gets string attribute Author
		*
		* @return WString: the attribute value
		*/
		virtual WString GetAuthor() const;

		/**
		* Typesafe attribute validation of Author
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAuthor(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute CatalogID
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetCatalogID(const WString& value);

		/**
		* Gets string attribute CatalogID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetCatalogID() const;

		/**
		* Typesafe attribute validation of CatalogID
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidCatalogID(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute CatalogDetails
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetCatalogDetails(const WString& value);

		/**
		* Gets string attribute CatalogDetails
		*
		* @return WString: the attribute value
		*/
		virtual WString GetCatalogDetails() const;

		/**
		* Typesafe attribute validation of CatalogDetails
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidCatalogDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Enumeration strings for attribute Class
		* 
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& ClassString();

		/**
		* Enumeration string for Class enum value <br>
		* Converts the value of type EnumClass into corresponding string value,  
		* f.e. for EnumClass with value 'Class_Parameter' returns 'Parameter'
		*
		* @param EnumClass value: EnumClass enumeration value to convert
		* @return WString: EnumClass string value
		*/
		static WString ClassString(EnumClass value);

		/**
		* Sets attribute Class
		*
		* @param EnumClass value: enumeration value of the attribute Class to be set
		* @throws JDFException if here is attempt to set value as Class_Unknown or invalid class value
		*/
		virtual void SetClass(EnumClass value);

		/**
		* Gets typesafe enumerated value of attribute Class
		*
		* @return EnumClass: attribute enumeration value
		*/
		virtual EnumClass GetClass() const;

		/** 
		* Typesafe attribute validation of Class
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidClass(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		/**
		* Typesafe attribute validation of ID
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;


		//@{
		/**
		* Sets attribute Locked
		*
		* @param bool: the value to set the attribute to
		*/
		virtual void SetLocked(bool value);

		/**
		* Gets boolean attribute Locked; defaults to false. 
		* 
		* @return bool: the attribute value
		*/
		virtual bool GetLocked() const;

		/**
		* Typesafe attribute validation of Locked
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidLocked(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		//@{
		/**
		* Enumeration strings for attribute LotControl
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& LotControlString();

		/**
		* Enumeration string for LotControl enum value
		* Converts the value of type EnumLotControl into corresponding string value,  
		* f.e. for EnumLotControl with value 'LotControl_Explicit' returns 'Explicit' 
		*
		* @param EnumLotControl value: LotControl enumeration value to convert
		* @return WString: LotControl string value
		*/
		static WString LotControlString(EnumLotControl value);

		/**
		* Sets attribute LotControl
		*
		* @param EnumLotControl value: enumeration value of the attribute LotControl to be set
		*/
		void SetLotControl( EnumLotControl value);

		/**
		* Gets typesafe enumerated value of attribute LotControl; defaults to LotControl_Explicit
		*
		* @return EnumLotControl: attribute enumeration value
		*/
		EnumLotControl GetLotControl() const;

		/** 
		* Typesafe attribute validation of LotControl
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidLotControl(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Enumeration strings for attribute PartUsage
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& PartUsageString();

		/**
		* Enumeration string for PartUsage enum value
		* Converts the value of type EnumPartUsage into corresponding string value,  
		* f.e. for EnumPartUsage with value 'PartUsage_Explicit' returns 'Explicit' 
		*
		* @param EnumPartUsage value: PartUsage enumeration value to convert
		* @return WString: PartUsage string value
		*/
		static WString PartUsageString(EnumPartUsage value);

		/**
		* Sets attribute PartUsage
		*
		* @param EnumPartUsage value: enumeration value of the attribute PartUsage to be set
		*/
		void SetPartUsage( EnumPartUsage value);

		/**
		* Gets typesafe enumerated value of attribute PartUsage; defaults to PartUsage_Explicit
		*
		* @return EnumPartUsage: attribute enumeration value
		*/
		EnumPartUsage GetPartUsage() const;

		/**
		* if set to true, the default @PartUsage of unpartitioned resources is Implicit.
		* Note: this is NOT according to the specification since the Specification defaults PartUsage to Explicit for all Resources.
		* 
		* @param bUnpartitiondImplicit the bUnpartitiondImplicit to set
		*/
		static void setUnpartitiondImplicit(bool bUnpartitiondImplicit);

		/** 
		* Typesafe attribute validation of PartUsage
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidPartUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute PipeID
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetPipeID(const WString& value);

		/**
		* Gets string attribute PipeID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetPipeID() const;

		/**
		* Typesafe attribute validation of PipeID
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidPipeID(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		/**
		* Set attribute PipeProtocol
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetPipeProtocol(const WString& value);

		/**
		* Get string attribute PipeProtocol
		*
		* @return WString: the attribute value 
		*/
		WString GetPipeProtocol() const;

		/**
		* Typesafe attribute validation of PipeProtocol
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidPipeProtocol(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Sets attribute ProductID
		*
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetProductID(const WString& value);

		/**
		* Gets string attribute ProductID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetProductID() const;

		/**
		* Typesafe attribute validation of ProductID
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidProductID(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute PipeURL
		*
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetPipeURL(const WString& value);

		/**
		* Gets string attribute PipeURL
		*
		* @return WString: the attribute value
		*/
		virtual WString GetPipeURL() const;

		/**
		* Typesafe attribute validation of PipeURL
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidPipeURL(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Typesafe attribute validation of rRefs
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidrRefs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute SpawnIDs
		*
		* @param vWString value: the value to set the attribute to
		*/
		virtual void SetSpawnIDs(vWString value);

		/**
		* Appends new SpawnID token ('value') to the list of values of SpawnIDs attribute, 
		* if it is not yet in the list
		*
		* @param WString& value: the SpawnID token to append
		*/
		virtual void AppendSpawnIDs(const WString& value);

		/**
		* Removes SpawnID token ('value') from the list of values of SpawnIDs attribute, if it is in the list
		*
		* @param WString& value: the SpawnID token to remove from the NMTOKENS list
		* @return int: the number of removed tokens
		*/
		virtual int RemoveFromSpawnIDs(const WString& value);

		/**
		* Gets string attribute SpawnIDs
		*
		* @param bool bInherit: if true, searches through all leaves, else searches only this leaf/node
		* @return vWString: the vector of SpawnIDs
		*/
		vWString GetSpawnIDs(bool bInherit=true) const;

		/**
		* Typesafe attribute validation of SpawnIDs
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidSpawnIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Enumeration strings for attribute SpawnStatus
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& SpawnStatusString();

		/**
		* Enumeration string for SpawnStatus enum value <br>
		* Converts the value of type EnumSpawnStatus into corresponding string value,  
		* f.e. for EnumSpawnStatus with value 'SpawnStatus_NotSpawned' returns 'NotSpawned' 
		* 
		* @param EnumSpawnStatus value: SpawnStatus enumeration value to convert
		* @return WString: SpawnStatus string value
		*/
		static WString SpawnStatusString(EnumSpawnStatus value);

		/**
		* Sets attribute SpawnStatus
		*
		* @param EnumSpawnStatus value: enumeration value of the attribute SpawnStatus to be set
		*/
		void SetSpawnStatus(EnumSpawnStatus value);

		/**
		* Gets typesafe enumerated value of attribute SpawnStatus
		* defults to SpawnStatus_NotSpawned
		*
		* @return EnumSpawnStatus: attribute enumeration value 
		*/
		EnumSpawnStatus GetSpawnStatus() const;

		/** 
		* Typesafe attribute validation of SpawnStatus
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidSpawnStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Enumeration strings for attribute Status
		*
		* @return WString&: comma separated list of enumerated string values
		*/
		static const WString& StatusString();

		/**
		* Enumeration string for Status enum value <br>
		* Converts the value of type EnumStatus into corresponding string value,  
		* f.e. for EnumStatus with value 'Status_Incomplete' returns 'Incomplete'
		*
		* @param EnumStatus value: EnumStatus enumeration value to convert
		* @return WString: EnumStatus string value
		*/
		static WString StatusString(EnumStatus value);

		/**
		* Gets typesafe enumerated value of attribute Status
		*
		* @param bool bRecurseRefs: if bRecurseRefs is set, also recurse into all resources
		* linked by rRefs and return the minimum status
		* @return EnumStatus: attribute enumeration value 
		*/
		EnumStatus GetStatus(bool bRecurseRefs=false)const;

		/**
		* Gets the minimum typesafe enumerated value of attribute Status from the value of all leaves 
		*
		* @param bAll if true, also evaluate intermediate partitions, else leaves only
		* @return EnumResStatus - the minimum Status enumeration value
		*
		*/
		EnumStatus getStatusFromLeaves(bool bAll) const;

		/**
		* Sets attribute Status
		*
		* @param EnumStatus value: enumeration value of the attribute Status to be set
		* @param bCleanLeaves if true, remove Status attribute from any child leaves below this
		*/
		virtual void SetStatus(EnumStatus value, bool bCleanLeaves=false);

		/** 
		* Typesafe attribute validation of Status
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute UpdateID
		* 
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetUpdateID(const WString& value);

		/**
		* Gets string attribute UpdateID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetUpdateID() const;

		/**
		* Typesafe attribute validation of UpdateID
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidUpdateID(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute NoOp
		*
		* @param bool value: value to set the attribute to
		*/
		virtual void SetNoOp(bool value);

		/**
		* Gets bool attribute NoOp; defaults to false
		*
		* @return bool: the attribute value 
		*/
		virtual bool GetNoOp() const;

		/**
		* Typesafe attribute validation of NoOp
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidNoOp(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute Sorting
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSorting(JDFIntegerRangeList value);

		/**
		* Gets range attribute Sorting
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetSorting() const;

		/**
		* Typesafe attribute validation of Sorting
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSorting(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SortAmount
		*
		* @param bool value: value to set the attribute to
		*/
		virtual void SetSortAmount(bool value);

		/**
		* Gets bool attribute SortAmount
		*
		* @return bool: the attribute value 
		*/
		virtual bool GetSortAmount() const;

		/**
		* Typesafe attribute validation of SortAmount
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSortAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute AlternateBrand
		*
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetAlternateBrand(const WString& value);

		/**
		* Gets string attribute AlternateBrand
		*
		* @return WString: the attribute value
		*/
		virtual WString GetAlternateBrand() const;

		/**
		* Typesafe attribute validation of AlternateBrand
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAlternateBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute Amount
		*
		* @param double value: value to set the attribute to
		*/

		virtual void SetAmount(double value);

		/**
		* Gets double attribute Amount
		*
		* @return double: the attribute value
		*/
		virtual double GetAmount() const;

		/**
		* Typesafe attribute validation of Amount
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute AmountProduced
		* 
		* @param double value: value to set the attribute to
		*/
		virtual void SetAmountProduced(double value);

		/**
		* Gets double attribute AmountProduced
		*
		* @return double: the attribute value
		*/
		virtual double GetAmountProduced() const;

		/**
		* Typesafe attribute validation of AmountProduced
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAmountProduced(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute AmountRequired
		* 
		* @param double value: value to set the attribute to
		*/
		virtual void SetAmountRequired(double value);

		/**
		* Gets double attribute AmountRequired
		*
		* @return double: the attribute value
		*/
		virtual double GetAmountRequired() const;

		/**
		* Typesafe attribute validation of AmountRequired
		* 
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidAmountRequired(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute BatchID
		*
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetBatchID(const WString& value);

		/**
		* Gets string attribute BatchID
		*
		* @return WString: the attribute value
		*/
		virtual WString GetBatchID() const;

		/**
		* Typesafe attribute validation of BatchID
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidBatchID(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute Brand
		* 
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetBrand(const WString& value);

		/**
		* Gets string attribute Brand
		*
		* @return WString: the attribute value
		*/
		virtual WString GetBrand() const;

		/**
		* Typesafe attribute validation of Brand
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		//@{
		/**
		* Sets attribute Manufacturer
		* 
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetManufacturer(const WString& value);

		/**
		* Gets string attribute Manufacturer
		*
		* @return WString: the attribute value
		*/
		virtual WString GetManufacturer() const;

		/**
		* Typesafe attribute validation of Manufacturer
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidManufacturer(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute ResourceWeight
		*
		* @param double value: value to set the attribute to
		*/
		virtual void SetResourceWeight(double value);

		/**
		* Gets double attribute ResourceWeight
		*
		* @return double: the attribute value
		*/
		virtual double GetResourceWeight() const;

		/**
		* Typesafe attribute validation of ResourceWeight
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidResourceWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}

		//@{
		/**
		* Sets attribute GrossWeight
		*
		* @param double value: value to set the attribute to
		*/
		virtual void SetGrossWeight(double value);

		/**
		* Gets double attribute GrossWeight
		*
		* @return double: the attribute value
		*/
		virtual double GetGrossWeight() const;

		/**
		* Typesafe attribute validation of GrossWeight
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidGrossWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Sets attribute Unit
		*
		* @param WString& value: value to set the attribute to
		*/
		virtual void SetUnit(const WString& value);

		/**
		* Gets string attribute Unit
		*
		* @return WString: the attribute value
		*/
		virtual WString GetUnit() const;

		/**
		* Typesafe attribute validation of Unit
		*
		* @param EnumValidationLevel level: level of attribute validation
		* @return bool: true, if valid
		*/
		virtual bool ValidUnit(EnumValidationLevel level=ValidationLevel_Complete) const;		
		//@}



		// naming of derived elements
		/**
		* Gets nodename of a ResourceLink that links to 'this'
		*
		* @return WString: name of a link to 'this'
		*/
		WString GetLinkString()const;

		/*
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Additional utilities for partitioned resources
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		*/

		/**
		* Gets a map of all partition key-value pairs for this leaf / node
		* this includes a recursion to the part root;
		*
		* @return mAttribute: the part attribute map for 'this' leaf / node
		*/
		mAttribute GetPartMap() const;

		/**
		* Gets a vector of maps of all partition attribute key-value pairs for this node and all its children
		*
		* @param bool bIntermediate: if true also includes intermediate nodes including this
		* @return vmAttribute: the vector of partition attribute maps for this leaf / node and all its children
		*/
		vmAttribute GetPartMapVector(bool bIntermediate=false) const;

		/**
		* Gets a list of all valid part keys for this resource
		*
		* @return vWString: list of all PartIDKeys
		*/
		vWString GetPartIDKeys() const;

		/**
		* Tests, if this leaf has a partIDKey as specified by key 
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @return bool: true if key exists in this leaf or below 
		*/
		bool HasPartIDKey(EnumPartIDKey key)const;

		/**
		* Converts a PartIDKey string into the corresponding enum
		*
		* @param WString& key: the PartIDKey attribute name
		* @return EnumPartIDKey: he corresponding PartIDKey enum
		*
		* @throws JDFException if the specified key is illegal
		*/
		static EnumPartIDKey GetPartIDKeyEnum(const WString& key);

		/**
		* Sets the value of attibute, specified by key 
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @param WString& value: the value to set key to
		*/
		void SetPartIDKey(EnumPartIDKey key, const WString&value );

		/**
		* Tests, if this leaf has a consistent PartIDKey as specified by key
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @return bool: true, if key exists in this leaf is in PartIDKeys
		*/
		virtual bool ConsistentPartIDKeys(EnumPartIDKey key) const;


		/**
		* Gets a list of all valid pipe part keys for this resource
		*
		* @return vWString: list of all PipePartIDKeys
		*/
		vWString GetPipePartIDKeys() const;

		/**
		* Tests, if this leaf has a PipePartIDKey as specified by key
		*
		* @param EnumPipePartIDKey key: the PipePartIDKey attribute name
		* @return bool: true if key exists in this leaf or below
		*
		* @throws JDFException if the specified key is illegal
		*
		* @throws JDFException if the specified key is illegal
		*/
		bool HasPipePartIDKey(EnumPartIDKey key)const;

		/**
		* Converts a PipePartIDKey string into the corresponding enum
		*
		* @param WString& key: the PipePartIDKey attribute name
		* @return EnumPipePartIDKey: the PipePartIDKey attribute 
		*/
		static EnumPartIDKey GetPipePartIDKeyEnum(const WString& key);

		/**
		* Sets the value of attibute, specified by key 
		*
		* @param EnumPipePartIDKey key: the PipePartIDKey attribute name
		* @param WString& value: the value to set key to
		*/
		void SetPipePartIDKey(EnumPartIDKey key, const WString&value );

		/**
		* Tests, if this leaf has a consistent PartIDKey as specified by key
		*
		* @param EnumPipePartIDKey key: the PipePartIDKey attribute name
		* @return bool: true, if key exists in this leaf is in PipePartIDKeys
		*/
		virtual bool ConsistentPipePartIDKeys(EnumPartIDKey key) const;


		/**
		* Gets the vector of parts (resource leaves or nodes) that match mAttribute
		*
		* @param mAttribute m: the map of key-value partitions (where key - PartIDKey, value - its value)
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @return vElement: the vector of matching resource leaves or nodes
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		vElement GetPartitionVector(const mAttribute& m, EnumPartUsage partUsage=PartUsage_Unknown)const;

		/**
		* Gets the vector of parts that matches specified key-value pair
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @param WString& value: the string value of the partition key
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @return vElement: the vector matching resource leaves or nodes
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		vElement GetPartitionVector(EnumPartIDKey key, const WString & value, EnumPartUsage partUsage=PartUsage_Unknown)const;

		/**
		* Gets the part that best matches mAttribute
		*
		* If parts are distributed over multiple children, the closest common ancestor of all matching children is returned.<br>
		* Therefore it is recommended to use GetPartitionVector in case multiple parts are anticipated<br>
		* If Partmap is already non-ovelapping, i.e. keys with different values than those specified in mAttribute exist, a null resource is returned
		* 
		*
		* @param mAttribute m: the map of key-value partitions (where key - PartIDKey, value - its value)
		* @param bool bIncomplete: if true use PartUsage_Implicit, else PartUsage_Explicit
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @return JDFResource: the first matching resource leaf or node
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		JDFResource GetPartition(const mAttribute& m, EnumPartUsage partUsage=PartUsage_Unknown)const;

		/**
		* If parts are distributed over multiple children, the closest common ancestor of all matching children is returned.<br>
		* Therefore it is recommended to use GetPartitionVector in case multiple parts are anticipated<br>
		* If Partmap is already non-ovelapping, i.e. keys with different values than those specified in mAttribute exist, a null resource is returned
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @param WString& value: the string value of the partition key
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @return JDFResource: the first matching resource leaf or node
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		JDFResource GetPartition(EnumPartIDKey key, const WString & value, EnumPartUsage partUsage=PartUsage_Unknown)const;

		/**
		* Gets the vector of parts (resource leaves or nodes) that match mAttribute
		*
		* @param mAttribute m: the map of key-value partitions (where key - PartIDKey, value - its value)
		* @param bool bIncomplete: if true use PartUsage_Implicit, else PartUsage_Explicit
		* @deprecated use signature with enumPartUsage! will be time-bombed October 1 2006
		* @return vElement: the vector of matching resource leaves or nodes
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		vElement GetPartitionVector(const mAttribute& m, bool bIncomplete)const;

		/**
		* Gets the vector of parts that matches specified key-value pair
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @param WString& value: the string value of the partition key
		* @param bool bIncomplete: if true use PartUsage_Implicit, else PartUsage_Explicit
		* @deprecated use signature with enumPartUsage! will be time-bombed October 1 2006
		* @return vElement: the vector matching resource leaves or nodes
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		vElement GetPartitionVector(EnumPartIDKey key, const WString & value, bool bIncomplete)const;

		/**
		* Gets the part that best matches mAttribute
		*
		* If parts are distributed over multiple children, the closest common ancestor of all matching children is returned.<br>
		* Therefore it is recommended to use GetPartitionVector in case multiple parts are anticipated<br>
		* If Partmap is already non-ovelapping, i.e. keys with different values than those specified in mAttribute exist, a null resource is returned
		* 
		*
		* @param mAttribute m: the map of key-value partitions (where key - PartIDKey, value - its value)
		* @param bool bIncomplete: if true use PartUsage_Implicit, else PartUsage_Explicit
		* @deprecated use signature with enumPartUsage! will be time-bombed October 1 2006
		* @return JDFResource: the first matching resource leaf or node
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		JDFResource GetPartition(const mAttribute& m, bool bIncomplete)const;

		/**
		* If parts are distributed over multiple children, the closest common ancestor of all matching children is returned.<br>
		* Therefore it is recommended to use GetPartitionVector in case multiple parts are anticipated<br>
		* If Partmap is already non-ovelapping, i.e. keys with different values than those specified in mAttribute exist, a null resource is returned
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @param WString& value: the string value of the partition key
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @return JDFResource: the first matching resource leaf or node
		* @throws JDFException if the map contains keys that are not JDF defined partition keys
		*/
		JDFResource GetPartition(EnumPartIDKey key, const WString & value, bool bIncomplete)const;
		/**
		* Recursively adds the partition leaves defined in vPartMap
		*
		* @param vmAttribute vPartMap: the vector of maps of part keys
		* @param vWString vPartIDKeys: the vector of partIDKeys strings of the resource. 
		*	If empty (the default) the Resource PartIDKeys attribute is used
		* @return vElement the vector of newly created partitions
		* @since 050708 The routine now returns the vector of created resources
		*
		* @throws JDFException if there are in the partMap not matching partitions 
		* @throws JDFException if there is an attempt to fill non-matching partIDKeys
		* @throws JDFException if by adding of last partition key there is either non-continuous partmap or left more than one key
		*/
		vElement CreatePartitions(const vmAttribute& vPartMap, const vWString& vPartIDKeys=vWString::emptyvStr);

		/**
		* Recursively adds the partition leaves defined in partMap
		*
		* @param mAttribute partMap: the map of part keys
		* @param vWString vPartIDKeys: the vector of partIDKeys strings of the resource. 
		*	If empty (the default) the Resource PartIDKeys attribute is used
		* @return JDFResource: the last created partition leaf
		*
		* @throws JDFException if there are in the partMap not matching partitions 
		* @throws JDFException if there is an attempt to fill non-matching partIDKeys
		* @throws JDFException if by adding of last partition key there is either non-continuous partmap or left more than one key
		*/
		JDFResource GetCreatePartition(const mAttribute& partMap, const vWString& vPartIDKeys=vWString::emptyvStr);

		/**
		* Gets the first part that matches key-value
		* if it does not exist, create it
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @param WString & value: the string value of the partition key
		* @return JDFResource: the matching resource
		*/
		JDFResource GetCreatePartition(EnumPartIDKey key, const WString & value, const vWString& vPartIDKeys=vWString::emptyvStr);

		/**
		* Gets a list of the values for attribute part type within the leaves
		*
		* @param EnumPartIDKey key: the PartIDKey attribute name
		* @return vWString: a list of values of the specifird partition key
		*/
		vWString GetPartValues(EnumPartIDKey key)const;

		/**
		* Gets a list of all direct or indirect leaves
		*
		* @param bool bIntermediate: if true also include intermediate nodes including this
		* @return vElement: the vector of all leaves
		*/
		vElement GetLeaves(bool bIntermediate=false)const;

		/**
		* Tests, whether 'this' is the end of a partition (i.e. there is no element with the same name directly below)
		*
		* @return bool: true, if 'this' is a leaf
		*/
		bool IsLeaf()const;

		/**
		* Tests, whether 'this' is root of partition (i.e. there is no element with the same name over 'this')
		*
		* @return bool: true, if 'this' is a root
		*/
		bool IsRootElement()const;

		/**
		* Tests, whether the first ancestor of 'this' is in ValidParentNodeNames - must be one of:
		* DropItemIntent,CustomerInfo,NodeInfo,ResourcePool,PipeParams,ResourceInfo,ResourceCmdParams
		*
		* @return bool: true, if 'this' is a root resource
		*/
		bool IsResourceRoot()const;

		/**
		* Tests, whether the first ancestor of 'this' is ValidRootParentNodeNames - must be one of:
		* ResourcePool,PipeParams,ResourceInfo,ResourceCmdParams
		*
		* @return boolean: true if this lives as a root resource in the ResourcePool
		*/
		bool IsResourceRootRoot()const;


		/**
		* Tests, if the first ancestor with a name different from the node name is not one of
		* DropItemIntent,CustomerInfo,NodeInfo,ResourcePool,PipeParams,ResourceInfo,ResourceCmdParams. <br>
		* In other words if this resource is a subelement but not a resourceroot
		*
		* @return bool: true, if this is a subelement but not a root
		*/
		bool IsResourceElement()const;


		/**
		* Tests, if 'this' is a Resource - always true
		*
		* @param bool createFactory if true generate a factory class and recursively check 
		* internally required in order to avoid infinite loops - dummy in this instance
		* @return bool: true if 'this' is a resource and a resource root
		*/
		virtual bool IsResource(bool createFactory=true)const;

		/**
		* Adds a new part to this node
		* also handles PartIDKeys in the root etc.
		*
		* @param EnumPartIDKey partType: part type of a new part
		* @param WString & value: its value
		* @return JDFResource: newly created part
		* @throws JDFException if this is not a root resource
		*/
		JDFResource AddPartition(EnumPartIDKey partType, const WString &  value);

		/**
		* Creates parts of part type 'partType' with values as defined in 'values';
		* the number of values is defined by the number of elements in 'values'
		*
		* @param EnumPartIDKey partType: part type of a new part
		* @param WString & values: its value
		* @return vElement: vector of newly created parts
		* @throws JDFException if this is not a root resource
		*/
		vElement AddPartitions(EnumPartIDKey partType,const vWString &  values);

		/**
		* Gets all children from the actual element matching the given conditions
		* also get the non-overwritten elements in the parents for partitioned resources
		*
		* @param WString& element: elementname you are searching for
		* @param WString& nameSpaceURI: nameSpace you are searching for
		* @param mAttribute& mAttrib: attributes you are lokking for
		* @pasram bool bAnd: if true, a child is only added if it has all attributes specified in Attributes mAttrib
		* @param unsigned int maxSize: maximum size of the element vector
		* @param bool bResolveTarget: if true, IDRef elements are followed, dummy at this level but needed in JDFElement
		* @return vElement: vector with all found elements
		*/
		virtual vElement GetChildElementVector(const WString & element=WString::star, const WString & nameSpaceURI=WString::emptyStr, const mAttribute& mAttrib=mAttribute::emptyMap, bool bAnd=true, unsigned int maxSize=0,bool bResolveTarget=false)const;

		/**
		* The same as KElement::GetElement but also follows References and searches parents
		*
		* @param WString& nodeName: name of the child node to get
		* @param WString& nameSpaceURI: namespace to search for
		* @param int iSkip: get the iSkipth element that fits
		* @return KElement: the matching element
		*/
		virtual KElement GetElement(const WString& nodeName, const WString & nameSpaceURI=WString::emptyStr, int iSkip=0)const;

		/**
		* Recursive GetElement that also checks parent nodes up to the part root
		*
		* @param WString& nodeName: name of the child node to get
		* @param WString& nameSpaceURI: namespace to search for
		* @param int iSkip: get the iSkipth element that fits
		* @return KElement: the matching element
		*/
		virtual KElement GetCreateElement(const WString &  nodeName, const WString & nameSpaceURI=WString::emptyStr, int iSkip=0);

		/**
		* Removes children that match nodeName and nameSpaceURI
		* also removes elements in the parent node
		* @param WString& nodeName: name of the child node to get, if empty or "*" remove all
		* @param WString& nameSpaceURI: namespace to search for
		*/
		virtual void RemoveChildren(const WString& nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Removes child node that matches nodeName and nameSpaceURI
		* also removes element in the parent node
		*
		* @param WString& nodeName: name of the child node to remove,f empty or "*" remove all
		* @param WString& nameSpaceURI: namespace to search for
		* @param int n: number of nodes to skip before deleting
		* @return KElement: the removed node
		*/
		virtual KElement RemoveChild(const WString & nodeName,const WString & nameSpaceURI=WString::emptyStr,unsigned int n=0);

		/**
		* Gets an attribute value. Also follows partition parents to the resource root
		*
		* @param WString& attrib: attribute name to get
		* @param WString& nameSpaceURI: namespace to search for
		* @param WString& def: attribute default that is returned if no attribute exists
		* @return WString: attribute value
		*/
		virtual WString GetAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr, const WString &def=WString::emptyStr) const;

		/**
		* Checks if the actual element has a specific attribute<br>
		* this version checks within the resource and its partitioned parent xml elements
		*
		* @param WString attrib: the name of the attribute to look for
		* @param WString nameSpaceURI: the nameSpace to look in
		* @param bool bInherit: if true also check recursively in inherited elements, regardless of partitioning
		* @return bool: true, if the attribute is present
		*/
		virtual bool HasAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr, bool bInherit=false) const;

		/**
		* The same as JDFResource::NumChildElements but also follows References
		*
		* @param WString & nodeName: the nodes to count
		* @param WString & nameSpaceURI: the nameSpace to look in
		* @return int: the number of child elements
		*/
		virtual int NumChildElements(const WString & nodeName=WString::emptyStr,const WString & nameSpaceURI=WString::emptyStr)const;		

		/**
		* Gets the number of attributes for this element, 
		* including the inherited attributes in ancestor partitions
		*
		* @return int: number of attributes
		*/
		virtual int NumAttributes()const;

		/**
		* Gets all local attribute names as an vector of strings
		*
		* @return vWString: the vector of attribute names
		*/
		virtual vWString GetAttributeVector()const;

		/**
		* Removes attribute if it is explicitly in this leaf
		*
		* @param WString & attrib: the attribute key to remove
		* @param WString & nameSpaceURI: the attribute nameSpaceURI to remove
		*/
		virtual void RemoveAttribute(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Removes attribute including all overwritten leaves below
		*
		* @param WString & attrib: the attribute key to remove
		* @param WString & nameSpaceURI: the attribute nameSpaceURI to remove
		*/
		void RemoveAttributeFromLeaves(const WString & attrib, const WString & nameSpaceURI=WString::emptyStr);

		/**
		* Gets the parent element that actually contains the attribute key in a partitioned resource
		*
		* @param WString &key: attribute key to look for
		* @return JDFResource: the parent element that actually contains the attribute key
		*/
		JDFResource GetAttributePart(const WString &key)const;

		/**
		* Gets a unique vector of resource leaf elements that actually contain the attribute key
		*
		* @param WString &key: attribute key to look for
		* @return vElement: a vector of resource leaf elements that actually contain the attribute key
		*/
		vElement GetAttributePartVector(const WString &key)const;

		/**
		* Reduces partition so that only the parts that overlap with vResources remain
		*
		* @param vmAttribute & vValidParts: vector of partmaps that define the individual valid parts
		* the individual PartMaps ar ored to define the final resource
		*/
		void ReducePartitions(const vmAttribute & vValidParts);

		/**
		* Expand so that each leaf is complete (except for ID)
		*
		* @param bool bDeleteFromNode: removes all intermediate elements and attributes
		*/
		void Expand(bool bDeleteFromNode=false);

		/**
		* collapse all redundant attributes and elements
		*
		* @param bool bCollapseToNode: only collapse redundant attriutes and elements that pre-exist in the nodes
		*/
		void Collapse(bool bCollapseToNode=false);

		/**
		* Enumeration for the policy of merging the amounts from ResourceLinks <p>
		*	AmountMerge_none does not recalculate amounts
		*	AmountMerge_LinkOnly calculates the Resource Amount based on the Amount values in the ResourceLinks only. The original Resource Amount is ignored
		*	AmountMerge_UpdateLink calculates the Resource Amount based on the difference of previous and current resource link amounts
		*/
		enum EnumAmountMerge{AmountMerge_None,AmountMerge_LinkOnly,AmountMerge_UpdateLink};

		/**
		* Merges partitioned resources into this resource
		* uses PartIDKey to identify the correct resources
		*
		* @param JDFResource& resToMerge: the resource leaf to merge into this
		* @param WString & spawnID: the spawnID of the spawning that will now be merged
		* @param EnumAmountMerge amountPolicy: how to clean up the Resource amounts after merging
		* @param bool  bLocalResource: must be true for the local resources in a spawned node and its subnodes, which default to RW
		*
		* @throws JDFException if here is an attempt to merge incompatible resources 
		* @throws JDFException if here is an attempt to merge incompatible partitions
		*/
		void MergePartition (const JDFResource& resToMerge, const WString & spawnID, EnumAmountMerge amountPolicy=AmountMerge_None, bool bLocalResource=false);

		/**
		* Update the amount of a resource based on the connected resource links
		*
		* @param double previousAmount: the previous resource Amount
		*/
		void UpdateAmounts(double previousAmount);

		/**
		* Merges the spawnIDs of the various partitions <br>
		* also update SpawnStatus, if necessary <br>
		* this routine is needed to correctly handle nested spawning and merging
		*
		* @param JDFResource& resToMerge: the resource with potentially new spawnIDs
		* @param vWString& previousMergeIDs: vector of already merged spawnIDs that may still be in a partition
		*/
		void MergeSpawnIDs(const JDFResource& resToMerge,const vWString& previousMergeIDs);

		/**
		* Finds the canonical vector of parts that defines the vector of parts that fits to vParts
		* if all children of a parent node are in vParts, they are replaced by their parent. <br>
		* for example the canonical vector of all leaves is the root
		*
		* @param vmAttribute& vParts: the vector of parts to check against this
		* @return vmAttribute: the canonical vector
		*/
		vmAttribute ReducePartVector(const vmAttribute& vParts)const;





		/**
		* Partition stuff
		*/
		//@{

		/**
		* Sets attribute BinderySignatureName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetBinderySignatureName(const WString& value);

		/**
		* Gets string attribute BinderySignatureName
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetBinderySignatureName() const;

		/**
		* Typesafe attribute validation of BinderySignatureName
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidBinderySignatureName(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute BlockName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetBlockName(const WString& value);

		/**
		* Gets string attribute BlockName
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetBlockName() const;

		/**
		* Typesafe attribute validation of BlockName
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidBlockName(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute BundleItemIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetBundleItemIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute BundleItemIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetBundleItemIndex() const;

		/**
		* Typesafe attribute validation of BundleItemIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidBundleItemIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute CellIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetCellIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute CellIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetCellIndex() const;

		/**
		* Typesafe attribute validation of CellIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidCellIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute Condition
		*
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetCondition(WString value);

		/**
		* Gets string attribute Condition
		*
		* @return WString: the attribute value
		*/
		virtual WString GetCondition() const;

		/**
		* Typesafe attribute validation of Condition
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidCondition(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute DocCopies
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetDocCopies(JDFIntegerRangeList value);

		/**
		* Gets range attribute DocCopies
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetDocCopies() const;

		/**
		* Typesafe attribute validation of DocCopies
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidDocCopies(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute DocIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetDocIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute DocIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetDocIndex() const;

		/**
		* Typesafe attribute validation of DocIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidDocIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute DocRunIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetDocRunIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute DocRunIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetDocRunIndex() const;

		/**
		* Typesafe attribute validation of DocRunIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidDocRunIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute DocSheetIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetDocSheetIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute DocSheetIndex
		*
		* @return JDFIntegerRangeList: the attribute value
		*/
		virtual JDFIntegerRangeList GetDocSheetIndex() const;

		/**
		* Typesafe attribute validation of DocSheetIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidDocSheetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute FountainNumber
		*
		* @param int value: the value to set the attribute to
		*/
		virtual void SetFountainNumber(int value);

		/**
		* Gets integer attribute FountainNumber
		*
		* @return int: the attribute value 
		*/
		virtual int GetFountainNumber() const;

		/**
		* Typesafe attribute validation of FountainNumber
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidFountainNumber(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute ItemNames
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetItemNames(const WString& value);

		/**
		* Gets string attribute ItemNames
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetItemNames() const;

		/**
		* Typesafe attribute validation of ItemNames
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidItemNames(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute LayerIDs
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetLayerIDs(JDFIntegerRangeList value);

		/**
		* Gets range attribute LayerIDs
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetLayerIDs() const;

		/**
		* Typesafe attribute validation of LayerIDs
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidLayerIDs(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute Location
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetLocation(const WString& value);

		/**
		* Gets string attribute Location
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetLocation() const;

		/**
		* Typesafe attribute validation of Location
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidLocation(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute Option
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetOption(const WString& value);

		/**
		* Gets string attribute Option
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetOption() const;

		/**
		* Typesafe attribute validation of Option
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidOption(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute PageNumber
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetPageNumber(JDFIntegerRangeList value);

		/**
		* Gets range attribute PageNumber
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetPageNumber() const;

		/**
		* Typesafe attribute validation of PageNumber
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidPageNumber(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute PartVersion
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetPartVersion(const WString& value);

		/**
		* Gets string attribute PartVersion
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetPartVersion() const;

		/**
		* Typesafe attribute validation of PartVersion
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidPartVersion(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute PreflightRule
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetPreflightRule(const WString& value);

		/**
		* Gets string attribute PreflightRule
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetPreflightRule() const;

		/**
		* Typesafe attribute validation of PreflightRule
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidPreflightRule(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute PreviewType
		*
		* @param EnumPreviewType value: enumeration value of attribute PreviewType to be set 
		*/
		virtual void SetPreviewType( JDFPart::EnumPreviewType value);

		/**
		* Gets typesafe enumerated value of attribute PreviewType
		*
		* @return EnumPreviewTypethe: the enumeration value of attribute
		*/
		virtual JDFPart::EnumPreviewType GetPreviewType() const;

		/**
		* Typesafe attribute validation of PreviewType
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidPreviewType(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute RibbonName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetRibbonName(const WString& value);

		/**
		* Gets string attribute RibbonName
		*
		* @return WString: the attribute value
		*/
		virtual WString GetRibbonName() const;

		/**
		* Typesafe attribute validation of RibbonName
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidRibbonName(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute Run
		*
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetRun(const WString& value);

		/**
		* Gets string attribute Run
		*
		* @return WString: the attribute value
		*/
		virtual WString GetRun() const;

		/**
		* Typesafe attribute validation of Run
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidRun(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute RunIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetRunIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute RunIndex
		*
		* @return JDFIntegerRangeList: the attribute value
		*/
		virtual JDFIntegerRangeList GetRunIndex() const;

		/**
		* Typesafe attribute validation of RunIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidRunIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute RunTags
		*
		* @param vWString& value: the value to set the attribute to
		*/
		virtual void SetRunTags(const vWString& value);

		/**
		* Gets NMTOKENS attribute RunTags
		*
		* @return vWString: the value of the attribute 
		*/
		virtual vWString GetRunTags() const;

		/**
		* Typesafe attribute validation of RunTags
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidRunTags(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute RunPage
		*
		* @param int value: the value to set the attribute to
		*/
		virtual void SetRunPage(int value);

		/**
		* Gets integer attribute RunPage
		*
		* @return int: the attribute value 
		*/
		virtual int GetRunPage() const;

		/**
		* Typesafe attribute validation of RunPage
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidRunPage(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SectionIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSectionIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute SectionIndex
		*
		* @return JDFIntegerRangeList: the attribute value
		*/
		virtual JDFIntegerRangeList GetSectionIndex() const;

		/**
		* Typesafe attribute validation of SectionIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSectionIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute Separation
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetSeparation(const WString& value);

		/**
		* Gets string attribute Separation
		*
		* @return WString: the attribute value
		*/
		virtual WString GetSeparation() const;

		/**
		* Typesafe attribute validation of Separation
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSeparation(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SetDocIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSetDocIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute SetDocIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetSetDocIndex() const;

		/**
		* Typesafe attribute validation of SetDocIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSetDocIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SetIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSetIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute SetIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetSetIndex() const;

		/**
		* Typesafe attribute validation of SetIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SetRunIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSetRunIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute SetRunIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetSetRunIndex() const;

		/**
		* Typesafe attribute validation of SetRunIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSetRunIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SheetIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSheetIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute SheetIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetSheetIndex() const ;

		/**
		* Typesafe attribute validation of SheetIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSheetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SetSheetIndex
		*
		* @param JDFIntegerRangeList value: the value to set the attribute to
		*/
		virtual void SetSetSheetIndex(JDFIntegerRangeList value);

		/**
		* Gets range attribute SetSheetIndex
		*
		* @return JDFIntegerRangeList: the attribute value 
		*/
		virtual JDFIntegerRangeList GetSetSheetIndex() const ;

		/**
		* Typesafe attribute validation of SetSheetIndex
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSetSheetIndex(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SheetName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetSheetName(const WString& value);

		/**
		* Gets string attribute SheetName
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetSheetName() const;

		/**
		* Typesafe attribute validation of SheetName
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSheetName(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute Side
		*
		* @param EnumSide value: enumeration value of attribute Side to be set
		*/
		virtual void SetSide(JDFPart::EnumSide value);

		/**
		* Gets typesafe enumerated value of attribute Side
		*
		* @return EnumSide: the enumeration value of the attribute
		*/
		virtual JDFPart::EnumSide GetSide() const;

		/**
		* Typesafe attribute validation of Side
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSide(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute SignatureName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetSignatureName(const WString& value);

		/**
		* Gets string attribute SignatureName
		*
		* @return WString: the attribute value
		*/
		virtual WString GetSignatureName() const;

		/**
		* Typesafe attribute validation of SignatureName
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidSignatureName(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute TileID
		*
		* @param JDFXYPair value: the value to set the attribute to
		*/
		virtual void SetTileID(JDFXYPair value);

		/**
		* Gets XYPair attribute TileID
		*
		* @return JDFXYPair: the attribute value 
		*/
		virtual JDFXYPair GetTileID() const ;

		/**
		* Typesafe attribute validation of TileID
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidTileID(EnumValidationLevel level=ValidationLevel_Complete) const;


		/**
		* Sets attribute WebName
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetWebName(const WString& value);

		/**
		* Gets string attribute WebName
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetWebName() const;

		/**
		* Typesafe attribute validation of WebName
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidWebName(EnumValidationLevel level=ValidationLevel_Complete) const;
		/**
		* Sets attribute WebProduct
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetWebProduct(const WString& value);

		/**
		* Gets string attribute WebProduct
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetWebProduct() const;

		/**
		* Typesafe attribute validation of WebProduct
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidWebProduct(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* Sets attribute WebSetup
		*
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetWebSetup(const WString& value);

		/**
		* Gets string attribute WebSetup
		*
		* @return WString: the attribute value 
		*/
		virtual WString GetWebSetup() const;

		/**
		* Typesafe attribute validation of WebSetup
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		virtual bool ValidWebSetup(EnumValidationLevel level=ValidationLevel_Complete) const;
		//////////////////////////////////////////////////////////////////////////////////
		/**
		* Sets attribute DeliveryUnit
		* 
		* @param iUnit a value between 0 and 9 to set DeliveryUnit<iUnit>
		* @param value the value to set the attribute to
		*/
		void setDeliveryUnit(int iUnit, const WString& value);

		/**
		* Gets attribute DeliveryUnit
		* 
		* @param iUnit a value between 0 and 9 to set DeliveryUnit<iUnit>
		*
		* @return in the attribute value 
		*/
		WString getDeliveryUnit(int iUnit) const;

		/**
		* Typesafe attribute validation of DeliveryUnit
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true, if valid
		*/
		bool validDeliveryUnit(int iUnit, EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* end of partition stuff
		*/
		//@}




		//@{
		/** 
		* Gets of 'this' the iSkip-th child Update element 
		*
		* @param int iSkip: number of child Update elements to skip
		* @return JDFResource: the matching Resource Update element
		*/
		JDFResource GetUpdate(int iSkip=0)const;

		/**
		* Gets of 'this' child Update element with an appropriate UpdateID
		*
		* @param WString& updateID: UpdateID of the element to get
		* @return JDFResource: the matching Update element
		*/
		JDFResource GetUpdate(const WString& updateID)const;

		/**
		* Gets of 'this' a vector of all Update elements
		*
		* @return vElement: vector of all Resource Update elements in 'this'
		*/
		vElement GetUpdateVector()const;

		/**
		* Removes of 'this' child Update element with an appropriate UpdateID
		*
		* @param WString& updateID: UpdateID of the element to remove
		*/
		void RemoveUpdate(const WString & updateID);

		/**
		* Removes of 'this' the iSkip-th child Update element
		*
		* @param int iSkip: number of child Update elements to skip
		*/
		void RemoveUpdate(int iSkip=0);

		/**
		* Appends to 'this' a resource Update element with an appropriate UpdateID
		*
		* @param WString& updateID: updateID of the new Update element 
		* @return JDFResource: newly created Resource Update element
		*
		* @throws JDFException: if Update element with such ID already exists
		*/
		JDFResource AppendUpdate(const WString& updateID=WString::emptyStr);

		/**
		* Gets of 'this' the number of child Update elements
		*
		* @return int: number of Update elements in 'this'
		*/
		int NumUpdates() const;

		/**
		* Tests, whether in 'this' any child Update elements already exist 
		*
		* @return bool: true, if 'this' has already one or more Update elements  
		*/
		inline bool HasUpdate() const {return NumUpdates()>0;};

		/**
		* Gets the qualified node name of resource Update based on 'this'
		*
		* @return WString: the mangled node name
		*/
		WString GetUpdateName() const;
		//@}


		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */

		//@{
		/** 
		* Gets of 'this' child Contact element, 
		* optionally creates it, if it doesn't exist.
		* 
		* @return JDFContact: the matching Contact element
		*/
		JDFContact GetCreateContact();

		/**
		* Gets of 'this' an existing child Contact element  
		*
		* @return JDFContact: the matching Contact element
		*/
		JDFContact GetContact()const;

		/**
		* Appends new Contact element to the end of 'this'  
		*
		* @return JDFContact: newly created child Contact element
		*/
		JDFContact AppendContact();
		//@}
		//@{

		/** Get Element SourceResource
		* 
		* @param int iSkip number of elements to skip
		* @return JDFSourceResource The element
		*/
		JDFSourceResource GetCreateSourceResource(int iSkip=0);

		/**
		* const get element SourceResource
		* @param int iSkip number of elements to skip
		* @return JDFSourceResource The element
		*/
		JDFSourceResource GetSourceResource(int iSkip=0)const;
		/**
		* Append element SourceResource
		*/
		JDFSourceResource AppendSourceResource();
		//@}

		//@{
		/** 
		* Gets of 'this' child Location element,
		* optionally creates it, if it doesn't exist.
		*
		* @return JDFLocation: the matching Location element
		*/
		JDFLocation GetCreateLocationElement();

		/**
		* Gets of 'this' an existing child Location element 
		*
		* @return JDFLocation: element Location
		*/
		JDFLocation GetLocationElement()const;

		/**
		* Appends new child Location element to the end of 'this' 
		*
		* @return JDFLocation: newly created child Location element
		*/
		JDFLocation AppendLocationElement();

		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th QualityControlResult element,
		* optionally creates it, if it doesn't exist.
		* If iSkip is more than one larger that the number of elements
		* only one will be created and appended.
		*
		* @param int iSkip: number of child QualityControlResult elements to skip
		* @return JDFQualityControlResult: the matching QualityControlResult element
		*/
		JDFQualityControlResult GetCreateQualityControlResult(int iSkip=0);

		/** 
		* Gets of 'this' the iSkip-th child QualityControlResult element
		*
		* @param int iSkip: number of child QualityControlResult elements to skip, default=0
		* @return JDFQualityControlResult: the matching QualityControlResult element
		*/
		JDFQualityControlResult GetQualityControlResult(int iSkip=0)const;

		/**
		* Appends new child QualityControlResult element to the end of 'this' 
		*
		* @return JDFQualityControlResult: newly created child QualityControlResult element
		*/
		JDFQualityControlResult AppendQualityControlResult();

		//@}


		//@{
		/** 
		* Gets of 'this' the iSkip-th IdentificationField element,
		* optionally creates it, if it doesn't exist.
		* If iSkip is more than one larger that the number of elements
		* only one will be created and appended.
		*
		* @param int iSkip: number of child IdentificationField elements to skip
		* @return JDFIdentificationField: the matching IdentificationField element
		*/
		JDFIdentificationField GetCreateIdentificationField(int iSkip=0);

		/** 
		* Gets of 'this' the iSkip-th child IdentificationField element
		*
		* @param int iSkip: number of child IdentificationField elements to skip, default=0
		* @return JDFIdentificationField: the matching IdentificationField element
		*/
		JDFIdentificationField GetIdentificationField(int iSkip=0)const;

		/**
		* Appends new child IdentificationField element to the end of 'this' 
		*
		* @return JDFIdentificationField: newly created child IdentificationField element
		*/
		JDFIdentificationField AppendIdentificationField();

		//@}
		/**
		* append an empty GeneralID 
		* 
		* @return the newly created GeneralID
		*/
		JDFGeneralID appendGeneralID();

		/**
		* append a GeneralID with idValue, duplicate entries are retained
		* 
		* @param idUsage the IDUsage attribute of the generalID
		* @param idValue the IDValue attribute of the generalID
		* @return the newly created GeneralID
		*/
		JDFGeneralID appendGeneralID(const WString& idUsage, const WString& idValue);

		/**
		* gets attribute GeneralID
		* @param i get the i'th element that fits
		* @return the attribute value
		*/
		JDFGeneralID getGeneralID(int i)const;
		/**
		* Creates or Updates a GeneralID with the IDUsage idUsage and IDValue=idValue
		* all entries with a duplicate idUsage are removed
		* 
		* @param idUsage usage to set the attribute to
		* @param idValue   value to set the attribute to
		*/
		void setGeneralID(const WString& idUsage, const WString& idValue);

		/**
		* removes GeneralID with the IDUsage idUsage
		* 
		* @param idUsage value to get
		*/
		void removeGeneralID(const WString& idUsage=WString::emptyStr);

		/**
		* Gets IDValue of the GeneralID with IDUsage=idUsage
		*
		* @return double the attribute value
		*/
		WString getGeneralID(const WString& idUsage)const;
		/**
		* Validator of 'this'
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true, if 'this' is valid
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;

		/**
		* Version fixing routine
		*
		*
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);


		/**
		* Gets the id of a modified resource
		*
		* @return WString: the new id;
		* @throws JDFException if it is too many equivalent modified resources.
		*/
		WString NewModifiedID()const; 


		/**
		* Gets a list of all partition keys that this resource may be implicitly partitioned by
		* e.g. RunIndex for RunList...
		*
		* @return vint: vector of integers that must be casted to EnumPartIDKey
		*/
		virtual vint GetImplicitPartitions() const;

		/** 
		* level to required converter 
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if validation level is one of: Complete or RecursiveComplete
		*/
		virtual bool RequiredLevel(EnumValidationLevel level)const;

		/**
		* Tests if a spawn of the given partition of the resource is allowed
		* (by means of the JDF specification).
		* 
		* @param amPartMap Map of possible PartIDKeys
		* 
		* @return boolean - true if spawn is allowed.
		*/
		bool isSpawnAllowed();

		/**
		* set the partIDKeys attribute of the root of this
		* @param partIDKeys
		*/
		void setPartIDKeys(const vWString& partIDKeys);

		/**
		* Typesafe attribute validation of Class
		* 
		* corresponds to C++ JDFResource::ValidClass()
		* 
		* @param level level of attribute validation
		* @return boolean true, if valid
		*/
		bool validResourceClass(KElement::EnumValidationLevel level) const;

		/**
		* remove any resource specific attribute when making this to an element
		*/
		void cleanResourceAttributes();

		/**
		* deletes this if it is no longer linked by either resource refs or resource links
		* 
		* @return true if this has been deleted
		*/
		bool deleteUnLinked();
		/**
		* Gets all resourcelinks and refelements that link to this<br/>
		* note that this method may be tim consuming in a large loop <br/>
		* - in case of massive cleanup, use {@link LinkRefFinder} and access the complete map of references from within the loop @see {@link LinkRefFinder}
		* 
		* 
		* @param bLink if true, include resource links
		* @param bRef if true include resource refs
		* 
		* @return VElement - vector of all found elements, null if none found
		*/
		VElement getLinksAndRefs( bool bLink,  bool bRef);


	protected:

		/**
		* calculate a new level based on the status
		* @param KElement::EnumValidationLevel level
		* @return KElement::EnumValidationLevel level the modified level
		*/
		KElement::EnumValidationLevel IncompleteLevel(KElement::EnumValidationLevel level, bool bForce=false)const;

		/**
		* Gets a vector of matching parts from somewhere down there
		*
		* @param mAttribute &m: map of attributes that should fit;
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @param int matchingDepth number of elements in the map that have already been found
		* @return vElement: vector of matching resource nodes or leaves
		*/
		vElement GetDeepPartVector(const mAttribute &m, EnumPartUsage partUsage, int matchingDepth)const;	

		/**
		* Gets a matching part from somewhere down there
		* returns the closest ancestor of all matching elements within the target vector
		*
		* @param mAttribute &m: map of attributes that should fit;
		* @param EnumPartUsage partUsage: also accept nodes that are are not completely specified in the partmap, 
		*  e.g. if partitioned by run, RunPage and only Run is specified
		* @return JDFResource: the first found matching resource node or leaf
		*/
		JDFResource GetDeepPart(const mAttribute &m, EnumPartUsage partUsage=PartUsage_Implicit)const;

		/**
		* Adds a new PartIDKey to the root
		* first checks for existence
		*
		* @param EnumPartIDKey partType: new PartIDKey to add
		*
		* @throws JDFException if here is an attempt to add implicit partition
		*/
		void AddPartIDKey(EnumPartIDKey partType);

		/**
		* Adds a new PipePartIDKey to the root,
		* first checks for existence
		*
		* @param EnumPipePartIDKey partType: new PipePartIDKey to add
		* @throws JDFException if here is an attempt to add implicit partition
		*/
		void AddPipePartIDKey(EnumPartIDKey partType);

		/**
		* gets a prefix for ID creation for the element
		*
		* @return WString: a prefix for ID creation
		*/
		virtual WString GetIDPrefix() const;

		/**
		* list of valid node names of potential parents for a resource
		*
		* @return WString&: comma separated list of node names
		*/
		static const WString& ValidParentNodeNames();

		/**
		* list of valid node names of potential parents for a resource that impy a real resource root with class, id etc.
		*
		* @return WString&: comma separated list of node names
		*/
		static const WString& ValidRootParentNodeNames();

	private:
		/**
		* private implementor for GetResourceRoot
		*/
		JDFResource GetResourceRootImpl()const;

		/**
		* heuristic guess of the best possible partidkey sequence
		* @param partMap the partmap that we want to create
		* @param vPartIDKeys the known base partidkeys
		* @return the best guess vector of partidkeys
		*/
		vWString expandKeysFromNode(const mAttribute& partMap, const vWString& vPartIDKeys) const;

		mAttribute removeImplicitPartions(mAttribute & m) const;

		/**
		* reorder the partIDKeys used for generating the new partition based on existing partIDKeys
		* @param vPartKeys
		* @return VString the reordered VString of partIDKeys
		*/
		vWString reorderPartKeys(const vWString& vPartKeys);

		static bool bUnpartitiondImplicit;

	};
#define vResource vElement // deprecated legacy

};

#endif // !defined(__JDFRESOURCE_H__)
