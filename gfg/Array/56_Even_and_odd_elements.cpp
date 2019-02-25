// https://practice.geeksforgeeks.org/problems/even-and-odd-elements-at-even-and-odd-positions/0

#include <bits/stdc++.h>
using namespace std;

void find_sorted(int a[], int n) 
{
    int i=0,j=0,start, end, iter, temp;

    while (true) {
        while (a[i]%2 != 0 && i < n) {
            i += 1;
        }

        while (a[j]%2 != 1 && j < n) {
            j += 1;
        }

        if (i < n) {
            cout << a[i] << " ";
        } if (j < n) {
            cout << a[j] << " ";
        } else {
            break;
        }

        i++;
        j++;
    }

    cout << endl;

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

        find_sorted(a,n);
    }
    return 0;
}