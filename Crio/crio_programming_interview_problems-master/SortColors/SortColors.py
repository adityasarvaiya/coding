from crio.io import PrintMatrix

def sortColors(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    nums1,nums2,nums0 = 0,0,0
    for i in nums:
        if i == 1:
            nums1+=1
        elif i == 2:
            nums2+=1
        elif i == 0:
            nums0+=1
    lis = [0]*nums0 + [1]*nums1 + [2]*nums2
    return lis
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    nums = sortColors(nums)
    PrintMatrix.OneDMatrix(nums, " ")
    