# BlinkReceipt Integration Instructions

## Installation with Swift Package Manager

The [Swift Package Manager](https://www.swift.org/package-manager/) is a tool for automating the distribution of Swift code and is integrated into the swift compiler and Xcode.

We provide a URL to the public package repository that you can add in Xcode:

```shell
https://github.com/blinkreceipt/blinkreceipt-ios/
```

In Xcode:

* File > Add Packages
* Enter `https://github.com/blinkreceipt/blinkreceipt-ios/` in the search box in top right corner
* Select "BlinkReceiptStatic" from the list of search results
* For the version strategy choose "branch""""" and make sure that "master" branch is selected""
* Click "Add Package"""

## Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for iOS, which automates and simplifies the process of using 3rd-party libraries like BlinkReceipt in your projects. If you do not have Cocoapods installed, see the [Getting Started Guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

### Podfile

Here is a sample barebones `Podfile` which imports the BlinkReceipt pod:

```ruby
#You must include this additional source as the BlinkReceipt pod is hosted in a private spec repository
source 'https://github.com/BlinkReceipt/PodSpecRepo.git'
source 'https://cdn.cocoapods.org/'

platform :ios, '11.0'

target 'YourTarget' do
  use_frameworks!
  
  pod 'BlinkReceipt', '~> 1.27' 
end
```

After editing your `Podfile`, run `pod install` and then make sure to open the `.xcworkspace` file rather than the `.xcodeproj`

## Installation with Carthage

[Carthage](https://github.com/Carthage/Carthage) is a lightweight dependency manager for iOS. If you do not have Carthage installed see the [Quick Start](https://github.com/Carthage/Carthage#quick-start)

### Cartfile
```
binary "https://raw.githubusercontent.com/BlinkReceipt/blinkreceipt-ios/master/BlinkReceiptStatic.json" ~> 1.27
```

After editing your `Cartfile`, run `carthage update --use-xcframeworks` and then add the framework to your project as described in the Quick Start above

## Standalone Installation

If you do not use a dependency manager:

- Download the latest release from the [Releases](https://github.com/BlinkReceipt/blinkreceipt-ios/releases) tab
- Unzip and drag `BlinkReceiptStatic.xcframework` into your XCode project
- In your target's settings, in the General tab, scroll down to `Frameworks, Libraries, and Embedded Content` and change the `Embed` value for `BlinkReceiptStatic.xcframework` to `Embed & Sign`


## Integration

Please see our integration instructions and reference at https://blinkreceipt.github.io/blinkreceipt-ios


Copyright (c) 2020 BlinkReceipt. All rights reserved.
