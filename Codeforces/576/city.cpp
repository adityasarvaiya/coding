#include <bits/stdc++.h>
using namespace std;

int util(vector <int> A, int n, int x, int y) {
    int j,l,r;

    for (int i = 0; i < A.size(); ++i) {
        r = INT_MAX;
        l = INT_MAX;

        for (j = i+1; j < A.size() && j-i <= y; ++j) {
            if (r > A[j]) {
                r = A[j];
            }
        }

        for (j = i-1; j >= 0 && i-j <= x; --j) {
            if (l > A[j]) {
                l = A[j];
            }
        }

        if (l > A[i] && r > A[i]) {
            return i+1;
        }
    }

    return -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    vector <int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i]; 
    }

    cout << util(A, n, x, y) << endl;

    return 0;
}