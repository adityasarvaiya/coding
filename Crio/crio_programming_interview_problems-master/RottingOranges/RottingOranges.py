from queue import Queue

def rottingOranges(a):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if len(a)==0:
        return 0
    if len(a[0])==0:
        return 0
    
    n = len(a)
    m = len(a[0])   
    cnt =0
    q = Queue()

    for i in range(n):
        for j in range(m):
            if a[i][j]==2:
                q.put(i*m+j)
            elif a[i][j]==1:
                cnt +=1
    ans =0
    dir = [-1,0,1,0,-1]
    while True:
        temp = Queue()
        while q.qsize():
            top = q.get()
            topx = int(top/m)
            topy = top%m

            for i in range(4):
                x = topx+dir[i]
                y = topy+dir[i+1]

                if x>=0 and x<n and y>=0 and y<m and a[x][y]==1:
                    cnt-=1
                    a[x][y]=2
                    temp.put(x*m+y)
        if temp.qsize()==0:
            break
        else:
            ans+=1 
            q = temp

    if cnt==0:
        return ans
    else: return -1
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    t= int(input())
    while t>0:
        n,m = map(int,input().split())
        oranges = []
        for i in range(n):
            oranges.append(list(map(int,input().strip().split())))
        ans= rottingOranges(oranges)
        print(ans)
        t-=1

if __name__ == "__main__":
    main()
