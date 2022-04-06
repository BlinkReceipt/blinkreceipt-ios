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
#import "BRFrameAttributes.h"

///
typedef NS_ENUM(NSUInteger, BRDistanceStatus) {
    BRDistanceStatusOK,
    BRDistanceStatusTooFar,
};

///
typedef NS_ENUM(NSUInteger, BRWrongRetailerConfidence) {
    BRWrongRetailerConfidencePhone,
    BRWrongRetailerConfidencePhoneAndProducts
};

///
typedef NS_ENUM(NSUInteger, BRLightingCondition) {
    BRLightingConditionTerrible,
    BRLightingConditionLow,
    BRLightingConditionGood
};

///
typedef NS_ENUM(NSUInteger, BRCameraType) {
    BRCameraUXStandard,
    BRCameraUXEnhanced
};

/**
 *  Base camera controller class. Subclass to build your own UI on top of the fullscreen camera view
 */
@interface BRCameraViewController : UIViewController


///------------------
/// @name Properties
///------------------

/**
 *  Set this property of your subclass in order to scan only a certain region of the returned image from the camera. The values of the `CGRect`
 *  are all given from 0.0 to 1.0, indicating a fraction of the current view's dimensions. Default is (0.0, 0.0, 1.0, 1.0) which scans the whole screen.
 *  It is recommended to set the scanning region equal to the area of the screen that is not covered by other UI elements, so that the frames being scanned are consistent with what the user appears to be snapping photos of
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

/**
 *  Indicates whether edge detection is running
 */
@property (readonly, nonatomic) BOOL isEdgeDetectionRunning;


/**
 *  Set this property to `YES` to prevent the parent view controller from starting and stopping the `AVCaptureSession` based on view lifecycle events.
 *  You will be responsible for manually calling `-[BRCameraViewController resumeScanning]` and `-[BRCameraViewController pauseScanning]` to manage the capture session
 */
@property (nonatomic) BOOL manualCaptureSession;



///--------------------------
/// @name Base Class Methods
///--------------------------

/**
 *  Call this method to notify the camera controller that the user has attempted to snap a picture.
 *
 *  @param readyBlock   This block will be invoked once the camera controller has obtained a suitable frame to display to the user as a preview. Be careful of retain cycles in this block!
 *
 *      * `UIImage *frameImg` - The frame to display as a preview
 *
 *      * `BRFrameAttributes *frameAttributes` - Various attributes about the current frame (blurriness, screen detection, etc see `BRFrameAttributes`)
 */
- (void)userSnappedPhotoOnReady:(void(^)(UIImage *frameImg, BRFrameAttributes *frameAttributes))readyBlock;

/**
 *  Call this method to notify the camera controller that the user has indicated they have finished scanning.
 *  This will perform some cleanup and then call `-[BRScanResultsDelegate didFinishScanning:withScanResults:]` on your scanning delegate. It is recommended that prior to or simultaneous with calling this method, you display some sort of loader until the callback is received
 */
- (void)userFinishedScan;



/**
 *  Call this method to invoke the same processing that happens at the end of the scan session.
 *
 *  @param callback     This callback is invoked as soon as it is possible to return preliminary results
 *                      The client should return `YES` or `NO` depending on whether the results are satisfactory to end the scanning session
 *
 *      * `BRScanResults *scanResults` - The scan results up to this point
 */
- (void)getPreliminaryResults:(BOOL(^)(BRScanResults *scanResults))callback;

/**
 *  Call this method to notify the camera controller that the user has cancelled scanning.
 *  This will perform some cleanup and then call `-[BRScanResultsDelegate didCancelScanning:]` on your scanning delegate
 */
- (void)userCancelledScan;

/**
 *  Call this method to notify the camera controller that the user has confirmed a particular frame. This will mark the frame internally as a user frame which allows it to be saved remotely after the scan session, and also saved to disk if `BRScanOptions.storeUserFrames` is set
 *
 *  @param frameImg     The image the user has confirmed. Should be the same as the image passed to the `readyBlock` of `userSnappedPhotoOnReady:` above
 */
