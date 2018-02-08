//
//  BRProductAdditionalLine.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 1/29/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRValue.h"

@interface BRProductAdditionalLine : NSObject


/**
 The type of this additional line. For example "Full Price", "Price Cut", "Quantity", etc.
 */
@property (nonatomic, readonly, strong) BRStringValue *type;


/**
 The text of this additional line
 */
@property (nonatomic, readonly, strong) BRStringValue *text;


/**
 The line number of this additional line
 */
@property (nonatomic, readonly) NSInteger lineNumber;

@end
