//
//  BRCameraViewController.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 9/8/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BRScanOptions.h"
#import "BRScanResults.h"

typedef NS_ENUM(NSUInteger, BRDistanceStatus) {
    BRDistanceStatusOK,
    BRDistanceStatusTooFar
};

typedef NS_ENUM(NSUInteger, BRWrongRetailerConfidence) {
    BRWrongRetailerConfidencePhone,
    BRWrongRetailerConfidencePhoneAndProducts
};

/**
 *  Base camera controller class. Subclass BRCameraViewController to build your own UI on top of the fullscreen camera view
 */
@interface BRCameraViewController : UIViewController


/**------------------*/
/** @name Properties */
/**------------------*/

/**
 *  Indicates the number of frames currently in the processing pipeline. You may want to consult this property to delay closing the view controller
 *  until all frames have finished
 */
@property (readonly, nonatomic) NSInteger numFramesProcessing;

/**
 *  Set this property in viewDidLoad of your subclass in order to scan only a certain region of the returned image from the camera. The values of the CGRect
 *  are all given from 0.0 to 1.0, indicating a fraction of the current view's dimensions. Default is (0.0, 0.0, 1.0, 1.0) which scans the whole screen.
 */
@property (nonatomic) CGRect scanningRegion;

/**
 *  Indicates whether the torch is on
 */
@property (readonly, nonatomic) BOOL isTorchOn;

/**
 *  Indicates whether scanning is paused
 */
@property (readonly, nonatomic) BOOL isPaused;



/**--------------------------*/
/** @name Base Class Methods */
/**--------------------------*/

/**
 *  Call this method to notify the camera controller that the user has attempted to snap a picture.
 *
 *  @param readyBlock This block will be invoked once the camera controller has obtained a suitable frame to display to the user as a preview, and also includes a flag indicating whether the frame is below the blurry threshold (isBlurry == YES means the frame was below the threshold is blurry)
 */
- (void)userSnappedPhotoOnReady:(void(^)(UIImage *frameImg, BOOL isBlurry))readyBlock;

/**
 *  Call this method to notify the camera controller that the user has indicated they have finished scanning.
 *  This will perform some cleanup and then call the didFinishScanning: method on the BRScanResultsDelegate instance that you have supplied
 */
- (void)userFinishedScan;

/**
 *  Call this method to notify the camera controller that the user has cancelled scanning.
 *  This will perform some cleanup and then call the didCancelScanning: method on the BRScanResultsDelegate instance that you have supplied
 */
- (void)userCancelledScan;

/**
 *  Call this method to notify the camera controller that the user has confirmed a particular frame. This will mark the frame internally as a user frame
 *  and after the scanning session it will be saved to disk if the storeUserFrames flag in BRScanOptions is set
 *
 *  @param frameImg The image the user has confirmed. Should be the same as the image passed to the readyBlock of userSnappedPhotoOnReady: above
 */
- (void)userConfirmedFrame:(UIImage*)frameImg;

/**
 *  Toggle the status of the torch
 *
 *  @param torchOn Whether to turn the torch on or off
 */
- (void)setTorch:(BOOL)torchOn;

/**
 *  Pause frame capture and scanning. Any frames that are already in the processing pipeline will continue to be scanned
 */
- (void)pauseScanning;


/**
 Resume frame capture and scanning.
 */
- (void)resumeScanning;


/**
 After receiving the "didDetectWrongRetailer:" callback, call this method to indicate that scanning should use the new retailer going forward

 @param retailerId The new retailer to use
 */
- (void)confirmCorrectRetailer:(WFRetailerId)retailerId;

/**-------------------------*/
/** @name Subclass Methods */
/**-------------------------*/

/**
 *  Override this method to be notified when a determination is made that the user's scanning distance is either too far or is acceptable (OK)
 *
 *  @param newStatus The newly detected distance status
 */
- (void)userDistanceChanged:(BRDistanceStatus)newStatus;


/**
 Override this method to receive statistics on each frame that is processed

 @param frameStats A dictionary with the following keys:
    contentWidth    : CGFloat indicating what percent (0-100) of the image the receipt appears in
 */
- (void)didGetFrameStats:(NSDictionary*)frameStats;


/**
 Override this method to be notified when the SDK detects that the receipt being scanned is from a different retailer than was specified

 @param correctRetailer The retailer the SDK believes the receipt to be from
 @param confidence Whether the new retailer is based only on a store phone match, or if we have also successfully parsed products using the new retailer
 */
- (void)didDetectWrongRetailer:(WFRetailerId)correctRetailer withConfidence:(BRWrongRetailerConfidence)confidence;


/**
 Override this method to receive frame by frame scan results (note: metadata only, does not include product results).
 Results are cumulative from all frames previously scanned.

 @param frameResults The scan results at this point in time
 */
- (void)didGetFrameResults:(BRScanResults*)frameResults;

@end
