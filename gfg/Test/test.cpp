#include <bits/stdc++.h>
using namespace std;
 
int util(int **a, int n, int m) {
    
    int ones = 0, ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cout << a[i][j] << " ";
            if (a[i][j] == 1) {
                ones++;
            }
        }

        // cout << endl;
    }

    while (ones > 0) {
        int curr = ones;
        typedef pair<int, int> pairs; 
        set<pairs> h;
        // unordered_set <pair<int, int>> h;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 2 && h.find({i,j}) == h.end()) {
                    if (i-1 >= 0 && a[i-1][j] == 1) {
                        a[i-1][j] = 2;
                        ones--;
                        h.insert({i-1,j});
                    }

                    if (i+1 < n && a[i+1][j] == 1) {
                        a[i+1][j] = 2;
                        ones--;
                        h.insert({i+1,j});
                    }

                    if (j-1 >= 0 && a[i][j-1] == 1) {
                        a[i][j-1] = 2;
                        ones--;
                        h.insert({i,j-1});
                    }

                    if (j+1 < m && a[i][j+1] == 1) {
                        a[i][j+1] = 2;
                        ones--;
                        h.insert({i,j+1});
                    }
                }
            }
        }

        if (ones == curr) {return -1;}
        ans++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,m; 
    cin >> t;
     
    while (t--) {
        cin >> n >> m;

        int **a = new int *[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new int [m];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        
        cout << util(a,n,m) << endl;
    }
     
    return 0;
}