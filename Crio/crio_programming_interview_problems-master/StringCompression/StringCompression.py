def compress(s):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(s)
    res = ""
    i = 0
    while(i < n):
        j = i
        while j < n and s[i] == s[j]:
            j += 1
        res += s[i] + str(j - i)
        i = j

    if len(res) >= len(s):
        return s
    return res
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

s = input().strip()
result = compress(s)
print(result)
