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
 *  The payment method (i.e. Cash, Credit, Debit, Gift Card, Check, etc), if any
 */
@property (nonatomic, readonly, strong) BRStringValue *method;

/**
 *  The card type (i.e. Visa, American Express, Mastercard, or Discover), if any
 */
@property (nonatomic, readonly, strong) BRStringValue *cardType;

/**
 *  The card issuer (i.e. Target, Walmart, etc), if any
 */
@property (nonatomic, readonly, strong) BRStringValue *cardIssuer;

/**
 *  The amount charged to this payment method
 */
@property (nonatomic, readonly, strong) BRFloatValue *amount;

@end
