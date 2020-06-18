def get_intersection_node(lst1, lst2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    # Create set for containing all the nodes of list 1
    HashTableSet = set()
    iterator = lst1
    while (iterator != None):
        HashTableSet.add(iterator)
        iterator = iterator.next

    # For every node in list 2 check if it already exists in set
    iterator = lst2
    while (iterator != None):
        # If same node present in set that means it is the intersection point
        if iterator in HashTableSet:
            return iterator

        iterator = iterator.next
    
    # If there is no intersection itself then return None
    return None
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS            
