from crio.io import PrintMatrix

def rotate(matrix):
    # TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    # Your implementation goes here

    return []

if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        nums = input().split()
        nums = [int(i) for i in nums]
        matrix.append(nums)
    rotate(matrix)
    PrintMatrix.SquareMatrix(matrix)

