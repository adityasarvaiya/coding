#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, len, i, j, prod, carry;
    int ar[200];
    cin >> n;

    while (n--) {
        cin >> x;
        ar[0] = 1;
        len = 1;

        for (i = 2; i <= x; ++i) {
            carry = 0;
            for (j = 0; j < len; j++) {
                prod = (ar[j] * i) + carry;
                ar[j] = prod % 10;
                carry = prod / 10;
            }

            while (carry > 0) {
                ar[len++] = carry % 10;
                carry = carry / 10;
            }
        }

        // we have to give output in reverse order
        for (i = len - 1; i >= 0; --i) {
            cout << ar[i];
        }

        cout << endl;
    }   

    return 0;
}
