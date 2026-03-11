from typing import List

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        '''
        Giải thích yêu cầu bài toán: Cho một mảng số nguyên flowerbed, mảng này đại diện cho một luống hoa (một dãy các cây hoa nối thành một đoạn thẳng), trong đó phần tử của mảng flowerbed chỉ có thể mang giá trị là 0 hoặc 1. Phần tử thứ i mang giá trị 1 cho biết rằng tại vị trí thứ i của luống hoa hiện tại đã có trồng một cây hoa, ngược lại nếu giá trị phần tử thứ i là 0 thì vị trí này vẫn còn trống và có thể trồng một cây hoa mới vào. Chúng ta được cung cấp một số nguyên n đại diện cho số lượng cây hoa cần trồng vào luống hoa, tuy nhiên khi trồng thì cần đảm bảo quy tắc sau được thỏa mãn: Không được trồng hai cây hoa bất kỳ liên tiếp nhau. Kết quả trả về sẽ là True nếu có thể trồng hết n cây hoa vào luống hoa mà không vi phạm quy tắc, ngược lại thì trả về False.

        Hướng giải quyết bài toán: Chúng ta sẽ trồng toàn bộ n cây hoa bắt đầu từ vị trí đầu tiên của luống hoa. Khi xét đến vị trí thứ i, nếu ở vị trí (i - 1) và vị trí (i + 1) đều trống thì ta có thể trồng hoa vào vị trí thứ i hiện tại, trường hợp ở hai đầu luống hoa thì chỉ cần xét một vị trí kế cận. Khởi tạo vòng lặp while với điều kiện là số lượng cây hoa còn trồng vẫn còn và số lượng vị trí còn lại vẫn lớn hơn 0, khi kết thúc vòng lặp nếu số lượng hoa cần trồng đã hết thì trả về True, ngược lại thì số lượng hoa cần trồng vẫn còn và số lượng vị trí có thể trồng hoa hợp lệ đã hết thì trả về False.
        '''
        i = len(flowerbed)
        
        if n == 0:
            return True
        if i == 1:
            return not flowerbed[0]
        else:
            i -= 1
        
        flowerbed.append(0)
        
        while i > 0 and n > 0:
            if flowerbed[i] == 1:
                i -= 1
                continue
            elif flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
                n -= 1
                i -= 1
            else:
                i -= 1
        
        if n <= 0:
            return True
        elif n > 1 or flowerbed[i] or flowerbed[i + 1]:
            return False
        else:
            return True