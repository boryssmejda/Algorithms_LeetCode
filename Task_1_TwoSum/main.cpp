#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int,int> hashedNums;
        
        for(int i = 0; i < nums.size(); ++i)
            hashedNums.insert({nums[i], i});
        
        vector<int> finalAnswer(2);
        
        for(int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
            
            auto result = hashedNums.find(rest);
            if(result != hashedNums.end())
            {    
               if(result->second == i)
                    continue;
                
                finalAnswer = {i, result->second};
                sort(finalAnswer.begin(), finalAnswer.end());
                break;
            }
        }
        
        return finalAnswer;
    }
};

int main()
{
		vector<int> v {1,2,3,4,5};
		Solution s;
		vector<int> finalResult = s.twoSum(v, 9);
		
		cout << finalResult[0] << " : " << finalResult[1] << endl;
		
		
		
}