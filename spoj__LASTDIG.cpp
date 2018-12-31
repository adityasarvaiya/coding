#include <bits/stdc++.h>
using namespace std;

int m(string b, int x) 
{
    int i,b_=b.length(),mod = 0;

    for (i=0;i<b_;i++) {
        mod=(mod*10+b[i]-'0')%x;
    }

    return mod;
}

int main()
{
    int n, a_, b_, e, r;
    cin >> n;
    string a, b;

    while (n--) {
        cin >> a >> b;

        a_ = a.length();
        b_ = b.length();

        if ((a_ == 1 && b_ == 1) && (a[a_ - 1] == '0' && b[b_ - 1] == '0')) {
            r = 1;
        } else if (a_ == 1 && a[a_ - 1] == '0') {
            r = 0;
        } else if (b_ == 1 && b[b_ - 1] == '0') {
            r = 1;
        } else {
            e = (m(b, 4) == 0) ? 4 : m(b, 4);
            r = pow(a[a_ - 1] - '0', e);
        }

        cout << (r % 10) << endl;
    }

    return 0;
}
