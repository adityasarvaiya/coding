#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    while (n != 0) {
        cout << (n * (n + 1) * (n * 2 + 1) / 6) << endl;

        cin >> n;
    }

    return 0;
}
