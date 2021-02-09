/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
   from
	SoundPlugin VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b
 */
static char __buildInfo[] = "SoundPlugin VMMaker.oscog-eem.2943 uuid: e003897d-8105-40a7-bffe-2e8f14f31b5b " __DATE__ ;



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

#include "SoundPlugin.h"
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
#define PrimErrBadIndex 4
#define PrimErrBadNumArgs 5
#define PrimErrGenericFailure 1
#define PrimErrNoCMemory 10
#define PrimErrNoMemory 9


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveGetDefaultSoundPlayer(void);
EXPORT(sqInt) primitiveGetDefaultSoundRecorder(void);
EXPORT(sqInt) primitiveGetNumberOfSoundPlayerDevices(void);
EXPORT(sqInt) primitiveGetNumberOfSoundRecorderDevices(void);
EXPORT(sqInt) primitiveGetSoundPlayerDeviceName(void);
#if TerfVM
EXPORT(sqInt) primitiveGetSoundPlayerDeviceUID(void);
#endif /* TerfVM */
EXPORT(sqInt) primitiveGetSoundRecorderDeviceName(void);
#if TerfVM
EXPORT(sqInt) primitiveGetSoundRecorderDeviceUID(void);
#endif /* TerfVM */
EXPORT(sqInt) primitiveSetDefaultSoundPlayer(void);
EXPORT(sqInt) primitiveSetDefaultSoundRecorder(void);
EXPORT(sqInt) primitiveSoundAvailableSpace(void);
EXPORT(sqInt) primitiveSoundEnableAEC(void);
EXPORT(sqInt) primitiveSoundGetRecordingSampleRate(void);
EXPORT(sqInt) primitiveSoundGetRecordLevel(void);
EXPORT(sqInt) primitiveSoundGetVolume(void);
EXPORT(sqInt) primitiveSoundInsertSamples(void);
EXPORT(sqInt) primitiveSoundPlaySamples(void);
EXPORT(sqInt) primitiveSoundPlaySilence(void);
EXPORT(sqInt) primitiveSoundRecordSamples(void);
EXPORT(sqInt) primitiveSoundSetLeftVolume(void);
EXPORT(sqInt) primitiveSoundSetRecordLevel(void);
EXPORT(sqInt) primitiveSoundStart(void);
EXPORT(sqInt) primitiveSoundStartRecording(void);
EXPORT(sqInt) primitiveSoundStartWithSemaphore(void);
EXPORT(sqInt) primitiveSoundStop(void);
EXPORT(sqInt) primitiveSoundStopRecording(void);
EXPORT(sqInt) primitiveSoundSupportsAEC(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
EXPORT(sqInt) shutdownModule(void);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*booleanValueOf)(sqInt obj);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classArray)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*floatObjectOf)(double aFloat);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
static sqInt (*isBooleanObject)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isFloatObject)(sqInt oop);
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isWordsOrShorts)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnBool)(sqInt boolean);
static sqInt (*methodReturnFloat)(double aFloat);
static sqInt (*methodReturnInteger)(sqInt integer);
static sqInt (*methodReturnReceiver)(void);
static sqInt (*methodReturnString)(char *aCString);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*nilObject)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static usqInt (*positive32BitValueOf)(sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*pushRemappableOop)(sqInt oop);
static double (*stackFloatValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt booleanValueOf(sqInt obj);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classArray(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt floatObjectOf(double aFloat);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
extern sqInt isBooleanObject(sqInt oop);
#else
# define isBooleanObject(oop) 0
#endif
extern sqInt isBytes(sqInt oop);
extern sqInt isFloatObject(sqInt oop);
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
extern sqInt isWordsOrShorts(sqInt oop);
#else
# define isWordsOrShorts(oop) 0
#endif
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnBool(sqInt boolean);
extern sqInt methodReturnFloat(double aFloat);
extern sqInt methodReturnInteger(sqInt integer);
extern sqInt methodReturnReceiver(void);
extern sqInt methodReturnString(char *aCString);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt nilObject(void);
extern sqInt pop(sqInt nItems);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern usqInt positive32BitValueOf(sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt pushRemappableOop(sqInt oop);
extern double stackFloatValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "SoundPlugin VMMaker.oscog-eem.2943 " INT_EXT;



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

	/* SoundPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return soundInit();
}


/*	Answer a String with the operating system name of the default output
	device, or nil
 */
/*	no arguments */

	/* SoundPlugin>>#primitiveGetDefaultSoundPlayer */
EXPORT(sqInt)
primitiveGetDefaultSoundPlayer(void)
{
	char *cString;

	/* begin methodReturnStringOrNil: */
	cString = ((char *) (getDefaultSoundPlayer()));
	if (cString == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(cString);
	}
	return 0;
}


/*	Answer a String with the operating system name of the default input
	device, or nil
 */
/*	no arguments */

	/* SoundPlugin>>#primitiveGetDefaultSoundRecorder */
EXPORT(sqInt)
primitiveGetDefaultSoundRecorder(void)
{
	char *cString;

	/* begin methodReturnStringOrNil: */
	cString = ((char *) (getDefaultSoundRecorder()));
	if (cString == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(cString);
	}
	return 0;
}

	/* SoundPlugin>>#primitiveGetNumberOfSoundPlayerDevices */
EXPORT(sqInt)
primitiveGetNumberOfSoundPlayerDevices(void)
{
	return methodReturnInteger(getNumberOfSoundPlayerDevices());
}

	/* SoundPlugin>>#primitiveGetNumberOfSoundRecorderDevices */
EXPORT(sqInt)
primitiveGetNumberOfSoundRecorderDevices(void)
{
	return methodReturnInteger(getNumberOfSoundRecorderDevices());
}


/*	arguments: name(type, stack offset)
	deviceNumber(Integer, 0) */
/*	answers a string or nil */
/*	Parse arguments */

	/* SoundPlugin>>#primitiveGetSoundPlayerDeviceName */
EXPORT(sqInt)
primitiveGetSoundPlayerDeviceName(void)
{
	char *cString;
	usqInt deviceNumber;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	deviceNumber = positive32BitValueOf(stackValue(0));
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin methodReturnStringOrNil: */
	cString = ((char *) (getSoundPlayerDeviceName(deviceNumber - 1)));
	if (cString == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(cString);
	}
	return 0;
}


/*	arguments: name(type, stack offset)
	deviceNumber(Integer, 0) */
/*	answers a string or nil */
/*	Parse arguments */

	/* SoundPlugin>>#primitiveGetSoundPlayerDeviceUID */
#if TerfVM
EXPORT(sqInt)
primitiveGetSoundPlayerDeviceUID(void)
{
	char *cString;
	usqInt deviceNumber;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	deviceNumber = positive32BitValueOf(stackValue(0));
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin methodReturnStringOrNil: */
	cString = ((char *) (getSoundPlayerDeviceUID(deviceNumber - 1)));
	if (cString == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(cString);
	}
	return 0;
}
#endif /* TerfVM */


/*	arguments: name(type, stack offset)
	deviceNumber(Integer, 0) */
/*	answers a string or nil */
/*	Parse arguments */

	/* SoundPlugin>>#primitiveGetSoundRecorderDeviceName */
EXPORT(sqInt)
primitiveGetSoundRecorderDeviceName(void)
{
	char *cString;
	usqInt deviceNumber;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	deviceNumber = positive32BitValueOf(stackValue(0));
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin methodReturnStringOrNil: */
	cString = ((char *) (getSoundRecorderDeviceName(deviceNumber - 1)));
	if (cString == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(cString);
	}
	return 0;
}


/*	arguments: name(type, stack offset)
	deviceNumber(Integer, 0) */
/*	answers a string or nil */
/*	Parse arguments */

	/* SoundPlugin>>#primitiveGetSoundRecorderDeviceUID */
#if TerfVM
EXPORT(sqInt)
primitiveGetSoundRecorderDeviceUID(void)
{
	char *cString;
	usqInt deviceNumber;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	deviceNumber = positive32BitValueOf(stackValue(0));
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin methodReturnStringOrNil: */
	cString = ((char *) (getSoundRecorderDeviceUID(deviceNumber - 1)));
	if (cString == null) {
		methodReturnValue(nilObject());
	}
	else {
		methodReturnString(cString);
	}
	return 0;
}
#endif /* TerfVM */


/*	Tell the operating system to use the specified device name as the output
	device for sound.
 */
/*	arg at top of stack is the String */
/*	Parse arguments */

	/* SoundPlugin>>#primitiveSetDefaultSoundPlayer */
EXPORT(sqInt)
primitiveSetDefaultSoundPlayer(void)
{
	char * deviceName;
	char *dstPtr;
	sqInt obj;
	sqInt sz;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	/* begin stackEphemeralStringValue: */
	obj = stackValue(0);
	if (!(isBytes(obj))) {
		primitiveFailFor(PrimErrBadArgument);
		deviceName = null;
		goto l1;
	}
	sz = byteSizeOf(obj);
	dstPtr = alloca(sz + 1);
	if (!dstPtr) {
		primitiveFailFor(PrimErrNoCMemory);
		deviceName = null;
		goto l1;
	}
	memcpy(dstPtr, firstIndexableField(obj), sz);
	dstPtr[sz] = 0;
	deviceName = dstPtr;
	l1:	/* end stackEphemeralStringValue: */;
	if (!(failed())) {
		setDefaultSoundPlayer(deviceName);
		if (!(failed())) {
			methodReturnReceiver();
		}
	}
	return 0;
}


/*	Tell the operating system to use the specified device name as the input
	device for sound.
 */
/*	arg at top of stack is the String */
/*	Parse arguments */

	/* SoundPlugin>>#primitiveSetDefaultSoundRecorder */
EXPORT(sqInt)
primitiveSetDefaultSoundRecorder(void)
{
	char * deviceName;
	char *dstPtr;
	sqInt obj;
	sqInt sz;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	/* begin stackEphemeralStringValue: */
	obj = stackValue(0);
	if (!(isBytes(obj))) {
		primitiveFailFor(PrimErrBadArgument);
		deviceName = null;
		goto l1;
	}
	sz = byteSizeOf(obj);
	dstPtr = alloca(sz + 1);
	if (!dstPtr) {
		primitiveFailFor(PrimErrNoCMemory);
		deviceName = null;
		goto l1;
	}
	memcpy(dstPtr, firstIndexableField(obj), sz);
	dstPtr[sz] = 0;
	deviceName = dstPtr;
	l1:	/* end stackEphemeralStringValue: */;
	if (!(failed())) {
		setDefaultSoundRecorder(deviceName);
		if (!(failed())) {
			methodReturnReceiver();
		}
	}
	return 0;
}


/*	Returns the number of bytes of available sound output buffer space.
	This should be (frames*4) if the device is in stereo mode, or (frames*2)
	otherwise 
 */

	/* SoundPlugin>>#primitiveSoundAvailableSpace */
EXPORT(sqInt)
primitiveSoundAvailableSpace(void)
{
	sqInt frames;


	/* -1 if sound output not started */
	frames = snd_AvailableSpace();
	if (frames >= 0) {
		methodReturnInteger(frames);
	}
	else {
		primitiveFail();
	}
	return 0;
}


/*	Enable or disable acoustic echo-cancellation (AEC).
	Arg is a boolean or 1 for true and 0 for false. */

	/* SoundPlugin>>#primitiveSoundEnableAEC */
EXPORT(sqInt)
primitiveSoundEnableAEC(void)
{
	sqInt arg;
	sqInt errorCode;
	int trueOrFalse;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	if (isIntegerObject((arg = stackValue(0)))) {
		arg = integerValueOf(arg);
		if ((((unsigned) arg)) > 1) {
			return primitiveFailFor(PrimErrBadArgument);
		}
		trueOrFalse = arg == 1;
	}
	else {
		if (!(isBooleanObject(arg))) {
			return primitiveFailFor(PrimErrBadArgument);
		}
		trueOrFalse = booleanValueOf(arg);
	}
	if (((errorCode = snd_EnableAEC(trueOrFalse))) != 0) {
		primitiveFailFor((errorCode < 0
			? PrimErrGenericFailure
			: errorCode));
	}
	methodReturnReceiver();
	return 0;
}


/*	Return a float representing the actual sampling rate during recording.
	Fail if not currently recording.
 */

	/* SoundPlugin>>#primitiveSoundGetRecordingSampleRate */
EXPORT(sqInt)
primitiveSoundGetRecordingSampleRate(void)
{
	double rate;


	/* fails if not recording */
	rate = snd_GetRecordingSampleRate();
	if (!(failed())) {
		return methodReturnFloat(rate);
	}
	return 0;
}


/*	Get the default input device's volume level in the range 0-1000. */

	/* SoundPlugin>>#primitiveSoundGetRecordLevel */
EXPORT(sqInt)
primitiveSoundGetRecordLevel(void)
{
	int level;

	level = snd_GetRecordLevel();
	return (level >= 0
		? methodReturnInteger(level)
		: primitiveFail());
}


/*	Get the default output device's volume level as a left/right pair of
	floats in the range 0-1.
 */

	/* SoundPlugin>>#primitiveSoundGetVolume */
EXPORT(sqInt)
primitiveSoundGetVolume(void)
{
	double left;
	sqInt leftOop;
	sqInt results;
	double right;
	sqInt rightOop;

	left = 0.0;
	right = 0.0;
	snd_Volume((&left), (&right));
	if (failed()) {
		return 0;
	}
	results = instantiateClassindexableSize(classArray(), 2);
	if (!results) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	
#if SPURVM
	leftOop = floatObjectOf(left);
	rightOop = floatObjectOf(right);
#else /* SPURVM */
	pushRemappableOop(results);
	leftOop = floatObjectOf(left);
		pushRemappableOop(leftOop);
	rightOop = floatObjectOf(right);
	leftOop = popRemappableOop();
	results = popRemappableOop();
#endif /* SPURVM */
	storePointerofObjectwithValue(0, results, leftOop);
	storePointerofObjectwithValue(1, results, rightOop);
	methodReturnValue(results);
	return 0;
}


/*	Insert a buffer's worth of sound samples into the currently playing 
	buffer. Used to make a sound start playing as quickly as possible. The 
	new sound is mixed with the previously buffered sampled. */
/*	Details: Unlike primitiveSoundPlaySamples, this primitive always starts 
	with the first sample the given sample buffer. Its third argument 
	specifies the number of samples past the estimated sound output buffer 
	position the inserted sound should start. If successful, it returns the 
	number of samples inserted. */
/*	N.B. At least on Windows and MacOS Cocoa circa late 2020 this is
	unsupported. snd_InsertSamplesFromLeadTime merely answers zero. */

	/* SoundPlugin>>#primitiveSoundInsertSamples:from:leadTime: */
EXPORT(sqInt)
primitiveSoundInsertSamples(void)
{
	short *buf;
	sqInt frameCount;
	sqInt framesPlayed;
	sqInt leadTime;

	if (!((isIntegerObject((frameCount = stackValue(2))))
		 && ((isWordsOrShorts(stackValue(1)))
		 && (isIntegerObject((leadTime = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	frameCount = integerValueOf(frameCount);
	buf = ((short *) (firstIndexableField(stackValue(1))));
	leadTime = integerValueOf(leadTime);
	if (failed()) {
		return null;
	}
	if ((((usqInt) frameCount)) > ((byteSizeOf(((sqInt)(sqIntptr_t)(buf) - BaseHeaderSize))) / ((sizeof(short)) * 2))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	framesPlayed = snd_InsertSamplesFromLeadTime(frameCount, buf, leadTime);
	if (framesPlayed >= 0) {
		methodReturnInteger(framesPlayed);
	}
	else {
		primitiveFail();
	}
	return 0;
}


/*	Output a buffer's worth of stereo sound samples. The frameCount is the
	number of 16-bit sample pairs.
	See e.g. platforms/iOS/plugins/SoundPlugin/sqSqueakSoundCoreAudio.m:
	#define SqueakFrameSize	4	// guaranteed (see class SoundPlayer)
	Of course there is no FrameSize in Squeak 5.x/6.x; sigh... */

	/* SoundPlugin>>#primitiveSoundPlaySamples:from:startingAt: */
EXPORT(sqInt)
primitiveSoundPlaySamples(void)
{
	short *buf;
	sqInt frameCount;
	sqInt framesPlayed;
	sqInt startIndex;

	if (!((isIntegerObject((frameCount = stackValue(2))))
		 && ((isWordsOrShorts(stackValue(1)))
		 && (isIntegerObject((startIndex = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	frameCount = integerValueOf(frameCount);
	buf = ((short *) (firstIndexableField(stackValue(1))));
	startIndex = integerValueOf(startIndex);
	if (failed()) {
		return null;
	}
	if (!((startIndex >= 1)
		 && (((startIndex + frameCount) - 1) <= ((byteSizeOf(((sqInt)(sqIntptr_t)(buf) - BaseHeaderSize))) / ((sizeof(short)) * 2))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	framesPlayed = snd_PlaySamplesFromAtLength(frameCount, buf, startIndex - 1);
	if (framesPlayed >= 0) {
		methodReturnInteger(framesPlayed);
	}
	else {
		primitiveFail();
	}
	return 0;
}


/*	Output a buffer's worth of silence. Returns the number of sample frames
	played. 
 */

	/* SoundPlugin>>#primitiveSoundPlaySilence */
EXPORT(sqInt)
primitiveSoundPlaySilence(void)
{
	sqInt framesPlayed;


	/* -1 if sound output not started */
	framesPlayed = snd_PlaySilence();
	if (framesPlayed >= 0) {
		methodReturnInteger(framesPlayed);
	}
	else {
		primitiveFail();
	}
	return 0;
}


/*	Record a buffer's worth of (mono?) 16-bit sound samples. */

	/* SoundPlugin>>#primitiveSoundRecordSamplesInto:startingAt: */
EXPORT(sqInt)
primitiveSoundRecordSamples(void)
{
	short *buf;
	sqInt bufSizeInBytes;
	sqInt byteOffset;
	sqInt samplesRecorded;
	sqInt startWordIndex;

	if (!((isWordsOrShorts(stackValue(1)))
		 && (isIntegerObject((startWordIndex = stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	buf = ((short *) (firstIndexableField(stackValue(1))));
	startWordIndex = integerValueOf(startWordIndex);
	if (failed()) {
		return null;
	}
	bufSizeInBytes = byteSizeOf(((sqInt)(sqIntptr_t)(buf) - BaseHeaderSize));
	byteOffset = (startWordIndex - 1) * 2;
	if (!((startWordIndex >= 1)
		 && (byteOffset < bufSizeInBytes))) {
		return primitiveFailFor(PrimErrBadIndex);
	}
	samplesRecorded = snd_RecordSamplesIntoAtLength((((char *) buf)) + byteOffset, 0, bufSizeInBytes - byteOffset);
	if (!(failed())) {
		methodReturnValue(positive32BitIntegerFor(samplesRecorded));
		return null;
	}
	return 0;
}


/*	Set the sound input recording level. */

	/* SoundPlugin>>#primitiveSoundSetLeftVolume:rightVolume: */
EXPORT(sqInt)
primitiveSoundSetLeftVolume(void)
{
	double aLeftVolume;
	double aRightVolume;

	if (!((isFloatObject(stackValue(1)))
		 && (isFloatObject(stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	aLeftVolume = stackFloatValue(1);
	aRightVolume = stackFloatValue(0);
	if (failed()) {
		return null;
	}
	snd_SetVolume(aLeftVolume, aRightVolume);
	if (!(failed())) {
		pop(2);
	}
	return null;
}


/*	Set the sound input recording level. */

	/* SoundPlugin>>#primitiveSoundSetRecordLevel: */
EXPORT(sqInt)
primitiveSoundSetRecordLevel(void)
{
	sqInt level;

	if (!(isIntegerObject((level = stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	level = integerValueOf(level);
	if (failed()) {
		return null;
	}
	snd_SetRecordLevel(level);
	if (!(failed())) {
		pop(1);
	}
	return null;
}


/*	Start the double-buffered sound output with the given buffer size, sample
	rate, and stereo flag.
 */

	/* SoundPlugin>>#primitiveSoundStartBufferSize:rate:stereo: */
EXPORT(sqInt)
primitiveSoundStart(void)
{
	sqInt bufFrames;
	sqInt samplesPerSec;
	sqInt stereoFlag;

	if (!((isIntegerObject((bufFrames = stackValue(2))))
		 && ((isIntegerObject((samplesPerSec = stackValue(1))))
		 && (isBooleanObject(stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	bufFrames = integerValueOf(bufFrames);
	samplesPerSec = integerValueOf(samplesPerSec);
	stereoFlag = booleanValueOf(stackValue(0));
	if (failed()) {
		return null;
	}
	success(snd_Start(bufFrames, samplesPerSec, stereoFlag, 0));
	if (!(failed())) {
		pop(3);
	}
	return null;
}


/*	Start recording sound with the given parameters. */

	/* SoundPlugin>>#primitiveSoundStartRecordingDesiredSampleRate:stereo:semaIndex: */
EXPORT(sqInt)
primitiveSoundStartRecording(void)
{
	sqInt desiredSamplesPerSec;
	sqInt semaIndex;
	sqInt stereoFlag;

	if (!((isIntegerObject((desiredSamplesPerSec = stackValue(2))))
		 && ((isBooleanObject(stackValue(1)))
		 && (isIntegerObject((semaIndex = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	desiredSamplesPerSec = integerValueOf(desiredSamplesPerSec);
	stereoFlag = booleanValueOf(stackValue(1));
	semaIndex = integerValueOf(semaIndex);
	if (failed()) {
		return null;
	}
	snd_StartRecording(desiredSamplesPerSec, stereoFlag, semaIndex);
	if (!(failed())) {
		pop(3);
	}
	return null;
}


/*	Start the double-buffered sound output with the given buffer size, sample
	rate, stereo flag, and semaphore index.
 */

	/* SoundPlugin>>#primitiveSoundStartBufferSize:rate:stereo:semaIndex: */
EXPORT(sqInt)
primitiveSoundStartWithSemaphore(void)
{
	sqInt bufFrames;
	sqInt samplesPerSec;
	sqInt semaIndex;
	sqInt stereoFlag;

	if (!((isIntegerObject((bufFrames = stackValue(3))))
		 && ((isIntegerObject((samplesPerSec = stackValue(2))))
		 && ((isBooleanObject(stackValue(1)))
		 && (isIntegerObject((semaIndex = stackValue(0)))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	bufFrames = integerValueOf(bufFrames);
	samplesPerSec = integerValueOf(samplesPerSec);
	stereoFlag = booleanValueOf(stackValue(1));
	semaIndex = integerValueOf(semaIndex);
	if (failed()) {
		return null;
	}
	success(snd_Start(bufFrames, samplesPerSec, stereoFlag, semaIndex));
	if (!(failed())) {
		pop(4);
	}
	return null;
}


/*	Stop double-buffered sound output. */

	/* SoundPlugin>>#primitiveSoundStop */
EXPORT(sqInt)
primitiveSoundStop(void)
{
	snd_Stop();
	return 0;
}


/*	Stop recording sound. */

	/* SoundPlugin>>#primitiveSoundStopRecording */
EXPORT(sqInt)
primitiveSoundStopRecording(void)
{
	snd_StopRecording();
	return 0;
}


/*	Answer if the OS/hardware supports echo-cancellation. */

	/* SoundPlugin>>#primitiveSoundSupportsAEC */
EXPORT(sqInt)
primitiveSoundSupportsAEC(void)
{
	methodReturnBool((snd_SupportsAEC()) != 0);
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
		booleanValueOf = interpreterProxy->booleanValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		classArray = interpreterProxy->classArray;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		floatObjectOf = interpreterProxy->floatObjectOf;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
		isBooleanObject = interpreterProxy->isBooleanObject;
#else
#if !defined(isBooleanObject)
		isBooleanObject = 0;
#endif
#endif
		isBytes = interpreterProxy->isBytes;
		isFloatObject = interpreterProxy->isFloatObject;
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 17)
		isWordsOrShorts = interpreterProxy->isWordsOrShorts;
#else
#if !defined(isWordsOrShorts)
		isWordsOrShorts = 0;
#endif
#endif
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		methodReturnBool = interpreterProxy->methodReturnBool;
		methodReturnFloat = interpreterProxy->methodReturnFloat;
		methodReturnInteger = interpreterProxy->methodReturnInteger;
		methodReturnReceiver = interpreterProxy->methodReturnReceiver;
		methodReturnString = interpreterProxy->methodReturnString;
		methodReturnValue = interpreterProxy->methodReturnValue;
		nilObject = interpreterProxy->nilObject;
		pop = interpreterProxy->pop;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		positive32BitValueOf = interpreterProxy->positive32BitValueOf;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		stackFloatValue = interpreterProxy->stackFloatValue;
		stackValue = interpreterProxy->stackValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* SoundPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return soundShutdown();
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "SoundPlugin";
void* SoundPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveGetDefaultSoundPlayer\000\377", (void*)primitiveGetDefaultSoundPlayer},
	{(void*)_m, "primitiveGetDefaultSoundRecorder\000\377", (void*)primitiveGetDefaultSoundRecorder},
	{(void*)_m, "primitiveGetNumberOfSoundPlayerDevices\000\377", (void*)primitiveGetNumberOfSoundPlayerDevices},
	{(void*)_m, "primitiveGetNumberOfSoundRecorderDevices\000\377", (void*)primitiveGetNumberOfSoundRecorderDevices},
	{(void*)_m, "primitiveGetSoundPlayerDeviceName\000\377", (void*)primitiveGetSoundPlayerDeviceName},
#if TerfVM
	{(void*)_m, "primitiveGetSoundPlayerDeviceUID\000\377", (void*)primitiveGetSoundPlayerDeviceUID},
#endif /* TerfVM */
	{(void*)_m, "primitiveGetSoundRecorderDeviceName\000\377", (void*)primitiveGetSoundRecorderDeviceName},
#if TerfVM
	{(void*)_m, "primitiveGetSoundRecorderDeviceUID\000\377", (void*)primitiveGetSoundRecorderDeviceUID},
#endif /* TerfVM */
	{(void*)_m, "primitiveSetDefaultSoundPlayer\000\000", (void*)primitiveSetDefaultSoundPlayer},
	{(void*)_m, "primitiveSetDefaultSoundRecorder\000\000", (void*)primitiveSetDefaultSoundRecorder},
	{(void*)_m, "primitiveSoundAvailableSpace\000\377", (void*)primitiveSoundAvailableSpace},
	{(void*)_m, "primitiveSoundEnableAEC\000\000", (void*)primitiveSoundEnableAEC},
	{(void*)_m, "primitiveSoundGetRecordingSampleRate\000\377", (void*)primitiveSoundGetRecordingSampleRate},
	{(void*)_m, "primitiveSoundGetRecordLevel\000\377", (void*)primitiveSoundGetRecordLevel},
	{(void*)_m, "primitiveSoundGetVolume\000\377", (void*)primitiveSoundGetVolume},
	{(void*)_m, "primitiveSoundInsertSamples\000\000", (void*)primitiveSoundInsertSamples},
	{(void*)_m, "primitiveSoundPlaySamples\000\000", (void*)primitiveSoundPlaySamples},
	{(void*)_m, "primitiveSoundPlaySilence\000\377", (void*)primitiveSoundPlaySilence},
	{(void*)_m, "primitiveSoundRecordSamples\000\000", (void*)primitiveSoundRecordSamples},
	{(void*)_m, "primitiveSoundSetLeftVolume\000\000", (void*)primitiveSoundSetLeftVolume},
	{(void*)_m, "primitiveSoundSetRecordLevel\000\000", (void*)primitiveSoundSetRecordLevel},
	{(void*)_m, "primitiveSoundStart\000\000", (void*)primitiveSoundStart},
	{(void*)_m, "primitiveSoundStartRecording\000\000", (void*)primitiveSoundStartRecording},
	{(void*)_m, "primitiveSoundStartWithSemaphore\000\000", (void*)primitiveSoundStartWithSemaphore},
	{(void*)_m, "primitiveSoundStop\000\377", (void*)primitiveSoundStop},
	{(void*)_m, "primitiveSoundStopRecording\000\377", (void*)primitiveSoundStopRecording},
	{(void*)_m, "primitiveSoundSupportsAEC\000\377", (void*)primitiveSoundSupportsAEC},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{(void*)_m, "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveSetDefaultSoundPlayerAccessorDepth = 0;
signed char primitiveSetDefaultSoundRecorderAccessorDepth = 0;
signed char primitiveSoundEnableAECAccessorDepth = 0;
signed char primitiveSoundInsertSamplesAccessorDepth = 0;
signed char primitiveSoundPlaySamplesAccessorDepth = 0;
signed char primitiveSoundRecordSamplesAccessorDepth = 0;
signed char primitiveSoundSetLeftVolumeAccessorDepth = 0;
signed char primitiveSoundSetRecordLevelAccessorDepth = 0;
signed char primitiveSoundStartAccessorDepth = 0;
signed char primitiveSoundStartRecordingAccessorDepth = 0;
signed char primitiveSoundStartWithSemaphoreAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
