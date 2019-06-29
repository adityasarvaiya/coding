#include <bits/stdc++.h>
using namespace std;
 
int util(int a) 
{
    int tog = 0;
    for (int i = 0; i < 31; ++i) {
        if ((a & (1 << i)) & (a & (1 << (i+1)))) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,l,r; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        cout << util(n) << endl;
    }
     
    return 0;
}