class Solution:
    def decodeString(self, s: str) -> str:
        # Bài toán yêu cầu ta giải mã một chuỗi đầu vào có dạng:
        # một số nguyên k đi kèm với một chuỗi trong cặp dấu ngoặc vuông. Ví dụ "3[a]" sẽ được giải mã thành "aaa". Lưu ý là các đoạn mã có thể lồng nhau: "3[a2[c]]" và chúng phải được giải mã đúng (từ trong ra ngoài) thành "accaccacc": 3[a2[c]] -> 3[acc] -> accaccacc

        # Để giải bài này, ta sẽ sử dụng một stack, khi gặp chuỗi ký tự, ta đưa vào stack còn nếu gặp dấu ngoặc vuông đóng "]" thì ta bắt đầu giải mã đoạn chuỗi vừa khép lại.
        stack = []
        # Chúng ta duyệt qua mỗi ký tự trong chuỗi đầu vào
        for char in s:
            if char != ']':
                stack.append(char)
                continue
            # Nếu ký tự hiện tại là "]", ta sẽ bắt đầu giải mã.
            string = []
            # Ta lần lượt lấy các ký tự hiện tại trong ngăn xếp cho đến khi gặp ký tự "[", đây chính là điểm bắt đầu của đoạn chuỗi cần nhân bản. 
            while stack[-1] != '[':
                string.append(stack.pop())
            
            stack.pop()
            freq = ''
            # Ta lấy số lần lặp bằng cách lấy ký tự số ngay trước ký tự "[", nếu không có ký tự số thì đoạn chuỗi này chỉ xuất hiện một lần (hay nói cách khác là không lặp), ...
            while stack and stack[-1].isdigit():
                freq += stack.pop()
            
            freq = freq[::-1]
            # lưu ý cần đảo ngược lại vì ta đang lấy ngược từ cuối stack
            string = string[::-1]
            string = ''.join(string)

            # ... rồi tiến hành nhân bản chuỗi tương ứng.
            if freq:
                string = string * int(freq)

            # Sau khi nhân bản, đưa chuỗi đã nhân bản vào lại stack -> stack chứa chuỗi con đã giải mã từ đầu đến trước ký tự "]" đang xét.
            stack.append(string)
        
        return ''.join(stack)
