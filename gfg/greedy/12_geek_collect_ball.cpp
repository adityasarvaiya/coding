#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,m,i,j; 
    cin >> t;
     
    while (t--) {
        cin >> m >> n;
        int A[m], B[n];
        unordered_map<int, int> h;

        for (i = 0; i < m; ++i) {
            cin >> A[i];
        }

        for (i = 0; i < n; ++i) {
            cin >> B[i];
            h[B[i]] = i;
        }

        i=0;
        j=0;
        long long ans = 0;

        while (i < m || j < n)
        {   
            long long s1=0,s2=0;
            while (i < m && h.find(A[i]) == h.end())
            {
                s1 += A[i];
                ++i;
            }

            while (i < m-1 && A[i] == A[i+1]) {
                s1 += A[i];
                ++i;
            }

            while (j < n && j < h[A[i]]) {
                s2 += B[j];
                j++;
            }
            
            if (i < m) {
                s1 += A[i++];
            }

            if (j < n) {
                s2 += B[j++];
            }

            ans += max(s1,s2);

        }
        
        cout << ans << endl;
    }
     
    return 0;
}