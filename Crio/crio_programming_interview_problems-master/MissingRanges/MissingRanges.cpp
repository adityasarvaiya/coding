#include<bits/stdc++.h>
using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<string>ans;
	if(nums.size() == 0) {
        string toPush = to_string(lower) + "->" + to_string(upper);
        if(lower == upper) {
            toPush = to_string(lower);
        }
        ans.push_back(toPush);
        return ans;
    }
	if(nums[0] > lower) {
		if(nums[0] == lower+1) {
			ans.push_back(to_string(lower));
		} else {
			string toPush = to_string(lower) + "->" + to_string(nums[0]-1);
			ans.push_back(toPush);
		}
	}
	for(int i = 0 ; i < nums.size()-1 ; i++) {
		if(nums[i] < nums[i+1] && nums[i] + 1 != nums[i+1]) {
			if(nums[i+1] == 2  + nums[i]) {
				ans.push_back(to_string(nums[i]+1));
			} else {
				string toPush = to_string(nums[i]+1) + "->" + to_string(nums[i+1]-1);
				ans.push_back(toPush);
			}
		}
	}
	if(nums[nums.size()-1] < upper) {
		if(nums[nums.size()-1] + 1 == upper) {
			ans.push_back(to_string(upper));
		} else {
			string toPush = to_string(nums[nums.size()-1] + 1) + "->" + to_string(upper);
			ans.push_back(toPush);
		}
	}
	return ans;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	int lower , upper;
	cin >> lower >> upper;
	for(int i = 0 ; i < n ; i++) {
		cin >> nums[i];
	}

	vector<string>answer = findMissingRanges(nums,lower,upper);
	for(int i = 0 ; i < answer.size() ; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}
