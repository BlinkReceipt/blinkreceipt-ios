//
//  BRAmazonManager.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 2/19/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "BRScanResults.h"

typedef enum : NSUInteger {
    BRAmazonErrorNone = 0,
    BRAmazonErrorNoCredentials,
    BRAmazonErrorInvalidEmail,
    BRAmazonErrorInvalidPassword,
    BRAmazonErrorInvalidCookie,
    BRAmazonErrorVerificationNeeded,
    BRAmazonErrorParsingFail,
    BRAmazonErrorLoginTimeout,
    BRAmazonErroriOS12
} BRAmazonError;

/**
 *  Use this interface to manage Amazon parsing. Here are the basic steps to integrate:
 *
 *  1. Implement UI to capture the user's Amazon email and password
 *  2. Store these using `-[BRAmazonManager storeCredentials:password:]`
 *  3. Call `-[BRAmazonManager verifyAmazonAccount:]` to ensure the credentials are valid
 *  4. If validation succeeds, call `-[BRAmazonManager grabNewAmazonOrders:]`
 *  5. The callback to this method will return all Amazon order details available since the most recent successful invocation
 */
@interface BRAmazonManager : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  Set this property to control how far back in the user's Amazon history to search for orders
 *
 *  Default: 15
 */
@property (nonatomic) NSInteger amazonDayCutoff;

///---------------------
/// @name Class Methods
///---------------------

+ (instancetype)shared;

///---------------
/// @name Methods
///---------------

/**
 *  This method grabs any incremental orders found on the user's Amazon account. An incremental order is defined as an order that has not been previously returned, or an order previously returned but with a new status (i.e. if the status of any items changes from "Processing" to "Shipped")
 
 *  @param completion This callback is invoked when parsing the user's Amazon account has completed
 *
 *      * `NSArray<BRScanResults*> *orders` - An array of `BRScanResults` objects representing all the Amazon orders found. You can expect the following order-level properties to be populated:
 *
 *          * `BRScanResults.total`
 *          * `BRScanResults.receiptDate`
 *          * `BRScanResults.ereceiptOrderNum`
 *          * `BRScanResults.shipments` - An array of `BRShipment` objects. Each shipment contains a status and an array of products.
 *
 *          For products in an Amazon order, you can expect the following properties to be populated:
 *
 *          * `BRProduct.productNumber` (this corresponds to the Amazon ASIN)
 *          * `BRProduct.productDescription`
 *          * `BRProduct.unitPrice`
 *          * `BRProduct.totalPrice`
 *          * `BRProduct.quantity`
 *
 *          If you have product intelligence enabled, we also attempt to populate these product fields:
 *
 *          * `BRProduct.productName`
 *          * `BRProduct.brand`
 *          * `BRProduct.category`
 *          * `BRProduct.size`
 *          * `BRProduct.upc`
 *          * `BRProduct.imgUrl`
 *
 *      * `BRAmazonError error` - `BRAmazonErrorNone` on success, otherwise indicates the type of error.
 *
 *          `BRAmazonErrorVerificationNeeded` indicates the user needs to manually log in to Amazon via a mobile web page, for this see the  `-[BRAmazonManager showBrowserFromViewController:withCompletion:]` method below
 */
- (void)grabNewAmazonOrders:(void(^)(NSArray<BRScanResults*> *orders, BRAmazonError error))completion;

/**
 *  Store the user's Amazon credentials in the keychain
 */
- (void)storeCredentials:(NSString*)email password:(NSString*)password;

/**
 *  This method must be called to clear the Amazon credentials if switching Amazon accounts or if, for example, the user changes their Amazon password and `-[BRAmazonManager grabNewAmazonOrders:]` starts returning error codes.
 */
- (void)clearAmazonCredentials;

/**
 *  Indicates whether Amazon credentials are stored
 */
- (BOOL)hasCredentials;

/**
 *  Reset the stored history of Amazon orders
 */
- (void)resetAmazonOrders;

/**
 *  Attempts to verify the stored Amazon credentials
 *
 *  @param completion Callback indicates whether account was verified successfully or not.
 *
 *      * `BRAmazonError error` - `BRAmazonErrorNone` on success, otherwise indicates the type of error.
 *          `BRAmazonErrorVerificationNeeded` indicates the user needs to manually log in to Amazon via a mobile web page, for this see the  `-[BRAmazonManager showBrowserFromViewController:withCompletion:]` method below
 */
- (void)verifyAmazonAccount:(void(^)(BRAmazonError error))completion;

/**
 *  Shows a view controller containing a web view that allows
 *
 *  @param viewController You must provide a view controller from which the web view will be shown
 *  @param completion Indicates whether the user successfully logged in manually. If so, you can call `-[BRAmazonManager grabNewAmazonOrders:]`
 *
 *      * `BRAmazonError error` - `BRAmazonErrorNone` if manual login was successful. Otherwise, the appropriate error code
 */
- (void)showBrowserFromViewController:(UIViewController*)viewController withCompletion:(void(^)(BRAmazonError error))completion;

@end
