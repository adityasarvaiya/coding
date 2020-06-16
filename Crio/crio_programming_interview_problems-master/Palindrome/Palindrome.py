from Solution import *
from crio.ds.List.ListNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    testCases = int(input())
    for testCase in range(testCases):
        n = int(input().strip())
        lst = [int(x) for x in input().strip().split()]
        assert(len(lst) == n)
        lstToCheck = createList(lst)
        originalLst = createList(lst)
        
        isPalindrome = is_palindrome_list(lstToCheck)

        if not areListsEqual(lstToCheck, originalLst):
            print("Linked List has been modified")

        if isPalindrome:
            print("Yes")
        else:
            print("No")

def areListsEqual(head1, head2):
    while (head1 is not None and head2 is not None):
        if head1.val != head2.val:
            return False
        head1 = head1.next;
        head2 = head2.next;

    if (head1 is None and head2 is None):
        return True
    else:
        return False

if __name__ == '__main__':
    main()
