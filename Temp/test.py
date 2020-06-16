
def find_unsorted_subarray(nums):
    if len(nums) == 0 or len(nums) == 1:
        return 0
    minUnsortedElement = float('inf')
    maxUnsortedElement = float('-inf')
    for i in range(0, len(nums)):
        current = nums[i]
        if isUnsortedCurrent(i, current, nums):
            minUnsortedElement = min(minUnsortedElement, current)
            maxUnsortedElement = max(maxUnsortedElement, current)
    if minUnsortedElement == float('inf') or maxUnsortedElement == float('-inf'):
        return 0
    for leftIndex in range(0, len(nums)):
        if minUnsortedElement < nums[leftIndex]:
            break
    for rightIndex in range(len(nums) - 1, -1, -1):
        if maxUnsortedElement > nums[rightIndex]:
            break
    return rightIndex - leftIndex + 1

def isUnsortedCurrent(i, current, nums):
    if i == 0:
        return current > nums[i+1]
    if i == len(nums) - 1:
        return current < nums[i-1]
    return current < nums[i-1] or current > nums[i+1]

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    answer = find_unsorted_subarray(nums)
    print(answer)


if __name__ == "__main__":
    main()