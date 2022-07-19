#include <iostream>
#include <gtest/gtest.h>
#include "Adder/adder.h"

TEST(sampleTest, sampleTestcase) {
  EXPECT_EQ(adder(3,4), 7);
}