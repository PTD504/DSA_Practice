#include <bits/stdc++.h> 

std::string stringSum(std::string &num1, std::string &num2) {
    int n1 = num1.size() - 1, n2 = num2.size() - 1, r = 0, s = 0;
    std::string sum = "";

    while (n1 > -1 and n2 > -1) {
        s = (num1[n1--] - '0') + (num2[n2--] - '0') + r;
        r = s / 10;
        s %= 10;

        sum += char(s + '0');
    }

    while (n1 > -1) {
        s = (num1[n1--] - '0') + r;
        r = s / 10;
        s %= 10;

        sum += char(s + '0');
    }

    while (n2 > -1) {
        s = (num2[n2--] - '0') + r;
        r = s / 10;
        s %= 10;

        sum += char(s + '0');
    }

    if (r) sum += '1';

    std::reverse(sum.begin(), sum.end());

    return sum;
}