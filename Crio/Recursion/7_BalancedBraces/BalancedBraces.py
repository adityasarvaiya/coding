#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def findAllBalncedBraces(i, n, toBeClosed, currentBraceSeq, result):
    if i == n:
        result.append(currentBraceSeq + ')' * toBeClosed)
        return
    if toBeClosed > 0:
        findAllBalncedBraces(i , n, toBeClosed - 1, currentBraceSeq + ')', result)
    findAllBalncedBraces(i + 1, n, toBeClosed + 1, currentBraceSeq + '(', result)
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def balancedBraces(n):
    #CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    result = []
    findAllBalncedBraces(0, n, 0, '', result)
    return result
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    result = balancedBraces(n)
    for line in result:
        print(line)

if __name__ == '__main__':
    main()
