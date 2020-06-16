
def houseThief(n,arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	dp=[0 for i in range(n+1)]
	dp[0]= arr[0]
	if n==1:
		return dp[0]
	dp[1]= max( dp[0], arr[1])
	for i in range(2,n):
		dp[i]=max( dp[i-1],arr[i]+dp[i-2])
	ans=max(dp)
	return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
	n=int(input());
	arr=list(map(int,input().split()))
	ans =houseThief(n,arr)
	print(ans)

if __name__ == '__main__':
	main()
