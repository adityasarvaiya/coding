#include <bits/stdc++.h>
using namespace std;

long long util(string &s) {

    long long curr, prev1 = 1, prev2 = 0;
    int len = s.length();

    for (int i = s.length()-1; i >= 0; --i) {
        curr = 0;

        if (s[i] != '0') {
            curr += prev1;
        }
        
        if (i < len-1 && (s[i]-'0' == 1) || (s[i]-'0' == 2 && s[i+1]-'0' < 7)) {
            curr += prev2;
        }

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "A";

    while (true) {
        cin >> s;

        if (s[0] == '0' && s.size() == 1) {
            break;
        }

        cout << util(s) << endl;
    }

    return 0;
}