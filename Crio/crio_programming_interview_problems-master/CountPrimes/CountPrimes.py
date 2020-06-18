import math
def countPrimes(n):
	ans = 0
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	for number in range(2,n):
		flag = True
		for i in range(2,int(math.sqrt(number))+1):
			if number%i==0:
				flag=False
				break
		if flag:
			ans+=1

	# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	return ans

if __name__ == '__main__':
	n = int(input())
	result = countPrimes(n)
	print(result)
