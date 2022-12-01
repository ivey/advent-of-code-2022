#include "libpart2.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part2Test, Test1) {
    EXPECT_EQ(2,2);
}

class FooTest : public ::testing::Test {
    protected:
        void SetUp() override {
            std::cout << "setup\n";
        }

        void TearDown() override {
            std::cout << "teardown\n";
        }
};

TEST_F(FooTest, Test1) {
    EXPECT_EQ(1,1);
    EXPECT_EQ(1,1);
    EXPECT_EQ(1,1);
    EXPECT_EQ(1,1);
    EXPECT_EQ(1,1);
    EXPECT_EQ(1,1);
    EXPECT_EQ(1,1);
}