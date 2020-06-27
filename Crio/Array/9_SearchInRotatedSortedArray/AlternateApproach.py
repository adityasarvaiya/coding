flag = False
globalMapping = {}
def search(nums, target):
    global flag,globalMapping
    if not flag :
        flag = True
        for i,num in enumerate(nums) :
            globalMapping[num] = i
    if target not in globalMapping :
        return -1
    return globalMapping[target]
    
if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]

    q = int(input())
    for i in range(q):
        target = int(input())
        result = search(nums, target)
        print(result)
