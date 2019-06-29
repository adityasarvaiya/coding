#include <bits/stdc++.h>
using namespace std;
 
int util(int a, int l, int r) 
{
    int tog = 0;
    for (int i = l; i <= r; ++i) {
        tog |= 1 << i-1;
    }

    return a ^ tog;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,l,r; 
    cin >> t;
     
    while (t--) {
        cin >> n >> l >> r;
        cout << util(n,l,r) << endl;
    }
     
    return 0;
}