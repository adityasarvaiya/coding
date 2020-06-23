from crio.ds.List.ListNode import *

'''
# Definition for ListNode
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''

def mergeKSortedLists(lis):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    nodes = list()
    point = ListNode(0)
    head = point
    for l in lis:
        while l != None:
            nodes.append(l.val)
            l = l.next
    nodes.sort()
    for x in nodes:
        point.next = ListNode(x)
        point = point.next
    return head.next 
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
