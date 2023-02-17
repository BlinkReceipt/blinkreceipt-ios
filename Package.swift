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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.34.0/BlinkReceiptStatic.xcframework-1.34.0.zip",
            checksum: "d0f2cc812efd0a344d9d62afb351fd06401b41c31c5dd779fb1af5960855383b"
        )
    ]
)
