def firstMissingPositive(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    res = 0
    m = dict()
    for i in nums:
        if(i>0):
            m[i]=1
    res = 1
    while(m.get(res)==1):
        res+=1
    return res
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = []
    if n > 0:
        nums = input().split()
        nums = [int(i) for i in nums]

    result = firstMissingPositive(nums)
    print(result)

