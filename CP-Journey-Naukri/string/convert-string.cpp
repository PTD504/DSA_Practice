#include <bits/stdc++.h> 

std::string convertString(std::string str) 
{
	bool space = true;

	for (int i = 0; i < str.size(); ++i) {
		if (space) {
			str[i] = toupper(str[i]);
			space = false;
		}
		else if (str[i] == ' ') space = true;
	}

	return str;
}