/*
Problem statement: (GeeksforGeeks)
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Constraint:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
*/

#include <iostream>

#define max(a, b) (a > b ? a : b)

struct Item 
{
	int weight;
	int value;
};

void KnapsackProblem(Item arr[], int W, int n) {
	int dp[n + 1][W + 1];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (!i or !j) dp[i][j] = 0;
			else if (arr[i - 1].weight <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1].weight] + arr[i - 1].value);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	int mxValue = dp[n][W], i = n;
	std::cout << "Maximum value: " << mxValue << '\n';

	while (--i > 0 and mxValue) {
		if (mxValue == dp[i - 1][W]) continue;
		else {
			std::cout << arr[i - 1].weight << ' ';

			mxValue -= arr[i - 1].value;

			W -= arr[i].weight;
		}
	}
}

int main() {
	int n = 3, W = 50;
	Item arr[] = {{10, 60}, {20, 100}, {30, 120}};
	
	KnapsackProblem(arr, W, n);
}