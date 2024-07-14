/*
Source: CSES Problem Set

Problem statement: 
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.

Constraints
1 <= n <= 10^6
*/

#include <iostream>
#include <cstring>

#define min(a, b) (a < b ? a : b)

int recursiveApproach(int n, int dp[]) {
	if (n < 10) return dp[n] = 1;
	if (dp[n] + 1) return dp[n];

	int ans = 1e6 + 1, temp = n;

	while (temp) {
		int digit = temp % 10;
		temp /= 10;
		if (!digit) continue;
		ans = min(ans, recursiveApproach(n - digit, dp));
	}

	return dp[n] = ans + 1;
}

int iterativeApproach(int n, int dp[]) {
	dp[0] = 0;

	for (int i = 1, temp; i <= n; ++i) {
		temp = i;
		dp[i] = 1e6 + 1;
		while (temp) dp[i] = min(dp[i], dp[i - temp % 10]), temp /= 10;
		dp[i] += 1;
	}

	return dp[n];
}

int RemovingDigits(int N) {
	int dp[N + 1];
	memset(dp, -1, sizeof(dp));

	srand(unsigned(time(NULL)));

	if (rand() & 1) return recursiveApproach(N, dp);
	else return iterativeApproach(N, dp);
}

int main() {
	int N = 4534; // std::cin >> N;
	std::cout << RemovingDigits(N);
}