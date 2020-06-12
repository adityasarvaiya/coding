from crio.ds.List.ListNode import *

# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#  TC : O( 1 )
#  SC : O( 1 )

def delete_middle_node(head, node):
    """
    :type node: ListNode
    :rtype: Return head
    """

    if node.next is not None:
        # make node.val equals to node.next.val
        node.val = node.next.val 

        # make node.next point to the next of the node.next
        node.next = node.next.next

    return head