#include <bits/stdc++.h>
using namespace std;

long long Atoi(string s)
{
    int n = s.length(), i;
    long long res = 0;

    for (i = 0; i < n; ++i) {
        
        if (i == 0 && s[i] == '-') {
            continue;
        } else {
            if (isalpha(s[i])) {
                return -1;
            }
            res = res * 10 + (s[i] - '0');
        }
    }

    return s[0] == '-' ? res * -1 : res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << Atoi(s) << endl;

    }
    return 0;
}