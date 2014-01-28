#if !defined(_JDFNode_H__)
#define _JDFNode_H__

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
*    not be used to endorse or promfote products derived from this
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// 120700 RP GetLink added
// 180700 RP MyString -> WString : all strings now 16 bit
// 040900 RP renamed JDFProcess to JDFNode
// 040900 | RP | AddProcessGroup | Routine added
// 310801 | MM | GetInheritedElement | GetInheritedNodeInfo | GetInheritedCustomerInfo | GetActivation | IsActive
// 151101 | RP | GetInheritedElement | GetInheritedAttribute moved to KElement
// 090102 | RP | Spawning + merging added SpawnIDs, SpawnID, NewSpawnID and MergeID support
// 230102 | RP | added MergeNode
// 060202 | RP | modified spawning + merging so that spawning of partitioned nodes does not create new partitions
// 110202 | TG | added GetPartStatus SetPartStatus
// 120202 | RP | added ValidNodeNames, modified validators
// 220202 | RP | GetPredecessors added bRecurse parameter and recursion check, changed return type to vJDFNode
// 210302 | RP | added UnSpawn
// 300402 | RP | modified activation list
// 300402 | RP | added ProjectID support
// 020502 | RP | modified GetParentJDFNode()
// 030502 | RP | added 	bSpawnROPartsOnly to Spawn(...) and AddSpawnedResources(...)
// 180502 | RP | added GetAncestorAttribute(), HasAncestorAttribute()
// 270502 | RP | GetMatchingLinks() minor bug fixes
// 290502 | RP | renamed UnSpawn to UnSpawnNode()
// 290502 | RP | added GetAncestorElement(), HasAncestorElement()
// 100602 | RP | fixed StatusPool Handling in UnspawnNode() and SetPartStatus()
// 110602 | RP | GetMissingLinkVecor() bug fix
// 110602 | RP | removed GetAncestorNode -> use GetParentJDFNode instead
// 110602 | RP | calls to GetInheritedAttribute replaced by calls to GetAncestorAttribute
// 140602 | RP | calls to HasAttribute replaced by calls to HasAncestorAttribute
// 140602 | RP | AddSpawnedResources() bug fix for appending to rRefsRO / rRefsRW, remove call to SetLocked for root of partitioned resource
// 180602 | RP | MergePartition added calls to Expand() and Collapse()
// 200602 | RP | AddSpawnedResources() bug fix for  rRefsRW
// 260602 | RP | SetAmount() removed - was only useful for prototyping. Use dedicated SetAmount for the appropriate resources + ResourceLinks instead
// 260602 | RP | Added typesafe Tool Support
// 010702 | RP | AddSpawnedResources() bug fix for locks of partitioned resources
// 010702 | RP | GetAncestorIDs() inverted sequence
// 010702 | RP | AddSpawnedResources() bug fix for referenced resources in local resources
// 080802 | RP | StatusString() is now public
// 120802 | RP | Added Preview to list of potential generic resources
// 120802 | RP | GetMatchingIndex() add check for "*"
// 150802 | RP | enabled bInherit for Version attribute
// 160802 | RP | AddSpawnedResources() Massive cleanup for rRef referenced resources
//        | RP | Spawn() Gracefully handle implied partitions
// 190802 | RP | GetChildJDFNode(id) added
// 200802 | RP | Added check for resource IDs in AddSpawnedResources
//        | RP | vResource::Node() is now const
//        | RP | Added Preview support getter / setter routines etc.
// 300802 | RP | Spawn fixed handling of http / file prefix in SpawnURL
// 050902 | RP | AddSpawnedResources() major overhaul
// 050902 | RP | UnSpawnNode() major overhaul
// 100902 | RP | MapEnumToInfo > --> >=
// 130902 | RP | GetLinkedResources added
// 311002 | RP | Added numOccurrences to GetMatchingLinks
// 211102 | RP | CloneResourceToModify() added
// 211102 | RP | PrepareToModifyLink() added
// 190503 | RP | GetChildJDFNode() 
// 200503 | RP | added GetAncestorElementAttribute(), HasAncestorElementAttribute()
// 210703 | KM | changed return type from Spawn() to JDFDoc (old: JDFNode)
// 120803 | RP | IsExecutable() added bCheckChildren
// 010903 | RP | CleanUpMerge() added
// 010903 | RP | MergeJDF added cleanupPolicy and call to CleanUpMerge() 
// 071103 | RP | Added MergeAmounts 
// 140104 | RP | RemoveMatchingLinks bug fix 
// 260804 | RP | removed class vJDFNode. replace with vElement
// 221204 | RP | CopySpawnedResource moved from // JDFResourcePool::CopyResource()

// 100105 | ES | bug fix in GetType(),GetCategory(),GetNamedFeatures(),GetStatusDetails(),GetTemplate() - methods need no parameter 
// 080205 | RP | Added SpawnInformative()
// 170205 | RP | added AddInternalPipe()
// 220605 | RP | split MergeJDF into multiple routines for better readability
// 160806 | NB | added setCombined()
// 210806 | NB | added setPhase()
// 210806 | NB | added getEnumTypes()
// 210806 | NB | added getLinksForType()
// 210806 | NB | added getLinksForCombinedProcessIndex()
// 220806 | NB | added addExecutablePartitions()
// 230806 | NB | fixed SetType - now attribute "type" is removed correctly
// 250806 | NB | added EnumProcessUsageFromString()
// 250806 | NB | fixed addResource()
// 280806 | NB | fixed PrepareToModifyLink()
// 300806 | NB | fixed GetNodeInfo(), GetInheritedNodeInfo(), GetCustomerInfo(), GetInheritedCustomerInfo(), GetAncestorElement()
// 310806 | NB | fixed TypeLinkNames(), TypeLinkInfo()
// 310806 | NB | added getNiCi()
// 310806 | NB | fixed RemoveNodeInfos(), RemoveCustomerInfos()
// 010906 | NB | changed NodeInfo() access to public
// 040906 | NB | modified checkSpawnedResources(), Spawn(), SpawnInformative to use JDFSpawn
// 050906 | NB | modified MergeJDF()to use JDFMerge
// 050906 | NB | added getUnknownLinkVector()
// 080906 | NB | fixed IsValid()
// 250906 | NB | fixed GetparentIDs()
// 281106 | NB | fuxed IsExecutable()
// 250107 | NB | removed unreferenced variables
//
// JDFNode.h: interface for the JDFNode class.
// This class wraps all JDF nodes
//
//////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "JDFElement.h"
#include "JDFResource.h"
#include "JDFResourceAudit.h"
#include "JDFNodeInfo.h"
#include "JDFMISDetails.h"
#include "JDFDeviceInfo.h"

namespace JDF{

	class JDFResourcePool;	
	class JDFResourceLink;	
	class JDFResourceLinkPool;	
	class JDFStatusPool;	
	class JDFDoc;
	class JDFNode;
	class JDFNodeInfo;
	class JDFCustomerInfo;
	class JDFAuditPool;
	class JDFAudit;
	class JDFSpawned;
	class JDFAncestorPool;
	class JDFApprovalSuccess;
	class JDFDevice;
	class JDFEmployee;
	class JDFPreview;
	class JDFTool;
	class JDFBusinessInfo;
	class JDFMISDetails;
	class JDFNotificationFilter;
	class JDFCompany;
	class JDFCustomerMessage;
	class VoidSet;


	/**
	* the mother of all JDF nodes
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNode : public JDFElement{

	public:
		static const JDFNode DefJDFNode; 

		/**
		* Construction / Destruction
		*/
		inline JDFNode():JDFElement(){};

		/** 
		* Copy constructor <br>
		* Creates a new JDFNode object by copying the KElement object 'other'
		*/
		inline JDFNode(const KElement & other):JDFElement(){
			*this=other;
		};

		/**
		* Equivalence copy constructor <br>
		* Assignment of KElement object 'other' to the current JDFNode object
		*
		* @param KElement& other: KElement object to assign
		* @throws JDFException if constructor for JDFNode is invalid
		*/
		JDFNode& operator =(const KElement& other);

		/**
		* Destructor
		*/
		virtual ~JDFNode(){};

		/**
		* Enumeration for accessing typesafe nodes<p>
		*/
		enum EnumProcessUsage{ProcessUsage_Unknown,ProcessUsage_AnyInput,ProcessUsage_AnyOutput,ProcessUsage_Any,ProcessUsage_Jacket,ProcessUsage_Parent,ProcessUsage_Cover,ProcessUsage_Rejected,ProcessUsage_Accepted,ProcessUsage_Marks,ProcessUsage_Document,
			ProcessUsage_Surface,ProcessUsage_Waste,ProcessUsage_Proof,ProcessUsage_Input,ProcessUsage_Plate,ProcessUsage_Good,ProcessUsage_BookBlock,ProcessUsage_Box,ProcessUsage_CoverMaterial,ProcessUsage_SpineBoard,ProcessUsage_CoverBoard,ProcessUsage_Case,
			ProcessUsage_FrontEndSheet,ProcessUsage_BackEndSheet,ProcessUsage_Child,ProcessUsage_Mother,ProcessUsage_Book,ProcessUsage_Label,ProcessUsage_RingBinder};

		/**
		* Enumeration strings for ProcessUsage
		*
		* @return WString&: comma separated list of enumerated string values 
		*/
		static const WString& ProcessUsageString();

		/**
		* Enumeration string for enum value of ProcessUsage
		* Converts the value of type EnumProcessUsage into corresponding string value,  
		* f.e. for EnumProcessUsage with value 'ProcessUsage_Any' returns 'Any' 
		*
		* @param EnumProcessUsage value: ProcessUsage enumeration value to convert
		* @return WString: ProcessUsage string value
		*/
		static const WString ProcessUsageString(EnumProcessUsage processUsage);

		/**
		* Get the enumeration fitting this ProcessUsage, ProcessUsage_Unknown if non-standard
		* @param WString pu the string to convert to an enum
		* @return EnumProcessUsage the node's enumerated processusage
		*/
		static EnumProcessUsage EnumProcessUsageFromString(const WString& pu);

