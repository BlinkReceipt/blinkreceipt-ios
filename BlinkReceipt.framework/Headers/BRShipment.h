//
//  BRShipment.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 6/8/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRProduct.h"

@interface BRShipment : NSObject

@property (strong, nonatomic) NSString *status;
@property (strong, nonatomic) NSArray<BRProduct*> *products;

@end
