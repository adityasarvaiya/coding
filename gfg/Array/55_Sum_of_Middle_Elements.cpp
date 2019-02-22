// https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0

#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin >> t;

    while (t--) {
        cin >> n;
        int a[n], b[n], i, j;

        for (i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (i = 0; i < n; ++i) {
            cin >> b[i];
        }

        i=0;
        j=0;
        int prev1=-1, prev2=-1, count = 0;
        
        while (count <= n) {
            prev1 = prev2;
            if (a[i] <= b[j]) {
                prev2 = a[i];
                i++;
            } else {
                prev2 = b[j];
                j++;
            }
            count++;
        }

        cout << prev1 + prev2 << endl;    
    }    

    return 0;
}