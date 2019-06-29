#include <bits/stdc++.h>
using namespace std;
 
int util(int c[], int n) 
{
    int ans = c[0];
    for (int i = 1; i < n; ++i) {
        ans ^= (c[i]);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,l,r; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        int c[n];

        for(int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        cout << util(c, n) << endl;
    }
     
    return 0;
}