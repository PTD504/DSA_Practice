#include <string>
#include <iostream>
#include <cmath>

class Solution {
public:
    bool isValid(std::string s) {
        int sz = s.size();
        std::string prefix = "";
        
        for (int i = 0; i < sz; ++i) {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[') {
                prefix += s[i];
            }
            else if (prefix.size() == 0)
                return false;
            else if (abs(s[i] - prefix.back()) > 2) return false;
            else prefix.pop_back();
        }
        
        return prefix.size() == 0;
    }
};