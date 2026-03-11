class Solution:
    def reverseVowels(self, s: str) -> str:
        '''
        Mô tả bài toán: Cho một chuỗi ký tự chỉ chứa các ký tự có thể in được trong bảng mã ASCII. Yêu cầu bài toán là đảo ngược lại chuỗi đầu vào nhưng chỉ áp dụng thao tác đảo ngược này lên những phần tử được gọi là vowel trong tiếng Anh, gồm: 'a', 'e', 'i', 'o', 'u' và phiên bản in hoa của các chữ đó.

        Hướng giải bài toán: Ta sẽ dùng kỹ thuật hai con trỏ, khởi tạo biến i bắt đầu từ đầu chuỗi, biến j chạy từ cuối chuỗi về. Khởi tạo vòng lặp while với điều kiện hai biến i và j đang xét vẫn chưa giao nhau (số lượng ký tự còn lại cần xét đang lớn hơn 1). Ở mỗi bước, nếu cả hai phần tử tại vị trí i và j của chuỗi đều là vowels thì tiến hành đổi chỗ hai ký tự này với nhau đồng thời cập nhật lại giá trị của i và j để tiếp tục xét những cặp ký tự tiếp theo. Nếu chỉ một trong hai ký tự ở hai vị trí i và j là vowel thì ta sẽ tiếp tục xét ký tự này trong vòng lặp tiếp theo, ký tự còn lại không phải là vowel thì bỏ qua để xét tiếp các ký tự khác. Nếu không có ký tự nào trong hai ký tự đó là vowel thì chúng ta sẽ cập nhật biến i và j để tiếp tục xét các ký tự khác.
        '''
        s_list = list(s)
        i, j = 0, len(s_list) - 1

        while i < j:
            if s_list[i].lower() in ('a', 'e', 'i', 'o', 'u') and s_list[j].lower() in ('a', 'e', 'i', 'o', 'u'):
                s_list[i], s_list[j] = s_list[j], s_list[i]
                i += 1
                j -= 1
            elif s_list[i].lower() in ('a', 'e', 'i', 'o', 'u'):
                j -= 1
            elif s_list[j].lower() in ('a', 'e', 'i', 'o', 'u'):
                i += 1
            else:
                i += 1
                j -= 1
        
        s = "".join(s_list)
        return s