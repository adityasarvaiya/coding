def letterCombinationsOfPhoneNumber(digits):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    res = []
    digits = str(digits)
    h = {
        '2':['a','b','c'],
        '3':['d','e','f'],
        '4':['g','h','i'],
        '5':['j','k','l'],
        '6':['m','n','o'],
        '7':['p','q','r','s'],
        '8':['t','u','v'],
        '9':['w','x','y','z']
    }
    for ch in h[digits[0]]:
        res.append(ch)
    for d in digits[1:]:
        t = []
        for r in res:
            for ch in h[d]:
                t.append(r+ch)
        res = t
    sorted(res)
    return res
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    digits = input()
    result = letterCombinationsOfPhoneNumber(digits)
    print(*result)
