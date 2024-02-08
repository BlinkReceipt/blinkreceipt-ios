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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.45.0/BlinkReceiptStatic.xcframework-1.45.0.zip",
            checksum: "7649f09ba9641c816b5250dd6bb1d1493ff085448b0c547d8d913526d20a832e"
        )
    ]
)
