
class Solution:
    def findStartingIndex(self, nums, target):
        low = 0
        high = len(nums) - 1
        start = -1

        while (low <= high):
            mid = int(low + (high - low)/2)

            # If we find target still we will search on its left side
            if (nums[mid] == target):
                start = mid
                high = mid-1
            elif (nums[mid] > target) :    
                high = mid-1
            else :
                low = mid+1

        return start 

    def findEndingIndex(self, nums, target):
        low = 0
        high = len(nums) - 1
        end = -1

        while (low <= high):
            mid = int(low + (high - low)/2)
            
            # If we find target still we will search on its Right side
            if (nums[mid] == target):
                end = mid
                low = mid+1
            elif (nums[mid] > target) :    
                high = mid-1
            else :
                low = mid+1

        return end

    def searchRange(self, nums, target):
        
        # to find starting index of target in array nums
        start = self.findStartingIndex(nums, target)
        # to find ending index of target in array nums
        end = self.findEndingIndex(nums, target)

        ans = []
        ans.append(start)
        ans.append(end)
        return ans