// swift-tools-version: 5.7

import PackageDescription

let package = Package(
    name: "BlinkReceiptStatic",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "BlinkReceiptStatic",
            targets: ["BlinkReceiptStatic"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "BlinkReceiptStatic",
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.41.0/BlinkReceiptStatic.xcframework-1.41.0.zip",
            checksum: "27b1c597a4a39df23d8f1b6147de60db854153ca813ce6f0cc1d551ca5cf4e4c"
        )
    ]
)
