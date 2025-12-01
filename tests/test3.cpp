#include <gtest/gtest.h>

TEST(SampleTest, FailureExample) {
    EXPECT_EQ(2 * 2, 5);   // わざと失敗させる
}
