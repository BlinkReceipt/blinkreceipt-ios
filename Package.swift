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
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: frameworkName,
            path: "\(frameworkName).xcframework"
        )
    ]
)
