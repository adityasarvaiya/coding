from collections import Counter

def length_of_substring(s, k):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if k == 0:
        return 0
    start = end = 0
    answer = 1
    dic = Counter()
    while end < len(s):
        dic[s[end]] += 1
        end += 1
        while len(dic) > k:
            if dic[s[start]] != 1:
                dic[s[start]] -= 1
            else:
                del dic[s[start]] 
            start += 1
        answer = max(answer, end - start)
    return answer
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n, k = map(int, input().split())    
    s = input()
    answer = length_of_substring(s, k)
    print(answer)

if __name__ == "__main__":
    main()