def cuttingPalindrome(n,s):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    INT_MAX = 5000
    is_palindrome = [ [ False for _ in range(n)] for _ in range(n) ]
    for i in range(n):
        is_palindrome[i][i]=True
    cuts = [INT_MAX for _ in range(n)]

    for length in range(2,n+1):
        for i in range(n-length+1):
            j = i+length-1
            if length==2:
                if s[i]==s[j]:
                    is_palindrome[i][j]=True
            else: 
                if s[i]==s[j] and is_palindrome[i+1][j-1]:
                    is_palindrome[i][j]=True
    
    cuts[0]=0
    for i in range(1,n):
        if is_palindrome[0][i]:
            cuts[i]=0
        else:
            minimum_previous_cuts=INT_MAX
            for j in range(i):
                if is_palindrome[j+1][i] and cuts[j]<minimum_previous_cuts:
                    minimum_previous_cuts = cuts[j]
            cuts[i]=minimum_previous_cuts+1
    
    return cuts[n-1]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    s = input().strip()
    ans = cuttingPalindrome(n,s)
    print(ans)

if __name__=="__main__":
    main()        

