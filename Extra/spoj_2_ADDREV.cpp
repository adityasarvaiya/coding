#include <iostream>

using namespace std;

double rev(int x)
{
    int i;
    int ans;

    ans = 0;

    while (x) {
        ans = (ans * 10) + (x % 10);
        x /= 10;
    }

    return ans;
}

int main()
{
    int n;
    int i;
    double x1, x2;
    double ans;
    cin >> n;

    for (i = 0; i < n; ++i) {
        cin >> x1;
        cin >> x2;

        cout << rev( rev(x1) + rev(x2)) << endl;
    }

    return 0;
}