def shortestSupersequence(longer_size,longer_array,shorter_size,shorter_array):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ans = 1e9
    n = longer_size
    m = shorter_size
    
    M = dict()
    for x in shorter_array:
        if x in M:    
            M[x] = M[x]+1
        else: M[x]=1
    
    required_numbers = len(M)
    formed =0
    left = 0
    right = 0
    curr_map = dict()

    while right < n:
        if longer_array[right] in curr_map:
            curr_map[longer_array[right]]=curr_map[longer_array[right]]+1
        else:
            curr_map[longer_array[right]]=1

        if longer_array[right] in M and curr_map[longer_array[right]]==M[longer_array[right]]:
            formed+=1
        

        while left<=right and formed==required_numbers:
            ans = min(ans,right-left+1)

            curr_map[longer_array[left]]-=1
            if longer_array[left] in M and curr_map[longer_array[left]]<M[longer_array[left]]:
                formed-=1
            
            left+=1
        right+=1
    
    if ans==1e9:
        return -1
    else:
        return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,m = map(int,input().strip().split())
    ar = list(map(int,input().strip().split()))
    br = list(map(int,input().strip().split()))
    if n<m:
        tmp = n
        n = m
        m = tmp
        tmp = ar
        ar = br
        br = tmp
    ans = shortestSupersequence(n,ar,m,br)
    print(ans)

if __name__ == "__main__":
    main()