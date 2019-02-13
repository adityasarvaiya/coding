// https://practice.geeksforgeeks.org/problems/unsorted-array/0

#include <bits/stdc++.h>
using namespace std;
 
int find_target(vector <int>& nums)
{
    int n = nums.size(), i;
    int max_l_to_r[n], min_r_to_l[n];

    for (i=0; i<n; i++) {
        if (i == 0) {
            max_l_to_r[0] = nums[0];
        } else {
            max_l_to_r[i] = max(max_l_to_r[i-1], nums[i]);
        }
    } 

    for (i=n-1; i>=0; i--) {
        if (i == n-1) {
            min_r_to_l[n-1] = nums[n-1];
        } else {
            min_r_to_l[i] = min(min_r_to_l[i+1], nums[i]);
        }
    } 

    for (i=1; i<n-1; i++) {
        if (nums[i] >= max_l_to_r[i-1] && nums[i] <= min_r_to_l[i+1]) {
            return nums[i];
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t, n, i, curr; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector <int> in;
        
        for (i = 0; i < n; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        int out = find_target(in);

        cout << out << endl;
    }
     
    return 0;
}