//
//  BRScanManager.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 7/18/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "BRScanOptions.h"
#import "BRScanResultsDelegate.h"
#import "BRCameraViewController.h"
#import "BRPromotionInfo.h"
#import "BRSurvey.h"

@class MFMailComposeViewController;

/**
 *  This is the main interface for initiating scanning sessions
 */
@interface BRScanManager : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  Your BlinkReceipt license key
 */
@property (strong, nonatomic, nonnull) NSString *licenseKey;

/**
 *  Google Places Web Service API Key (for more info see: https://developers.google.com/places/web-service/get-api-key)
 */
@property (strong, nonatomic, nullable) NSString *googlePlacesApiKey;

/**
 *  Yelp API Key (for more infos see: https://www.yelp.com/developers)
 */
@property (strong, nonatomic, nullable) NSString *yelpApiKey;

/**
 *  Your BlinkReceipt product intelligence key (if any)
 */
@property (strong, nonatomic, nullable) NSString *prodIntelKey;

/**
 *  A client-specified identifier for the current user
 */
@property (strong, nonatomic, nullable) NSString *clientUserId;

/**
 *  An array of `NSString` filepaths corresponding to the user images, if any, which were confirmed by the user during the scanning session.
 */
@property (strong, nonatomic, nullable) NSArray<NSString*> *userFramesFilepaths;

/**
 *  If users should be able to correct historical receipts, this controls how long the receipt data will be stored locally to enable editing
 *
 *  Default: 0 (indicates receipt data will not be stored locally)
 */
@property (nonatomic) NSInteger daysToStoreReceiptData;

/**
*  Indicates whether the current device is capable of processing video frames
*/
@property (readonly, nonatomic) BOOL deviceCanProcessVideo;

///---------------------
/// @name Class Methods
///---------------------

/**
 *  Always access this singleton instance
 *
 *  @return The singleton instance
 */
+(nonnull instancetype) sharedManager;

///---------------
/// @name Methods
///---------------

/**
 *  Initiates a static camera scanning experience (in which the user appears to be snapping static photos)
 *
 *  @param viewController The parent view controller from which to display the camera controller modally
 *  @param cameraType       User can choose to use standard (old) or enhanced (latest) camera UI
 *  @param scanOptions    An instance of `BRScanOptions` specifying options for this scanning session
 *  @param delegate       An instance conforming to `BRScanResultsDelegate`
 */
- (void)startStaticCameraFromController:(nonnull UIViewController*)viewController
                             cameraType:(BRCameraType)cameraType
                            scanOptions:(nullable BRScanOptions*)scanOptions
                           withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;

/**
 *  Initiates a scanning session using your own subclass of `BRCameraViewController` which is presented as modal from the supplied `UIViewController`
 *
 *  @param customController Your custom subclass of `BRCameraViewController`
 *  @param viewController   The parent view controller from which to display the camera controller modally
 *  @param scanOptions      An instance of `BRScanOptions` specifying options for this scanning session
 *  @param delegate         An instance conforming to `BRScanResultsDelegate`
 */
- (void)startCustomCamera:(nonnull BRCameraViewController*)customController
           fromController:(nonnull UIViewController*)viewController
              scanOptions:(nullable BRScanOptions*)scanOptions
             withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;

/**
 *  Initiates a scanning session using your own subclass of `BRCameraViewController` which is pushed from the supplied `UINavigationController`
 *
 *  @param customController Your custom subclass of `BRCameraViewController`
 *  @param navCon   The navigation controller from which to push the camera controller
 *  @param scanOptions      An instance of `BRScanOptions` specifying options for this scanning session
 *  @param delegate         An instance conforming to `BRScanResultsDelegate`
 */
- (void)pushCustomCamera:(nonnull BRCameraViewController*)customController
       fromNavController:(nonnull UINavigationController*)navCon
             scanOptions:(nullable BRScanOptions*)scanOptions
            withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;

/**
 *  Creates a new `MFMailComposeViewController` populated with debug information about the most recent scan. Caller is responsible for setting the mailComposeDelegate and presenting/dismissing the view controller.
 *
 *  Note: If this method is invoked on the simulator or a device with no email supported, it will output the message body to the console and return `nil`.
 *
 *  @return The controller to display
 */
- (nonnull MFMailComposeViewController*)createMailControllerWithDebugInfo;

