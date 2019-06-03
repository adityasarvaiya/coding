#include <bits/stdc++.h>
using namespace std;

int find(string s)
{
    int i,c=0,l = s.length();

    for (i = 0; i < l; ++i) {
        if (s[i] == '1') {
            ++c;
        }
    }

    return ((c-1)*c/2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int temp;
        cin >> temp;
        string s;
        cin >> s;

        cout << find(s) << endl;

    }
    return 0;
}