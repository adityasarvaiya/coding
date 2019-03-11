// 
// https://practice.geeksforgeeks.org/problems/k-largest-elements/0
// leetcode

#include <bits/stdc++.h>
using namespace std;

int find(vector<int> nums, int k) 
{
    sort(nums.begin(), nums.end());

    return nums[nums.size()-k];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr,k;
        cin >> n;
        vector <int> in;

        for (i=0; i<n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

        cin >> k;

       cout << find(in,k) << endl;

    }
    return 0;
}