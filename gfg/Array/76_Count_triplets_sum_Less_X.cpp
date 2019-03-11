// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x/0

#include <bits/stdc++.h>
using namespace std;

int count_triplets(vector <int> a, int n, int X) 
{
    int i,j,k,sum,curr,count=0,triplets;
    
    sort(a.begin(), a.end());

    for (i = 0; i < n-2; ++i) {
        j = i+1;
        k = n-1;

        while (j<k) {
            sum = a[i] + a[j] + a[k];

            if (sum >= X) {
                --k;
            } else {
                count += k-j;
                j++;
            }
        }
    }

    return count;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,X,curr;
        cin >> n >> X;  
        vector<int> a;

        for (i=0; i<n; ++i) {
            cin >> curr;
            a.push_back(curr);
        }

        cout << count_triplets(a,n,X) << endl;
    }
    return 0;
}