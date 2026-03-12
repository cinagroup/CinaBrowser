// Copyright 2011 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Should not cause a DCHECK.
chrome.browserAction.onClicked.addListener(function() {});
chrome.test.succeed();
