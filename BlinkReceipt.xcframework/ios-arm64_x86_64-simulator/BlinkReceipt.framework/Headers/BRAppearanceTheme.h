//
//  BRAppearanceTheme.h
//  BlinkReceipt
//
//  Public theming API for BlinkReceipt
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Identifiers for every color the SDK can resolve from your `BRAppearanceTheme`.
 *
 *  Override `-[BRAppearanceTheme colorForKey:]` and return a `UIColor`, or
 *  `nil` to keep the built-in style for that element. Each case maps to one
 *  background, text color, or icon tint in the SDK's stock scan UI.
 */
typedef NS_ENUM(NSInteger, BRAppearanceColorKey) {
    /// Tint applied to the leading icon on every row of the scan help sheet.
    BRAppearanceColorKeyHelpModalRowIcons,
    /// Title color of the "Done" button on the scan help sheet.
    BRAppearanceColorKeyHelpModalCloseButtonLabel,
    /// Background color of the "Done" button on the scan help sheet.
    BRAppearanceColorKeyHelpModalCloseButtonBackground,

    /// Background color of the "Skip" / "Back" button on each onboarding page.
    BRAppearanceColorKeyOnboardingDismissButtonBackground,
    /// Title color of the "Skip" / "Back" button on each onboarding page.
    BRAppearanceColorKeyOnboardingDismissButtonLabel,
    /// Background color of the "Next" / "Done" button on each onboarding page.
    BRAppearanceColorKeyOnboardingConfirmButtonBackground,
    /// Title color of the "Next" / "Done" button on each onboarding page.
    BRAppearanceColorKeyOnboardingConfirmButtonLabel,
    /// Active dot color of the page control on the onboarding screen.
    BRAppearanceColorKeyOnboardingCurrentPageControl,
};

/**
 *  Identifiers for every icon the SDK can resolve from your `BRAppearanceTheme`.
 *
 *  Override `-[BRAppearanceTheme imageForKey:]` and return a `UIImage`, or
 *  `nil` to keep the built-in asset. Each case lists the recommended image
 *  size in points; the stock control scales the image to fit its button if
 *  you supply a different size, so the listed size produces the cleanest
 *  result. Include @2x and @3x variants for Retina screens.
 */
typedef NS_ENUM(NSInteger, BRAppearanceIconKey) {
    /// Torch button on the camera screen, torch-off state. Recommended size: 46 × 46 pt.
    BRAppearanceIconKeyTorchButtonOff,
    /// Torch button on the camera screen, torch-on state. Recommended size: 46 × 46 pt.
    BRAppearanceIconKeyTorchButtonOn,
    /// Help / info button on the camera screen. Recommended size: 46 × 46 pt.
    BRAppearanceIconKeyInfoButton,
    /// Shutter button on the camera screen, default state. Recommended size: 98 × 98 pt.
    BRAppearanceIconKeyTakePictureButton,
    /// Shutter button on the camera screen, highlighted / pressed state. Recommended size: 98 × 98 pt.
    BRAppearanceIconKeyTakePictureButtonPressed,
    /// "Add another frame" button on the confirm screen (same control as the shutter). Recommended size: 98 × 98 pt.
    BRAppearanceIconKeyAddFrameButton,
    /// "Retake" button on the confirm screen. Recommended size: 46 × 46 pt.
    BRAppearanceIconKeyRetakeButton,
    /// "Finish" button on the confirm screen. Recommended size: 46 × 46 pt.
    BRAppearanceIconKeyFinishButton,
    /// Close (cancel) button on the camera screen. Recommended size: 46 × 46 pt.
    BRAppearanceIconKeyCloseButton,
};

/**
 *  Customizes colors and icons in the SDK's stock scan UI (help sheet,
 *  onboarding, camera toolbar, and related surfaces).
 *
 *  Subclass `BRAppearanceTheme` and override `colorForKey:` and / or
 *  `imageForKey:` to supply your own values, then assign an instance to
 *  `BRScanOptions.appearance` *before* you start a scan. Both methods use an
 *  *opt-in* model: return `nil` for any key you don't want to customize and
 *  the SDK keeps its built-in value. The base implementation returns `nil`
 *  for every key, so an unmodified `BRAppearanceTheme` is equivalent to
 *  leaving `BRScanOptions.appearance` set to `nil`.
 *
 *  The SDK queries the theme each time the relevant control is configured,
 *  so values may be read more than once per scan session and should be cheap
 *  to produce. You can swap themes between scans (for example, to react to
 *  light / dark mode) by assigning a new instance.
 *
 *  Example (Objective-C):
 *
 *      @interface MyAppearanceTheme : BRAppearanceTheme
 *      @end
 *
 *      @implementation MyAppearanceTheme
 *      - (UIColor *)colorForKey:(BRAppearanceColorKey)key {
 *          if (key == BRAppearanceColorKeyHelpModalCloseButtonBackground) {
 *              return UIColor.systemBlueColor;
 *          }
 *          return nil;
 *      }
 *      @end
 *
 *      BRScanOptions *options = [BRScanOptions new];
 *      options.appearance = [MyAppearanceTheme new];
 *
 *  Example (Swift):
 *
 *      final class MyAppearanceTheme: BRAppearanceTheme {
 *          override func color(for key: BRAppearanceColorKey) -> UIColor? {
 *              key == .helpModalCloseButtonBackground ? .systemBlue : nil
 *          }
 *      }
 *
 *      let options = BRScanOptions()
 *      options.appearance = MyAppearanceTheme()
 */
@interface BRAppearanceTheme : NSObject

/**
 *  Returns a color for the given key, or `nil` to keep the SDK default for
 *  that element.
 *
 *  Override in a subclass to supply custom colors. The base implementation
 *  always returns `nil`.
 */
- (nullable UIColor *)colorForKey:(BRAppearanceColorKey)key;

/**
 *  Returns an image for the given key, or `nil` to keep the SDK default
 *  asset.
 *
 *  Override in a subclass to supply custom icons. The base implementation
 *  always returns `nil`.
 */
- (nullable UIImage *)imageForKey:(BRAppearanceIconKey)key;

@end

NS_ASSUME_NONNULL_END
