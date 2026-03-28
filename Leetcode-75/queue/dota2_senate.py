from queue import Queue
from collections import Counter

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        # Bài toán cho chúng ta một chuỗi đầu vào với mỗi ký tự có thể là 'R' đại diện cho một thượng nghị sĩ thuộc Radiant party hoặc 'D' đại diện cho mộtthượng nghị sĩ thuộc Dire party. 
        # Các thành viên này sẽ tham gia vào một cuộc bỏ phiếu theo vòng tròn bắt đầu từ người đầu tiên trong chuỗi. Tại một vòng, người chơi có thể thực hiện một trong hai quyền sau:
        # 1. Cấm toàn bộ quyền của một người nào đó, hành động này sẽ làm người đó mất hết quyền trong vòng hiện tại cũng như các vòng tương lai
        # 2. Tuyên bố chiến thắng nếu các thành viên khác - những người vẫn có thể thực hiện quyền của mình - đều thuộc một party.

        # Yêu cầu bài toán là trả về party chiến thắng sau khi cuộc bỏ phiếu kết thúc

        # Chiến thuật tối ưu cho bài toán là ở tại một round, người hiện tại sẽ ban người thuộc party đối lập ở phía sau mình. Với cách này, người vote có thể hạn chế được tối đa lượng người chung party bị ban bởi người thuộc party khác. 

        # Để thực hiện chiến thuật này, ta sẽ khởi tạo hai hàng đợi, một hàng đợi chứa vị trí của các thành viên thuộc Radiant, hàng đợi còn lại chứa vị trí của các thành viên thuộc Dire
        R = Queue()
        D = Queue()
        num_senators = len(senate)

        # Chúng ta duyệt qua chuỗi đầu vào và lưu lại vị trí của các thành viên trong hai hàng đợi vừa khởi tạo
        for i in range(num_senators):
            if senate[i] == 'R':
                R.put(i)
            else:
                D.put(i)
        
        # Bắt đầu cuộc voting, ta sẽ tiếp tục voting cho đến khi có một bên không còn người nào có thể tham gia nữa
        while not R.empty() and not D.empty():
            # Lấy ra một thượng nghị sĩ Radiant và một thượng nghị sĩ Dire
            # Vì ta duyệt theo vòng tròn nên method get sẽ lấy ra người đến lượt tiếp theo của quá trình vote của hai bên
            senator_R = R.get()
            senator_D = D.get()

            # Nếu vị trí của thượng nghị sĩ R nhỏ hơn vị trí của thượng nghị sĩ D, tức là người bên R đến lượt trước, bên R sẽ ban tất cả quyền của thành viên hiện tại của D và được thêm trở lại vào hàng đợi của R và đợi đến lượt sau
            if senator_R < senator_D:
                R.put(senator_R + num_senators)
            # Ngược lại, bên D sẽ ban quyền của thành viên R và được thêm trở lại vào hàng đợi cho lượt sau
            else:
                D.put(senator_D + num_senators)
            # Lưu ý khi thêm lại vào hàng đợi, chúng ta phải cộng giá trị vị trí với num_senators vì cuộc vote sẽ tiếp diễn qua num_senators nữa rồi mới quay trở lại người hiện tại
        
        # Trả về kết quả cuối cùng, hàng đợi nào còn người thì party đó dành chiến thắng
        return 'Radiant' if not R.empty() else 'Dire'