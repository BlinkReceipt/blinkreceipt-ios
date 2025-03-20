//
//  BRQualifiedProduct.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 3/17/25.
//  Copyright © 2025 Microblink. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRSerializable.h"

NS_ASSUME_NONNULL_BEGIN

@interface BRQualifiedProduct : NSObject<BRSerializable>

@property (nonatomic, readonly) NSInteger productIndex;
@property (strong, nonatomic, readonly) NSArray<NSString*> *productGroups;

@end

NS_ASSUME_NONNULL_END
