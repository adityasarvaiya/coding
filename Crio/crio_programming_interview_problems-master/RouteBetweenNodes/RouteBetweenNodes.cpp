#include <bits/stdc++.h>
using namespace std;

bool RouteBetweenNodes(int startNode,int toReach,int numberofnodes, vector<vector<int> > edgelist)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<vector<int > > graph(numberofnodes+1);
    for(auto edge:edgelist)
    {
        graph[edge[0]].push_back(edge[1]);
    }
    queue<int > que;
    que.push(startNode);
    vector<bool> visited(graph.size(),false);
    while(!que.empty())
    {
        int ele = que.front();
        for(auto child:graph[ele])
        {
            if(!visited[child])
            {
                visited[child]=true;
                que.push(child);
                if(child==toReach)
                    return true;
            }
        }
        que.pop();
    }
    return false;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int numberofnodes,edges;
        cin>>numberofnodes>>edges;
        int vertex1,vertex2;
        vector<vector<int > > edgelist;
        for(int i=0;i<edges;i++)
        {
            cin>>vertex1>>vertex2;
            vector<int > temp = {vertex1,vertex2};
            edgelist.push_back(temp);
        }
        int start,end;
        cin>>start>>end;
        bool result = RouteBetweenNodes(start,end,numberofnodes,edgelist);
        cout<<((result)?"yes":"no")<<"\n";
    }
    return 0;
}
