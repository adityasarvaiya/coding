// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0 <br>
// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,k,i,curr;
        cin >> n >> k;
        int a[n];
        int b[n-k+1];
        deque <int> dq;

        for (i=0; i<k; ++i) {
            cin >> a[i];
            while (!dq.empty() && a[i] > a[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        
        b[0] = a[dq.front()];

        for (; i<n; ++i) {
            cin >> a[i];
            while (!dq.empty() && a[i] > a[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i - dq.front() >= k) {
                dq.pop_front();
            }

            b[i-k+1] = a[dq.front()];
        }

        for (i=0; i<n-k+1; ++i) {
            cout << b[i] << " ";
        }

        cout << endl;
    }

    return 0;
}