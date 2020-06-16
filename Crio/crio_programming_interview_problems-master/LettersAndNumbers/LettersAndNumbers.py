# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def isInteger(x):
    if ord(x) >= ord('0') and ord(x) <= ord('9'):
        return 1
    return -1
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def lettersAndNumbers(s, n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    pref = [isInteger(s[i]) for i in range(n)]
    for i in range(1, n):
        pref[i] += pref[i-1]
    
    prefSumIndex = {0: -1}
    result = [0, -1, -1]
    for i in range(n):
        requiredPrefSum = pref[i]
        if requiredPrefSum not in prefSumIndex:
            prefSumIndex[pref[i]] = i
            continue
        
        if result[0] < (i - prefSumIndex[requiredPrefSum]):
            result = [i - prefSumIndex[requiredPrefSum], prefSumIndex[requiredPrefSum] + 1, i]  
        
    return [-1] if result[0] == 0 else result[1:]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(input())
s = input().strip()

result = lettersAndNumbers(s, n)
print(*result)
