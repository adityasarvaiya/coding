#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n,q;
    unsigned long long m; 
    cin >> n >> q;

    vector <int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int maxeleindex = max_element(A.begin(), A.end()) - A.begin();
    int B[n], maxsofar;

    int j=0;
    for (int i = maxeleindex; i < n; ++i) {
        B[j++] = A[i];
    }

    // cout << maxeleindex << endl;

    maxsofar = A[0];
    vector <pair<int, int>> ans;
    for (int i = 0; i < maxeleindex, j < n; ++i, ++j) {
        B[j] = A[i];
        
        if (i > 0) {
            ans.push_back({maxsofar, A[i]});
            maxsofar = max(maxsofar, A[i]);
        } 
    }

    // cout << "DONE +++++  : " << ans.size() << endl;
    long long mod = n-1;


    for (int i = 0; i < q; ++i) {
        cin >> m;
        if (m < (unsigned long long)maxeleindex) {
            int x = m;
            // cout << x << endl;
            cout << ans[x-1].first << " " << ans[x-1].second << endl;
        } 
        else {
            cout << B[0] << " " << B[1+ (int)(m - 1LL*(maxeleindex+1))%mod] << endl;
        }
    }

     
    return 0;
}