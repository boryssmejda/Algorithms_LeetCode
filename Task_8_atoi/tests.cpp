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

TEST_F(SolutionTest, SpecialCharactersWithNumbers) 
{ 
    EXPECT_EQ(s.myAtoi(".1"), 0);
    EXPECT_EQ(s.myAtoi(",1234"), 0);
    EXPECT_EQ(s.myAtoi("   @378"), 0);
    EXPECT_EQ(s.myAtoi(";;;190"), 0);
    EXPECT_EQ(s.myAtoi(" '+120"), 0);
    EXPECT_EQ(s.myAtoi(" \"123 "), 0);
    EXPECT_EQ(s.myAtoi("-^123   "), 0);
    EXPECT_EQ(s.myAtoi("+-5678900   "), 0);
    EXPECT_EQ(s.myAtoi("$988   "), 0);
}

TEST_F(SolutionTest, OnlyLetters) 
{ 
    EXPECT_EQ(s.myAtoi("+A"), 0);
    EXPECT_EQ(s.myAtoi("-a"), 0);
    EXPECT_EQ(s.myAtoi("     - A "), 0);
    EXPECT_EQ(s.myAtoi("\t\t\t  +B  \t \t \r  \n"), 0);
    EXPECT_EQ(s.myAtoi(" borys +"), 0);
    EXPECT_EQ(s.myAtoi(" hello  -"), 0);
    EXPECT_EQ(s.myAtoi("-niceToMeetYou   "), 0);
    EXPECT_EQ(s.myAtoi("+YouToo   "), 0);
    EXPECT_EQ(s.myAtoi("Friends   "), 0);
    EXPECT_EQ(s.myAtoi("  Friends"), 0);
}

TEST_F(SolutionTest, NumbersWithSign) 
{ 
    EXPECT_EQ(s.myAtoi("+10"), 10);
    EXPECT_EQ(s.myAtoi("-10"), -10);
    EXPECT_EQ(s.myAtoi("+505900"), 505900);
    EXPECT_EQ(s.myAtoi("-505900"), -505900);
    EXPECT_EQ(s.myAtoi("     -345 hello"), -345);
    EXPECT_EQ(s.myAtoi("  +9999  \t \t \r  \n"), 9999);
    EXPECT_EQ(s.myAtoi("  +12345"), 12345);
    EXPECT_EQ(s.myAtoi(" -123456789"), -123456789);
    EXPECT_EQ(s.myAtoi("-900001   "), -900001);
}

TEST_F(SolutionTest, NumbersNoSign) 
{ 
    EXPECT_EQ(s.myAtoi("101"), 101);
    EXPECT_EQ(s.myAtoi("990"), 990);
    EXPECT_EQ(s.myAtoi("505900"), 505900);
    
    EXPECT_EQ(s.myAtoi("     345 hello"), 345);
    EXPECT_EQ(s.myAtoi("  9999  \t \t \r  \n"), 9999);
    EXPECT_EQ(s.myAtoi("  12345"), 12345);
    EXPECT_EQ(s.myAtoi(" 123456789"), 123456789);
    EXPECT_EQ(s.myAtoi("900001   "), 900001);
}

TEST_F(SolutionTest, OverflowCases) 
{ 
    EXPECT_EQ(s.myAtoi("91283472332"), INT_MAX);
    EXPECT_EQ(s.myAtoi("-91283472332"), INT_MIN);
    EXPECT_EQ(s.myAtoi("2147483647"), INT_MAX);
    EXPECT_EQ(s.myAtoi("+2147483647"), INT_MAX);

    EXPECT_EQ(s.myAtoi("-2147483648"), INT_MIN);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}