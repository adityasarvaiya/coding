def romanToInt(s):
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	mapped = { "I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000,"IV":4,"IX":9,"XL":40,"XC":90,"CD":400,"CM":900}
	n = len(s)
	ans , i  = 0 , 0 
	while i < n:
		if i+1 < n and s[i:i+2] in mapped:
			ans += mapped[s[i:i+2]]
			i+=2
		else:
			ans += mapped[s[i]]
			i+=1
	return ans
	# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = input()
    result = romanToInt(s)
    print(result)
