// swift-tools-version: 5.7

import PackageDescription

let package = Package(
    name: "BlinkReceipt",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "BlinkReceipt",
            targets: ["BlinkReceipt"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "BlinkReceiptStatic",
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.46.0/BlinkReceiptStatic.xcframework-1.46.0.zip",
            checksum: "11d44aab4df7d50a01baf7cd2f9e414c14c5255ba506264cfcc3820f2e3ebe1d"
        )
    ]
)
