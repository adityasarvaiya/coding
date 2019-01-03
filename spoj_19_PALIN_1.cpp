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
        string st, s1, s2;
        cin >> st;

        int len = st.length();

        if (len == 1) {
            if (st[0] < '9') {
                cout << st[0]-'0'+1 << endl;
            } else {
                cout << 11 << endl;
            }
        } else if (!all9(st)) {

            int isOddLen, i,j,f=1;
            char midChar;

            if (len % 2 == 0) {
                i = (len / 2) - 1;
                j = len / 2;
                isOddLen = 0;
            } else {
                i = (len / 2) - 1;
                j = len / 2 + 1;
                isOddLen = 1;
                midChar = st[len/2];
            }
            
            s1 = st.substr(0, len/2);
            s2 = st.substr(j, len/2);

            while (i >= 0) {
                if (st[i] > st[j]) {
                    break;
                } else if (st[i] < st[j]) {
                    if (isOddLen) { 
                        if (midChar < '9') {
                            midChar = midChar + 1;
                            break;
                        } else {
                            midChar = '0';
                        }
                    }

                    s1 = increment(s1);
                    f = 0;
                    break;
                } else {
                    i--;
                    j++;
                }
            }
            
            if (f) {
                if (isOddLen) { 
                    if (midChar < '9') {
                        midChar = midChar + 1;
                    } else {
                        midChar = '0';
                     //   s1 = increment(s1);
                    }
                } else {
                   // s1 = increment(s1);
                }
            }

            cout << s1;
            if (isOddLen) {
                cout << midChar;
            }
            reverse(s1.begin(), s1.end());
            cout << s1 << endl;

        }
    }

    return 0;
}