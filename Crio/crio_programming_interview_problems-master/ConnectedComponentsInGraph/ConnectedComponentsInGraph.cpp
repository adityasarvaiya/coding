#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<bool>vis;
void dfs(int node, vector<vector<int>>& graph){
    vis[node]=true;
    for (auto &&child : graph[node])
    {
        if(!vis[child]){
            dfs(child, graph);
        }
    }
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int connectedComponentsInGraph(int nodes, vector<vector<int>>& edgelist){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<vector<int>>graph(nodes+1);
    for (auto edge: edgelist)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vis.resize(nodes+1);
    int ans = 0;
    for (int i = 1; i <= nodes; i++)
    {
        if(!vis[i]){
            ans++;
            dfs(i,graph);
        }
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main(){

    int nodes, edges;
    cin>>nodes>>edges;
    int vertex1,vertex2;
    vector<vector<int > > edgelist;
    for(int i=0;i<edges;i++)
    {
        cin>>vertex1>>vertex2;
        vector<int > temp = {vertex1,vertex2};
        edgelist.push_back(temp);
    }
    int ans = connectedComponentsInGraph(nodes, edgelist);
    cout<<ans;
    
}
