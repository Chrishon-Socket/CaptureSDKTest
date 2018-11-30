/**
    @file SktCaptureProperty.h
    @brief define the properties used in Capture

    @date 1/29/17
    @copyright © 2017 Socket Mobile, Inc.

*/

#ifndef SktCaptureProperty_h
#define SktCaptureProperty_h

#import "SktCapturePropertyIds.h"

/**
 @brief device type class
 */
typedef NS_ENUM (NSInteger, SKTCaptureDeviceClass) {
    /** the device belongs to the device class */
    SKTCaptureDeviceTypeClassDevice,
    /** the device belongs to the device manager class */
    SKTCaptureDeviceTypeClassDeviceManager
};

/**
 @brief Capture Device Interface type

 */
typedef NS_ENUM (NSInteger, SKTCaptureDeviceInterfaceType) {
    /** interface not specified */
    SKTCaptureDeviceInterfaceTypeNone = 0,
    /** interface Secure Digital */
    SKTCaptureDeviceInterfaceTypeSD = 1,
    /** interface Compact Flash */
    SKTCaptureDeviceInterfaceTypeCF = 2,
    /** interface Bluetooth */
    SKTCaptureDeviceInterfaceTypeBluetooth = 3,
    /** interface Serial */
    SKTCaptureDeviceInterfaceTypeSerial = 4,
    /** interface BLE */
    SKTCaptureDeviceInterfaceTypeBle = 5
};

/**

 @brief Capture Device product type

 */
typedef NS_ENUM (NSInteger, SKTCaptureDeviceProductId) {
    /** no product type speficied */
    SKTCaptureDeviceProductIdNone,
    /** product of the 7 Series */
    SKTCaptureDeviceProductId7Series,
    /** product of the 7x Series */
    SKTCaptureDeviceProductId7xSeries,
    /** product of the 9 Series */
    SKTCaptureDeviceProductId9Series,
    /** product of the 7xi Series */
    SKTCaptureDeviceProductId7xiSeries,
    /** product of SoftScan type */
    SKTCaptureDeviceProductIdSoftScan,
    /** product of 8ci Series */
    SKTCaptureDeviceProductId8ciSeries,
    /** product of 8qi Series */
    SKTCaptureDeviceProductId8qiSeries,
    /** product of D700 Series */
    SKTCaptureDeviceProductIdD700Series,
    /** product of D730 Series */
    SKTCaptureDeviceProductIdD730Series,
    /** product of the D750 Series */
    SKTCaptureDeviceProductIdD750Series,
    /** product of the D600 Series */
    SKTCaptureDeviceProductIdD600Series,
    /** product unknown */
    SKTCaptureDeviceProductIdUnknown
};

/**
 @brief Identifier for the Device Managers
 */
typedef NS_ENUM (NSInteger, SKTCaptureDeviceManagerId) {
    /** no device manager - regular device */
    SKTCaptureDeviceManagerIdNone,
    /** BLE device manager */
    SKTCaptureDeviceManagerIdBle,
    /** unknown device manager, does Capture need to be updated? */
    SKTCaptureDeviceManagerIdUnknown
};

/**

 @brief the device type is a combination of product type and interface

 */
typedef NS_ENUM (NSInteger, SKTCaptureDeviceType) {
    /** unknown device type */
    SKTCaptureDeviceTypeNone =
    SKTCaptureDeviceInterfaceTypeNone<<16 | SKTCaptureDeviceProductIdNone,
    /** Scanner 7 device type */
    SKTCaptureDeviceTypeScanner7 =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductId7Series,
    /** Scanner 7x device type */
    SKTCaptureDeviceTypeScanner7x =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductId7xSeries,
    /** Scanner 7xi device type */
    SKTCaptureDeviceTypeScanner7xi =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductId7xiSeries,
    /** Scanner 9 device type */
    SKTCaptureDeviceTypeScanner9 =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductId9Series,
    /** SoftScan device type */
    SKTCaptureDeviceTypeSoftScan =
    SKTCaptureDeviceInterfaceTypeNone<<16 | SKTCaptureDeviceProductIdSoftScan,
    /** Scanner 8ci device type */
    SKTCaptureDeviceTypeScanner8ci =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductId8ciSeries,
    /** Scanner 8qi device type */
    SKTCaptureDeviceTypeScanner8qi =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductId8qiSeries,
    /** Scanner D700 device type */
    SKTCaptureDeviceTypeScannerD700 =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductIdD700Series,
    /** Scanner D730 device type */
    SKTCaptureDeviceTypeScannerD730 =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductIdD730Series,
    /** Scanner D750 device type */
    SKTCaptureDeviceTypeScannerD750 =
    SKTCaptureDeviceInterfaceTypeBluetooth<<16 | SKTCaptureDeviceProductIdD750Series,
    /** Scanner D600 device type */
    SKTCaptureDeviceTypeScannerD600 = SKTCaptureDeviceTypeClassDevice<<24 |
    SKTCaptureDeviceInterfaceTypeBle<<16 | SKTCaptureDeviceProductIdD600Series,

    // device Manager
    /** BLE Device Manager type */
    SKTCaptureDeviceManagerTypeBle = SKTCaptureDeviceTypeClassDeviceManager<<24 |
    SKTCaptureDeviceInterfaceTypeBle<<16 | SKTCaptureDeviceManagerIdBle,

};

