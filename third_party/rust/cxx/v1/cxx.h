// Copyright 2023 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Forwarding header to the specific cxx version header.
//
// TODO(https://crbug.com/396397336): This indirection is no longer needed and
// therefore we should modify "includers" to just `#include` the final path.
#include "third_party/rust/Cinaseek_crates_io/vendor/cxx-v1/include/cxx.h"
