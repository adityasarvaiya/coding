# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class SegmentTree:
    def __init__(self , l , r , v):
        self.s = l
        self.e = r
        self.v = v
        self.left = None
        self.right = None

    def update(self, x):
        if self.s == self.e:
            self.v += 1
        else:
            m = (self.s + self.e) // 2
            if x <= m:
                if self.left == None:
                    self.left = SegmentTree(self.s , m , 0)
                self.left.update(x)
            else:
                if self.right == None:
                    self.right = SegmentTree(m + 1 , self.e , 0)
                self.right.update(x)
            self.v = 0
            if self.left != None:
                self.v += self.left.v
            if self.right != None:
                self.v += self.right.v

    def query(self, l , r):
        if self.s > r or self.e < l:
            return 0;

        if self.s >= l and self.e <= r:
            return self.v

        m = (self.s + self.e) // 2
        p1 = 0
        if self.left != None:
            p1 = self.left.query(l , r)
        p2 = 0
        if self.right != None:
            p2 = self.right.query(l , r)
        return p1 + p2

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

class Solution:
    def countSmaller(self, nums):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        result = [0 for i in range(len(nums))]
        MIN = -10**9
        MAX = 10**9
        segmentTree = SegmentTree(MIN, MAX, 0)
        for i in range(len(nums)-1,-1,-1):
            result[i] = segmentTree.query(MIN , nums[i] - 1)
            segmentTree.update(nums[i])
        return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
