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
    n = int(input())
    nums1 = input().split()
    nums1 = [int(i) for i in nums1]
    m = int(input())
    nums2 = input().split()
    nums2 = [int(i) for i in nums2]
    l1 = createList(nums1)
    l2 = createList(nums2)
    resultList = addTwoNumbers(l1, l2)
    result = extractList(resultList)
    for i in result:
        print(i,end=' ')
