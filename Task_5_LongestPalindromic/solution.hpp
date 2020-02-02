#include <string>

using std::string;

class Solution {

private:
    string expand(string t_s, int t_left, int t_right);

public:
    string longestPalindrome(string s);
};