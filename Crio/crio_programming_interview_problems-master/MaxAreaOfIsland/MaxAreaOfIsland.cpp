#include <bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
bool vis[500][500];
int n,m;
int dfs(vector<vector<int>>& grid, int i, int j){
    int ans = 1;
    vis[i][j]=1;
    if(i-1>=0){
        if(grid[i-1][j]==1 && !vis[i-1][j]){
            ans+=dfs(grid, i-1, j);
        }
    }
    if(i+1<n){
        if(grid[i+1][j]==1 && !vis[i+1][j]){
            ans+=dfs(grid, i+1, j);
        }
    }
    if(j-1>=0){
        if(grid[i][j-1]==1 && !vis[i][j-1]){
            ans+=dfs(grid, i, j-1);
        }
    }
    if(j+1<m){
        if(grid[i][j+1]==1 && !vis[i][j+1]){
            ans+=dfs(grid, i, j+1);
        }
    }
    return ans;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


int maxAreaOfIsland(vector<vector<int>> grid){

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = grid.size();
    m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j]==1){
                ans = max(ans, dfs(grid, i, j));
            }
        }
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }
    int ans = maxAreaOfIsland(grid);
    cout<<ans;
}
