class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # Hướng giải quyết: bắt đầu xét hai chuỗi từ ký tự ban đầu (chỉ số 0), chúng ta sẽ lần lượt duyệt qua mảng t và kiểm tra xem đến một phần tử nào đó trong chuỗi t (tối đa là đến phần tử cuối cùng trong mảng t) mà chuỗi s sẽ được tạo thành từ chuỗi con t[:i] (i <= len(t)) hay không.

        # Khởi tạo j là chỉ số xét từng phần tử trong chuỗi s
        j, s_len = 0, len(s)

        if s_len == 0:
            return True

        # Vòng lặp duyệt qua chuỗi t
        for i in range(0, len(t)):
            # Nếu hai phần từ tại i của t và tại j của s giống nhau, tức là tính đến thời điểm hiện tại, ta có thể tạo được chuỗi s[0, j] từ chuỗi t[0, i]. Ta sẽ cập nhật biến j lên một đơn vị để trong vòng lặp tiếp theo sẽ tiếp tục kiểm tra việc tạo thêm phần tử s[j + 1].
            if t[i] == s[j]:
                j += 1
                # Nếu j >= s_len, tức là ở thời điểm hiện tại, ta đã có thể tạo được chuỗi s từ chuỗi t[0, i], trả vềTrue
                if j >= s_len:
                    return True
        
        # Sau khi kết thúc vòng lặp mà vẫn chưa tạo dược s, trả về False
        return False