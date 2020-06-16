def subSort(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(arr)
    e = n-1

    for s in range(0,n-1): 
        if arr[s] > arr[s+1]: 
            break
          
    if s == n-1: 
        return -1, -1
  
    e= n-1
    while e > 0: 
        if arr[e] < arr[e-1]: 
            break
        e -= 1
  
    max = arr[s] 
    min = arr[s] 
    for i in range(s+1,e+1): 
        if arr[i] > max: 
            max = arr[i] 
        if arr[i] < min: 
            min = arr[i] 
              
    for i in range(s): 
        if arr[i] > min: 
            s = i 
            break
  
    i = n-1
    while i >= e+1: 
        if arr[i] < max: 
            e = i 
            break
        i -= 1
    if s > e:
        return -1, -1
    return s, e
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    
n = int(input())
arr = list(map(int, input().strip().split()))

left, right = subSort(arr)
print(left, right)
