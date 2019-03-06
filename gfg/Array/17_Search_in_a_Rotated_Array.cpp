// unsubmitted 

#include <bits/stdc++.h>
using namespace std;

int find_index(int a[],int n, int target) 
{
    int i, pivot=0, end=a[n-1], l=0, h=n-1, mid;
    while (true) {
        if (l == h ) {
            pivot = l;
            break;
        } else {
            mid = (l + h) / 2;
        
            if (a[mid] > a[mid + 1]) {
                pivot = mid;
                break;
            } else {
                if (a[l] <= end && a[h] <= end) {

                }
                if (a[mid] > end) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
    }


    return ;
}
 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i, target;
        cin >> n;
        int a[n];

        for (i=0; i<n; ++i) {
            cin >> a[i];
        }

        cin >> target;

        find_index(a,n,target);
    }
    return 0;
}