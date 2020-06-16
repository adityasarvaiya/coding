def subarraySumZero(n,arr):
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	sum=0
	M= dict()
	for i in range (0,n):
		sum+= arr[i]
		
		if sum == 0:
			return "Yes"
		if sum in M:
			return "Yes"
		M[sum]=1

	return "No"
	# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
	test=int(input())
	for t in range (test): 
		n= int(input())
		arr = list(map(int,input().strip().split()))
		result=subarraySumZero(n,arr)
		print(result)
                
if __name__ == "__main__":
    main()
