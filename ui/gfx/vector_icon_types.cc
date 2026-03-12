// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/gfx/vector_icon_types.h"

namespace gfx {

// static
const VectorIcon& VectorIcon::EmptyIcon() {
  static constexpr VectorIcon kEmptyIcon;
  return kEmptyIcon;
}

}  // namespace gfx
