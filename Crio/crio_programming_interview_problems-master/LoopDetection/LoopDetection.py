from Solution import *
from crio.ds.List.ListNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
   n = int(input().strip())
   lst = input().strip().split()
   lst = [int(x) for x in lst]
   k = int(input().strip()) 
   lst = generateLinkedListWithCycle(lst, k-1)
   
   node = get_loop_start(lst)
 
   if node != None:
      print(node.val)
   else:
      print("-1")

if __name__ == '__main__':
    main()