		/**
		* Enumeration for accessing typesafe node types<p>
		*
		*/
		enum EnumType{Type_Unknown,Type_Product,Type_ProcessGroup,Type_Combined,Type_Approval,Type_Buffer,Type_Combine,Type_Delivery,Type_ManualLabor,Type_Ordering
			,Type_Packing,Type_QualityControl,Type_ResourceDefinition,Type_Split,Type_Verification,Type_AssetListCreation,Type_Bending,Type_ColorCorrection,Type_ColorSpaceConversion,Type_ContactCopying
			,Type_ContoneCalibration,Type_CylinderLayoutPreparation,Type_DBDocTemplateLayout,Type_DBTemplateMerging,Type_DigitalDelivery,Type_FilmToPlateCopying,Type_FormatConversion,Type_ImageReplacement,Type_ImageSetting,Type_Imposition
			,Type_InkZoneCalculation,Type_Interpreting,Type_LayoutElementProduction,Type_LayoutPreparation,Type_PDFToPSConversion,Type_PDLCreation,Type_Preflight,Type_PreviewGeneration,Type_Proofing,Type_PSToPDFConversion
			,Type_RasterReading,Type_Rendering,Type_Scanning,Type_Screening,Type_Separation,Type_SoftProofing,Type_Stripping,Type_Tiling,Type_Trapping,Type_ConventionalPrinting
			,Type_DigitalPrinting,Type_IDPrinting,Type_AdhesiveBinding,Type_BlockPreparation,Type_BoxFolding,Type_BoxPacking,Type_Bundling,Type_CaseMaking,Type_CasingIn,Type_ChannelBinding
			,Type_CoilBinding,Type_Collecting,Type_CoverApplication,Type_Creasing,Type_Cutting,Type_Dividing,Type_Embossing,Type_EndSheetGluing,Type_Feeding,Type_Folding
			,Type_Gathering,Type_Gluing,Type_HeadBandApplication,Type_HoleMaking,Type_Inserting,Type_Jacketing,Type_Labeling,Type_Laminating,Type_LongitudinalRibbonOperations,Type_Numbering
			,Type_Palletizing,Type_Perforating,Type_PlasticCombBinding,Type_PrintRolling,Type_RingBinding,Type_SaddleStitching,Type_ShapeCutting,Type_Shrinking,Type_SideSewing,Type_SpinePreparation
			,Type_SpineTaping,Type_Stacking,Type_Stitching,Type_Strapping,Type_StripBinding,Type_ThreadSealing,Type_ThreadSewing,Type_Trimming,Type_WebInlineFinishing,Type_WireCombBinding
			,Type_Wrapping};

		/**
		* Enumeration strings for ProcessUsage
		*
		* @return WString&: comma separated list of enumerated string values 
		*/
		static const WString& TypeString();

		/**
		* typestring for the enumeration
		*
		* @return WString: string value of attribute Type 
		*/
		static WString TypeString(EnumType typ);


		/**
		* comma separated list of valid node names
		*
		* @return vWString&:
		*/
		static const vWString& TypeVector();


		/**
		* Gets the enumeration fitting this Type, TypeUnknown if non-standard
		*
		* @return EnumType the node's enumerated type
		*/
		EnumType GetEnumType()const;

		/**
		* Sets Type to the enumeration typ
		*
		* @param EnumType the node's enumerated type
		*/
		void SetEnumType(JDFNode::EnumType typ);

		/**
		* get the Types as a vWString of EnumType
		* @return vWString The vector of enumerated types, null if extensions exist that hinder us from generating a complete vector
		* e.g. extension types or gray box names
		*/
		vWString getEnumTypes();

		/**
		* Get the enumeration fitting this Type, Type_Unknown if non-standard
		* @param WString typ the string to convert to an enum
		* @return EnumType the node's enumerated type
		*/
		static EnumType EnumTypeFromString(const WString& typ);

		/**
		* is this the JDF root element, i.e. it has no JDF above it 
		* @ param void
		* @ return bool: true if this is a root
		*/
		bool IsJDFRoot()const;

		/**
		* definition of resource link names in the JDF namespace
		* @return WString list of resource names that may be linked
		*/
		const WString& GenericLinkNames()const;

		/**
		* definition of resource link usage, cardinality and ProcessUsage in the JDF namespace
		* @return WString list of resource information usages that may be linked, 
		*/
		const WString& GenericLinkInfo()const;
		/**
		* definition of resource link usage, cardinality and ProcessUsage in the JDF namespace
		* @return WString list of resource information usages that may be linked, 
		*/
		WString TypeLinkInfo(EnumType typeNum)const;

		/**
		* definition of resource link names in the JDF namespace
		* @return WString list of resource names that may be linked
		*/
		WString TypeLinkNames(EnumType typeNum)const;

		/**
		* definition of resource link usage, cardinality and ProcessUsage in the JDF namespace
		* @return WString list of resource information usages that may be linked, 
		*/
		WString LinkInfo()const;

		/**
		* definition of resource link names in the JDF namespace
		* @return WString list of resource names that may be linked
		*/
		WString LinkNames()const;

		/**
		* getLink - get the resourcelink that resides in the ResourceLinkPool of this node and references
		* the resource r
		* @param r      - the resource you are searching a link for
		* @param bInput - if true, get links with Usage="Input", else with Usage="Output"
		* @return JDFResourceLink - the resource link you were searching for, or an empty JDFResourceLink if not found
		* default: getLink(r, true)
		* @deprecated use getLink(resource, EnumUsage)
		*/
		JDFResourceLink GetLink(const JDFResource& r, bool bInput=true);		
		/**
		* getLink - get the resourcelink that resides in the ResourceLinkPool of this node and references
		* the resource r
		* @param r      - the resource you are searching a link for
		* @param usage  - the usage attribute of the link. If Usage_Unknown, both input and output resourelinks will be returned
		* @return JDFResourceLink - the resource link you were searching for, or an empty JDFResourceLink if not found
		*/
		JDFResourceLink getLink(const JDFResource& r, JDFResourceLink::EnumUsage usage=JDFResourceLink::Usage_Unknown);		

		/**
		* get the links that are selected by a given CombinedProcessIndex
		* all links with no CombinedProcessIndex are included in the list
		* 
		* @param combinedProcessIndex the nTh occurence of the CombinedProcessIndex 
		* field, -1 if all valid positions are ok
		* 
		* @default getLinksForCombinedProcessIndex(-1)
		*/
		vElement getLinksForCombinedProcessIndex(int combinedProcessIndex);

		/**
		* get the links that are selected by a given CombinedProcessIndex
		* all links with no CombinedProcessIndex are included in the list
		* 
		* @param type the process type for which to get the links
		* @param nType the nTh occurence of the Type field, -1 if all valid positions are ok
		* 
		* @default getLinksForType(type, -1)
		*/
		vElement getLinksForType(JDFNode::EnumType type, int nType);

		/**
		* getLinks - get the links matching mLinkAtt out of the resource link pool
		*
		* @param linkName - the name of the link including or excluding the "Link", 
		* If it is omitted, it will be added
		* @param mLinkAtt - the attributes to search for
		* @param linkNS - the namespace of the link
		*
		* @return VElement - all elements matching the condition mLinkAtt
		* default: getLinks(null,null,null)
		*/
		VElement getLinks(WString linkName, const JDFAttributeMap& mLinkAtt, const WString& linkNS=WString::emptyStr)const;

		/**
		* spawn a node; url is the file name of the new node,
		*
		* vRWResourceUsage is the vector of Resources Usages, Resource Names or Resource IDs that are
		* spawned RW, all others are spawned read only;
		* vParts is the vector of part maps that are to be spawned,
		* defaults to no part, i.e. the whole thing
		*
		* @param WString spawnURL: URL of the spawned JDF file
		* @param vWString vRWResourceUsage: vector of resource names and Usage / ProcessUsage that are spawned as rw <br>
		*		the format is one of:<br>
		*                     ResName<br>
		*                     ResName:Input<br>
		*		              ResName:Output<br>
		*		              ResName:ProcessUsage<br>
		*		              ID<br>
		* @param vmAttribute vParts: vector of mAttributes that describe the parts to spawn
		* @param bool bSpawnROPartsOnly if true, only the parts of RO resources that are specified in vParts are spawned, else the complete resource is spawned
		* @param bool bCopyNodeInfo copy the NodeInfo elements into the Ancestors
		* @param bool bCopyCustomerInfo copy the CustomerInfo elements into the Ancestors
		* @param bool bCopyComments if true, also copy the Comment elements into the ancestor
		* @return JDFDoc: The spawned node's owner document.
		* @deprecated - use JDFSpawn class 
		*
		* @since 2003-07-23 returns JDFDoc instead of JDFNode due to refCounting of the document
		*/
		JDFDoc Spawn(const WString &  parentURL, const WString& spawnURL=WString::emptyStr, 
			const vWString& vRWResourceUsage=vWString::emptyvStr, 
			const vmAttribute& vParts=vmAttribute::emptyvMap, 
			bool bSpawnROPartsOnly=false, bool bCopyNodeInfo=false, 
			bool bCopyCustomerInfo=false, bool bCopyComments=false);

		/**
		* spawn a node in informative mode without modifying the root JDF; url is the file name of the new node,
		* the parameters except for the list of rw resources, which are by definition empty, are identical to those of Spawn
		*
		* vRWResourceUsage is the vector of Resources Usages, Resource Names or Resource IDs that are
		* spawned RW, all others are spawned read only;
		* vParts is the vector of part maps that are to be spawned,
		* defaults to no part, i.e. the whole thing
		*
		* @param WString spawnURL: URL of the spawned JDF file
		* @param vmAttribute vParts: vector of mAttributes that describe the parts to spawn
		* @param bool bSpawnROPartsOnly if true, only the parts of RO resources that are specified in vParts are spawned, else the complete resource is spawned
		* @param bool bCopyNodeInfo copy the NodeInfo elements into the Ancestors
		* @param bool bCopyCustomerInfo copy the CustomerInfo elements into the Ancestors
		* @param bool bCopyComments if true, also copy the Comment elements into the ancestor
		* @return JDFDoc: The spawned node's owner document.
		* @deprecated USE JDFSpawn::spawnInformative()
		*
		*/
		JDFDoc SpawnInformative(const WString &  parentURL, const WString& spawnURL=WString::emptyStr, 
			const vmAttribute& vParts=vmAttribute::emptyvMap, bool bSpawnROPartsOnly=false, 
			bool bCopyNodeInfo=false, bool bCopyCustomerInfo=false, bool bCopyComments=false) const;

