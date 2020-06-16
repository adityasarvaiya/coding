def isValidSudoku(grid):
    # TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    # Your implementation goes here

    return False

if __name__ == '__main__':
    grid = []
    for i in range(9):
        nums = input().split()
        grid.append(nums)
    if isValidSudoku(grid):
        print('true')
    else:
        print('false')
