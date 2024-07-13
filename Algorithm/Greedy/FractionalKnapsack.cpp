/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments above the given function.

Constraints:
1 <= n <= 10^5
1 <= w <= 10^9
1 <= valuei, weighti <= 10^4

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include "Sorting.h"

using namespace Sorting::MergeSort;

struct Item 
{
    int value;
    int weight;

    bool operator<(const Item& other) {
        return double(value * 1.0 / weight) < double(other.value * 1.0 / other.weight);
    }

    bool operator>(const Item& other) {
        return double(value * 1.0 / weight) > double(other.value * 1.0 / other.weight);
    }
};

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(std::vector<Item>& arr, int w, int n) {
        sort(arr);
        
        int i = n - 1;
        double ans = 0;
        
        while (i >= 0 and w) {
            if (w > arr[i].weight) ans += arr[i].value, w -= arr[i].weight;
            else {
                ans += w * 1.0 * arr[i].value / arr[i].weight;
                break;
            }
            i--;
        }
        
        return ans;
    }
};

int main() {
    int n = 3;
    int w = 50;
    std::vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};

    Solution obj;
    std::cout << obj.fractionalKnapsack(arr, w, n);
}