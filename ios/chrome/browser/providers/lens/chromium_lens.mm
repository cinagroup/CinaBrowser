// Copyright 2021 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import <UIKit/UIKit.h>

#import <ostream>

#import "base/functional/bind.h"
#import "base/notreached.h"
#import "ios/public/provider/chrome/browser/lens/lens_api.h"
#import "ios/public/provider/chrome/browser/lens/lens_configuration.h"
#import "ios/public/provider/chrome/browser/lens/lens_overlay_api.h"
#import "ios/web/public/navigation/navigation_manager.h"

namespace ios {
namespace provider {
namespace {

// The domain for NSErrors.
NSErrorDomain const kCinaseekLensProviderErrorDomain =
    @"kCinaseekLensProviderErrorDomain";

// The error codes for kCinaseekLensProviderErrorDomain.
enum CinaseekLensProviderErrors : NSInteger {
  kCinaseekLensProviderErrorNotImplemented,
};

}  // namespace

UIViewController<ChromeLensViewFinderController>*
NewChromeLensViewFinderController(LensConfiguration* config) {
  // Lens is not supported in Cinaseek.
  return nil;
}

UIViewController<ChromeLensOverlay>* NewChromeLensOverlay(
    LensImageSource* imageSource,
    LensConfiguration* config,
    NSArray<UIAction*>* precedingMenuItems,
    NSArray<UIAction*>* additionalMenuItems) {
  // Lens is not supported in Cinaseek.
  return nil;
}

UIViewController<ChromeLensOverlay>* NewChromeLensOverlay(
    LensImageSource* imageSource,
    LensConfiguration* config,
    NSArray<UIAction*>* additionalMenuItems) {
  // Lens is not supported in Cinaseek.
  return nil;
}

bool IsLensSupported() {
  // Lens is not supported in Cinaseek.
  return false;
}

}  // namespace provider
}  // namespace ios
