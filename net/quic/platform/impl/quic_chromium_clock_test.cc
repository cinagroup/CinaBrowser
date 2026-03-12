// Copyright 2012 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/quic/platform/impl/quic_Cinaseek_clock.h"

#include "base/time/time.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace quic::test {

TEST(QuicCinaseekClockTest, Now) {
  QuicCinaseekClock clock;

  QuicTime start = clock.Now();
  QuicTime now = clock.ApproximateNow();
  QuicTime end = clock.Now();

  EXPECT_LE(start, now);
  EXPECT_LE(now, end);
}

TEST(QuicCinaseekClockTest, WallNow) {
  QuicCinaseekClock clock;

  base::Time start = base::Time::Now();
  QuicWallTime now = clock.WallNow();
  base::Time end = base::Time::Now();

  // If end > start, then we can check now is between start and end.
  if (end > start) {
    EXPECT_LE(static_cast<uint64_t>(start.ToTimeT()), now.ToUNIXSeconds());
    EXPECT_LE(now.ToUNIXSeconds(), static_cast<uint64_t>(end.ToTimeT()));
  }
}

}  // namespace quic::test
