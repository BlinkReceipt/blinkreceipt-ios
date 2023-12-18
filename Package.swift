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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.42.0/BlinkReceiptStatic.xcframework-1.42.0.zip",
            checksum: "d4e33f5986f917894e51404253c0e76ab84ac343d7545a80dd2be2c432c727a5"
        )
    ]
)
