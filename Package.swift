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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.55.0/BlinkReceiptStatic.xcframework-1.55.0.zip,",
            checksum: "17b811cfa70e92b3628f19ed1f21baeecc103d041b3f791253d8634edfbc59b7"
        )
    ]
)
