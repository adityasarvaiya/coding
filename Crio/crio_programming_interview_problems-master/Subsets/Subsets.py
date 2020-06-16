from crio.io import PrintMatrix

def subsets(nums):
    res = []
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    return res

if __name__ == '__main__':
    n = int(input())
    nums = []
    if n > 0:
        nums = input().split()
    nums = [int(i) for i in nums]
    result = subsets(nums)
    PrintMatrix.TwoDMatrix(result)

