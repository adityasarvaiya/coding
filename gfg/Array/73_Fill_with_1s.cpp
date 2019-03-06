// https://practice.geeksforgeeks.org/problems/fill-array-by-1s/0

#include <bits/stdc++.h>
using namespace std;

int fillWith1(int a[], int n) 
{   
    int start = -1, end, curr_window = INT_MAX, min_window=INT_MIN;
    for (end = 0; end < n; ++end) {
        if (a[end] == 0) {
            if (start == -1) {
                start = end;
            }

            if (end == n-1 && start == 0) {
                return -1;
            }
        }
        
        if (start != -1 && (a[end] == 1 || end == n-1)) {
            if (a[end] == 1) {
                if (start > 0 && a[start -1] == 1) {
                    curr_window = (end - start + 1) / 2;
                } else {
                    curr_window = end - start;
                }

                start = -1;
            } else { // a[end] == 0 and end == n-1
                curr_window = end - start + 1;
            }

            min_window = max(min_window, curr_window);
        }
    }

    return min_window;
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

        cout << fillWith1(a,n) << endl;
    }
    return 0;
}