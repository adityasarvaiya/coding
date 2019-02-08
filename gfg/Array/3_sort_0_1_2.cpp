// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <bits/stdc++.h>
using namespace std;

int * sort_array(int in[], int n) {

    int i=0,j=n-1,k=0;

    while (k <= j) {
        switch(in[k]) {
            case 0:
                swap(in[i++], in[k++]);
                break;
            case 1:
                k++;
                break;
            case 2:
                swap(in[k], in[j--]);
                break;

        }
    }
    
    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr;
        cin >> n;
        int in[n];
        
        for (i=0; i<n; i++) {
            cin >> curr;
            in[i] = curr;
        }

        int *out = sort_array(in,n);

        for (i = 0; i < n; i++) {
            cout << out[i] << " ";
        }

        cout << endl;
    }

    return 0;
}