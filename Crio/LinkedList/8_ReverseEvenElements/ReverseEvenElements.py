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
   if n > 0:
       lst = input().strip().split()
       lst = [int(x) for x in lst]
       lst = createList(lst)
   
   print_list(reverse_continuous_even_elements(lst))

if __name__ == '__main__':
    main()
