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