"""
Approach: Chúng ta có thể xác định độ dài tối đa của chuỗi kết quả bằng cách tính GCD của độ dài hai chuỗi đầu vào. Độ dài của chuỗi kết quả sẽ không vượt quá giá trị này.
"""

class Solution:
    def __gcd(self, n: int, m: int) -> int:
        if n % m == 0:
            return m
        return self.__gcd(m, n % m)
    
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        """
        Hướng tiếp cận: O(n^2), lặp qua từng substring có thể, bắt đầu từ substring với độ dài là 1. Luôn bắt đầu từ substring với phần tử đầu tiên của substring là phần tử đầu tiên của chuỗi đầu vào -> Nếu hai chuỗi đầu vào có phần tử đầu tiên khác nhau thì trả về rỗng ngay lập tức.
        """
        len1, len2 = len(str1), len(str2)
        gcd_max_len = self.__gcd(len(str1), len(str2))

        for step in range(gcd_max_len, 0, -1):
            j = 0
            while j + step <= len1 and j + step <= len2 and str1[j:j + step] == str1[:step] and str2[j:j + step] == str1[:step]:
                j += step
            
            if j >= len1 and j >= len2:
                return str1[:step]
            elif j < len1 and j < len2:
                continue
            elif j < len1:
                while j + step <= len1 and str1[j:j + step] == str1[:step]:
                    j += step
                if j < len1:
                    continue
                else:
                    return str1[:step]
            else:
                while j + step <= len2 and str2[j:j + step] == str1[:step]:
                    j += step
                if j < len2:
                    continue
                else:
                    return str1[:step]
        
        return ""