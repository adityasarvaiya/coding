#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def isPalindrome(a):
    return a == a[::-1]
def getAllPartitions(i, prev, s, result, current):
    n = len(s)
    if i == n:
        if (prev + 1) == n:
            result.append(current)
        return
    
    getAllPartitions(i + 1, prev, s, result, current)
    if isPalindrome(s[prev + 1: i + 1]):
        getAllPartitions(i + 1, i, s, result, current + [s[prev + 1: i + 1]])
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def palindromePartitioning(s):
    #CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    result = []
    getAllPartitions(0, -1, s, result, [])
    return result
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    s = input().strip()
    result = palindromePartitioning(s)
    for line in result:
        print(*line)

if __name__ == '__main__':
    main()
