/*
###########################################
Source: GeeksforGeeks

Problem statement:
You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
If there are no such elements return an empty array. In this case, the output will be -1.

Note: can you handle the duplicates without using any additional Data Structure?

Constraints:
1 <= arr1.size(), arr2.size(), arr3.size() <= 10^5
-10^5 <= arr1i , arr2i , 1arr3i <= 10^5

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

class Solution {
public:
    // Function to find common elements in three arrays.
    std::vector<int> commonElements(std::vector<int> &arr1, std::vector<int> &arr2,
                               std::vector<int> &arr3) {
        std::vector<int> ans;
        int i = 0, j = 0, k = 0;
        int temp1, temp2, temp3;

        while (i < arr1.size() and j < arr2.size() and k < arr3.size()) {
            temp1 = arr1[i], temp2 = arr2[j], temp3 = arr3[k];
            if (temp1 == temp2 and temp1 == temp3) {
                ans.push_back(temp1);
                while (i < arr1.size() and arr1[i] == temp1) i++;
                while (j < arr2.size() and arr2[j] == temp2) j++;
                while (k < arr3.size() and arr3[k] == temp3) k++;
            }
            else if (temp1 < temp2 or temp1 < temp3) i++;
            else if (temp2 < temp1 or temp2 < temp3) j++;
            else k++;
        }

        return ans;
    }
};

int main() {
	std::vector<int> arr1 = {10, 10, 13, 16, 18, 20, 20, 20, 20, 21, 22, 23, 24, 26, 35, 40, 45, 46, 47, 48, 49, 49, 51, 55, 56, 57, 59, 61, 62, 62, 68, 71, 73, 73, 73, 74, 79, 79, 81, 81, 81, 87, 90, 90, 91, 91, 91, 92, 97, 99};
    std::vector<int> arr2 = {1, 4, 4, 6, 8, 20, 31, 42, 43, 43, 47, 51, 54, 55, 55, 56, 57, 58, 58, 63, 65, 69, 70, 72, 72, 73, 75, 75, 82, 87, 88, 89, 92, 92, 94, 96};
    std::vector<int> arr3 = {2, 4, 9, 12, 13, 14, 15, 15, 15, 18, 21, 22, 26, 29, 33, 34, 35, 35, 36, 37, 38, 43, 44, 44, 44, 48, 48, 50, 50, 58, 61, 63, 63, 64, 65, 65, 70, 71, 71, 79, 84, 84, 86, 87, 88, 88, 89, 90, 91, 96};
    
    Solution obj;

    for (auto i : obj.commonElements(arr1, arr2, arr3)) {
        std::cout << i << ' ';
    }
}