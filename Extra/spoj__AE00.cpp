#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, i, j, count=0;
    cin >> n;

    for (i = 1; i <= n; ++i) {
        for (j = i; j <= n; ++j) {
            if ((i * j) > n) {
                break;
            }
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
