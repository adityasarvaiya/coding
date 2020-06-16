from crio.io import PrintMatrix

def twoSum(nums, target):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return [0, 0]

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    target = int(input())
    result = twoSum(nums, target)
    PrintMatrix.OneDMatrix(result, " ")
