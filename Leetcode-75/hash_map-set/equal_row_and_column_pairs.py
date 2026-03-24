from typing import List

class Solution:
    def equalPairsOpt(self, grid: List[List[int]]) -> int:
        # Một ý tưởng khác tối ưu hơn giúp giảm độ phức tạp thời gian (độ phức tạp thời gian trung bình) chính là dùng bảng băm. Để ý ở cách tiếp cận brute force, chúng ta sẽ phải duyệt qua một hàng (hay cột tùy cách chạy ban đầu) trong ma trận đầu vào khá nhiều lần, chúng ta có thể dùng bảng băm để tối ưu điểm này. Cụ thể, mỗi lần duyệt qua một hàng, ta sẽ lưu hàng này (dùng tuple để đảm bảo biến các hàng của ma trận thành một giá trị key trong bảng băm). Sau đó, khi duyệt qua các cột, ta sẽ biến các cột đang xét thành tuple rồi kiểm tra xem tuple này có trong bảng băm chưa, nếu có thì rõ ràng ta vừa tìm thêm một cột trong ma trận giống với hàng i nào đó, ta sẽ cập nhật lại đáp án.
        hashRows = {}
        n = len(grid)

        for r in range(n):
            row = tuple(grid[r])
            if row in hashRows:
                hashRows[row] += 1
            else:
                hashRows[row] = 1
        
        equal_pairs = 0

        for c in range(n):
            col = []
            for r in range(n):
                col.append(grid[r][c])
            col = tuple(col)
            if col in hashRows:
                equal_pairs += hashRows[col]
        
        return equal_pairs

    def equalPairs(self, grid: List[List[int]]) -> int:
        # Cách đơn giản nhất chính là dùng 3 vòng lặp for rồi so sánh từng cột và từng hàng
        equal_pairs = 0
        n = len(grid)

        for i in range(n):
            for j in range(n):
                is_equal = True
                for k in range(n):
                    if grid[i][k] != grid[k][j]:
                        is_equal = False
                        break
                equal_pairs += 1 if is_equal else 0
        
        return equal_pairs