def containsDuplicate(nums):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return True

if __name__ == '__main__':
    n = int(input())
    nums = []
    if n > 0:
        nums = input().split()

    nums = [int(i) for i in nums]
    result = containsDuplicate(nums)
    if result:
        print('true')
    else:
        print('false')