/**

 @brief Data Confirmation mode defines how the decoded data should be confirmed.

 */
typedef NS_ENUM (NSInteger, SKTCaptureDataConfirmation)
{
    /** use the device configuration (Local Confirmation or App) */
    SKTCaptureDataConfirmationModeOff,
    /** the device confirms the decoded data locally */
    SKTCaptureDataConfirmationModeDevice,
    /** Capture confirms the decoded data as it receives them and there is one app */
    SKTCaptureDataConfirmationModeCapture,
    /** the Application confirms the decoded data as it receives them */
    SKTCaptureDataConfirmationModeApp
};

/**

 @brief Device Data Acknowledgment mode
 */
typedef NS_ENUM (NSInteger, SKTCaptureDeviceDataAcknowledgment)
{
    /** the device won't locally acknowledge decoded data */
    SKTCaptureDeviceDataAcknowledgmentOff,
    /** the device will locally acknowledge decoded data */
    SKTCaptureDeviceDataAcknowledgmentOn,
};

/**

 @brief define the device security mode
 */
typedef NS_ENUM (NSInteger, SKTCaptureSecurityMode )
{
    /** no security */
    SKTCaptureSecurityModeNone,
    /** authentication only */
    SKTCaptureSecurityModeAuthentication,
    /** authentication and encryption */
    SKTCaptureSecurityModeAuthenticationEncryption,
};

/**

 @brief Trigger parameter

 */
typedef NS_ENUM (NSInteger, SKTCaptureTrigger )
{
    /** start a scan */
    SKTCaptureTriggerStart=1,
    /** stop a scan */
    SKTCaptureTriggerStop,
    /** enable the trigger */
    SKTCaptureTriggerEnable,
    /** disable the trigger */
    SKTCaptureTriggerDisable,
    /** start a scan in continuous mode (SoftScan scanner only, ESKT_NOTSUPPORTED returned when used with other scanner) */
    SKTCaptureTriggerContinuousScan,
};

/**

 @brief Delete Pairing Parameter

 */
typedef NS_ENUM (NSInteger, SKTCaptureDeletePairing )
{
    /** delete only the current pairing information */
    SKTCaptureDeletePairingCurrent=0,
    /** delete all the pairing information */
    SKTCaptureDeletePairingAll=1,
};

/**

 @brief action when the device successful decode data

 */
typedef NS_ENUM (NSInteger, SKTCaptureSoundActionType)
{
    /** good read from the host */
    SKTCaptureSoundActionTypeGoodScan,
    /** good read from the device */
    SKTCaptureSoundActionTypeGoodScanLocal,
    /** bad read from the host */
    SKTCaptureSoundActionTypeBadScan,
    /** bad read from the device */
    SKTCaptureSoundActionTypeBadScanLocal,
};

/**

 @brief sound configuration frequency

 */
typedef NS_ENUM (NSInteger, SKTCaptureSoundFrequency)
{
    /** no frequency sound */
    SKTCaptureSoundFrequencyNone=0,
    /** low frequency sound */
    SKTCaptureSoundFrequencyLow,
    /** medium frequency sound */
    SKTCaptureSoundFrequencyMedium,
    /** high frequency sound */
    SKTCaptureSoundFrequencyHigh,
    /** not a frequency sound value */
    SKTCaptureSoundFrequencyLast
};

/**

 @brief Rumble configuration for a specific action Type

 */
