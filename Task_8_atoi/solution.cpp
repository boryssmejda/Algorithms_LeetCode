#include "solution.hpp"
#include <climits>
#include <cctype>

using std::string;

int Solution::myAtoi(std::string str)
{
    if(isEmpty(str))
        return 0;

    //Find first number, or number's sign +/-
    int firstNonEmptyPos{-1};
    for(int i = 0; i < static_cast<int>(str.length()); ++i)
    {
        if(isdigit(str[i]) || str[i] == '-' || str[i] == '+')
        {
            firstNonEmptyPos = i;
            break;
        }
        else if(str[i] == ' ')
            continue;
        else
            return 0;
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
    else if(isdigit(str[firstNonEmptyPos]))
    {
        isNegative = false;
    }
    else
    {
        return 0;
    }
    

    //Actual string to number conversion
    int result{0};
    for(int i = firstNonEmptyPos; i < static_cast<int>(str.length()); ++i)
    {
        if(!isdigit(str[i]))
            return (isNegative ? -result : result);

        int tmp = static_cast<int>(str[i] - '0');
        if(result > INT_MAX/10)
        {
            return overflowCase(isNegative);
        }
        else if(result == INT_MAX / 10 && tmp > 7)
        {
            return overflowCase(isNegative);
        }

        result = result * 10 + tmp;
    }

    return (isNegative ? -result : result);
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

inline int Solution::overflowCase(bool t_isNegative)
{
    if(t_isNegative)
        return INT_MIN;

    return INT_MAX;
}