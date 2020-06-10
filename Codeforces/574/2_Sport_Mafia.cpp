#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,c;
    cin >> n >> c;

    long long tmp;
    int l = 1, r = n, mid;

    while (l <= r) {
        mid = l + (r-l)/2;

        tmp = (1LL*mid*(mid+1+0LL)/2) - 1LL*(n-mid); 

        if (tmp == c) {
            cout << (n-mid);
            break;
        } 

        if (tmp < c) {
            l = mid  + 1;
        } else {
            r = mid - 1;
        }
    }

    return 0;
}