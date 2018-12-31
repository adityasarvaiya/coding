#include <bits/stdc++.h>
using namespace std;

int mod(string b, int x) 
{
    int i,b_=b.length(),mod = 0;

    for (i=0;i<b_;i++) {
        mod=(mod*10+b[i]-'0')%x;
    }

    return mod;
}

string divide(string b, int x) 
{
    // int x = stoi(st);
    int i,b_=b.length(),mod = 0;
    string result = "";
    int res, flag = 0;

    for (i=0;i<b_;i++) {
        res = (mod*10+ b[i] - '0') / 2;

        if (res == 0) {
            if (flag) {
                result.push_back(res + '0'); 
            }
        } else {
            result.push_back(res + '0');
            flag = 1;
        }
        mod=(mod*10+b[i]-'0')%x;    
    }

    return result;
}

string sub(string st, string x) 
{
    int i, res, borrow = 0, flag = 0;
    string result = "";   

    reverse(st.begin(), st.end());
    reverse(x.begin(), x.end());

    for (i = 0; i < x.length(); ++i) {
        res = (st[i] - '0') - (x[i] - '0') - borrow;

        if (res < 0) {
            res += 10;
            borrow = 1;
        } else {
            borrow = 0;
        } 

        result.push_back(res + '0');
    }

    for (i = x.length(); i < st.length(); ++i) {
        res = (st[i] - '0') - borrow;

        if (res < 0) {
            res += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        if (res == 0) {
            if (flag) {
                result.push_back(res + '0'); 
            }
        } else {
            result.push_back(res + '0');
            flag = 1;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, char const *argv[])
{
    int n = 10;
    string st, x;

    while (n--) {
        cin >> st;
        cin >> x;

        string r = sub(st, x);
        string n = divide(r, 2);
        string k = sub(st, n);

        cout << k << endl << n << endl;

    }

    return 0;
}
