#include "solution.hpp"
#include <unordered_map>

int Solution::lengthOfLongestSubstring(string s)
{
    std::unordered_map<char, int> allCharsPresentBefore;
    int maxLength = 0;
    int currentLength = 0;
    int seqBeginning = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        const auto element = allCharsPresentBefore.find(s[i]);
        if(element == allCharsPresentBefore.end())
        {
            ++currentLength;
            if(currentLength > maxLength)
                maxLength = currentLength;

        }
        else
        {   
            int foundAtPos = element->second;

            if(foundAtPos < seqBeginning)
            {
                currentLength = i - seqBeginning + 1;
            }
            else
            {
                seqBeginning = foundAtPos + 1;
                currentLength = i - seqBeginning + 1;
            }
            
        }

        if(currentLength > maxLength)
            maxLength = currentLength;

        char key = s[i];
        int value = i;
        allCharsPresentBefore[key] = value;
    }

    return maxLength;
}