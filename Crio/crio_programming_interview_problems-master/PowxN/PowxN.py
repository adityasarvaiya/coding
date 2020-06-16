def myPow(x, y):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    mod = 10**9 + 7
    x = x% mod
    if y == 0:
        return 1
    ans = myPow(x,y//2)
    ans = (ans * ans) % mod
    if y%2 ==1:
        ans = (ans * x)%mod
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    row = input().split()
    x = int(row[0])
    y = int(row[1])
    result = myPow(x, y)
    print(result)