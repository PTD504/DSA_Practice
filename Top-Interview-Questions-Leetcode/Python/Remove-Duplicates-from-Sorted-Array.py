from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l, sz = 1, len(nums)
        cnt, cur = 1, nums[0]
        
        for h in range(1, sz):
            if nums[h] != cur:
                nums[l] = nums[h]
                l += 1
                cur = nums[h]
                cnt += 1
        
        return cnt

# Example usage
def main():
    nums = [1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 5, 6, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10, 10]
    solution = Solution()
    length = solution.removeDuplicates(nums)
    print(f"Length of array after removing duplicates: {length}")
    print(f"Modified array: {nums[:length]}")

if __name__ == "__main__":
    main()