
def permute(lis):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if len(lis) == 0:
        return []
    if len(lis) == 1:
        return [lis]
    l=[]
    for i in range(len(lis)):
        m=lis[i]
        remain = lis[:i] + lis[i+1:]
        for p in permute(remain):
            l.append([m]+p)
    return l
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def permutationWIthDups(string):
#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    lis = permute(list(string))
    result = set()
    for perm in lis: 
         result.add(''.join(perm))
    return list(result)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    
def main():
    string = input()
    result = permutationWIthDups(string)
    print('\n'.join([i for i in result]))

if __name__ == "__main__":
    main()
