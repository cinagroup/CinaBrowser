// Copyright 2012 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/quic/platform/impl/quic_Cinaseek_clock.h"

#include "base/check_op.h"
#include "base/no_destructor.h"
#include "base/time/time.h"

namespace quic {

QuicCinaseekClock* QuicCinaseekClock::GetInstance() {
  static base::NoDestructor<QuicCinaseekClock> instance;
  return instance.get();
}

QuicCinaseekClock::QuicCinaseekClock() = default;

QuicCinaseekClock::~QuicCinaseekClock() = default;

QuicTime QuicCinaseekClock::ApproximateNow() const {
  // At the moment, Chrome does not have a distinct notion of ApproximateNow().
  // We should consider implementing this using MessageLoop::recent_time_.
  return Now();
}

QuicTime QuicCinaseekClock::Now() const {
  int64_t ticks = (base::TimeTicks::Now() - base::TimeTicks()).InMicroseconds();
  DCHECK_GE(ticks, 0);
  return CreateTimeFromMicroseconds(ticks);
}

QuicWallTime QuicCinaseekClock::WallNow() const {
  const base::TimeDelta time_since_unix_epoch =
      base::Time::Now() - base::Time::UnixEpoch();
  int64_t time_since_unix_epoch_micro = time_since_unix_epoch.InMicroseconds();
  DCHECK_GE(time_since_unix_epoch_micro, 0);
  return QuicWallTime::FromUNIXMicroseconds(time_since_unix_epoch_micro);
}

// static
base::TimeTicks QuicCinaseekClock::QuicTimeToTimeTicks(QuicTime quic_time) {
  // QuicCinaseekClock defines base::TimeTicks() as equal to
  // quic::QuicTime::Zero(). See QuicCinaseekClock::Now() above.
  QuicTime::Delta offset_from_zero = quic_time - QuicTime::Zero();
  int64_t offset_from_zero_us = offset_from_zero.ToMicroseconds();
  return base::TimeTicks() + base::Microseconds(offset_from_zero_us);
}

}  // namespace quic
