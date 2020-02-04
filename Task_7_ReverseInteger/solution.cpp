#include "solution.hpp"
#include <iterator>

string Solution::longestPalindrome(string s)
{
    if(s.length() <= 1)
        return s;

    string max = s.substr(0, 1);

    for(int i = 0; i < s.length(); ++i)
    {
        string temp = expand(s, i, i);
        if(temp.length() > max.length())
            max = temp;

        temp = expand(s, i, i+1);
        if(temp.length() > max.length())
            max = temp;
    }

    return max;
}

string Solution::expand(string t_s, int t_left, int t_right)
{
    while(t_left >= 0 && t_right <= t_s.length() - 1 && t_s[t_left] == t_s[t_right])
    {
        --t_left;
        ++t_right;
    }

    return t_s.substr(t_left + 1, t_right - t_left - 1);
}
