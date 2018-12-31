#include <bits/stdc++.h>
using namespace std;

int stringtonum(string st) 
{
    int i, res = 0, n = st.length();


    for (i = 0; i < n; i++) {
        res = res*10 + (st[i] - '0');
    }

    return res;
}

int decode(string n, unordered_map <int, int> ar, int index) 
{

    if (ar.find(index) != ar.end()) {
        return ar[index];
    
    } else {

        int res = 0;

        if (n[0] == '0') {
            return 0;
        } else if (n.length() == 1) {
            return 1;
        } else if (n.length() == 2) {
            res = (n[0] - '0') * 10 + (n[1] - '0');

            if (res < 27 && (res > 0 && res != 10)) {
                return 2;
            } else {
                return 1;
            }
        }

        string s1 = n.substr(1,n.length()-1);

        if (s1.length() > 1) {
            res += decode(s1);
        }

        if (n.length() > 1 && stringtonum(n.substr(0,2)) < 27) {
            if (n[0] != '0') {
                res += decode(n.substr(2, n.length() - 2));
            }
        }
    }

    return res;
}

int process(string n) 
{   
    int res = 0;
    int curr;

    unordered_map <int, int> ar;

    for (int i = n.length()-1; i >= 0; --i) {
        if (ar.find(i) == ar.end()) {
            curr = decode(n.substr(i, n.length()-i), ar, i);
            ar[i] = curr;
        }

        res += ar[i];
    }

    for (auto x : ar)
      cout << x.first << " " << x.second << endl;

    return ar[0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ways;
    string n;
    cin >> n;

    while (n[0] != '0') {
        ways = process(n);
        cout << ways << endl;
        cin >> n;
    }

    return 0;
}