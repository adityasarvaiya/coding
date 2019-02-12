//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
//https://www.geeksforgeeks.org/stock-buy-sell/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,f=-1, j=0, count=0;
        cin >> n;
        int a[n], b[n][2];

        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (i = 0; i < n; i++) {
            if (f == -1) {
                b[j][0] = i;
                f=i;
            }

            
            if (i == n-1 || a[i] > a[i+1]) {
                if (b[j][0] != i) {
                    b[j][1] = i;
                    j++;    
                } 

                f=-1;
            }
            
        }

        for (i = 0; i < j; i++) {
            if (b[i][0] != b[i][1]) {
                cout << "(" << b[i][0] << " " << b[i][1] << ") ";
            } else {
                count++;
            }
        }

        if (j == 0) {
            cout << "No Profit";
        }

        cout << endl;

    }

    return 0;
}