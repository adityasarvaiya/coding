#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,k,i,tmp,num_candies; 
    cin >> t;
     
    while (t--) {
        cin >> n >> k;
        vector <int> A;

        for (i = 0; i < n; ++i) {
            cin >> tmp;
            A.push_back(tmp);
        }

        sort(A.begin(), A.end());

        if (n % (1+k) == 0) {
            num_candies = n/(1+k);
        } else {
            num_candies = n/(1+k) + 1;
        }

        long long mn = 0, mx = 0;
        for (i = 0; i < num_candies; ++i) {
            mn += A[i];
            mx += A[(n-1)-i];
        }

        cout << mn << " " << mx << endl;
    }
     
    return 0;
}