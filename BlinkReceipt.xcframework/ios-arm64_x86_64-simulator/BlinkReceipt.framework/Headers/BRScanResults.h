//
//  BRScanResults.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "BRScanOptions.h"
#import "BRProduct.h"
#import "BRCoupon.h"
#import "BRPaymentMethod.h"
#import "BRPromotion.h"
#import "BRShipment.h"
#import "BRValue.h"
#import "BRSerializable.h"
#import "BRSurvey.h"

/**
 *  Represents a single method of identifying the merchant on the receipt
 */
typedef NS_ENUM(NSUInteger, BRMerchantSource) {
    BRMerchantSourcePhone = 1,
    BRMerchantSourceStoreId,
    BRMerchantSourceTaxId,
    BRMerchantSourceAddress,
    
    /// Text on receipt was matched against a list of known retailers
    BRMerchantSourceKnownList,
    
    /// Text on receipt was matched to a retailer based on external name lookups
    BRMerchantSourceNameLookup,
    BRMerchantSourceLogo,
    
    /// Text on receipt matched common layout characteristics of merchant's receipts
    BRMerchantSourceLayoutAnalysis
};

/**
 *  This class holds the scan results for a particular scanning session
 */
@interface BRScanResults : NSObject <BRSerializable>

///------------------
/// @name Properties
///------------------

/**
 *  For future auto-detect retailer functionality
 */
@property (nonatomic, readonly) WFRetailerId retailerId;


/**
 *  Unique ID for this receipt which allows BlinkReceipt to correspond scan data to the correct receipt image stored by client
 */
@property (strong, nonatomic, readonly) NSString *blinkReceiptId;

/**
 *  An array of `BRProduct` objects representing the products that were detected on the receipt, if any
 *  Some e-receipts may return `shipments` with products instead of products list directly.
 */
@property (strong, nonatomic, readonly) NSArray<BRProduct*> *products;

/**
 *  An array of `BRCoupon` objects representing the coupons that were detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSArray<BRCoupon*> *coupons;


/**
 *  The total detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRFloatValue *total;

/**
 *  The subtotal detected on the receipt, if any
 */
@property (nonatomic, readonly) BRFloatValue *subtotal;

/**
 *  The tax detected on the receipt, if any
 */
@property (nonatomic, readonly) BRFloatValue *taxes;

/**
 *  The tip detected on the receipt, if any
 */
@property (nonatomic, readonly) BRFloatValue *tip;

/**
 *  The purchase date found on the receipt formatted as MM/dd/yyyy, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *receiptDate;

/**
 *  The purchase time found on the receipt formatted as HH:mm, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *receiptTime;

/**
 *  The barcode detected on the receipt, if any.
 *  Currently we recognize Code 39, Code 128, and ITF formats
 */
@property (strong, nonatomic, readonly) NSString *barcode;

/**
 *  The store number detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *storeNumber;

/**
 *  The store name detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *merchantName;

/**
 *  If there is client-specific version of a particular merchant, it will be passed back in this property
 */
@property (strong, nonatomic, readonly) BRStringValue *clientMerchantName;

/**
 *  An array of `NSNumber` objects wrapping `BRMerchantSource` values indicating which merchant detection method(s) succeeded in identifying the current merchant.
 *  This will be `nil` if no merchant was detected (i.e. `merchantName == nil`)
 */
@property (strong, nonatomic, readonly) NSArray<NSNumber*> *merchantSources;

/**
 *  When no merchant is detected using standard methods, the parser will occasionally return a best guess for the merchant based on receipt heuristics.
 */
@property (strong, nonatomic, readonly) NSString *merchantGuess;

/**
 *  The mall name in which the retailer is located, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *mallName;

/**
 *  The store street address detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *storeAddress;

/**
 *  The store city detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *storeCity;

/**
 *  The store state detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *storeState;

/**
 *  The store zipcode detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *storeZip;

/**
 *  The store phone number detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *storePhone;


/**
 *  The cashier ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *cashierId;

/**
 *  The transaction ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *transactionId;

/**
 *  Some receipts contain a longer transaction number in addition to the standard one
 */
