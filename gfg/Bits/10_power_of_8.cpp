#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,f=1; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        if (n == 0) {
            cout << "No" << endl;
            continue;
        }

        while (n) {
            if (n % 8 != 0 && n != 1) {
                f =0 ;
                cout << "No" << endl;
            }
        }
     
        if (f) {
            cout << "Yes" << endl;
        }
    }

    
     
    return 0;
}