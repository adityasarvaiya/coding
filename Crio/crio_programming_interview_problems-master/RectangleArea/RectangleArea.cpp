#include<bits/stdc++.h>
using namespace std;
uint64_t rectangleArea(int n,vector<vector<int> > rectangles)
{
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	uint64_t sum = 0;
	uint64_t mod = 1000000000+7;
	multiset< pair < uint64_t, pair < uint64_t, uint64_t > > > s;
	multiset< pair < uint64_t, uint64_t > , greater < pair< uint64_t , uint64_t > > > maxs;
	multiset< pair < uint64_t, uint64_t > > mins;	
	sort(rectangles.begin(),rectangles.end());
	uint64_t curr = 0,prev = 0;
	for(int i=0;i<n;)
	{
		prev = curr;
		if(!s.empty())
		{
			curr = min((uint64_t)rectangles[i][0],s.begin()->first);
			sum = ((sum%mod)+(((curr-prev)%mod)*((maxs.begin()->first-mins.begin()->first)%mod))%mod)%mod;
		}
		else
			curr = (uint64_t)rectangles[i][0];
		if(curr == (uint64_t)rectangles[i][0])
		{	
			s.insert(make_pair((uint64_t)rectangles[i][2],make_pair((uint64_t)rectangles[i][1],(uint64_t)rectangles[i][3])));
			maxs.insert(make_pair((uint64_t)rectangles[i][3],(uint64_t)rectangles[i][2]));
			mins.insert(make_pair((uint64_t)rectangles[i][1],(uint64_t)rectangles[i][2]));
			i++;
		}
		else
		{
			auto it=maxs.find(make_pair(s.begin()->second.second,curr));
			auto pt=mins.find(make_pair(s.begin()->second.first,curr));
			s.erase(s.begin());
			maxs.erase(it);
			mins.erase(pt);
		}
	}
	while(!s.empty())
	{
		prev = curr;
		curr = s.begin()->first;
		sum = ((sum%mod)+(((curr-prev)%mod)*((maxs.begin()->first-mins.begin()->first)%mod))%mod)%mod;	
		auto it=maxs.find(make_pair(s.begin()->second.second,curr));
		auto pt=mins.find(make_pair(s.begin()->second.first,curr));
		s.erase(s.begin());
		maxs.erase(it);
		mins.erase(pt);
	}
	return sum;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int> > rectangles(n,vector<int>(4));
	for(int i=0;i<n;i++)
	{
		cin>>rectangles[i][0]>>rectangles[i][1]>>rectangles[i][2]>>rectangles[i][3];
	}
	cout<<rectangleArea(n,rectangles);
}
