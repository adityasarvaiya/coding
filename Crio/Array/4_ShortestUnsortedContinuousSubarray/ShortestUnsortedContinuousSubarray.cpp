#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) { 
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vector<int>temp(nums);
	sort(temp.begin(), temp.end());
	int start = -1 , last = -1;
	for(int i = 0 ; i < nums.size() ; i++) {
		if(temp[i] != nums[i]) {
			start = i;
			break;
		}
	}
	for(int i = nums.size()-1 ; i >= 0 ; i--) {
		if(temp[i] != nums[i]) {
			last = i;
			break;
		}
	}
	if(start == -1 && last == -1)
		return 0;
	return (last-start+1);
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int n;
	cin >> n;
	vector<int>nums(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> nums[i];
	}
	int answer = findUnsortedSubarray(nums);
	cout << answer << "\n";
	return 0;	
}
