// wrong implementation
#include <bits/stdc++.h>
using namespace std;

int all9(string st)
{
    int flag=1, len = st.length();

    for (int i = 0; i < len; i++) {
        if (st[i] != '9') {
            flag = 0;
            break;
        }
    }

    if (flag) {
        cout << 1;

        for (int i = 1; i <= len-1; i++) {
            cout << 0;
        }

        cout << 1 << endl;
        return 1;
    }

    return 0;
}

string increment(string st) 
{
    int done = 0, len = st.length();

    for (int i = len-1; i >= 0; i++) {
        if (st[i] < '9') {
            st[i] = st[i] + 1;
            done = 1;
            break;
        }
    }

    if (!done) {
        string ans(len+1, '0');
        ans[0] = '1';

        for (int i = 1; i < len; i++) {
            ans[i] = '0';
        }

        return ans;
    }

    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string s, s1;
        cin >> s1;
        s = increment(s1);

        int len = s.length();

        
        
    }

    return 0;
}