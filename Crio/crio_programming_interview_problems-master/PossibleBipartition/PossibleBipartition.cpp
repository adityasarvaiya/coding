#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int dfs( int x, vector<vector<int>> &v, map<int, int>&color, map<int, int>&visited) {
    for ( auto it : v[x]) {
        if ( visited.find(it) == visited.end()) {
            visited[it] = 1;
            color[it] = !color[x];
            if (!dfs(it, v, color, visited))
                return 0;
        }
        else if ( color[it] == color[x])
            return 0;
    }
    return 1;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
string possibleBipartition(int N, vector<vector<int>>& edges) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<vector<int > > v;
    map<int, int> color, visited;
    v.resize(N + 10);
    int n = edges.size();
    for ( int i = 0; i < n; i++) {
        int first = edges[i][0];
        int second = edges[i][1];
        v[first].push_back(second);
        v[second].push_back(first);
    }
    for ( int i = 1; i <= N; i++) {
        if (visited.find(i) != visited.end()) continue;
        int ans = dfs(i, v, color, visited );
        if (ans == 0)
            return "Not Possible";
    }
    return "Possible";
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main() {
    int n, e, tests;
    cin >> tests;
    while (tests--) {
        cin >> n >> e;

        vector< vector<int> > edges;
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            edges.push_back({x, y});
        }
        string answer =  possibleBipartition(n + 1, edges) ;
        cout << answer << endl;
    }
}
