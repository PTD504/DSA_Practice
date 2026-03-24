from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        # Bài toán cho một mảng asteroids (các tiểu hành tinh) biểu diễn cho các asteroid trên một hàng. Giá trị tuyệt đối của các phần tử trong mảng đầu vào đại diện cho kích thước của các asteroid, còn dấu của các giá trị này (âm hoặc dương) đại diện cho hướng (di chuyển) của các asteroid. Như vậy, khi các asteroid này được xếp trên một hàng, các asteroid có hướng vào nhau sẽ xảy ra va chạm và asteroid có kích thước nhỏ hơn sẽ biến mất hoặc nếu cả hai asteroid có kích thước bằng nhau thì cả hai sẽ biến mất. Tìm danh sách asteroid sau khi kết thúc các va chạm.

        # Cách tiếp cận bài này cũng sẽ dùng stack, duyệt lần lượt từ asteroid đầu đến asteroid cuối trong mảng đầu vào. Khi xét một asteroid, nếu asteroid này đối hướng với asteroid trước đó (phần từ ở vị trí cuối cùng trong ngăn xếp) thì ta sẽ dựa vào kích thước để xem loại bỏ asteroid nào, cứ như vậy đến khi asteroid hiện tại đang xét biến mất hoặc không còn đối hướng với asteroid trong ngăn xếp nữa.
        asteroid_state = []

        for asteroid in asteroids:
            if asteroid < 0 and asteroid_state:
                current_asteroid = asteroid
                while asteroid_state and asteroid_state[-1] > 0:
                    if asteroid_state[-1] == abs(current_asteroid):
                        asteroid_state.pop()
                        current_asteroid = 0
                        break
                    elif asteroid_state[-1] < abs(current_asteroid):
                        asteroid_state.pop()
                    else:
                        current_asteroid = 0
                        break
                if current_asteroid:
                    asteroid_state.append(current_asteroid)
            else:
                asteroid_state.append(asteroid)
        
        return asteroid_state