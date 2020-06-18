def largestRectangleInHistogram(heights):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    s = []
    ans = 0
    n = len(heights)
    i=0
    while(i<n):
        if(len(s)==0 or heights[s[-1]]<=heights[i]):
            s.append(i)
            i+=1
        else:
            x = s.pop()
            if len(s)>0:
                ans= max(ans,heights[x]*(i-s[-1]-1))
            else:
                ans= max(ans,heights[x]*i)

    while(len(s)>0):
        x = s.pop()
        if len(s)>0:
            ans= max(ans,heights[x]*(i-s[-1]-1))
        else:
            ans= max(ans,heights[x]*i)

    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    heights = []
    if n > 0:
        heights = input().split()
        heights = [int(i) for i in heights]

    result = largestRectangleInHistogram(heights)
    print(result)

