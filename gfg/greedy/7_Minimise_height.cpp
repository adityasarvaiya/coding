#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t, n, k ; 
    cin >> t;
     
    while (t--) {
        cin >> k >> n;
        long long ans, tmp, mn = LLONG_MAX, mx = LLONG_MIN;

        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            mn = min(mn,tmp);
            mx = max(mx,tmp);
        }

        ans = min(mx-mn, min(mx-mn-k, mx-mn-(2*k)));
        cout << ans << endl;
    }
     
 
    return 0;
}