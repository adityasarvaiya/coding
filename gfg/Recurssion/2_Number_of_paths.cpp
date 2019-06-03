#include <bits/stdc++.h>
using namespace std;

int countPath(int m, int n, int x, int y) 
{
    if (x > m || y > n) {
        return 0;
    }

    if (x == m && y == n) {
        return 1;
    }

    return (countPath(m,n,x+1,y) + countPath(m,n,x,y+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,x,y; 
    cin >> t;
     
    while (t--) {
        cin >> x >> y;
        cout << countPath(x,y,1,1) << endl;
    }
     
    return 0;
}