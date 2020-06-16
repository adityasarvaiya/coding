#include <bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int getParent(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent[x], parent);
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

bool comp(const vector<int> &a,const vector<int> &b){
    return a[2]<b[2];
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int cobbledStreets(int n, int p, vector<vector<int> > &edges)
{
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    sort(edges.begin(), edges.end(),comp);
    vector<int> size(n, 0);

    long long cost = 0;

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
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

    return cost * p;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int p, n, m;
        cin >> p >> n >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u,v,w});
        }

        int ans = cobbledStreets(n, p, edges);
        cout << ans << endl;
    }
}
 
