//
//  BRFrameAttributes.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 6/14/20.
//  Copyright © 2020 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///
@interface BRFrameAttributes : NSObject

/// Indicates whether this frame is blurry
@property (nonatomic, readonly) BOOL isBlurry;

/// Indicates whether this frame is believed to be an image of a receipt
@property (nonatomic, readonly) BOOL isReceipt;

/// Indicates whether this frame is believed to be a photo of a screen
@property (nonatomic, readonly) BOOL isScreen;

@end

NS_ASSUME_NONNULL_END
