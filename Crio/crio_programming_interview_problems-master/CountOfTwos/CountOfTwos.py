
def countOfTwos(n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    answer = 0
    for i in range(1,n+1):
        answer += str(i).count('2')
    return answer
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n=int(input())
    result = countOfTwos(n)
    print(result) 

if __name__ == "__main__":
    main()
