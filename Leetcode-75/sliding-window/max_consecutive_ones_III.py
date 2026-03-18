from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        # Ý tưởng của bài toán vẫn là áp dụng kỹ thuật sliding window, tuy nhiên chúng ta sẽ không giải bài toán cũ mà thay thế bằng một bài toán tương đương như sau: tìm độ dài dãy con lớn nhất có số lượng 0 <= k -> Đây cũng chính là đáp án của bài toán.

        # Sau khi đã định nghĩa lại bài toán theo hướng quen thuộc, chúng ta cũng sẽ giải với ý tưởng của sliding window như các bài trước (maximum average subarray hay max vowel). Khởi tạo một biến startZero giữ phần tử đầu của cửa sổ, biến countZero để đếm phần tử 0 có trong cửa sổ hiện tại và phần tử maxLength để lưu trữ cửa sổ có số lượng 0 <= k lớn nhất.
        # Một điểm khác biệt ở bài này là ta sẽ không còn lưu giữ cố định chiều dài cửa sổ là một số cho trước nữa mà chỉ cập nhật khi số lượng phần tử 0 có trong cửa sổ vượt quá k.
        startZero = 0
        countZero, maxLength = 0, 0

        for i in range(len(nums)):
            if nums[i] == 0:
                countZero += 1
            if countZero > k:
                while startZero <= i:
                    if nums[startZero] == 0:
                        countZero -= 1
                        startZero += 1
                        break
                    startZero += 1
            maxLength = max(maxLength, i - startZero + 1)
        
        return maxLength