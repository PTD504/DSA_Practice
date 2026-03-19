from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        # Bài toán yêu cầu tìm một điểm i (một phần tử tại chỉ số i nào đó thuộc mảng đầu vào) mà tổng giá trị của các phần tử trong mảng đầu vào nằm bên trái phần tử i này bằng với tổng các phần tử nằm bên phải của phần tử i đang xét, lưu ý là giá trị phần tử i sẽ không được tính vào tổng.
        # Để giải bài này, chúng ta chỉ cần tạo hai mảng prefix và suffix, trong đó:
        # prefix[i] = sum(nums[1 ... i]), tức là tổng của i phần tử đầu tiên (các phần tử nằm bên trái của phần tử i và chính phần tử i) trong mảng nums (giả sử đang dùng index là 1)
        # suffix[i] = sum(nums[i ... n]), tức là tổng của các phần tử nằm bên phải của i, tính cả i
        # Lúc này việc kiểm tra xem i có phải là một pivot index hay không sẽ là: prefix[1 ... (i - 1)] == suffix[(i + 1) ... n]

        # Tuy nhiên chúng ta có thể tối ưu space complexity bằng cách sử dụng hai biến thay cho hai mảng, xử lý khéo léo để vẫn tính được prefix sum và suffix sum của i tại mỗi i

        # Đầu tiên khởi tạo biến suffixSum thay vì là một mảng, ta sẽ chỉ lưu trữ giá trị là tổng của các phần tử hiện tại của mảng nums. Lưu ý hai phần tử ngoài cùng (sau phần tử ở chỉ số 0 và sau phần tử cuối cùng của mảng nums có giá trị là 0). Chúng ta sẽ duyệt từ đầu mảng, tức là ban đầu, chúng ta đang duyệt ở phần tử ở chỉ số 0, như vậy suffix sum bây giờ chính là toàn bộ mảng nums, còn prefix sum sẽ là 0 - giá trị của phần tử nằm ngoài mảng
        suffixSum = sum(nums)
        prefixSum = 0

        # Khởi tạo vòng lặp for, ở mỗi vòng lặp, ta sẽ kiểm tra xem phần tử hiện tại có phải là pivot index hay không (nếu có thì trả về ngay vì bài toán yêu cầu nếu có nhiều phần tử là pivot index trong một mảng thì trả về phần từ đầu tiên từ trái qua) và cập nhật hai biến suffixSum và prefixSum bằng cách:
        # Bước đầu tiên ở mỗi vòng lặp là bỏ đi giá trị của phần tử đang xét hiện tại ra khỏi suffixSum, có hai lý do: một là theo yêu cầu phần tử pivot không được đóng góp giá trị vào tổng hai đầu lúc so sánh, thứ hai là vì suffixSum đang có chứa giá trị của phần tử hiện tại khi tính tổng ban đầu.
        # Nếu phần tử hiện tại là pivot index, tức prefixSum bằng với suffixSum, ta chỉ việc trả về.
        # Ngược lại, nếu phần tử hiện tại không phải là pivot index, thì ở vòng lặp tiếp theo, chúng ta sẽ xét phần từ ngay bên phải của phần tử đang xét, lúc này phần tử i đang xét sẽ thuộc về vùng giá trị để tính prefix sum (vùng nằm bên trái), như vậy ta chỉ cần cộng thêm giá trị của phần tử hiện tại vào prefixSum là cập nhật được prefixSum cho vòng lặp sau để so sánh
        # Cứ như vậy đến phần tử cuối cùng, kết thúc vòng lặp mà vẫn không tìm được pivot index thì ta trả về -1
        for i in range(len(nums)):
            if prefixSum == suffixSum - nums[i]:
                return i
            prefixSum += nums[i]
            suffixSum -= nums[i]
        
        return -1