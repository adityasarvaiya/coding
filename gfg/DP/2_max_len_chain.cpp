#include <bits/stdc++.h>
using namespace std;

int find(int A[][2], int curr, int n, int max_till_now);
{
    if (curr == n) {return 0;}

    find(A, curr+1, n, )
}

int main () {`
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,a,b;
    cin >> t;

    while (t--) {
        cin >> n;
        int A[n][2];

        for (i = 0; i < n; ++i) {
            cin >> A[i][0] >> A[i][1];
        }

        cout << find(A, 0, n, INT_MIN) << endl;
    }
    return 0;
}