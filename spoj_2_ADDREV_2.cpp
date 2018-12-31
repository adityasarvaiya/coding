#include <iostream>
#include <cmath>

using namespace std;

int countdigits(int x)
{
    int digits = 0;

    while (x >= 1) {
        ++digits;
        x /= 10;
    }

    return digits;
}

int rev(int x)
{
    int l = countdigits(x);
    int i;
    int ans = 0;

    for (i = 1; i <= l; ++i) {
        // cout << "pow(10,l-i) " << pow(10,l-i) << "  (x % 10) " << (x % 10) << endl;
        ans += (pow(10,l-i)) * (x % 10);
        x /= 10;
    }

    return ans;
}

int main()
{
    int n;
    int i;
    int x1, x2;
    int ans;
    cin >> n;

    for (i = 0; i < n; ++i) {
        cin >> x1 >> x2;

        x1 = rev(x1);
        x2 = rev(x2);

        // cout << "X1, X2 : " << x1 << " " << x2 << endl;

        ans = x1 + x2;
        // cout << "Ans : " << ans << endl;
        ans = rev(ans);

        cout << ans << endl;
    }

    return 0;
}