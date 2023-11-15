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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.40.0/BlinkReceiptStatic.xcframework-1.40.0.zip",
            checksum: "4690e24f3df93506ee40e624bd6693561395065edbe6ec31c0fc2a36ec553c45"
        )
    ]
)
