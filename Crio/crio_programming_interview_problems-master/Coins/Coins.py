#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
mod = 10**9+7
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def countWays(n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    coins = [1,5,10,25]

    lis = [0 for _ in range(n+1)]
    lis[0]=1
    for i in coins:
        for j in range(i,n+1):
            lis[j] = (lis[j] + lis[j-i])%mod
    return lis[n]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    result = countWays(n)
    print(result)


if __name__ == "__main__":
    main()
