//https://www.spoj.com/problems/PALIN/
// wrong implementation
#include <bits/stdc++.h>
using namespace std;

string strim(string st)
{
    int i;

    for (i = st.length()-1; i >= 0; --i) {
        if (st[i] == '0') {
            continue;
        } else {
            break;
        }
    }



    return st.substr(0, i+1);
}

string increment(string st1)
{   
    string st = strim(st1);
    // cout << st << endl;
    int len = st.length();
    int i, flag = 0;

    i = len/2 + 1 - 1;

    if (i > 0 && st[i-1] < st[i]) {
        st[i-1] = st[i];
    } else {
        for (; i < len; ++i) {
            if (st[i] != '9') {
                st[i] = st[i] + 1;
                flag = 1;
                break;
            } else {
                st[i] = '0';
            }
        }

        if (!flag) {
            st.push_back('1');
        }
    }

    return st;
}

string make_palin(string st)
{
    int len = st.length();
    for (int i = 0; i < len / 2; ++i) {
        st[len - i - 1] = st[i];

        // if (st[len - i - 1] > st[i] || st[len - i - 1] == '0') {
        //     st[len - i - 1] = st[i];
        // } else {
        //     st[i] = st[len - i - 1];
        // }
    }

    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, len;
    cin >> n;
    
    while (n--) {
        string st;
        cin >> st;

        reverse(st.begin(), st.end());
        string st1 = increment(st);
        // cout << st1 << endl;
        reverse(st1.begin(), st1.end());
        // cout << st1 << endl;

        cout << make_palin(st1) << endl;       

    }

    return 0;
}