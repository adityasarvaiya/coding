def happyNumber(n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vis = set()
    n= abs(n)
    while(n!=1 and n not in vis):
        vis.add(n)
        x = n
        n = 0
        while(x>0):
            n+=(x%10)**2
            x//=10

    if(n==1):
        return "true"
    return "false"
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


if __name__ == '__main__':
    n = int(input())
    ans = happyNumber(n)
    print(ans)
