import sys
from Solution import Solution

q = int(sys.stdin.readline().strip())

solution = Solution()
for i in range(q):
    t, x = sys.stdin.readline().strip().split()
    x = int(x)
    if t == '+':
        solution.track(x)
    else:
        sys.stdout.write(str(solution.getRankOfNumber(x)) + '\n')

