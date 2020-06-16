
def beesToHives(bees, hives):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(bees)
    bees.sort()
    hives.sort()
    diff = [abs(bees[i]- hives[i]) for i in range(n)]
    ans = max(diff)
    return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS    

def main():
    n = input()
    bees = list(map(int,input().split()))
    hives = list(map(int,input().split()))
    assert len(bees) == len(hives)
    ans = beesToHives(bees, hives)
    print(ans)

if __name__ == "__main__":
    main()
