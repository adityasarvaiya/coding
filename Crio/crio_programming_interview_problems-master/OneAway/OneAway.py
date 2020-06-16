# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def checkReplace(a, b):
    foundOne = False

    for charA, charB in zip(a, b):
        if charA == charB:
            continue
        if not foundOne:
            foundOne = True
            continue
        return False
    return True

def checkInsert(a, b):
    mismatchIndex = -1
    for i in range(len(a)):
        if a[i] != b[i]:
            mismatchIndex = i
            break
    if mismatchIndex == -1:
        return True
    newA = a[:i] + b[i] + a[i:]
    return newA == b

def checkRemove(a, b):
    mismatchIndex = -1
    for i in range(len(b)):
        if a[i] != b[i]:
            mismatchIndex = i
            break
    if mismatchIndex == -1:
        return True
    newA = a[:i] + a[i+1:]
    return newA == b
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def isOneAway(a, b):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if abs(len(a) - len(b)) > 1:
        return False
    if a == b:
        return True
    
    if len(a) == len(b):
        return checkReplace(a, b)
    elif len(a)+1 == len(b):
        return checkInsert(a, b)
    else:
        return checkRemove(a, b)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

T = int(input())
for _t in range(T):
    a, b = input().strip().split()
    result = isOneAway(a, b)
    print(result)
