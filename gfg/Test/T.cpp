#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    vector <vector <int>> A;
    int n = 3, m = 2;

    for (int i = 0; i < n; ++i) {
        vector <int> B(m);
        for (int j = 0; j < m; ++j) {
            cin >> B[j];
        }
        A.push_back(B);
    }

    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l) {
            cout << A[k][l] << " ";
        }
        cout << endl;
    }
    
    return 0;
}