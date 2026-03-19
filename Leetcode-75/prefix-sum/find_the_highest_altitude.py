from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        # Bài toán yêu cầu tìm điểm có độ cao lớn nhất trong quá trình người di chuyển từ điểm 1 đến điểm n + 1. Ở mỗi lượt di chuyển, độ cao sẽ được cộng dồn với giá trị ở giữa hai điểm - được lưu trữ trong mảng gain
        # Như vậy, chúng ta chỉ cần khởi tạo một biến sumGain để lưu trữ độ cao (sau khi đã cộng dồn từ thời điểm xuất phát đến thời điểm hiện tại) ở điểm hiện tại, giá trị lớn nhất mà sumGain có được trong quá trình người này di chuyển chính là đáp án.
        sumGain = 0
        maxGain = 0

        for altitude in gain:
            sumGain += altitude
            maxGain = max(maxGain, sumGain)
        
        return maxGain