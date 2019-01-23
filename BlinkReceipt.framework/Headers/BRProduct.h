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
@interface BRProduct : NSObject <BRSerializable>

///------------------
/// @name Properties
///------------------

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
 *  The total price paid for this line item, taking into account quantities, weights, and discounts
 */
@property (nonatomic, readonly) float totalPrice;


/**
 *  The total price before any savings were applied to this item (to compute the discount on this item, subtract totalPrice from fullPrice)
 */
@property (nonatomic, readonly) float fullPrice;

@property (nonatomic, readonly) float priceAfterCoupons;

/**
 *  An array of any additional lines connected to this product that were scanned (can be above or below). This array can be nil if no lines were found
 */
@property (strong, nonatomic, readonly) NSArray<BRProductAdditionalLine*> *additionalLines;

/**
 *  Indicates whether this is a voided product. Voided products will only be returned if `BRScanOptions.returnVoidedProducts` is set
 */
@property (nonatomic, readonly) BOOL isVoided;

/**
 *  For e-receipt orders, this indicates the shipping status of this product
 */
@property (strong, nonatomic, readonly) NSString *shippingStatus;

/**
 *  Additional product fields
 */
@property (strong, nonatomic, readonly) NSDictionary *extendedFields;

///---------------------------------------
/// @name Product Intelligence Properties
///---------------------------------------

/// These properties will only be set if a valid `prodIntelKey` is set on `[BRScanManager sharedManager]`

/**
 *  The full product name
 */
@property (strong, nonatomic, readonly) NSString *productName;

/**
 *  The product brand
 */
@property (strong, nonatomic, readonly) NSString *brand;

/**
 *  The product category
 */
@property (strong, nonatomic, readonly) NSString *category;

/**
 *  The product size
 */
@property (strong, nonatomic, readonly) NSString *size;

/**
 *  The product UPC
 */
@property (strong, nonatomic, readonly) NSString *upc;

/**
 *  The product thumbnail URL (size may vary)
 */
@property (strong, nonatomic, readonly) NSString *imgUrl;

@end
