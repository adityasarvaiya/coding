from Solution import *
from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def get_tail(head):
    tail = None
    while head != None:
        tail = head
        head = head.next
    return tail

def read_list_one():
   n = int(input().strip())
   lst = None
   if n > 0:
       lst = input().strip().split()
       lst = [int(x) for x in lst]
       lst = createList(lst)
   return lst


def main():
   l1 = read_list_one()
   l2 = read_list_one()
   l3 = read_list_one()
   
   l1_tail = get_tail(l1)
   l2_tail = get_tail(l2)
   if l1_tail != None:
       l1_tail.next = l3
   else:
       l1_tail = l3
       l1 = l3

   if l2_tail != None:
       l2_tail.next = l3
   else:
       l2_tail = l3 
       l2 = l3

   node = get_intersection_node(l1, l2)
   print(node.val if node != None else -1)

if __name__ == '__main__':
    main()


