/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a string str, find the longest palindromic substring in str. Substring of string str: str[ i . . . . j ] where 0 ≤ i ≤ j < len(str). Return the longest palindromic substring of str.

Palindrome string: A string that reads the same backward. More formally, str is a palindrome if reverse(str) = str. In case of conflict, return the substring which occurs first ( with the least starting index).

Constraints:
1 ≤ |str| ≤ 10^3

Solution: PTD504
###########################################
*/

#include <iostream>

class Solution {
public:
    std::string longestPalin (std::string S) {
        int n = (int)S.size();
        int first = 0, second = 0;
        int tempf, temps;
        for (int i = 0; i < n; ++i){
            tempf = i - 1, temps = i + 1;
            while(tempf >= 0 && temps < n){
                if (S[tempf] == S[temps]){
                    if (temps - tempf > second - first)
                        first = tempf, second = temps;
                    tempf--, temps++;
                }
                else
                    break;
            }
            tempf = i, temps = i + 1;
            while(tempf >= 0 && temps < n){
                if (S[tempf] == S[temps]){
                    if (temps - tempf > second - first)
                        first = tempf, second = temps;
                    tempf--, temps++;
                }
                else
                    break;
            }
        }
        std::string ans = "";
        for (int i = first; i <= second; ++i)
            ans += S[i];
        return ans;
    }
};

int main() {
	std::string s = "zxcvbnmasdfghjklqwertyuioppoiuytrewqlkjhgfdsvbmamnbvcxz";

    Solution obj;

    std::cout << obj.longestPalin(s);
}