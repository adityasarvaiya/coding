#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalOrdering(int n,int e, vector<vector<int>>& edges){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<int>in(n+1);
    vector<vector<int>>adj(n+1);
    for (auto &&edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        in[edge[1]]++;
    }
    queue<int>q;
    vector<int>ans;
    for (int node = 1; node <= n; node++)
    {
        if(in[node]==0){
            q.push(node);            
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto &&child : adj[node])
        {
            in[child]--;
            if(in[child]==0){
                q.push(child);
            }
        }  
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main(){
    
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges(e);
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    vector<int>ans = topologicalOrdering(n,e,edges);
    for (auto &&i : ans)
    {
        cout<<i<<" ";
    }
    
}
