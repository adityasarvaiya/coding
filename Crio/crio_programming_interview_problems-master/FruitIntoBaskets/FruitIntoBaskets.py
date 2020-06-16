from collections import Counter

def total_fruit(tree):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    i = answer = 0
    count = Counter()
    for j, x in enumerate(tree):
        count[x] += 1
        while len(count) >= 3:
            count[tree[i]] -= 1
            if count[tree[i]] == 0:
                del count[tree[i]]
            i += 1
        answer = max(answer, j - i + 1)
    return answer
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    tree = list(map(int, input().split()))
    answer = total_fruit(tree)
    print(answer)


if __name__ == "__main__":
    main()