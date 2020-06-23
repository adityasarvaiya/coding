#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement( vector<int>& A) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    int n = A.size();
    stack<int> s;
    vector<int> ans(n);
    for ( int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            s.push(A[i]);
            ans[i] = -1;
            continue;
        }
        else if ( s.top() > A[i]) {
            ans[i] = s.top();
            s.push(A[i]);

        }
        else {
            while (!s.empty() && s.top() <= A[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = -1;
                s.push(A[i]);
                continue;
            }
            else {
                ans[i] = s.top();
                s.push(A[i]);
            }
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
    for ( int i = 0; i < n; i++) cin >> A[i];

    vector<int> ans = nextLargerElement(A);
    for ( int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}