typedef NS_ENUM (NSInteger, SKTCaptureRumbleActionType)
{
    /** Vibrate when the host is ack'ing positively the decoded data */
    SKTCaptureRumbleActionTypeGoodScan,
    /** Vibrate when the device is ack'ing positively the decoded data */
    SKTCaptureRumbleActionTypeGoodScanLocal,
    /** Vibrate when the host is ack'ing negatively the decoded data */
    SKTCaptureRumbleActionTypeBadScan,
    /** Vibrate when the device ack'ing negatively the decoded data */
    SKTCaptureRumbleActionTypeBadScanLocal
};


/**


 @brief configure the local decode action when the device has a good read

 */
typedef NS_OPTIONS (NSInteger, SKTCaptureLocalDecodeAction)
{
    /** no decode action when the device reads correctly */
    SKTCaptureLocalDecodeActionNone=0,
    /** the device beeps when it reads correctly */
    SKTCaptureLocalDecodeActionBeep=1,
    /** the device LED flashes when it reads correctly */
    SKTCaptureLocalDecodeActionFlash=2,
    /** the device vibrates when it reads correctly */
    SKTCaptureLocalDecodeActionRumble=4
};

/**

 @brief Device LED configuration when confirming a read

 */
typedef NS_ENUM (NSInteger, SKTCaptureDataConfirmationLed)
{
    /** Device LED do nothing when confirming a read */
    SKTCaptureDataConfirmationLedNone=0,
    /** Device LED flashes in green when confirming a read */
    SKTCaptureDataConfirmationLedGreen=1,
    /** Device LED flashes in red when confirming a read */
    SKTCaptureDataConfirmationLedRed=2
};

/**

 @brief Device beep configuration when confirming a read

 */
typedef NS_ENUM (NSInteger, SKTCaptureDataConfirmationBeep)
{
    /** Device makes no beep when confirming a read */
    SKTCaptureDataConfirmationBeepNone=0,
    /** Device makes a good beep when confirming a read */
    SKTCaptureDataConfirmationBeepGood=1,
    /** Device makes a bad beep when confirming a read */
    SKTCaptureDataConfirmationBeepBad=2
};

/**


 @brief Device rumble configuration when confirming a read

 */
typedef NS_ENUM (NSInteger, SKTCaptureDataConfirmationRumble)
{
    /** no rumble when confirming a read */
    SKTCaptureDataConfirmationRumbleNone=0,
    /** good rumble when confirming a read */
    SKTCaptureDataConfirmationRumbleGood=1,
    /** bad rumble when confirming a read */
    SKTCaptureDataConfirmationRumbleBad=2
};

/**


 @brief SoftScan flash setting

 */
typedef NS_ENUM (NSInteger, SKTCaptureFlash)
{
    /**  turn the flash off */
    SKTCaptureFlashOff=0,
    /** turn the flash on */
    SKTCaptureFlashOn=1
};

/**


 @brief status of the SoftScan scanner. Sofscan is a barcode scanner using the
 device camera.

 */
typedef NS_ENUM (NSInteger, SKTCaptureSoftScan)
{
    /** the SoftScan feature is enabled */
    SKTCaptureSoftScanEnable=0,
    /** the SoftScan feature is disabled */
    SKTCaptureSoftScanDisable=1,
    /** make the SoftScan feature not supported (Set Property only) */
    SKTCaptureSoftScanNotSupported=2,
    /** make the SoftScan feature supported (Set property only) */
    SKTCaptureSoftScanSupported=3
};

/**
    KVC key for the SoftScan Overlay definition. The context should be
 the application UIViewController from which the SoftScan viewfinder should be
 attached.
 */
extern NSString* _Nonnull SKTCaptureSoftScanContext;

/**
 KVC key for the Layout ID. This is not used in iOS, it is ignored if set.
 */
extern NSString* _Nonnull SKTCaptureSoftScanLayoutId;

/**
 KVC key for the viewfinder ID. This is not used in iOS, it is ignored if set.
 */
extern NSString* _Nonnull SKTCaptureSoftScanViewFinderId;
/**
 KVC key for the SoftScan Flash Button ID. This is not used in iOS, it is ignored if set.
 */
extern NSString* _Nonnull SKTCaptureSoftScanFlashButtonId;

/**
 KVC text to display on the Cancel button in the SoftScan overlay
 if this key value is missing the English version is displayed by default
 */
extern NSString* _Nonnull SKTCaptureSoftScanCancelButton;
/**
 KVC for if the dictionary for SoftScan overlay doesn't have this
 key, the flash button won't be displayed in the overlay
 */
extern NSString* _Nonnull SKTCaptureSoftScanFlashButton;// coma-separated text: Flash,ON,OFF
/**
 KVC key for the text that gives some direction to the user on how to scan with SoftScan.
 */
