//
//  BRScanOptions.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRProduct.h"

/**
 *  If retailer is known in advance, setting `BRScanOptions.retailerId` to one of these values can increase scanning accuracy.
 */
typedef NS_ENUM(NSUInteger, WFRetailerId) {
    WFRetailerUnknown = 0,  // Means retailer is not known
    WFRetailerAcme = 116,
    WFRetailerBJSWholesale = 100,
    WFRetailerCostco = 29,
    WFRetailerCVS = 103,
    WFRetailerDuaneReade = 101,
    WFRetailerFredMeyer = 108,
    WFRetailerHEB = 117,
    WFRetailerJewelOsco = 115,
    WFRetailerKroger = 111,
    WFRetailerMeijer = 112,
    WFRetailerMilitaryCommissary = 124,
    WFRetailerPublix = 118,
    WFRetailerSamsClub = 99,
    WFRetailerShaws = 113,
    WFRetailerStarMarket = 114,
    WFRetailerTarget = 21,
    WFRetailerWalgreens = 24,
    WFRetailerWalmart = 25,
    WFRetailerWinco = 110,
    WFRetailerShoprite = 120,
    WFRetailerWinnDixie = 122,
    WFRetailerWegmans = 126,
    WFRetailerWholeFoods = 131,
    WFRetailerHyVee = 125,
    WFRetailerSprouts = 127,
    WFRetailerAlbertsons = 102,
    WFRetailerSafeway = 119,
    WFRetailerGiant = 128,
    WFRetailerStopNShop = 121,
    WFRetailerHarrisTeeter = 123,
    WFRetailerFrys = 129,
    WFRetailerSmiths = 130,
    WFRetailerBakers = 137,
    WFRetailerOwens = 138,
    WFRetailerPayLess = 139,
    WFRetailerGerbes = 140,
    WFRetailerJayC = 141,
    WFRetailerRulerFoods = 142,
    WFRetailerQFC = 143,
    WFRetailerCityMarket = 144,
    WFRetailerFood4Less = 145,
    WFRetailerDillons = 146,
    WFRetailerRalphs = 147,
    WFRetailerKingSoopers = 148,
    WFRetailerWalmartQR = 149,
    WFRetailerFoodsCo = 150
};

/**
 *  Create an instance of this class to specify the scanning options for a session
 */
@interface BRScanOptions : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  If the retailer is known in advance pass in a value from the `WFRetailerId` enum
 */
@property (nonatomic) WFRetailerId retailerId;


/**
 *  Whether to return the raw OCR text. If this property is true, `-[BRScanResultsDelegate didOutputRawText:]` will be called
 *
 *  Default: NO
 */
@property (nonatomic) BOOL returnRawText;

/**
 *  Whether to write the user-confirmed frames to disk. If this property is true, after a scanning session `BRScanManager.userFramesFilepaths` will contain the local paths of the user frames. You are responsible for deleting these images from disk when you are done with them.
 *
 *  Default: NO
 */
@property (nonatomic) BOOL storeUserFrames;

/**
 *  Whether the client uses a Scandit camera independently of the BlinkReceipt SDK. If this is the case, BlinkReceipt will incorporate a fix to an inconsistent camera bug that occurs in this scenario.
 *
 *  Default: NO
 */
@property (nonatomic) BOOL clientUsesScanditCamera;


/**
 *  Whether to store up all the frames that the SDK parsed for inclusion in the debug email after the scan
 *
 *  Default: NO
 */
@property (nonatomic) BOOL debugMode;


/**
 *  The compression quality parameter to pass into `UIImageJPEGRepresentation` for saving user images to disk
 *
 *  Default: 0.9
 */
@property (nonatomic) float jpegCompressionQuality;


/**
 *  This controls when the "Move Closer" message appears. The threshold is a percentage expressed as an integer between 1 and 99. If edges are detected such that the width of the receipt divided by the width of the full image is below this threshold, the "too far" flag will be passed to the client.
 *
 *  Default: 80
 */
@property (nonatomic) NSInteger tooFarThreshold;


/**
 *  This controls how often edge detection is run on frames returned by the camera. Must be an even integer between 2 and 30. For example, setting this to 8 means edge detection will be run every 8th frame
 *
 *  Default: 6
 */
@property (nonatomic) NSInteger edgesEveryNthFrame;


