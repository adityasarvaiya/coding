def nextLargerElement(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(arr)
    current_stack = []
    nextLarger = [-1 for i in range(n)]

    for i in range(n):
        while current_stack and arr[current_stack[-1]] < arr[i]:
            nextLarger[current_stack[-1]] = arr[i]
            current_stack.pop()
        current_stack.append(i)
    return nextLarger
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(input())
arr = list(map(int, input().strip().split()))
result = nextLargerElement(arr)
print(*result)
