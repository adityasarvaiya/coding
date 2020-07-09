# Steps:
# 1. check if number of elements are less the equals to 1
# 2. Else Initialise 2 varibles, both pointing starting of the array (index)
# 3. Iterate over the array with one pointer and use second pointer to keep track of number of unique elements found
# 4. Return number of unique elements 

def removeDuplicates(nums):
    """
    :type nums: List[int]
    :return type: int
    """
    
    # Your implementation goes here

    # 1. check if number of elements are less the equals to 1
    numElements = len(nums)
    if numElements <= 1:
        return numElements

    # 2. Else Initialise 2 varibles, both pointing starting of the array (index)
    pointer1 = 0
    pointer2 = 0
    
    # 3. Iterate over the array with one pointer and use second pointer to keep track of number of unique elements found
    while pointer2 < numElements:
        if nums[pointer2] == nums[pointer1]:
            pointer2 += 1
        else:
            pointer1 += 1
            nums[pointer1] = nums[pointer2]
            pointer2 += 1

    # 4. Return number of unique elements 
    return pointer1 + 1


if __name__ == '__main__':
    n = int(input())
    nums = []
    if n > 0:
        nums = input().split()
    nums = [int(i) for i in nums]
    result = removeDuplicates(nums)
    print(result)


































