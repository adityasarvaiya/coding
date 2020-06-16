from crio.io import PrintMatrix
from crio.ds.List import ListNode

def addTwoNumbers(l1, l2):
    # TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    # Your implementation goes here

    return []

if __name__ == '__main__':
    n = int(input())
    nums1 = input().split()
    nums1 = [int(i) for i in nums1]
    m = int(input())
    nums2 = input().split()
    nums2 = [int(i) for i in nums2]
    l1 = ListNode.createList(nums1)
    l2 = ListNode.createList(nums2)
    resultList = addTwoNumbers(l1, l2)
    result = ListNode.extractList(resultList)
    PrintMatrix.OneDMatrix(result, " ")
