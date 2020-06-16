def fractionToRecurringDecimal(numerator, denominator):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    res = ""
    num = abs(numerator)
    den = abs(denominator)
    if(numerator*denominator<0):
        res+='-'
    res+=str(num//den)
    rem = num%den
    m = dict()
    afterD = ""
    while(rem>0 and not m.get(rem)):
        m[rem] = len(afterD)+1
        rem*=10
        afterD+=str(rem//den)
        rem%=den
    if(rem==0):
        if(len(afterD)>0):
            res+='.'
            res+=afterD
    else:
        res+='.'
        for ch in afterD[:m.get(rem)-1]:
            res+=ch
        res+='('
        for ch in afterD[m.get(rem)-1:]:
            res+=ch
        res+=')'
    return res
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    row = input().split()
    numerator = int(row[0])
    denominator = int(row[1])
    result = fractionToRecurringDecimal(numerator, denominator)
    print(result)

