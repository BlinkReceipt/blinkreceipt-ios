//
//  BREReceiptManager.h
//  WindfallSDK-Dev
//
//  Created by Danny Panzer on 5/4/18.
//  Copyright © 2018 Windfall. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "BRScanResults.h"

typedef NS_ENUM(NSUInteger, BREReceiptProvider) {
    BREReceiptProviderNone = 0,
    BREReceiptProviderGmail,
    BREReceiptProviderOutlook,
    BREReceiptProviderYahoo,
    BREReceiptProviderAOL
};

/**
 *  This class is the interface to manage e-receipt parsing
 */
@interface BREReceiptManager : NSObject

///------------------
/// @name Properties
///------------------

/**
 *  In order to authenticate Gmail accounts, you must enable the Gmail API in your Google API Console and obtain a Client ID for your app's bundle.
 *  When you have done so, input the Client ID here before attempting to begin the OAuth process for Gmail
 */
@property (nonatomic, strong) NSString *googleClientId;

/**
 *  In order to authenticate Outlook accounts, you must register your app at the MS Application Registration Portal (https://apps.dev.microsoft.com) and add a Native Application platform. This will generate a Client ID
 *  When you have done so, input the Client ID here before attempting to begin the OAuth process for Outlook
 */
@property (nonatomic, strong) NSString *outlookClientId;

/**
 *  In order to authenticate Yahoo accounts, you must register a Yahoo developer account at https://developer.yahoo.com and then contact mail-api@oath.com to request an IMAP ID
 */
@property (nonatomic, strong) NSString *yahooImapId;

/**
 *  In order to authenticate Yahoo accounts, after obtaining above IMAP ID, create a new app (type=Web Application, callback_domain=microblink.com) at https://developer.yahoo.com.
 *  The permissions you need to request are "Mail->Read" and "Profiles->Read/Write Public and Private"
 *  You will then obtain the Client ID and Client Secret
 */
@property (nonatomic, strong) NSString *yahooClientId;

/**
 *  In order to authenticate Yahoo accounts, after obtaining above IMAP ID, create a new app (type=Web Application, callback_domain=microblink.com) at https://developer.yahoo.com.
 *  The permissions you need to request are "Mail->Read" and "Profiles->Read/Write Public and Private"
 *  You will then obtain the Client ID and Client Secret
 */
@property (nonatomic, strong) NSString *yahooClientSecret;

/**
 *  Whether there is a stored provider
 */
@property (nonatomic) BOOL userHasProvider;

/**
 *  If there is a stored provider, this property will indicate which provider it is
 */
@property (nonatomic) BREReceiptProvider currentProvider;

/**
 *  Debug property to enable other sender emails to be parsed as ereceipts.
 *  Each element in this array should be a dictionary with the following keys:
 *      * `email` - The e-mail address to whitelist
 *      * `merchant` - The merchant to use for parsing emails from this sender. Values are: Peapod, Walmart, Target, Instacart, Jet, Costco, SamsClub
 */
@property (strong, nonatomic) NSArray<NSDictionary*> *whitelistedSenders;


/**
 *  How far back (in days) to search the user's inbox for e-receipts
 *
 *  Default: 14
 */
@property (nonatomic) NSInteger dayCutoff;

/**
 *  If the OAuth provider supports returning the logged-in email, it will be populated into this property after OAuth or silent authentications
 */
@property (strong, nonatomic) NSString *userCurrentEmail;

///---------------------
/// @name Class Methods
///---------------------

+ (instancetype)shared;

///---------------
/// @name Methods
///---------------

/**
 *  Begins the OAuth process for the given provider (currently only Gmail and Outlook supported). If the completion is called with no error, you may then invoke `-[BREReceiptManager getEReceiptsWithCompletion:]`
 *
 *  @param provider The provider you would like to authenticate against
 *  @param viewController The view controller from which to present the OAuth modal
 *  @param completion The completion is invoked after the OAuth attempt has completed
 *
 *      * `NSError *error` - The error returned during the OAuth attempt, if any. A successful attempt will return `nil`
 */
- (void)beginOAuthForProvider:(BREReceiptProvider)provider
           withViewController:(UIViewController*)viewController
                andCompletion:(void(^)(NSError *error))completion;

/**
 *  For IMAP providers (currently AOL and Yahoo) you must store the credentials prior to calling `-[BREReceiptManager getEReceiptsWithCompletion:]`
 *
 *  @return `nil` on success, otherwise the error
 */
- (NSError *)storeImapCredentials:(NSString*)user
                      andPassword:(NSString*)password
                      forProvider:(BREReceiptProvider)provider;

/**
 *  Verifies that stored IMAP credentials are valid
 *
 *  @param completion The completion is invoked after the attempt to verify IMAP credentials completes
 *
 *      * `BOOL success` - indicates whether verification succeeded or not
 *      * `NSError *error` - `nil` on success, otherwise contains error information
 */
- (void)verifyImapCredentials:(void(^)(BOOL success, NSError *error))completion;

/**
 *  Attempts to retrieve new (since last check) e-receipts from the stored e-mail account. You must have successfully authenticated an OAuth provider, or stored IMAP credentials prior to calling this method
 *
 *  @param completion The completion function will be invoked when e-receipt parsing has completed.
 *
 *      * `NSArray<BRScanResults*> *receipts` - an array of `BRScanResults` objects corresponding to the e-receipts that were successfully parsed. You can expect the following order-level properties to be populated:
 *
 *          * `BRScanResults.total`
 *          * `BRScanResults.receiptDate`
 *          * `BRScanResults.ereceiptOrderNum`
 *
 *          For products in an e-receipt, you can expect the following properties to be populated:
 *
 *          * `BRProduct.productNumber`
 *          * `BRProduct.productDescription`
 *          * `BRProduct.unitPrice`
 *          * `BRProduct.totalPrice`
 *          * `BRProduct.quantity`
 *          * `BRProduct.shippingStatus`
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
 *      * `NSError *error` - `nil` on success, otherwise contains the error
 */
- (void)getEReceiptsWithCompletion:(void(^)(NSArray<BRScanResults*> *receipts, NSError *error))completion;

/**
 *  Signs out of any stored email account and stored e-receipt info. For OAuth providers this signs out of the provider and invalidates the access token. For IMAP providers this removes stored credentails.
 */
- (void)signOut;

/**
 *  Resets emails so you don't need to log out and log in during testing
 */
- (void)resetEmailsChecked;

@end
