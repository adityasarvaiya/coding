def numDecodings(digits: str) -> int: 
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	n= len(digits)
	mod = 1000000007
	if digits[0] == '0':
		return 0
	count = [0] * (n + 1); 
	count[0] = 1; 
	count[1] = 1; 
	for i in range(2, n + 1): 
		count[i] = 0; 
		if (digits[i - 1] > '0'): 
			count[i] = count[i - 1]%mod; 
		if (digits[i - 2] == '1' or
		(digits[i - 2] == '2' and
			digits[i - 1] < '7') ): 
			count[i] =((count[i]%mod)+(count[i - 2]%mod))%mod; 
	return count[n]; 
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = input()
    result = numDecodings(s)
    print(result)
    
