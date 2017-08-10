//
//  BRProduct.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2017 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Describes one product on a receipt
 */
@interface BRProduct : NSObject

/**------------------*/
/** @name Properties */
/**------------------*/

/**
 *  The product number (SKU, UPC, or other) found on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *productNumber;

/**
 *  The product description found on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *productDescription;

/**
 *  The product quantity found on the receipt, if any (can be # of items or an amount if units are weight)
 */
@property (nonatomic, readonly) float quantity;

/**
 *  The unit price (i.e. if the item costs $8/lb this would be 8.0)
 */
@property (nonatomic, readonly) float unitPrice;

/**
 *  The total price for this line item, taking into account quantities and weights
 */
@property (nonatomic, readonly) float totalPrice;

/**
 *  The unit of measure for this item (i.e. pounds, ounces, packs, etc)
 */
@property (strong, nonatomic, readonly) NSString *unitOfMeasure;


/**
 *  The total price before any savings were applied to this item (to compute the discount on this item, subtract totalPrice from fullPrice)
 */
@property (nonatomic, readonly) float fullPrice;

@end
