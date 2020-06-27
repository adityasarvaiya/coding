from collections import Counter

def find_anagrams(p, s):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    len_s, len_p = len(s), len(p)
    if len_s < len_p:
        return []
    count_of_p = Counter(p)
    count_of_s = Counter()
    answer = []
    for i in range(len_s):
        count_of_s[s[i]] += 1
        if i >= len_p:
            if count_of_s[s[i-len_p]] != 1:
                count_of_s[s[i-len_p]] -= 1
            else:
                del count_of_s[s[i-len_p]]
        if count_of_s == count_of_p:
            answer.append(i - len_p + 1)
    return answer
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    s, p = input().split()
    answer = find_anagrams(p, s)
    print(len(answer))
    print(' '.join([str(i) for i in answer]))


if __name__ == "__main__":
    main()