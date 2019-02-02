#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int dp[1000];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    int dp_index = 2;

    while (n--) {
        int N;
        cin >> N;

        if (N > (dp_index + 1)) {
            for (int i = dp_index; i <= N; i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }

        cout << dp[N] << endl;
    }

    return 0;
}
