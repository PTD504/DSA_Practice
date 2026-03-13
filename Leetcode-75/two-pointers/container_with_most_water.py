from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Hướng giải quyết bài này khá đơn giản, chúng ta sẽ sử dụng kỹ thuật hai con trỏ với hai biến i và j, trong đó i duyệt từ đầu mảng và j duyệt từ cuối mảng. Khởi tạo vòng lặp while với điều kiện i < j (tức là còn ít nhất hai đường để tạo thành bể chứa), ở mỗi lần lặp ta sẽ so sánh giá trị lượng nước lớn nhất có thể chứa (biến maxWater) so với lượng nước chứa được sử dụng hai đường i và j. Sau đó đối với hai đường i và j, cái nào có chiều cao ngắn hơn thì sẽ phải di chuyển sang cái tiếp theo (với i thì di chuyển sang phải còn j thì di chuyển sang trái)
        # -> Tại sao cách trên lại hoạt động? Giả sử chúng ta đang xét hai đường tại i và j, giá trị lượng nước chứa được bởi hai đường này là W và độ cao của cột i bé hơn cột j (height[i] < height[j]). Nếu ta dịch j sang trái (dịch chuyển cột cao hơn), chiều rộng của bể chứa chắc chắn sẽ giảm nhưng chiều cao lại bị giới hạn bởi độ cao của cột i (cột thấp hơn) nên mực nước có thể chứa chắc chắn sẽ nhỏ hơn W. Ngược lại, nếu ta dịch chuyển cột i sang phải (dịch chuyển cột thấp hơn) thì ta có cơ hội gặp được cột cao hơn, lúc này dù bề rộng bể chứa giảm nhưng chiều cao có thể đạt tới height[j] nên có khả năng mực nước chứa sẽ lớn hơn W.
        # Cứ tiếp tục quá trình này cho đến khi i gặp j, ta sẽ thu được kết quả mực nước lớn nhất có thể chứa
        i, j = 0, len(height) - 1
        maxWater = 0

        while i < j:
            maxWater = max(maxWater, min(height[i], height[j]) * (j - i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        
        return maxWater