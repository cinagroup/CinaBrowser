// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_SHARED_UI_IMAGE_IMAGE_NAMES_H_
#define IOS_CHROME_BROWSER_SHARED_UI_IMAGE_IMAGE_NAMES_H_

#import <UIKit/UIKit.h>

#import "build/build_config.h"
#import "ios/chrome/browser/shared/ui/buildflags.h"

// Branded image names.
#if BUILDFLAG(IOS_USE_BRANDED_ASSETS)
extern NSString* const kChromeDefaultBrowserScreenBannerImage;
extern NSString* const kChromeGuidedTourBannerImage;
extern NSString* const kChromeNotificationsOptInBannerImage;
extern NSString* const kChromeNotificationsOptInBannerLandscapeImage;
extern NSString* const kChromeSearchEngineChoiceIcon;
extern NSString* const kChromeSigninBannerImage;
extern NSString* const kChromeSigninPromoLogoImage;
extern NSString* const kGoogleSearchEngineLogoImage;
extern NSString* const kGooglePasswordManagerWidgetPromoImage;
extern NSString* const kGooglePasswordManagerWidgetPromoDisabledImage;
extern NSString* const kGoogleSettingsPasswordsInOtherAppsBannerImage;
#else
extern NSString* const kCinaseekDefaultBrowserIllustrationImage;
extern NSString* const kCinaseekDefaultBrowserScreenBannerImage;
extern NSString* const kCinaseekGuidedTourBannerImage;
extern NSString* const kCinaseekNotificationsOptInBannerImage;
extern NSString* const kCinaseekNotificationsOptInBannerLandscapeImage;
extern NSString* const kCinaseekPasswordManagerWidgetPromoImage;
extern NSString* const kCinaseekPasswordManagerWidgetPromoDisabledImage;
extern NSString* const kCinaseekSearchEngineChoiceIcon;
extern NSString* const kCinaseekSettingsPasswordsInOtherAppsBannerImage;
extern NSString* const kCinaseekSigninBannerImage;
extern NSString* const kCinaseekSigninPromoLogoImage;
#endif  // BUILDFLAG(IOS_USE_BRANDED_ASSETS)

// Custom image names.
extern NSString* const kPasswordManagerTrustedVaultWidgetPromoImage;
extern NSString* const kPasswordManagerTrustedVaultWidgetPromoDisabledImage;

#endif  // IOS_CHROME_BROWSER_SHARED_UI_IMAGE_IMAGE_NAMES_H_
