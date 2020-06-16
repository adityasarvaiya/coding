#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
class SegmentTree:
    def __init__(self, L):
        assert L != []
        self.N = 1
        while self.N < len(L):
            self.N *= 2
        self.c = [0] * (2 * self.N)
        self.s = [0] * (2 * self.N)
        self.w = [0] * (2 * self.N)
        for i in range(len(L)):
            self.w[self.N + i] = L[i]
        for p in range(self.N - 1, 0, -1):
            self.w[p] = self.w[2 * p] + self.w[2 * p + 1]

    def cover(self):
        return self.s[1]


    def change(self, i, k, delta):
        self._change(1, 0, self.N, i, k, delta)


    def _change(self, p, start, span, i, k, delta):
        if start + span <= i or k <= start:
            return
        if i <= start and start + span <= k:
            self.c[p] += delta
        else:
            self._change(2 * p, start, span // 2, i, k, delta)
            self._change(2 * p + 1, start + span // 2, span // 2,
                         i, k, delta)
        if self.c[p] == 0:
            if p >= self.N:
                self.s[p] = 0
            else:
                self.s[p] = self.s[2 * p] + self.s[2 * p + 1]
        else:
            self.s[p] = self.w[p]
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def rectangleArea(n, rectangles):
#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    MOD  = 10**9 + 7
    if n == 0:
        return 0
    X = list()
    Y = list()
    for j in range(n):
        (x1, y1, x2, y2) = rectangles[j]
        assert x1 <= x2 and y1 <= y2
        X.append(x1)
        X.append(x2)
        Y.append((y1, +1, j))
        Y.append((y2, -1, j))
    X.sort()
    Y.sort()
    X2i = {X[i]: i for i in range(len(X))}
    L = [X[i + 1] - X[i] for i in range(len(X) - 1)]
    C = SegmentTree(L)
    area = 0
    last = 0
    for (y, delta, j) in Y:
        area += (y - last) * C.cover()
        last = y
        (x1, y1, x2, y2) = rectangles[j]
        i = X2i[x1]
        k = X2i[x2]
        C.change(i, k, delta)
    return area% MOD
#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    n = int(input())
    rectangles = []
    for i in range(n):
        rectangles.append(list(map(int,input().split())))
    ans  = rectangleArea(n, rectangles)
    print(ans)

if __name__ == "__main__":
    import sys
    sys.setrecursionlimit(10000)
    main()
