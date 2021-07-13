/* Automatically generated by
	CCodeGenerator * VMMaker.oscog-eem.2980 uuid: 540cacd9-187d-4e9b-b357-47076ef661c8
 */

typedef struct {
	unsigned short	homeOffset;
	unsigned short	startpc;
;
	unsigned		cmNumArgs : 8;
	unsigned		cmType : 3;
	unsigned		cmRefersToYoung : 1;
	unsigned		cpicHasMNUCaseOrCMIsFullBlock : 1;
	unsigned		cmUsageCount : 3;
	unsigned		cmUsesPenultimateLit : 1;
	unsigned		cbUsesInstVars : 1;
	unsigned		cmHasMovableLiteral : 1;
	unsigned		cmUnusedFlag : 1;
	unsigned		stackCheckOffset : 12;
 } CogBlockMethod;

typedef struct {
	sqInt	objectHeader;
	unsigned		cmNumArgs : 8;
	unsigned		cmType : 3;
	unsigned		cmRefersToYoung : 1;
	unsigned		cpicHasMNUCaseOrCMIsFullBlock : 1;
	unsigned		cmUsageCount : 3;
	unsigned		cmUsesPenultimateLit : 1;
	unsigned		cbUsesInstVars : 1;
	unsigned		cmHasMovableLiteral : 1;
	unsigned		cmUnusedFlag : 1;
	unsigned		stackCheckOffset : 12;
	unsigned short	blockSize;
	unsigned short	blockEntryOffset;
	sqInt	methodObject;
	sqInt	methodHeader;
	sqInt	selector;
 } CogMethod;
