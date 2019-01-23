//
//  BRPaymentMethod.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 2/4/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRValue.h"
#import "BRSerializable.h"

/**
 *  Described a payment method and the amount charged to that payment method
 */
@interface BRPaymentMethod : NSObject <BRSerializable>

///------------------
/// @name Properties
///------------------

/**
 *  The payment method type (i.e. Cash, Credit, American Express, etc)
 */
@property (nonatomic, readonly, strong) BRStringValue *type;

/**
 *  The amount charged to this payment method
 */
@property (nonatomic, readonly, strong) BRFloatValue *amount;

@end
