#include <bits/stdc++.h>
using namespace std;

int find(vector <vector <int>> a, int r, int c, int pr, int pc) {

    int inright = 0, inleft = 0;    

    for (int i = 0; i < r; i++) {
        
    }

    return ;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,r,c;
    cin >> t;

    while (t--) {
        cin >> r >> c;

        vector <vector<int>> a(r);

        for (int i = 0; i < c; ++i) {
            a[i] = vector<int> (c);
        }

        cout << find(a,r,c, (r/2)+1, (c/2)+1);
    }
    return 0;
}