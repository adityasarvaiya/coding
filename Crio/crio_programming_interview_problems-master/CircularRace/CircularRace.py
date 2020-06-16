def circularRace(n,gas,burn):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    starting_point = 0
    curr_tank=0
    total_tank=0

    for i in range(n):
        total_tank +=(gas[i]-burn[i])
        curr_tank+=(gas[i]-burn[i])
        if curr_tank<0:
            starting_point = i+1
            curr_tank=0
        
    if total_tank <0:
        return -1
    return starting_point+1
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input().strip())
    gas = list(map(int,input().strip().split()))
    burn = list(map(int,input().strip().split()))
    
    ans = circularRace(n,gas,burn)
    print(ans)

if __name__ == "__main__":
    main()
