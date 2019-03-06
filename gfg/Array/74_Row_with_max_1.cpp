// https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
// https://practice.geeksforgeeks.org/problems/row-with-max-1s/0

#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s (vector <vector<int>> a, int m, int n) 
{   
    int i, j, first_1=n, max_1_row=0;
    for (i = 0; i < n; ++i) {
        if (a[0][i] == 1) {
            first_1 = i;
            break;
        }
    }

    for (i = 1; i < m; ++i) {
        if (first_1 != 0 && a[i][first_1-1] == 1) {
            first_1 = lower_bound(a[i].begin(), a[i].end(), 1) - a[i].begin();
            max_1_row = i;
        }
    }

    return max_1_row;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int m,n,i,j,curr;
        cin >> m >> n;
        vector <vector<int>> a;
        

        for (i=0; i<m; ++i) {   
            vector <int> b;
            for (j=0; j<n; ++j) {
                cin >> curr;
                b.push_back(curr);
            }
            a.push_back(b);
        }

        cout << rowWithMax1s(a,m,n) << endl;
    }
    return 0;
}