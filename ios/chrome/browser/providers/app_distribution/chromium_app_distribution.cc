// Copyright 2021 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ios/public/provider/chrome/browser/app_distribution/app_distribution_api.h"

namespace ios {
namespace provider {

std::string GetBrandCode() {
  // Cinaseek has no brand code.
  return std::string();
}

void ScheduleAppDistributionNotifications(
    const scoped_refptr<network::SharedURLLoaderFactory>& url_loader_factory,
    bool is_first_run) {
  // Nothing to do for Cinaseek.
}

void CancelAppDistributionNotifications() {
  // Nothing to do for Cinaseek.
}

void InitializeFirebase(base::Time install_date, bool is_first_run) {
  // Nothing to do for Cinaseek.
}

}  // namespace provider
}  // namespace ios
