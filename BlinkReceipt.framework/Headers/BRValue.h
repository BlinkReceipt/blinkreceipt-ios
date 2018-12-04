//
//  BRValue.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 2/4/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Parent class to hold a value and a confidence
 */
@interface BRValue : NSObject

/**
 Confidence between 0-100
 */
@property (nonatomic, readonly) float confidence;
@end

/**
 Child class for all string values
 */
@interface BRStringValue : BRValue
@property (nonatomic, readonly, strong) NSString *value;
@end

/**
 Child class for all float values
 */
@interface BRFloatValue : BRValue
@property (nonatomic, readonly) float value;

/**
 Rounded to exactly 2 decimal places for currency
 */
@property (strong, nonatomic, readonly) NSDecimalNumber *decimalValue;
@end

/**
 Child class for all int values
 */
@interface BRIntValue : BRValue
@property (nonatomic, readonly) NSInteger value;
@end
