#include <gtest/gtest.h>
#include "mymath.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  // EXPECT_EQ(1 * 6, 42);
}

TEST(HelloTest, TESTHeloo) {
  EXPECT_EQ(7 * 6, 42);
}


TEST(TESTmymath, TESTmymathA) {
  EXPECT_EQ(Factorial(3), 6);
}