@property (strong, nonatomic, readonly) BRStringValue *longTransactionId;

/**
 *  The register ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *registerId;


/**
 *  An array of `BRPaymentMethod` objects representing all payment methods found on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSArray<BRPaymentMethod*> *paymentMethods;

/**
 *  The last 4 digits of the credit card used, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *last4CC;

/**
 *  The tax ID of the retailer, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *taxId;

/**
 *  The retail channel for this receipt, if any
*/
@property (strong, nonatomic, readonly) BRStringValue *channel;

/**
 * The unique identifier associated with the payment processor’s terminal
 */
@property (strong, nonatomic, readonly) BRStringValue *paymentTerminalId;

/**
 * The unique identifier associated with the payment processor’s transaction
 */
@property (strong, nonatomic, readonly) BRStringValue *paymentTransactionId;

/**
*  Represents the type of purchase
*/
@property (strong, nonatomic, readonly) NSString *purchaseType;

/**
 *  Whether there is an indication of a loyalty program found on the receipt
*/
@property (nonatomic, readonly) BOOL loyaltyProgram;

/**
 *  Whether the purchase was made by an Instacart shopper
*/
@property (nonatomic, readonly) BOOL isInstacartShopper;

/**
 *  An average confidence (between 0 and 100) for the OCR performed on this receipt
 */
@property (nonatomic, readonly) float ocrConfidence;

/**
 *  Indicates whether any server lookups were still pending at the time results were returned to the client
 */
@property (nonatomic, readonly) BOOL serverLookupsCompleted;

/**
 *  Indicates whether a top edge was found on any frame that was scanned in this session
 */
@property (nonatomic, readonly) BOOL foundTopEdge;

/**
 *  Indicates whether a bottom edge was found on any frame that was scanned in this session
 */
@property (nonatomic, readonly) BOOL foundBottomEdge;

/**
 *  Indicates whether the subtotal matches the sum of the products and coupons
 */
@property (nonatomic, readonly) BOOL subtotalMatches;

/**
 * The currency for this receipt, if identified
 */
@property (strong, nonatomic, readonly) NSString *currencyCode;

/**
 *  Indicates how many products were still awaiting product intelligence results when the scan session ended
 */
@property (nonatomic, readonly) NSInteger productsPendingLookup;

/**
 *  Indicate whether the receipt is a duplicate (depends on `BRScanOptions.detectDuplicates` being enabled)
 */
@property (nonatomic, readonly) BOOL isDuplicate;

/**
 *  Indicate whether the receipt is believed to be fraudulent (depends on `BRScanOptions.detectDuplicates` being enabled)
 */
@property (nonatomic, readonly) BOOL isFraudulent;

/**
 *  If `isDuplicate` is true, this property contains the Blink Receipt ID(s) of the duplicate receipts
 */
@property (strong, nonatomic, readonly) NSArray<NSString*> *duplicateBlinkReceiptIds;

/**
 *  If promotion validation is enabled, this will contain all the promotions that were validated
 */
@property (strong, nonatomic, readonly) NSArray<BRPromotion*> *qualifiedPromotions;

/**
 *  If promotion validation is enabled, this will contain all the promotions that were NOT validated
 */
@property (strong, nonatomic, readonly) NSArray<BRPromotion*> *unqualifiedPromotions;

/**
*  If promotion validation is enabled, this will contain all the surveys that were validated
*/
@property (strong, nonatomic, readonly) NSArray<BRSurvey*> *qualifiedSurveys;

/**
 *  Additional receipt fields
 */
@property (strong, nonatomic, readonly) NSDictionary *extendedFields;

/**
 *  For an Amazon or e-receipt order, this is the order number
 */
@property (strong, nonatomic, readonly) NSString *ereceiptOrderNumber;

/**
 *  For an e-receipt order, this is the order status
 */
@property (strong, nonatomic, readonly) NSString *ereceiptOrderStatus;

/**
 *  For an Amazon or e-receipt order, this is the raw HTML that was parsed
 */
