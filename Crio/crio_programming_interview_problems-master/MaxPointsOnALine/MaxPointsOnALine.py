
def maxPoints(points):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(points)
    if n<3: 
        return n
    max_val=0
    for i in points:
        d = {}  
        dups = 0
        cur_max = 0 
        for j in points: 
            if i!=j: 
                if j[0]==i[0]:
                    slope='inf'
                else: 
                    slope=float(j[1]-i[1])/float(j[0]-i[0])
                d[slope] = d.get(slope,0)+1
                cur_max=max(cur_max, d[slope])
            else: 
                dups+=1
        max_val=max(max_val, cur_max+dups)
    return max_val 
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    points = list()
    for i in range(n):
        point = list(map(int,input().split()))
        points.append(point)
    result = maxPoints(points)
    print(result)


if __name__ == "__main__":
    main()