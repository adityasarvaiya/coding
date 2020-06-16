#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(int n, vector<vector<int>>& times, int K){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int nodes = n;
    int source = K;
    vector<vector<int>>& edges=times;
    vector<vector<pair<int,int>>>adj(nodes+1);
    for (auto &&edge : edges)
    {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    vector<int>dist(nodes+1,INT_MAX);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for (auto &&edge : adj[source])
    {
        int time = edge.second;
        int child = edge.first;
        dist[child] = time;
        q.push({time,child});
    }
    while (!q.empty())
    {
        pair<int,int> x = q.top();
        q.pop();
        int time = x.first;
        int node = x.second;
        for (auto &&edge : adj[node])
        {
            int child = edge.first;
            int d = edge.second;
            if(dist[child]>d+time){
                dist[child] = d+time;
                q.push({dist[child],child});
            }
        }
    }
    int ans = *max_element(1+dist.begin(),dist.end());
    if(ans == INT_MAX) ans=-1;
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main(){

    int nodes, source, e;
    cin>>nodes>>e;
    vector<vector<int>>edges(e);
    for (int i = 0; i < e; i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(t);
    }
    cin>>source;
    int ans = networkDelayTime(nodes,edges,source);
    cout<<ans;
}
