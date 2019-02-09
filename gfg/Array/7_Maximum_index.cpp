// https://practice.geeksforgeeks.org/problems/maximum-index/0
// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

#include <bits/stdc++.h>
using namespace std;

int find_max_index(vector <int> nums) 
{   
    int n=nums.size(),i=0, j=0, k, max_diff = 0;
    int min_left[n], max_right[n];

    min_left[0] = nums[0];
    for (k = 1; k < n; k++) {
        min_left[k] = min(nums[k], min_left[k-1]);
    }

    max_right[n-1] = nums[n-1];
    for (k = n-2; k >= 0; k--) {
        max_right[k] = max(nums[k], max_right[k+1]);
    }

    while (j < n && i < n) {
        // cout << i << " " << j << " " << max_diff << endl;
        if (min_left[i] <= max_right[j]) {
            max_diff = max(max_diff, j-i);
            j++;
        } else {
            i++;
        }

        // cout << i << " " << j << " " << max_diff << endl << endl;
    }

    return max_diff;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr,max;
        cin >> n;
        vector<int> in;

        for (i = 0; i < n; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        max = find_max_index(in);

        cout << max << endl;
    }

    return 0;
}