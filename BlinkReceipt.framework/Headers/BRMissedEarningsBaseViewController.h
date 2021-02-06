//
//  BRMissedEarningsBaseViewController.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 9/21/19.
//  Copyright © 2019 Windfall. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

///
typedef NS_ENUM(NSUInteger, BRMissedEarningsLookupResult) {
    BRMissedEarningsProductParticipates,
    BRMissedEarningsProductDoesNotParticipate,
    BRMissedEarningsUPCNotFound,
    BRMissedEarningsLookupFailed
};

@interface BRMissedEarningsBaseViewController : UIViewController

/**
 *  This property restricts the region in which barcode will be detected. The parametesr are specified as percentages of the view size. The default value is `(0.0, 0.0, 1.0, 1.0)`
 */
@property (nonatomic) CGRect scanningRegion;

/**
 *  Due to differences in barcode lengths, specifying the country code helps determine the correct barcode length the SDK should detect
 */
@property (nonatomic, strong) NSString *countryCode;

/**
 * Override this method to be notified when a barcode is detected. Supports 12 digit and 6 digit UPC's.
 */
- (void)didDetectBarcode:(NSString*)barcode;

/**
 * Perform server lookup of this UPC
 *
 * @param completion This callback is invoked when the lookup completes (or fails)
 *      * `BRMissedEarningsLookupResult lookupResult` - The status of the lookup indicating whether the supplied UPC participates in the program, does not participate, was not found, or if the lookup failed
 *      * `NSDictionary *productInfo` - If the UPC was found, this dictionary contains information about the product. The keys are: `productName`, `brand`, `image_url`, and `brand_participates`, which is a boolean indicating whether this product's brand is part of the program. This helps identify scenarios where some products in a brand participate in the program, but the provided UPC does not. Additionally a `message` key which can contain a custom message for a given product
 */
- (void)lookupUPC:(NSString*)upc withCompletion:(void(^)(BRMissedEarningsLookupResult lookupResult, NSDictionary *productInfo))completion;

/**
 *  Toggle the status of the torch
 *
 *  @param torchOn      Whether to turn the torch on or off
 */
- (void)setTorch:(BOOL)torchOn;

/**
 * When a barcode is found, the capture session is automatically paused. Invoke this method to restart the capture session afterwards.
 */
- (void)restartCaptureSession;

@end

NS_ASSUME_NONNULL_END
