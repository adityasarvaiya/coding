from Solution import Solution
import sys
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(sys.stdin.readline().strip())
nums = list(map(int, sys.stdin.readline().strip().split()))

result = Solution().countSmaller(nums)
sys.stdout.write(' '.join([str(cnt) for cnt in result]) + '\n')

