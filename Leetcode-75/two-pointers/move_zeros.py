from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Sử dụng kỹ thuật hai con trỏ đề giải quyết bài toán này. Chúng ta sẽ đổi bài toán thành di chuyển tất cả các phần từ khác 0 của mảng đầu vào lên đầu mảng (giữ nguyên vị trí tương đối giữa các phần tử ban đầu).

        # Đầu tiên chúng ta sẽ tìm vị trí phần tử bằng 0 đầu tiên trong mảng đầu vào, nếu không có thì lập tức dừng hàm vì không cần điều chỉnh gì trên mảng đầu vào nữa
        try:
            j = nums.index(0)
        except ValueError:
            return
        
        # Khởi tạo vòng lặp for chạy từ j + 1. Hai con trỏ chúng ta sử dụng lúc này là biến i và biến j, trong đó biến i có vai trò duyệt qua các phần tử sau phần tử có giá trị 0 đầu tiên của mảng, còn j lưu vị trí để lưu phần tử khác 0 tiếp theo tìm được khi duyệt i
        for i in range(j + 1, len(nums)):
            # Khi phần tử ở vị trí i đang xét khác 0,
            if nums[i] != 0:
                # Ta sẽ chuyển giá trị phần tử này vào vị trí j đang giữ và tăng j lên 1 đơn vị để cập nhật phần tử khác 0 tiếp theo
                nums[i], nums[j] = nums[j], nums[i]
                j += 1