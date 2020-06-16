
def regularExpressionMatching(text, pattern):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    pat = pattern[0]
    for i in pattern[1:]:
        if pat[-1] != i or i != "*" :
            pat+=i
    pattern = pat
    pos = 0
    while pos < len(pattern) and pattern[pos] == "*":
        pos+=1
    n , m = len(text) , len(pattern)
    dp = [[False] * (m + 1) for _ in range(n + 1)]
    dp[-1][-1] = True
    for i in range(n, -1, -1):
        for j in range(m - 1, -1, -1):
            first_match = i < n and pattern[j] in {text[i], '.'}
            if j+1 < m and pattern[j+1] == '*':
                dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
            else:
                dp[i][j] = first_match and dp[i+1][j+1]

    return "true" if dp[0][pos] else "false"
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    s = input().rstrip()
    p = input().rstrip()
    ans  = regularExpressionMatching(s,p)
    print(ans)

if __name__ == "__main__":
    main()
