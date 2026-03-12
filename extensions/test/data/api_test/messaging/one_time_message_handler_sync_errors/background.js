// Copyright 2025 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  throw new Error('sync error #1');
});

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  throw new Error('sync error #2');
});
