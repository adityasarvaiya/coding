#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def steps(n, fromRod, toRod, auxRod, result):
    if n == 1:
        result.append("{} {} {}".format(n, fromRod, toRod))
        return
    
    steps(n - 1, fromRod, auxRod, toRod, result)
    result.append("{} {} {}".format(n, fromRod, toRod))
    steps(n - 1, auxRod, toRod, fromRod, result)
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def towerOfHanoi(n):
    #CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    result = []
    steps(n, 'A', 'C', 'B', result)
    return result
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    result = towerOfHanoi(n)
    for line in result:
        print(line)

if __name__ == '__main__':
    main()
