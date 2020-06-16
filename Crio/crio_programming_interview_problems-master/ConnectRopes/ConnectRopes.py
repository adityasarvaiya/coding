
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from queue import PriorityQueue
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def connectRopes(nums):
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	q= PriorityQueue()
	for i in range(0,len(nums)): 
		q.put(nums[i])
		answer =0
	while  q.qsize()>1:
		item1=q.get()
		item2=q.get()
		q.put(item1+item2)
		answer+=item1+item2
	return answer
	# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
	n =int(input())
	nums=[]
	nums=list(map(int ,input().split()))
	answer = connectRopes(nums)
	print(answer)
