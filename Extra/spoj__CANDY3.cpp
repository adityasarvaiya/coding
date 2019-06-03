#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, t, i, sum, x;
    cin >> n;

    while (n--) {
        cin >> t;
        sum = 0;

        for (i = 0; i < t; ++i) {
            cin >> x;
            sum = (sum + x) % t;
        }

        if (sum) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
