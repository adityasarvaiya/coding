def sqrtX(n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    for i in range(n):
        if(i*i>n):
            return i-1
    return n
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    result = sqrtX(n)
    print(result)
