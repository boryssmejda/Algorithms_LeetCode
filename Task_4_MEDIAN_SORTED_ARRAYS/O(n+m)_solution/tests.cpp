// tests.cpp
#include "solution.hpp"
#include <gtest/gtest.h>
#include <vector> 

TEST(LongestSubstringTest, AllCharsDifferent) 
{ 

    Solution s;

    {
        vector<int> a {1, 3};
        vector<int> b {2};
        ASSERT_DOUBLE_EQ(2.0, s.findMedianSortedArrays(a, b));
    }
    {
        vector<int> a {1, 3};
        vector<int> b {2, 4};
        ASSERT_DOUBLE_EQ(2.5, s.findMedianSortedArrays(a, b));
    }

     {
        vector<int> a {1, 3 , 5};
        vector<int> b {2, 4};
        ASSERT_DOUBLE_EQ(3.0, s.findMedianSortedArrays(a, b));
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}