
def three_sums(nums, n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    nums.sort()
    ans = list()
    for i in range(n):
        j = i+1
        k = n-1
        if i > 0 and nums[i] == nums[i-1]:
            continue
        while j < k:
            if k < n-1 and nums[k] == nums[k+1]:
                k -= 1
                continue
            if nums[i] + nums[j] + nums[k] > 0:
                k -= 1
            elif nums[i] + nums[j] + nums[k] < 0:
                j += 1
            else:
                ans.append([nums[i], nums[j], nums[k]])
                j += 1
                k -= 1
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    result = three_sums(nums, n)
    for answer in result:
        print(' '.join([str(i) for i in answer]))

if __name__ == "__main__":
    main()
