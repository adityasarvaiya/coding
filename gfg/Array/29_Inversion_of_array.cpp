// https://practice.geeksforgeeks.org/problems/inversion-of-array/0
// unsubmitted


#include <bits/stdc++.h>
using namespace std;

int find_inversions(vector<pair<int,int>> nums) 
{
    sort(nums.begin(), nums.end());

    int len = nums.size(), diff, count = 0;

    for (int i = 0; i < len; i++) {
        diff = i - nums[i].second;

        if (diff > 0) {
            count += diff;
        } 
    }

    return count;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        int i, curr;
        vector <pair<int, int>> in;

        for (i = 0; i < n; i++) {
            cin >> curr;
            in.push_back(make_pair(curr, i));
        }

        int out = find_inversions(in);
        cout << out << endl;
    }
     
    return 0;
}