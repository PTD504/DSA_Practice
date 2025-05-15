#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> dict = {{' ', 0},
                                         {'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C', 100},
                                         {'D', 500},
                                         {'M', 1000}};
        
        int prev = 0, cur, sum = 0;
        
        for (char ch : s) {
            cur = dict[ch];
            
            if (prev > cur) sum += prev, prev = cur;
            else if (prev == cur) prev += cur;
            else {
                prev = cur - prev;
            }
        }
        
        return sum + prev;
    }
};