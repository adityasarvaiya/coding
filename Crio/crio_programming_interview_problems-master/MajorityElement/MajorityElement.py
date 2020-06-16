def majorityElement(nums):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n=len(nums)
    M={}
    for i in range(n):
    	if nums[i] in M:
    		M[nums[i]]+=1
    	else:
    		M[nums[i]]=1
    ans =-1
    for k,v in M.items():
    	if v > n/2:
    		ans=k
    		break
    return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    result = majorityElement(nums)
    print(result)
