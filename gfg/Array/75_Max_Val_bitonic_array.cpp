// https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array/0

#include <bits/stdc++.h>
using namespace std;

int find_max(int a[], int n) 
{
    int i=0, j=n-1, mid;

    if (n==1) {
        return a[0];
    }

    while (true) {
        if (i == j-1) {
            if (a[i] > a[j]) {
                return a[i];
            } else {
                return a[j];
            }
        } else {
            mid = i + (j-i+1)/2;

            if (a[mid] > a[mid+1]) {
                if (a[mid] > a[mid-1]) {
                    return a[mid];
                } else {
                    j=mid;
                }
            } else {
                i = mid;
            }
        }
    }
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

        cout << find_max(a,n) << endl;
    }
    return 0;
}