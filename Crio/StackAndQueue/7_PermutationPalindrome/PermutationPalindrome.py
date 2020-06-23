def isPermutationPalindrome(s):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    charCount = {}

    for char in s:
        if char not in charCount:
            charCount[char] = 0
        charCount[char] += 1

    isOddLength = len(s)%2

    for char in charCount:
        if (charCount[char] % 2) == 0:
            continue
        if isOddLength:
            isOddLength = 0
            continue
        return False
        
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    return True

T = int(input())
for _t in range(T):
    s = input().strip()
    result = isPermutationPalindrome(s)
    print(result)
