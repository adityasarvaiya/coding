#include <bits/stdc++.h>

using namespace std;

int main () {
    string s = "  Aditya k Sarvaiya ";

    cout << s << endl;

    replace(s.begin(), s.end(), ' ', '+');

    cout << s << endl;

    return 0;
}