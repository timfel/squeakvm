/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
   from
	XDisplayControlPlugin VMConstruction-Plugins-XDisplayControlPlugin.oscog-eem.19 uuid: 51bf0a7a-bd19-4c35-9f1f-2d67c4cde3c4
 */
static char __buildInfo[] = "XDisplayControlPlugin VMConstruction-Plugins-XDisplayControlPlugin.oscog-eem.19 uuid: 51bf0a7a-bd19-4c35-9f1f-2d67c4cde3c4 " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <X11/Xlib.h>

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


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
EXPORT(sqInt) primitiveCanConnectToDisplay(void);
EXPORT(sqInt) primitiveDisconnectDisplay(void);
EXPORT(sqInt) primitiveFlushDisplay(void);
EXPORT(sqInt) primitiveGetDisplayName(void);
EXPORT(sqInt) primitiveIsConnectedToDisplay(void);
EXPORT(sqInt) primitiveKillDisplay(void);
EXPORT(sqInt) primitiveModuleName(void);
EXPORT(sqInt) primitiveOpenDisplay(void);
EXPORT(sqInt) primitiveSetDisplayName(void);
EXPORT(sqInt) primitiveVersionString(void);
static sqInt sandboxSecurity(void);
static sqInt securityHeurisitic(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static char * transientCStringFromString(sqInt aString);
static char * versionString(void);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*classString)(void);
static sqInt (*falseObject)(void);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static void * (*ioLoadFunctionFrom)(char *functionName, char *moduleName);
static sqInt (*methodReturnString)(char *aCString);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*nilObject)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popRemappableOop)(void);
static sqInt (*push)(sqInt object);
static sqInt (*pushInteger)(sqInt integerValue);
static sqInt (*pushRemappableOop)(sqInt oop);
static sqInt (*sizeOfSTArrayFromCPrimitive)(void *cPtr);
static sqInt (*stackObjectValue)(sqInt offset);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt classString(void);
extern sqInt falseObject(void);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern void * ioLoadFunctionFrom(char *functionName, char *moduleName);
extern sqInt methodReturnString(char *aCString);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt nilObject(void);
extern sqInt pop(sqInt nItems);
extern sqInt popRemappableOop(void);
extern sqInt push(sqInt object);
extern sqInt pushInteger(sqInt integerValue);
extern sqInt pushRemappableOop(sqInt oop);
extern sqInt sizeOfSTArrayFromCPrimitive(void *cPtr);
extern sqInt stackObjectValue(sqInt offset);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "XDisplayControlPlugin VMConstruction-Plugins-XDisplayControlPlugin.oscog-eem.19 " INT_EXT;
static int osprocessSandboxSecurity;



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

	/* XDisplayControlPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	osprocessSandboxSecurity = -1;
	return 1;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

	/* XDisplayControlPlugin>>#moduleUnloaded: */
EXPORT(sqInt)
moduleUnloaded(char *aModuleName)
{
	return 0;
}


/*	Open and close a connection to displayName. It the connection was
	successfully opened, answer true; otherwise false. This is intended to
	check for the ability
	to open an X display prior to actually making the attempt.
 */

	/* XDisplayControlPlugin>>#primitiveCanConnectToDisplay */
EXPORT(sqInt)
primitiveCanConnectToDisplay(void)
{
    Display *d;
    sqInt name;
    char * namePtr;


	/* Do not allow this if running in secure mode */
	if ((sandboxSecurity()) == 1) {
		pop(2);
		push(falseObject());
	}
	else {
		name = stackObjectValue(0);
		namePtr = transientCStringFromString(name);
		d = XOpenDisplay(namePtr);
		if (d == 0) {

			/* Failed to make connection to server, answer false */
			pop(2);
			push(falseObject());
		}
		else {

			/* Successfully opened connection; close it and answer true */
			XCloseDisplay(d);
			pop(2);
			push(trueObject());
		}
	}
	return 0;
}


/*	Call an internal function which will disconnect the X display session. The
	actual Squeak window on the X server is not effected, but this instance of
	Squeak will
	not have any further interaction with it.
 */
/*	Do not allow this if running in secure mode */

	/* XDisplayControlPlugin>>#primitiveDisconnectDisplay */
EXPORT(sqInt)
primitiveDisconnectDisplay(void)
{
	if (!((sandboxSecurity()) == 1)) {
		forgetXDisplay();
	}
	return 0;
}


/*	Call an internal function to synchronize output to the X display. */

	/* XDisplayControlPlugin>>#primitiveFlushDisplay */
EXPORT(sqInt)
primitiveFlushDisplay(void)
{
	synchronizeXDisplay();
	return 0;
}


