#include <bits/stdc++.h>
using namespace std;

class DecodeWays {
  public:
    int numDecodings(string s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int mod = 1000000007;
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= int(s.length()); i++) {
            int one = stoi(s.substr(i - 1, 1));
            int two = stoi(s.substr(i - 2, 2));

            if (one >= 1)
                dp[i] = (dp[i] + dp[i - 1]) % mod;
            if (two >= 10 && two <= 26)
                dp[i] = (dp[i] + dp[i - 2]) % mod;
        }

        return dp[s.length()];
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    string s;
    cin >> s;
    int result = DecodeWays().numDecodings(s);
    cout << result;
    return 0;
}
