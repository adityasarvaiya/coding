#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
long long n;
pair<long long,pair<long long,long long> > ar[1009];

bool compare(pair<long long ,pair<long long ,long long > > &i, pair<long long,pair<long long,long long > > &j)
{
    if(i.first>j.first)
        return true;
    else if(i.first==j.first)
    {
        if(i.second.first>j.second.first)
            return true;
        else if(i.second.first==j.second.first)
        {
            if(i.second.second>j.second.second)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;

}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
long long stackTheBoxes(int length[],int breadth[],int height[],int m)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    for(int i=0;i<m;i++)
    {
        pair<long long,pair<long long,long long> > p;
        p.first=length[i];
        (p.second).first=breadth[i];
        (p.second).second=height[i];
        ar[i+1]=p;
    }
    n=m;
    sort(ar+1,ar+1+n,compare);
    long long i,j,ans=0;
    vector<long long> dp(n+9, 0);
    //long long dp[n+9]={0};
    for(i=1;i<=n;i++)
        dp[i]=ar[i].second.second;
    for(i=n;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
        {
            if( (ar[j].first < ar[i].first) && ar[j].second.first < ar[i].second.first && ar[j].second.second < ar[i].second.second )
                dp[i]=max(dp[i],dp[j]+ar[i].second.second);
        }
    }
    for(i=1;i<=n;i++)
    {
        ans=max(dp[i],ans);
    }
    return ans;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    int m;
    cin>>m;
    int length[m],breadth[m],height[m];
    for(long long i=0;i<m;i++)
    {
        cin>>length[i]>>breadth[i]>>height[i];
    }
    cout<<stackTheBoxes(length,breadth,height,m)<<"\n";
}
