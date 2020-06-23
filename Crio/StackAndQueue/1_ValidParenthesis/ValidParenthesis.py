def isValid(s):
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	stack = list()
	m = { "{": "}" , "[": "]" , "(" : ")" }
	for ch in s:
		if ch == "]" or ch =="}" or ch == ")":
			if len(stack) == 0:
				return "false"
			if ch == m[stack[-1]]:
				stack.pop()
			else:
				return "false"
		else:
			stack.append(ch)
	if len(stack) == 0:
		return "true"
	else:
		return "false"
	# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
	s = input().strip()
	result = isValid(s)
	print(result)
