#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> wallsAndGates(vector<vector<int>> &rooms)
{
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<int> dir = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> q;

    for (int i = 0; i < rooms.size(); i++)
    {
        for (int j = 0; j < rooms[i].size(); j++)
        {
            if (rooms[i][j] == 0)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    while (!q.empty())
    {
        int n = rooms.size();
        int m = rooms[0].size();

        pair<int, int> top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = top.first + dir[i];
            int c = top.second + dir[i + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && rooms[r][c] == INT_MAX)
            {
                rooms[r][c] = rooms[top.first][top.second] + 1;
                q.push(make_pair(r, c));
            }
        }
    }
    return rooms;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    vector<vector<int>> grid;
    int n, m;
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> b(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> b[j];
        }
        grid[i] = b;
    }
    vector<vector<int>> ans = wallsAndGates(grid);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
