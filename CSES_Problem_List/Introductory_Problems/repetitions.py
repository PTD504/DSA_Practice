def repetitions(s: str) -> int:
    # A T G C
    ctr = s[0]
    count = 0
    mx_length = 0

    for ch in s:
        if ctr == ch:
            count += 1
            mx_length = max(mx_length, count)
        else:
            count = 1
            ctr = ch

    return mx_length


def main():
    # Test cases
    # assert repetitions("ATTCGGGA") == 3, "Test case 1 failed"
    # assert repetitions("ATGC") == 1, "Test case 2 failed"
    # assert repetitions("AAAAAAA") == 7, "Test case 3 failed"
    # assert repetitions("TTGGCCAG") == 2, "Test case 4 failed"

    s = input()
    result = repetitions(s)
    print(result)

if __name__ == "__main__":
    main()
    # print("All test cases passed!")