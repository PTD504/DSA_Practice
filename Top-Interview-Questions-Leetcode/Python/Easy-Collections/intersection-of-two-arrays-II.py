from typing import List

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        # If both arrays are sorted, we can use two pointers to find the intersection.
        # return self.intersect_sorted(nums1, nums2)

        intersect = []
        unordered_map = {}
        
        for val in nums1:
            if val in unordered_map:
                unordered_map[val] += 1
            else:
                unordered_map[val] = 1
        
        for val in nums2:
            if val in unordered_map:
                if unordered_map[val] > 0:
                    intersect.append(val)
                    unordered_map[val] -= 1
        
        return intersect
    
    def intersect_sorted(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersect = []
        n1, n2 = len(nums1), len(nums2)
        i1, i2 = 0, 0
        
        while i1 < n1 and i2 < n2:
            if nums1[i1] == nums2[i2]:
                intersect.append(nums1[i1])
                i1 += 1
                i2 += 1
            elif nums1[i1] > nums2[i2]:
                i2 += 1
            else:
                i1 += 1
        
        return intersect

def main():
    # Example usage
    nums1 = [1, 2, 4, 4, 5, 5, 5, 5, 6, 7, 8, 8, 8, 8, 9]
    nums2 = [1, 4, 4, 5, 6, 6, 7, 8, 9, 9]
    solution = Solution()
    result = solution.intersect(nums1, nums2)
    print(result)

if __name__ == "__main__":
    main()