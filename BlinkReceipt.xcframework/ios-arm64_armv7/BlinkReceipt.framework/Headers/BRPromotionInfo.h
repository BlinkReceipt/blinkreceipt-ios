//
//  BRPromotionInfo.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 2/5/20.
//  Copyright © 2020 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRSerializable.h"

NS_ASSUME_NONNULL_BEGIN

/**
*  Represents information about a promotion retrieved for the current user
*/
@interface BRPromotionInfo : NSObject <BRSerializable>

/**
*  The promotion slug from the PVP dashboard
*/
@property (strong, nonatomic, readonly) NSString *slug;

/**
*  Whether this promotion is targeted to this user or not
*/
@property (nonatomic, readonly) BOOL targeted;

@end

NS_ASSUME_NONNULL_END
