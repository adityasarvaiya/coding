
def peaksAndValleys(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    arr.sort()
    for i in range(0,len(arr)-1,2):
        temp = arr[i] 
        arr[i] = arr[i+1]
        arr[i+1] = temp
    return arr
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
