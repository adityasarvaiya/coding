#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, curr;
        cin >> n;
        int a[n];

        int max_till_here = 0, max_overall = INT_MIN;

        for (int i = 0; i < n; ++i) {
            cin >> curr;

            max_till_here = max_till_here + curr;

            if (max_till_here > max_overall) {
                max_overall = max_till_here;
            }

            if (max_till_here < 0) {
                max_till_here = 0;
            }
        }

        cout << max_overall << endl;
    }

    return 0;
}