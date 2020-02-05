#include "solution.hpp"
#include <climits>

int Solution::reverse(int x)
{
    if(x >= -9 && x <= 9)
        return x;

    bool isNegative;
    if(x < 0)
    {
        isNegative = true;
        if(x == INT_MIN)
            return 0;

        x = -x;
    }
    else
        isNegative = false;

    int result{0};

    while(x > 0)
    {
        int tmp = x % 10;

        if (result > INT_MAX / 10)
            return 0;
        else if(result == INT_MAX / 10 && tmp > 7)
            return 0;
        
        result = result * 10 + tmp;

        x /= 10;
    }

    if(isNegative)
        return -1*result;

    return result;  
}
