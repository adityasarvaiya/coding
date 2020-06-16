# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class Segtree:
    def __init__(self , n , values):
        self.n = n
        self.tree = [0 for i in range(2*n)]
        self.tree[n:2*n] = values

    def build(self):
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = min(self.tree[i<<1], self.tree[i<<1|1])
     
    def update(self,p, value):
        p += self.n
        self.tree[p] = value
        while p > 1:
            self.tree[p>>1] = min(self.tree[p], self.tree[p^1])
            p >>= 1
     
    def query(self,l, r):
        res = 10**9+1
        l += self.n
        r += self.n
        while l < r:
            if (l&1):
                res = min(res, self.tree[l])
                l+=1
            if (r&1):
                res = min(res, self.tree[r-1])
                r-=1
            l >>= 1
            r >>= 1
        return res
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def lilliput(n , height , q, queries):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    segmentTree = Segtree(n ,height)
    segmentTree.build()
    ans = list()
    for qu in queries:
        if qu[0] == 'q':
            ans.append(segmentTree.query(qu[1], qu[2]+1))
        else: 
            segmentTree.update(qu[1],qu[2])
    return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    height = list(map(int, input().split()))
    q = int(input())
    queries = list()
    for i in range(q):
        query = input().split()
        query[1] = int(query[1])
        query[2] = int(query[2])
        queries.append(query)
    res = lilliput(n, height, q, queries)
    print("\n".join(map(str,res)))

if __name__ == "__main__":
    main()
