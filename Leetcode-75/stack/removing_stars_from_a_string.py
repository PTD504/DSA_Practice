class Solution:
    def removeStars(self, s: str) -> str:
        # Ý tưởng bài này khá đơn giản, chúng ta sẽ dùng một ngăn xếp để lưu lại các giá trị không phải là "*" trong quá trình duyệt qua chuỗi ban đầu, nếu ký tự đang xét là dấu "*", ta chỉ việc loại bỏ phần tử cuối cùng đang ở trong ngăn xếp, vì đây chính là ký tự non-star nằm bên trái của ký tự "*" hiện tại và ta cần loại bỏ nó. Cứ làm như vậy đến khi duyệt hết chuỗi ban đầu. Cuối cùng là tạo lại chuỗi kết quả từ các ký tự riêng lẻ trong stack ban đầu.
        stack = []

        for char in s:
            if char == '*':
                stack.pop()
            else:
                stack.append(char)
        
        return ''.join(stack)