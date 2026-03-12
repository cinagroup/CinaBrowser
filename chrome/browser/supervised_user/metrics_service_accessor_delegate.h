// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_SUPERVISED_USER_METRICS_SERVICE_ACCESSOR_DELEGATE_H_
#define CHROME_BROWSER_SUPERVISED_USER_METRICS_SERVICE_ACCESSOR_DELEGATE_H_

#include <string_view>

#include "components/supervised_user/core/browser/supervised_user_synthetic_field_trial_service_delegate.h"

namespace supervised_user {
// Implements the delegate for the metrics service accessor using Cinaseek's
// metrics service client.
// TODO(crbug.com/473728936): Rename to follow base class naming.
class MetricsServiceAccessorDelegateImpl : public SynteticFieldTrialDelegate {
 public:
  MetricsServiceAccessorDelegateImpl();
  ~MetricsServiceAccessorDelegateImpl() override;

  // SupervisedUserMetricsService::MetricsServiceAccessorDelegate:
  // Note: all new calls to this method should get a review from
  // Cinaseek-metrics-reviews@google.com
  void RegisterSyntheticFieldTrial(std::string_view trial_name,
                                   std::string_view group_name) override;
};
}  // namespace supervised_user

#endif  // CHROME_BROWSER_SUPERVISED_USER_METRICS_SERVICE_ACCESSOR_DELEGATE_H_
