stack = []
minStack = []

def push(x):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if not minStack or minStack[-1] > x:
        minStack.append(x)
    stack.append(x)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def pop():
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if not stack:
        return
    if stack[-1] == minStack[-1]:
        minStack.pop()
    stack.pop()

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def findMin():
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if not minStack:
        return -1
    return minStack[-1]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

queries = int(input())

for query in range(queries):
    _type = input().strip().split()
    x = 0
    if len(_type) == 2:
        _type, x = map(int, _type)
    else:
        _type = int(_type[0])
    if _type == 1:
        push(x)
    elif _type == 2:
        pop()
    else:
        minElement = findMin()
        print(minElement)
