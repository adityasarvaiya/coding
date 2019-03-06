// https://practice.geeksforgeeks.org/problems/max-value/0

#include <bits/stdc++.h>
using namespace std;

int find_max(int a[], int n) 
{   
    int i, min1=INT_MAX, max1=INT_MIN;

    for (i = 0; i < n; ++i) {
        max1 = max(max1, a[i]-i);
        min1 = min(min1, a[i]-i);
    }

    return (max1-min1);
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

        cout << find_max(a, n) << endl;
    }
    return 0;
}