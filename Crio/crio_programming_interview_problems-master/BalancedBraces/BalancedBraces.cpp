#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<string> balanced;
void findAllBalancedBraces(int n,int to_be_closed,string s)
{
	if(n==0)
	{
		for(int i=0;i<to_be_closed;i++)
			s+=')';
		balanced.push_back(s);
		return ;
	}
	findAllBalancedBraces(n-1,to_be_closed+1,s+"(");
	if(to_be_closed>0)
	{
		findAllBalancedBraces(n,to_be_closed-1,s+")");
	}
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<string> balancedBraces(int n)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	findAllBalancedBraces(n,0,"");	
	return balanced;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int n;
	cin>>n;
	vector<string> ans=balancedBraces(n);
	for(auto i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
}
