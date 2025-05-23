#include <iostream>
#include <vector>

class Solution {
private:
    
    void assign_vector(std::vector<int>& begin, std::vector<int>& end) {
        end.push_back(begin[0]);
        for (int i = 0; i < begin.size() - 1; ++i) {
            end.push_back(begin[i + 1] + begin[i]);
        }
        end.push_back(begin.back());
    }
    
public:
    std::vector<std::vector<int>> generate(int numRows) {        
        std::vector<std::vector<int> > triangle = {{1}};
        std::vector<int> f = {1};
        std::vector<int> s;
        bool check = true;
        
        for (int i = 2; i <= numRows; ++i) {
            if (check) {
                assign_vector(f, s);
                f.clear();
                triangle.push_back(s);
            }
            else {
                assign_vector(s, f);
                s.clear();
                triangle.push_back(f);
            }
            check ^= 1;
        }
        
        return triangle;
    }
};