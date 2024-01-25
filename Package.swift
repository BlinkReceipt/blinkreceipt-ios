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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.44.0/BlinkReceiptStatic.xcframework-1.44.0.zip",
            checksum: "6488a35c748e14ecda541a2aede5c7cea50bfe952a967b486e161b66790e6867"
        )
    ]
)
