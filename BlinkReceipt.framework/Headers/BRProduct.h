//
//  BRProduct.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2017 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BRProductAdditionalLine.h"

#import "BRValue.h"

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
@property (strong, nonatomic, readonly) BRStringValue *productNumber;

/**
 *  The product description found on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *productDescription;

/**
 *  The product quantity found on the receipt, if any (can be # of items or an amount if units are weight)
 */
@property (strong, nonatomic, readonly) BRFloatValue *quantity;

/**
 *  The unit price (i.e. if the item costs $8/lb this would be 8.0)
 */
@property (strong, nonatomic, readonly) BRFloatValue *unitPrice;

/**
 *  The unit of measure for this item (i.e. pounds, ounces, packs, etc)
 */
@property (strong, nonatomic, readonly) BRStringValue *unitOfMeasure;

/**
 *  The total price for this line item, taking into account quantities and weights
 */
@property (nonatomic, readonly) float totalPrice;


/**
 *  The total price before any savings were applied to this item (to compute the discount on this item, subtract totalPrice from fullPrice)
 */
@property (nonatomic, readonly) float fullPrice;


/**
    An array of any additional lines connected to this product that were scanned (can be above or below). This array can be nil if no lines were found
 */
@property (strong, nonatomic, readonly) NSArray<BRProductAdditionalLine*> *additionalLines;

@end
