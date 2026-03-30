// swift-tools-version: 5.7

import PackageDescription

let frameworkName = "BlinkReceipt"
let package = Package(
    name: frameworkName,
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: frameworkName,
            targets: [frameworkName]),
        .library(
            name: "\(frameworkName)Static",
            targets: ["\(frameworkName)Static"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: frameworkName,
            path: "\(frameworkName).xcframework"
        ),
        .binaryTarget(
            name: "\(frameworkName)Static",
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.66.1/BlinkReceiptStatic.xcframework-1.66.1.zip",
            checksum: "3945098e6576f0b1b639f69cb1972af23846a6febc37977dffc7807a6d2a9e9e"
        )
    ]
)
