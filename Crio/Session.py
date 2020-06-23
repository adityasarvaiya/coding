
def find_unsorted_subarray(nums):
    if len(nums) <2:
        return 0
    
    l=0
    r=len(nums)-1
    
    while l<len(nums)-1 and nums[l] <= nums[l+1]:
        l+=1
        
    while r>0 and nums[r] >= nums[r-1]:
        r-=1
    
    if l>r:
        return 0

    min_el = min(nums[l:r+1])#min(nums[l], nums[r])
    max_el = max(nums[l:r+1])#max(nums[l], nums[r])

    # l -= 1
    while l>0 and nums[l-1]>min_el:
        l -= 1

    # r += 1
    while r < len(nums)-1 and nums[r+1]<max_el:
        r += 1

    return r-l+1

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    answer = find_unsorted_subarray(nums)
    print(answer)


if __name__ == "__main__":
    main()