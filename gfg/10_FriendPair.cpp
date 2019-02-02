#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    long long dp[1000];
    dp[0] = 1;
    dp[1] = 1;
    long long dp_index = 2;

    while (t--) {
        long long n;
        cin >> n;

        if (n >= dp_index) {
            for (long long i = dp_index; i <= n; ++i) {
                dp[i] = dp[i-1] + ((i-1)*(dp[i-2])) % (long long)(pow(10,9)+7);
            }

            dp_index = n+1;
        }

        for (long long i = 0; i < dp_index; i++) {
            cout << i << " " << dp[i] << endl;
        }

        cout << dp[n] << endl;
    }

    return 0;
}