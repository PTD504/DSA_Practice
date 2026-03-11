class Solution:
    def mergeAlternatelyFirstApproach(self, word1: str, word2: str) -> str:
        '''
        Giải thích bài toán: Yêu cầu bài toán rất rõ ràng rằng chúng ta sẽ tạo một chuỗi mới với các phần tử từ hai chuỗi đầu vào, các phần tử trong chuỗi mới sẽ được lấy một cách thay thế nhau từ hai chuỗi đầu vào, phần tử đầu tiên của chuỗi mới sẽ là phần tử đầu tiên của chuỗi đầu vào word1, phần tử thứ hai của chuối mới sẽ là phần tử đầu tiên của chuỗi word2, rồi lại về phần tử tiếp theo của chuỗi word1, và cứ như vậy.

        Hướng tiếp cận: Vì yêu cầu của bài toán rất trực tiếp nên phương pháp giải chính là ta lấy từng phần tử từ hai chuỗi đầu vào lượt lượt thêm vào chuỗi mới.
        
        Cách giải cụ thể như sau:
        - Tạo biến merged_word ban đầu rỗng để chứa chuỗi kết quả merge
        - Tạo hai biến là len1, len2 lần lượt là độ dài của chuỗi word1, word2. 
        - Khởi tạo hai biến đếm i, j ban đầu mang giá trị là 0. Hai biến đếm này sẽ lần lượt đi qua các phần tử của hai chuỗi word1, word2 và thêm vào chuỗi mới xen kẽ nhau theo yêu cầu bài toán.
        - Khởi tạo vòng lặp while, điều kiện vòng lặp cả hai chuỗi word1, word2 đều còn phần tử để thêm vào chuỗi mới. Như vậy, vòng lặp sẽ kết thúc khi chúng ta đã sử dụng hết số phần tử của một trong hai chuỗi đầu vào.
        - Sau khi thoát ra khỏi vòng lặp, sẽ có trường hợp hai chuỗi đầu vào có độ dài chênh nhau khác 1, lúc này sẽ xảy ra trường hợp một chuỗi vẫn còn phần tử chưa xét đến. Lúc này ta sẽ kiểm tra và thêm vào các phần tử còn lại của chuỗi này vào chuỗi mới và trả về kết quả.
        '''
        merged_word = ""
        len1, len2 = len(word1), len(word2)
        i, j, check = 0, 0, 0

        while i < len1 and j < len2:
            if check & 1:
                merged_word += word2[j]
                j += 1
            else:
                merged_word += word1[i]
                i += 1
            
            check = 1 - check
        
        if i < len1:
            merged_word += word1[i:]
        else:
            merged_word += word2[j:]
        
        return merged_word
    
    def mergeAlternatelyImproved(self, word1: str, word2: str) -> str:
        '''
        Một hướng tiếp cận khác hiệu quả hơn cho bài toán
        Ý tưởng:
        - Chúng ta có thể thấy rằng, các phần tử có cùng chỉ số của hai chuỗi luôn sẽ xuất hiện liên tiếp nhau trong chuỗi mới và bắt đầu bằng phần tử của chuỗi word1. 
        - Ví dụ: word1 = "abc", word2 = "def". Lúc này, phần từ a và d đều có chỉ số bằng 0, tương tự cho chỉ số là 1 và 2. Chuỗi mới sẽ là "adbecf", rõ ràng là các phần tử có cùng chỉ số ban đầu trong hai chuỗi sẽ nằm cạnh nhau trong đó phần tử của chuỗi word1 bắt đầu trước.
        - Dựa vào đặc điểm trên, chúng ta sẽ không cần phải kiểm tra lượt thêm hiện tại là của chuỗi word1 hay word2 nữa (sử dụng biến check ở cách vừa rồi), mà ta có thể tạo một biến đếm từ chỉ số 0, và trong vòng lặp sẽ thêm lần lượt hai phần tử với chỉ số là i vào chuối mới. Cuối cùng, chúng ta sẽ kiểm tra lại xem trong hai chuỗi, chuỗi nào còn phần tử chưa xét (chuỗi dài hơn) thì thêm vào cuối chuỗi mới.

        Cách triển khai cụ thể:
        - Tạo biến merged_word để chứa chuỗi kết quả.
        - Khởi tạo biến min_len chứa độ dài của chuỗi ngắn hơn trong hai chuỗi đầu vào.
        - Khởi tạo vòng lặp for, cho biến i chạy từ 0 (từ chỉ số phần tử đầu tiên của hai chuỗi) đến min_len. Trong vòng lặp, chúng ta sẽ thêm lần lượt hai phần tử có cùng chỉ số là i (giá trị của biến i sẽ chạy từ 0 đến min_len - 1) vào cuối chuỗi mới, luôn luôn bắt đầu từ phần tử của chuỗi word1 trước.
        - Sau khi kết thúc vòng lặp, chúng ta sẽ thêm vào chuỗi con của chuối dài hơn mà trong vòng lặp for không thể xét đến bằng hai dòng code:
        ```python
        merged_word += word1[min_len:]
        merged_word += word2[min_len:]
        ```
        -> Phần tử chưa xét đến trong vòng lặp for sẽ có chỉ số trong chuỗi ban đầu bắt đầu từ giá trị hiện tại của min_len trở đi, chính vì vậy ta chỉ cần kiểm tra chuỗi con bắt đầu từ chỉ số mang giá trị min_len trở về sau của hai chuỗi đầu vào là sẽ có được chuỗi con cần thêm vào. Sau đó trả về kết quả là chuỗi sau khi merge.
        '''
        merged_word = ""
        min_len = min(len(word1), len(word2))

        for i in range(min_len):
            merged_word += word1[i]
            merged_word += word2[i]
        
        merged_word += word1[min_len:]
        merged_word += word2[min_len:]

        return merged_word
    
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return self.mergeAlternatelyImproved(word1, word2)