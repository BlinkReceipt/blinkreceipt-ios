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
 *  This callback provides encrypted debugging information that can be used to help identify crashes. For example, if the client app uses Firebase Crashlytics, this can be passed along as follows:
 *
 *  `[[FIRCrashlytics crashlytics] log:debugInfo];`
 *
 *  @param debugInfo    The encrypted debugging information
 */
- (void)didOutputDebugInfo:(NSString*)debugInfo;

/**
 *  This callback provides debugging information as key value pairs. For example, if the client app uses Firebase Crashlytics, this can be passed as a custom attribute as follows:
 *
 *  `[[FIRCrashlytics crashlytics] setCustomValue:val forKey:key];`
 *
 *  @param key    Description of the type of debugging information
 *  @param val    The information itself
 */
- (void)didOutputDebugKey:(NSString*)key withValue:(id)val;

@end
