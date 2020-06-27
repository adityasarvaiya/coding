#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<int> convertToBinary(long long n)
{
    long long flag=0,r,num=n;
    vector<int> vec;
    while(num!=0)
    {
        r=num%2;
        num/=2;
        vec.push_back(r);
    }
    return vec;
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
string nextGreater(vector<int> vec)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vec.push_back(0);
    long long flag=0,ans=0;
    for(long long i=0;i<vec.size();i++)
    {
        if(vec[i]==1)
            flag=1;
        if(vec[i]==0 && flag==1)
        {
            vec[i]=1;
            vec[i-1]=0;
            break;
        }
    }
    if(vec[vec.size()-1]==1)
    {
        long long val=0;
        for(long long i=0;i<vec.size();i++)
        {
            if(vec[i]==1)
                val++;
        }
        ans+= (1ll<<(vec.size()-1));
        for(long long i=0;i<val-1;i++)
            ans+= (1ll<<i);
    }
    else
    {
        for(long long i=0;i<vec.size();i++)
        {
            if(vec[i]==1)
                ans+= (1ll<<i);
        }
    }
    string gans=to_string(ans);
    return gans;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
string nextSmaller(vector<int> vec)
{
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long long flag=0,ans=0,temp;
    for(long long i=0;i<vec.size();i++)
    {
        if(vec[i]==0)
            flag=1;
        if(vec[i]==1 && flag==1)
        {
            vec[i]=0;
            vec[i-1]=1;
            temp=i-1;
            break;
        }
    }
    if(flag==0)
        return "No Number";
    else
    {
        long long oneval=0;
        for(long long i=temp-1;i>=0;i--)
        {
            if(vec[i]==1)
                oneval++;
        }
        for(long long i=temp-1;i>=0;i--)
        {
            if(oneval>0)
            {
                 vec[i]=1;
                 oneval--;
            }
            else
                vec[i]=0;
        }
        for(long long i=0;i<vec.size();i++)
        {
            if(vec[i]==1)
                ans+= (1ll<<i);
        }
        string sans=to_string(ans);
        return sans;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    long long n;
    cin>>n;
    vector<int> vec = convertToBinary(n);
    string great=nextGreater(vec);
    string small=nextSmaller(vec);
    cout<<great<<"\n";
    cout<<small<<"\n";
}
