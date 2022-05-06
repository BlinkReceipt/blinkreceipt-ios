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
@property (strong, nonatomic, readonly) BRFloatValue *totalPrice;

/**
 *  The total price before any savings were applied to this item (to compute the discount on this item, subtract totalPrice from fullPrice)
 */
@property (strong, nonatomic, readonly) BRFloatValue *fullPrice;


@property (strong, nonatomic, readonly) BRFloatValue *priceAfterCoupons;

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
 *  The prefix found before the product description if any
 */
@property (strong, nonatomic, readonly) BRStringValue *prodDescPrefix;

/**
 *  The postfix found after the product description if any
 */
@property (strong, nonatomic, readonly) BRStringValue *prodDescPostfix;

/**
 *  The prefix found before the product number if any
 */
@property (strong, nonatomic, readonly) BRStringValue *prodNumPrefix;

/**
 *  The postfix found after the product number if any
 */
@property (strong, nonatomic, readonly) BRStringValue *prodNumPostfix;

/**
 *  If this product is fuel, this will be the type of fuel (e.g. "Regular", "Unleaded", etc)
 */
@property (strong, nonatomic, readonly) NSString *fuelType;

/**
 *  Additional product fields
 */
@property (strong, nonatomic, readonly) NSDictionary *extendedFields;

/**
 *  The product reseller, if any
 */
@property (strong, nonatomic, readonly) NSString *seller;

/**
 *  The product condition, if any  (e.g. "New", "Used", etc)
 */
@property (strong, nonatomic, readonly) NSString *condition;

/**
 *  The product url, if any  (usually found in ereceipts)
 */
@property (strong, nonatomic, readonly) NSString *productUrl;

/**
 *  The currency for this product, if identified. It can be different from BRScanResults.currencyCode
 */
@property (strong, nonatomic, readonly) NSString *currencyCode;

/**
 *  The subscription frequency for this product, if identified (e.g. every week, every month, etc...)
 */
@property (strong, nonatomic, readonly) NSString *subscriptionFrequency;

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
 *  The product category (this is a legacy property - it is recommended to use `BRProduct.sector`, `BRProduct.department`, `BRProduct.majorCategory` and `BRProduct.subCategory` instead
 */
@property (strong, nonatomic, readonly) NSString *category;

/**
 * The product sector (highest level of taxonomy)
 */
@property (strong, nonatomic, readonly) NSString *sector;

/**
 * The product department
 */
@property (strong, nonatomic, readonly) NSString *department;

/**
 * The product major category
 */
@property (strong, nonatomic, readonly) NSString *majorCategory;

/**
 * The product sub category
 */
@property (strong, nonatomic, readonly) NSString *subCategory;

/**
 *  The product size
 */
@property (strong, nonatomic, readonly) NSString *size;

/**
 *  The product UPC
 */
@property (strong, nonatomic, readonly) NSString *upc;

/**
 * The product item type
 */
@property (strong, nonatomic, readonly) NSString *itemType;

/**
 * Zero or more attributes related to the product. Each attribute is a dictionary with a single key-value pair, representing the name of the attribute and its value
 */
@property (strong, nonatomic, readonly) NSArray<NSDictionary*> *attributes;

/**
 *  If this product is part of a different product's `possibleProducts` array, then this property indicates an estimate of how likely this particular possible product is to match the description of the parent `BRProduct`
 */
@property (nonatomic, readonly) float probability;

/**
 *  The product thumbnail URL (size may vary)
 */
@property (strong, nonatomic, readonly) NSString *imgUrl;

/**
 *  If product intelligence is unable to return an exact product match, it may return an array of possible products. Each of these will have only the above product intelligence properties populated.
 */
@property (strong, nonatomic, readonly) NSArray<BRProduct*> *possibleProducts;

/**
*  An array of sub products tied to the current product, if any. Generally only populated for restaurants
*/
@property (strong, nonatomic, readonly) NSArray<BRProduct*> *subProducts;

/**
 *  Whether the user added this product during the receipt correction flow
 */
@property (nonatomic, readonly) BOOL userAdded;

/**
 *  Whether the user modified this product during the receipt corretion flow
 */
@property (nonatomic, readonly) BOOL userModified;

/**
 *  If `BRScanOptions.filterSensitiveData` is enabled, then this flag will indicate whether the current product is from a sensitive category as determined by product intelligence
 */
@property (nonatomic, readonly) BOOL isSensitive;

/**
 * For custom user corrections flow, when a user modifies an existing product, call this method to update the product's properties.
 * Note: You should pass values for all the properties even if the user did not modify them
 *
 * @param brand     The brand, if any, of the modified product
 * @param upc         The upc, if any, of the modified product
 * @param productName The name, if any, of the modified product
 * @param imageUrl    The image URL, if any, of the modified product
 * @param totalPrice The total price of the modified product
 * @param quantity The quantity of the modified product
 */
- (void)userCorrectedBrand:(NSString*)brand
                       upc:(NSString*)upc
               productName:(NSString*)productName
                  imageUrl:(NSString*)imageUrl
                totalPrice:(float)totalPrice
                  quantity:(float)quantity;

@end
