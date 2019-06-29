#include <bits/stdc++.h>
using namespace std;
 
int util(int n) {

    for (int i = 0; i < 32; ++i) {
        if (n & 1 << i) {
            return i+1;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        cout << util(n) << endl;
    }
     
    return 0;
}