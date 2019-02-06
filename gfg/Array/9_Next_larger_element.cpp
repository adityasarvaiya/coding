// https://practice.geeksforgeeks.org/problems/next-larger-element/0
// https://www.geeksforgeeks.org/next-greater-element/
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int t;
    cin >> t;

    while (t--) {
        int n, i;
        cin >> n;
        long long in[n], out[n];
        stack <long long> st;

        for (i=0; i < n; ++i) {
            cin >> in[i];
        }

        for (i=n-1; i >= 0; --i) {
            while (!st.empty() && st.top() <= in[i]) {
                st.pop();
            }

            if (st.empty()) {
                out[i] = -1;
            } else {
                out[i] = st.top();
            }

            st.push(in[i]);
        }

        for (i=0; i < n; ++i) {
            cout << out[i] << " " ;
        }

        cout << endl;
    }

    return 0;
}