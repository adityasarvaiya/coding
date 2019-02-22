#include <bits/stdc++.h>
using namespace std;

void find_sorted(int a[], int n) 
{
    int i=0,j=1;

    while (true) {
        while (a[i]%2 == 0 && i < n) {
            i += 2;
        }

        while (a[j]%2 == 1 && j < n) {
            j += 2;
        }

        if (i < n && j < n) {
            swap(a[i], a[j]);
        } else {
            break;
        }
    }

    for (i = 0; i < n; ++i) {
        cout << a[i] << " ";
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