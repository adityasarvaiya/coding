
def findKthLargest(nums, k):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    import heapq
    return heapq.nlargest(k, nums)[-1]
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    k = int(input())
    result = findKthLargest(nums, k)
    print(result)
    
