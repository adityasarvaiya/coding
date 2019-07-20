// unsubmitted

#include <bits/stdc++.h>
using namespace std;
 
int merge(vector <int> a, vector <int> b, int l, int mid, int r, vector <int> &out) {
    int i = l, j = mid, k = l, l1 = a.size(), l2 = b.size(), inversions = 0;

    while (i < l1 && j < l2) {  
        if (a[i] <= b[j]) {
            out[k++] = a[i++];
            out[k++] = b[j++];
        } else {
            out[k++] = b[j++];
            inversions += l1-i;
        }
    }

    while (i < l1) {
        out[k++] = a[i++];
    }

    while (j < l2) {
        out[k++] = b[j++];
    }

    return inversions;
}

int mergesort(int l, int r, vector <int> in, vector <int> &out) {
    int inversions = 0, mid;
    if (l < r) {
        mid = (r+l)/2;
        vector <int> a(mid - l + 1);
        vector <int> b(r-mid);
        inversions = mergesort (l, mid, in, a);
        inversions += mergesort (mid+1, r, in, b);

        inversions += merge(a,b,l,mid,r,out);
    }

    return inversions;
}

int util(vector <int> a, int n) {
    vector <int> ans(n);
    return mergesort(0, n-1, a, ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector <int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << util(a, n);
    }
     
    return 0;
}