# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def countPermutations(arr, factorial):
    return factorial[len(arr)]

def findKthPermutation(arr, k, factorial):
    if len(arr) == 1:
        return arr

    n = len(arr)
    
    for i in range(n):
        curr = arr[i]
        newArr = arr[:i] + arr[i+1:]
        newArrPermutationCount = countPermutations(newArr, factorial)
        if k > newArrPermutationCount:
            k -= newArrPermutationCount
            continue
        return curr + findKthPermutation(newArr, k, factorial)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def kThPermutation(n, k):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    arr = ''.join(chr(65 + i) for i in range(n))

    factorial = [1 for i in range(n + 1)]
    for i in range(1, n + 1):
        factorial[i] = i * factorial[i-1]

    return findKthPermutation(arr, k, factorial)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n, k = map(int, input().strip().split())

    result = kThPermutation(n, k)
    print(result)

if __name__ == '__main__':
    main()
