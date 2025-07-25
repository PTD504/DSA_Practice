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

	namespace QuickSelect
	{
		// This function partitions the array around a pivot, moving elements greater than the pivot to the left.
		template<typename T>
		int partition(std::vector<T> &arr, int l, int h, const T &pivot) {
			int store_index = l;

			for (int i = l; i <= h; ++i) {
				if (arr[i] > pivot) { // Change the condition to < if you want to find the k-th smallest element
					std::swap(arr[i], arr[store_index]);
					store_index++;
				}
			}

			return store_index;
		}

		// The QuickSelect algorithm is a selection algorithm to find the k-th smallest element in an unordered list.
		// Below are two implementations: one recursive and one iterative.
		
		// Recursive implementation
		template<typename T>
		T quickSelect(std::vector<T> &arr, int l, int h, const int &k) {
			if (l == h) return arr[l];

			int pivot_index = rand() % (h - l + 1) + l;
			pivot_index = partition(arr, l, h, arr[pivot_index]);

			if (k == pivot_index) 
				return arr[k];
			else if (k < pivot_index) 
				return quickSelect(arr, l, pivot_index - 1, k);
			else 
				return quickSelect(arr, pivot_index + 1, h, k);
		}

		// Iterative implementation
		template<typename T>
		T quickSelect_iterative(std::vector<T> &arr, int l, int h, const int &k) {
			while (l < h) {
				int pivot_index = rand() % (h - l + 1) + l;
				pivot_index = partition(arr, l, h, arr[pivot_index]);

				if (k == pivot_index)
					return arr[k];
				else if (k < pivot_index) 
					h = pivot_index - 1;
				else 
					l = pivot_index + 1;
			}

			return arr[l];
		}

		template<typename T>
		T search(std::vector<T> &arr, const int &k) {
			if (k < 0 || k >= arr.size()) {
				throw std::out_of_range("Index k is out of bounds of the array.");
			}

			// Randomly shuffle the array to ensure average-case performance
			std::random_device rd;
			std::mt19937 g(rd());
			std::shuffle(arr.begin(), arr.end(), g);

			return quickSelect(arr, 0, arr.size() - 1, k);

			// Time Complexity: O(N) on average, O(N^2) in the worst case
			// Auxiliary space: O(1)
		}
	}
}