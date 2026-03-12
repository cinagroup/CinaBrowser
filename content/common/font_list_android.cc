// Copyright 2013 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/common/font_list.h"

#include <memory>

#include "base/values.h"

namespace content {

base::ListValue GetFontList_SlowBlocking() {
  return base::ListValue();
}

}  // namespace content
