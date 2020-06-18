# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from collections import defaultdict
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def minimumWindowSubstring(s,t):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    m = defaultdict(int)
    ans = ""
    for ch in t:
        m[ch]+=1
    l,start = len(s)+1,0
    i,j=0,0
    while(i<len(s) or j<len(s)):
        if (all(x<=0 for x in m.values())):
            if(l>j-i):
                l,start = j-i, i
            m[s[i]]+=1
            i+=1
        else:
            if(j>=len(s)):
                break
            m[s[j]]-=1
            j+=1

    if(l==len(s)+1):
        return ans
    ans = s[start:start+l]
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == "__main__":
    s = input()
    t = input()
    ans = minimumWindowSubstring(s,t)
    print(ans)