#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int input[1001][1001],visited[1001][1001],n,m;
vector<pair<int,int> > vec;
int dfs(int r,int c)
{
    if(r==n && c==m)
    {
        if(input[r][c]==0)
        {    
            vec.push_back(make_pair(r,c));
            return 1;
        }
    }
    if(r>n || c>m || r<1 || c<1 || input[r][c]==1)
        return 0;
    if(visited[r][c]==0)
    {
        visited[r][c]=1;
        int val=dfs(r+1,c);
        if(val==1)
        {
            vec.push_back(make_pair(r,c));
            return val;
        }
        int val1=dfs(r,c+1);
        if(val1==1)
        {
            vec.push_back(make_pair(r,c));
            return val1;
        }
    }
    if(visited[r][c]==1)
        return 0;
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<string> robotInAGrid(vector< vector<int > > vec1 , int a , int b)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<string> answer;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            input[i+1][j+1]=vec1[i][j];
        }
    }
    n=a;
    m=b;
    dfs(1,1);
    if(vec.size()==0)
        answer.push_back("Not Possible");
    else
    {
        for(int i=vec.size()-1;i>=0;i--)
        {
            answer.push_back(to_string(vec[i].first)+" "+to_string(vec[i].second));
        }
    }
    return answer;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    int a,b;
    cin>>a>>b;
    vector<vector<int> > input1(a,vector<int> (b));
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>input1[i][j];
        }
    }
    vector<string> ans = robotInAGrid(input1 ,a , b);
    for(string elem : ans)
    {
        cout<<elem<<"\n";
    }
}

