def moduloUsingRecursion(a, b):
	#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if b == 0:
        return -1
    if a < b:
        return a
    
    return moduloUsingRecursion(a - b, b)
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    a, b = map(int, input().split())
    result = moduloUsingRecursion(a, b)
    print(result)

if __name__ == '__main__':
    main()
