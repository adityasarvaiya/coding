// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
// https://www.geeksforgeeks.org/array-rotation/

#include <bits/stdc++.h>
using namespace std;

vector <int> rotate_array(vector<int> nums, int d) 
{
    int n = nums.size(), i, j;

    if (n == 0) {
        return nums ;
    }

    i = (n-d); j = n-1;

    while (i < j) {
        swap(nums[i++], nums[j--]);
    }

    i = 0; j = n-d-1;

    while (i < j) {
        swap(nums[i++], nums[j--]);
    }

    reverse(nums.begin(), nums.end());

    return nums; 
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int > :: iterator it;
    int t, n, d, i, curr; 
    cin >> t;

    while (t--) {
        cin >> n >> d;
        vector <int> in;

        for (i = 0; i < n; ++i) {
            cin >> curr;
            in.push_back(curr);
        }

        vector <int> out = rotate_array(in, d);


        for (it = out.begin(); it != out.end(); ++it) {
            cout << *it << " ";
        }

        cout << endl;
    }

    return 0;
}