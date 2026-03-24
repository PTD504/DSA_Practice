class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # Ý tưởng cốt lõi để biết được hai chuỗi đầu vào có close hay không chính là:
        # Thứ nhất: Tập ký tự cấu thành hai chuỗi đầu vào phải giống nhau
        # -> Tức là mọi ký tự xuất hiện trong một chuỗi sẽ phải xuất hiện trong chuỗi còn lại
        # Thứ hai: Phân phối tần suất xuất hiện của các ký tự này phải giống nhau
        # -> Sau khi đếm số lần xuất hiện của từng ký tự trong mỗi chuỗi, ta sắp xếp các tần suất này theo thứ tự tăng dần. Nếu hai danh sách tần suất giống nhau thì ta có thể hoán đổi các ký tự để đạt được sự tương ứng. Ngược lại, nếu khác nhau thì ta sẽ không thể biến đổi để hai chuỗi ký tự ban đầu được coi là close

        # Bài này chúng ta có thể sử dụng bảng băm để đếm tần suất xuất hiện của mỗi ký tự trong mỗi chuỗi, tuy nhiên nếu để ý đề bài thì ta nhận thấy giới hạn các ký tự cấu tạo nên mỗi chuỗi chỉ là các ký tự lowercase, có nghĩa là tổng cộng có thể có 26 ký tự khác nhau có thể xuất hiện trong mỗi chuỗi. Như vậy thay vì dùng hash map phức tạp, ta có thể dùng một mảng số nguyên để đại diện cho hash map và đếm tần suất. Sau khi có mảng tần suất, việc sắp xếp và so sánh là điều khá dễ dàng (lưu ý kiểm tra tập ký tự của hai chuỗi trước).
        hash_word1 = [0 for _ in range(26)]
        hash_word2 = [0 for _ in range(26)]

        for char in word1:
            hash_word1[ord(char) - 97] += 1 # ord('a') = 97
        for char in word2:
            hash_word2[ord(char) - 97] += 1
        
        for i in range(26):
            if hash_word1[i] == hash_word2[i]:
                hash_word1[i] = hash_word2[i] = 0
            elif hash_word1[i] == 0 or hash_word2[i] == 0:
                return False
        
        hash_word1.sort()
        hash_word2.sort()

        for i in range(26):
            if hash_word1[i] != hash_word2[i]:
                return False
        
        return True