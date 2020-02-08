#include <string>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>

class Solution {

public:
    int myAtoi(std::string str);
    
private:
    bool isEmpty(std::string t_str);
    bool startsWithNumber(std::string t_str);
    int overflowCase(bool t_isNegative);

};