#include <bits/stdc++.h>
using namespace std;
 
int find_min_op(int n, unordered_map<int, int> &h) {

    if (h.find(n) != h.end()) {
        return h[n];
    }

    h[n] = n%2 == 1 ? 1+find_min_op(n-1, h) : 1+ find_min_op(n/2, h);

    return h[n];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n; 
    cin >> t;
    
    unordered_map <int, int> h;
    h[0] = 0;
    h[1] = 1;

    while (t--) {
        cin >> n;

        cout << find_min_op(n, h) << endl;

    }
     
    return 0;
}