/*	Answer a string containing the name for the X display, or nil if the
	display was opened
	using the $DISPLAY environment variable. This answers the name of the X
	display as of
	the time it was last opened, which may be different from the current
	setting of $DISPLAY.
 */

	/* XDisplayControlPlugin>>#primitiveGetDisplayName */
EXPORT(sqInt)
primitiveGetDisplayName(void)
{
    extern char *displayName;

	/* begin methodReturnStringOrNil: */
	if (displayName == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(displayName);
	}
	return 0;
}


/*	Answer true if VM is currently connected to an X server. */

	/* XDisplayControlPlugin>>#primitiveIsConnectedToDisplay */
EXPORT(sqInt)
primitiveIsConnectedToDisplay(void)
{
    extern int isConnectedToXServer;

	if (isConnectedToXServer != 0) {
		pop(1);
		push(trueObject());
	}
	else {
		pop(1);
		push(falseObject());
	}
	return 0;
}


/*	Call an internal function to disconnect the X display session and destroy
	the Squeak window on the X display. */
/*	Do not allow this if running in secure mode */

	/* XDisplayControlPlugin>>#primitiveKillDisplay */
EXPORT(sqInt)
primitiveKillDisplay(void)
{
	if (!((sandboxSecurity()) == 1)) {
		disconnectXDisplay();
	}
	return 0;
}


/*	Answer a string containing the module name string for this plugin. */

	/* XDisplayControlPlugin>>#primitiveModuleName */
EXPORT(sqInt)
primitiveModuleName(void)
{
	methodReturnString(getModuleName());
	return 0;
}


/*	Call an internal function which will open the X display session. */
/*	Do not allow this if running in secure mode */

	/* XDisplayControlPlugin>>#primitiveOpenDisplay */
EXPORT(sqInt)
primitiveOpenDisplay(void)
{
	if (!((sandboxSecurity()) == 1)) {
		openXDisplay();
	}
	return 0;
}


/*	Set the name for the X display for use in the next call to
	primitiveOpenXDisplay. Expects
	one parameter which must be either a String or nil.
 */

	/* XDisplayControlPlugin>>#primitiveSetDisplayName */
EXPORT(sqInt)
primitiveSetDisplayName(void)
{
    extern char *displayName;
    sqInt name;
    static char nameBuffer[501];
    char * namePtr;


	/* Do not allow this if running in secure mode */
	if ((sandboxSecurity()) == 1) {
		pop(2);
		pushInteger(-1);
	}
	else {
		name = stackObjectValue(0);
		if (name == (nilObject())) {
			displayName = 0;
		}
		else {
			namePtr = transientCStringFromString(name);
			strncpy(nameBuffer, namePtr, 500);
			nameBuffer[500] = 0;
			displayName = nameBuffer;
		}
		pop(1);
	}
	return 0;
}


/*	Answer a string containing the version string for this plugin. */

	/* XDisplayControlPlugin>>#primitiveVersionString */
EXPORT(sqInt)
primitiveVersionString(void)
{
	methodReturnString(versionString());
	return 0;
}


/*	Answer 1 if running in secure mode, else 0. The osprocessSandboxSecurity
	variable is initialized to -1. On the first call to this method, set its
	value to
	either 0 (user has full access to the plugin) or 1 (user is not permitted
	to do
	dangerous things).
 */

	/* XDisplayControlPlugin>>#sandboxSecurity */
static sqInt
sandboxSecurity(void)
{
	if (osprocessSandboxSecurity < 0) {
		osprocessSandboxSecurity = securityHeurisitic();
	}
	return osprocessSandboxSecurity;
}


/*	Answer 0 to permit full access to OSProcess functions, or 1 if access
	should be
	restricted for dangerous functions. The rules are:
	- If the security plugin is not present, grant full access
	- If the security plugin can be loaded, restrict access unless user has
	all of secCanWriteImage, secHasFileAccess and secHasSocketAccess */
/*	FIXME: This function has not been tested. -dtl */
/*	If the security plugin can be loaded, use it to check. If not, assume it's
	ok 
 */

	/* XDisplayControlPlugin>>#securityHeurisitic */
