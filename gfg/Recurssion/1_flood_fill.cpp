#include <bits/stdc++.h>
using namespace std;

void fill(int n, int m, vector <vector<int>> &A, int x, int y, int k, int old)
{
    int i,j;
    
    if (x < 0 || x > n-1 || y < 0 || y > m-1) {return;}
    if (A[x][y] != old) {return ;}

    A[x][y] = k;

    fill(n,m,A,x-1,y,k,old);
    fill(n,m,A,x,y-1,k,old);
    fill(n,m,A,x+1,y,k,old);
    fill(n,m,A,x,y+1,k,old);
}

void print(int n, int m, vector <vector<int>> A) 
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << " ";
        }
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int t,n,m,i,j,x,y,k,tmp; 
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        vector <vector <int>> A;

        for (i = 0; i < n; ++i) {
            vector <int> vec;
            for (j = 0; j < m; ++j) {
                cin >> tmp;
                vec.push_back(tmp);
            }
            A.push_back(vec);
        }

        cin >> x >> y >> k;

        fill(n,m,A,x,y,k, A[x][y]);

        print(n,m,A);
    }
     
    return 0;
}