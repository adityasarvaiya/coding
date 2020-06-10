#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long ans = 0, ele, curr = 1, tmp;
    long long m = 998244353;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        curr = 1;

        while (tmp) {
            ele = tmp % 10;
            tmp /= 10;

            ans = ((ans + (ele*curr) % m) % m + (10*((ele*curr) % m))%m) % m;

            curr *= 100;
        }
    }

    ans = (ans * n) % m;

    cout << ans;

    return 0;
}