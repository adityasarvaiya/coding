def contigiousSequence(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    mx = -10**9
    cur_max = 0

    for i in range(len(arr)):
        cur_max += arr[i]

        if mx < cur_max:
            mx = cur_max
        if cur_max < 0:
            cur_max = 0
    return mx
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(input())
arr = list(map(int, input().strip().split()))
result = contigiousSequence(arr)
print(result)
