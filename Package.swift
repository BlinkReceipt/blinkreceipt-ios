// swift-tools-version: 5.7

import PackageDescription

let package = Package(
    name: "BlinkReceipt",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "BlinkReceipt",
            targets: ["BlinkReceipt"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "BlinkReceipt",
            path: "BlinkReceipt.xcframework"
        )
    ]
)
