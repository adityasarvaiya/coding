#include <bits/stdc++.h>
#define ll long long
using namespace std;


// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
bool comp(const vector<int> &a,const vector<int> &b){
    return a[2]<b[2];
}
int getParent(int x, vector<int> &parent)
{
    if(parent[x]==x)return x;

    return parent[x]=getParent(parent[x],parent);
}

void setUnion(int a, int b, vector<int> &parent, vector<int> &size)
{
    a = getParent(a, parent);
    b = getParent(b, parent);

    if (size[a] > size[b])
    {
        swap(a, b);
    }

    parent[b] = a;
    size[a] += size[b];
    return;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int minCostOfRoad(int n, vector<vector<int> > &edges)
{
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    sort(edges.begin(), edges.end(),comp);
    vector<int> size(n, 0);

    ll cost = 0;

    vector<int> parent(n+1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (auto edge : edges)
    {
        int p1 = getParent(edge[0], parent);
        int p2 = getParent(edge[1], parent);

        if (p1 == p2)
        {
            continue;
        }
        cost += edge[2];
        setUnion(p1, p2, parent, size);
    }

    return cost;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
    int n,m;
    cin >> n>>m;

    vector<vector<int> > edges;

    for (int i = 0; i < m; i++)
    {   int u,v,w;cin>>u>>v>>w;
        vector<int> b(3,0);
        b[0]=u;
        b[1]=v;
        b[2]=w;
        edges.push_back(b);
    }

    int ans = minCostOfRoad(n, edges);

    cout << ans << endl;
}
