#include <bits/stdc++.h> 
using namespace std; 
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
vector<string> movement;
void steps(int n, char from_rod,char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		string s=to_string(n)+" "+from_rod+" "+to_rod;
		movement.push_back(s);
		return; 
	} 
	steps(n - 1, from_rod, aux_rod, to_rod); 
	string s=to_string(n)+" "+from_rod+" "+to_rod;
	movement.push_back(s); 
	steps(n - 1, aux_rod, to_rod, from_rod); 
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEM
vector<string> towerOfHanoi(int n)
{
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	steps(n,'A','C','B');
	return movement;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEM
} 

int main() 
{ 
	int n;
	cin>>n;
	vector<string> ans=towerOfHanoi(n);
	for(auto i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\n";
	}
} 

