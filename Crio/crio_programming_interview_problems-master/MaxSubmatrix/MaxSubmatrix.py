def maxSubmatrix(n,m,matrix):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    max_sum = -1e9
    for row in matrix:
        for x in row:
            max_sum = max(max_sum,x)
    
    if max_sum<0:
        return max_sum

    
    for left in range(m):
        tmp = [0 for _ in range(n)]
        for right in range(left,m):
            for i in range(n):
                tmp[i]+=matrix[i][right]
            curr_sum=0
            for i in range(n):
                curr_sum+=tmp[i]
                if(curr_sum<0):
                    curr_sum=0
            max_sum = max(max_sum,curr_sum)
    
    

    return max_sum
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,m = map(int,input().strip().split())
    matrix = []
    for _ in range(n):
        tmp = list(map(int,input().strip().split()))
        matrix.append(tmp)  
    ans = maxSubmatrix(n,m,matrix)
    print(ans)

if __name__=="__main__":
    main()