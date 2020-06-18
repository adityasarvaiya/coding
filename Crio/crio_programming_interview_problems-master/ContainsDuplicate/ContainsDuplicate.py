def containsDuplicate(nums):
    nums = sorted(nums)
    for i in range(len(nums)-1):
        if nums[i]==nums[i+1]:
            return True

    return False

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
