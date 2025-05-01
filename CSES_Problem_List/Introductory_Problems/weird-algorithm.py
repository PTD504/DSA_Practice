def weird_algorithm(n):
    li = [n]
    while n != 1:
        if n & 1:
            n = 3 * n + 1
        else:
            n //= 2
        li.append(n)
    
    print(" ".join(map(str, li)))

def main():
    n = int(input())
    weird_algorithm(n)

if __name__ == "__main__":
    main()