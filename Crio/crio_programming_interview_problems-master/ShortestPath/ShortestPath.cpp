#include<bits/stdc++.h>
using namespace std;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<vector<int> > createAdjList(int n,vector<vector<int > > edges)
{
	vector<vector<int> > adjList(n+1);
	for(int i=0;i<edges.size();i++)
	{
		adjList[edges[i][0]].push_back(edges[i][1]);
		adjList[edges[i][1]].push_back(edges[i][0]);
	}
	return adjList;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<int> shortestPath(int n,vector<vector<int> > edges, int source, int destination)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vector<vector<int> > vec= createAdjList(n,edges);
	int level[n+1]={0};
	queue<int> q;
	level[source]=1;
	q.push(source);
	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(int i=0;i<vec[front].size();i++)
		{
			if(level[vec[front][i]]==0)
			{
				level[vec[front][i]]=level[front]+1;
				q.push(vec[front][i]);
			}
		}
	}
	int curnode=destination;
	vector<int> answer;
	for(int i=1;i<=level[destination];i++)
	{
		answer.push_back(curnode);
		for(auto it=vec[curnode].begin();it!=vec[curnode].end();it++)
		{
			if(level[*it]==level[curnode]-1)
			{
				curnode=*it;
				break;
			}
		}
	}
	reverse(answer.begin(),answer.end());
	return answer;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{

	int n,m;
	cin>>n>>m;
	vector<vector<int> > edges(m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		edges[i].push_back(x);
		edges[i].push_back(y);
	}
	int source,destination;
	cin>>source>>destination;
	vector<int> ans = shortestPath(n,edges,source,destination);
	for(int node: ans)
	{
		cout<<node<<"\n";
	}
}
