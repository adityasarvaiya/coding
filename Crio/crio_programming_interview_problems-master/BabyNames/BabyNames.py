import sys
class DSU:
    def __init__(self, n, names, frequency):
        self.parent = [i for i in range(n)]
        self.sz = [1 for i in range(n)]
        self.names = [names[i] for i in range(n)]
        self.frequency = [frequency[i] for i in range(n)]

    def root(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.root(self.parent[x])
        return self.parent[x]
    def isRoot(self, x):
        return x == self.parent[x]

    def __add(self, a, b):
        self.parent[b] = a
        self.sz[a] += self.sz[b]
        self.frequency[a] += self.frequency[b]
        if self.names[a] > self.names[b]:
            self.names[a] = self.names[b]
        
    def join(self, a, b):
        a = self.root(a)
        b = self.root(b)
        if a == b:
            return
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.__add(a, b)
        
def babyNames(names, frequency, synonymPairs):
    indexMap = {names[i]: i for i in range(len(names))}

    for synonymPair in synonymPairs:
        a = synonymPair[0]
        b = synonymPair[1]
        if a not in indexMap:
            indexMap[a] = len(names)
            names.append(a)
            frequency.append(0)
        if b not in indexMap:
            indexMap[b] = len(names)
            names.append(b)
            frequency.append(0)

    dsu = DSU(len(names), names, frequency)
    for synonymPair in synonymPairs:
        a = synonymPair[0]
        b = synonymPair[1]
        dsu.join(indexMap[a], indexMap[b])
    result = []
    for i in range(len(names)):
        if dsu.isRoot(i):
            result.append([dsu.names[i], dsu.frequency[i]%1000000007])
    return sorted(result)

n = int(sys.stdin.readline())
names = ['' for i in range(n)]
frequency = [0 for i in range(n)]

for i in range(n):
    names[i], frequency[i] = sys.stdin.readline().strip().split()
    frequency[i] = int(frequency[i])

m = int(sys.stdin.readline())
synonymPairs = [[] for i in range(m)]
for i in range(m):
    synonymPairs[i] = sys.stdin.readline().strip().split()

result = babyNames(names, frequency, synonymPairs)
for name, frequency in result:
    print(name, frequency)