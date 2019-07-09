#include <bits/stdc++.h>
using namespace std;
 
void util(int n) 
{
    if (n==0) {
        cout << 0 << endl;
        return;
    }

    vector <int> a;

    while (n)
    {
        a.push_back(n%2);
        n /= 2;
    }

    if (a.size() < 14) {
        for (int i = 14-a.size(); i >= 0; --i) {
            cout << 0;
        } 
    }

    for (int i = a.size()-1; i >= 0; --i) {
        cout << a[i];
    } 
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        util(n);
    }
     
    return 0;
}