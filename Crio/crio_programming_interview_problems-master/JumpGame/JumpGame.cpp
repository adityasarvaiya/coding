#include<bits/stdc++.h>
using namespace std;
string jumpGame(vector<int> nums)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int lastPos = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i + nums[i] >= lastPos)
        {
            lastPos = i;
        }
    }
    if(lastPos == 0)
    	return "true";
    else
    	return "false";
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i=0;i<n;i++)
		cin>>ar[i];
	cout<<jumpGame(ar);
}
