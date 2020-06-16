#include <bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
bool isCyclic(int node ,int nodes, vector<vector<int> >& graph, vector<bool >& visited )
{
    vector<int > parent(nodes+1 , -1);
    queue<int > q;
    visited[node] = true;
    q.push(node);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(auto child:graph[cur])
        {
            if(!visited[child])
            {
                visited[child] =true;
                q.push(child);
                parent[child] = cur;
            }
            else if(parent[cur] != child)
                return true;
        }
    }
    return false;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

string detectCycle(int nodes, vector<vector<int > >& edgelist)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<vector<int > > graph(nodes+1);
    for(auto edge:edgelist)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(nodes+1 , false);
    for(int i=1;i<=nodes ; i++)
    {
        if( !visited[i] && isCyclic(i,nodes, graph,visited) )
            return "Yes";
    }
    return "No";
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int tests;
    cin>>tests;
    while (tests--)
    {
        int nodes;
        cin>>nodes;
        int edges;
        cin>>edges;
        int vertex1,vertex2;
        vector<vector<int > > edgelist;
        for(int i=0;i<edges;i++)
        {
            cin>>vertex1>>vertex2;
            vector<int > temp = {vertex1,vertex2};
            edgelist.push_back(temp);
        }
        string answer = detectCycle(nodes, edgelist);
        cout<<answer<<"\n";
    }

    return 0;
}
