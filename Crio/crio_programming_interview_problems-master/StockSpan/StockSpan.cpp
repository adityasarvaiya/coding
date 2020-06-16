
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> &A )
{
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    stack<int> s;
    int n = A.size();
    vector<int> ans(A.size());
    for ( int i = 0; i < n; i++) {
        while (!s.empty() && A[s.top()] <= A[i])
            s.pop();
        if (s.empty())
        {
            ans[i] = i + 1;
            s.push(i);
        } else {
            ans[i] = i - s.top();
            s.push(i);
        }
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for ( int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> ans = stockSpan(A);
    for ( int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}






