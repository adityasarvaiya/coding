
def frequentWords(words, k):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    mapped = dict()
    for element in words:
        if element not in mapped:
            mapped[element]=0
        else:
            mapped[element]+=1
    assert len(mapped) >= k
    mapped = [(k,v) for k,v in mapped.items()]
    mapped = sorted(mapped, key = lambda w: (-w[1], w[0]))
    answer = [mapped[i][0] for i in range(k)]
    return answer
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    words = input().strip().split()
    k = int(input())
    result = frequentWords(words ,k)
    print('\n'.join(result))

if __name__ == "__main__":
    main()