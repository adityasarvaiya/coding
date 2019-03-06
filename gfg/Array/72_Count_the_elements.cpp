// https://practice.geeksforgeeks.org/problems/count-the-elements/0
// Given two arrays A and B. Given Q queries each having a positive 
// integer i denoting an index of the array A. For each query, your 
// task is to find all the elements less than or equal to Ai in the array B.

#include <bits/stdc++.h>
using namespace std;

int count_elements(int a, vector <int> b, int n) 
{   
    int i=0, j=n-1, mid;
    
    // cout << "a : " << a  << " " << n << endl; 

    while (true) {
        if (i == j) {
            if (b[j] > a) {
                // cout << 'j : ' << j << 'b[j] ' << b[j] << endl;
                return 0;
            }
            return i+1;
        } 
    
        mid = i + (j-i+1) / 2;

        if (b[mid] > a) {
            j = mid - 1;
        } else {
            i = mid;
        }
        

        // cout << i << " " << j << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr;
        cin >> n;
        vector <int> a;
        vector <int> b;

        for (i=0; i<n; ++i) {
            cin >> curr;
            a.push_back(curr);
        }

        for (i=0; i<n; ++i) {
            cin >> curr;
            b.push_back(curr);
        }

        sort(b.begin(), b.end());

        int q,qr;
        cin >> q;
        while (q--) {
            cin >> qr;
            cout << count_elements(a[qr], b, n) << endl;
        }
    }
    return 0;
}