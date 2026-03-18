from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        # Tương tự với bài Maximum Consecutive Ones III, chúng ta sẽ phát biểu bài toán ban đầu thành một bài toán có thể áp dụng kỹ thuật sliding window một cách rõ ràng như sau: tìm mảng con dài nhất có số lượng phần tử 0 trong mảng không vượt quá 1 (lúc này, nếu có 1 phần tử 0 trong mảng con cuối cùng thì ta chỉ cần bỏ phần tử này đi là sẽ có một mảng toàn 1, còn nếu không có phần tử 0 nào thì ta chỉ cần bỏ 1 phần tử 1 bất kỳ, dù là cách nào thì subarray thu được cũng thỏa mãn yêu cầu đề bài)

        # Cách triển khai hoàn toàn tương tự bài Maximum Consecutive Ones III, cũng vẫn là điểm lưu ý khi ta không cố định kích thước cửa sổ nữa mà chỉ cập nhật điểm bắt đầu của cửa sổ khi số lượng 0 trong cửa sổ hiện tại đã vượt quá 1.
        countZero = 0
        maxLength = 0
        startZero = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                countZero += 1
            
            while countZero > 1:
                if nums[startZero] == 0:
                    countZero -= 1
                startZero += 1
            
            maxLength = max(maxLength, i - startZero + 1)
        
        # Lưu ý trả về giá trị maxLength - 1 vì đề bài yêu cầu chúng ta cần xóa một phần tử trong mảng con cuối cùng.
        return maxLength - 1