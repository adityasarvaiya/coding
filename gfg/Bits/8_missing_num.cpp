#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,l,r; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        long long sum = n * (n+1) / 2, tmp;

        for(int i = 0; i < n-1; ++i) {
            cin >> tmp;
            sum -= tmp;
        }

        cout << sum << endl;
    }
     
    return 0;
}