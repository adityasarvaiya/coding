// https://practice.geeksforgeeks.org/problems/finding-number/0

#include <bits/stdc++.h>
using namespace std;

int find(vector <int> in, int x) 
{   
    int n=in.size(), l=0,h=n-1,mid;

    while (l<=h) {
        // cout << x << " " << l << " " << in[l] << " --- " << h << " " << in[h] << " --- " << mid << " "<<  in[mid] << endl; 

        if (l == h) {
            if (in[h] == x) {
                return l;
            }

            break;
        } else {
            mid = l+(h-l+1)/2;

            if (in[mid] == x) {
                return mid;
            } else if (in[mid] >= in[mid-1]) {
                // if array is increasing 
                if (x >= in[l] && x < in[mid] ) {
                    h = mid-1;
                } else {
                    l = mid+1;
                }
             
            } else if (x <= in[h] && x > in[mid]) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }

        // cout << x << " " << l << " " << in[l] << " --- " << h << " " << in[h] << " --- " << mid << " " << in[mid] << endl << endl; 
    }

    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr,x;
        cin >> n;
        vector <int> in;

        for (i=0; i<n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

        cin >> x;

        cout << find(in,x) << endl;

    }
    return 0;
}