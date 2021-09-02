//
//  BRCoupon.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 10/13/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRValue.h"
#import "BRSerializable.h"

///
typedef NS_ENUM(NSUInteger, BRCouponType) {
    BRCouponTypeUnknown,
    BRCouponTypeStore,
    BRCouponTypeMfgr
};

/**
 *  Describes one coupon or discount on a receipt
 */
@interface BRCoupon : NSObject <BRSerializable>

///------------------
/// @name Properties
///------------------

/**
 *  The type of coupon based on the above enum
 */
@property (nonatomic, readonly) BRCouponType couponType;

/**
 *  The amount of the coupon or discount
 */
@property (nonatomic, readonly, strong) BRFloatValue *couponAmount;

/**
 *  Coupon description
 */
@property (nonatomic, readonly, strong) BRStringValue *couponDesc;

/**
 *  Coupon SKU
 */
@property (nonatomic, readonly, strong) BRStringValue *couponSku;

/**
 *  The prefix found before the coupon description if any
 */
@property (nonatomic, readonly, strong) BRStringValue *couponDescPrefix;

/**
 *  The postfix found after the coupon description if any
 */
@property (nonatomic, readonly, strong) BRStringValue *couponDescPostfix;

/**
 *  The prefix found before the coupon SKU if any
 */
@property (nonatomic, readonly, strong) BRStringValue *couponSkuPrefix;

/**
 *  The postfix found after the coupon SKU if any
 */
@property (nonatomic, readonly, strong) BRStringValue *couponSkuPostfix;

/**
 *  If this coupon is related to a particular product, this property will be set to correspond to the index of related product in the `BRScanResults.products` array.
 *
 *  Default value: -1
 */
@property (nonatomic, readonly) NSInteger relatedProductIndex;

///---------------------
/// @name Class Methods
///---------------------

/**
 *  Convert a coupon type to a user-friendly string
 */
+ (NSString*)friendlyNameForCouponType:(BRCouponType)type;

@end
