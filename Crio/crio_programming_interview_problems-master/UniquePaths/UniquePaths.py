def uniquePaths(m, n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    mod = int(10**9+7)
    numberofWays = [[0 for i in range(n)] for i in range(m)]
    for i in range(m):
        numberofWays[i][0] = 1
    for i in range(n):
        numberofWays[0][i] = 1
    for i in range(1,m):
        for j in range(1,n):
            numberofWays[i][j] = (numberofWays[i-1][j] + numberofWays[i][j-1]) % mod
    return numberofWays[m - 1][n - 1]
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    result = uniquePaths(m, n)
    print(result)
    