def missing_number(nums):
    sum = 0

    for num in nums:
        sum += num
    
    return ((len(nums) + 1) * (len(nums) + 2)) // 2 - sum

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    print(missing_number(nums))

if __name__ == "__main__":
    main()