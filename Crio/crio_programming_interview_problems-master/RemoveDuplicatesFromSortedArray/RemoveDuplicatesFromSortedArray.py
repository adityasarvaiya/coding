
def removeDuplicates(nums):
   
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n=len(nums)
    if n<=1:
        return n
    cnt=0
    i=0
    while i<n:
        if nums[i]==nums[cnt]:
            i+=1
        else:
            cnt+=1
            nums[cnt]=nums[i]
        
    return cnt+1
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    return 0

if __name__ == '__main__':
    n = int(input())
    nums = []
    if n > 0:
        nums = input().split()
    nums = [int(i) for i in nums]
    result = removeDuplicates(nums)
    print(result)
