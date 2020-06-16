def meetingRooms(meetings):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    intervals = []

    for meeting in meetings:
        intervals.append((meeting[0],1))
        intervals.append((meeting[1],-1))
    
    ans = 0
    sum = 0

    for interval in sorted(intervals):
        sum+=interval[1]
        ans = max(ans,sum)
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input().strip())
    meetings = list()

    for _ in range(n):
        meetings.append(list(map(int,input().strip().split())))

    answer = meetingRooms(meetings)
    print(answer)

if __name__=="__main__":
    main()
