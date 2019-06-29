vector<bool> isprime(n+1,true);
vector<int> ans;
isprime[0]=false;
isprime[1]=false;
for(int p=2;p*p<=n;p++)
{
    if(isprime[p])
    {
        for(int i=p*2;i<=n;i=i+p)
        {
            isprime[i]=false;
        }
    }
}
for(int i=2;i<=n;i++)
{
    if(isprime[i])
    ans.push_back(i);
}
return ans;