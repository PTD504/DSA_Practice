from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        """
        Giải thích bài toán: Cho một mảng số nguyên candies, phần tử thứ i đại diện cho số kẹo của bạn nhỏ thứ i đang có. Một số nguyên extraCandies đại diện cho số kẹo mà bạn đang giữ. Yêu cầu là trả về một mảng result chứa kiểu giá trị boolean, phần tử thứ i có giá trị là True nếu sau khi bạn đưa toàn bộ số kẹo đang có (extraCandies) cho đứa trẻ thứ i thì đứa trẻ này có số kẹo lớn nhất trong số các đứa trẻ.

        Hướng giải quyết bài toán: Tìm phần tử lớn nhất hiện tại của mảng candies. Sau đó khởi tạo vòng lặp for xét duyệt từng phần tử trong mảng candies, khi xét đến một phần tử i nào đó, chúng ta sẽ cộng giá trị candies[i] hiện tại (là số kẹo hiện tại mà đứa trẻ i đang có) với số kẹo bạn đang giữ (extraCandies), nếu giá trị tổng sau khi cộng lại lớn hơn giá trị lớn nhất của mảng hiện tại thì thỏa mãn yêu cầu và giá trị của phần tử thứ i trong mảng result cuối cùng là True, ngược lại thì là False, tức là dù có đưa hết kẹo bạn đang giữ cho đứa trẻ hiện tại thì số kẹo mà đứa trẻ này có cũng ít hơn số kẹo mà (những) đứa trẻ có số kẹo lớn nhất hiện tại đang giữ.
        """
        max_candies = max(candies)
        result = []

        for candy_number in candies:
            if candy_number + extraCandies >= max_candies:
                result.append(True)
            else:
                result.append(False)
        
        return result