/**
 *  Controls whether edge detection is used to make determinations of user's distance from the receipt
 *
 *  Default: NO
 */
@property (nonatomic) BOOL detectDistanceWithEdges;


/**
 *  The number of consecutive frames above the `tooFarThreshold` before we stop running edge detection
 *
 *  Default: 2
 */
@property (nonatomic) NSInteger numGoodFramesToStopEdges;

/**
 *  If `numGoodFramesToStopEdges` is greater than 0, this property allows edge detection to restart after a user confirms a frame
 *
 *  Default: NO
 */
@property (nonatomic) BOOL restartEdgesAfterUserConfirm;

/**
 *  Whether the SDK should continue edge detection after the first user snapped photo
 *
 *  Default: NO
 */
@property (nonatomic) BOOL enableEdgesAfterUserPhoto;

/**
 *  Whether the SDK should begin edge detection immediately at the start of the scan session (as opposed to establishing frame quality baselines before starting edge detection)
 *
 *  Default: NO
 */
@property (nonatomic) BOOL beginEdgesImmediately;

/**
 *  Whether the SDK should attempt to verify that the user is in fact scanning a receipt from the specified retailer. If this property is true and the SDK detects a different retailer than specified, `-[BRCameraViewController didDetectWrongRetailer:withConfidence:]` will be triggered, which allows the client to determine if scanning should continue with the new retailer
 *
 *  Default: NO
 */
@property (nonatomic) BOOL detectWrongRetailer;


/**
 *  If specified, the SDK will assume all receipts scanned are from a particular country.
 Format is ISO 2 character country code for the receipts which will be scanned (full list here: https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2#Officially_assigned_code_elements )
 *
 *  Default: nil
 */
@property (strong, nonatomic) NSString *countryCode;

/**
 *  Whether to enable logo detection
 *
 *  Default: YES
 */
@property (nonatomic) BOOL detectLogo;


/**
 *  Whether the client will control the torch manually (should only be used with custom `BRCameraViewController` subclass). When this is enabled, `-[BRCameraViewController didGetLightingCondition:]` will be invoked to notify the client of lighting changes
 *
 *  Default: NO
 */
@property (nonatomic) BOOL manualTorchControl;

/**
 *  If this property is enabled, the SDK will not perform any on-device frame processing
 *
 *  Default: NO
 */
@property (nonatomic) BOOL disableOnDeviceProcessing;

/**
 *  If this property is enabled, and the receipt is detected to be a duplicate, `BRScanResults.isDuplicate` will be set to true. Also checks for fraudulent receipts and sets the `BRScanResults.isFraudulent` property
 *
 *  Default: NO
 */
@property (nonatomic) BOOL detectDuplicates;

/**
 *  If this property is enabled, voided products will be returned with the `BRProduct.isVoided` property set to `YES`
 *
 *  Default: NO
 */
@property (nonatomic) BOOL returnVoidedProducts;

/**
 *  Whether to attempt to validate scan results against specified promotions
 *
 *  Default: NO
 */
@property (nonatomic) BOOL validatePromotions;

/**
 *  One or more promotion slugs to validate against
 */
@property (strong, nonatomic) NSArray *promotionSlugs;

/**
 *  If enabled, the stock camera controller's UI will adjust based on the user's text size preference from the Settings or Accessibility screens
 *
 *  Default: NO
 */
@property (nonatomic) BOOL enableDynamicTextSizing;

/**
 *  This property controls how much of the previous frame is visible in the stock controller once a user has touched to add an additional frame. Specified in pixels
 *
 *  Default: 72
 */
@property (nonatomic) NSInteger previousFrameOverlap;

/**
 *  If this property is enabled, subproducts will be returned in the `BRProduct.subProducts` array of the parent product
 *
 *  Default: NO
 */
@property (nonatomic) BOOL returnSubproducts;

/**
 *  If enabled, date chip will show whether the date is recognized after scan
 *
 *  Default: NO
 */
@property (nonatomic) BOOL enableDateChip;

/**
 *  If enabled, total chip will show whether the total is recognized after scan
 *
 *  Default: NO
 */
@property (nonatomic) BOOL enableTotalChip;

/**
 *  If enabled, merchant chip will show whether the merchant is recognized after scan
 *
 *  Default: NO
 */
@property (nonatomic) BOOL enableMerchantChip;


@end
