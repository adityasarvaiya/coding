import sys
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
dp=list()
cnt = 0
def cal(word1,word2,n,m):
	if n==0:
		return m
	if m==0:
		return n
	global dp
	global cnt
	if dp[n-1][m-1] != -1:
		return dp[n-1][m-1]
	cnt+=1
	if word1[n-1]== word2[m-1]:
		dp[n-1][m-1] = cal(word1,word2,n-1,m-1)
		return dp[n-1][m-1]  
	x= cal(word1,word2,n,m-1)
	y= cal(word1,word2,n-1,m)
	z= cal(word1,word2,n-1,m-1)

	dp[n-1][m-1]=1+min(x,y,z)
	return dp[n-1][m-1]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def editDistance(word1,word2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	n=len(word1)
	m=len(word2)
	global dp
	global cnt
	dp =[[-1 for x in range(m+1)] for y in range(n+1)] 
	ans=cal(word1,word2,n,m)
	return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
	word1=input()
	word2=input()
	sys.setrecursionlimit(1000000)
	ans=editDistance(word1,word2)
	print(ans)


if __name__ == '__main__':
	main()
