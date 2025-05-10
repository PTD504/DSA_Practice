#include <iostream>
#include <vector>
#include <random>

class Solution {
private:
    
    std::vector<int> origin;
    std::mt19937 gen;
    
public:
    Solution(std::vector<int>& nums) : origin(nums), gen(std::random_device()()) {}
    
    std::vector<int> reset() {
        return this->origin;
    }
    
    std::vector<int> shuffle() {
        int sz = this->origin.size();
        std::uniform_int_distribution<> distrib;

        std::vector<int> nums(origin.begin(), origin.end());

        for (int i = sz - 1, idx; i >= 0; --i) {
            distrib.param(std::uniform_int_distribution<>::param_type(0, i));
            idx = distrib(gen);
            std::swap(nums[i], nums[idx]);
        }

        return nums;
    }
    
    // Alternative implementation using rand()
    std::vector<int> shuffle_rand() {
        int sz = this->origin.size();
        std::vector<int> nums = origin;
        
        for (int i = sz - 1, idx; i >= 0; --i) {
            idx = rand() % (i + 1);
            std::swap(nums[idx], nums[i]);
        }
        
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */