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


class Solution:
    def __init__(self):
        self.root = SegmentTree(0, 10 ** 9 , 0)
    def track(self, x):
        self.root.update(x)

    def getRankOfNumber(self, x):
        return self.root.query(0, x)