		/**
		* add any resources that live in ancestor nodes to this node
		* @param vWString vRWResourceUsage: vector of resource names and Usage / ProcessUsage that are spawned as rw <br>
		*		the format is one of:<br>
		*                     ResName<br>
		*                     ResName:Input<br>
		*		              ResName:Output<br>
		*		              ResName:ProcessUsage<br>
		*		              ID<br>
		* @param vmAttribute vParts: vector of mAttributes that describe the parts to spawn
		* @return vElement: vector of resources or resource partitions that would be spawned rw multiple times
		*/
		vElement CheckSpawnedResources(const vWString& vRWResourceUsage=vWString::emptyvStr, const vmAttribute& vParts=vmAttribute());		

		/** 
		* clone the target resource of this and generate a ResourceAudit in the parent node's AuditPool
		* both resourcelinks of the ResourceAudit are filled in<br>
		* the resource selected by this may now be modified. <br>
		* the cloned copy has a new Id in the format: (thisID)_old_nnn 
		*
		* @return the ResourceAudit that was created
		*/
		JDFResourceAudit CloneResourceToModify(const JDFResourceLink& resLink);

		/** 
		* Generate a ResourceAudit in the parent node's AuditPool
		* an initial copy of the not yet modified resourcelink is inserted<br>
		* call JDFResourceAudit::UpdateLink with the modified link to finalize
		*
		* @return the ResourceAudit that was created
		*/
		JDFResourceAudit PrepareToModifyLink(const JDFResourceLink& resLink);

		/**
		* Add a resource to resroot and link it to this process
		* <p> except when using this function for private exensions, the  typesafe extensions should be used
		* @param WString name: Name of the resource
		* @param JDFResource.Class: Class enumeration of the resource
		* @param bool bInput: true if linked as input
		* @param JDFNode resRoot: node where the ResourcePool resides
		* @param boolean bLink: link the resource, if true
		* @param String nameSpaceURI: namespace of the added resource
		* @param JDFResource& toReplace resource that should be replaced
		* @return JDFResource:
		* @deprecated
		*/
		JDFResource AddResource(const WString &  name, JDFResource::EnumClass resClass, bool bInput, JDFNode resRoot=JDFNode::DefJDFNode, bool bLink=true, const WString & nameSpaceURI=WString::emptyStr, const JDFResource & toReplace=JDFResource::DefJDFResource);

		/**
		* addResource - add a resource to resroot and link it to this process
		*
		* @param name      the localname of the resource
		* @param resClass  the JFD/@Class of the resource; if null, find the resource class from factory
		* @param usage    the Usage attrinute of the ResourceLink. if null, ther resource is not linked
		* @param processUsage     The processUsage attribute of the link to the resource
		* @param resRoot   the node where to add the Resource, if null defaults to this. Note that the link is always in this
		* @param nameSpaceURI the nsURI of the resource, if null take the default ns
		*
		* @return JDFResource
		* 
		* default: addResource(name, null, usage, null, null, null)
		*/
		JDFResource addResource(const WString & name,JDFResource::EnumClass resClass, JDFResourceLink::EnumUsage usage, const WString& procUsage=WString::emptyStr, JDFNode resRoot=JDFNode::DefJDFNode, const WString & nameSpaceURI=WString::emptyStr, const JDFResource & toReplace=JDFResource::DefJDFResource);
		/**
		* Add a parameter resource to resroot and link it to this process
		* <p> except when using this function for private exensions, the  typesafe extensions should be used
		* @param WString name: The name of the newly created parameter resource
		* @param bool bInput: true if linked as input
		* @param JDFNode resRoot: node where the ResourcePool resides
		* @param boolean bLink: link the resource, if true
		* @param String nameSpaceURI: namespace of the added resource
		* @param JDFResource& toReplace resource that should be replaced
		* @return JDFResource:
		*/
		JDFResource AddParameter(const WString &  name, bool bInput=true, JDFNode resRoot=JDFNode::DefJDFNode,bool bLink=true, const WString & nameSpaceURI=WString::emptyStr, const JDFResource & toReplace=JDFResource::DefJDFResource);

		/**
		* Add a consumable resource to resroot and link it to this process
		* <p> except when using this function for private exensions, the  typesafe extensions should be used
		* @param WString name: The name of the newly created Consumable resource
		* @param bool bInput: true if linked as input
		* @param JDFNode resRoot: node where the ResourcePool resides
		* @param boolean bLink: link the resource, if true
		* @param String nameSpaceURI: namespace of the added resource
		* @param JDFResource& toReplace resource that should be replaced
		* @return JDFResource:
		*/
		JDFResource AddConsumable(const WString &  name, bool bInput=true, JDFNode resRoot=JDFNode::DefJDFNode,bool bLink=true, const WString & nameSpaceURI=WString::emptyStr, const JDFResource & toReplace=JDFResource::DefJDFResource);

		/** Add an implementation resource to resroot and link it to this process
		* <p> except when using this function for private exensions, the  typesafe extensions should be used
		* @param WString name: The name of the newly created implementation resource
		* @param bool bInput: true if linked as input
		* @param JDFNode resRoot: node where the ResourcePool resides
		* @param boolean bLink: link the resource, if true
		* @param String nameSpaceURI: namespace of the added resource
		* @param JDFResource& toReplace resource that should be replaced
		* @return JDFResource:
		*/
		JDFResource AddImplementation(const WString &  name, bool bInput=true, JDFNode resRoot=JDFNode::DefJDFNode,bool bLink=true, const WString & nameSpaceURI=WString::emptyStr, const JDFResource & toReplace=JDFResource::DefJDFResource);

		/** Add a handling resource to resroot and link it to this process
		* <p> except when using this function for private exensions, the  typesafe extensions should be used
		* @param WString name: The name of the newly created handling resource
		* @param bool bInput: true if linked as input
		* @param JDFNode resRoot: node where the ResourcePool resides
		* @param boolean bLink: link the resource, if true
		* @param String nameSpaceURI: namespace of the added resource
		* @param JDFResource& toReplace resource that should be replaced
		* @return JDFResource:
		*/
		JDFResource AddHandling(const WString &  name, bool bInput=true, JDFNode resRoot=JDFNode::DefJDFNode,bool bLink=true, const WString & nameSpaceURI=WString::emptyStr, const JDFResource & toReplace=JDFResource::DefJDFResource);

		/**
		* Is this a Combined node type ?
		* return boolean: true if this is a combined node
		*/
		bool IsCombined()const;

		/**
		* Is this a ProcessGroup node type ?
		* return boolean: true if this is a ProcessGroup node
		*/
		bool IsProcessGroup()const;

		/**
		* Is this a Product node type ?
		* return boolean: true if this is a Product node
		*/
		bool IsProduct()const;

		/**
		* Is this a group node type (ProcessGroup or Product)?
		* return boolean: true if this is a Group node
		*/
		bool IsGroupNode()const;

		/**
		* update the status of a node depending on its resources and child nodes
		*/
		void UpDateStatus();

		/**
		* get a child node with a given jobpartid
		* @param String jobPartID_a: the ID of the part job
		* @param String jobID_a: the ID of the job
		* @return JDFNode: the JDFNode with the job part
		*/
		JDFNode GetJobPart(const WString &  jobPartID_a, const WString &  jobID_a=WString::emptyStr)const;

		/**
		* typesafe validator
		* @param EnumValidationLevel level validation level
		* @return bool true if this is valid
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;

		/**
		* definition of the allowed node names for elements of this type
		* @return comma separated list of valid node names, * if any
		*/
		virtual WString ValidNodeNames()const;

		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;

		/**
		* checks whether a node is executable by checking the resources linked by the resourcelinkpool
		* @param mAttribute partMap: the Attribute map of parts
		* @param bool bCheckChildren if true, calculates the availability Status of a resource from all child partition leaves, 
		* else the Status is taken from the appropriate leaf itself
		* @return bool: true if the node executable, false if not
		*/
		bool IsExecutable(const mAttribute & partMap=mAttribute::emptyMap,bool bCheckChildren=true);

		/**
		* get a vector of all direct predecessor or following nodes depending on bpre
		* @param boolean bPre: if true get predecessors, if false get following nodes
		* @param boolean bRecurse: if true recurse into previous nodes
		* @return vElement vector of pre / post decessor nodes
		*/
		vElement GetPredecessors(bool bPre=true, bool bRecurse=true)const;

		/**
		* get the resourcelinks in the resourcepool of this node
		* @param Attributes mLinkAtt: the map of attributes
		* @return vElement the vector of ResorceLinks:
		*/
		vElement GetResourceLinks(const mAttribute &mLinkAtt=mAttribute::emptyMap);

		/**
		* Get the linked resources matching some conditions<br>
		* combines all linked resources from ResourceLinkPool, CustomerInfo, NodeInfo and AuditPool
		*
		* @param mAttribute mResAtt: map of Resource attributes to search for
		* @param boolean bFollowRefs true if internal references shall be followed
		* @return vResource: vector with all elements matching the conditions
		*/
		vElement GetLinkedResources(const mAttribute &mResAtt=mAttribute::emptyMap, bool bFollowRefs=false)const;

		/**
		* Create a resourcelink to r and put it into the resourcelinkpool of this node
		*
		* @param JDFResource r: the resource to link
		* @param boolean input: if true, usage=input
		* @param boolean bForce: create a new resourcelink, even if a matching link already exists
		* @return JDFResourceLink: the newly created resource link
		* @deprecated use linkResource(enum)
		*/
		JDFResourceLink LinkResource(JDFResource r, bool input=true, bool bForce=false);

		/**
		* LinkResource: create a resourceLink in the resourceLinkPool that refers to 
		* the resource jdfResource 
		* also sets the appropriate combined process index
		* 
		*
		* @param jdfResource the resource or partition to link to
		* @param usage Usage of the resource
		* @param processUsage processUsage of the resource
		*
		* @return JDFResourceLink the new link
		* default: LinkResource(r, usage, null)
		*/
		JDFResourceLink linkResource(JDFResource jdfResource, JDFResourceLink::EnumUsage usage, EnumProcessUsage processUsage);

