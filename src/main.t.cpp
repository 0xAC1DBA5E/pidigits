#include "pidigits.hpp"
#include "gtest/gtest.h"

TEST(pidigits, calculations) {
  EXPECT_EQ(0x243f6a88, pi16(0));
  EXPECT_EQ(0x43f6a888, pi16(1));
  EXPECT_EQ(0x3f6a8885, pi16(2));
  EXPECT_EQ(0xf6a8885a, pi16(3));
  EXPECT_EQ(0x6a8885a3, pi16(4));
  EXPECT_EQ(0x26C65E52, pi16(999999));
  EXPECT_EQ(0x6C65E52C, pi16(1000000));
  EXPECT_EQ(0xC65E52CB, pi16(1000001));
  EXPECT_EQ(0x65E52CB4, pi16(1000002));
  EXPECT_EQ(0x5E52CB45, pi16(1000003));
}
