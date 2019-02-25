// Flip Bits
// https://practice.geeksforgeeks.org/problems/flip-bits/0

#include <bits/stdc++.h>
using namespace std;

int find_max_1(int a[], int n)
{
    int start=-1, end=-1, i, zeros;

    for (i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++zeros;
        } else {
            --zeros;
        }

        if (zeros < 0) {
            zeros = 0;
            end = -1;
            start = -1;
        } else {
            if (start == -1) {
                start = i;
                end = i;
            } else {
                end = i;
            }
        }
    }

    cout << end - start + 1 << endl;

    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i;
        cin >> n;
        int a[n];

        for (i=0; i<n; ++i) {
            cin >> a[i];
        }

        cout << find_max_1(a,n) << endl;
    }
    return 0;
}