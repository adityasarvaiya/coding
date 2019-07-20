#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    long long d, ans = 0;
    vector <long long> A(3);
    cin >> A[0] >> A[1] >> A[2] >> d;
    sort(A.begin(), A.end());

    if ((A[1] - A[0]) < d) {
        ans += (d - (A[1] - A[0]));
    }

    if ((A[2] - A[1]) < d) {
        ans += (d - (A[2] - A[1]));
    }

    cout << ans << endl;
      
    return 0;
}