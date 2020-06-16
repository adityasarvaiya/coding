#include <bits/stdc++.h>
using namespace std;

long long CircularRace(long long n,vector<long long > gas, vector<long long > burn)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long long sum1 = accumulate(gas.begin(),gas.end(),0);
    long long burn1 = accumulate(burn.begin(),burn.end(),0);
    if(sum1 <  burn1)
        return -1;
    vector<long long > res(n);
    for(int i=0;i<n;i++)
        res[i] = gas[i] - burn[i];
    long long current = 0,pos = 0 ; 
    for(int i=0;i<n;i++)
    {
        current +=res[i];
        if(current<0)
        {
            pos = i+1;
            current =0 ;
        }
    }
    return pos+1;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}


int main()
{
    int n;
    cin>>n;
    vector<long long > gas(n),burn(n);
    for(int i=0;i<n;i++)
        cin>>gas[i];
    for(int i=0;i<n;i++)
        cin>>burn[i];
    int result = CircularRace(n, gas,  burn); 
    cout<<result<<"\n";
    return 0;
}
