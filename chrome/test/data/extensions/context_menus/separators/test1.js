// Copyright 2010 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Create a bunch of items with no explicit parent.
createTestSet(null, function() {
  chrome.test.sendMessage("test1 create finished");
});
