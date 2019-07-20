#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long sum = 0, m, tmp_sum; 
    int n, i; 
    cin >> n >> m;

    vector <int> A(n);
    stack <int> st;
    int ans;
    priority_queue <int> q;

    for (i = 0; i < n; ++i) {
        cin >> A[i];
        sum += A[i];
        ans = 0;

        if (sum > m) {
            tmp_sum = sum;
            vector <int> a;

            while (tmp_sum > m) {
                tmp_sum -= q.top();
                a.push_back(q.top());
                q.pop();
                ans++;
            }

            for (int j = 0; j < a.size(); ++j) { 
                q.push(a[j]);
            }
        }
        
        q.push(A[i]);

        cout << ans << " ";
    }    

    return 0;
}