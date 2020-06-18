from crio.ds.List.ListNode import *

'''
# Definition for ListNode
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''

def partition(head, x) : 
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    smallerHead = None
    smallerLast = None
    greaterLast = None
    greaterHead = None
    equalHead = None
    equalLast = None
  
    while (head != None) : 
        if (head.val == x):  
            if (equalHead == None):  
                equalHead = equalLast = head  
            else: 
                equalLast.next = head  
                equalLast = equalLast.next
        elif (head.val < x):  
            if (smallerHead == None):  
                smallerLast = smallerHead = head  
            else: 
                smallerLast.next = head  
                smallerLast = head  
        else : 
            if (greaterHead == None) : 
                greaterLast = greaterHead = head  
            else: 
                greaterLast.next = head  
                greaterLast = head  
        head = head.next
      
    if (greaterLast != None) : 
        greaterLast.next = None
    if (smallerHead == None) : 
        if (equalHead == None) : 
            return greaterHead  
        equalLast.next = greaterHead  
        return equalHead  
    if (equalHead == None) : 
        smallerLast.next = greaterHead  
        return smallerHead  
      
    smallerLast.next = equalHead  
    equalLast.next = greaterHead  
    return smallerHead  
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
