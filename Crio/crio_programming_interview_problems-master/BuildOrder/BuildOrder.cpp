#include<bits/stdc++.h>
using namespace std;
vector<string> buildOrder(vector<string>& project, vector<vector<string>>& depend){
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int n = project.size();
    map<string,int>hash;
    map<int,string>hashrev;
    int c = 1;
    for (auto &&name : project)
    {
        hashrev[c] = name;
        hash[name] = c++;
    }
    vector<int>inD(n+1);
    vector<vector<int>>adj(n+1);
    for (auto &&edge : depend)
    {
        inD[hash[edge[1]]]++;
        adj[hash[edge[0]]].push_back(hash[edge[1]]);
    }
    queue<int>q;
    vector<string>ans;
    for (int i = 1; i <= n; i++)
    {
        if(inD[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int p = q.front();
        q.pop();
        ans.push_back(hashrev[p]);
        for (auto &&child : adj[p])
        {
            inD[child]--;
            if(inD[child]==0){
                q.push(child);
            }
        }
    }
    if(ans.size()!=n){
        ans.clear();
        ans.push_back("-1");
    }
    return ans;
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main(){

    int n,d;
    cin>>n>>d;
    vector<string>project(n);
    vector<vector<string>>depend(d);
    for (int i = 0; i < n; i++)
    {
        cin>>project[i];
    }

    for (int i = 0; i < d; i++)
    {
        string u,v;
        cin>>u>>v;
        depend[i].push_back(u);
        depend[i].push_back(v);
    }
    vector<string> ans = buildOrder(project,depend);
    for (auto p : ans)
    {
        cout<<p<<" ";
    }
    
}
