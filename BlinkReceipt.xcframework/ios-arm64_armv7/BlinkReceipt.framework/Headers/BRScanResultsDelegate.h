//
//  BRScanResultsDelegate.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRProduct.h"
#import "BRScanResults.h"

///
typedef NS_ENUM(NSUInteger, BRErrorCodes) {
    BRErrorInvalidLicenseKey,
    BRErrorFailToGrabImage,
    BRErrorFailToWriteToDisk,
    BRErrorCameraPermission
};

/**
 *  Implement this protocol to receive callbacks from a scanning session
 */
@protocol BRScanResultsDelegate <NSObject>

///---------------
/// @name Methods
///---------------

@optional

/**
 *  Indicates that the scanning session has ended
 *
 *  @param cameraViewController     The subclass of `BRCameraViewController` to dismiss
 *  @param scanResults              The results of the scanning session
 */
- (void)didFinishScanning:(UIViewController*)cameraViewController withScanResults:(BRScanResults*)scanResults;

/**
 *  Indicates that the scanning session has been cancelled
 *
 *  @param cameraViewController     The subclass of `BRCameraViewController` to dismiss
 */
- (void)didCancelScanning:(UIViewController*)cameraViewController;

/**
 *  If `BRScanOptions.returnRawText` was enabled, this callback will be invoked after each scanned frame with raw OCR results
 *
 *  @param rawText      The raw OCR results
 */
- (void)didOutputRawText:(NSString*)rawText;


/**
 *  This callback indicates an error occurred during scanning
 *
 *  @param error        The error that occurred during scanning
 */
- (void)scanningErrorOccurred:(NSError*)error;


/**
 *  This callback provides encrypted debugging information that can be used to help identify crashes. For example, if the client app uses Crashlytics, this can be passed along as follows:
 *
 *  `CLSLog(@"%@", debugInfo);`
 *
 *  @param debugInfo    The encrypted debugging information
 */
- (void)didOutputDebugInfo:(NSString*)debugInfo;

@end
