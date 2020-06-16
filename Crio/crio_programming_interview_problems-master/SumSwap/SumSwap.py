def find_pair(l1, l2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    s1 = sum(l1)
    s2 = sum(l2)

    if s1 == s2:
        return "ALREADY EQUAL"
    
    dict_of_two_times_e1 = {2 * one_elem : True for one_elem in l1} 

    # s1 - e1 + e2 = s2 - e2 + e1
    for e2 in l2:
        two_times_e1 = (s1 - s2 + 2 * e2)
        if two_times_e1 in dict_of_two_times_e1:
            return "POSSIBLE"

    return "NOT POSSIBLE"
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    (n, m) = [int(x) for x in input().strip().split()]
    l1 = [int(x) for x in input().strip().split()]
    l2 = [int(x) for x in input().strip().split()]

    print(find_pair(l1, l2))

if __name__ == '__main__': 
    main()
