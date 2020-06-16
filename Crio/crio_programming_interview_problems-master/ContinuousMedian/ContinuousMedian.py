
def continuousMedian(arr):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    from heapq import heappush, heappop, heapify
    medians = list()
    maxheap = list()   # max heap
    minheap = list()     # min heap
    for element in arr:
        heappush(maxheap, -element)
        heappush(minheap, -maxheap[0])
        heappop(maxheap)
        if len(maxheap) < len(minheap):
            heappush(maxheap, -minheap[0])
            heappop(minheap)
        if len(maxheap) == len(minheap):
            medians.append( int((-maxheap[0] + minheap[0])/2))
        else:
            medians.append(-maxheap[0])
    return medians
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    n= int(input())
    arr = list(map(int,input().split()))
    answer = continuousMedian(arr)
    print('\n'.join(map(str, answer)))

if __name__ == "__main__":
    main()


