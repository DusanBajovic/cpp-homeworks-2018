#include <gtest/gtest.h>

#include <./digit_counting.h>

TEST(TestDigitCounting, ReturnTrue) {
  EXPECT_EQ(true, ReturnTrue());
}

TEST(TestDigitCounting, TestWarp)
{
  EXPECT_EQ(0.125, Warp(0.125, 3));
  EXPECT_NE(0.125, Warp(0.125, 3000000000000000000));
}

TEST(TestDigitCounting, TestCountSameSignificantDigitsSameNumbers)
{
  EXPECT_EQ(100, CountSameSignificantDigits(3.12, 3.12));
  EXPECT_EQ(100, CountSameSignificantDigits(10230258, 10230258));
  EXPECT_EQ(100, CountSameSignificantDigits(0.123456789125, 0.123456789125));
  EXPECT_EQ(100, CountSameSignificantDigits(78569354123.123456789125, 78569354123.123456789125)); 
}

TEST(TestDigitCounting, TestCountSameSignificantDigitsDifferentNumbers)
{
  EXPECT_EQ(0, CountSameSignificantDigits(-526.158, 10.2589)); 
  EXPECT_GT(100, CountSameSignificantDigits(3.12, 3.22));
  EXPECT_GT(100, CountSameSignificantDigits(10256, 5296));
  EXPECT_GT(100, CountSameSignificantDigits(10256, 256));
  EXPECT_GT(100, CountSameSignificantDigits(0.58964, 0.6894478));
  EXPECT_GT(100, CountSameSignificantDigits(56980.58964, 980.589));
}