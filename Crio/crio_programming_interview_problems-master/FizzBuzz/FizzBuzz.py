
def fizzBuzz(n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    lis=list()
    for i in range(1,n+1):
        if i%15 == 0:
            lis.append("FizzBuzz")
        elif i%5 == 0:
            lis.append("Buzz")
        elif i%3 == 0:
            lis.append("Fizz")
        else:
            lis.append(str(i))
    return lis
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    result = fizzBuzz(n)
    print('\n'.join([i for i in result]))

if __name__ == "__main__":
    main()
