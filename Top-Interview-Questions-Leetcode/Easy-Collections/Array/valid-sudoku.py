from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        rows = [[0 for _ in range(9)] for _ in range(9)]
        cols = [[0 for _ in range(9)] for _ in range(9)]
        subs = [[0 for _ in range(9)] for _ in range(9)]
        
        for row in range(9):
            for col in range(9):
                if board[row][col] == '.':
                    continue
                
                val = int(board[row][col]) - int('0') - 1
                
                if rows[row][val] != 0 or cols[col][val] != 0: 
                    return False
                else:
                    rows[row][val] = cols[col][val] = 1
                
                # Determine the number of submatrix that board[row][col] belongs to
                '''
                1 2 3
                4 5 6
                7 8 9
                '''
                
                submatrix = (row // 3) * 3 + (col // 3)
                
                if subs[submatrix][val] != 0:
                    return False
                else:
                    subs[submatrix][val] = 1
        
        return True
                
# Example usage
def main():
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", "6", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", "2", "4", "1", "9", ".", ".", "."],
        [".", "8", "7", ".", "6", ".", ".", "3", "."]
    ]
    
    solution = Solution()
    print(solution.isValidSudoku(board))

if __name__ == "__main__":
    main()               