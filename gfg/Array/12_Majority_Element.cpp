// https://practice.geeksforgeeks.org/problems/majority-element/0

#include <bits/stdc++.h>
using namespace std;

int find_majority(vector<int> nums)
{   
    int n=nums.size(),i;
    int voters[n], votes[n];
    vector <int> :: iterator it;

     
    for (i=0; i<n; i++) {
        if (i==0) {
            voters[0] = nums[0];
            votes[0] = 1;
        } else {
            if (nums[i] == voters[i-1]) {
                voters[i] = voters[i-1];
                votes[i] = votes[i-1] + 1;
            } else {
                if (votes[i-1] == 0) {
                    voters[i] = nums[i];
                    votes[i] = 1;
                } else {
                    voters[i] = voters[i-1];
                    votes[i] = votes[i-1] - 1;
                }
            }
        }
    }

    int count = 0;

    // cout << voters[n-1] << " " << votes[n-1] << " " << count << endl;

    if (votes[n-1] == 0) {
        return -1;
    } 

    for (i=0; i<n; i++) {
        if (nums[i] == voters[n-1]) {
            count++;
        }
    }

    if (count > n/2) {
        return voters[n-1];
    }

    return -1;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n,i,curr;
        cin >> n;

        vector<int> in;

        for (i=0; i<n; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        int out = find_majority(in);

        cout << out << endl;
    }

    return 0;
}