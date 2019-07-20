#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t, i, j, ci, cj, l1, l2, f; 
    cin >> t;
     
    while (t--) {
        string a,b;
        cin >> a >> b;

        l1 = a.length();
        l2 = b.length();
        i = 0; j = 0; f = 1;
        while (i < l1) {
            ci = 1; cj = 1;

            while (i < l1 && a[i] == a[i+1]) {
                ci++;
                i++;
            }

            if (b[j] == a[i]) {
                while (j < l2 && b[j] == b[j+1]) {
                    cj++;
                    j++;
                }
            } else {
                cj = 0;
            }
            

            if (ci > cj) {
                f = 0;
                break;
            }

            i++;
            j++;
        }

        if (j != l2) {
            f = 0;
        }

        if (f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
     
    return 0;
}