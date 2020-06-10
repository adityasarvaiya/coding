#include <bits/stdc++.h>
using namespace std;

long long util(vector <vector <int>> &A, int n)
{
    if (n == 1) {
        return max(0LL+A[0][0], 0LL+A[1][0]);
    }

    if (n == 2) {
        return max(0LL+A[0][0]+A[1][1], 0LL+A[0][1]+A[1][0]);
    }

    long long a1,b1,a2,b2,a3,b3;

    a1 = A[0][0];
    b1 = A[1][0];

    a2 = 0LL + A[0][1] + A[1][0];
    b2 = 0LL + A[1][1] + A[0][0];

    for (int i = 2; i < n; ++i) {
        a3 = 0LL + A[0][i] + max(b1,b2);
        b3 = 0LL + A[1][i] + max(a1,a2);

        a1 = a2;
        b1 = b2;

        a2 = a3;
        b2 = b3;    
    }
    
    return max(a2,b2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector <int> B(n);
    vector <vector <int>> A(2, B);

    for (int i = 0; i < n; ++i) {
        cin >> A[0][i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> A[1][i];
    }

    cout << util(A, n);

    return 0;
}