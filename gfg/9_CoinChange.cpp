#include <bits/stdc++.h>
using namespace std;

int count(vector<int> coins, int diff_coins, int tot_sum) {    
    int dp[diff_coins][tot_sum+1];

    for (int i = 0; i < diff_coins; ++i) {
        dp[i][0] = 1;
    }


    vector <int> :: iterator it;

    for (int i = 0; i < diff_coins; ++i) {
        for (int j = 1; j <= tot_sum; ++j) {
            if (i == 0) {
                if (i <= j) {
                    if (j % coins[i] == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    dp[i][j] = 0;
                }
            } else {
                dp[i][j] = dp[i-1][j];
                if (j - coins[i] >= 0) {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }

        }
    }
    
    // for (int i = 0; i < diff_coins; ++i) {
    //     for (int j = 0; j <= tot_sum; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[diff_coins-1][tot_sum];
}

int main(){
    
    int n;
    cin >> n;
    
    while (n--) {
        int diff_coins, tot_sum, temp;
        cin >> diff_coins;

        vector<int> coins;

        for (int i = 0; i < diff_coins; i++) {
            cin >> temp;
            coins.push_back(temp); 
        }

        sort(coins.begin(), coins.end());

        cin >> tot_sum;
        cout << count(coins, diff_coins, tot_sum) << endl;
    }

    return 0;
}