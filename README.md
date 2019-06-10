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

- The simplest way to test the SDK is by launching our prepackaged scanning experience

### Prepackaged Scanning Experience

This scanning mode simulates the user snapping a series of still photos although in fact live video frames are actually being scanned in the background. To test this:

- Add the following code to the top of your view controller

```obj-c
#import <BlinkReceipt/BlinkReceipt.h>
```

- Add the following code to an IBAction handler in your view controller:

```obj-c
- (IBAction)btnTouched:(id)sender {
  BRScanOptions *scanOptions = [BRScanOptions new];
  
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

### Custom Camera Controller UI

You can also build out your own UI that sits on top of our basic camera controller. Check out our [Custom Camera Controller](https://blinkreceipt.github.io/blinkreceipt-ios/custom-camera-controller.html) guide for further details.


Copyright (c) 2017 BlinkReceipt. All rights reserved.
