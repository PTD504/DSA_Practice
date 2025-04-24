from typing import List

class Solution:
    
    def __reverse(self, array: List[int]) -> None:
        low, high = 0, len(array) - 1
        
        while low < high:
            array[low] ^= array[high]
            array[high] ^= array[low]
            array[low] ^= array[high]
            
            low += 1
            high -= 1
    
    def __print_matrix(self, matrix: List[List[int]]) -> None:
        for row in matrix:
            print(' '.join(map(str, row)))
    
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        for i in range(len(matrix)):
            for j in range(i + 1, len(matrix[0])):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        
        for i in range(len(matrix)):
            self.__reverse(matrix[i])
    
    def display(self, matrix: List[List[int]]) -> None:
        self.__print_matrix(matrix)

# Example usage
def main():
    
    matrix = [
        [1, 2, 3, 4, 5, 6],
        [7, 8, 9, 10, 11, 12],
        [13, 14, 15, 16, 17, 18],
        [19, 20, 21, 22, 23, 24],
        [25, 26, 27, 28, 29, 30],
        [31, 32, 33, 34, 35, 36]
    ]

    
    
    solution = Solution()

    print("Original matrix:")
    solution.display(matrix)

    # Rotate the matrix
    solution.rotate(matrix)

    print("\nRotated matrix:")
    solution.display(matrix)


if __name__ == "__main__":
    main()