from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # Chúng ta sẽ sử dụng kỹ thuật sliding window (cửa sổ trượt) cho các dạng bài toán duyệt mảng theo đừng đoạn có độ dài cố định cho trước như bài này.

        # Bắt đầu bằng việc khởi tạo một biến start - lưu trữ phần tử đầu tiên của "cửa sổ" (dãy con gồm các phần tử liên tiếp với độ dài là k) đang xét.
        # Biến maxSum sẽ có nhiệm vụ lưu giá trị lớn nhất của tổng các phần tử trong toàn bộ cửa sổ tạo được, khởi tạo bằng giá trị sum của cửa sổ đầu tiên (dãy con đầu tiên với độ dài k)
        start = 0
        maxSum = curSum = sum(nums[:k])

        # Sau đó, chúng ta sẽ khởi tạo vòng lặp for bắt đầu xét từ phần tử đầu tiên nằm ngoài dãy con đã tính tổng phía trên, tức là phần tử thứ k + 1 (chỉ số là k)
        for i in range(k, len(nums)):
            # Trong mỗi vòng lặp như vậy, ta chỉ cần thêm phần tử đang xét vào tổng hiện có, loại bỏ phần tử đầu tiên của cửa sổ trước là ta đã có được tổng của cửa sổ tiếp theo
            # Tính nhanh tổng của cửa sổ vừa có và cập nhật giá trị của maxSum
            curSum += nums[i] - nums[start]
            maxSum = max(curSum, maxSum)
            start += 1
        
        # Trả về giá trị trung bình, ở đây giá trị trung bình lớn nhất sẽ phụ thuộc vào tổng lớn nhất tìm được
        return maxSum / k