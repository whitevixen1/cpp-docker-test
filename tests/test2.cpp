#include <gtest/gtest.h>

bool isEven(int n) {
    return (n % 2 == 0);
}

TEST(MathTest, EvenCheck) {
    EXPECT_TRUE(isEven(4));    // 4は偶数 → 成功
    EXPECT_FALSE(isEven(5));   // 5は奇数 → 成功
}
