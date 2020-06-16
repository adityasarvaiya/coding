def candyToKids(n,goodness):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    goodness_index_pair= []
    for i in range(n):
        goodness_index_pair.append([goodness[i],i])
    goodness_index_pair = sorted(goodness_index_pair)
    candies = [1 for _ in goodness]
    for i in range(n):
        ind = goodness_index_pair[i][1]
        good = goodness_index_pair[i][0]
        if ind-1>=0:
            if goodness[ind-1]>good:
                candies[ind-1]=max(candies[ind-1],candies[ind]+1)
            
        if (ind+1)<n :
            if goodness[ind+1]>good:
                candies[ind+1]=max(candies[ind+1],candies[ind]+1)
    ans = sum(candies)
    return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    goodness = list(map(int,input().strip().split()))

    ans = candyToKids(n,goodness)
    print(ans)

if __name__=="__main__":
    main()
