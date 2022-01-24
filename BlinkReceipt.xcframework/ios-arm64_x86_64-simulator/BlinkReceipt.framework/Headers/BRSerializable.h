//
//  BRSerializable.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 12/13/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#ifndef BRSerializable_h
#define BRSerializable_h

#import <Foundation/Foundation.h>

/**
 *  All BlinkReceipt results objects implement this protocol in order to provide an easy method for serializing results into JSON (or other formats). You can call `dictionaryForSerializing` on any results object or sub-object and get an `NSDictionary*` that is suitable for serialization (i.e. contains no custom classes)
 */
@protocol BRSerializable

///---------------
/// @name Methods
///---------------

/**
 *  Retrieves a dictionary suitable for JSON (or other) serialization
 */
- (NSDictionary*)dictionaryForSerializing;

+ (instancetype)objectFromDictionary:(NSDictionary*)dict;

@end

#endif /* BRSerializable_h */
