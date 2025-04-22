from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n = len(nums)
        
        for i in range(1, n):
            j = i
            
            while j >= 1:
                if nums[j - 1] == nums[j]:
                    return True
                elif nums[j - 1] < nums[j]:
                    break
                else:
                    nums[j] ^= nums[j - 1]
                    nums[j - 1] ^= nums[j]
                    nums[j] ^= nums[j - 1]
                
                j -= 1
        
        return False

# Example usage
def main():
    solution = Solution()
    nums = [2, 3, 1, 4, 5, 6, 1, 7, 3]
    print(solution.containsDuplicate(nums))  # Output: True

if __name__ == "__main__":
    main()