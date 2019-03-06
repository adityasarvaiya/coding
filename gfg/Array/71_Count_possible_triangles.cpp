// https://practice.geeksforgeeks.org/problems/count-possible-triangles/0
// unsubmitted

#include <bits/stdc++.h>
using namespace std;

int find_possible_tri(vector<int> nums) 
{   
    int i,j,k, sum, triangles=0, n = nums.size();
    sort(nums.begin(), nums.end());

    // for (i = 0; i < n; ++i) {
    //     nums[i] = pow(nums[i], 2);
    // }

    for (i = 0; i < n-2; ++i) {
        for (j = i+1; j < n-1; ++j) {
            sum = nums[i] + nums[j];

            // triangles += (n-j-1);

            for (k = j+1; k < n; ++k) {
                if (nums[k] >= sum) {
                    triangles += (n-k);
                    break;
                }
            }
        }
    }

    return triangles;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr;
        cin >> n;
        vector <int> nums;

        for (i=0; i<n; ++i) {
            cin >> curr;
            nums.push_back(curr);
        }

        cout << find_possible_tri(nums) << endl;
    }
    return 0;
}
