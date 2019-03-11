// https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1

#include <bits/stdc++.h>
using namespace std;

int max_path_sum(int A[], int B[], int l1, int l2)
{
    int i=0, j=0, sum_a = 0, sum_b = 0, sum_g=0;

    while (i < l1 && j < l2) {
        if ((i < l1-1 && j < l2-1) && A[i+1] == B[j+1]) {
            sum_a += A[++i];
            sum_b += B[++j];
            
            sum_g += max(sum_a, sum_b);
            sum_a = 0;
            sum_b = 0;    
            

        } else if (A[i] < B[j])){
            sum_a += A[++i];
        } else if (j < l2) {
            sum_b += B[++j];
        }
    }
    
    sum_g += max(sum_a, sum_b);
    
    return sum_g;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,m,i;
        cin >> n >> m;
        int a[n], b[m];

        for (i=0; i<n; ++i) {
            cin >> a[i];
        }

        for (i=0; i<m; ++i) {
            cin >> b[i];
        }

        cout << max_path_sum(a,b,n,m) << endl;

    }
    return 0;
}