from typing import List

class Solution:
    def __upperbound(self, nums: List[int], key: int) -> int:
        low, high = 0, len(nums) - 1

        while low <= high:
            mid = (low + high) // 2
            if nums[mid] <= key:
                low = mid + 1
            else:
                high = mid - 1
        
        return low

    def __maxOperationsOpt(self, nums: List[int], k: int) -> int:
        # Để sử dụng ý tưởng thuật toán hai con trỏ cho bài này, chúng ta cần mảng đầu vào đã được sắp xếp (tăng dần hoặc giảm dần, ở đây chúng ta sẽ chọn tăng dần)
        nums.sort()
        i = 0
        # Ở khâu khởi tạo hai con trỏ, chúng ta có thể duyệt cả mảng khi đặt giá trị của j là vị trí phần tử cuối mảng. Tuy nhiên, chúng ta có thể tối ưu thêm bằng cách loại bỏ các phần tử trong mảng (không xét các phần tử này) mà giá trị của chúng lớn hơn k (thực ra với ràng buộc giá trị các phần tử trong mảng đầu vào thì ta có thể lược bỏ thêm các giá trị bằng k - không xét các phần tử có giá trị >= k)
        j = self.__upperbound(nums, k) - 1
        numPairs = 0

        # Khởi tạo vòng lặp cho i và j chạy, i chạy từ đầu mảng (từ các phần tử nhỏ nhất trong mảng), j chạy từ cuối mảng (từ các phần tử lớn nhất trong mảng, ở đây là các phần tử <= k)
        while i < j:
            # Nếu cặp giá trị tại i và j hiện tại có tổng bằng k, ta cập nhật số lượng cặp thỏa mãn và cập nhật giá trị của i, j để xét tiếp các cặp tiếp theo
            if nums[i] + nums[j] == k:
                i += 1
                j -= 1
                numPairs += 1
            # Nếu tổng của hai phần tử ở i và j nhỏ hơn k, lúc này ta sẽ tăng biến i vì khi tăng i, giá trị nums[i] sẽ tăng theo (vì đây là mảng không giảm) để bù lại phần nhỏ hơn của tổng
            elif nums[i] + nums[j] < k:
                i += 1
            # Ngược lại, nếu tổng lớn hơn k thì ta giảm giá trị của j, tức là giảm giá trị của tổng đang xét
            else:
                j -= 1
        
        return numPairs

    def maxOperations(self, nums: List[int], k: int) -> int:
        # return self.__maxOperationsOpt(nums, k)

        # Bài này chúng ta có hai hướng tiếp cận chính, một là sử dụng kỹ thuật hai con trỏ (trong hàm __maxOperationsOpt()), hai là sử dụng bảng băm như cách triển khai bên dưới.
        hashKSum = {}
        maxOp = 0

        # Chúng ta sẽ duyệt qua các phần tử của mảng đầu vào, với mỗi phần tử, chúng ta sẽ kiểm tra xem có phần tử nào trước đó đã thêm vào bảng băm mà tổng của chúng bằng k không. Nếu có, chúng ta sẽ cập nhật biến đếm số cặp và bỏ ra phần tử mà có tổng với phần tử đang xét bằng k. Nếu không có phần tử thỏa mãn, ta chỉ việc thêm phần tử hiện tại vào bảng băm để xét tiếp các phần tử khác
        for num in nums:
            if (k - num) in hashKSum:
                maxOp += 1
                hashKSum[k - num] -= 1
                if hashKSum[k - num] < 1:
                    hashKSum.pop(k - num)
            else:
                hashKSum[num] = hashKSum[num] + 1 if (num in hashKSum) else 1
        
        return maxOp

        # Độ phức tạp thời gian (time complexity) của cách này trong trường hợp tệ nhất (worst case) là O(n^2) bởi vì chúng ta đang sử dụng bảng băm, một cấu trúc dữ liệu có độ phức tạp thời gian khi thêm, xóa, truy cập một phần tử trong trường hợp tệ nhất là O(n), việc dùng trong mỗi vòng lặp khiến cho độ phức tạp thời gian trở thành O(n^2) - worst case.