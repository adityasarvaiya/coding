// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0
// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
// https://leetcode.com/problems/largest-number/submissions/

#include <bits/stdc++.h>
using namespace std;

bool static comparator(int a, int b) 
{
    string ab = to_string(a).append(to_string(b));
    string ba = to_string(b).append(to_string(a));

    return ab > ba;
}

vector <int> find_max_number(vector <int>& in)
{
    sort(in.begin(), in.end(), comparator);

    return in;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t, n, i, curr; 
    cin >> t;
     
    while (t--) {
        cin >> n;
        vector<int> in;

        for (i = 0; i < n; i++) {
            cin >> curr;
            in.push_back(curr);
        }

        vector<int> out = find_max_number(in);

        if (out[0] == '0') {
            cout << "0";   // Corner case : with all zeros as input ==> output == "0" Not "0000.."
        } else {
            for (i = 0; i < n; i++) {
                cout << out[i];
            } 
        }


        cout << endl;
    }
     
    return 0;
}