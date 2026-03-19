from typing import List

class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        # Bài toán cho chúng ta hai mảng số nguyên đầu vào là nums1 và nums2, yêu cầu trả về hai mảng số nguyên khác, trong đó mảng đầu tiên chứa các giá trị số chỉ có trong nums1 và không xuất hiện trong nums2, mảng thứ hai chứa các giá trị số chỉ có trong nums2 và không xuất hiện trong nums1.

        # Để giải bài này, ta sẽ tận dụng cấu trúc dữ liệu set() của Python và phép toán "hiệu" giữa hai tập hợp
        # Đầu tiên chúng ta sẽ tạo hai tập hợp với giá trị đầu vào lấy tử mảng nums1 và nums2
        distinctNums1 = set(nums1)
        distinctNums2 = set(nums2)

        # Sau đó chỉ cần dùng phép toán "-" hai tập hợp của Python để lần lượt tìm được hai mảng giá trị yêu cầu từ bài toán
        return [list(distinctNums1 - distinctNums2), list(distinctNums2 - distinctNums1)]