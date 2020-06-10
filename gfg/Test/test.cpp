#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "this is my workplace. this is you. This is you.";
    string p = "XX";

    int pos = s.find(p);
    cout << pos;

    return 0;
}