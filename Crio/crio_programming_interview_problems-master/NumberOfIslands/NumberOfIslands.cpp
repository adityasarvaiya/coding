#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class NumberOfIslands {
  public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    void dfs(vector<string>& grid, int i, int j, int n, int m,
             vector<bool> vis[]) {
        if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '0' ||
            vis[i][j])
            return;
        if (grid[i][j] == '1') {
            vis[i][j] = true;
            dfs(grid, i + 1, j, n, m, vis);
            dfs(grid, i - 1, j, n, m, vis);
            dfs(grid, i, j + 1, n, m, vis);
            dfs(grid, i, j - 1, n, m, vis);
        }
        return;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    int numIslands(vector<string>& grid) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int x = 0;
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        vector<bool> vis[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i].push_back(false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '0' && !vis[i][j]) {
                    x++;
                    dfs(grid, i, j, n, m, vis);
                }
            }
        }
        return x;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid;
    ReadMatrix<string>().OneDMatrix(n, grid);
    int result = NumberOfIslands().numIslands(grid);
    cout << result;
    return 0;
}
