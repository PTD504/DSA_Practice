class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, h = 0, len(s) - 1
        
        while l < h:
            if s[l].isalpha() == False and s[l].isdigit() == False:
                l += 1
            elif s[h].isalpha() == False and s[h].isdigit() == False:
                h -= 1
            elif s[l].lower() != s[h].lower():
                return False
            else:
                l += 1
                h -= 1
        
        return True

# Example usage
def main():
    s = "as&78&2332&& sadha 77a8s&8^ 233287sa";

    obj = Solution()
    print(obj.isPalindrome(s))

if __name__ == "__main__":
    main()