@property (strong, nonatomic, readonly) NSString *ereceiptRawHTML;

/**
 *  The name of the email provider from which this e-receipt was obtained
 */
@property (strong, nonatomic, readonly) NSString *ereceiptEmailProvider;

/**
 * The sender address for this e-receipt
 */
@property (strong, nonatomic, readonly) NSString *ereceiptMerchantEmail;

/**
 * The subject of the e-receipt email
 */
@property (strong, nonatomic, readonly) NSString *ereceiptEmailSubject;

/**
 *  For e-receipt orders, if aggregation is turned on, this property will contain the scan results objects from each component email for a given order. However, please note that for emails related to the same order that were originally seen in a different scrape session, the only property of the `BRScanResults` object that will be populated is the `blinkReceiptId`
 */
@property (strong, nonatomic, readonly) NSArray<BRScanResults*> *ereceiptComponentEmails;

/**
 *  For an Amazon or e-receipt order, this is the type of purchase
 */
@property (strong, nonatomic, readonly) NSString *ereceiptPurchaseType;

/**
*  The name of the 3rd party service (like Instacart) that fulfilled this order, if any
*/
@property (strong, nonatomic, readonly) NSString *ereceiptFulfilledBy;

/**
*  The name of the sub-merchant (like "McDonald's" for some Uber Eats orders), if any
*/
@property (strong, nonatomic, readonly) NSString *ereceiptSubMerchant;

/**
*  The point of sale system used for this order, if any
*/
@property (strong, nonatomic, readonly) NSString *ereceiptPOSSystem;

/**
 * The internal identifier of this email message from the provider
 */
@property (strong, nonatomic, readonly) NSString *ereceiptEmailId;

/**
 * The shipping costs for this e-receipt, if any
 */
@property (nonatomic, readonly) float ereceiptShippingCosts;

/**
*  Whether this e-receipt could be authenticated via DKIM or SPF headers
*/
@property (nonatomic, readonly) BOOL ereceiptAuthenticated;

/**
*  Whether the email was successfully identified as an e-receipt or related message (as opposed to a marketing message, etc)
*/
@property (nonatomic, readonly) BOOL ereceiptIsValid;

/**
 *  Additional fees / charges for this e-receipt, if any (like tips, bag / bottle fees, etc...)
 *  Each key-value pair, represents the name of the fee and its amount { "Tips": "2.19", "Bag Fee": "0.05" }
 */
@property (strong, nonatomic, readonly) NSDictionary<NSString*,NSString*> *ereceiptAdditionalFees;

/**
 *  An array of `BRShipment` objects representing all shipments discovered in this order
 */
@property (strong, nonatomic, readonly) NSArray<BRShipment*> *shipments;

/**
 *  NSString representing cumulative set of raw results
 */
@property (strong, nonatomic, readonly) NSString *combinedRawText;

/**
 * For custom user corrections flow, if the user adds a new product, call this method to add it to this scan results object
 * @param brand     The brand, if any, of the new product
 * @param upc         The upc, if any, of the new product
 * @param productName The name, if any, of the new product
 * @param imgUrl    The image URL, if any, of the new product
 * @param totalPrice The total price of the new product
 * @param quantity The quantity of the new product
 */
- (void)addUserCorrectedProductWithBrand:(NSString*)brand
                                     upc:(NSString*)upc
                             productName:(NSString*)productName
                                imageUrl:(NSString*)imgUrl
                              totalPrice:(float)totalPrice
                                quantity:(float)quantity;

/**
 * For custom user corrections flow, when a user modifies the date, call this method to update the receipt's purchase date
 *
 * @param dateString     The date in MM/dd/yyyy format
 */
- (void)userCorrectedDate:(NSString*)dateString;

/**
 * For custom user corrections flow, when a user modifies the total, call this method to update the receipt's purchase total
 *
 * @param total
 */
- (void)userCorrectedTotal:(float)total;

/**
 * For custom user corrections flow, when a user modifies the merchant, call this method to update the receipt's purchase merchant name
 *
 * @param name
 */
- (void)userCorrectedMerchant:(NSString*)name;

@end
