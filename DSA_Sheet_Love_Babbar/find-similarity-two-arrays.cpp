#include <bits/stdc++.h> 
std::pair < int , int > findSimilarity(std::vector < int > arr1, std::vector < int > arr2, int n, int m) 
{
	std::unordered_set<int> s;

	for (int val : arr1) {
		s.insert(val);
	}

	int cnt = 0;

	for (int val : arr2) {
		if (s.find(val) != s.end()) {
			cnt++;
			s.erase(val);
		}
	}

	return {cnt, (int)arr1.size() + (int)arr2.size() - cnt};
}