		/**
		* generic initialization
		* @param bool flush if true, clean this element
		* @param JDFRoot parent the parent that this is spawned from, defaults to null
		* @return bool true if successful
		*/
		bool init(bool flush=true,const JDFNode& parent=JDFNode::DefJDFNode);


		/**
		* Get the Parent JDF Node, null if the parent element is the document or an envelope xml
		* @return JDFNode: the parent JDF, null if this is the root JDF
		*/	
		JDFNode GetParentJDFNode()const;

		/**
		* Get a Child JDF Node with a given ID attribute
		*
		* @param WString id the id of the child
		* @param boolean bDirect: if true, only direct children, else recurse down the tree
		*
		* @return JDFNode: the parent JDF, null if this is the root JDF
		*/	
		JDFNode GetChildJDFNode(const WString& id, bool bDirect=false)const;

		/**
		* remove a node. If bLeaveSubmit is true, leave a stub with the id and status field
		* @param boolean bLeaveSubmit: if true, leave a stub with id and stauts field
		* @return void:
		*/
		void RemoveNode(bool bLeaveSubmit=true);

		/**
		* set the node's partition status and StatusDetails
		* if version<1.3 StatusPool/PartStatus elements are filled, else NodeInfo/@NodeStatus is filled
		*
		* @param mAttribute mattr: Attribute map of partition
		* @param EnumStatus status: Status to set
		* @param WString StatusDetails the statusdetails to set
		* @param vWString partIDKeys the partIDKeys sequence used to create nodeinfo partitions
		* @return boolean: success or not
		*/
		bool SetPartStatus (const mAttribute& mattr, EnumStatus status, const WString& statusDetails=WString::emptyStr, const vWString partIDKeys=vWString::emptyvStr);

		/**
		* set the node's partition status and StatusDetails
		* if version<1.3 StatusPool/PartStatus elements are filled, else NodeInfo/@NodeStatus is filled
		*
		* @param vmAttribute vmattr: vector of Attribute maps of partition
		* @param EnumStatus status: Status to set
		* @param WString StatusDetails the statusdetails to set
		* @param vWString partIDKeys the partIDKeys sequence used to create nodeinfo partitions
		* @return boolean: success or not
		*/
		bool SetPartStatus (const vmAttribute& vmattr, EnumStatus status,  const WString& statusDetails=WString::emptyStr, const vWString partIDKeys=vWString::emptyvStr);

		/**
		* get the node's partition status
		* if version<1.3 StatusPool/PartStatus elements are filled, else NodeInfo/@NodeStatus is filled
		* @param mAttribute mattr: Attribute map of partition
		* @return EnumStatus: Status of the partition
		*/
		EnumStatus GetPartStatus (const mAttribute& mattr);		

		/**
		* get the node's partition statusdetails
		* if version<1.3 StatusPool/PartStatus elements are filled, else NodeInfo/@NodeStatus is filled
		* @param mAttribute mattr: Attribute map of partition
		* @return WString: StatusDetails of the partition
		*/
		WString GetPartStatusDetails (const mAttribute& mattr);		

		/**
		* This function returns the root of the document
		* @return JDFNode: the root node of the document
		*/
		JDFNode GetRoot()const;

		/**
		* Get an ordered list of all Parents ID attributes<br>
		* the <em>last</em> entry is the direct parent, the last-1 entry is the grandparent etc.<br>
		* this is analog to the definition of JDFAncestorPool
		*
		* @return vWString vector of strings representing the node IDs:
		*/
		vWString GetAncestorIDs()const;


		/**
		* get a vector of Link names that are missing in this element<br>
		* if the links need a processusage, the format is LinkName:ProcessUsage
		*
		* @param int nMax maximum size of the returned vector
		* @return  vWString vector of strings that contains missing Link names
		*/
		vWString GetMissingLinkVector(int nMax=9999999)const;

		/**
		* get a vector of Link names that may be inserted in this element<br>
		* if the links need a processusage, the format is LinkName:ProcessUsage
		*
		* @param int nMax maximum size of the returned vector
		* @return  vWString vector of strings that contains insertable Link names
		*/
		vWString GetInsertLinkVector(int nMax=9999999)const;

		/**
		* true if Links are missing in this element
		*
		* @return boolean true if Links are missing
		*/
		bool HasMissingLinks()const;


		/**
		* get a vector of Link names that are missing in this element
		*
		* @param int nMax maximum size of the returned vector
		* @return  vWString vector of strings that contains missing Link keys
		*/
		virtual vWString GetMissingLinks(int nMax=99999999)const;

		/**
		* get a vector of Link names that exist but are unknown by this element
		*
		* @param vWString& vInNameSpace list of namespaces where unknown Links are searched for. if empty, all namespaces are searched
		* @param int nMax maximum size of the returned vector
		* @return  vWString vector of strings that contains missing Link keys
		*/
		vWString GetUnknownLinkVector(vWString vInNameSpace=vWString::emptyvStr, int nMax=9999999)const;

		/**
		* get a vector of Link names that exist but are unknown by this element
		*
		* @param vWString& vInNameSpace list of namespaces where unknown Links are searched for. if empty, all namespaces are searched
		* @param int nMax maximum size of the returned vector
		* @return  vWString vector of strings that contains missing Link keys
		*/
		vElement getUnknownLinkVector(vWString vInNameSpace=vWString::emptyvStr, int nMax=9999999)const;

		/**
		* true if Links are unknown in this element
		*
		* @param vWString& vInNameSpace list of namespaces where unknown Links are searched for. if empty, all namespaces are searched
		* @return boolean true if unknown Links are in this element
		*/
		inline bool HasUnknownLinks(const vWString& vInNameSpace=vWString::emptyvStr)const{ 
			return GetUnknownLinkVector(vInNameSpace,1).size()>0;
		};

