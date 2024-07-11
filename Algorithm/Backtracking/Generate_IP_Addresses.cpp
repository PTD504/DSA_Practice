/*
###########################################
Source: GeeksforGeeks

Problem statement:
Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Constraints:
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>

const int MAXVALUE = 255;

class Solution{
public:
    std::vector<std::string> ans;

    int stoi(std::string s) {
        int num = 0;

        for (char ch : s) num = num * 10 + (ch - '0');

        return num;
    }

    bool checkAnswer(std::vector<std::string> &ips, const std::string& s) {
        for (int i = 0; i < 4; ++i) {
            if (ips[i].size() > 1 and ips[i][0] == '0') return false;
        }

        std::string validIp = ips[0] + "." + ips[1] + "." + ips[2] + "." + ips[3];

        if (validIp.size() > s.size() + 3) return false;

        ans.push_back(validIp);

        return true;
    } 

    void recursion(const std::string &s, std::vector<std::string>& ips, int idx_s, int idx_curIp) {
        
        for (int i = idx_s; i < s.size() and ips[idx_curIp].size() < 3; ++i) {
            ips[idx_curIp] += s[i];

            if (stoi(ips[idx_curIp]) > 255) {
                ips[idx_curIp] = "";
                return;
            }

            if (idx_curIp < 3) recursion(s, ips, i + 1, idx_curIp + 1);
            else {
                if (i < s.size() - 1) continue;
                auto t = checkAnswer(ips, s);

                if (!t) {
                    ips[idx_curIp] = "";
                    return;
                }
            }
        }

        ips[idx_curIp] = "";
    }    

    std::vector<std::string> genIp(std::string &s) {
        std::vector<std::string> ips(4, "");

        recursion(s, ips, 0, 0);

        return ans;
    }
};

int main() {
    std::string s = "123211211"; // std::cin >> s;

    Solution obj;

    for (auto str : obj.genIp(s)) {
        std::cout << str << '\n';
    }
}