#include <bits/stdc++.h>
using namespace std;
 
int util(int m, int n)
{
    if (m == n) {
        return -1;
    }

    for (int i = 0; i < 32; ++i) {
        if ((m & (1 << i)) ^ (n & (1 << i))) {
            return i+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,m; 
    cin >> t;
     
    while (t--) {
        cin  >> m >> n;

        cout << util(m, n) << endl;
    }
     
    return 0;
}