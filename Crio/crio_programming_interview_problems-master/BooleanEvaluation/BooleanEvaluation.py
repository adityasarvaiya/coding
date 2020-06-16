# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
MOD = 10 ** 9 + 7
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def booleanEvaluation(expression, result):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(expression)
    dp = [[[0,0] for i in range(n)] for j in range(len(expression))]

    numberOfWays = 0
    for left in range(n-1, -1, -2):
        for right in range(left, n, 2):
            for value in range(2):
                if left == right:
                    dp[left][right][value] = int(value == int(expression[left]))
                    continue
                for mid in range(left, right, 2):
                    operator = expression[mid+1]
                    for leftResult in range(2):
                        for rightResult in range(2):
                            if eval('{}{}{}'.format(leftResult, operator, rightResult)) == value:
                                count = (dp[left][mid][leftResult] * dp[mid+2][right][rightResult]) % MOD
                                dp[left][right][value] = (dp[left][right][value] + count) % MOD

    return dp[0][n-1][result]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

expression = input().strip()
result = int(input())

result = booleanEvaluation(expression, result)
print(result)
