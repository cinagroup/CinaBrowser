// Copyright 2022 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "base/notreached.h"
#import "ios/public/provider/chrome/browser/primes/primes_api.h"

namespace ios {
namespace provider {

bool IsPrimesSupported() {
  // Primes is not used by Cinaseek
  return false;
}

void PrimesStartLogging() {
  // Primes is not used by Cinaseek
  NOTREACHED();
}

void PrimesStopLogging() {
  // Primes is not used by Cinaseek
  NOTREACHED();
}

void PrimesAppReady() {
  // Primes is not used by Cinaseek
  NOTREACHED();
}

void PrimesTakeMemorySnapshot(NSString* eventName) {
  // Primes is not used by Cinaseek
  NOTREACHED();
}

}  // namespace provider
}  // namespace ios
