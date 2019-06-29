#include <bits/stdc++.h>
using namespace std;
 
unsigned int util(unsigned int n) 
{   
    unsigned int ans = 0;

    int s = sizeof(n);

    while(n) {
        ans << 1;
        ans |= (n & 1);
        n >>= 1;
        s--;
    }

    ans <<= s;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t;
    unsigned int n; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        cout << util(n) << endl;
    }
     
    return 0;
}