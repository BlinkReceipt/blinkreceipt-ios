//
//  BRSurveyAnswer.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 7/16/20.
//  Copyright © 2020 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Represents a multiple choice answer to a survey question
 */
@interface BRSurveyAnswer : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  Answer text
 */
@property (readonly, nonatomic, strong) NSString *text;

@end

NS_ASSUME_NONNULL_END
