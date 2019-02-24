// https://practice.geeksforgeeks.org/problems/type-of-array/0

#include <bits/stdc++.h>
using namespace std;

void find_type(int a[], int n) {

    int i=0;

    while (i < n-1 && a[i] <= a[i+1]) {
        i++;
    }

    if (i == n-1) {
        cout << a[n-1] << " " << 1 << endl;
        return;
    } else if (i == 0) {
        
        while (i < n-1 && a[i] >= a[i+1]) {
            i++;
        }

        if (i == n-1) {
            cout << a[0] << " " << 2 << endl;
            return;
        } else if (a[0] < a[i+1]) {
            cout << a[i+1] << " " << 3 << endl;
            return;
        } else {
            cout << a[0] << " " << 4 << endl;
            return;
        }
    } else {
        if (a[0] > a[i+1]) {
            cout << max(a[0], a[i]) << " " << 4 << endl;
            return;
        } else {
            cout << max(a[0], a[i]) << " " << 3 << endl;
            return;
        }
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i;
    cin >> t;

    while (t--) {
        cin >> n;
        int a[n];

        for (i = 0; i < n; ++i) {
            cin >> a[i];
        }

        find_type(a,n);
    }

    return 0;
}