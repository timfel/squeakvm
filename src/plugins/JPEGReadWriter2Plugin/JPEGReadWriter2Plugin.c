/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2785 uuid: 9fa77ef1-7255-47f3-9dd1-c500f9529cbb
   from
	JPEGReadWriter2Plugin VMMaker.oscog-eem.2785 uuid: 9fa77ef1-7255-47f3-9dd1-c500f9529cbb
 */
static char __buildInfo[] = "JPEGReadWriter2Plugin VMMaker.oscog-eem.2785 uuid: 9fa77ef1-7255-47f3-9dd1-c500f9529cbb " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif

#include "JPEGReadWriter2Plugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primImageHeight(void);
EXPORT(sqInt) primImageNumComponents(void);
EXPORT(sqInt) primImageWidth(void);
EXPORT(sqInt) primJPEGCompressStructSize(void);
EXPORT(sqInt) primJPEGDecompressStructSize(void);
EXPORT(sqInt) primJPEGErrorMgr2StructSize(void);
EXPORT(sqInt) primJPEGPluginIsPresent(void);
EXPORT(sqInt) primJPEGReadHeaderfromByteArrayerrorMgr(void);
EXPORT(sqInt) primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void);
EXPORT(sqInt) primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void);
EXPORT(sqInt) primSupports8BitGrayscaleJPEGs(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*booleanValueOf)(sqInt obj);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*failed)(void);
static sqInt (*falseObject)(void);
static sqInt (*fetchIntegerofObject)(sqInt fieldIndex, sqInt objectPointer);
static sqInt (*fetchPointerofObject)(sqInt index, sqInt oop);
static void * (*firstIndexableField)(sqInt oop);
#if !defined(integerObjectOf)
static sqInt (*integerObjectOf)(sqInt value);
#endif
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
static sqInt (*isKindOf)(sqInt oop, char *aString);
static sqInt (*isBooleanObject)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isWordsOrBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stSizeOf)(sqInt oop);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt booleanValueOf(sqInt obj);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt failed(void);
extern sqInt falseObject(void);
extern sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
extern sqInt fetchPointerofObject(sqInt index, sqInt oop);
extern void * firstIndexableField(sqInt oop);
#if !defined(integerObjectOf)
extern sqInt integerObjectOf(sqInt value);
#endif
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
extern sqInt isKindOf(sqInt oop, char *aString);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
extern sqInt isBooleanObject(sqInt oop);
#else
# define isBooleanObject(oop) 0
#endif
extern sqInt isBytes(sqInt oop);
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
extern sqInt isWordsOrBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stSizeOf(sqInt oop);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "JPEGReadWriter2Plugin VMMaker.oscog-eem.2785 " INT_EXT;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* JPEGReadWriter2Plugin>>#primImageHeight: */
EXPORT(sqInt)
primImageHeight(void)
{
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	if (!(isBytes(stackValue(0)))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	if (!((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGDecompressStruct) - BaseHeaderSize))) >= (sizeof(struct jpeg_decompress_struct)))) {
		return primitiveFail();
	}
	if (!(failed())) {
		_return_value = integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_height));
		if (!(failed())) {
			popthenPush(2, _return_value);
		}
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primImageNumComponents: */
EXPORT(sqInt)
primImageNumComponents(void)
{
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	if (!(isBytes(stackValue(0)))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	if (!((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGDecompressStruct) - BaseHeaderSize))) >= (sizeof(struct jpeg_decompress_struct)))) {
		return primitiveFail();
	}
	if (!(failed())) {
		_return_value = integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->num_components));
		if (!(failed())) {
			popthenPush(2, _return_value);
		}
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primImageWidth: */
EXPORT(sqInt)
primImageWidth(void)
{
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	if (!(isBytes(stackValue(0)))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	if (!((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGDecompressStruct) - BaseHeaderSize))) >= (sizeof(struct jpeg_decompress_struct)))) {
		return primitiveFail();
	}
	if (!(failed())) {
		_return_value = integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_width));
		if (!(failed())) {
			popthenPush(2, _return_value);
		}
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGCompressStructSize */
EXPORT(sqInt)
primJPEGCompressStructSize(void)
{
	sqInt _return_value;

	_return_value = integerObjectOf((sizeof(struct jpeg_compress_struct)));
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGDecompressStructSize */
EXPORT(sqInt)
primJPEGDecompressStructSize(void)
{
	sqInt _return_value;

	_return_value = integerObjectOf((sizeof(struct jpeg_decompress_struct)));
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGErrorMgr2StructSize */
EXPORT(sqInt)
primJPEGErrorMgr2StructSize(void)
{
	sqInt _return_value;

	_return_value = integerObjectOf((sizeof(struct error_mgr2)));
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGPluginIsPresent */
EXPORT(sqInt)
primJPEGPluginIsPresent(void)
{
	sqInt _return_value;

	_return_value = ((1) ? trueObject() : falseObject());
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGReadHeader:fromByteArray:errorMgr: */
EXPORT(sqInt)
primJPEGReadHeaderfromByteArrayerrorMgr(void)
{
	char *aJPEGDecompressStruct;
	char *aJPEGErrorMgr2Struct;
	char *source;
	sqInt sourceSize;

	if (!((isBytes(stackValue(2)))
		 && ((isBytes(stackValue(1)))
		 && (isBytes(stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(2))));
	source = ((char *) (firstIndexableField(stackValue(1))));
	aJPEGErrorMgr2Struct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	if (!(((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGDecompressStruct) - BaseHeaderSize))) >= (sizeof(struct jpeg_decompress_struct)))
		 && ((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGErrorMgr2Struct) - BaseHeaderSize))) >= (sizeof(struct error_mgr2))))) {
		return primitiveFail();
	}
	sourceSize = byteSizeOf(((sqInt)(sqIntptr_t)(source) - BaseHeaderSize));
	if (sourceSize > 0) {
		primJPEGReadHeaderfromByteArraysizeerrorMgrReadHeader(aJPEGDecompressStruct, source, sourceSize, aJPEGErrorMgr2Struct);
	}
	if (!(failed())) {
		pop(3);
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGReadImage:fromByteArray:onForm:doDithering:errorMgr: */
EXPORT(sqInt)
primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void)
{
	char *aJPEGDecompressStruct;
	char *aJPEGErrorMgr2Struct;
	sqInt ditherFlag;
	sqInt form;
	unsigned int *formBitmap;
	sqInt formBitmapOOP;
	sqInt formBitmapSizeInBytes;
	int formComponentBitSize;
	int formComponents;
	sqInt formDepth;
	sqInt formHeight;
	sqInt formNativeDepth;
	sqInt formPitch;
	sqInt formWidth;
	int pixelsPerWord;
	char *source;
	sqInt sourceSize;
	sqInt wordsPerRow;

	if (!((isBytes(stackValue(4)))
		 && ((isBytes(stackValue(3)))
		 && ((isKindOf(stackValue(2), "Form"))
		 && ((isBooleanObject(stackValue(1)))
		 && (isBytes(stackValue(0)))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aJPEGDecompressStruct = ((char *) (firstIndexableField(stackValue(4))));
	source = ((char *) (firstIndexableField(stackValue(3))));
	form = stackValue(2);
	ditherFlag = booleanValueOf(stackValue(1));
	aJPEGErrorMgr2Struct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	formBitmapOOP = fetchPointerofObject(0, form);
	formNativeDepth = fetchIntegerofObject(3, form);
	formWidth = fetchIntegerofObject(1, form);
	formHeight = fetchIntegerofObject(2, form);

	/* Various parameter checks */
	formDepth = SQABS(formNativeDepth);
	if (!(((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGDecompressStruct) - BaseHeaderSize))) >= (sizeof(struct jpeg_decompress_struct)))
		 && ((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGErrorMgr2Struct) - BaseHeaderSize))) >= (sizeof(struct error_mgr2))))) {
		return primitiveFail();
	}
	formComponents = (formDepth != 8
		? 4
		: 1);
	formComponentBitSize = (formDepth != 16
		? 8
		: 4);
	pixelsPerWord = 32 / (formComponents * formComponentBitSize);
	wordsPerRow = ((formWidth + pixelsPerWord) - 1) / pixelsPerWord;
	formPitch = ((formWidth + (pixelsPerWord - 1)) / pixelsPerWord) * 4;
	formBitmapSizeInBytes = byteSizeOf(formBitmapOOP);
	success((isWordsOrBytes(formBitmapOOP))
	 && (formBitmapSizeInBytes >= (formPitch * formHeight)));
	if (failed()) {
		return null;
	}
	sourceSize = stSizeOf(stackValue(3));
	success(sourceSize != 0);
	if (failed()) {
		return null;
	}
	formBitmap = firstIndexableField(formBitmapOOP);
	primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgrReadScanlines(aJPEGDecompressStruct, aJPEGErrorMgr2Struct, source, sourceSize, ditherFlag, formBitmap, pixelsPerWord, wordsPerRow, formNativeDepth);
	if (!(failed())) {
		pop(5);
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primJPEGWriteImage:onByteArray:form:quality:progressiveJPEG:errorMgr: */
EXPORT(sqInt)
primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void)
{
	char *aJPEGCompressStruct;
	char *aJPEGErrorMgr2Struct;
	char *destination;
	unsigned int destinationSize;
	sqInt form;
	unsigned int *formBitmap;
	sqInt formBitmapOOP;
	sqInt formBitmapSizeInBytes;
	int formComponentBitSize;
	int formComponents;
	sqInt formDepth;
	sqInt formHeight;
	sqInt formNativeDepth;
	sqInt formPitch;
	sqInt formWidth;
	int pixelsPerWord;
	sqInt progressiveFlag;
	sqInt quality;
	sqInt wordsPerRow;
	sqInt _return_value;

	if (!((isBytes(stackValue(5)))
		 && ((isBytes(stackValue(4)))
		 && ((isKindOf(stackValue(3), "Form"))
		 && ((isIntegerObject((quality = stackValue(2))))
		 && ((isBooleanObject(stackValue(1)))
		 && (isBytes(stackValue(0))))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aJPEGCompressStruct = ((char *) (firstIndexableField(stackValue(5))));
	destination = ((char *) (firstIndexableField(stackValue(4))));
	form = stackValue(3);
	quality = integerValueOf(quality);
	progressiveFlag = booleanValueOf(stackValue(1));
	aJPEGErrorMgr2Struct = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	formBitmapOOP = fetchPointerofObject(0, form);
	formWidth = fetchIntegerofObject(1, form);
	formHeight = fetchIntegerofObject(2, form);
	formNativeDepth = fetchIntegerofObject(3, form);

	/* Various parameter checks */
	formDepth = SQABS(formNativeDepth);
	if (!(((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGCompressStruct) - BaseHeaderSize))) >= (sizeof(struct jpeg_compress_struct)))
		 && ((byteSizeOf(((sqInt)(sqIntptr_t)(aJPEGErrorMgr2Struct) - BaseHeaderSize))) >= (sizeof(struct error_mgr2))))) {
		return primitiveFail();
	}
	formComponents = (formDepth != 8
		? 4
		: 1);
	formComponentBitSize = (formDepth != 16
		? 8
		: 4);
	pixelsPerWord = 32 / (formComponents * formComponentBitSize);
	wordsPerRow = ((formWidth + pixelsPerWord) - 1) / pixelsPerWord;
	formPitch = wordsPerRow * 4;
	formBitmapSizeInBytes = byteSizeOf(formBitmapOOP);
	success((isWordsOrBytes(formBitmapOOP))
	 && (formBitmapSizeInBytes >= (formPitch * formHeight)));
	if (failed()) {
		return null;
	}
	formBitmap = firstIndexableField(formBitmapOOP);
	destinationSize = stSizeOf(stackValue(4));
	if (destinationSize > 0) {
		primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgrWriteScanlines(formWidth, formHeight, formNativeDepth, formBitmap, aJPEGCompressStruct, aJPEGErrorMgr2Struct, quality, progressiveFlag, pixelsPerWord, wordsPerRow, destination, (&destinationSize));
	}
	if (!(failed())) {
		_return_value = integerObjectOf(destinationSize);
		if (!(failed())) {
			popthenPush(7, _return_value);
		}
	}
	return null;
}

	/* JPEGReadWriter2Plugin>>#primSupports8BitGrayscaleJPEGs */
EXPORT(sqInt)
primSupports8BitGrayscaleJPEGs(void)
{
	sqInt _return_value;

	_return_value = ((1) ? trueObject() : falseObject());
	if (!(failed())) {
		popthenPush(1, _return_value);
	}
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
	sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		booleanValueOf = interpreterProxy->booleanValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		failed = interpreterProxy->failed;
		falseObject = interpreterProxy->falseObject;
		fetchIntegerofObject = interpreterProxy->fetchIntegerofObject;
		fetchPointerofObject = interpreterProxy->fetchPointerofObject;
		firstIndexableField = interpreterProxy->firstIndexableField;
#if !defined(integerObjectOf)
		integerObjectOf = interpreterProxy->integerObjectOf;
#endif
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
		isKindOf = interpreterProxy->isKindOf;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
		isBooleanObject = interpreterProxy->isBooleanObject;
#else
#if !defined(isBooleanObject)
		isBooleanObject = 0;
#endif
#endif
		isBytes = interpreterProxy->isBytes;
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
		isWordsOrBytes = interpreterProxy->isWordsOrBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		stSizeOf = interpreterProxy->stSizeOf;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
		trueObject = interpreterProxy->trueObject;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "JPEGReadWriter2Plugin";
void* JPEGReadWriter2Plugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primImageHeight\000\377", (void*)primImageHeight},
	{(void*)_m, "primImageNumComponents\000\377", (void*)primImageNumComponents},
	{(void*)_m, "primImageWidth\000\377", (void*)primImageWidth},
	{(void*)_m, "primJPEGCompressStructSize\000\377", (void*)primJPEGCompressStructSize},
	{(void*)_m, "primJPEGDecompressStructSize\000\377", (void*)primJPEGDecompressStructSize},
	{(void*)_m, "primJPEGErrorMgr2StructSize\000\377", (void*)primJPEGErrorMgr2StructSize},
	{(void*)_m, "primJPEGPluginIsPresent\000\377", (void*)primJPEGPluginIsPresent},
	{(void*)_m, "primJPEGReadHeaderfromByteArrayerrorMgr\000\377", (void*)primJPEGReadHeaderfromByteArrayerrorMgr},
	{(void*)_m, "primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr\000\002", (void*)primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr},
	{(void*)_m, "primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr\000\002", (void*)primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr},
	{(void*)_m, "primSupports8BitGrayscaleJPEGs\000\377", (void*)primSupports8BitGrayscaleJPEGs},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgrAccessorDepth = 2;
signed char primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgrAccessorDepth = 2;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
