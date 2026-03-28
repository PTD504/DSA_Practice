from queue import Queue

class RecentCounter:

    def __init__(self):
        # Khởi tạo một danh sách (list data type) để lưu trữ thời điểm các request được gửi đến hệ thống
        self.request_counter = []
        # Biến first lưu trữ thời điểm request đầu tiên mà vẫn còn nằm trong khoảng thời gian [t - 3000, t]
        self.first = 0
        # Biến len lưu trữ tổng số lượng request tính đến thời điểm hiện tại
        self.len = 0

    def ping(self, t: int) -> int:
        # Bài toán yêu cầu chúng ta xây dựng một lớp (class trong Python) để đếm lượng request trong một khoảng thời gian nhất định, cụ thể ở đây là [t - 3000, t] với t là thời điểm một request nào đó được gửi

        # Hàm ping có nhiệm vụ trả về số lượng request hiện tại mà được gọi trong khoảng thời gian từ [t - 3000, t]
        
        # Khi người dùng gửi một request, hệ thống sẽ gửi cho ta thời điểm mà người dùng vừa gửi request đó, lúc này ta chỉ việc thêm thời điểm này vào danh sách lưu trữ
        self.request_counter.append(t)
        # Tăng số lượng request tính đến thời điểm hiện tại lên 1
        self.len += 1
        # Xác định thời điểm biên dưới mà ta cần đếm số lượng request tính từ thời điểm này
        lower_bound = t - 3000

        # Ta duyệt qua danh sách lưu trữ thời điểm hiện tại và kiểm tra những thời điểm nào không còn nằm trong đoạn [t - 3000, t] và loại chúng đi khỏi kết quả cuối cùng
        while  self.first < self.len and self.request_counter[self.first] < lower_bound:
            self.first += 1
        # Trả về lượng request mà có thời gian gọi đến nằm trong [t - 3000, t]    
        return self.len - self.first

# -> Vậy là chúng ta vừa xây dựng xong một lớp có cơ chế hoạt động khá tương đồng với CTDL Queue


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)