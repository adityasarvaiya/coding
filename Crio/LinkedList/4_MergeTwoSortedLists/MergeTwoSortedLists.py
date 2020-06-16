from Solution import *
from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def print_list(head):
    while head != None:
        print(head.val, end = " ")
        head = head.next

def main():
    m = int(input().strip())
    nums1 = input().strip().split()
    nums1 = [int(x) for x in nums1]

    n = int(input().strip())
    nums2 = input().strip().split()
    nums2 = [int(x) for x in nums2]

    l1 = createList(nums1)
    l2 = createList(nums2)
    result = mergeTwoLists(l1, l2)
    print_list(result)

if __name__ == '__main__':
    main()

