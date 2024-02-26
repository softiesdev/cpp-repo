#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(AnotherTest, Basic) { EXPECT_GE(69, 1); }

TEST(AnotherTest, Basic2) { EXPECT_GE(420, 67); }

TEST(AnotherTest, BasicFailing) { EXPECT_EQ(69, 420); }
