def jumpGame(nums):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    lastPos = len(nums) - 1
    for i in reversed(range(len(nums))) :
        if i + int(nums[i]) >= lastPos:
            lastPos = i
    if lastPos == 0:
        return "true"
    else:
        return "false"
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    	
if __name__ == '__main__':
    n = int(input())
    ar = list(map(int,input().strip().split()))
    result = jumpGame(ar)
    print(result)
