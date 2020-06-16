
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def isSmaller(box1, box2):
    for x, y in zip(box1, box2):
        if x >= y:
            return False
    return True
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def stackTheBoxes(length, breadth, height):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    boxes = [(length[i], breadth[i], height[i]) for i in range(n)]
    boxes.sort()
    maximumStack = [boxes[i][2] for i in range(n)]

    for i in range(1, n):
        for j in range(i):
            if isSmaller(boxes[j], boxes[i]):
                maximumStack[i] = max(maximumStack[i], boxes[i][2] + maximumStack[j])

    return max(maximumStack)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

n = int(input())
length = [0 for i in range(n)]
breadth = [0 for i in range(n)]
height = [0 for i in range(n)]
for i in range(n):
    length[i], breadth[i], height[i] = map(int, input().strip().split())

result = stackTheBoxes(length, breadth, height)
print(result)
