#include "solution.hpp"
#include <vector>


double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int size_A = nums1.size();
    int size_B = nums2.size();
    double median{0};

    if(size_A < size_B)
    {
        median = search_bin(nums1, nums2);
    }
    else
    {
        median = search_bin(nums2, nums1);
    }
    
    return median;
}

double Solution::search_bin(vector<int>& shorter, vector<int>& longer)
{
    int begin = 0;
    int end = shorter.size() - 1;

    while(begin < end)
    {
        int middleElement = shorter[(begin+end)/2];
        
    }
}