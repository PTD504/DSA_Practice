from typing import List

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        # Bài toán cho một mảng số nguyên, yêu cầu xác định xem số lượng giá trị xuất hiện của các phần tử riêng biệt (distinct value) trong mảng có đôi một phân biệt hay không (unique occurence)?

        # Với bài này, chúng ta đơn giản là sử dụng bảng băm (dictionary trong Python), duyệt qua mảng đầu vào đếm tần suất xuất hiện của mỗi giá trị riêng biệt trong mảng, sau đó so sánh các giá trị tần xuất này đôi một với nhau, nếu tất cả đều đôi một khác nhau thì trả về True, ngược lại trả về False

        num_occurs = {}

        for num in arr:
            if num in num_occurs:
                num_occurs[num] += 1
            else:
                num_occurs[num] = 1
        
        distinct_num_occurs = set()
        for value in num_occurs.values():
            if value in distinct_num_occurs:
                return False
            distinct_num_occurs.add(value)
        
        return True