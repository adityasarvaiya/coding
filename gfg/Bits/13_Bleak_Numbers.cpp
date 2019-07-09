#include <bits/stdc++.h>
using namespace std;
 
int util(int n)
{
    int i = 0;
    if (n > 32) {
        i = n-32;
    }

    for (; i <= n; i++) {
        int tmp = i, c = 0;

        while (tmp)
        {
            c++;
            tmp &= (tmp-1);
        }
        
        if (i + c == n) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t;
    int n; 
    cin >> t;
     
    while (t--) {
        cin >> n;

        cout << util(n) << endl;
    }
     
    return 0;
}