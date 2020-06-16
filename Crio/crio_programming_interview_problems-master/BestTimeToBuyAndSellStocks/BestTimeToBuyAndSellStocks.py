def maxProfit(prices):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    max_profit = 0
    for i in range(1,len(prices)):
        if prices[i]>prices[i-1]:
            max_profit+=prices[i]-prices[i-1]

    return max_profit
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    prices = input().split()
    prices = [int(i) for i in prices]
    result = maxProfit(prices)
    print(result)
