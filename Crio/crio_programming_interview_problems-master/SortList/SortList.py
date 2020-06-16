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
   if n > 0 :
      lst = [int(x) for x in input().strip().split()]
      lst = createList(lst)
      print_list(sort_list(lst))
   else:
      print_list(sort_list(None))

if __name__ == '__main__':
    main()
