// https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
// https://practice.geeksforgeeks.org/problems/row-with-max-1s/0

#include <bits/stdc++.h>
using namespace std;
// do not use this code use other methon mentioned below
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
 
//use this method
int util(vector <vector <int>> A, int n, int m)
{
    int i = 0, j = m-1;
    int ans = 0;

    while (i < n && j >= 0) {
        if (A[i][j] == 1) {
            ans = i;
        }

        while (j >= 0 && A[i][j] == 1) {
            j--;
        }

        while ((i < n && j >= 0) && A[i][j] == 0) {
            i++;
        }
    }   

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,m; 
    cin >> t;
     
    while (t--) {
        cin >> n >> m;
        vector <vector <int>> A (n, vector <int> (m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> A[i][j];
            }
        }

        cout << util(A, n, m) << endl;
    }
     
    return 0;
}