#include <bits/stdc++.h>
using namespace std;

class UniquePaths {
  public:
    int uniquePaths(int m, int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int numberOfWays[m][n];
        int mod = 1000000007;
        for (int i = 0; i < m; i++) {
            numberOfWays[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            numberOfWays[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                numberOfWays[i][j] = (numberOfWays[i - 1][j] % mod +
                                      numberOfWays[i][j - 1] % mod) %
                                     mod;
            }
        }
        return (numberOfWays[m - 1][n - 1] % mod);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int result = UniquePaths().uniquePaths(m, n);
    cout << result;
    return 0;
}
