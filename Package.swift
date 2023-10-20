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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.39.0/BlinkReceiptStatic.xcframework-1.39.0.zip",
            checksum: "4d6822113e1dfc5c148f44bbbe6a638ac80f0f78cf93e02dd2672611dd7c7dd9"
        )
    ]
)
