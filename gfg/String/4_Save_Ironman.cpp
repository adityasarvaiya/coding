// https://practice.geeksforgeeks.org/problems/save-ironman/0

#include <bits/stdc++.h>
using namespace std;

int check_palindrom(string in) 
{
    long long l = in.length(),i=0,j=l-1;

    while (true) {
        while (!isalnum(in[i])) {
            ++i;
        }

        while (!isalnum(in[j])) {
            --j;
        }

        if (i > j) {
            break;
        }

        if (tolower(in[i++]) != tolower(in[j--])) {
            return 0;
        }
    }

    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int n,i,curr;
        string in;

        getline(cin, in);
        // cout << in << endl;

        if (check_palindrom(in)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}