def theMesseuse(n,appointments):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    time= [0 for _ in range(n)]
    time[0]=appointments[0]
    time[1]=max(time[0],appointments[1])
    for i in range(2,n):
        time[i] =  max(time[i-1],time[i-2]+appointments[i])
    return time[n-1]
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input().strip())
    appointments = list(map(int,input().strip().split()))
    ans = theMesseuse(n,appointments)
    print(ans)

if __name__=="__main__":
    main()
