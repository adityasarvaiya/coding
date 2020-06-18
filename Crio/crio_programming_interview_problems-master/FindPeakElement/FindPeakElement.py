def findPeakElement(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    nums.insert(0,-1)
    nums.append(-1)
    for i in range(1,len(nums)-1):
        if(nums[i]>nums[i-1] and nums[i]>nums[i+1]):
            return i-1
            
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    result = findPeakElement(nums)
    print(result)
    