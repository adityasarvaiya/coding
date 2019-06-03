#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,tmp,k; 
    cin >> t;
     
    while (t--) {
        cin >> n >> k;
        vector <int> vec;

        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            vec.push_back(tmp);
        }

        sort(vec.begin(), vec.end());

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (vec[i] <= k) {
                k -= vec[i];
                count++;
            } else {
                break;
            }
        }

        cout << count << endl;

    }
     
    return 0;
}