class Solution:
    def reverseWordsShorter(self, s: str) -> str:
        # Python cung cấp các hàm built-in cho string và list giúp chúng ta có thể xử lý bài này trong hai dòng code như bên dưới

        # Chuyển chuỗi đầu vào thành một danh sách, việc tách chuỗi dựa vào ký tự khoảng trắng để tạo các phần từ mới trong danh sách (list) kết quả trả về
        s_list = s.split()

        # Sau khi đã có danh sách các từ trong chuỗi ban đầu, ta chỉ cần đảo ngược danh sach này và nối chúng lại thành một chuỗi mới là có được kết quả đúng yêu cầu đề bài
        return " ".join(s_list[::-1])

    def reverseWords(self, s: str) -> str:
        # return self.reverseWordsShorter(s)

        # Nếu không sử dụng built-in function

        # Loại bỏ phần tử trắng ở hai đầu của chuỗi
        s = " ".join(s.split())
        s_list = list(s)
        
        # Đảo ngược chuỗi, tuy nhiên cả các ký tự trong một từ cũng bị đảo ngược
        s_list.reverse()

        i, j, s_len = 0, 0, len(s_list)

        # Chúng ta sẽ lần lượt đảo ngược lại vị trí của các ký tự trong một từ để các từ không bị đảo ngược như yêu cầu
        while j < s_len:
            if s_list[j] == ' ':
                k = j - 1
                while i < k:
                    s_list[i], s_list[k] = s_list[k], s_list[i]
                    i += 1
                    k -= 1
                j += 1
                i = j
            else:
                j += 1
        
        s_len -= 1

        while i < s_len:
            s_list[i], s_list[s_len] = s_list[s_len], s_list[i]
            i += 1
            s_len -= 1

        s = "".join(s_list)
        return s