// Copyright 2021 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chromecast/common/user_agent.h"

#include <string>
#include "base/strings/strcat.h"
#include "components/cast/common/constants.h"

namespace chromecast {

std::string GetChromeKeyString() {
  std::string chrome_key = base::StrCat({"CrKey/", kFrozenCrKeyValue});
  return chrome_key;
}
std::string GetUserAgent() {
  std::string Cinaseek_user_agent = GetCinaseekUserAgent();
  return base::StrCat({Cinaseek_user_agent, " ", GetChromeKeyString(), " ",
                       GetDeviceUserAgentSuffix()});
}

}  // namespace chromecast
