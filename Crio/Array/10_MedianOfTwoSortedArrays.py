# MedianOfTwoSortedArrays Solution 
# Issue with Testcase 30 - perf-test-8 

def find_median(num1, num2, size1, size2):        
    # We will do binary search on smaller array for partition
    if (size1 > size2) : 
        num1, num2, size1, size2 = num2, num1, size2, size1 
    
    low = 0
    high = size1
    half_length = int((size1 + size2 + 1) / 2)
        
    while low <= high:
        # bcos partitionInArray1 + partitionInArray2 = (size1 + size2 + 1)/2 = half part
        partitionInArray1 = low + int((high - low)/2)
        partitionInArray2 = half_length - partitionInArray1
        
        
        if partitionInArray1 < size1 and num2[partitionInArray2-1] > num1[partitionInArray1]:
            # partitionInArray1 is too small, must increase it
            low = partitionInArray1 + 1
        elif partitionInArray1 > 0 and num1[partitionInArray1-1] > num2[partitionInArray2]:
            # partitionInArray1 is too big, must decrease it
            high = partitionInArray1 - 1
        else:
            # partitionInArray1 is perfect
            if partitionInArray1 == 0: max_of_left = num2[partitionInArray2-1]
            elif partitionInArray2 == 0: max_of_left = num1[partitionInArray1-1]
            else: max_of_left = max(num1[partitionInArray1-1], num2[partitionInArray2-1])

            # If total odd number of elements
            if (size1 + size2) % 2 == 1:
                return max_of_left

            if partitionInArray1 == size1: min_of_right = num2[partitionInArray2]
            elif partitionInArray2 == size2: min_of_right = num1[partitionInArray1]
            else: min_of_right = min(num1[partitionInArray1], num2[partitionInArray2])

            return (max_of_left + min_of_right) / 2.0

def main():
    n = int(input())
    nums1 = list(map(int, input().split()))
    m = int(input())
    nums2 = list(map(int, input().split()))
    queries = int(input())
    while queries >= 1:
        size1, size2 = map(int, input().split()) 
        answer = find_median(nums1, nums2, size1, size2)
        print(answer*1.0)
        queries -= 1

if __name__ == "__main__":
    main()