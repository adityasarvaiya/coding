# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def isMatch(i, j, prevI, wordMap, text, pattern):
    n = len(text)
    m = len(pattern)
    
    if i == n and j == m:
        return True
    if i == n or j == m:
        return False
    
    result = isMatch(i + 1, j, prevI, wordMap, text, pattern)

    currentStr = text[prevI + 1: i + 1]

    if pattern[j] not in wordMap:
        wordMap[pattern[j]] = currentStr
        result = result or isMatch(i + 1, j + 1, i, wordMap, text, pattern)
        wordMap.pop(pattern[j])
    else:
        if currentStr == wordMap[pattern[j]]:
            result = result or isMatch(i + 1, j + 1, i, wordMap, text, pattern)
    return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def patternMatching(text, pat):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    return isMatch(0, 0, -1, {}, text, pattern)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

T = int(input())
for _t in range(T):
    text, pattern = input().strip().split()
    result = patternMatching(text, pattern)
    print("Yes" if result else "No")
