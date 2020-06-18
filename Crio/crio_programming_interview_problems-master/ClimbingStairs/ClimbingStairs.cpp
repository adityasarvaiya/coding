#include <bits/stdc++.h>
using namespace std;
class ClimbingStairs {
public:
    int climbingStairs(int numberOfStairs) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (numberOfStairs == 0) return 1;
        int dp[numberOfStairs + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= numberOfStairs; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[numberOfStairs];
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int numberOfStairs;
    cin >> numberOfStairs;
    int result = ClimbingStairs().climbingStairs(numberOfStairs);
    cout << result;
    return 0;
}