extern NSString* _Nonnull SKTCaptureSoftScanDirectionText;
/**
 KVC key for the Background Color
 */
extern NSString* _Nonnull SKTCaptureSoftScanBackgroundColor;//"rgb() or rgba()
/**
 KVC key  for the SoftScan viewfinder text color
 */
extern NSString* _Nonnull SKTCaptureSoftScanTextColor;//"rgb() or rgba()
/**
 KVC key for selecting which camera (front or back) SoftScan should use
 */
extern NSString* _Nonnull SKTCaptureSoftScanCamera; // "front" "back"

/**
 @brief identify the device button for which the button event is received
 */
typedef NS_OPTIONS(NSInteger, SKTCaptureButtonsState)
{
    /** the left button has its state changed */
    SKTCaptureButtonsStateLeft=0x01,
    /** the right button has its state changed */
    SKTCaptureButtonsStateRight=0x02,
    /** the middle button has its state changed */
    SKTCaptureButtonsStateMiddle=0x04,
    /** the power button has its state changed */
    SKTCaptureButtonsStatePower=0x08,
    /** the ring detach state has changed (Series 9 only) */
    SKTCaptureButtonsStateRingDetach=0x10
};


/**
 @brief define the power state
 */
typedef NS_ENUM(NSInteger, SKTCapturePowerState)
{
    /** the power state is unknown */
    SKTCapturePowerStateUnknown=0x00,
    /** the power comes from battery */
    SKTCapturePowerStateOnBattery=0x01,
    /** the power comes from cradle */
    SKTCapturePowerStateOnCradle=0x02,
    /** the power comes from AC */
    SKTCapturePowerStateOnAc=0x04
};

/**

 @brief define the type of profile

 */
typedef NS_ENUM(NSInteger, SKTCaptureProfileSelect)
{
    /** the profile has no type */
    SKTCaptureProfileSelectNone=0,
    /** the profile is Serial Port Profile */
    SKTCaptureProfileSelectSpp=1,
    /** the profile is Keyboard emulation HID */
    SKTCaptureProfileSelectHid=2
};

/**

 @brief define the role of the device

*/
typedef NS_ENUM(NSInteger, SKTCaptureProfileConfig)
{
    /** do nothing when the profile is active */
    SKTCaptureProfileConfigNone=0,
    /** accepts incoming connection when the profile is active */
    SKTCaptureProfileConfigAcceptor=1,
    /** initiate a connection when the profile is active */
    SKTCaptureProfileConfigInitiator=2
};

/**

 @brief parameter for the disconnect property (set only)

 */
typedef NS_ENUM(NSInteger, SKTCaptureDisconnect)
{
    /** disconnect and then start the selected profile */
    SKTCaptureDisconnectStartProfile=0,
    /** disconnect and disable the radio (low power) */
    SKTCaptureDisconnectDisableRadio=1,
};

/**

 @brief notification configuration. This configuration is a bitmask

 */
typedef NS_OPTIONS(NSInteger, SKTCaptureNotifications)
{
    /** disable all notifications */
    SKTCaptureNotificationsNone=0,
    /** enable scan button press notifications */
    SKTCaptureNotificationsScanButtonPress=1<<0,
    /** enable scan button release notifications */
    SKTCaptureNotificationsScanButtonRelease=1<<1,
    /** enable power button release notifications */
    SKTCaptureNotificationsPowerButtonPress=1<<2,
    /** enable power button release notifications */
    SKTCaptureNotificationsPowerButtonRelease=1<<3,
    /** enable power state change notifications */
    SKTCaptureNotificationsPowerState=1<<4,
    /** enable battery level change notifications */
    SKTCaptureNotificationsBatteryLevelChange=1<<5
};

/**

 @brief start up role when in SPP configuration mode

 */
typedef NS_ENUM(NSInteger, SKTCaptureStartUpRole)
{
    /** the SPP Role will always be Acceptor */
    SKTCaptureStartUpRoleSPPAcceptor=0,
    /** the SPP Role will always be what was the last SPP Role config */
    SKTCaptureStartUpRoleSPPLastRole=1
};

/**

 @brief connect beep configuration

 */
typedef NS_ENUM(NSInteger, SKTCaptureConnectBeepConfig)
{
    /** don't beep when a connection is established */
    SKTCaptureConnectBeepConfigNoBeep=0,
    /** Beep when a connection is established */
    SKTCaptureConnectBeepConfigBeep=1
};

