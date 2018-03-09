//
//  BRScanResults.h
//  BlinkReceipt
//
//  Created by Danny Panzer on 8/8/16.
//  Copyright © 2016 BlinkReceipt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BRScanOptions.h"
#import "BRProduct.h"
#import "BRCoupon.h"
#import "BRPaymentMethod.h"
#import "BRValue.h"

/**
 *  This class holds the scan results for a particular scanning session
 */
@interface BRScanResults : NSObject

/**------------------*/
/** @name Properties */
/**------------------*/

/**
 *  For future auto-detect retailer functionality
 */
@property (nonatomic, readonly) WFRetailerId retailerId;


/**
 Unique ID for this receipt which allows BlinkReceipt to correspond scan data to the correct receipt image stored by client
 */
@property (strong, nonatomic, readonly) NSString *blinkReceiptId;

/**
 *  An array of BRProduct's representing the products that were detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSArray<BRProduct*> *products;

/**
 *  An array of BRCoupon's representing the coupons that were detected on the receipt, if any
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
 The purchase date found on the receipt formatted as MM/dd/yyyy, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *receiptDate;


/**
 The purchase time found on the receipt formatted as HH:mm, if any
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
 *  The register ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *registerId;


/**
 An array of BRPaymentMethod's representing all payment methods found on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSArray<BRPaymentMethod*> *paymentMethods;

/**
 *  The tax ID of the retailer, if any
 */
@property (strong, nonatomic, readonly) BRStringValue *taxId;


/**
 An average confidence (between 0 and 1) for the OCR performed on this receipt
 */
@property (nonatomic, readonly) float ocrConfidence;

/**
 Indicates whether any server lookups were still pending at the time results were returned to the client
 */
@property (nonatomic, readonly) BOOL serverLookupsCompleted;

@end
