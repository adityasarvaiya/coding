#include <bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

int bfs(int root, int nodes , vector<vector<int > >& graph, vector<int>& diameter)
{
    queue<int > q;
    vector<bool>visited(nodes+1, false);
    for(int i=0;i<=nodes;i++)
        diameter[i]=0;
    q.push(root);
    visited[root] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto child: graph[u])
        {
            if(!visited[child])
            {
                visited[child] =  true;
                diameter[child] += diameter[u]+1;
                q.push(child);
            }
        }
    }
    auto iterator = max_element(diameter.begin(),diameter.end());
    return iterator - diameter.begin();
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int DiameterofTree(int nodes,vector<vector<int > >& edgelist)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<vector<int > > graph(nodes+1);
    for(auto edge: edgelist)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<int> diameter(nodes+1,0);
    int first = bfs(1, nodes, graph, diameter);
    int second = bfs(first , nodes, graph, diameter);
    return diameter[second];
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
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
        int result = DiameterofTree(nodes , edgelist);
        cout<< result<<"\n";
    }
    return 0;
}
