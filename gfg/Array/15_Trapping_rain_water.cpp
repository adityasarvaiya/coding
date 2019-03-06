// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

#include <bits/stdc++.h>
using namespace std;

int find_tot_trapped_water(vector <int> nums, int n)
{
    int max_left[n], max_rt, i, water=0;

    for (i = n-1; i >= 0; --i) {
        if (i == n-1) {
            max_left[i] = nums[i];
        } else {
            max_left[i] = max(max_left[i+1], nums[i]);
        }
    }   

    for (i = 0; i < n; ++i) {
        if (i == 0) {
            max_rt = nums[i];
        } else {
            max_rt = max(max_rt, nums[i]);
        }

        water += min(max_rt, max_left[i]) - nums[i];
    }   

    return water;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,curr;
    cin >> t;

    while (t--) {
        cin >> n;
        vector <int> nums;

        for (i = 0; i < n; ++i) {
            cin >> curr;
            nums.push_back(curr);
        }

        cout << find_tot_trapped_water(nums,n) << endl;
    }

    return 0;
}