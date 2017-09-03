//
//  BRScanOptions.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRProduct.h"

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

/**------------------*/
/** @name Properties */
/**------------------*/

/**
 Pass in one of the retailer ID's enumerated in the WFRetailerID typedef above
 */
@property (nonatomic) WFRetailerId retailerId;


/**
 Whether to return the raw OCR text. If this property is true, the BRScanResultsDelegate method didOutputRawText: will be called
 Default: NO
 */
@property (nonatomic) BOOL returnRawText;

/**
 Whether to write the user-confirmed frames to disk. If this property is true, after a scanning session the userFramesFilepaths property of BRScanManager will be set
 Default: NO
 */
@property (nonatomic) BOOL storeUserFrames;

/**
 Whether the client uses a Scandit camera independently of the BlinkReceipt SDK. If this is the case, BlinkReceipt will incorporate a fix to an inconsistent
 camera bug that occurs in this scenario.
 Default: NO
 */
@property (nonatomic) BOOL clientUsesScanditCamera;


/**
 Whether to store up all the frames that the SDK parsed for inclusion in the debug email after the scan
 Default: NO
 */
@property (nonatomic) BOOL debugMode;


/**
 The compression quality parameter to pass into UIImageJPEGRepresentation for saving user images to disk
 Default: 0.9
 */
@property (nonatomic) float jpegCompressionQuality;


/**
 This controls when the "Move Closer" message appears. The threshold is a percentage expressed as an integer between 1 and 99. If edges are detected such that the width of the receipt divided by the width of the full image is below this threshold, the "too far" flag will be passed to the client.
 Default: 80
 */
@property (nonatomic) NSInteger tooFarThreshold;


/**
 This controls how often edge detection is run on frames returned by the camera. Must be an even integer between 2 and 30. For example, setting this to 8 means edge detection will be run every 8th frame 
 Default: 6
 */
@property (nonatomic) NSInteger edgesEveryNthFrame;


/**
 Controls whether edge detection is used to make determinations of user's distance from the receipt
 Default: NO
 */
@property (nonatomic) BOOL detectDistanceWithEdges;


/**
 The number of consecutive frames above the tooFarThreshold before we stop running edge detection
 Default: 2
 */
@property (nonatomic) NSInteger numGoodFramesToStopEdges;

/**
 Whether the SDK should attempt to verify that the user is in fact scanning a receipt from the specified retailer. If this property is true and the SDK detects a different retailer than specified, the didDetectWrongRetailer callback will be triggered, which allows the client to determine if scanning should continue with the new retailer
 Default: NO
 */
@property (nonatomic) BOOL detectWrongRetailer;


/**
 If specified, the SDK will assume all receipts scanned are from a particular country.
 Format is ISO 2 character country code for the receipts which will be scanned (full list here: https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2#Officially_assigned_code_elements )
 Default: nil
 */
@property (strong, nonatomic) NSString *countryCode;


@end
