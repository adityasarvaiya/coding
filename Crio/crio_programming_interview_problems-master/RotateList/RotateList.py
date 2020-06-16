from Solution import *
from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def print_list(head):
    while head != None:
        print(head.val, end = " ")
        head = head.next

def main():
   n = int(input().strip())
   lst = None
   lst = input().strip().split()
   lst = [int(x) for x in lst]
   lst = createList(lst)
   k = int(input().strip())
   
   print_list(rotate_list_by_k(lst, k))

if __name__ == '__main__':
    main()


