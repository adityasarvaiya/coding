
def findMissingRanges(lis,lower,upper):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    iterator = lower
    result=list()
    lis.append(upper+1)
    for i in lis:
        if i>iterator+1:
            result.append(str(iterator)+"->"+str(i-1))
        elif i==iterator+1:
            result.append(str(iterator))
        iterator = i+1
    return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n=int(input())
    lower,upper = map(int,input().split())
    if n==0:
        lis=list()
    else:
        lis = list(map(int,input().split()))
    result = findMissingRanges(lis,lower,upper)
    print('\n'.join([i for i in result]))

if __name__ == "__main__":
    main()
