from Solution import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    k = int(input())
    lis = list()
    for _ in range(k):
        _ = int(input())
        values = list(map(int, input().split()))
        head = createList(values)
        lis.append(head)
    ans = mergeKSortedLists(lis)
    while ans != None:
        print(ans.val,end = " ")
        ans = ans.next


if __name__ == "__main__":
    main()
