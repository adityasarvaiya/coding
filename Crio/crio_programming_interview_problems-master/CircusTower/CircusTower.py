def circusTower(n,arr):
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	arr.sort()
	dp=[1]*(n+1)
	for i in range(0,n):
		for j in range(i+1,n):
			if arr[j][0] > arr[i][0] and arr[j][1] > arr[i][1] :
				dp[j]= max( dp[j], dp[i]+1)
	 
	return max(dp)
	# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
	n=int(input())
	arr= []
	for i in range(n):	
		h,w=map(int,input().split())
		arr.append([h,w])
	ans =circusTower(n,arr)
	print(ans)


if __name__ == '__main__':
	main()