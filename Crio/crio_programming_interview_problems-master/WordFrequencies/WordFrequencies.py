'''
Complete the following function.

@return - list of list
        [[word1, count_word1], [word2, count_word2], ...]
'''
def wordFrequencies(words):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    wordCount = {}
    for word in words:
        if word not in wordCount:
            wordCount[word] = 0
        wordCount[word] += 1
    
    return sorted([[word, wordCount[word]] for word in wordCount])
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        
n = int(input())
words = [input().strip() for i in range(n)]

wordCount = wordFrequencies(words)

for word, count in wordCount:
    print(word, count)
