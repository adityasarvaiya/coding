#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

void show(vector <string> A) {
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }

    cout << endl;
}

long long util(string s) {
    int n = s.length();
    string new_s = s + s;
    int index = new_s.find(s, 1);

    long long i = 1;
    cout << index << " " << endl;

    // cout << 1 << s << " " << new_s << endl;

    while (1) {
        if (((i * (i+1) / 2) % s.length()) == index) {
            return i;
        }

        i++;
    }
    
    return -1;
}

int find(vector <string> A)
{
    long long ans = 1, t;

    for (int i = 0; i < A.size(); ++i) {
        t = util(A[i]);

        ans = ((ans%mod * t%mod)%mod) / __gcd(ans, t);
    }

    return ans % mod;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <string> A(n);

    for (int i = 0; i < n; ++i) {    
        cin >> A[i];
        cin.ignore();

        cout << A[i] << endl;

        cout << find(A) << endl;

    }

    // show(A);

    return 0;
}