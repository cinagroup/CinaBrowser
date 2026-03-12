// Copyright 2024 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const worker = new Worker('post_loaded.js');
worker.addEventListener("message", (event) => {
    self.postMessage(event.data);
});