		/**
		* get a vector of Link names that exist but are unknown by this element
		*
		* @param bool bIgnorePrivate if true, only look in default and JDF namespace
		* @param int nMax maximum size of the returned vector
		* @return  vWString vector of strings that contains missing Link keys
		* @tbd clean up namespace handling
		*/
		vWString GetUnknownLinks(bool bIgnorePrivate,int nMax=99999999)const;

		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid Link names
		*/
		vWString GetInvalidLinks(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

		/**
		* typesafe validator utility - explicitly finds inconsistent combinations
		* @param EnumValidationLevel level validation level
		* @return vWString vector of invalid Link names
		*/
		vWString GetInconsistentLinks(EnumValidationLevel level)const;

		/**
		* true if invalid Links are in this element
		*
		* @param vWString& vInNameSpace list of namespaces where unknown Links are searched for. if empty, all namespaces are searched
		* @return boolean true if unknown Links are in this element
		*/
		inline bool HasInvalidLinks(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=false)const{ 
			return GetInvalidLinks(level,bIgnorePrivate).size()>0;
		};
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param JDFResourceLink resource link to test
		* @return bool true if the resource link is valid in this node
		*/
		bool IsValidLink(EnumValidationLevel level, const JDFResourceLink& rl, vint& doneNameList,vint& doneIndexList)const;
		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid attribute names
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

		/**
		* typesafe validator utility
		* @param EnumValidationLevel level validation level
		* @param bool bIgnorePrivate ignore objects in foreign namespaces
		* @param int nMax size of the returned vector
		* @return vWString vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;



		/* ******************************************************
		// Attribute Getter / Setter
		****************************************************** */

		/**
		* Enumeration for attribute Activation
		*/
		enum EnumActivation{Activation_Unknown,Activation_Inactive,Activation_Informative,Activation_Held,Activation_TestRun,Activation_TestRunAndGo,Activation_Active};

		/**
		definition of required attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;

		/**
		definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;


		//@{
		/**
		* Enumeration strings for Activation
		* @return const WString& comma separated list of enumerated string values 
		*/
		static const WString& ActivationString();

		/**
		* Enumeration string for enum value
		* @param EnumActivation value the enumeration to translate
		* @return WString the string representation of the enumeration
		*/
		static const WString ActivationString(EnumActivation value);

		/**
		* Set attribute Activation
		* @param EnumActivation value the value to set the attribute to
		*/
		virtual void SetActivation( EnumActivation value);

		/**
		* Typesafe enumerated attribute Activation; defaults to Active
		* @param bWalkThroughAnchestors if true, walks through all anchestors which may overwrite the loacal activation state (the default)
		* @return EnumActivationthe enumeration value of the attribute
		*/
		virtual EnumActivation GetActivation(bool bWalkThroughAnchestors=true) const;

		/**
		* Typesafe attribute validation of Activation
		* @param EnumValidationLevel level validation level
		* @return bool true if valid
		*/
		virtual bool ValidActivation(EnumValidationLevel level) const;

		/**
		* the activation state of this node
		* @param bWalkThroughAnchestors if true, walks through all anchestors which may overwrite the local activation state (the default)
		* @return boolean:
		*/		
		bool IsActive(bool bWalkThroughAnchestors=true)const;

		/**
		* the activation state of this node
		* @param bWalkThroughAnchestors if true, walks through all anchestors which may overwrite the local activation state (the default)
		* @return boolean:
		*/		
		bool FitsActivation(EnumActivation active,bool bWalkThroughAnchestors=true)const;

		/**
		* Get a vector of all JDF children with type nodeType 
		* @param String nodeType: node Type attribute
		* @param EnumActivation active: if true, return only nodes with Activation=Active
		* @param boolean bDirect: if true, only direct children, else recurse down the tree
		* @return vElement: vector of JDF nodes
		*/	
		vElement GetvJDFNode(const WString & nodeType=WString::emptyStr,EnumActivation active=Activation_Unknown, bool bDirect=false)const;
		//@}


		//@{
		/**
		* Set attribute Category
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetCategory(const WString& value);

		/**
		* Get string attribute Category
		* @return WString: the attribute value 
		*/
		virtual WString GetCategory() const;

		/**
		* Typesafe attribute validation of Category
		* @param EnumValidationLevel level validation level
		* @return bool: true if valid
		*/
		virtual bool ValidCategory(EnumValidationLevel level) const;
		//@}


		//@{

		/**
		* Set attribute ICSVersions
		* @param vWString& value: the value to set the attribute to
		*/
		virtual void SetICSVersions(const vWString& value);

		/**
		* Get NMTOKENS attribute ICSVersions
		* @param bool bInherit recurse through ancestors when searching
		* @return vWString: the attribute value 
		*/
		virtual vWString GetICSVersions(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of ICSVersions
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidICSVersions(EnumValidationLevel level) const;
		//@}


		/**
		* ID attribute support 
		*/
		//@{
		/**
		* Set attribute ID
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetID(WString value);

		/**
		* Get string attribute ID
		* @return WString: the attribute value
		*/
		virtual WString GetID() const;

		/**
		* Typesafe attribute validation of ID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute JobID
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetJobID(const WString& value);

		/**
		* Get string attribute JobID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value 
		*/
		virtual WString GetJobID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of JobID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidJobID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute JobPartID
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetJobPartID(const WString& value);

		/**
		* Get string attribute JobPartID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value
		*/
		virtual WString GetJobPartID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of JobPartID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidJobPartID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute MaxVersion
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetMaxVersion(const WString& value);

		/**
		* Get string attribute MaxVersion
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value
		*/
		virtual WString GetMaxVersion(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of MaxVersion
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidMaxVersion(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute NamedFeatures
		* @param vWString value: the value to set the attribute to
		*/
		virtual void SetNamedFeatures(const vWString& value);

		/**
		* Get NMTOKENS attribute NamedFeatures
		* @return vWString: the attribute value
		*/
		virtual vWString GetNamedFeatures() const;

		/**
		* Typesafe attribute validation of NamedFeatures
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidNamedFeatures(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute ProjectID
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetProjectID(const WString& value);

		/**
		* Get string attribute ProjectID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value
		*/
		virtual WString GetProjectID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of ProjectID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidProjectID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute RelatedJobID
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetRelatedJobID(const WString& value);

		/**
		* Get string attribute RelatedJobID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value
		*/
		virtual WString GetRelatedJobID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of RelatedJobID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidRelatedJobID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute RelatedJobPartID
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetRelatedJobPartID(const WString& value);

		/**
		* Get string attribute RelatedJobPartID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value
		*/
		virtual WString GetRelatedJobPartID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of RelatedJobPartID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidRelatedJobPartID(EnumValidationLevel level) const;
		//@}


		//@{

		/**
		* Set attribute SpawnID
		* @param WString value: the value to set the attribute to
		*/
		virtual void SetSpawnID(const WString& value);

		/**
		* Get string attribute SpawnID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value 
		*/
		virtual WString GetSpawnID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of SpawnID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidSpawnID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute StatusDetails
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetStatusDetails(const WString& value);

		/**
		* Get string attribute StatusDetails
		* @return WString: the attribute value 
		*/
		virtual WString GetStatusDetails() const;

		/**
		* Typesafe attribute validation of StatusDetails
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidStatusDetails(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute Template
		* @param bool value: the value to set the attribute to
		*/
		virtual void SetTemplate(bool value);

		/**
		* Get bool attribute Template, default=false
		* @return bool: the attribute value 
		*/
		virtual bool GetTemplate() const ;

		/**
		* Typesafe attribute validation of Template
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;
		//@}


		//@{
		/**
		* Set attribute TemplateID
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetTemplateID(const WString& value);

		/**
		* Get string attribute TemplateID
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value 
		*/
		virtual WString GetTemplateID(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of TemplateID
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidTemplateID(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute TemplateVersion
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetTemplateVersion(const WString& value);

		/**
		* Get string attribute TemplateVersion
		* @param bool bInherit: recurse through ancestors when searching
		* @return WString: the attribute value
		*/
		virtual WString GetTemplateVersion(bool bInherit=false) const;

		/**
		* Typesafe attribute validation of TemplateVersion
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidTemplateVersion(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* set node Types , also set Type to Combined
		* @param vWString& typ: vector of types
		*/
		virtual void SetTypes(const vWString &typ);

		/**
		* insert a new Process into @Types at the position pos
		* @param type the process type
		* @param beforePos the position before which to add the in the list, 0 is first, ... -1 is before the last, very large is append
		*/
		void insertTypeInTypes(EnumType type, int beforePos);
		/**
		* Get vWString attribute Types if this is a combined node
		* @return vWString: the attribute value
		*/
		virtual vWString GetTypes() const;

		/**
		* Gets the vector of the string Type/Types attribute values of the given JDFNode by 
		* recursively traversing the tree
		* returns exactly one element="Product" if the tested node's type is product
		*
		* @param JDFNode jdfRoot - the ProcessGroup JDFNode
		* @return VString - vector of Type/Types attributes of the tested ProcessGroup JDFNode
		* @throws JDFException if the testen JDFNode has illegal combination of attribute 'Types' and child JDFNodes
		*/
		vWString getAllTypes() const;
		/**
		* Typesafe attribute validation of Types
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidTypes(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set node Type
		* @param WString& typ: node Type to set
		*/
		virtual void SetType(const WString &typ);

		/**
		* Get string attribute Type
		* @return WString: the attribute value
		*/
		virtual WString GetType() const;

		/**
		* Typesafe attribute validation of Type
		* @param EnumValidationLevel level:validation level
		* @return bool: true if valid
		*/
		virtual bool ValidType(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Set attribute Version
		* @param WString& value: the value to set the attribute to
		*/
		virtual void SetVersion(const WString& value);

		/**
		* Set attribute Version
		* @param EnumVersion value: the value to set the attribute to
		*/
		void SetEnumVersion(EnumVersion value);

		/**
		* Typesafe attribute validation of Version
		* @param EnumValidationLevel level: validation level
		* @return bool: true if valid
		*/
		virtual bool ValidVersion(EnumValidationLevel level) const;

		/**
		* Version fixing routine
		*
		* uses heuristics to modify this element and its children to be compatible with a given version
		* in general, it will be able to move from low to high versions but potentially fail 
		* when attempting to move from higher to lower versions
		*
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);


		//@}


		//@{
		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute CleanupDuration of the found NodeInfo element.
		* @return JDFDuration: value of CleanupDuration attribute
		*/
		JDFDuration GetNodeInfoCleanupDuration() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute CostType of the found NodeInfo element.
		* @return JDFNodeInfo::EnumCostType: value of CostType attribute
		*/
		JDFMISDetails::EnumCostType GetNodeInfoCostType() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute DueLevel of the found NodeInfo element.
		* @return JDFNodeInfo::EnumDueLevel: value of DueLevel attribute
		*/
		JDFNodeInfo::EnumDueLevel GetNodeInfoDueLevel() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute End of the found NodeInfo element.
		* @return JDFDate: value of End attribute
		*/
		JDFDate GetNodeInfoEnd() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute FirstEnd of the found NodeInfo element.
		* @return JDFDate: value of FirstEnd attribute
		*/
		JDFDate GetNodeInfoFirstEnd() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute FirstStart of the found NodeInfo element.
		* @return JDFDate: value of FirstStart attribute
		*/
		JDFDate GetNodeInfoFirstStart() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute IPPVersion of the found NodeInfo element.
		* @return JDFXYPair: value of IPPVersion attribute
		*/
		JDFXYPair GetNodeInfoIPPVersion() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute JobPriority of the found NodeInfo element.
		* @return int: value of JobPriority attribute
		*/
		int GetNodeInfoJobPriority() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute LastEnd of the found NodeInfo element.
		* @return JDFDate: value of LastEnd attribute
		*/
		JDFDate GetNodeInfoLastEnd() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute LastStart of the found NodeInfo element.
		* @return JDFDate: value of LastStart attribute
		*/
		JDFDate GetNodeInfoLastStart() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute NaturalLang of the found NodeInfo element.
		* @return WString: value of NaturalLang attribute
		*/
		WString GetNodeInfoNaturalLang() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute MergeTarget of the found NodeInfo element.
		* @return bool: value of MergeTarget attribute
		*/
		bool GetNodeInfoMergeTarget() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute Route of the found NodeInfo element.
		* @return WString: value of Route attribute
		*/
		WString GetNodeInfoRoute() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute rRefs of the found NodeInfo element.
		* @return vWString: value of rRefs attribute
		*/
		vWString GetNodeInforRefs() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute SetupDuration of the found NodeInfo element.
		* @return JDFDuration: value of SetupDuration attribute
		*/
		JDFDuration GetNodeInfoSetupDuration() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute Start of the found NodeInfo element.
		* @return JDFDate: value of Start attribute
		*/
		JDFDate GetNodeInfoStart() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute TargetRoute of the found NodeInfo element.
		* @return WString: value of TargetRoute attribute
		*/
		WString GetNodeInfoTargetRoute() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute CleanupDuration of the found NodeInfo element.
		* @return JDFDuration: value of CleanupDuration attribute
		*/
		JDFDuration GetNodeInfoTotalDuration() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute WorkType of the found NodeInfo element.
		* @return JDFNodeInfo::EnumWorkType: value of WorkType attribute
		*/
		JDFMISDetails::EnumWorkType GetNodeInfoWorkType() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets value of attribute WorkTypeDetails of the found NodeInfo element.
		* @return WString: value of WorkTypeDetails attribute
		*/
		WString GetNodeInfoWorkTypeDetails() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets of the found NodeInfo element the refelement BusinessInfo
		* @param int iSkip: number of elements to skip, dafault=0
		* @return JDFBusinessInfo: found BusinessInfo element
		*/
		JDFBusinessInfo GetNodeInfoBusinessInfo() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets of the found NodeInfo element the subelement Employee
		* @return JDFEmployee: found Employee element
		*/
		JDFEmployee GetNodeInfoEmployee() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets of the found NodeInfo element the iSkip-th JMF subelement.
		* @param int iSkip: number of elements to skip, dafault=0
		* @return JDFJMF: found JMF element
		*/
		JDFJMF GetNodeInfoJMF(int iSkip=0) const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element.  
		* Gets of the found NodeInfo element the subelement MISDetails
		* @return JDFMISDetails: found MISDetails element
		*/
		JDFMISDetails GetNodeInfoMISDetails() const; 

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the NodeInfo element. 
		* Gets of the found NodeInfo element the iSkip-th NotificationFilter subelement.
		* @param int iSkip: number of elements to skip, dafault=0
		* @return JDFNotificationFilter: found NotificationFilter element
		*/
		JDFNotificationFilter GetNodeInfoNotificationFilter(int iSkip=0) const; 
		//@}


		//@{
		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets value of attribute BillingCode of the found CustomerInfo element.
		* @return WString: value of BillingCode attribute
		*/
		WString GetCustomerInfoBillingCode() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets value of attribute CustomerID of the found CustomerInfo element.
		* @return WString: value of CustomerID attribute
		*/
		WString GetCustomerInfoCustomerID() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets value of attribute CustomerJobName of the found CustomerInfo element.
		* @return WString: value of CustomerJobName attribute
		*/
		WString GetCustomerInfoCustomerJobName() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets value of attribute CustomerOrderID of the found CustomerInfo element.
		* @return WString: value of CustomerOrderID attribute
		*/
		WString GetCustomerInfoCustomerOrderID() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets value of attribute CustomerProjectID of the found CustomerInfo element.
		* @return WString: value of CustomerProjectID attribute
		*/
		WString GetCustomerInfoCustomerProjectID() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets value of attribute rRefs of the found CustomerInfo element.
		* @return WString: value of rRefs attribute
		*/
		vWString GetCustomerInforRefs() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets of the found CustomerInfo element the subelement Company.
		* @return JDFCompany: found Company element
		*/
		JDFCompany GetCustomerInfoCompany() const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets of the found CustomerInfo element the iSkip-th Contact subelement.
		* @param int iSkip: number of elements to skip, dafault=0
		* @return JDFContact: found Contact element
		*/
		JDFContact GetCustomerInfoContact(int iSkip=0) const;

		/**
		* Searches through the child elements of 'this' and its ancestors  
		* for the first occurrence of the CustomerInfo element.  
		* Gets of the found CustomerInfo element the iSkip-th CustomerMessage subelement.
		* @param int iSkip: number of elements to skip, dafault=0
		* @return JDFCustomerMessage: found CustomerMessage element
		*/
		JDFCustomerMessage GetCustomerInfoCustomerMessage(int iSkip=0) const;
		//@}


		/**
		* searches for the first attribute occurrence in the ancestor elements
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 180502 
		* @return WString: value of attribute found, empty string if not available
		*/
		WString GetAncestorAttribute(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr,const WString & def=WString::emptyStr)const;

		/**
		* true if a non default attribute occurrence in the parent nodes and then the ancestor elements of the root ancestorpool exists
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @since 180502 
		* @return bool: true if the attribute exists
		*/
		bool HasAncestorAttribute(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr)const;

		/**
		* searches for the first element occurrence in the parent nodes and then the ancestor elements of the root ancestorpool
		*
		* @param WString element: the element name
		* @param WString nameSpaceURI: the XML-namespace
		* @since 290502 
		* @return WString: value of attribute found, value of def if not available
		*/
		JDFElement GetAncestorElement(const WString & element,const WString& nameSpaceURI=WString::emptyStr)const;

		/**
		* true if a non default attribute occurrence in the parent nodes and then the ancestor elements of the root ancestorpool exists
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @since 180502 
		* @return bool: true if the attribute exists
		*/
		bool HasAncestorElement(const WString & attrib,const WString& nameSpaceURI=WString::emptyStr)const;


		/**
		* searches for the first attribute occurrence in the ancestor elements subelements<br>
		* e.g. the JobPriority in NodeInfo
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 200503 
		* @return WString: value of attribute found, empty string if not available
		*/
		WString GetAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI=WString::emptyStr,const WString & def=WString::emptyStr)const;

		/**
		* true if a non default attribute occurrence in the parent nodes and then the ancestor elements subelements of the root ancestorpool exists
		* e.g. the JobPriority in NodeInfo
		*
		* @param WString attrib: the attribute name
		* @param WString nameSpaceURI: the XML-namespace
		* @param WString def: the default if it does not exist
		* @since 200503 
		* @return bool: true if the attribute exists
		*/
		bool HasAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI=WString::emptyStr)const;

		/* ******************************************************
		* Element Getter / Setter
		**************************************************************** */		

		/** Get Element AncestorPool
		* @param bool bCreate create a new element if it does not exist
		* @return JDFAncestorPool The element
		*/
		JDFAncestorPool GetCreateAncestorPool();
		/**
		* const get first element AncestorPool
		*@return  JDFAncestorPool The element
		*/
		JDFAncestorPool GetAncestorPool()const;
		/** Append Element AncestorPool, return existing element if one already exist
		* @return JDFAncestorPool The element
		*/
		JDFAncestorPool AppendAncestorPool();

		/** Get Element AuditPool
		* @return JDFAuditPool The element
		*/
		JDFAuditPool GetCreateAuditPool();

		/**
		* const get first element AuditPool
		*@return  JDFAuditPool The element
		*/
		JDFAuditPool GetAuditPool()const;


		/** Append Element AuditPool, return existing element if one already exist
		* @return AuditPool The element
		*/
		JDFAuditPool AppendAuditPool();

		/** Get Element CustomerInfo
		* @return JDFCustomerInfo The element
		*/
		JDFCustomerInfo GetCreateCustomerInfo();

		/**
		* const get first element CustomerInfo
		* @see also GetInheritedCustomerInfo() for a version that checks sub elements and ancestorpool
		*@return  JDFCustomerInfo The element
		*/
		JDFCustomerInfo GetCustomerInfo()const;

		// MM added 2001-08-31: 
		/**
		* get first CustomerInfo element from child list or child list of any anchestor
		*@return  JDFCustomerInfo The element
		*/
		JDFCustomerInfo GetInheritedCustomerInfo()const;


		/** Append Element CustomerInfo, return existing element if one already exist
		* @return JDFCustomerInfo The element
		*/
		JDFCustomerInfo AppendCustomerInfo();

		/** Get Element NodeInfo
		* @return JDFNodeInfo The NodeInfo element
		*/
		JDFNodeInfo GetCreateNodeInfo();

		/** Append Element NodeInfo, return existing element if one already exist
		* @return JDFNodeInfo The NodeInfo element
		*/
		JDFNodeInfo AppendNodeInfo();

		/**
		* const get first element NodeInfo
		* @see also GetInheritedNodeInfo() for a version that checks sub elements and ancestorpool
		* @return  JDFNodeInfo The element
		*/
		JDFNodeInfo GetNodeInfo()const;

		/**
		* removes all nodeinfos from this node
		*/
		void RemoveNodeInfos();

		/**
		* removes all customerinfos from this node
		*/
		void RemoveCustomerInfos();

		/**
		*	return true if this has CustomerInfo Childs in any form (elements or resources)
		*/
		bool HasCustomerInfo();

		/**
		*	return true if this has NodeInfo Childs in any form (elements or resources)
		*/
		bool HasNodeInfo();

		/**
		* return number of customerinfo 'childs' as resource or element
		*/
		int NumCustomerInfos();


		/**
		* return number of nodeinfo 'childs' as resource or element
		*/
		int NumNodeInfos();

		// MM added 2001-08-31: 
		/**
		* get first NodeInfo element from child list or child list of any ancestor
		* @return  JDFNodeInfo The element
		*/
		JDFNodeInfo GetInheritedNodeInfo()const;


		/** Get Element ResourceLinkPool
		* @return JDFResourceLinkPool The element
		*/
		JDFResourceLinkPool GetCreateResourceLinkPool();

		/**
		* const get first element ResourceLinkPool
		*@return  JDFResourceLinkPool The element
		*/
		JDFResourceLinkPool GetResourceLinkPool()const;


		/** Append Element ResourceLinkPool, return existing element if one already exist
		* @return JDFResourceLinkPool The ResourceLinkPool element
		*/
		JDFResourceLinkPool AppendResourceLinkPool();

		/** Get Element ResourcePool
		* @return JDFResourcePool The element
		*/
		JDFResourcePool GetCreateResourcePool();

		/**
		* const get first element ResourcePool
		*@return  JDFResourcePool The element
		*/
		JDFResourcePool GetResourcePool()const;

		/** Append Element ResourcePool, return existing element if one already exist
		* @return JDFResourcePool The ResourcePool element
		*/
		JDFResourcePool AppendResourcePool();


		/** Get Element StatusPool
		* @return JDFStatusPool The element
		*/
		JDFStatusPool GetCreateStatusPool();
		/**
		* const get first element StatusPool
		*@return  JDFStatusPool The element
		*/
		JDFStatusPool GetStatusPool()const;

		/** Append Element StatusPool, return existing element if one already exist
		* @return JDFStatusPool The StatusPool element
		*/
		JDFStatusPool AppendStatusPool();

		/**
		* definition of unique elements in the JDF namespace
		*/
		virtual WString UniqueElements()const;

		/**
		* definition of optional elements in the JDF namespace
		*/
		virtual WString OptionalElements()const;

		/**
		* get inter-resource linked resource ids
		* @param vWString vDoneRefs:
		* @param bool bRecurse if true, also return recursively linked IDS
		* @return vWString: the vector of referenced resource ids
		*/
		vWString GetHRefs(const vWString& vDoneRefs=vWString::emptyvStr, bool bRecurse=false)const;

		/**
		* get inter-resource linked resource refs and resourcs links
		* @param vElement vDoneRefs
		* @param bool bRecurse if true, also return recursively linked references
		* @return velement: the vector of referenced resource refs and links
		*/
		VoidSet* GetAllRefs(VoidSet* vs, bool bRecurse=false)const;

		/**
		* Set the Status and StatusDetails of this node
		* update the PhaseTime audit or append a new phasetime as appropriate  
		* also generate a status JMF
		* 
		* @param nodeStatus the new status of the node
		* @param nodeStatusDetails the new statusDetails of the node
		* @param deviceStatus the new status of the device
		* @param deviceStatusDetails the new statusDetails of the device
		* @param vPartMap the vector of parts to that should be set
		* 
		* @return The root element representing the PhaseTime JMF
		*/
		JDFDoc setPhase(JDFNode::EnumStatus nodeStatus, const WString& nodeStatusDetails, const WString& deviceID, 
			JDFDeviceInfo::EnumDeviceStatus deviceStatus, const WString& deviceStatusDetails, const vmAttribute& vPartMap);

	protected:

		/** 
		* level to required converter 
		*
		* @param EnumValidationLevel level: validation level
		* @return bool: true if validation level is one of: Complete or RecursiveComplete
		*/
		virtual bool RequiredLevel(EnumValidationLevel level)const;

		/**
		* calculate a new level based on the status
		* @param KElement::EnumValidationLevel level
		* @return KElement::EnumValidationLevel level the modified level
		*/
		KElement::EnumValidationLevel IncompleteLevel(KElement::EnumValidationLevel level)const;

		/**
		* Utilities for typesafe node handling using the index of typesafe node strings
		*
		*/
		//*@{
		/**
		* definition of the length of LinkNames, LinkInfo for generic JDF nodes
		* @return int length of the generic (JDFNode::) link string functions,
		*/
		static int genericLinksLength;		

		/**
		* definition of resource link usage, cardinality and ProcessUsage in the JDF namespace for one index
		* @param int namIndex index of the named list, if<0 tokenize all 
		* @return vWString list of resource process usages that may be linked, 
		*/
		vWString vLinkInfo(int namIndex=-1)const;


	private:
		vWString GetMatchType(const WString& resName, EnumProcessUsage processUsage);

		/**
		* get the resource that matches the typesafe link described by i
		* @param WString info the LinkInfo string for this name
		* @param int i the index of the pu to find
		* @return EnumProcessUsage the enumerated process usage of this checked link
		*/
		EnumProcessUsage GetEnumProcessUsage(const WString&info, int i=0)const;

		/**
		* Get the index in Linknames of the RL described by rl
		* return -1 if it does not fit
		*/
		int GetMatchingIndex(const JDFResourceLink & rl, int &iIndex, int nOccur)const;

		void generateCombinedProcessIndex(const JDFResource& jdfResource, JDFResourceLink::EnumUsage usage, JDFNode::EnumProcessUsage processUsage, JDFResourceLink resourceLink, const vWString& types);
		bool cleanCombinedProcessIndex(JDFResourceLink::EnumUsage usage, const vWString& types, JDFIntegerList& cpi, const WString& resName, int lastGot, const vWString& typeLinkNamesLast, bool bAddCPI, const vWString& typeInfo);

		/**
		* gets the existing inherited CustomerInfo or NodeInfo from parents including ancestorpool
		* attribute xPath is dummy for now
		* TODO implement xPath in KElement
		* @return the existing CustomerInfo or NodeInfo.
		*/
		KElement getNiCi(const WString& elementName, bool bInherit, const WString& xPath = WString::emptyStr) const;

	public:
		/**
		* get the resource that matches a typesafe resource name
		* if the Resource type is not defined for the process represented by this node
		* see chapter 6 JDFSpec, then the resource is ignored
		* 
		* @param WString resName of the resource to remove
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @param int pos the position of the link if multiple matching links exist
		* @return the resourcelink element
		*/
		JDFResource GetMatchingResource(const WString& resName, EnumProcessUsage processUsage=ProcessUsage_Any, const mAttribute & partMap=mAttribute::emptyMap,int pos=0)const;

		/**
		* get the link that matches the typesafe resource name
		* if the Resource type is not defined for the process represented by this node
		* see chapter 6 JDFSpec, then the link is ignored
		*
		* @param WString resName of the resource to remove
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @param int pos the position of the link if multiple matching links exist
		* @return the resource element
		*/
		JDFResourceLink GetMatchingLink(const WString& resName, EnumProcessUsage processUsage=ProcessUsage_Any, int pos=0)const;

		/**
		* get the links that match the typesafe resource name
		* if the Resource type is not defined for the process represented by this node
		* see chapter 6 JDFSpec, then the links are ignored
		*
		* @param WString resName of the resource to remove
		* @param boolean bLink: if false, returns the linked resources, else if true, returns the ResourceLink elements
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @return the vector of resourcelink elements
		*/
		vElement GetMatchingLinks(const WString& resName, bool bLink=true, EnumProcessUsage processUsage=ProcessUsage_Any)const;	

		/**
		* get the number of links that match the typesafe link resource name
		* if the Resource type is not defined for the process represented by this node
		* see chapter 6 JDFSpec, then the link is ignored
		*
		* @param WString resName of the resource to remove
		* @param boolean bLink: if false, returns the linked resources, else if true, returns the ResourceLink elements
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @return the number of resourcelink elements
		*/
		int NumMatchingLinks(const WString& resName, bool bLink=true, EnumProcessUsage processUsage=ProcessUsage_Any)const;

		/**
		* remove a type from the types list - also cleaning up combinedprocessindex
		* @param type the type
		* @param iSkip the index of this type in the list of identical types - typically 0
		* @param bRemoveEmptyLink if true, remove any reslinks that have no remaining combinedprocessindex
		* 
		*/
		void removeFromTypes(const WString& type, int iSkip, bool bRemoveEmptyLink);

		/**
		* 
		* remove a resourceLink and potentially its linked resource
		* @param l
		* @param bRemoveResource
		*/
		void JDFNode::removeLink( JDFResourceLink l,  bool bRemoveResource);

		/**
		* remove the link that matches the typesafe link resource name
		*
		* @param WString resName of the resource to remove
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @param int pos the position of the link if multiple matching links exist
		* @param bool bRemoveResource also remove the resource if it is not linked by any other process
		* @return bool true if successful
		*/
		bool RemoveMatchingLink(const WString& resName, EnumProcessUsage processUsage=ProcessUsage_Any, bool bRemoveResource=false,int pos=0);

		/**
		* remove all links that match the typesafe link described by resource name
		*
		* @param WString name of the resource to remove
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @param bool bRemoveResource also remove the resource if it is not linked by any other process
		* @return bool true if successful
		*/
		bool RemoveMatchingLinks(const WString& resName, EnumProcessUsage processUsage=ProcessUsage_Any, bool bRemoveResource=false);

		/**
		* Append a resource that matches the typesafe link described by i
		*
		* @param WString name of the resource to remove
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @param JDFNode resourceRoot the node where the ResourcePool resides that will contain the newly created resource
		* @return JDFResource the newly created resource, null if unsuccessful
		*/
		JDFResource AppendMatchingResource(const WString& resName, EnumProcessUsage processUsage, JDFNode resourceRoot=JDFNode::DefJDFNode);

		/**
		* Append a resource that matches the typesafe link described by resource name
		*
		* @param JDFResource resourcet the resource to link
		* @param int processUsage enum that defines if all links matching the name or only those matching the name usage and/or processusage are requested
		* @param mAttribute partMap: the Attribute map of parts
		* @return JDFResourceLink the new link, null if failure
		*/
		JDFResourceLink LinkMatchingResource(const JDFResource & resource, EnumProcessUsage processUsage, const mAttribute & partMap=mAttribute::emptyMap);

		//*@}

		/**
		* merge nodes in a way that no duplicate elements are created
		* attention !! this kills pools !!
		* @param JDFNode e: the node element to merge with the current node
		* @param boolean bDelete: if true KElement e will be deleted
		* @return JDFNode: the merged node element
		*/
		JDFNode MergeNode(JDFNode e,bool bDelete);

		/**a child node of this root; 
		* 
		* @param WString spawnID: the SpawnID of the spwned node
		* @return bool true if successful:
		* @tbd enhance nested spawning of partitioned nodes
		*/
		bool UnSpawnNode(const WString & spawnID);

		/**
		* gets the maximum job part id;
		* note that this assumes integer job part ids
		* return int: XXX
		*/
		int GetMaxJobPartId(const WString& idPrefix=WString::emptyStr);

		/**
		* Loop over all IDs and find the min ID that will create unique new IDs
		* @return int: the new minimum ID that will generate unique IDs
		*/
		int GetMinID();

		/**
		* return true if a node with the same ID as one in p's ancestorpool exists in this document
		* @param JDFNode p: the node to check
		* @return boolean: true if a node with the same ID as one in p's ancestorpool exists
		*/
		bool HasParent(JDFNode p);

		/**
		* Enumeration for the policy of cleaning up the Spawn and Merge audits <p>
		*
		*/
		enum EnumCleanUpMerge{CleanUpMerge_None,CleanUpMerge_RemoverRefs,CleanUpMerge_RemoveAll};

		/**
		* clean up the spawn and merge audits in this Node
		* @param EnumCleanUpMerge policy how to clean up the spawn and merge audits after merging
		* @param WString spawnID the SpawnID of the spawn and MergeID of the merge to clean up
		*	if not specified all spawns will be cleaned up
		* @param bool bRecurse if true also recurse into all child JDF nodes; default=false
		*/
		void CleanUpMerge(EnumCleanUpMerge cleanPolicy, const WString& spawnID=WString::emptyStr, bool bRecurse=false);

	private:
		/**
		* merge the audit and ancestor pools
		* @param JDFNode& toMerge the source node of the audit pool to merge into this
		* @param JDFNode& overWriteParent the parent node that contains the ancestor pool
		* @param vmAttribute parts the partitions to merge
		* @param vWString& vsRW Resource IDs of non-local spawned resources 
		* @param const WString& spawnID the original spawnID 
		* @param const WString& urlMerge URL of the merged file
		* @param bool bSnafu boolean whether to append a mess up notification
		*/
		void MergeMainPools(JDFNode toMerge,  JDFNode overWriteParent, const vmAttribute &parts, const vWString& vsRW, const WString& spawnID, const WString& preSpawn, const WString& urlMerge, bool bSnafu);

		/**
		* merge the status pools
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param vmAttribute parts the partitions to merge
		*/
		void MergeStatusPool(JDFNode toMerge, const vmAttribute &parts);

		/**
		* merge the audit pools
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		*/
		void MergeAuditPool(JDFNode toMerge);

		/**
		* merge the resource link pools
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param vmAttribute parts the partitions to merge
		*/
		void MergeResourceLinkPool(JDFNode toMerge, const vmAttribute &parts);

		/**
		* merge the resource links of local JDF Nodes resource
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param vmAttribute parts the partitions to merge
		*/
		void MergeLocalLinks(JDFNode toMerge, const vmAttribute& parts);	

		/**
		* merge the elements of local JDF Nodes resource
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param vmAttribute parts the partitions to merge
		* @param vWString& previousMergeIDs SpawnIDs of previously merged 
		* @param const WString& spawnID the original spawnID 
		* @param JDFResource::EnumAmountMerge amountPolicy  
		*/
		void MergeLocalNodes(JDFNode toMerge, const vmAttribute& parts, const vWString& previousMergeIDs, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy);	

		/**
		* merge the RO resources of the main JDF
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param vWString& previousMergeIDs SpawnIDs of previously merged 
		* @param vWString& vsRO Resource IDs of non-local spawned resources 
		* @param const WString& spawnID the original spawnID 
		*/
		void CleanROResources(JDFNode toMerge, const vWString& previousMergeIDs, const vWString& vsRO, const WString& spawnID);

		/**
		* merge the RW resources of the main JDF
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param vWString& previousMergeIDs SpawnIDs of previously merged 
		* @param vWString& vsRW Resource IDs of non-local spawned resources 
		* @param const WString& spawnID the original spawnID 
		* @param JDFResource::EnumAmountMerge amountPolicy  
		*/
		void MergeRWResources(JDFNode toMerge, const vWString& previousMergeIDs, const vWString& vsRW, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy);

		/**
		* merge the comments of local JDF Nodes 
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		*/
		void MergeComments(JDFNode toMerge);

	public:

		/**
		* removes a Resource from this ResourceLinkPool and from the resourcePool if it is 
		* no longer linked to any other process
		* 
		* @param resName  the resource name of the Resource, "NodeInfo" for example
		* @param iSkip     number to skip before deleting
		* @return KElement the removed element, null if nothing was found or deleted e.g. 4 found 
		*                  and the 5th is the one to deleate 
		*/
		KElement RemoveResource(const WString& resName, int iSkip = 0);

		/**
		* merge a previously spawned JDF into a node that is a child of, or this root 
		* @param JDFNode toMerge the previosly spawned jdf node. 
		* Note that this node gets massively modified by the algorithm and should be discarded after use
		* @param WString urlMerge the url of the output file that the merged jdf will be written to
		* @param EnumCleanUpMerge policy how to clean up the spawn and merge audits after merging
		* @param EnumAmountMerge policy how to clean up the Resource amounts after merging
		* @return boolean: true if successful
		*
		* @throws JDFException if toMerge has already been merged 
		* @throws JDFException if toMerge was not spawned from this
		* @throws JDFException if toMerge has no AncestorPool
		* @deprecated use JDFMerge class
		*/
		bool MergeJDF(JDFNode toMerge, const WString& urlMerge=WString::emptyStr, EnumCleanUpMerge cleanPolicy=CleanUpMerge_None, JDFResource::EnumAmountMerge amountPolicy=JDFResource::AmountMerge_None);

		/**
		* undo the spawn a child node of this root; 
		* 
		* @param WString spawnID: the SpawnID of the spwned node
		* @return bool true if successful:
		* @deprecated use new JDFSpawn(this).unSpawn(spawnID);
		*/
		bool UnSpawn(const WString & spawnID);

		/**
		* Get an ordered list of the ids of the parents of this node <br>
		* the <em>last</em> element in the pool is the direct parent, 
		* the second to last is the grandparent etc. The <em>first</em> element is the original root element.
		* @return: vWString: the list of ids in the order parent, grandparent...
		*/
		vWString GetParentIds();

		/**
		* Set the parent when a node is spawned<p>
		* Fills the AncestorPool with the appropriate Ancestor elements, the <em>last</em> element in the pool is the direct parent, 
		* the second to last is the grandparent etc. The <em>first</em> element is the original root element.
		*
		* @param JDFNode parent: the node that contains the auditpool for this spawning
		* @param WString url the location of the parent node file that this was spawned from
		* @param vmAttribute vSpawnParts the list of part elements that describe the parts if only a partial node was spawned
		* @param bool bCopyNodeInfo copy the NodeInfo elements into the Ancestors
		* @param bool bCopyCustomerInfo copy the CustomerInfo elements into the Ancestors
		* @param bool bCopyComments if true, also copy the Comment elements into the ancestor
		* @return void:
		*/
		void SetSpawnParent(const JDFNode& parent,const WString& url=WString::emptyStr,const vmAttribute& vSpawnParts=vmAttribute(),bool bCopyNodeInfo=false, bool bCopyCustomerInfo=false, bool bCopyComments=false);

		/**
		* Add a process node to this process group
		* @param String processName:
		* @return JDFNode
		*/
		JDFNode AddProcess(const WString &  processName);

		/**
		* Add a product node 
		* @return JDFNode:
		*/
		JDFNode AddProduct();

		/**
		* Get a Product direct child node
		* @param WString productType Component/@ProductType of the requested Product node
		* @param iSkip number of matching nodes to skip
		* @return JDFNode the matching node, an empty JDFNode if no match is found
		* @since 010704
		*/
		JDFNode GetProduct(const WString& productType=WString::star, int iSkip=0)const;

		/**
		* Add a process group node
		* @param Vector types: Types of the processgroup
		* @return JDFNode
		*/
		JDFNode AddProcessGroup(const vWString& types=vWString::emptyvStr);

		/**
		* Add a combined node
		* @param Vector types:Types of the processgroup
		* @return JDFNode:
		*/
		JDFNode AddCombined(const vWString& types);

		/**
		*  you can get a vector with all nodes by calling this function
		*  @return Vector: a vector with all nodes
		*/	
		vElement GetCompleted()const;

		/**
		* Remove all Child Processses that are already completed
		*/
		bool RemoveCompleted();

		/**
		* @param EnumType typ:
		* @return JDFNode:
		*/
		JDFNode AddJDFNode(EnumType typ);

		/**
		* Returns a resource with id anywhere in the tree below this node
		* similar to GetTarget(id) but looks only in the resource pool's direct children
		* @param id the id of the resource
		* @return the resource, if available
		*/
		JDFResource GetTargetResource(const WString& id)const;

		/**
		* Add an internal resource pipe between two sub-processes of a combined node
		* used e.g. ro modify a coordinate system of a combined process
		* @param WString resourceName the name of the resourcew; typically RunList or Component
		* @param int indexOutput the CombinedPocessIndex of the subprocess that creates the resource
		* @param int indexInput the CombinedPocessIndex of the subprocess that consumes the resource
		* @return the newly created resource
		* @throws JDFException if the CombinedProcessIndex values do not point correctly into Types or the node is not Combined
		* @since 050217
		*/
		JDFResource AddInternalPipe(const WString& resourceName, unsigned int indexOutput, unsigned int indexInput); 

		/**
		* get a heuristic partidkey vector from the partitons of the linked resources
		* @param JDFAttributeMap partMap the partmap to order. If not specified, use the output link
		* @return the ordered vector of partIDKeys
		*/
		vWString GetPartIDKeys(const mAttribute& partMap=mAttribute::emptyMap);

		/**
		* setCombined - set the combined node types to the values in vCombiNodes
		*
		* @param Vector vCombiNodes
		*/
		void setCombined(const vWString& vCombiNodes);

		/**
		* prepare the nodeinfo for a partitioned spawn
		* @param vmAttribute& vSpawnParts the list of parts to spawn
		* @return the vector of nodeinfo leaves
		*/
		vElement PrepareNodeInfo(const vmAttribute& vSpawnParts);

	private:

		/**
		* @param String typ:
		* @return JDFNode:
		*/
		JDFNode AddJDFNode(const WString & typ);

		/**
		* get a prefix for ID creation for the element
		* @return the prefix for the appropriate node 
		* returns "n" for a node
		*
		*/
		virtual WString GetIDPrefix() const;

		/**
		* get a vector of all direct predecessor or following nodes depending on bpre
		* @param boolean bPre: if true get predecessors, if false get following nodes
		* @param boolean bRecurse: if true recurse into previous nodes
		* @param vWString vIDs: vector of nodes to break circular links
		* 
		* @return vElement vector of pre / post decessor nodes
		*/
		vElement GetPredecessors(bool bPre, bool bRecurse, const vWString &vID)const;

		/**
		* calculate whether a link should be RW or RO
		* @param JDFResourceLink li the link to check
		* @param vWString& vRWResources the list of resource ids, process usages, usages, names. 
		*	If any match, the referenced resource is considered rw
		* @return bool true if rw
		*/
		static bool LinkFitsRWRes(const JDFResourceLink& li, const vWString& vRWResources);

		/**
		* calculate whether a link should be RW or RO
		* @param JDFResourceLink li the link to check
		* @param vWString& vRWResources the list of resource ids, process usages, usages, names. 
		*	If any match, the referenced resource is considered rw
		* @return bool true if rw
		*/
		static bool ResFitsRWRes(const JDFResource& r, const vWString& vRWResources);
		/**
		* copies a resource recursively and optionally fixes status flags and locks in the source resource
		* @param JDFREsourcePool p: the pool to copy r into 
		* @param JDFREsource r: the resource to copy 
		* @param JDFResource.SpawnStatus copyStatus: rw or ro
		* @param vmAttribute vParts: part map vector of the partitions to copy
		* @param WString &spawnID the spawnID of the spawning that initiated the copy
		* @param vWString &resInPool internal recursion checker 
		* @param vWString &vRWResources write resources
		* @return vWString: vector of resource names that have been copied
		*/
		static void CopySpawnedResource(JDFResourcePool p, JDFResource r, JDFResource::EnumSpawnStatus copyStatus, const vmAttribute& vParts, const WString &spawnID,const vWString& resInPool,const vWString& vRWResources, vWString& vRWIDs, vWString& vROIDs, bool bSpawnROPartsOnly);

		// Note: class JDFNode::ExecPartFlags has intentionally not been implemented		


	}; // end of class JDFNode

	/**
	* removed utility class for vectors of Nodes
	* identical to vElement but contains JDFNode objects
	*/
#define vJDFNode vElement

}; // end of namespace JDF

#endif // !defined(_JDFNode_H__)
