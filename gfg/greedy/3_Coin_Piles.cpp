#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,st,k,f; 
    cin >> t;

    while (t--) {
        cin >> n >> k;
        int tmp, minele, maxele;
        vector <int> vec;
        priority_queue <int, vector<int>, greater<int>> q;

        for (i = 0; i < n; ++i) {
            cin >> tmp;
            vec.push_back(tmp);
            q.push(tmp);
        }

        long long remove,ans = LLONG_MAX;
        while (!q.empty()) {
            minele = q.top();
            q.pop();
            remove = 0;
            f = 1;

            for (i = 0; i < vec.size(); ++i) {
                if (vec[i] - minele > k) {
                    remove += (vec[i] - minele - k);
                    f = 0;
                } else if (vec[i] < minele) {
                    remove += vec[i];
                }
            }

            ans = min(ans, remove);

            if (f) break;
        }

        cout << ans << endl;

    }
     
    return 0;
}