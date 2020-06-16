from crio.ds.List import ListNode

def hasCycle(head):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return True

if __name__ == '__main__':
    nums = input().split()
    nums = [int(i) for i in nums]
    pos = int(input())
    head = ListNode.generateLinkedListWithCycle(nums, pos)
    result = hasCycle(head)
    if result:
        print('true')
    else:
        print('false')