/**
 *  For purchase validation, use these properties to indicate the date a user activated a specific promotion

 *  @param activationDate      The date on which the user activated this promotion
 *  @param promotionSlug       The promotion slug as set up in the web PVP interface
 */
- (void)setActivationDate:(nonnull NSDate*)activationDate forPromotion:(nonnull NSString*)promotionSlug;

/**
 *  Begin the receipt correction flow for a receipt stored on disk
 *
 *  @param blinkReceiptId      The receipt id of a receipt scanned within `daysToStoreReceiptData` days
 *  @param vc                  The view controller from which to show this modal
 *  @param countryCode         Current country (this helps with barcode scanning)
 *  @param customFont          Pass a non-null `UIFont` to style all of the elements in this flow
 *  @param completion          This callback is invoked when the correction flow ends
 *
 *      * `BRScanResults *scanResults` - Updated scan results object containing any changes the user made to the products (including adding new products) as well as an updated `qualifiedPromotions` array containing the results of the purchase validation call made after the user's corrections
 *
 *      * `NSError *error` - If the correction flow failed for any reason (such as being unable to find the passed receipt id record on disk) this parameter will be non-null
 */
- (void)startReceiptCorrection:(nonnull NSString*)blinkReceiptId
            fromViewController:(nonnull UIViewController*)vc
               withCountryCode:(nullable NSString*)countryCode
               withCustomFont:(nullable UIFont*)customFont
                withCompletion:(nullable void(^)(BRScanResults* _Nullable, NSError* _Nullable))completion;

/**
 * Retrieve resullts from disk or remotely for a specific receipt for custom user corrections flow
 *
 * @param blinkReceiptId    The receipt id to load from disk
 * @param completion    This callback is invoked once the SDK has attempted to retrieve results for this receipt
 *      * `BRScanResults *results` - The scan results associated with this `blinkReceiptId`
 *
 *      * `NSArray<UIImage*>* images` - The images associated with this `blinkReceiptId`
 */
- (void)getResultsForReceiptCorrection:(nonnull NSString*)blinkReceiptId
                        withCompletion:(nonnull void(^)(BRScanResults* _Nullable results, NSArray<UIImage*> * _Nonnull images))completion;


/**
 * After custom user correction flow, call this method to validate the new results against promotions
 *
 * @param scanResults   The results object that was obtained from `getResultsForReceiptCorrection:`
 * @param countryCode The country code to use for product intelligence on the updated results (default is @"US")
 * @param completion    This callback is invoked once validation has been performed
 *      * `BRScanResults *scanResults` - Updated scan results object containing any changes the user made to the products (including adding new products) as well as an updated `qualifiedPromotions` array containing the results of the purchase validation call made after the user's corrections
 *
 *      * `NSError *error` - If any error occurred during validation this will be non-null
 */
- (void)submitUpdatedResultsForValidation:(BRScanResults* _Nonnull)scanResults
                          withCountryCode:(nullable NSString*)countryCode
                           withCompletion:(nullable void(^)(BRScanResults* _Nonnull, NSError* _Nullable))completion;


/**
 * Retrieves targeted and general promotions for current user
 *
 * @param completion    This callback is invoked once promotions have been retrieved
 *      * `NSArray<BRPromotionInfo*>* promos` - An array of promotion info objects for the current user
 */
- (void)getPromotionsWithCompletion:(nonnull void(^)(NSArray<BRPromotionInfo*> * _Nullable promos))completion;

/**
 * Retrieves surveys for current user
 *
 * @param completion    This callback is invoked once surveys have been retrieved
 *      * `NSArray<BRSurvey*>* promos` - An array of survey objects for the current user
 */
- (void)getSurveysWithCompletion:(nonnull void(^)(NSArray<BRSurvey*> * _Nullable surveys))completion;

/**
 * Displays a given survey using the prepackaged flow
 *
 * @param survey            The survey to display
 * @param viewController    The view controller from which to display the survey
 * @param completion        This callback is invoked after the user has completed or cancelled the survey
 *      * `BOOL cancelled` - whether the user cancelled the survey or not
 */
- (void)startSurvey:(nonnull BRSurvey*)survey
 fromViewController:(nonnull UIViewController*)viewController
     withCompletion:(nullable void(^)(BOOL userCancelled))completion;

/**
 * When displaying a survey using a custom UI, call this method after the user has completed the survey to post the results
 *
 * @param survey    This is the completed `BRSurvey` object containing the user's responses
 */
- (void)submitSurveyResults:(nonnull BRSurvey*)survey;

@end
