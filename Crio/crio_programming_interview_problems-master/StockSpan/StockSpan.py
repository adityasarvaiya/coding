def stockSpan(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(arr)
    stack = []
    span = [0 for i in range(n)]

    for i in range(n-1, -1, -1):
        while stack and arr[stack[-1]] < arr[i]:
            span[stack[-1]] = stack[-1] - i
            stack.pop()
        stack.append(i)
    
    while stack:
        span[stack[-1]] = stack[-1] + 1
        stack.pop()
        
    return span
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(input())
arr = list(map(int, input().strip().split()))
result = stockSpan(arr)
print(*result)
