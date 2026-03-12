from typing import List

MAX_VALUE = 2 ** 31 - 1

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # Có khá nhiều cách tiếp cận cho bài toán này, chúng ta có thể đi từ brute force rồi tối ưu dần

        # Với cách tiếp cận brute force, chúng ta sẽ sử dụng ba vòng lặp for để kiểm tra tất cả các bộ ba có thể trong mảng đầu vào, vòng lặp đầu tiên để tìm phần tử i, vòng lặp hai sẽ tìm phần tử j thỏa mãn i < j và nums[i] < nums[j] và vòng lặp cuối cùng sẽ tìm phần tử k thỏa mãn i < j < k và nums[i] < nums[j] < nums[k].

        # Từ cách tiếp cận trên với độ phức tạp O(n^3), ta có thể tối ưu độ phức tạp thời gian xuống còn O(n^2) bằng cách sử dụng hai vòng lặp for và cách xử lý khéo léo hơn. Với vòng lặp ngoài cùng, chúng ta sẽ dùng để cố định phần tử j (trong điều kiện i < j < k và nums[i] < nums[k] < nums[k]), ở vòng lặp tiếp theo, chúng ta sẽ lần lượt tìm phẩn tử i và phần tử k thỏa mãn điều kiện đề bài bằng cách: kiểm tra các phần tử từ 0 -> j - 1 để tìm phần tử thỏa mãn điều kiện < nums[j] hiện tại; kiểm tra các phần tử từ j + 1 -> len(nums) - 1 để tìm phần tử thỏa mã điều kiện  > nums[j] hiện tại. Với cách tiếp cận lấy j và nums[j] làm phần tử trung tâm, ta có thể giảm được độ phức tạp thời gian của hướng brute force ban đầu.

        # Một cách tiếp cận khác cho bài toán này chính là giải quyết một bài toán khác: tìm mảng con tăng dài nhất trong mảng nums đầu vào, nếu kết quả cuối cùng là một mảng con có độ dài lớn hơn hoặc bằng 3 thì trả về True, ngược lại thì trả về False. Độ phức tạp của hướng tiếp cận này là O(nlogn)
        # Tuy nhiên thực tế là, độ phức tạp thời gian O(nlogn) của thuật toán DP (Dynamic Programming) sử dụng trong bài toán LIS (Longest Increasing Subsequence) là độ phức tạp trung bình và phụ thuộc vào độ dài chuỗi kết quả cuối cùng. Nếu chúng ta xác định chỉ tìm chuỗi con tăng với độ dài cố định là 3 thì độ phức tạp về thời gian sẽ chỉ còn là O(n) và độ phức tạp không gian (Space complexity) là hằng số - O(1)
        # Cụ thể hơn, trong bài toán LIS, độ phức tạp thời gian O(nlogn) được tính như sau: Chúng ta lặp qua toàn bộ mảng - O(n); ở mỗi lần lặp chúng ta cần tìm vị trí phù hợp trong mảng kết quả (mảng chứa chuỗi con tăng dài nhất chưa xét các phần tử từ i trở về sau). Thời gian để tìm kiếm vị trí phù hợp sẽ là O(logn) -> Tổng thời gian để giải quyết bài toán là O(nlogn). Nhưng nếu mảng kết quả của ta (ở bài toán này) chỉ cố định là 3 thì độ phức tạp sẽ giảm xuống còn O(n) cho việc lặp qua mảng nums và đương nhiên, chúng ta chỉ cần tạo 3 biến để chứa 3 phần tử trong mảng kết quả - Space complexity lúc này sẽ là O(1). Ý tưởng bài giải dưới đây cũng dựa vào cách tiếp cận này

        # Khởi tạo giá trị là MAX_VALUE cho 3 phần tử chứa kết quả chuỗi con tăng dài nhất (tối đa là 3 trong bài toán này), trong đó ta xác định: val_i < val_j < val_k (còn về điều kiện i < j < k, chúng ta chỉ cần tìm theo thứ tự như trên val_i, rồi val_j, rồi val_k là sẽ tự động thỏa mãn)
        val_i, val_j, val_k = MAX_VALUE, MAX_VALUE, MAX_VALUE

        # Duyệt qua từng phần tử trong nums
        for num in nums:
            # Nếu giá trị của phần tử đang xét nhỏ hơn giá trị nhỏ nhất trong mảng kết quả của ta (val_i) thì cập nhật giá trị của val_i = num
            if num <= val_i:
                val_i = num
            # Nếu giá trị của phần tử đang xét lớn hơn val_i nhưng nhỏ hơn val_j, chúng ta sẽ cập nhật lại val_j = num (lúc này ta đã có val_i < val_j và đương nhiên là i < j vì ta đang xét mảng nums từ đầu (index 0) đến cuối)
            elif num <= val_j:
                val_j = num
            # Nếu giá trị của phần tử đang xét lớn hơn val_i và val_j, lúc này, bản thân phần tử này chính là phần tử val_k chúng ta đang tìm, hay nói cách khác, trong mảng hiện tại tồn tại bộ 3 phần tử thỏa yêu cầu đề bài -> Return True
            elif num <= val_k:
                return True
        # Sau khi duyệt xong toàn bộ các phần tử trong nums mà không tìm được bộ 3 nào thỏa mãn, ta trả về False 
        return False
