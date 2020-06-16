#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
using namespace std;

class BestTimeToBuyAndSellStocks {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            int n = prices.size();
            for(int i = 1; i < n; ++i) {
                if( prices[i] - prices[i - 1] > 0 ) {
                    profit += prices[i] - prices[i-1];
                }
            }
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
            return profit;
        }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> prices;
    ReadMatrix<int>().OneDMatrix(n, prices);
    int result = BestTimeToBuyAndSellStocks().maxProfit(prices);
    cout << result;
    return 0;
}
