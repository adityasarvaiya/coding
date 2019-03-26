#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack <char> st;
    
    int i,n = s.length();
    
    for (i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
            st.push(s[i]);
            continue;
        } 

        char x = st.top();
        st.pop();
        switch (s[i])
        {
            case ')':
                if (x != '(') {
                    return 0;
                }
                break;

            case ']':
                if (x != '[') {
                    return 0;
                }
                break;

            case '}':
                if (x != '{') {
                    return 0;
                }
                break;
        }
    }
    
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string st;
        cin >> st;

        if (isValid(st)) {
            cout << "balanced" << endl;
        } else {
            cout << "not balanced" << endl;
        }
    }
    return 0;
}