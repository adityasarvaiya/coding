#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) { 
	int i,j,n=nums.size();
	vector<int> nums_copy;
	
	for(i=0;i<n;i++) {
		nums_copy.push_back(nums[i]);
	}
	sort(nums_copy.begin(),nums_copy.end());
	for(i=0;i<n;i++) {
		if(nums_copy[i]!=nums[i])
			break;
	}
	for(j=n-1;j>=0;j--) {
		if(nums_copy[j]!=nums[j])
			break;
	}

	if(i>j)
	  return 0;
	else
	  return j-i+1;
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
