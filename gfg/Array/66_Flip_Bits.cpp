// Flip Bits
// https://practice.geeksforgeeks.org/problems/flip-bits/0
// https://www.interviewbit.com/problems/flip/


#include <bits/stdc++.h>
using namespace std;

int find_max_1(int a[], int n)
{
    int start=-1, end=-1, i;

    for (i = 0; i < n; ++i) {
        if (a[i] == 1) {
            a[i] = 1;
        } else {
            a[i] = -1;
        } 
    }

    int gmax=INT_MIN, currmax=0, zeros=0;

    for (i = 0; i < n; ++i) {
        currmax += a[i];

        if (currmax < 0) {
            currmax = 0;
        }

        if (a[i] == 1) {
            zeros++;
        }

        if (currmax > gmax) {
            gmax = currmax;
        }
    }

    cout << zeros << endl;

    return 0;
}


int find_max(int a[], int n)
{
    int max_diff = -1, diff = 0, l=0,r=0, gl=-1,gr=-1;

    for (r = 0; r < n; ++r) {
        a[r] == 0 ? diff++ : diff--;

        if (diff > max_diff) {
            max_diff = diff;
            gr = r;
            gl = l;
        } else if (diff < 0) {
            l = r + 1;
            diff = 0;
        } 
    }

    int ans=0;
    for (int i = 0; i < n; ++i) {
        if (i >= gl && i <= gr) {
            if (a[i] == 0) {ans++;}
        } else if (a[i] == 1) {ans++;}
    }

    return ans;
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

        cout << find_max(a,n) << endl ;
    }
    return 0;
}