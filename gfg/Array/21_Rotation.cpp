// https://practice.geeksforgeeks.org/problems/rotation/0
// Given a sorted array A of size N. The array is rotated 'K' times. Find the value of 'K'. The array may contain duplicate elements.

// unsubmitted

#include <bits/stdc++.h>
using namespace std;

int find(vector <int> nums)
{       
    long long tot_sum=0, curr_sum=0, g_sum = INT_MIN, g_index;
    int n = nums.size(),i;

    for (i = 0; i < n; ++i) {
        tot_sum += nums[i];
        curr_sum += (nums[i] * i);
    }

    g_sum = curr_sum;
    g_index = 0;

    for (i = 1; i < n; ++i) {
        curr_sum = curr_sum - (tot_sum - nums[i]) + (nums[i] * (n-1));

        if (curr_sum > g_sum) {
            g_sum = curr_sum;
            g_index = i;
        }

    }

    return g_index;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr;
        cin >> n;
        vector <int> in;

        for (i=0; i<n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

       cout << find(in) << endl;

    }
    return 0;
}