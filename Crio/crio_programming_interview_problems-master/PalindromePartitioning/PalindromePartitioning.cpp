#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
string t;
int tsize;
vector<vector<string> > answer;
vector<string> vec;
void rec(int i,int j)
{
	int flag=0;
	if(j==tsize-1)
	{
		for(int k=i;k<=(i+j-1)/2;k++)
		{
			if(t[k]!=t[j-(k-i)])
			{	
				flag=1;
				break;
			}
		}
		if(flag==1)
			return ;
		vec.push_back(t.substr(i,j-i+1));
		answer.push_back(vec);
		vec.pop_back();
		return ;
	}
	rec(i,j+1);
	for(int k=i;k<=(i+j-1)/2;k++)
	{
		if(t[k]!=t[j-(k-i)])
		{	
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		vec.push_back(t.substr(i,j-i+1));
		rec(j+1,j+1);
		vec.pop_back();
	}
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<vector<string> > palindromePartitioning(string s)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	if(s=="")
		return answer;
	t=s;
	tsize=t.size();
	rec(0,0);
	return answer;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	string s;
	cin>>s;
	vector<vector<string> > ans=palindromePartitioning(s);
	for(auto it=0;it<ans.size();it++)
	{
		for(auto pt=0;pt<ans[it].size();pt++)
		{
			cout<<ans[it][pt]<<" ";
		}
		cout<<"\n";
	}
}
