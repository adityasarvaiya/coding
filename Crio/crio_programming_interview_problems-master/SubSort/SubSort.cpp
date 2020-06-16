#include <bits/stdc++.h>
using namespace std;
pair<int, int> subSort(vector<int> &A) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n = A.size();
    int l = 0, r = 0, s = 0, e = n - 1;
    int mx = A[0] , mn = A[n - 1];
    int lflag = 0, rflag = 0;

    for ( int i = 1; i < n; i++) {
        if (A[i] < mx) {
            l = i - 1;
            lflag = 1;
            break;
        }
        mx = max(A[i], mx);
    }
    for ( int i = n - 2; i >= 0; i--) {
        if ( A[i] > mn) {
            r = i + 1;
            rflag = 1;
            break;
        }
        mn = min(A[i] , mn);
    }

    if (lflag == 0 && rflag == 0) return { -1, -1};
    for ( int i = l ; i < r ; i++) {
        mn = min(A[i], mn);
        mx = max(A[i], mx);
    }

    for ( int i = 0; i < l; i++) {
        if (A[i] > mn) {
            l = i;
            break;
        }
    }

    for ( int i = n - 1; i >= r; i--) {
        if ( A[i] < mx) {
            r = i; break;
        }
    }


    return {l, r};
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);

    for ( int i = 0; i < n; i++) cin >> A[i];
    pair<int, int> P =  subSort(A);
    cout << P.first << " " << P.second << endl;
}






