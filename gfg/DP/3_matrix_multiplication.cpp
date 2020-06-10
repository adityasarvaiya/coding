#include <bits/stdc++.h>
using namespace std;

int util(vector <int> &A, int n) {

    vector <vector <int>> dp (n, vector <int> (n,0));

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j + i < n; ++j) {
            dp[j][i+j] = INT_MAX;

            for (int k = j; k < j+i; ++k) {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][j+i] + (A[j-1])*(A[k])*(A[j+i]));
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    return dp[1][n-1];
}

int main() {
    int t,n;
    cin >> t;

    while (t--) {
        cin >> n;

        vector <int> A(n);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        cout << util(A, n) << endl;
    }

    return 0;
}