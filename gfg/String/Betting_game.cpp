// https://practice.geeksforgeeks.org/problems/betting-game/0
#include <bits/stdc++.h>
using namespace std;

int bet(string s) 
{
    int i, sum = 1, money=4;

    for (i = 0; i < s.length(); ++i) {
        if (sum > money) {
            return -1;
        }
        
        if (s[i] == 'W') {
            money = money + sum;
            sum = 1;
        } else {
            money = money - sum;
            sum = 2 * sum;
        }  
    }

    return money;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int t;
    cin >> t;

    while (t--) {
        cin >> s;
        cout << bet(s) << endl;
    }

    return 0;
}