// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
// https://www.geeksforgeeks.org/find-the-missing-number/

#include <bits/stdc++.h>
using namespace std;

int find_missing_num(vector<int> in) 
{   
    int missing, sum = 0, exp_sum, n = in.size();
    vector <int> :: iterator it;

    for (it = in.begin(); it != in.end(); it++) {
        sum += (*it);
    }


    // we will use direct formula to find sum = n(n+1)/2
    // here we have n+1 actual elements in actual array (without missing value)
    exp_sum = (n+1)*(n+2) / 2;

    return exp_sum - sum;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin >> t;

    while (t--) {
        int i,curr;
        cin >> n;
        vector <int> in;

        for (i = 0; i < n-1; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        int out = find_missing_num(in);

        cout << out << endl;
    }

    return 0;
}