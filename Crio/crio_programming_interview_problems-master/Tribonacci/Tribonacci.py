def tribonacci(n):
	#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if n == 0:
        return 0
    if n <= 2:
        return 1
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    result = tribonacci(n)
    print(result)

if __name__ == '__main__':
    main()
