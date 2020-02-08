// tests.cpp
#include "solution.hpp"
#include <gtest/gtest.h>
#include <climits>
 
class SolutionTest: public ::testing::Test
{
    protected:
    void SetUp() override {}
    void TearDown() override {}

    Solution s;
};


TEST_F(SolutionTest, EmptyString) 
{ 
    EXPECT_EQ(s.myAtoi(""), 0);
    EXPECT_EQ(s.myAtoi("       "), 0);
    EXPECT_EQ(s.myAtoi("\t\t\t    \t \t \r  \n"), 0);
}

TEST_F(SolutionTest, OnlyPlusMinus) 
{ 
    EXPECT_EQ(s.myAtoi("+"), 0);
    EXPECT_EQ(s.myAtoi("-"), 0);
    EXPECT_EQ(s.myAtoi("     -  "), 0);
    EXPECT_EQ(s.myAtoi("\t\t\t  +  \t \t \r  \n"), 0);
    EXPECT_EQ(s.myAtoi("   +"), 0);
    EXPECT_EQ(s.myAtoi("   -"), 0);
    EXPECT_EQ(s.myAtoi("-   "), 0);
    EXPECT_EQ(s.myAtoi("+   "), 0);
}
    

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}