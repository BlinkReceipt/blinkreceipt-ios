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

@class MFMailComposeViewController;

/**
 *  This is the main interface for initiating scanning sessions
 */
@interface BRScanManager : NSObject

/**------------------*/
/** @name Properties */
/**------------------*/

/**
 *  The license key you were assigned for use with BlinkReceipt
 */
@property (strong, nonatomic, nonnull) NSString *licenseKey;

/**
 *  Scandit App Key (for more info see: https://www.scandit.com/)
 */
@property (strong, nonatomic, nullable) NSString *scanditAppKey;

/**
 *  Google Places Web Service API Key (for more info see: https://developers.google.com/places/web-service/get-api-key)
 */
@property (strong, nonatomic, nullable) NSString *googlePlacesApiKey;

/**
 *  Yelp API Key (for more infos see: https://www.yelp.com/developers)
 */
@property (strong, nonatomic, nullable) NSString *yelpApiKey;

/**
 *  An array of NSString filepaths corresponding to the user images, if any, which were confirmed by the user during the scanning session.
 *  Only applies to static camera UX
 */
@property (strong, nonatomic, nullable) NSArray<NSString*> *userFramesFilepaths;



/**------------------*/
/** @name Methods    */
/**------------------*/

/**
 *  Always access the singleton instance of BRScanManager using this class method
 *
 *  @return The singleton instance
 */
+(nonnull instancetype) sharedManager;


/**
 *  Initiates a static camera scanning experience (in which the user appears to be snapping static photos)
 *
 *  @param viewController The parent view controller from which to display the camera controller modally
 *  @param scanOptions    An instance of BRScanOptions specifying options for this scanning session
 *  @param delegate       An instance conforming to BRScanResultsDelegate
 */
- (void)startStaticCameraFromController:(nonnull UIViewController*)viewController
                            scanOptions:(nullable BRScanOptions*)scanOptions
                           withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;


/**
 *  Initiates a live camera scanning experience (in which the user simply hovers over the receipt image and character overlays are drawn to provide feedback)
 *
 *  @param viewController The parent view controller from which to display the camera controller modally
 *  @param scanOptions    An instance of BRScanOptions specifying options for this scanning session
 *  @param delegate       An instance conforming to BRScanResultsDelegate
 */
- (void)startLiveCameraFromController:(nonnull UIViewController*)viewController
                            scanOptions:(nullable BRScanOptions*)scanOptions
                           withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;


/**
 *  Initiates a scanning session using your own subclass of BRCameraViewController
 *
 *  @param customController Your custom subclass of BRCameraViewController
 *  @param viewController   The parent view controller from which to display the camera controller modally
 *  @param scanOptions      An instance of BRScanOptions specifying options for this scanning session
 *  @param delegate         An instance conforming to BRScanResultsDelegate
 */
- (void)startCustomCamera:(nonnull BRCameraViewController*)customController
           fromController:(nonnull UIViewController*)viewController
              scanOptions:(nullable BRScanOptions*)scanOptions
             withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;


/**
 Initiates a scanning session using QR code to grab remote image and scan it

 @param qrCodeText      The value of the QR code already scanned
 @param scanOptions     An instance of BRScanOptions specifying options for this scanning session
 @param delegate        An instance conforming to BRScanResultsDelegate
 
 Notes: If there is an error retrieving the remote image for this QR code, scanningErrorOccurred: will be invoked on the delegate with error code WFErrorCodeFailToGrabImage
 */
- (void)scanFromQRCode:(nonnull NSString*)qrCodeText
           scanOptions:(nonnull BRScanOptions*)scanOptions
          withDelegate:(nonnull NSObject<BRScanResultsDelegate>*)delegate;

/**
 Creates a new MFMailComposeViewController populated with debug information about the most recent scan. Caller is responsible for setting the mailComposeDelegate and presenting/dismissing the view controller.
 
 Note: If this method is invoked on the simulator or a device with no email supported, it will output the message body to the console and return nil.

 @return The controller to display
 */
- (nonnull MFMailComposeViewController*)createMailControllerWithDebugInfo;

@end
