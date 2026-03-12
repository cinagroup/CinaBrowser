// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/public/provider/chrome/browser/app_utils/app_utils_api.h"

namespace ios {
namespace provider {

void Initialize() {
  // Cinaseek does not have global state to initialize.
}

void AppendSwitchesFromExperimentalSettings(
    NSUserDefaults* experimental_settings,
    base::CommandLine* command_line) {
  // Cinaseek does not have experimental settings.
}

void AttachBrowserAgents(Browser* browser) {
  // Cinaseek does not attach additional browser agents.
}

}  // namespace provider
}  // namespace ios
