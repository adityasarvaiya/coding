def plusOne(digits):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    f = 1
    ans = []
    for i in digits[::-1]:
        if i < 9 and f:
            ans = [0]*len(ans)
            ans.append(i+1)
            f=0
        else:
            ans.append(i)
    if f:
        ans = [0]*len(ans)
        ans.append(1)
    return reversed(ans)
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
if __name__ == '__main__':
    digits = input().split()
    digits = [int(i) for i in digits]
    result = plusOne(digits)
    for i in result:
        print(i,end=' ')

