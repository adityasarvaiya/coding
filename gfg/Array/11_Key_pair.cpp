#include <bits/stdc++.h>
using namespace std;

int find_key_pair(vector<int> nums, int x) 
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int i = 0, j = n-1;
    int sum = nums[i] + nums[j];

    while (i < j) {
        if (sum == x) {
            return 1;
        } else if (sum < x) {
            sum -= nums[i++];
            sum += nums[i];
        } else {
            sum -= nums[j--];
            sum += nums[j];
        }
    }

    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,curr,x; 
    cin >> t;
     
    while (t--) {
        cin >> n >> x;
        vector <int> in;

        for (i = 0; i < n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

        if (find_key_pair(in,x)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}