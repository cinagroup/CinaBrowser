// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/common/swift/features.h"

BASE_FEATURE(kSwiftCoordinator, base::FEATURE_DISABLED_BY_DEFAULT);

bool IsSwiftCoordinatorEnabled() {
  return base::FeatureList::IsEnabled(kSwiftCoordinator);
}
