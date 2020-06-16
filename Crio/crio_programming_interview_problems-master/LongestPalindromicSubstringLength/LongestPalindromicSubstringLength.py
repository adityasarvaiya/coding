
def longestPalindromicSubstringLength(n, s):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    maxLength = 1
    start,low , high = 0,0,0
    for i in range(1, n): 
        low = i - 1
        high = i 
        while low >= 0 and high < n and s[low] == s[high]: 
            if high - low + 1 > maxLength: 
                start = low 
                maxLength = high - low + 1
            low -= 1
            high += 1
        low = i - 1
        high = i + 1
        while low >= 0 and high < n and s[low] == s[high]: 
            if high - low + 1 > maxLength: 
                start = low 
                maxLength = high - low + 1
            low -= 1
            high += 1
    return maxLength 
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input().rstrip()
        ans = longestPalindromicSubstringLength(n , s)
        print(ans)


if __name__ == "__main__":
    main()
