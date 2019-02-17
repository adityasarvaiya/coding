// https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
// https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0

#include <bits/stdc++.h>
using namespace std;

int find_pythagorean(vector<int> nums)
{
    int n = nums.size();
    vector <int> :: iterator it;

    for (it = nums.begin(); it < nums.end(); it++) {
        (*it) *= (*it);
    }

    sort(nums.begin(), nums.end());

    for (it = nums.begin(); it < nums.end(); it++) {
        cout << (*it) << endl;
    }

    for (int k = n-1; k > 1; --k) {
        int i = 0, j = k-1;
        int curr_sum = nums[i] + nums[j];

        while (i<j) {
            if (curr_sum == nums[k]) {
                return 1;
            } else if (curr_sum < nums[k]) {
                curr_sum -= nums[i++]; 
                curr_sum += nums[i]; 
            } else {
                curr_sum -= nums[j--]; 
                curr_sum += nums[j];
            }
        }
    }

    return 0;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,i,curr; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector <int> in;

        for (i = 0; i < n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

        if (find_pythagorean(in)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
     
    return 0;
}