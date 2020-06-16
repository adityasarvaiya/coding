#include <bits/stdc++.h>
using namespace std;


vector<int > TownsAndPoliceStations(int n, vector<vector<int > > edgelist, vector<int > sources )
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	
    vector<vector<int > > graph(n+1);
    for(auto edge: edgelist)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    queue<int > q;
    vector<int > dist(n+1,1e8);
    vector<bool> visited(n+1,false);
    for(int i=0;i<sources.size();i++)
    {
        q.push(sources[i]);
        visited[sources[i]]=true;
        dist[sources[i]]=0;
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto neighbour:graph[node])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
                dist[neighbour] = dist[node] + 1;
            }
        }
    }
    dist.erase(dist.begin());
    return dist;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int numberOfNodes,edges;
    cin>>numberOfNodes>>edges;
    int vertex1,vertex2;
    vector<vector<int > > edgelist;
    for(int i=0;i<edges;i++)
    {
        cin>>vertex1>>vertex2;
        vector<int > temp = {vertex1,vertex2};
        edgelist.push_back(temp);
    }
    int sourceCount;
    cin>>sourceCount;
    vector<int > sources(sourceCount);
    for(int i=0;i<sourceCount;i++)
        cin>>sources[i];
    vector<int > answer = TownsAndPoliceStations(numberOfNodes, edgelist ,sources);
    for(auto i:answer)
        cout<<i<<"\n";
    return 0;
}
