// tests.cpp
#include "solution.hpp"
#include <gtest/gtest.h>
 
TEST(LongestSubstringTest, AllCharsDifferent) 
{ 

    Solution s;

    ASSERT_EQ(5, s.lengthOfLongestSubstring("abcde"));
    ASSERT_EQ(1, s.lengthOfLongestSubstring("s"));
    ASSERT_EQ(10, s.lengthOfLongestSubstring("borysantek"));
}
 
TEST(LongestSubstringTest, CharRepetition)
{
    Solution s;

    ASSERT_EQ(3, s.lengthOfLongestSubstring("abcabcbb"));
    ASSERT_EQ(1, s.lengthOfLongestSubstring("bbbbb"));
    ASSERT_EQ(3, s.lengthOfLongestSubstring("pwwkew"));
}


TEST(LongestSubstringTest, CheckingSetClearance)
{
    Solution s;

    ASSERT_EQ(3, s.lengthOfLongestSubstring("dvdf"));
    ASSERT_EQ(5, s.lengthOfLongestSubstring("abcagh"));
    ASSERT_EQ(5, s.lengthOfLongestSubstring("ckilbkd"));
    ASSERT_EQ(7, s.lengthOfLongestSubstring("wobgrovaw"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}