from typing import List

class Solution:

    def compress(self, chars: List[str]) -> int:
        # Yêu cầu bài toán này khá trực tiếp, cách giải đơn giản là làm theo yêu cầu đề bài, chỉ lưu ý cách xử lý khi viết code để quản lý chỉ số trong mảng ban đầu cần cận thận.

        # Chúng ta bắt đầu với biến count = 1, đây là biến đếm số phần tử liên tiếp giống với phần tử đang xét hiện tại (chúng ta bắt đầu xét với ký tự đầu tiên trong danh sách đầu vào)
        count = 1
        cur_char = chars[0]

        # compress_string_index lưu chỉ số để cập nhật lại ký tự và số lượng ký tự đó trên mảng ký tự đầu vào ban đầu
        compress_string_index = 1
        # compress_string_length chứa chiều dài mảng ký tự sau khi nén
        compress_string_length = 0

        # Chúng ta sẽ duyệt từ ký tự thứ hai (i = 1) trong mảng đầu vào, ký tự dùng để so sánh là ký tự đầu của mảng ký tự đầu vào - curchar = chars[0]
        for i in range(1, len(chars)):
            # Nếu ký tự ở vị trí thứ i giống với ký tự cur_char, chúng ta chỉ cần tăng biến đếm count lên 1
            if cur_char == chars[i]:
                count += 1
            # Nếu ký tự ở vị trí thứ i khác với ký tự cur_char, chúng ta sẽ thêm cur_char (và số lượng ký tự này là count) vào mảng sau khi nén (ở đây là mảng ban đầu tuy nhiên chúng ta sẽ cập nhật tại các vị trí i đã xét qua)
            elif count == 1:
                # Thay thế ký tự tại vị trí chỉ số compress_string_index bằng ký tự cur_char. Vì số lượng ký tự này chỉ có 1 nên không cần thêm số vào. Sau đó ta cập nhật biến compress_string_index lên 1 (như bạn có thể thấy, các phần tử trong mảng ban đầu từ vị trí 0 đến compress_string_index - 1 đang là mảng kết quả hiện tại - mảng sau khi nén)
                chars[compress_string_index] = cur_char = chars[i]
                compress_string_index += 1
                # Tăng độ dài mảng kết quả lên 1 (vì chỉ thêm ký tự, không thêm số lượng)
                compress_string_length += 1
            else:
                # Nếu ký tự ở vị trí i khác với cur_char và số lượng ký tự là cur_char trong mảng hiện tại nhiều hơn 1, ta sẽ cần thêm vào mảng kết quả cả ký tự cur_char lẫn số lượng ký tự này.
                count_str = list(str(count))
                for char_of_count in count_str:
                    chars[compress_string_index] = char_of_count
                    compress_string_index += 1
                chars[compress_string_index] = cur_char = chars[i]
                compress_string_length += count
                count = 1
                compress_string_index += 1
        
        # Nhìn vào nguyên lý hoạt động của logic trong vòng lặp trên, bạn có thể thấy rằng các ký tự giống nhau cuối cùng trong mảng đầu vào sẽ không được xét trong vòng lặp, vì vậy ta cần xử lý chúng sau khi kết thúc vòng lặp, cách xử lý hoàn toạn tương tự khi xét một phần tử trong vòng lặp
        if compress_string_index < len(chars) and count != 1:
            count_str = list(str(count))
            for char_of_count in count_str:
                chars[compress_string_index] = char_of_count
                compress_string_index += 1
            chars = chars[:compress_string_index + 1]
        
        return compress_string_index
                