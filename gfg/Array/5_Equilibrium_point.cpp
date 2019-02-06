//https://practice.geeksforgeeks.org/problems/equilibrium-point/0 <br>
//https://www.geeksforgeeks.org/equilibrium-index-of-an-array/

#include <bits/stdc++.h>
using namespace std;

int Find_Equilibrium_Point(vector <int> a) 
{
    int sum = accumulate(a.begin(), a.end(), 0), left_sum = 0, i=0;

    vector <int> :: iterator it;

    for (it = a.begin(); it != a.end(); ++it) {
        sum -= *it;

        if (left_sum == sum) {
            return i+1;
        } else {
            left_sum += *it;
            i++;
        }
    } 

    return -1;
}

int main() 
{
    int t;
    cin >> t;

    while (t--) {
        int n,curr;
        cin >> n;
        vector <int> a;

        for (int i=0; i<n; ++i) {
            cin >> curr;
            a.push_back(curr);
        }

        cout << Find_Equilibrium_Point(a) << endl;
        
    }

    return 0;
}