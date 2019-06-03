#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,s; 
    cin >> t;
     
    while (t--) {
        cin >> n >> s;
        string st;

        if (n*9 < s || (s == 0 && n > 1)) {cout << -1 << endl;}
        else {
            while (n--)
            {
                if (s >= 9) {
                    st.push_back('9');
                    s -= 9;
                } else {
                    st.push_back(to_string(s)[0]);
                    s = 0;
                }
            }
            
            cout << st << endl;
        }
    }
     
 
    return 0;
}