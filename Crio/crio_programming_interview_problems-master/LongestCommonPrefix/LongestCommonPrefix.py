
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def prefix(word1 ,word2):
    i, j = 0, 0 
    while i < len(word1) and j < len(word2):
        if word2[j] == word1[i]:
            i+=1
            j+=1
        else:
            break
    return word1[:i]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def longestCommonPrefix(strs):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if len(strs) == 0:
        return ""
    word = strs[0]
    for word2 in strs[1:]:
        word = prefix(word, word2)
    return word
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    strs = input().split()
    result = longestCommonPrefix(strs)
    print(result)
