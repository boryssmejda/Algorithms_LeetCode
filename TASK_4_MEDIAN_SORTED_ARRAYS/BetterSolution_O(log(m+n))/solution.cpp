#include "solution.hpp"
#include <vector>


double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int size_total = nums1.size() + nums2.size();
    vector<int> result(size_total);

    auto leftVect = nums1.begin();
    auto rightVect = nums2.begin();

    int currentIndex = 0;
    while(leftVect != nums1.end() && rightVect != nums2.end())
    {
        if(*leftVect < *rightVect)
        {
            result[currentIndex] = *leftVect;
            ++leftVect;
        }else
        {
            result[currentIndex] = *rightVect;
            ++rightVect;
        }

        ++currentIndex;
    }

    while(leftVect != nums1.end())
    {
        result[currentIndex++] = *leftVect;
        ++leftVect;
    }
    while(rightVect != nums2.end())
    {
        result[currentIndex++] = *rightVect;
        ++rightVect;
    }
    double median{0};
    if (size_total % 2 == 0)
    {
        median = (result[size_total/2] + result[size_total/2 - 1])/2.0;
    }
    else
    {
        median = result[size_total/2];
    }
    
    return median;
}