/*
###########################################
Source: CSES

Problem statement:
Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
INPUT:
The only input line contains an integer n.

OUTPUT:
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

Constraints:
1 <= n <= 10^6

Solution: PTD504
###########################################
*/

#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n; cin>>n;
	if (n < 3){
		cout << "NO";
		return 0;
	}
	if (n & 1){
		ll temp = n - 3;
		if (temp % 4 == 0){
			cout << "YES" << '\n';
			ll j = 4;
			temp += 3;
			if (j < temp){
				cout << n / 2 + 1 << '\n';
				cout << 1 << " " << 2 << " ";
				ll i = 4, dem = 0, var = 0;
				while(dem < (temp - 3) / 4){
					cout << i << " " << temp - var++ << " ";
					dem++, i++;
				}
				cout << '\n' << n / 2 << '\n';
				cout << 3 << " ";
				dem = 0;
				while(dem < (temp - 3) / 4){
					cout << i << " " << temp - var++ << " ";
					dem++, i++;
				}
			}
			else
				cout << 2 << '\n' << 1 << " " << 2 << '\n' << 1 << '\n' << 3;
		}
		else
			cout << "NO";
	}
	else{
		if (n % 4 != 0)
			cout << "NO";
		else{
			cout << "YES" << '\n' << n / 2 << '\n';
			ll i;
			for (i = 1; i <= n / 4; ++i)
				cout << i << " " << n + 1 - i << " ";
			cout << '\n' << n / 2 << '\n';
			for (; i <= n / 2; ++i)
				cout << i << " " << n + 1 - i << " ";
		}
	}
}