#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;    

    long int dp[85];
    dp[0] = 1;
    dp[1] = 1;
    int dp_index = 2;

    while (n--) {
        int N,i;
        cin >> N;

        if (N >= dp_index) {
            for (i = dp_index; i < N; i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
        }

        for (i = 0; i < N; i++) {
            cout << dp[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
