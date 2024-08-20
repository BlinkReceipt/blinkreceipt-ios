// swift-tools-version: 5.7

import PackageDescription

let frameworkName = "BlinkReceipt"
let package = Package(
    name: frameworkName,
    platforms: [
        .iOS(.v12)
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
            url: "https://github.com/BlinkReceipt/blinkreceipt-ios/releases/download/1.52.0/BlinkReceiptStatic.xcframework-1.52.0.zip",
            checksum: "4731796d3955defd450b5a22d828fa2bd7d70ae34e4aa38aca604dbf91aa3b74"
        )
    ]
)
