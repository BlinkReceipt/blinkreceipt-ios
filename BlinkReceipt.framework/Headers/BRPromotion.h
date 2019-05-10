//
//  BRPromotion.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 12/13/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRSerializable.h"

typedef NSArray<NSNumber*>* BRPromotionQualification;

/**
 *  Represents a promotion identified on the receipt
 */
@interface BRPromotion : NSObject <BRSerializable>

///------------------
/// @name Properties
///------------------

/**
 *  Identifies which promotion qualified
 */
@property (strong, nonatomic, readonly) NSString *slug;

//For qualified promotions

/**
 *  The reward value for this promotion
 */
@property (nonatomic, readonly) float rewardValue;

/**
 *  The reward currency for this promotion
 */
@property (strong, nonatomic, readonly) NSString *rewardCurrency;

//For unqualified promotions

/**
 *  Error code for failure to qualify
 */
@property (nonatomic, readonly) NSInteger errorCode;

/**
 *  Error message for failure to qualify
 */
@property (strong, nonatomic, readonly) NSString *errorMessage;

/**
 *  If this promotion qualified, this property contains the indexes of the products in the `BRScanResults.products` array which caused this promotion to qualify
 */
@property (strong, nonatomic, readonly) NSArray<NSNumber*> *relatedProductIndexes;

/**
 *  If this promotion qualified, this property contains an array of each instance of qualification, and each instance is an array containing the indexes of the products in the `BRScanResults.products` array which caused this promotion to qualify
 */
@property (strong, nonatomic, readonly) NSArray<BRPromotionQualification> *qualifications;

@end
