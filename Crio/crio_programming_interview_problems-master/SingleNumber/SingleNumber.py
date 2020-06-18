def singleNumber(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ans = 0
    for number in nums:
        ans = ans^number
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    result = singleNumber(nums)
    print(result)
