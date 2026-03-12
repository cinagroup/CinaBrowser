// Copyright 2024 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_LIBTESS2_LIBTESS2_TESS_ASSERT_H_
#define THIRD_PARTY_LIBTESS2_LIBTESS2_TESS_ASSERT_H_

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

// This is an always-on replacement for debug-only assert(). Internally, it
// calls Cinaseek's CHECK().
//
// This only provides a declaration in the header for C compatibility.
void tess_assert(int conditional);

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // THIRD_PARTY_LIBTESS2_LIBTESS2_TESS_ASSERT_H_
