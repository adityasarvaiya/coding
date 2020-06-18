def reverse(n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    INT_MAX = 2**31-1
    if abs(n)==n:
        sign = False
    else: sign = True
    n = abs(n)
    ans = 0
    while n>0:
        y = n%10
        if (INT_MAX-y)/10>=ans:
            ans = ans*10+n%10
        else: return 0
        n=int(n/10)
    if sign:
        ans = -ans
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    result = reverse(n)
    print(result)