- (void)userConfirmedFrame:(UIImage*)frameImg;

/**
 *  Toggle the status of the torch
 *
 *  @param torchOn      Whether to turn the torch on or off
 */
- (void)setTorch:(BOOL)torchOn;

/**
 *  Pause frame capture and scanning. Any frames that are already in the processing pipeline will continue to be scanned
 */
- (void)pauseScanning;


/**
 *  Resume frame capture and scanning.
 */
- (void)resumeScanning;


/**
 *  After receiving the `didDetectWrongRetailer:` callback, call this method to indicate that scanning should use the new retailer going forward
 *
 *  @param retailerId   The new retailer to use
 */
- (void)confirmCorrectRetailer:(WFRetailerId)retailerId;

///------------------------
/// @name Subclass Methods
///------------------------

/**
 *  Override this method to be notified when a determination is made that the user's scanning distance is either too far or is acceptable (OK)
 *
 *  @param newStatus    The newly detected distance status
 */
- (void)userDistanceChanged:(BRDistanceStatus)newStatus;


/**
 *  Override this method to receive statistics on each frame that is processed
 *
 *  @param frameStats   A dictionary with the following keys:
 *
 *      `contentWidth` - a float indicating what percent (0-100) of the image the receipt appears in
 *
 *      `edgesRect` - a `CGRect` wrapped in `NSNumber` indicating the location of edges found in percentages of image size
 *
 *      `isReceipt` - a `BOOL` wrapped in `NSNumber` indicating whether the current frame is believed to contain a receipt
 */
- (void)didGetFrameStats:(NSDictionary*)frameStats;


/**
 *  Override this method to be notified when the SDK detects that the receipt being scanned is from a different retailer than was specified
 *
 *  @param correctRetailer  The retailer the SDK believes the receipt to be from
 *  @param confidence       Whether the new retailer is based only on a store phone match, or if we have also successfully parsed products using the new retailer
 */
- (void)didDetectWrongRetailer:(WFRetailerId)correctRetailer withConfidence:(BRWrongRetailerConfidence)confidence;


/**
 *  Override this method to receive frame by frame scan results (note: metadata only, does not include product results).
 *  Results are cumulative from all frames previously scanned.
 *
 *  @param frameResults     The scan results at this point in time
 */
- (void)didGetFrameResults:(BRScanResults*)frameResults;


/**
 *  Override this method to receive frame by frame estimations about whether the user is scanning a valid receipt (estimation is cumulative based on all previous frames scanned to that point)
 *
 *  @param validReceipt         Whether the SDK believes that it is scanning a valid receipt at this point
 */
- (void)receiptValidityEstimate:(BOOL)validReceipt;


/**
 *  When `BRScanOptions.manualTorchControl` is enabled, this callback will indicate to the client VC if the SDK detects a new lighting condition.
 *  Note: Lighting is assumed to start in `BRLightingConditionTerrible`, so there will never be a callback with that passed as a parameter, rather we only upgrade the lighting to `BRLightingConditionLow` or `BRLightingConditionGood`
 *
 *  @param lightingCondition    The new lighting condition
 */
- (void)didGetLightingCondition:(BRLightingCondition)lightingCondition;


/**
 *  Override this method to receive a callback when one or both horizontal edges is detected on the current frame. Note: This does *not* guarantee that this frame will be scanned.
 *  To determine if a top/bottom edge was seen on any of the scanned frames, consult `BRScanResults.foundTopEdge` and `BRScanResults.foundBottomEdge`
 *
 *  @param topEdge      Whether a top edge was detected on this frame
 *  @param bottomEdge   Whether a bottom edge was detected on this frame
 */
- (void)didGetHorizontalEdges:(BOOL)topEdge andBottomEdge:(BOOL)bottomEdge;

@end
