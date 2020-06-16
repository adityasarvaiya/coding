#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
bool isSafe(int i, int j , int n, int m , vector<vector<int> > &visited) {
    if (i >= 0 && j >= 0 && i < n && j < m && visited[i][j] == 0) {
        return true;
    }
    return false;
}

// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
int rottingOranges(vector<vector<int>>& grid) {

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n = grid.size();
    if (n == 0) return -1;
    int m = grid[0].size();
    if (m == 0) return -1;
    vector<vector<int> >visited(n, vector<int>(m));

    queue<pair<int, pair<int, int> > > Q;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                visited[i][j] = 1;
                Q.push({0, {i, j}});
            }
            if (grid[i][j] == 1) cnt++;
        }
    }
    if (cnt == 0) {
        return 0;
    }

    if (Q.empty()) return -1;
    vector<int> bx(4), by(4);
    bx[0] = 1; bx[1] = 0;  bx[2] = 0;  bx[3] = -1;
    by[0] = 0; by[1] = 1;  by[2] = -1;  by[3] = 0;

    int ans = 0;
    while (!Q.empty()) {
        pair<int, pair<int, int> > P = Q.front(); Q.pop();

        for ( int i = 0; i < 4; i++) {
            int x = P.second.first + bx[i];
            int y = P.second.second + by[i];
            int d = P.first;
            if (isSafe(x, y, n, m, visited) && grid[x][y] == 1) {
                Q.push({d + 1, {x, y}});
                ans = max( d + 1, ans);
                visited[x][y] = 1;
                cnt--;
            }
        }
    }
    if (cnt == 0)
        return ans;
    return -1;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main() {
    int n, m, t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << rottingOranges(grid) << endl;
    }
}
