import queue

def firstUniqueInteger(lis):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(lis)
    q = queue.Queue()
    m = dict()
    for el in lis:
        if el not in m:
            q.put(el)
            m[el]=0
        m[el]+=1
    while not q.empty():
        number = q.queue[0]
        q.get()
        if m[number] == 1:
            return number
    return -1 
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    lis = list(map(int,input().split()))
    assert len(lis) == n
    result = firstUniqueInteger(lis)
    print(result)

if __name__ == "__main__":
    main()
