from typing import List

class Solution:
    def productExceptSelfRequired(self, nums: List[int]) -> List[int]:
        # Nếu không được sử dụng phép chia, ta sẽ lưu lại hai mảng như sau:
        # mảng prefix với prefix[i] chứa tích của các phần từ trong mảng nums từ 0 đến i - 1
        # mảng suffix với suffix[i] chứa tích của các phần tử trong mảng nums từ i + 1 đên n - 1
        # Như vậy, giá trị của phần tử tại vị trí i ở mảng kết quả cuối cùng sẽ = prefix[i] * suffix[i]

        # Phần triển khai mã dưới đây tận dụng chỉ số mảng âm của Python để tiết kiệm một vòng lặp nên logic sẽ hơi khác nhưng ý tưởng đều dựa vào phương pháp trên
        prefix = [1]
        suffix = [1]

        for i in range(len(nums)):
            prefix.append(prefix[i] * nums[i])
            suffix.append(suffix[i] * nums[- (i + 1)])
        
        for i in range(len(nums)):
            nums[i] = prefix[i] * suffix[- (i + 2)]
        
        return nums

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        return self.productExceptSelfRequired(nums)

        # Time Complexity: O(n)
        # Space Complexity: O(1)
        # Hướng tiếp cận của bài này khá đơn giản, lưu ý cách dưới đây có sử dụng phép chia

        # product_array_value = tích của các phần tử khác 0 trong mảng nums
        # zero_count = số lượng phần tử bẳng 0 trong mảng nums
        product_array_value = 1
        zero_count = 0
        
        # Chúng ta lặp qua các phần tử của mảng đầu vào, mỗi lần lặp qua chúng ta làm hai việc:
        # kiểm tra xem phần tử hiện tại có bằng 0 để cập nhật zero_count
        # Nếu khác 0 thì cập nhật product_array_value
        for num in nums:
            if num == 0:
                zero_count += 1
            else:
                product_array_value *= num
        
        # Nếu số lượng phần tử bằng 0 trong mảng lớn hơn 1 thì trả về kết quả một mảng toàn 0
        if zero_count > 1:
            for i in range(len(nums)):
                nums[i] = 0
            return nums
        # Còn nếu chỉ có một phần tử duy nhất = 0 trong mảng thì giá trị tại phần tử này ở mảng kết quả chính là product_array_value, các phần tử khác trong mảng kết quả sẽ là 0
        elif zero_count == 1:
            for i in range(len(nums)):
                nums[i] = 0 if nums[i] != 0 else product_array_value
            return nums
        # Nếu mảng đầu vào không có phần tử không thì ta cập nhật bằng cách chia tích của toàn bộ phần tử trong mảng cho giá trị hiện tại để được kết quả theo yêu cầu cho giá trị phần tử trong mảng kết quả tương ứng.
        else:
            for i in range(len(nums)):
                nums[i] = product_array_value // nums[i]
            return nums