#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,s; 
    long long tmp;
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector <long long> A,B;

        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            A.push_back(tmp);
        }

        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            B.push_back(tmp);
        }


        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<long long>());

        tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp += (A[i] * B[i]);
        }

        cout << tmp << endl;
    }
     
 
    return 0;
}