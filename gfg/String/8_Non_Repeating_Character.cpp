// https://practice.geeksforgeeks.org/problems/non-repeating-character/0

#include <bits/stdc++.h>
using namespace std;

char find(string s,int len)
{
    int hash[26], i;
    fill_n(hash, 26, 0);

    for (i = 0; i < len; ++i) {
        hash[s[i] - 'a'] += 1;
    }

    for (i = 0; i < len; ++i) {
        if (hash[s[i]-'a'] == 1) { 
            return s[i];
        }
    }

    return '1';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s;
        int len;
        cin >> len;
        cin >> s;

        char out = find(s,len);

        if ( out == '1' ) {
            cout << -1 << endl;
        } else {
            cout << out << endl;
        }
    }

    return 0;
}