/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
   from
	SoundCodecPlugin VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
 */
static char __buildInfo[] = "SoundCodecPlugin VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#include "SoundCodecPrims.h"
#include "sqMemoryAccess.h"

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

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


/*** Constants ***/
#define PrimErrNoMemory 9


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveGSMDecode(void);
EXPORT(sqInt) primitiveGSMEncode(void);
EXPORT(sqInt) primitiveGSMNewState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classByteArray)(void);
static sqInt (*failed)(void);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWordsOrShorts)(sqInt oop);
static sqInt (*makePointwithxValueyValue)(sqInt xValue, sqInt yValue);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classByteArray(void);
extern sqInt failed(void);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
extern sqInt isWordsOrShorts(sqInt oop);
#else
# define isWordsOrShorts(oop) 0
#endif
extern sqInt makePointwithxValueyValue(sqInt xValue, sqInt yValue);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "SoundCodecPrims VMMaker.oscog-eem.2943 " INT_EXT;



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

	/* SoundCodecPlugin>>#primitiveGSMDecode */
EXPORT(sqInt)
primitiveGSMDecode(void)
{
    sqInt dst;
    sqInt dstDelta;
    sqInt dstIndex;
    sqInt dstSize;
    sqInt frameCount;
    sqInt result;
    sqInt src;
    sqInt srcDelta;
    sqInt srcIndex;
    sqInt srcSize;
    sqInt state;

	dstDelta = 0;
	srcDelta = 0;
	dstIndex = stackIntegerValue(0);
	dst = stackValue(1);
	srcIndex = stackIntegerValue(2);
	src = stackValue(3);
	frameCount = stackIntegerValue(4);
	state = stackValue(5);
	success((isWordsOrShorts(dst))
	 && ((isBytes(src))
	 && (isBytes(state))));
	if (failed()) {
		return null;
	}
	srcSize = byteSizeOf(src);
	dstSize = (byteSizeOf(dst)) / 2;
	gsmDecode(state + BaseHeaderSize, frameCount, src, srcIndex, srcSize, dst, dstIndex, dstSize, (&srcDelta), (&dstDelta));
	if (failed()) {
		return null;
	}
	result = makePointwithxValueyValue(srcDelta, dstDelta);
	if (failed()) {
		return null;
	}
	methodReturnValue(result);
	return 0;
}

	/* SoundCodecPlugin>>#primitiveGSMEncode */
EXPORT(sqInt)
primitiveGSMEncode(void)
{
    sqInt dst;
    sqInt dstDelta;
    sqInt dstIndex;
    sqInt dstSize;
    sqInt frameCount;
    sqInt result;
    sqInt src;
    sqInt srcDelta;
    sqInt srcIndex;
    sqInt srcSize;
    sqInt state;

	dstDelta = 0;
	srcDelta = 0;
	dstIndex = stackIntegerValue(0);
	dst = stackValue(1);
	srcIndex = stackIntegerValue(2);
	src = stackValue(3);
	frameCount = stackIntegerValue(4);
	state = stackValue(5);
	success((isBytes(dst))
	 && ((isWordsOrShorts(src))
	 && (isBytes(state))));
	if (failed()) {
		return null;
	}
	srcSize = (byteSizeOf(src)) / 2;
	dstSize = byteSizeOf(dst);
	gsmEncode(state + BaseHeaderSize, frameCount, src, srcIndex, srcSize, dst, dstIndex, dstSize, (&srcDelta), (&dstDelta));
	if (failed()) {
		return null;
	}
	result = makePointwithxValueyValue(srcDelta, dstDelta);
	if (failed()) {
		return null;
	}
	methodReturnValue(result);
	return 0;
}

	/* SoundCodecPlugin>>#primitiveGSMNewState */
EXPORT(sqInt)
primitiveGSMNewState(void)
{
    sqInt state;

	state = instantiateClassindexableSize(classByteArray(), gsmStateBytes());
	if (state == null) {
		primitiveFailFor(PrimErrNoMemory);
	}
	else {
		gsmInitState(state + BaseHeaderSize);
		methodReturnValue(state);
	}
	return 0;
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
		byteSizeOf = interpreterProxy->byteSizeOf;
		classByteArray = interpreterProxy->classByteArray;
		failed = interpreterProxy->failed;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
		isWordsOrShorts = interpreterProxy->isWordsOrShorts;
#else
#if !defined(isWordsOrShorts)
		isWordsOrShorts = 0;
#endif
#endif
		makePointwithxValueyValue = interpreterProxy->makePointwithxValueyValue;
		methodReturnValue = interpreterProxy->methodReturnValue;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "SoundCodecPrims";
void* SoundCodecPrims_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveGSMDecode\000\000", (void*)primitiveGSMDecode},
	{(void*)_m, "primitiveGSMEncode\000\000", (void*)primitiveGSMEncode},
	{(void*)_m, "primitiveGSMNewState\000\377", (void*)primitiveGSMNewState},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveGSMDecodeAccessorDepth = 0;
signed char primitiveGSMEncodeAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
