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

@interface BRAmazonManager : NSObject

/**
 Set this property to control how far back in the user's Amazon history to search for orders
 Default: 15
 */
@property (nonatomic) NSInteger amazonDayCutoff;

+ (instancetype)shared;

/**
 This callback provides any incremental orders found on the user's Amazon account. An incremental order is defined as an order that has not been previously returned, or an order previously returned but with a new status (i.e. if the status of any items changes from "Processing" to "Shipped")
 
 @param     orders      An array of BRScanResults objects. You can expect the following metadata properties to be populated:
                         total
                         receiptDate
                         ereceiptOrderNum
 
                         shipments - An array of BRShipment objects. Each shipment contains a status and an array of products.
 
                         For products in an Amazon order, you can expect the following properties to be populated:
                             productNumber (this corresponds to the Amazon ASIN)
                             productDescription
                             unitPrice
                             totalPrice
                             quantity
 
                        We also attempt to populate product intelligence fields for these products such as productName, brand, category, etc.
 
 @param     error       BRAmazonErrorNone on success, otherwise indicates the type of error.
                        BRAmazonErrorVerificationNeeded indicates the user needs to manually log in to Amazon via a mobile web page, for this we provide the showBrowserFromViewController:withCompletion: method below
 */
- (void)grabNewAmazonOrders:(void(^)(NSArray<BRScanResults*> *orders, BRAmazonError error))completion;

/**
 Store the user's Amazon credentials in the keychain
 
 @param     email
 @param     password
 */
- (void)storeCredentials:(NSString*)email password:(NSString*)password;

/**
 After receiving the didGetAmazonAuthenticationError callback, this method can be called to clear the Amazon credentials.
 */
- (void)clearAmazonCredentials;

/**
 Indicates whether Amazon credentials are stored
 */
- (BOOL)hasCredentials;

/**
 Reset the stored history of Amazon orders
 */
- (void)resetAmazonOrders;

/**
 Attempts to verify the stored Amazon credentials
 
 @param completion Callback indicates whether account was verified successfully or not.
                    @param     error        BRAmazonErrorNone on success, otherwise indicates the type of error.
                                            BRAmazonErrorVerificationNeeded indicates the user needs to manually log in to Amazon via a mobile web page, for this we provide the showBrowserFromViewController:withCompletion: method below
 */
- (void)verifyAmazonAccount:(void(^)(BRAmazonError error))completion;

/**
 Shows a view controller containing a web view that allows

 @param     viewController      You must provide a view controller from which the web view will be shown
 @param     completion          The completion indicates whether the user successfully logged in manually. If so, you can call grabNewAmazonOrders:
 */
- (void)showBrowserFromViewController:(UIViewController*)viewController withCompletion:(void(^)(BRAmazonError error))completion;

@end
