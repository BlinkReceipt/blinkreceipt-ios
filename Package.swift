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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.34.1/BlinkReceiptStatic.xcframework-1.34.1.zip",
            checksum: "2ff1270f6323614d15771d3f1c07737b1672404e872dcb1c769571a1071ffe89"
        )
    ]
)
