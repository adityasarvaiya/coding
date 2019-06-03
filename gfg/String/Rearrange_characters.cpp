#include <bits/stdc++.h>
using namespace std;

int rearrange(string s)
{
    int hash[26];
    int i, l = s.length();
    int max_l = (l + 1) / 2;

    for (i = 0; i < 26; ++i) {
        hash[i] = 0;
    }

    for (i=0; i < l; ++i) {
        hash[s[i] - 'a'] = hash[s[i] - 'a'] + 1;
        if (hash[s[i] - 'a'] > max_l) {
            return 0;
        }
    }


    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string s;
    cin >> t;

    while (t--) {
        cin >> s;
        cout << rearrange(s) << endl;
    }

    return 0;
}