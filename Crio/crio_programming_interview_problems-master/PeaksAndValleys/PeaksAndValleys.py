from Solution import peaksAndValleys
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n=int(input())
    integers = list(map(int,input().split()))
    result = peaksAndValleys(integers)
    print(' '.join([str(i) for i in result]))

if __name__ == "__main__":
    main()
