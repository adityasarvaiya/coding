// https://practice.geeksforgeeks.org/problems/stickler-theif/0
#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> in, int n)  
{
    int dp[10000],i;
    dp[0] = 0;
    dp[1] = in[0];

    for (i = 1; i < n; ++i) {
        dp[i+1] = max(in[i] + dp[i-1], dp[i]);
    }

    return dp[n];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,out;
    cin >> t;
    while (t--) {
        cin >> n;
        
        int i,curr;
        vector<int> in;

        for (i = 0; i < n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

        out = find_max(in, n);

        cout << out << endl;
    }

    return 0;
}