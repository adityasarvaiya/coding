def climbingStairs(numberOfStairs):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    dp = [0]*(numberOfStairs+2)
    dp[0],dp[1]=0,1
    for i in range(numberOfStairs):
        dp[i+2] = dp[i+1]+dp[i]
    return dp[numberOfStairs+1]
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


if __name__ == '__main__':
    numberOfStairs = int(input())
    result = climbingStairs(numberOfStairs)
    print(result)
