
def minimumJumps(arr, n): 
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    inf = 1e9
    jumps = [0 for i in range(n)]
    jumps[0] = 0
    for i in range(1, n): 
        jumps[i] = inf
        for j in range(i): 
            if (i <= j + arr[j]) and (jumps[j] != inf ): 
                jumps[i] = min(jumps[i], jumps[j] + 1) 
                break
    return jumps[n-1] if jumps[n-1] != inf else -1
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    lis = list(map(int, input().split() ))
    result  = minimumJumps(lis, n)
    print(result)

if __name__ == "__main__":
    main()
