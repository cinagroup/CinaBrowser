// Copyright 2010 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// Notify the extension needs to show the page action icon.
chrome.runtime.sendMessage({msg: "feedIcon"});
