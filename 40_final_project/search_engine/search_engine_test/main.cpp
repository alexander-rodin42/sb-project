#include <iostream>

#include "gtest/gtest.h"

TEST(sample_test_case, sample_test) {
    EXPECT_EQ(1,1);
}

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
