#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,k,i,tmp; 
    cin >> t;
     
    while (t--) {
        priority_queue <int, vector <int>, greater<int>> q;
        cin >> k;
        cin >> n;
        
        for (i = 0; i < n; ++i) {
            cin >> tmp;
            q.push(tmp);

            if (i < k-1) {
                cout << -1 << " ";
                continue;
            }

            while (q.size() > k) {
                q.pop();
            }

            cout << q.top() << " ";
        }

        cout << endl;
    }
     
    return 0;
}