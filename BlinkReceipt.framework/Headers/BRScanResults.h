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
@property (nonatomic, readonly) float total;

/**
 *  The subtotal detected on the receipt, if any
 */
@property (nonatomic, readonly) float subtotal;

/**
 *  The tax detected on the receipt, if any
 */
@property (nonatomic, readonly) float taxes;

/**
 The purchase date found on the receipt formatted as MM/dd/yyyy
 nil if not found
 */
@property (strong, nonatomic, readonly) NSString *receiptDate;


/**
 The purchase time found on the receipt formatted as HH:mm
 nil if not found
 */
@property (strong, nonatomic, readonly) NSString *receiptTime;

/**
 *  The barcode detected on the receipt, if any.
 *  Currently we recognize Code 39, Code 128, and ITF formats
 */
@property (strong, nonatomic, readonly) NSString *barcode;

/**
 *  The store number detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storeNumber;

/**
 *  The store name detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storeName;

/**
 *  The mall name in which the retailer is located, if any
 */
@property (strong, nonatomic, readonly) NSString *mallName;

/**
 *  The store street address detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storeAddress;

/**
 *  The store city detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storeCity;

/**
 *  The store state detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storeState;

/**
 *  The store zipcode detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storeZip;

/**
 *  The store phone number detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *storePhone;


/**
 *  The cashier ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *cashierId;

/**
 *  The transaction ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *transactionId;

/**
 *  The register ID detected on the receipt, if any
 */
@property (strong, nonatomic, readonly) NSString *registerId;


/**
 The payment methods detected on the receipt, if any
 Each payment method detected is returned as an NSDictionary* with keys:
   type     : NSString* with the name of the payment method
   amount   : NSNumber* containing a float with the amount for that payment method
 */
@property (strong, nonatomic, readonly) NSArray<NSDictionary*> *paymentMethods;

/**
 *  The tax ID of the retailer, if any
 */
@property (strong, nonatomic, readonly) NSString *taxId;

@end
