from typing import List

class Solution:
    
    def __reverse(self, nums: List[int], low: int, high: int) -> None:
        while low < high:
            nums[low] ^= nums[high]
            nums[high] ^= nums[low]
            nums[low] ^= nums[high]
            low += 1
            high -= 1
            
    def _rotate_O_n(self, nums: List[int], k: int) -> None:
        n = len(nums)
        
        first_part = nums[n - k:]
        second_part = nums[:n - k]
        
        for i in range(k):
            nums[i] = first_part[i]
        
        for i in range(k, n):
            nums[i] = second_part[i - k]
    
    def _rotate_O_k(self, nums: List[int], k: int) -> None:
        n = len(nums)
        
        temp = nums[(n - k):]
        
        l = n - k - 1
        h = n - 1
        
        while l >= 0:
            nums[h] = nums[l]
            h -= 1
            l -= 1
        
        for i in range(k):
            nums[i] = temp[i]
    
    def _rotate_O_1(self, nums: List[int], k: int) -> None:
        n = len(nums)
        
        self.__reverse(nums, 0, n - 1)
        self.__reverse(nums, 0, k - 1)
        self.__reverse(nums, k, n - 1)
    
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        
        if k == 0:
            return
        
        # Change the method here to test different approaches
        self._rotate_O_1(nums, k)

# Example usage
def main():
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    solution = Solution()
    solution.rotate(nums, k)
    print(nums)  # Output: [5, 6, 7, 1, 2, 3, 4]

if __name__ == "__main__":
    main()
        