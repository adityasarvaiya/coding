from Solution import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def createList(numbers):
	if(len(numbers) == 0):
		return None

	head = ListNode(numbers[0])
	node = head
	for i in range(1, len(numbers)):
		node.next = ListNode(numbers[i])
		node = node.next

	return head

def extractList(head):
	arr = []

	while(head):
		arr.append(head.val)
		head = head.next

	return arr

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    k = int(row[1])
    nums = input().split()
    nums = [int(i) for i in nums]
    List = createList(nums)
    result = removeNthNodeFromEndOflist(List, k)
    res = extractList(result)
    for i in res:
        print(i,end=' ')
