def permutations(n: int):
    if n == 1:
        return [1]
    
    if n < 4:
        print("NO SOLUTION")
        return []
    
    permutation = []
    val = 2

    while val <= n:
        permutation.append(val)
        val += 2
    
    val = 1

    while val <= n:
        permutation.append(val)
        val += 2
    
    return permutation

def main():
    n = int(input())
    permutation = permutations(n)

    if permutation:
        print(" ".join(map(str, permutation)))

if __name__ == "__main__":
    main()