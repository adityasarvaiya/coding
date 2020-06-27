# Implement your solution here
def find_unsorted_subarray(nums):
    if len(nums) <= 1 :
        return 0
    sortedNums = nums[:]
    sortedNums.sort()
    l,r,n = 0,0,len(nums)
    for l in range(len(nums)) :
        if(nums[l]!=sortedNums[l]) :
            break
    for r in range(len(nums)) :
        index = n-1-r
        if(nums[index]!=sortedNums[index]) :
            break
    r = n-r-1
    ans = max(r - l + 1,0)
    return ans

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    answer = find_unsorted_subarray(nums)
    print(answer)


if __name__ == "__main__":
    main()
