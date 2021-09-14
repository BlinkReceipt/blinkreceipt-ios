# 1.22.0
- Move to `XCFramework` packaging to support M1 processors

# 1.21.2
- Improved stack traces
- Fix for parser crash and infinite loop

# 1.21.1
- Parsing improvements

# 1.20.2
- Fix parser crashes

# 1.20.1
- Rebuild of 1.21.2 for compatibility with older BlinkEReceipt SDKs

# 1.20.0
- Parsing improvements
- Support prod intel for subproducts

# 1.19.0
- Alleviate memory consumption on iPhone 6 and below

# 1.18.1
- Add `countryCode` param for custom missed earnings flow
- Ensure correct country code is used for product intelligence during missed earnings
- Fix rare crash due to race condition
- Additional prod intel properties: `sector`, `department`, `majorCategory`, `subCategory`, `attributes`, `itemType`
- Improve logo detection for Target and other retailers

# 1.17.0
- Add additional barcode formats for missed earnings scanning in ZA
- Safety check to address infrequent crash
- Improved product intelligence for quick service retailers

# 1.16.0
- Parsing improvements
- Expanded support for retailers that print part of the receipt in inverted colors
- Add `countryCode` parameter to receipt correction flow to account for differences in barcode lengths
- Fix prod intel bug failing some requests with many products
- Fix crash in duplicate detection

# 1.15.0
- Fix 2021 date bug
- Fix OCR confidences bug
- Ability to disable prod intel by passing in a null key
- Fix various prod intel edge cases

# 1.14.0
- Add survey functionality
- Convert `totalPrice`, `fullPrice`, and `priceAfterCoupons` properties of `BRProduct` to `BRFloatValue` wrapper type
- Improved scanning accuracy

# 1.13.0
- Add `BRProduct.fuelType` property to identify receipts where fuel was purchased
- Improvements to merchant detection for fuel receipts
- Parsing improvements

# 1.12.0
- Add `BRScanResults.ereceiptComponentEmails` property to support BlinKEReceipt SDK 2.2.0

# 1.11.1
- Parsing improvements
- Migrate to AFNetworking 4.0
- Fix bugs related to `nil` dictionary values
- Improved screen detection

# 1.10.2
- Ability to push custom camera controller from navigation controller
- Scan option to start returning edge detection results at beginning of scan
- Fix bugs in missed earnings validation

# 1.10.1
- Fix bug parsing products without prices

# 1.10.0
- Support prefixes and postfixes for product and coupon descriptions and skus
- Improved screen fraud detection
- Fix crash in merchant detection
- Automatic corrections to product descriptions + skus based on historical scanning data

# 1.9.2
- Add Spanish + French localizations
- Fix crash in merchant detection
- Handle scenario of starting missed earnings flow with `BRScanResults` object immediately after scan session
- Fix bug not populating `totalPrice` in missed earnings flow when getting `BRScanResults` object from server

# 1.9.1
- Fix bug overwriting user changes in missed earnings flow

# 1.9.0
- Improvements to purchase validation during missed earnings flow
- Many receipt parsing improvements
- Refactor frame properties for user photos into separate class
- ML model for detecting photos of screens
- Fraud detection
- Improved channel detection
- Long tail merchant detection
- Fix for scenarios where subproducts were missed
- Fix crash where camera frame is null

# 1.8.9
- Fix crash when logo detection is disabled

# 1.8.8
- Reduced memory usage by neural networks
- Improved scanning accuracy
- Expanded editable fields in missed earnings flow
- Improved duplicate detection
- Improved blurry receipt detection

# 1.8.7
- Support sub products in missed earnings
- Serialize / deserialize `BRProduct.userAdded` and `BRProduct.userModified`
- Update for BlinkEReceipt v0.0.9
- Use AFNetworking subspec to avoid UIWebView submission rejection
- Better duplicate detection

# 1.8.6
- Continuous autofocus for missed earnings barcode controller
- Product intelligence for international + out of home merchants
- Support for sub products

# 1.8.5
- Fix crash on McDonald's receipts

# 1.8.4
- Missed Earnings crash fixes + UI tweaks
- Add property to indicate whether current device can process video frames
- Fix slow camera load on older devices
- Fix PVP crash for retailer promotions
- Add `isReceipt` parameter to `didGetFrameStats` callback
- Add method to retrieve PVP promotions for current user
- Improve logic for detecting merchant during scan

# 1.8.3
- Fix for Target + CVS barcode scanning impacting dates
- Add `isReceipt` parameter to user frame callback
- Fix promotion validation bug 

# 1.8.2
- Fix for certain 2020 dates

# 1.8.1
- Identify retailer loyalty programs
- Return retail channel property
- Fix UI bugs in stock camera controller in low memory conditions
- Improved scanning of Costco + Walmart receipts
- Fix crash in logging
- Support for dynamically improving merchant detection without SDK update
- Many parser improvements

# 1.8.0
- Incorporate full price into product intelligence
- Missed Earnings flow
- iOS 13 UI fixes
- Support for dark mode
- Fix Costco date parsing
- Fix foundTopEdge and foundBottomEdge properties
- Updated OCR model
- Parser improvements

# 1.7.9
- Fix parser crash

# 1.7.8
- Parsing improvements
- Logo detection improvements
- Consolidated merchant detection internationally
- More reliable purchase validation
- Ability to pass in a client user ID

# 1.7.7
- Updated internal OCR system
- Improved memory management
- Minor parser fixes
- Stability improvements

# 1.7.6
- Fix crash in low memory situations

# 1.7.5
- Refactor e-receipt dependencies into separate framework to avoid weak linking architecture  
- Remove Scandit support  
- Fix validation of retailer-based promotions  
- Fix bug in scanning dates on Costco receipts  
  
  
# 1.7.4  
- Remove MailCore dependency causing App Store submission issues due to weak linking  
- Updated OCR model  
- More reliable promotion validation  
- Duplicate detection can now return multiple duplicate Blink Receipt IDs  
- Fix scan state bug after showing and dismissing a view controller on top of camera controller  
  
  
# 1.7.3  
- Include possible products + probabilties in product intelligence data  
- Aggregate qualified promotions  
- Fix minor crash in Amazon parsing  
- Fix hang during end of scan flow