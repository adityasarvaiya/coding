#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k, tmp, ans = 0, left=0;
    cin >> n >> k;
    vector <int> a(k);

    for (int i = 0; i < n; ++i) {
        cin >> tmp;

        a[tmp-1] += 1;
    }

    for (int i = 0; i < k; ++i) {
        left += (a[i] % 2);
        ans += (a[i] % 2 == 0 ? a[i] : a[i]-1);
    }

    ans += (left+1)/2;

    cout << ans;

    return 0;
}