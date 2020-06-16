def findTrailingZeros(n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    i = 5
    trailingZeroCount = 0
    while n//i >= 1:
        trailingZeroCount += n // i
        i *= 5
    return trailingZeroCount
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(input())
result = findTrailingZeros(n)
print(result)
