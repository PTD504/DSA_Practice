#include <bits/stdc++.h> 

int largestElement(std::vector<int> &arr, int n) {
    int mx = 0;

    for (int i : arr) {
        mx = mx < i ? i : mx;
    }

    return mx;
}
