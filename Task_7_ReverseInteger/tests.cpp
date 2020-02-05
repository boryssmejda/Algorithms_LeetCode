// tests.cpp
#include "solution.hpp"
#include <gtest/gtest.h>
#include <climits>
 
TEST(ReverseInteger, PositiveNumbers) 
{ 

    Solution s;

    ASSERT_EQ(321, s.reverse(123));
    ASSERT_EQ(456, s.reverse(654));
    ASSERT_EQ(0, s.reverse(0));
    ASSERT_EQ(9, s.reverse(9));
}

TEST(ReverseInteger, PalindromicPositiveNumbers)
{
    Solution s;
    ASSERT_EQ(999, s.reverse(999));
    ASSERT_EQ(101, s.reverse(101));
}

TEST(ReverseInteger, NegativeNumber)
{
    Solution s;
    ASSERT_EQ(-123, s.reverse(-321));
    ASSERT_EQ(-456, s.reverse(-654));
}

TEST(ReverseInteger, PalindromicNegativeNumbers)
{
    Solution s;
    ASSERT_EQ(-999, s.reverse(-999));
    ASSERT_EQ(-101, s.reverse(-101));
}

TEST(ReverseInteger, SkippingZeroes)
{
    Solution s;
    ASSERT_EQ(21, s.reverse(120));
    ASSERT_EQ(99, s.reverse(990));
}


TEST(ReverseInteger, Overflow)
{
    Solution s;
    ASSERT_EQ(0, s.reverse(INT_MIN));
    ASSERT_EQ(0, s.reverse(INT_MAX));
} 

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}