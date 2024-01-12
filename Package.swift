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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.43.0/BlinkReceiptStatic.xcframework-1.43.0.zip",
            checksum: "dc29c57747c84325fb0021db3cd5fb14d41c33f099f48c5c52a5d9d2fbcdd1ab"
        )
    ]
)
