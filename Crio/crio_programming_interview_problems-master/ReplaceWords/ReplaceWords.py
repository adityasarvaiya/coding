# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

from collections import defaultdict
from functools import reduce

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def replaceWords(words, sentence):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    Trie = lambda: defaultdict(Trie)
    trie = Trie()
    End = True
    for root in words:
        reduce(dict.__getitem__, root, trie)[End] = root

    def replace(word):
        cur = trie
        for letter in word:
            if letter not in cur or End in cur: 
                break
            cur = cur[letter]
        return cur.get(End, word)

    return " ".join(map(replace, sentence.split()))
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    words = input().strip().split()
    sentence  = input()
    ans  = replaceWords(words, sentence)
    print(ans)

if __name__ == "__main__":
    main()
