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