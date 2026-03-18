class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        # Chúng ta sẽ giải bài này với ý tưởng như sau:
        # Đầu tiên, chúng ta sẽ duyệt qua substring với độ dài k đầu tiên của mảng đầu vào. Chúng ta sẽ lưu kết quả này vào biến curVowel
        vowels = set(['a', 'e', 'i', 'o', 'u'])
        curVowel = 0

        for i in range(k):
            if s[i] in vowels:
                curVowel += 1
        
        # Khởi tạo biến maxVowel để lưu trữ số lượng vowel lớn nhất có trong một cửa sổ (substring có độ dài k)
        maxVowel = curVowel
        # Biến start sẽ lưu giữ vị trí bắt đầu của phần tử đầu tiên trong substring có độ dài k mà ta đang xét. Mỗi lần muốn xét một substring mới, ta chỉ cần loại bỏ phần tử start này ở substring cũ rồi thêm phần tử mới vào cuối substring này là được.
        start = 0

        # Ở mỗi vòng lặp, ta sẽ đếm số lượng vowel và cập nhật cho biến maxVowel. Việc đếm sẽ dễ dàng hơn rất nhiều khi ta chỉ cần kiểm tra phần tử ở chỉ số start bị loại bỏ có phải là vowel hay không, đồng thời phần tử i chuẩn bị thêm vào có phải là vowel hay không rồi cập nhật biến curVowel
        for i in range(k, len(s)):
            if s[i] in vowels:
                curVowel += 1
            if s[start] in vowels:
                curVowel -= 1
            start += 1
            maxVowel = max(maxVowel, curVowel)
        
        return maxVowel