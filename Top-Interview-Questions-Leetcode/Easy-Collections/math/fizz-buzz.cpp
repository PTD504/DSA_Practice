#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> ans;
        
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) ans.push_back("FizzBuzz");
            else if (i % 5 == 0) ans.push_back("Buzz");
            else if (i % 3 == 0) ans.push_back("Fizz");
            else ans.push_back(std::to_string(i));
        }
        
        return ans;
    }
};