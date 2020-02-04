// tests.cpp
#include "solution.hpp"
#include <gtest/gtest.h>
 
TEST(LongestPalindromicSubstring, TrivialCases) 
{ 

    Solution s;

    ASSERT_EQ("bab", s.longestPalindrome("babad"));
    ASSERT_EQ("bb", s.longestPalindrome("cbbd"));
}

TEST(LongestPalindromicSubstring, EntireStringPalindrome)
{
    Solution s;

    ASSERT_EQ("a", s.longestPalindrome("a"));
    ASSERT_EQ("ikarlapalraki", s.longestPalindrome("ikarlapalraki"));
    ASSERT_EQ("elfukladalkufle", s.longestPalindrome("elfukladalkufle"));
    ASSERT_EQ("nawijajiwan", s.longestPalindrome("nawijajiwan"));
}
 

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}