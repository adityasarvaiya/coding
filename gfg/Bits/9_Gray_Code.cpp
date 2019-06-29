#include <bits/stdc++.h>
using namespace std;
 
int util(int n) 
{
    int g;
    
    g = n ^ n >> 1;
    g = g | (n  && 1 << 31);

    return g;
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