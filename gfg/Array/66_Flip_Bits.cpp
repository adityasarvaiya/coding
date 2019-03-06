// Flip Bits
// https://practice.geeksforgeeks.org/problems/flip-bits/0
// unsubmitted

#include <bits/stdc++.h>
using namespace std;

int find_max_1(int a[], int n)
{
    int start=-1, end=-1, i;

    for (i = 0; i < n; ++i) {
        if (a[i] == 1) {
            a[i] = 1;
        } else {
            a[i] = -1;
        } 
    }

    int gmax=INT_MIN, currmax=0, zeros=0;

    for (i = 0; i < n; ++i) {
        currmax += a[i];

        if (currmax < 0) {
            currmax = 0;
        }

        if (a[i] == 1) {
            zeros++;
        }

        if (currmax > gmax) {
            gmax = currmax;
        }
    }

    cout << zeros << endl;

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

        cout << find_max_1(a,n) << endl << endl;
    }
    return 0;
}