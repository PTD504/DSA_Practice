#include "Searching.h"
#include <iostream>
#include <vector>

// Change Searching::DesiredAlgorithm if you want to use another search algorithm in Searching.h
using namespace Searching::InterpolationSearch;

int main() 
{
	std::vector<short> arr = {12, 24, 25, 26, 83, 120, 220, 443, 550, 904};	
	short key1 = 120, key2 = 30;

	auto index1 = search(arr, key1);
	auto index2 = search(arr, key2);

	if (index1 + 1) 
		std::cout << "The first occurence of " << key1 << " in the array is at index " << index1;
	else 
		std::cout << key1 << " doesn't exist in the array";
}