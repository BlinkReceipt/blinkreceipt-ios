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
    BREReceiptProviderGmail = 1,
    BREReceiptProviderOutlook,
    BREReceiptProviderYahoo,
    BREReceiptProviderAOL
};

@interface BREReceiptManager : NSObject

#pragma mark Properties

/**
 In order to authenticate Gmail accounts, you must enable the Gmail API in your Google API Console and obtain a Client ID for your app's bundle.
 When you have done so, input the Client ID here before attempting to begin the OAuth process for Gmail
 */
@property (nonatomic, strong) NSString *googleClientId;

/**
 In order to authenticate Outlook accounts, you must register your app at the MS Application Registration Portal (https://apps.dev.microsoft.com) and add a Native Application platform. This will generate a Client ID
 When you have done so, input the Client ID here before attempting to begin the OAuth process for Outlook
 */
@property (nonatomic, strong) NSString *outlookClientId;

/**
 In order to authenticate Yahoo accounts, you must register a Yahoo developer account at https://developer.yahoo.com and then contact mail-api@oath.com to request an IMAP ID
 */
@property (nonatomic, strong) NSString *yahooImapId;

/**
 In order to authenticate Yahoo accounts, after obtaining above IMAP ID, create a new app (type=Web Application, callback_domain=microblink.com) at https://developer.yahoo.com.
 The permissions you need to request are "Mail->Read" and "Profiles->Read/Write Public and Private"
 You will then obtain the Client ID and Client Secret
 */
@property (nonatomic, strong) NSString *yahooClientId;
@property (nonatomic, strong) NSString *yahooClientSecret;

#pragma mark Methods

+ (instancetype)shared;

/**
 Begins the OAuth process for the given provider (currently only Gmail and Outlook supported). If the completion is called with no error, you may then invoke getEReceiptsWithCompletion:

 @param provider        The provider you would like to authenticate against
 @param viewController  The view controller from which to present the OAuth modal
 @param completion      The completion function which returns nil on success, and otherwise populates the error
 */
- (void)beginOAuthForProvider:(BREReceiptProvider)provider
           withViewController:(UIViewController*)viewController
                andCompletion:(void(^)(NSError *error))completion;

/**
 For IMAP providers (currently AOL and Yahoo) you must store the credentials prior to calling getEReceiptsWithCompletion:

 @param user        IMAP username
 @param password    IMAP password
 @param provider    IMAP provider
 @return            nil on success, otherwise the error
 */
- (NSError *)storeImapCredentials:(NSString*)user
                      andPassword:(NSString*)password
                      forProvider:(BREReceiptProvider)provider;

/**
 Attempts to retrieve new (since last check) e-receipts from the stored e-mail account. You must have successfully authenticated an OAuth provider, or stored IMAP credentials prior to calling this method

 @param completion  When retrieval is successful, "error" will be nil and "receipts" will contain an array of BRScanResults* objects corresponding to the e-receipts that were successfully parsed. In addition to standard receipt properties, these objects also contain properties unique to e-receipts: ereceiptOrderStatus and ereceiptOrderNum
                    On an error, "error" will be populated with the error, and "receipts" will be nil
 */
- (void)getEReceiptsWithCompletion:(void(^)(NSArray<BRScanResults*> *receipts, NSError *error))completion;

/**
 Signs out of any stored email account and stored e-receipt info. For OAuth providers this signs out of the provider and invalidates the access token. For IMAP providers this removes stored credentails.
 */
- (void)signOut;

+ (NSString*)getNameForProvider:(BREReceiptProvider)provider;

@end
