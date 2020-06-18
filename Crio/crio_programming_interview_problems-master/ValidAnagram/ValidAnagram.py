def validAnagram(s, t):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if(len(s)!=len(t)):
        return False
    m = [0]*26
    for ch in s:
        m[ord(ch)-ord('a')]+=1
    for ch in t:
        if(m[ord(ch)-ord('a')]>0):
            m[ord(ch)-ord('a')]-=1
        else:
            return False
    return True
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = input()
    t = input()
    if validAnagram(s, t):
        print('true')
    else:
        print('false')
