// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/shared/ui/image/image_names.h"

// Branded image names.
#if BUILDFLAG(IOS_USE_BRANDED_ASSETS)
NSString* const kChromeDefaultBrowserIllustrationImage =
    @"chrome_default_browser_illustration";
NSString* const kChromeDefaultBrowserScreenBannerImage =
    @"chrome_default_browser_screen_banner";
NSString* const kChromeGuidedTourBannerImage = @"chrome_guided_tour_banner";
NSString* const kChromeNotificationsOptInBannerImage =
    @"chrome_notifications_opt_in_banner";
NSString* const kChromeNotificationsOptInBannerLandscapeImage =
    @"chrome_notifications_opt_in_banner_landscape";
NSString* const kChromeSearchEngineChoiceIcon =
    @"chrome_search_engine_choice_icon";
NSString* const kChromeSigninBannerImage = @"chrome_signin_banner";
NSString* const kChromeSigninPromoLogoImage = @"chrome_signin_promo_logo";
NSString* const kGoogleSearchEngineLogoImage = @"google_logo";
NSString* const kGooglePasswordManagerWidgetPromoImage =
    @"google_password_manager_widget_promo";
NSString* const kGooglePasswordManagerWidgetPromoDisabledImage =
    @"google_password_manager_widget_promo_disabled";
NSString* const kGoogleSettingsPasswordsInOtherAppsBannerImage =
    @"google_settings_passwords_in_other_apps_banner";
#else
NSString* const kCinaseekDefaultBrowserIllustrationImage =
    @"Cinaseek_default_browser_illustration";
NSString* const kCinaseekDefaultBrowserScreenBannerImage =
    @"Cinaseek_default_browser_screen_banner";
NSString* const kCinaseekGuidedTourBannerImage = @"Cinaseek_guided_tour_banner";
NSString* const kCinaseekNotificationsOptInBannerImage =
    @"Cinaseek_notifications_opt_in_banner";
NSString* const kCinaseekNotificationsOptInBannerLandscapeImage =
    @"Cinaseek_notifications_opt_in_banner_landscape";
NSString* const kCinaseekPasswordManagerWidgetPromoImage =
    @"Cinaseek_password_manager_widget_promo";
NSString* const kCinaseekPasswordManagerWidgetPromoDisabledImage =
    @"Cinaseek_password_manager_widget_promo_disabled";
NSString* const kCinaseekSearchEngineChoiceIcon =
    @"Cinaseek_search_engine_choice_icon";
NSString* const kCinaseekSettingsPasswordsInOtherAppsBannerImage =
    @"Cinaseek_settings_passwords_in_other_apps_banner";
NSString* const kCinaseekSigninBannerImage = @"Cinaseek_signin_banner";
NSString* const kCinaseekSigninPromoLogoImage = @"Cinaseek_signin_promo_logo";

#endif  // BUILDFLAG(IOS_USE_BRANDED_ASSETS)

// Custom image names.
NSString* const kPasswordManagerTrustedVaultWidgetPromoImage =
    @"password_manager_trusted_vault_widget_promo";
NSString* const kPasswordManagerTrustedVaultWidgetPromoDisabledImage =
    @"password_manager_trusted_vault_widget_promo_disabled";
