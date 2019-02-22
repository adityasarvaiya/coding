#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n,i,curr;
        cin >> n;
        vector <int> in;

        for (i = 0; i < n; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        sort(in.begin(), in.end());

        cout << max(in[0]*in[1]*in[2], in[n-1]*in[n-2]*in[n-3]) << endl;
    }

    return 0;
}