static sqInt
securityHeurisitic(void)
{
    sqInt canWriteImage;
    sqInt hasFileAccess;
    sqInt hasSocketAccess;
    void (*sCWIfn)(void);
    void (*sHFAfn)(void);
    void (*sHSAfn)(void);

	sCWIfn = ioLoadFunctionFrom("secCanWriteImage", "SecurityPlugin");
	if (sCWIfn == 0) {
		return 0;
	}
	canWriteImage = ((sqInt (*) (void)) sCWIfn)();
	sHFAfn = ioLoadFunctionFrom("secHasFileAccess", "SecurityPlugin");
	if (sHFAfn == 0) {
		return 0;
	}
	hasFileAccess = ((sqInt (*) (void)) sHFAfn)();
	sHSAfn = ioLoadFunctionFrom("secHasSocketAccess", "SecurityPlugin");
	if (sHSAfn == 0) {
		return 0;
	}
	hasSocketAccess = ((sqInt (*) (void)) sHSAfn)();
	return ((canWriteImage
	 && (hasFileAccess))
	 && (hasSocketAccess)
		? 0
		: 1);
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
		classString = interpreterProxy->classString;
		falseObject = interpreterProxy->falseObject;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		ioLoadFunctionFrom = interpreterProxy->ioLoadFunctionFrom;
		methodReturnString = interpreterProxy->methodReturnString;
		methodReturnValue = interpreterProxy->methodReturnValue;
		nilObject = interpreterProxy->nilObject;
		pop = interpreterProxy->pop;
		popRemappableOop = interpreterProxy->popRemappableOop;
		push = interpreterProxy->push;
		pushInteger = interpreterProxy->pushInteger;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		sizeOfSTArrayFromCPrimitive = interpreterProxy->sizeOfSTArrayFromCPrimitive;
		stackObjectValue = interpreterProxy->stackObjectValue;
		trueObject = interpreterProxy->trueObject;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Answer a new null-terminated C string copied from aString.
	The string is allocated in object memory, and will be moved
	without warning by the garbage collector. Any C pointer
	reference the the result is valid only until the garbage
	collector next runs. Therefore, this method should only be used
	within a single primitive in a section of code in which the
	garbage collector is guaranteed not to run. Note also that
	this method may itself invoke the garbage collector prior
	to allocating the new C string.
	
	Warning: The result of this method will be invalidated by the
	next garbage collection, including a GC triggered by creation
	of a new object within a primitive. Do not call this method
	twice to obtain two string pointers.
 */

	/* XDisplayControlPlugin>>#transientCStringFromString: */
static char *
transientCStringFromString(sqInt aString)
{
    char *cString;
    sqInt len;
    sqInt newString;
    char *stringPtr;


	/* Allocate space for a null terminated C string. */
	len = sizeOfSTArrayFromCPrimitive(arrayValueOf(aString));
	
#if SPURVM
	newString = instantiateClassindexableSize(classString(), len + 1);
#else /* SPURVM */
	pushRemappableOop(aString);
	newString = instantiateClassindexableSize(classString(), len + 1);
	aString = popRemappableOop();
#endif /* SPURVM */
	stringPtr = arrayValueOf(aString);

	/* Point to the actual C string. */
	cString = arrayValueOf(newString);
	strncpy(cString, stringPtr, len);
	cString[len] = 0;
	return cString;
}


/*	Answer a string containing the version string for this plugin. Handle MNU
	errors, which can occur if class InterpreterPlugin has been removed from
	the system.
	
	Important: When this method is changed, the class side method must also be
	changed to match.
 */
/*	2.0 supports 64bit code base */

	/* XDisplayControlPlugin>>#versionString */
static char *
versionString(void)
{
    static char version[]= "2.1.6";

	return version;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "XDisplayControlPlugin";
void* XDisplayControlPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "moduleUnloaded", (void*)moduleUnloaded},
	{(void*)_m, "primitiveCanConnectToDisplay\000\001", (void*)primitiveCanConnectToDisplay},
	{(void*)_m, "primitiveDisconnectDisplay\000\377", (void*)primitiveDisconnectDisplay},
	{(void*)_m, "primitiveFlushDisplay\000\377", (void*)primitiveFlushDisplay},
	{(void*)_m, "primitiveGetDisplayName\000\377", (void*)primitiveGetDisplayName},
	{(void*)_m, "primitiveIsConnectedToDisplay\000\377", (void*)primitiveIsConnectedToDisplay},
	{(void*)_m, "primitiveKillDisplay\000\377", (void*)primitiveKillDisplay},
	{(void*)_m, "primitiveModuleName\000\377", (void*)primitiveModuleName},
	{(void*)_m, "primitiveOpenDisplay\000\377", (void*)primitiveOpenDisplay},
	{(void*)_m, "primitiveSetDisplayName\000\001", (void*)primitiveSetDisplayName},
	{(void*)_m, "primitiveVersionString\000\377", (void*)primitiveVersionString},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveCanConnectToDisplayAccessorDepth = 1;
signed char primitiveSetDisplayNameAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
