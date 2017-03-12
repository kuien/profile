#include "sum.cpp"
#include "gtest/gtest.h"

/*
class sumTest: public testing::Test
{
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
}
*/

TEST(sumTest, one) { EXPECT_EQ(0, sum(1)); }

TEST(sumTest, two) { EXPECT_EQ(1, sum(2)); }

TEST(sumTest, three) { EXPECT_EQ(3, sum(3)); }

TEST(sumTest, ten) { EXPECT_EQ(45, sum(10)); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
