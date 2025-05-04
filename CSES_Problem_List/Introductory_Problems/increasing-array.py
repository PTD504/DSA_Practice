def increasing_array(arr):
    min_move = 0

    for i in range(1, len(arr)):
        if arr[i] < arr[i - 1]:
            min_move += arr[i - 1] - arr[i]
            arr[i] = arr[i - 1]
    
    return min_move

def main():
    # Testcases
    # assert increasing_array([1, 2, 3, 4, 5]) == 0
    # assert increasing_array([3, 2, 1]) == 3
    # assert increasing_array([1, 2, 3, 2, 5]) == 1
    # assert increasing_array([1, 5, 2, 4, 3]) == 6

    n = int(input())
    arr = list(map(int, input().split()))
    result = increasing_array(arr)
    print(result)

if __name__ == "__main__":
    main()
    # print("All test cases passed!")