from crio.io import PrintMatrix

def merge(nums1, m, nums2, n):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return []

if __name__ == '__main__':
    m = int(input())
    n = int(input())
    nums1 = input().split()
    nums1 = [int(i) for i in nums1]
    nums2 = input().split()
    nums2 = [int(i) for i in nums2]
    for i in range(m, m+n):
        nums1.append(0)
    result = merge(nums1, m, nums2, n)
    PrintMatrix.OneDMatrix(nums1, " ")
