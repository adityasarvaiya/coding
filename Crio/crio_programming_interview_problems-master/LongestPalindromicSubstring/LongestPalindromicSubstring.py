def longestPalindrome(s):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(s)
    maxString = ""
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
    maxString = s[start:start+maxLength]
    return maxString
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = input()
    result = longestPalindrome(s)
    print(result)