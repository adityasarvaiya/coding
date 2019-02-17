// https://practice.geeksforgeeks.org/problems/equal-to-product/0

#include <bits/stdc++.h>
using namespace std;

int find_ans(vector<unsigned long long> &nums, unsigned long long x) 
{
    unordered_map<unsigned long long, int> hash;
    vector <unsigned long long> :: iterator it;
    unsigned long long other;

    for (it = nums.begin(); it != nums.end(); it++) {
        if ((*it) == 0) {
            if (x == 0) {
                return 1;
            }
        } else if (x % (*it) == 0) {
            other = x/(*it);
            if (hash.find(other) != hash.end()) {
                // cout << *it << " " << x/(*it) << endl;
                return 1;  
            }
        }
        
        if (hash.find(*it) != hash.end()) {
            hash[*it] += 1;
        } else {
            hash[*it] = 1;
        }
    }

    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    unsigned long long t, n, x, i, curr; 
    cin >> t;
     
    while (t--) {
        cin >> n >> x;
        vector <unsigned long long> in;

        for (i = 0; i < n; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        int out = find_ans(in, x);

        if (out == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
     
    return 0;
}