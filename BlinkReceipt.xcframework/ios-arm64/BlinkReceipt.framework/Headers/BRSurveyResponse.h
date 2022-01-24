//
//  BRSurveyResponse.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 7/17/20.
//  Copyright © 2020 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Represents a user response to a survey question
 */
@interface BRSurveyResponse : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  If the survey question is multiple choice, this array contains the indexes of the answer(s) the user selected
 */
@property (strong, nonatomic) NSArray<NSNumber*> *answersSelected;

/**
 *  If the survey question is open ended, this is the text the user entered in response
 */
@property (strong, nonatomic) NSString *freeText;

@end

NS_ASSUME_NONNULL_END
