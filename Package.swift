// swift-tools-version: 5.7

import PackageDescription

let frameworkName = "BlinkReceipt"
let package = Package(
    name: frameworkName,
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: frameworkName,
            targets: [frameworkName]),
        .library(
            name: "\(frameworkName)Static",
            targets: ["\(frameworkName)Static"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: frameworkName,
            path: "\(frameworkName).xcframework"
        ),
        .binaryTarget(
            name: "\(frameworkName)Static",
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.76.0/BlinkReceiptStatic.xcframework-1.76.0.zip",
            checksum: "02df3910c5e293c2ad914f0673c4454f07201b737a37b819f10894745f8a0541"
        )
    ]
)
