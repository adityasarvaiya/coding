#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
map <string,int> mp;
void permute(string a, int l, int r)
{
	if (l == r)
    {
        if(mp[a]!=1)
        {
            mp[a]=1;
        }
    }
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permute(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<string> permutationWIthDups(string s)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vector<string> ans;
    permute(s,0,s.length()-1);
    for(auto it=mp.begin();it!=mp.end();it++)
    	ans.push_back(it->first);
    return ans;
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	string str;
	cin>>str;
	vector<string> answer=permutationWIthDups(str);
	for(auto it=answer.begin();it!=answer.end();it++)
		cout<<*it<<"\n";
}
