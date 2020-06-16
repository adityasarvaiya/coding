def largestRectangleArea(heights):
    # TODO: CRIO_TASK_MODULE_L3_PROBLEMS
    # Your implementation goes here

    return 0

if __name__ == '__main__':
    n = int(input())
    heights = []
    if n > 0:
        heights = input().split()
        heights = [int(i) for i in heights]

    result = largestRectangleArea(heights)
    print(result)

