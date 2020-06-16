
def maximumXor(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    L = 31
    nums = [[(x >> i) & 1 for i in range(L)][::-1] for x in nums]
    max_xor = 0
    trie = dict()
    for num in nums:
        node = trie
        xor_node = trie
        curr_xor = 0
        for bit in num:
            if not bit in node:
                node[bit] = dict()
            node = node[bit]
            toggled_bit = bit^1
            if toggled_bit in xor_node:
                curr_xor = (curr_xor << 1) | 1
                xor_node = xor_node[toggled_bit]
            else:
                curr_xor = curr_xor << 1
                xor_node = xor_node[bit]
        max_xor = max(max_xor, curr_xor)
    return max_xor
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    arr = list(map(int,input().split()))
    res = maximumXor(arr)
    print(res)

if __name__ == "__main__":
    import sys
    sys.setrecursionlimit(10000)
    main()
