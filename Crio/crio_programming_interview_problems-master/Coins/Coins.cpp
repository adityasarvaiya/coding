#include<bits/stdc++.h>
using namespace std;

//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
long long ways[1000000+9],mod=1e9+7,s[]={1,5,10,25};
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

long long countWays(long long n )
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	ways[0]=1;
	for(long long i=0; i<4; i++)
		for(long long j=s[i]; j<=n; j++)
			ways[j]=((ways[j]%mod)+(ways[j-s[i]]%mod))%mod;

	return ways[n];
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
    long long n;
    cin>>n;
    cout<<countWays(n)%mod<<"\n";
}
