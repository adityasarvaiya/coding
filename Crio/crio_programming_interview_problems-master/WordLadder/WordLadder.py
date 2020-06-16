# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def isValidTranformation(a ,b ):
    difference = 0;
    for i in range(len(a)):
        if a[i] != b[i]:
            difference+=1
    return difference == 1;
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def ladderLength(beginWord, endWord, wordList):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    wordList.append(beginWord)
    vec = [[] for _ in range(len(wordList))]
    destination = -1
    for i in range(len(wordList)):
        for j in range(i+1,len(wordList)):
            if isValidTranformation(wordList[i],wordList[j]):
                vec[i].append(j)
                vec[j].append(i)

        if wordList[i]==endWord :
            destination =i

    q = list()
    level=[0 for _ in range(len(wordList))]
    q.append(len(wordList)-1)
    level[len(wordList)-1]=1
    while len(q) > 0:
        front = q.pop(0)
        for i in range(len(vec[front])):
            if level[vec[front][i]]==0:
                q.append(vec[front][i])
                level[vec[front][i]]=level[front]+1

    if destination == -1:
        return 0
    elif level[destination] == 0:
        return 0
    else:
        return level[destination]
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    beginWord = input()
    endWord = input()
    n = int(input())
    wordList = []
    if n > 0:
        wordList = input().split()
    result = ladderLength(beginWord, endWord, wordList)
    print(result)

