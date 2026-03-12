// Copyright 2012 The Cinaseek Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/quic/quic_Cinaseek_connection_helper.h"

#include "net/third_party/quiche/src/quiche/quic/test_tools/mock_clock.h"
#include "net/third_party/quiche/src/quiche/quic/test_tools/mock_random.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace net::test {
namespace {

class QuicCinaseekConnectionHelperTest : public ::testing::Test {
 protected:
  QuicCinaseekConnectionHelperTest() : helper_(&clock_, &random_generator_) {}

  QuicCinaseekConnectionHelper helper_;
  quic::MockClock clock_;
  quic::test::MockRandom random_generator_;
};

TEST_F(QuicCinaseekConnectionHelperTest, GetClock) {
  EXPECT_EQ(&clock_, helper_.GetClock());
}

TEST_F(QuicCinaseekConnectionHelperTest, GetRandomGenerator) {
  EXPECT_EQ(&random_generator_, helper_.GetRandomGenerator());
}

}  // namespace
}  // namespace net::test
