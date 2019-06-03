// https://practice.geeksforgeeks.org/problems/activity-selection/0

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,st; 
    cin >> t;

    while (t--) {
        cin >> n;
        int A[n], B[n];
        vector <pair<int, int>> vec;

        for (i = 0; i < n; ++i) {
            cin >> A[i];
        }

        for (i = 0; i < n; ++i) {
            cin >> B[i];
            vec.push_back({B[i], i});
        }   

        sort(vec.begin(), vec.end());

        st = 0;
        int count = 0;
        for (i = 0; i < vec.size(); ++i) {
            if (st <= A[vec[i].second]) {
                st = vec[i].first;
                count++;
                cout << vec[i].second << " ";
            }
        }

        cout << endl;
        // cout << count << endl;

    }
     
    return 0;
}