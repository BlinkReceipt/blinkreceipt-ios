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

typedef NS_ENUM(NSUInteger, WFErrorCodes) {
    WFErrorCodeFailToGrabImage
};

@protocol BRScanResultsDelegate <NSObject>

@optional

/**
 *  Indicates that the scanning session has ended
 *
 *  @param cameraViewController The subclass of BRCameraViewController to dismiss
 */
- (void)didFinishScanning:(UIViewController*)cameraViewController withScanResults:(BRScanResults*)scanResults;

/**
 *  Indicates that the scanning session has been cancelled
 *
 *  @param cameraViewController The subclass of BRCameraViewController to dismiss
 */
- (void)didCancelScanning:(UIViewController*)cameraViewController;

/**
 *  If the returnRawText property of BRScanOptions was set to YES, this callback will be invoked after each scanned frame with raw OCR results
 *
 *  @param rawText The raw OCR results
 */
- (void)didOutputRawText:(NSString*)rawText;


/**
 *  This callback indicates an error occurred during scanning
 *
 *  @param error The error that occurred during scanning
 */
- (void)scanningErrorOccurred:(NSError*)error;

@end
