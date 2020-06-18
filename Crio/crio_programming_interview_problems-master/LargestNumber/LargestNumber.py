import functools

def comp(x,y):
    str1 = str(x)+str(y)
    str2 = str(y)+str(x)
    # print(str1+" "+str2)
    if str1>str2:
        return -1
    else: return 1

def largestNumber(nums):
    # CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    nums =sorted(nums,key=functools.cmp_to_key(comp))
    ans = ""
    for num in nums:
        ans+=str(num)
    return ans
    # CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    
if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    result = largestNumber(nums)
    print(result)
    