
def find_unsorted_subarray(nums):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    copy = nums.copy()
    n = len(nums)
    copy.sort()
    start = -1
    last = -1
    for i in range(n):
        if copy[i] != nums[i]:
            start = i
            break

    for i in range(n-1, -1, -1):
        if copy[i] != nums[i]:
            last = i
            break

    if start == -1 and last == -1:
        return 0
    return last - start + 1
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    answer = find_unsorted_subarray(nums)
    print(answer)


if __name__ == "__main__":
    main()