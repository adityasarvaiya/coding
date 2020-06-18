def titleToNumber(s):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    result = 0
    for ch in s:
	    result = result*26 + ( ord(ch) - ord('A') + 1)
    return result
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = input()
    result = titleToNumber(s)
    print(result)
