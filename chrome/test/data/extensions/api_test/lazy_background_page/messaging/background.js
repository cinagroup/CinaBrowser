// Copyright 2012 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

chrome.runtime.onConnect.addListener(function(port) {
  port.onMessage.addListener(function(msg) {
    chrome.test.notifyPass();
  });
});
