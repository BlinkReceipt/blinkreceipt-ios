//
//  BRShipment.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 6/8/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRProduct.h"
#import "BRSerializable.h"

/**
 *  Represents one shipment in an Amazon order
 */
@interface BRShipment : NSObject <BRSerializable>

/**
 *  The status of this shipment. For example "Arriving Tomorrow", "Delivered", "Refunded", etc.
 */
@property (strong, nonatomic, readonly) NSString *status;

/**
 *  The products contained in this shipment
 */
@property (strong, nonatomic, readonly) NSArray<BRProduct*> *products;

@end
