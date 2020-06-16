def wordBreak(s, wordDict):
    # TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    # Your implementation goes here

    return True

if __name__ == '__main__':
    s = input()
    n = int(input())
    wordDict = []
    if n > 0:
        wordDict = input().split()

    result = wordBreak(s, wordDict)
    if result:
        print('true')
    else:
        print('false')
