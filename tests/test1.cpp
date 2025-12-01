#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(MathTest, Addition) {
    EXPECT_EQ(add(2, 3), 5);   // 2+3=5 → 成功
    EXPECT_EQ(add(-1, 1), 0);  // -1+1=0 → 成功
}
