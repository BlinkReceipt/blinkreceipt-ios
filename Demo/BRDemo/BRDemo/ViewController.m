//
//  ViewController.m
//  BRDemo
//
//  Created by Danny Panzer on 3/6/18.
//  Copyright © 2018 BlinkReceipt. All rights reserved.
//

#import "ViewController.h"
#import <BlinkReceipt/BlinkReceipt.h>

@interface ViewController ()<BRScanResultsDelegate>
  
  @end

@implementation ViewController
  
- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  [BRScanManager sharedManager].licenseKey = @"Test";
  self.view.backgroundColor = [UIColor grayColor];
  
  //create button
  UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
  [button addTarget:self action:@selector(scanReceipt) forControlEvents:UIControlEventTouchUpInside];
  [button setTitle:@"Scan receipt" forState:UIControlStateNormal];
  button.frame = CGRectMake(80.0, 210.0, 160.0, 40.0);
  [self.view addSubview:button];
  
}
  
  - (void)scanReceipt{
    BRScanOptions *scanOptions = [BRScanOptions new];
    [[BRScanManager sharedManager] startStaticCameraFromController:self scanOptions:scanOptions withDelegate:self];
  }
  
  - (void)printString:(NSString *)string name:(NSString *)name {
    NSLog(@"%@: %@", name, string ? string : @"none");
  }
  
  - (void)printFloat:(float)num name:(NSString *)name {
    NSLog(@"%@: %f", name, num);
  }
  
  - (void)didFinishScanning:(UIViewController *)cameraViewController withScanResults:(BRScanResults *)scanResults {
    [cameraViewController dismissViewControllerAnimated:YES completion:nil];
    
    NSLog(@"scanResults: %@", scanResults);
    [self printScanResults:scanResults];
  }
  
  - (void)printScanResults:(BRScanResults *)scanResults {
    NSLog(@"retailerId: %lu", (unsigned long)scanResults.retailerId);
    
    [self printString:scanResults.blinkReceiptId name:@"blinkReceiptId"];
    
    NSLog(@"Products:");
    for (BRProduct *product in scanResults.products) {
      if (product.productDescription) {
        [self printString:product.productDescription.value name:@"product"];
      }
    }
    
    NSLog(@"Coupons:");
    for (BRCoupon *coupon in scanResults.coupons) {
      if (coupon.couponDesc) {
        [self printString:coupon.couponDesc.value name:@"coupon"];
      }
    }
    
    
    if (scanResults.total) {
      [self printFloat:scanResults.total.value name:@"total"];
    }
    if (scanResults.subtotal) {
      [self printFloat:scanResults.subtotal.value name:@"subtotal"];
    }
    if (scanResults.taxes) {
      [self printFloat:scanResults.taxes.value name:@"taxes"];
    }
    if (scanResults.receiptDate) {
      [self printString:scanResults.receiptDate.value name:@"receiptDate"];
    }
    if (scanResults.receiptTime) {
      [self printString:scanResults.receiptTime.value name:@"receiptTime"];
    }
    
    [self printString:scanResults.barcode name:@"barcode"];
    
    if (scanResults.storeNumber) {
      [self printString:scanResults.storeNumber.value name:@"storeNumber"];
    }
    if (scanResults.merchantName) {
      [self printString:scanResults.merchantName.value name:@"merchantName"];
    }
    if (scanResults.mallName) {
      [self printString:scanResults.mallName.value name:@"mallName"];
    }
    if (scanResults.storeAddress) {
      [self printString:scanResults.storeAddress.value name:@"storeAddress"];
    }
    if (scanResults.storeCity) {
      [self printString:scanResults.storeCity.value name:@"storeCity"];
    }
    if (scanResults.storeState) {
      [self printString:scanResults.storeState.value name:@"storeState"];
    }
    if (scanResults.storeZip) {
      [self printString:scanResults.storeZip.value name:@"storeZip"];
    }
    if (scanResults.storePhone) {
      [self printString:scanResults.storePhone.value name:@"storePhone"];
    }
    
    if (scanResults.cashierId) {
      [self printString:scanResults.cashierId.value name:@"cashierId"];
    }
    if (scanResults.transactionId) {
      [self printString:scanResults.transactionId.value name:@"transactionId"];
    }
    if (scanResults.registerId) {
      [self printString:scanResults.registerId.value name:@"registerId"];
    }
    if (scanResults.paymentMethods) {
      [self printString:scanResults.paymentMethods.accessibilityValue name:@"paymentMethods"];
    }
    if (scanResults.taxId) {
      [self printString:scanResults.taxId.value name:@"taxId"];
    }
    
  }
  
  
- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}
  
  
  @end
