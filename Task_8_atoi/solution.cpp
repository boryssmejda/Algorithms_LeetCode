#include "solution.hpp"
#include <climits>
#include <cctype>

using std::string;

int Solution::myAtoi(std::string str)
{
    if(isEmpty(str))
        return 0;

    int firstNonEmptyPos{-1};
    for(int i = 0; i < str.length(); ++i)
    {
        if(isalnum(str[i]))
        {
            firstNonEmptyPos = i;
            break;
        }
    }

    bool isNegative{false};
    if(str[firstNonEmptyPos] == '-')
    {
        ++firstNonEmptyPos;
        isNegative = true;
    }
    else if(str[firstNonEmptyPos] == '+')
    {
        ++firstNonEmptyPos;
        isNegative = false;
    }


    int result{0};
    for(int i = firstNonEmptyPos; i < str.length(); ++i)
    {

    }

    return -1;
}

bool Solution::isEmpty(std::string str)
{
    if(str == "")
        return true;

    for(const auto& ch: str)
        if(isalnum(ch) || ch == '+' || ch == '-')
            return false;
    
    return true;
}