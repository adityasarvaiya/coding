// https://practice.geeksforgeeks.org/problems/string-formation-from-substring/0

#include <bits/stdc++.h>
using namespace std;

int check(string s, int j) 
{  
    string subst = s.substr(0, j);
    int i, l = s.length();

    for (i = 0; i < l; i += (j)) {
        if (subst != s.substr(i, j)) {
            return 0;
        }
    }

    return 1;
}

int form(string s) 
{
    int i, l = s.length(); 

    // for every substr of len i check first if it is divisible by s.len()
    // if yes then check if given str is formed by this substr
    for (i = 1; i <= l/2; i++) {
        if (l % i == 0) {
            if (check(s, i)) {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n; 
    cin >> t;
    string s;

    while (t--) {
        cin >> s;
        if (form(s)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
     
    return 0;
}