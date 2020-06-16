def mergeIntervals(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    nums.sort()
    ans = []
    ans.append([nums[0][0],nums[0][1]])
    for num in nums[1:]:
        if(num[0]<=ans[-1][1]):
            ans[-1][1] = max(ans[-1][1],num[1])
        else:
            ans.append([num[0],num[1]])
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = []
    for i in range(n):
        row = input().split()
        row = [int(i) for i in row]
        nums.append(row)
    result = mergeIntervals(nums)
    for interval in result:
        print(*interval)
