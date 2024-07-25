#include <iostream>
#include <vector>

namespace Sorting {
	// In this namespace, I will implement some common sort algorithm, the time complexity of each algorithm is considered on average case.
	namespace SelectionSort 
	{
		template <typename T>
		void sort(std::vector<T> &arr) {
			int _size = arr.size();

			// The main idea of the selection sort algorithm is to repeatedly find the minimum (or maximum) element from the unsorted portion of the array
			// and move it to the beginning (or end) of the sorted portion. This process continues until the entire array is sorted.

			// Time complexity: O(N * N), where N is the size of the array
			// Auxiliary Space: O(1)

			for (auto i = 0, idx = i; i < _size - 1; ++i, idx = i) {
				T min_cur = arr[idx];
				for (auto j = i + 1; j < _size; ++j) {
					idx = (min_cur < arr[j] ? idx : j);
					min_cur = (min_cur < arr[j] ? min_cur : arr[j]);
				}
				std::swap(arr[i], arr[idx]);
			}
		}
	}

	// Not true
	namespace BubbleSort
	{
		template <typename T>
		void sort(std::vector<T> &arr) {
			int _size = arr.size();

			// Bubble sort algorithm works by repeatedly std::swapping the adjacent elements if they are in the wrong order.

			// Time complexity: O(N * N), where N is the size of the array
			// Auxiliary space: O(1)

			for (auto i = 0; i < _size; ++i) {
				for (auto j = 0; j < _size - i - 1; ++j) {
					if (arr[j] > arr[j + 1])
						std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	namespace InsertionSort
	{
		template <typename T>
		void sort(std::vector<T> &arr) {
			int _size = arr.size();

			// Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into 
			// its correct position in a sorted portion of the list. It is a stable sorting algorithm, 
			// meaning that elements with equal values maintain their relative order in the sorted output.

			// Time complexity: O(N * N), where N is the size of the array 
			// Auxiliary space: O(1)

			for (auto i = 1; i < _size; ++i) {
				T temp = arr[i];
				auto j = i - 1;

				while (j >= 0 and temp < arr[j]) {
					arr[j + 1] = arr[j];
					j--;
				}

				arr[j + 1] = temp;
			}
		}
	}

	namespace MergeSort
	{
		template <typename T>
		void merge(std::vector<T> &arr, int l, int m, int h) {
			T temp[h - l + 1];
			int i = l, j = m, k = 0;
         
			while (i < m and j < h + 1) {
				if (arr[i] > arr[j]) temp[k++] = arr[j++];
				else temp[k++] = arr[i++];
			}
         
			while (i < m) temp[k++] = arr[i++];
			while (j < h + 1) temp[k++] = arr[j++];
         
			for (i = 0; i < h - l + 1; ++i) arr[i + l] = temp[i];
		}

		template <typename T>
		void mergeSort(std::vector<T> &arr, int l, int h) {
			if (l >= h) return;

			int m = l + ((h - l) >> 1);

			// Sort the subarray arr[l..m]
			mergeSort(arr, l, m);
			// Sort the subarray arr[m + 1..h]
			mergeSort(arr, m + 1, h);
			// Merge two sorted subarrays arr[l..m] and subarray[m + 1..h] into one subarray arr[l..h], this large subarray will be sorted during 
			// the merging.
			merge(arr, l, m + 1, h);
		}

		template <typename T>
		void sort(std::vector<T> &arr) {

			// Merge sort is a sorting algorithm that follows the divide-and-conquer approach. 
			// It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then 
			// merging them back together to obtain the sorted array.

			// Time complexity: O(N * log(N)), where N is the size of the array
			// Auxiliary space: O(N)

			mergeSort(arr, 0, arr.size() - 1);
		}
	}

	namespace QuickSort
	{
		template <typename T>
		void quickSort(std::vector<T> &arr, int l, int h) {
			if (l >= h) return;

			int i = l, j = h;
			auto x = arr[i + ((j - i) >> 1)];

			while (i < j) {

				while (arr[i] < x) i++;
				while (arr[j] > x) j--;

				if (i <= j) {
					std::swap(arr[i], arr[j]);
					i++;
					j--;
				}
			}

			if (j > l) quickSort(arr, l, j);
			if (i < h) quickSort(arr, i, h);
		}


		template <typename T>
		void sort(std::vector<T> &arr) {

			// QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot 
			// and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

			// Time complexity: O(N * log(N)) 
			// Auxiliary complexity: O(1), if we don’t consider the recursive stack space.

			quickSort(arr, 0, arr.size() - 1);
		}
	}

	namespace HeapSort
	{
		template <typename T>
		void heapify(std::vector<T> &arr, int N, int root) {
			int mx = root, left = (mx << 1) + 1, right = (mx << 1) + 2;

			if (left < N and arr[left] > arr[mx]) mx = left;
			if (right < N and arr[right] > arr[mx]) mx = right;

			if (mx != root) {
				std::swap(arr[mx], arr[root]);
				heapify(arr, N, mx);
			}
		}

		template <typename T>
		void sort(std::vector<T> &arr) {
			int _size = arr.size();

			// Heap sort is a comparison-based sorting technique based on Binary Heap data structure. 
			// It is similar to the selection sort where we first find the minimum element and place 
			// the minimum element at the beginning. Repeat the same process for the remaining elements.

			// Build max heap from original array
			for (auto i = (_size >> 1) - 1; i >= 0; --i) heapify(arr, _size, i);
			
			// Extract element from max heap (one by one).
			for (auto i = _size - 1; i > 0; --i) {
				std::swap(arr[i], arr[0]);

				heapify(arr, i, 0);
			}
		}
	}
}
