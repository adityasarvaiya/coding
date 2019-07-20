#include <bits/stdc++.h>
using namespace std;

int util(vector <pair<int, int>> A, int n) {

    if (n <= 3) {return 1;}

    sort(A.begin(), A.end());

    int d1,d2,d3, diff, f = 1, diff_so_far = 0, diff_index;

    d1 = A[1].first - A[0].first;
    d2 = A[2].first - A[1].first;
    d3 = A[3].first - A[2].first;

    if (d1 == d2) {
        f = 0;
        diff = d1;
    } else if (d1 == d3) {
        f = 0;
        diff = d1;
    } else if (d2 == d3) {
        diff_so_far++;
        diff_index = A[0].second+1;
        f = 0;
        diff = d2;
    }

    if (f) { return -1; }
    int i = 1;

    if (diff_so_far) {
        i = 2;
    }

    for (; i < n; ++i) {
        if (A[i].first - A[i-1].first != diff) {
            diff_so_far++;
            diff_index = A[i].second+1;

            if (diff_so_far > 1 || (i+1 < n && (A[i+1].first - A[i-1].first) != diff)) {
                return -1;
            } else {
                i++;
            }
        }
    }

    if (diff_so_far) {
        return diff_index;
    } else {
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n, tmp; 
    cin >> n;
    
    vector <pair<int, int>> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        A[i] = {tmp, i};
    }

    cout << util(A,n);
     
    return 0;
}