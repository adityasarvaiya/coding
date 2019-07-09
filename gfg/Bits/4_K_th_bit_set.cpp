#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,k; 
    cin >> t;
     
    while (t--) {
        cin >> n >> k;

        if (n & 1 << k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
     
    return 0;
}