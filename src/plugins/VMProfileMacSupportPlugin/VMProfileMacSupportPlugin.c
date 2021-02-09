/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
   from
	VMProfileMacSupportPlugin VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
 */
static char __buildInfo[] = "VMProfileMacSupportPlugin VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#include <mach-o/getsect.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

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
#define PrimErrBadArgument 3


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveDLSym(void);
EXPORT(sqInt) primitiveExecutableModulesAndOffsets(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classArray)(void);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*nilObject)(void);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static sqInt (*positive64BitIntegerFor)(usqLong integerValue);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*pushRemappableOop)(sqInt oop);
static sqInt (*signed32BitIntegerFor)(sqInt integerValue);
static sqInt (*signed64BitIntegerFor)(sqLong integerValue);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
static sqInt (*topRemappableOop)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classArray(void);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt nilObject(void);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern sqInt positive64BitIntegerFor(usqLong integerValue);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt pushRemappableOop(sqInt oop);
extern sqInt signed32BitIntegerFor(sqInt integerValue);
extern sqInt signed64BitIntegerFor(sqLong integerValue);
extern sqInt stackValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern sqInt topRemappableOop(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "VMProfileMacSupportPlugin VMMaker.oscog-eem.2943 " INT_EXT;



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


/*	Answer the address of the argument in the current process or nil if none. */

	/* VMProfileMacSupportPlugin>>#primitiveDLSym */
EXPORT(sqInt)
primitiveDLSym(void)
{
    void *addr;
    sqInt i;
    char *name;
    sqInt nameObj;
    char *namePtr;
    sqInt sz;

	nameObj = stackValue(0);
	if (!(isBytes(nameObj))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	sz = byteSizeOf(nameObj);
	name = malloc(sz + 1);
	namePtr = firstIndexableField(nameObj);
	for (i = 0; i < sz; i += 1) {
		name[i] = (namePtr[i]);
	}
	name[sz] = 0;
	addr = dlsym(RTLD_SELF,name);
	free(name);
	return methodReturnValue((addr == 0
		? nilObject()
		: (/* begin positiveMachineIntegerFor: */
			(BytesPerWord == 8
					? positive64BitIntegerFor(((usqIntptr_t)addr))
					: positive32BitIntegerFor(((usqIntptr_t)addr))))));
}


/*	Answer an Array of quads for executable modules (the VM executable
	and loaded libraries). Each quad is the module's name, its vm address
	relocation in memory, the (unrelocated) start address, and the size. */

	/* VMProfileMacSupportPlugin>>#primitiveExecutableModulesAndOffsets */
EXPORT(sqInt)
primitiveExecutableModulesAndOffsets(void)
{
    const struct mach_header *h;
    const struct mach_header_64 *h64;
    sqInt i;
    const char *name;
    char *nameObjData;
    sqInt nimages;
    sqInt resultObj;
    const struct section *s;
    const struct section_64 *s64;
    usqIntptr_t size;
    usqIntptr_t slide;
    usqIntptr_t start;
    sqInt valueObj;


#  if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_4

	/* _dyld_present was deprecated in 10.5 */
	if (!(_dyld_present())) {
		return primitiveFail();
	}
#  endif
	nimages = _dyld_image_count();
	resultObj = instantiateClassindexableSize(classArray(), nimages * 4);
	if (resultObj == 0) {
		return primitiveFail();
	}
	pushRemappableOop(resultObj);
	for (i = 0; i < nimages; i += 1) {

		/* impossible start & size */
		start = (size = -1);
		name = _dyld_get_image_name(i);
		slide = _dyld_get_image_vmaddr_slide(i);
#    if __x86_64__
		h64 = (const struct mach_header_64 *)_dyld_get_image_header(i);
		if (!(h64 == null)) {
			s64 = getsectbynamefromheader_64(h64,SEG_TEXT,SECT_TEXT);
			if (!(s64 == null)) {
				start = s64->addr;
				size = s64->size;
			}
		}
#    else /* __x86_64__ */
		h = _dyld_get_image_header(i);
		if (!(h == null)) {
			s = getsectbynamefromheader(h,SEG_TEXT,SECT_TEXT);
			if (!(s == null)) {
				start = s->addr;
				size = s->size;
			}
		}
#    endif /* __x86_64__ */
		valueObj = instantiateClassindexableSize(classString(), strlen(name));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue(i * 4, topRemappableOop(), valueObj);
		nameObjData = arrayValueOf(valueObj);
		memcpy(nameObjData, name, strlen(name));
		valueObj = (BytesPerWord == 8
			? signed64BitIntegerFor(slide)
			: signed32BitIntegerFor(slide));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue((i * 4) + 1, topRemappableOop(), valueObj);
		/* begin positiveMachineIntegerFor: */
		valueObj = (BytesPerWord == 8
			? positive64BitIntegerFor(start)
			: positive32BitIntegerFor(start));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue((i * 4) + 2, topRemappableOop(), valueObj);
		/* begin positiveMachineIntegerFor: */
		valueObj = (BytesPerWord == 8
			? positive64BitIntegerFor(size)
			: positive32BitIntegerFor(size));
		if (failed()) {
			popRemappableOop();
			return primitiveFail();
		}
		storePointerofObjectwithValue((i * 4) + 3, topRemappableOop(), valueObj);
	}
	resultObj = popRemappableOop();
	return popthenPush(1, resultObj);
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
		arrayValueOf = interpreterProxy->arrayValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		classArray = interpreterProxy->classArray;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		methodReturnValue = interpreterProxy->methodReturnValue;
		nilObject = interpreterProxy->nilObject;
		popthenPush = interpreterProxy->popthenPush;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		positive64BitIntegerFor = interpreterProxy->positive64BitIntegerFor;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		signed32BitIntegerFor = interpreterProxy->signed32BitIntegerFor;
		signed64BitIntegerFor = interpreterProxy->signed64BitIntegerFor;
		stackValue = interpreterProxy->stackValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
		topRemappableOop = interpreterProxy->topRemappableOop;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "VMProfileMacSupportPlugin";
void* VMProfileMacSupportPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDLSym\000\001", (void*)primitiveDLSym},
	{(void*)_m, "primitiveExecutableModulesAndOffsets\000\377", (void*)primitiveExecutableModulesAndOffsets},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDLSymAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
