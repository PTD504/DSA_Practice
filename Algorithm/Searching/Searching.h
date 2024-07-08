#include <iostream>
#include <vector>

namespace Searching
{
	// In this namespace, I will implement some search algorithms that will find the index of the first occurrence of a key in an array.
	// For search algorithms that require the array to be sorted, I assume that the input array is already sorted in ascending order.

	namespace LinearSeach 
	{
		template <typename T>
		int search(const std::vector<T> &arr, const T key) {
			int _size = arr.size();

			// The main idea of the linear search algorithm is to traverse the array element by element 
			// from the beginning to the end, comparing each element with the target value until the target is found
			// or the end of the list is reached.

			for (auto i = 0; i < _size; ++i) 
				if (arr[i] == key) return i;
			
			return -1; // return -1 if the key does not exist in the array.

			// Time Complexity: O(N), where N is the size of the array 
			// Auxiliary space: O(1)
		}
	}

	namespace BinarySearch
	{
		template <typename T> 
		int search(const std::vector<T> &arr, const T key) {
			int l = 0, h = arr.size() - 1, ans = -1;

			// The main idea of binary search is to repeatedly divide the search interval in half, 
			// eliminating half of the remaining elements from consideration each time.
			// Note: The primary condition to use binary search is that the array or list must be sorted.

			while (l <= h) {
				auto m = l + ((h - l) >> 1);

				if (arr[m] == key) {
					ans = m;
					h = m - 1;
				}
				else if (arr[m] < key) l = m + 1;
				else h = m - 1;
			}

			return ans;

			// Time Complexity: O(log(N)), where N is the size of the array
			// Auxiliary space: O(1)
		}
	}

	namespace InterpolationSearch
	{
		template <typename T>
		int search(const std::vector<T> &arr, const T key) {
			int l = 0, h = arr.size() - 1, ans = -1;

			// The main idea is to use the interpolation formula (Công thức nội suy) to guess where the target might be,
			// rather than consistently dividing the search interval in half as in binary search.

			// Note: Similar to binary search algorithm, the primary condition to use this algorithm is that the array or list must be sorted 
			// (in ascending order in this case).

			while (l <= h and arr[l] <= key and arr[h] >= key) {
				if (l == h) {
					ans = (arr[l] == key ? l : -1);
					break;
				}

				int m = l + ((double)(h - l) / (arr[h] - arr[l]) * (key - arr[l]));

				if (arr[m] == key) {
					ans = m;
					h = m - 1;
				}
				else if (arr[m] > key) h = m - 1;
				else l = m + 1;
			}

			return ans;

			// Time Complexity: O(log(log(N))), where N is the size of the array
			// Auxiliary space: O(1)
		}
	}
}