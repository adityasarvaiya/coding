# SearchInRotatedSortedArray solution
def findInRotatedArray(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    
    #Initialize the array ends we are searching in
    leftIndex = 0
    rightIndex = len(nums)-1
    ans = -1

    #We will apply binary search to find the target
    while (leftIndex <= rightIndex):
        
        mid = int(leftIndex + (rightIndex - leftIndex)/2)
        
        if (nums[mid] == target):
            return mid

        # if mid to rightIndex is sorted 
        if (nums[mid] <= nums[rightIndex]):
            # if target lies sorted part
            if (target > nums[mid] and target <= nums[rightIndex]):
                leftIndex = mid+1
            else:
                rightIndex = mid-1
                
        # else leftIndex to mid is sorted
        else:
            # if target lies sorted part
            if (target >= nums[leftIndex] and target < nums[mid]):
                rightIndex = mid-1
            else:
                leftIndex = mid+1

    return ans

if __name__ == '__main__':
    n = int(input().strip())
    nums = [int(i) for i in input().strip().split()]
    q = int(input().strip())

    for i in range(q):
        target = int(input().strip())
        print(findInRotatedArray(nums, target))