//https://www.spoj.com/problems/ACODE/

#include <bits/stdc++.h>
using namespace std;

long long int process(string st, unordered_map <int, long long int> ar) 
{
    long long int res = 0;
    int i;

    // for (auto x : ar)
    //     cout << x.first << " " << x.second << endl;
    // cout << endl;

    for (i = st.length()-3; i >= 0; --i) {
        if (ar.find(i) == ar.end()) {
            res = (st[i] - '0') * 10 + (st[i+1] - '0');

            if (res < 27 && (res > 10 && res != 20)) {
                if (i < st.length()-3 && st[i+2] == '0')  {
                    ar[i] = ar[i+1];
                } else {
                    ar[i] = ar[i+1] + ar[i+2];
                }
            } else {
                ar[i] = ar[i+1];
            }
        }

        // for (auto x : ar)
        //     cout << x.first << " " << x.second << endl;

        cout << endl;
    }

    
    return ar[0];
}

int main()
{
    long long int res = 0;
    string st;
    cin >> st;

    while (st[0] != '0') {
        unordered_map <int, long long int> ar;
        int res;

        if (st[st.length() - 1] == '0') {
            ar[st.length() - 1] = 0;
        } else {
            ar[st.length() - 1] = 1;
        }

        res = (st[st.length()-2] - '0') * 10 + (st[st.length()-1] - '0');

        if (res < 27 && (res > 10 && res != 20)) {
            ar[st.length()-2] = 2;
        } else {
            ar[st.length()-2] = 1;
        }

        res = process(st, ar);
        cout << res << endl;

        cin >> st;
    }

    return 0;
}