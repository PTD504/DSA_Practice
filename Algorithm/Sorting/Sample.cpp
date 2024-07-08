#include "Sorting.h"
#include <vector>
#include <iostream>

// Change Sorting::DesiredAlgorithm if you want to use another sort algorithm in Sorting.h
using namespace Sorting::QuickSort;

int main() 
{
	std::vector<std::string> arr = {"123", "012", "87", "asdas", "234sdsd", "sdsdf2324", "1212asdasd", "24832dsadas"};
	sort(arr);

	for (auto element : arr)
		std::cout << element << ' ';
}
