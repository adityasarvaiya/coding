from Solution import Solution

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().strip().split()))
    q = int(input())
    for _q in range(q):
        target = int(input())
        result = Solution().searchRange(nums, target)
        print(*result)
