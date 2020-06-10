# ContainerWithMostWater solution
# Test case 14,15,16,18,19 to be checked again

def maxArea(height):
    start = 0
    end = len(height)-1
    ans = -1

    while (start < end):
        ans = max(ans, min(height[start], height[end])*(end-start))

        # change the pointer pointing to lower height
        if (height[start] < height[end]):
            start += 1
        else:
            end -= 1
    
    return ans

if __name__ == '__main__':
    n = int(input())
    height = input().split()
    height = [int(i) for i in height]
    result = maxArea(height)
    print(result)
    