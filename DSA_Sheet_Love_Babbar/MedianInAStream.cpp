/*
###########################################
Source: Naukri

Problem statement:
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.

Constraints:
1 <= T <= 10
1 <= N <= 10^4
0 <= data <= 10^8
Where T is the number of test cases, N is the number of elements in the data stream.

Solution: PTD504
###########################################
*/

#include <iostream>
#include <vector>
#include <set>

std::multiset<int> head, tail;

void InsertIntoTwoSets(int val, int sz) {
	if (head.size() < sz / 2) {
		if (tail.size() == 0)
			head.insert(val);
		else {
			if (*tail.begin() < val) {
				head.insert(*tail.begin());
				tail.erase(tail.find(*tail.begin()));
				tail.insert(val);
			}
			else 
				head.insert(val);
		}
	} else {
		if (*head.rbegin() > val) {
			tail.insert(*head.rbegin());
			head.erase(head.find(*head.rbegin()));
			head.insert(val);
		} else
			tail.insert(val);
  }
}

int findMedianOfSingleArray(int m) {
	if (m & 1) return *tail.begin();
	else return (*head.rbegin() + *tail.begin()) / 2;
}

std::vector<int> findMedian(std::vector<int> &arr, int n){
	
	std::vector<int> ans;

	head.clear();
	tail.clear();

	ans.push_back(arr[0]);
	tail.insert(arr[0]);

	for (int i = 1; i < n; ++i) {
		InsertIntoTwoSets(arr[i], i + 1);
		ans.push_back(findMedianOfSingleArray(i + 1));
	}

	return ans;
}

int main() {
    int n = 20;

	std::vector<int> arr = {19, 41, 4, 25, 17, 4, 20, 25, 35, 42, 4, 35, 15, 40, 29, 10, 3, 28, 26, 19, 32, 45, 31, 44, 3, 31, 41, 34, 29, 32};

    auto ans = findMedian(arr, n);

    for (auto i : ans) std::cout << i << ' ';
}