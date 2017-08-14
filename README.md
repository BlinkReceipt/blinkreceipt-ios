# BlinkReceipt Integration Instructions

## Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like BlinkReceipt in your projects. If you do not have Cocoapods installed, see the [Getting Started Guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

### Podfile

```ruby
source 'https://github.com/BlinkReceipt/PodSpecRepo.git'
source 'https://github.com/CocoaPods/Specs.git'

platform :ios, '8.0'

target 'YourTarget' do
  use_frameworks!

  pod 'BlinkReceipt', '~> 1.0'
end
```
- Note: If you plan to use Scandit barcode scanning, please also add the following line to your `Podfile`:
```
pod 'BRScandit', '~> 2.0'
```
After editing your Podfile, run `pod install` and then make sure to open the `.xcworkspace` file rather than the `.xcodeproj`

## Integration

- Add the following to the top of your AppDelegate.m:

```obj-c
#import <BlinkReceipt/BlinkReceipt.h>
```

- Add the following to the `applicationDidFinishLaunching:` method:

```obj-c
[BRScanManager sharedManager].licenseKey = @"YOUR-LICENSE-KEY";
```

- If you have a Scandit app key (and included the `BRScandit` pod above) then add it as follows:

```obj-c
[BRScanManager sharedManager].scanditAppKey = @"YOUR-SCANDIT-KEY";
```

- The simplest way to test the SDK is by launching one of our prepackaged scanning experiences

### Static Camera Scanning

This scanning mode simulates the user snapping a series of still photos although in fact live video frames are actually being scanned in the background. To test this:

- Add the following code to the top of your view controller

```obj-c
#import <BlinkReceipt/BlinkReceipt.h>
```

- Add the following code to an IBAction handler in your view controller:

```obj-c
- (IBAction)btnTouched:(id)sender {
  BRScanOptions *scanOptions = [BRScanOptions new];
  scanOptions.retailerId = WFRetailerWalgreens;
  
  [[BRScanManager sharedManager] startStaticCameraFromController:self
                                                     scanOptions:scanOptions
                                                    withDelegate:self];
}
```

- Declare your view controller to conform to `BRScanResultsDelegate`:

```obj-c
@interface MyViewController () <BRScanResultsDelegate>
```

- Implement the delegate callback to handle scan results:

```obj-c
- (void)didFinishScanning:(UIViewController *)cameraViewController withScanResults:(BRScanResults *)scanResults {
    [cameraViewController dismissViewControllerAnimated:YES completion:nil];
        
    //Use scan results
}
```

### Live Camera Scanning

This scanning mode allows the user to simply hover over the receipt and receive scanning feedback in the form of character overlays that are displayed after OCR completes for each frame. To test this, follow all the same instructions as above, but in the IBAction handler of your view controller, use the following method call instead:

```obj-c
[[BRScanManager sharedManager] startLiveCameraFromController:self
                                                 scanOptions:scanOptions
                                                withDelegate:self];
```

### Custom Camera Controller UI

You can also build out your own UI that sits on top of our basic camera controller. To do so, all you have to do is subclass `BRCameraViewController` and create your UI programmatically or in Interface Builder as normal.

```obj-c
#import <BlinkReceipt/BlinkReceipt.h>

@interface MyCameraController : BRCameraViewController
```

- Note that you must set the background of your view to be transparent so that the camera controller underneath will be visible.

Your camera controller interacts with properties and methods of its superclass to facilitate the scanning experience. For details refer to BRCameraViewController.h

To begin scanning with your custom controller use the following in your IBAction handler:

```obj-c
MyCameraController *cameraController = [MyCameraController new]; //or instantiate from storyboard

[[BRScanManager sharedManager] startCustomCamera:cameraController
                                  fromController:self
                                     scanOptions:scanOptions
                                    withDelegate:self];
```


Copyright (c) 2017 BlinkReceipt. All rights reserved.