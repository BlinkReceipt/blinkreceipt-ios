//
//  BRSurvey.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 7/16/20.
//  Copyright © 2020 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRSurveyQuestion.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Represents a survey consisting of a series of multiple choice or open ended questions
 */
@interface BRSurvey : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  Identifier for this survey
 */
@property (readonly, nonatomic, strong) NSString *slug;

/**
 *  Survey start date, or `nil` if no start date
 */
@property (readonly, nonatomic, strong, nullable) NSDate *startDate;

/**
 *  Survey end date, or `nil` if no end date
 */
@property (readonly, nonatomic, strong, nullable) NSDate *endDate;

/**
 *  Reward value for participating in survey
 */
@property (readonly, nonatomic) float rewardValue;

/**
 *  Array of questions contained in this survey
 */
@property (readonly, nonatomic, strong) NSArray<BRSurveyQuestion*> *questions;

@end

NS_ASSUME_NONNULL_END
