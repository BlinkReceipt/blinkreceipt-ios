// swift-tools-version: 5.7

import PackageDescription

let frameworkName = "BlinkReceipt"
let package = Package(
    name: frameworkName,
    platforms: [
        .iOS(.v13)
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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.59.0/BlinkReceiptStatic.xcframework-1.59.0.zip",
            checksum: "d1d55b96dfb58aa19b8d5964ad491ee2f62c00467218bac9cd597be370a4fd61"
        )
    ]
)
