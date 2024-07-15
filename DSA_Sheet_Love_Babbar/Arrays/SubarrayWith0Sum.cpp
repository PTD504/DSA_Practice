/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

Constraints:
1 <= n <= 10^4
-10^5 <= a[i] <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <unordered_map>

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        std::unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0, sum = 0; i < n; ++i) {
            sum += arr[i];
            if (mp[sum]) return true;
            else mp[sum] = 1;
        }

        return false;
    }
};

int main() {
    int n = 30;
	int arr[] = {30, 13, 19, -27, -47, 24, -47, -18, -19, -9, -6, 16, -1, 41, -20, -26, -9, 6, 3, 27, -37, -18, 26, -6, -7, 6, 15, 25, -26, -44, -15, -42, 3, -18, 23, 46};

    Solution obj;
    
    if (obj.subArrayExists(arr, n)) std::cout << "There is at least one subarray with zero sum in the array \'arr\'";
    else std::cout << "There is no subarray with zero sum in the array \'arr\'";
}