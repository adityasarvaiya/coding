#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    long long dp[101];
    dp[0] = 1;
    int dp_index = 1;

    while (n--) {
        int N, i, j;
        cin >> N;

        if (N >= dp_index) {
            for (i = dp_index; i <= N; i++) {
                long long sum = 0;
                for (j = 0; j < i; j++) {
                    sum += dp[j] * dp[(i-1) - j];
                }

                dp[i] = sum;
            }
        }

        cout << dp[N] << endl;

        // for (i = 0; i < N; i++) {
        //     cout << dp[i] << " " ;
        // }
    }    

    return 0;
}
