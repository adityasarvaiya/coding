def get_intersection_node(lst1, lst2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    # Initialize pointer with first list
    iteratorForList1 = lst1

    # For every node in first list check if it is the intersection point
    while (iteratorForList1 != None):
        # For every node in List 1, start from the begining of the 2nd list
        iteratorForList2 = lst2

        while (iteratorForList2 != None) :
            # if at any point both nodes are same we will return that node
            if (iteratorForList1 == iteratorForList2):
                return iteratorForList1
            
            iteratorForList2 = iteratorForList2.next
        
        iteratorForList1 = iteratorForList1.next

    # If there is no intersection itself then return None
    return None
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS            
