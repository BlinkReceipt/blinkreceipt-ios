//
//  BRCoupon.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 10/13/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, BRCouponType) {
    BRCouponTypeUnknown,
    BRCouponTypeStore,
    BRCouponTypeMfgr
};

/**
 *  Describes one coupon or discount on a receipt
 */
@interface BRCoupon : NSObject

/**
 *  The type of coupon based on the above enum
 */
@property (nonatomic, readonly) BRCouponType couponType;

/**
 *  The amount of the coupon or discount
 */
@property (nonatomic, readonly) float couponAmount;

/**
 *  Coupon description
 */
@property (nonatomic, strong, readonly) NSString *couponDesc;


/**
 *  Coupon SKU
 */
@property (nonatomic, strong, readonly) NSString *couponSku;

/**
 *  Convert a coupon type to a user-friendly string
 */
+ (NSString*)friendlyNameForCouponType:(BRCouponType)type;

@end
