

def PhoneDigits(digits):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    res=['']
    hashtable = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z'] }
    for dig in digits:
        newset = hashtable[dig]
        r=[]
        for string in res:
            for val in newset:
                r.append(string+val)
        res=r
    if len(digits)==0:
        return []
    return res
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    # t=int(input())
    t=1
    for _ in range(t):
        n=int(input())
        lis = input().split()

        result = PhoneDigits(lis)
        print(' '.join([string for string in result]))


if __name__ == "__main__":
    main()
