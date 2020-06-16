def removeDuplicates(nums):
    # Your implementation goes here
    uniques = set()
    uniques.update(nums)
    return len(uniques)

if __name__ == '__main__':
    n = int(input())
    nums = []
    if n > 0:
        nums = input().split()
    nums = [int(i) for i in nums]
    result = removeDuplicates(nums)
    print(result)