/**

 @brief define the data format

 */
typedef NS_ENUM(NSInteger, SKTCaptureDataFormat)
{
    /** data format without protocol fields */
    SKTCaptureDataFormatRaw=0,
    /** data format respecting the protocol format */
    SKTCaptureDataFormatPacket=1
};

/**

 @brief identify the timer for which the value are defined

 */
typedef NS_ENUM(NSInteger, SKTCaptureTimer)
{
    /** Trigger lock selected */
    SKTCaptureTimerTriggerAutoLockTimeout=1,
    /** Disconnected state timeout */
    SKTCaptureTimerPowerOffDisconnected=2,
    /** Connected state timeout */
    SKTCaptureTimerPowerOffConnected=4
};

/**

 @brief gives the reason for the connection to occur

 */
typedef NS_ENUM(NSInteger, SKTCaptureConnectReason)
{
    /** unknown reason */
    SKTCaptureConnectReasonUnknown=0,
    /** the device has connected because it powers on */
    SKTCaptureConnectReasonPowerOn=1,
    /** the device has connected because it scans a connect barcode */
    SKTCaptureConnectReasonBarcode=2,
    /** the device has connected because the user press the power button or the trigger button */
    SKTCaptureConnectReasonUserAction=3,
    /** the device has connected because the host has changed */
    SKTCaptureConnectReasonHostChange=4,
    /** the device has connected because it is back in range */
    SKTCaptureConnectReasonRetry=5,
};

/**

 @brief stand configuration

 */
typedef NS_ENUM(NSInteger, SKTCaptureStandConfig) {
    /** the device is always in trigger mode */
    SKTCaptureStandConfigMobileMode=0,
    /** the device is always in presentation mode */
    SKTCaptureStandConfigKioskMode=1,
    /** the device is in presentation mode when resting on stand, trigger mode otherwise */
    SKTCaptureStandConfigDetectMode=2,
    /** the device stays in presentation mode until trigger is pressed, goes back in presentation when resting on stand */
    SKTCaptureStandConfigAutoMode=3,
};

/**

 @brief type of the property parameter

 */
typedef NS_ENUM(NSInteger, SKTCapturePropertyType) {
    /** the property does not have parameter */
    SKTCapturePropertyTypeNone,
    /** the parameter is not applicable for the property */
    SKTCapturePropertyTypeNotApplicable,
    /** the property has a byte as parameter */
    SKTCapturePropertyTypeByte,
    /** the property has an unisgned long integer as parameter */
    SKTCapturePropertyTypeUlong,
    /** the property has a byte array as parameter */
    SKTCapturePropertyTypeArray,
    /** the property has a length variable string as parameter */
    SKTCapturePropertyTypeString,
    /** the property has a version structure as parameter */
    SKTCapturePropertyTypeVersion,
    /** the property has a Data Source structure as parameter */
    SKTCapturePropertyTypeDataSource,
    /** the property has an enumeration structure as parameter */
    SKTCapturePropertyTypeEnum,
    /** the property has an object as parameter */
    SKTCapturePropertyTypeObject,
    /** this is not a parameter property type but it gives the number of enums */
    SKTCapturePropertyTypeLastType,
};

/**
 @class SKTCaptureProperty

 @brief define a Capture Property composed by a Property ID, a Property Type and
 an eventual property parameter of the specified type.

 */
@interface SKTCaptureProperty : NSObject

/**
 @brief get or set the property ID
 */
@property SKTCapturePropertyID ID;

/**
 @brief get or set the type of the property parameter
 */
@property SKTCapturePropertyType Type;

/**
 @brief property array of byte parameter
 */
@property (nullable, nonatomic, strong) NSData* ArrayValue;

/**
 @brief property string parameter
 */
@property (nullable, nonatomic, strong) NSString* StringValue;

/**
 @brief property byte value parameter
 */
@property int8_t ByteValue;

/**
 @brief property unsigned long integer parameter
 */
@property unsigned long ULongValue;

/**
 @brief property version parameter
 */
@property (nullable, nonatomic, strong) SKTCaptureVersion* Version;

/**
 @brief property data source parameter
 */
@property (nullable, nonatomic, strong) SKTCaptureDataSource* DataSource;

/**
 @brief property user context
 */
@property (nullable) void *Context;

/**
 @brief property pointer to object parameter
 */
@property (nullable, retain) NSObject *Object;

/**
 @brief initialize the property object
 */
-(instancetype _Nonnull ) init;

@end

#endif /* SktCaptureProperty_h */
