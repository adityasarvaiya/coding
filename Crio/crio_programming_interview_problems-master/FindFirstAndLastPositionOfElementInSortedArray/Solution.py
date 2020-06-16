
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def binarySearch(nums, target, compare):
    start = 0
    end = len(nums) - 1
    result = -1
    while(start <= end):
        mid = (start + end) // 2

        if compare(nums[mid], target):
            start = mid + 1
            if(nums[mid] == target):
                result = mid
        else:
            end = mid - 1
            if(nums[mid] == target):
                result = mid
    
    return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class Solution:
    def searchRange(self, nums, target):
        # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        first = binarySearch(nums, target, lambda a, b: a < b)
        second = binarySearch(nums, target, lambda a, b: a <= b)
        return [first, second]
        # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
