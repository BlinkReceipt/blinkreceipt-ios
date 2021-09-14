//
//  BRSurveyQuestion.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 7/16/20.
//  Copyright © 2020 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRSurveyAnswer.h"
#import "BRSurveyResponse.h"

typedef NS_ENUM(NSUInteger, BRSurveyQuestionType) {
    BRSurveyQuestionTypeMultipleChoice,
    BRSurveyQuestionTypeOpenEnded
};

NS_ASSUME_NONNULL_BEGIN

/**
 *  Represents a survey question, which is either multiple choice or open-ended
 */
@interface BRSurveyQuestion : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  Survey question text
 */
@property (readonly, nonatomic, strong) NSString* text;

/**
 *  Survey question type
 */
@property (readonly, nonatomic) BRSurveyQuestionType type;

/**
 *  Array of multiple choice answers to this question, if the `type` is `BRSurveyQuestionTypeMultipleChoice`
 */
@property (readonly, nonatomic, strong) NSArray<BRSurveyAnswer*> *answers;

/**
 *  Indicates whether multiple answers can be selected, if the `type` is `BRSurveyQuestionTypeMultipleChoice`
 */
@property (readonly, nonatomic) BOOL multipleAnswers;

/**
 *  The user's response to this survey question, if the survey was completed
 */
@property (readonly, nonatomic, strong) BRSurveyResponse *userResponse;

///---------------
/// @name Methods
///---------------

/**
 *  When displaying the survey with a custom UI, call this method to indicate the user's answer to this question

 *  @param response      The user's response to this question
 */
- (void)addUserResponse:(BRSurveyResponse*)response;

/**
 *  When displaying the survey with a custom UI, after adding the user's response to the current question, call this method to get the next question index to display (since the flow may be dynamic based on the user's responses). A return value of `-1` indicates there are no further questions.
 */
- (NSInteger)getNextQuestionIndex;

@end

NS_ASSUME_NONNULL_END
