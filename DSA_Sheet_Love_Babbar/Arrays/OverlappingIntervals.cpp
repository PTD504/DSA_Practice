/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Constraints:
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 1000

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

class Solution {
public:
    std::vector<std::vector<int>> overlappedInterval(std::vector<std::vector<int>>& intervals) {
         std::sort(intervals.begin(), intervals.end());
         std::vector<std::vector<int> > ans;
         ans.push_back(intervals[0]);

         for (int i = 1; i < intervals.size(); ++i) {
             if (ans.back()[1] < intervals[i][0]) ans.push_back(intervals[i]);
             else if (ans.back()[1] >= intervals[i][0] and ans.back()[1] <= intervals[i][1]) {
                 ans.back()[1] = intervals[i][1];
             }
         }

         return ans;
    }
};

int main() {
	std::vector<std::vector<int> > intervals = {
        {1, 5}, {4, 7}, {10, 12}, {15, 20}, {18, 22},
        {25, 30}, {28, 32}, {35, 40}, {38, 42}, {45, 50},
        {48, 55}, {60, 65}, {64, 70}, {72, 75}, {80, 85},
        {84, 90}, {95, 150}, {99, 105}, {110, 115}, {112, 120},
        {125, 130}, {128, 135}, {140, 145}, {150, 155}, {160, 165}
    };

    Solution obj;

    for (auto v : obj.overlappedInterval(intervals)) {
        for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';
    }
}