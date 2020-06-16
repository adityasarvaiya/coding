#include <bits/stdc++.h>
using namespace std;

class MajorityElement {
public:
	int majorityElement(vector<int>& nums) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		map<int, int> M;
		int n = nums.size();
		for ( int i = 0; i < n; i++) M[nums[i]]++;
		int mx = 0, my = 0;
		for ( auto it : M) {
			if (it.second > mx)
				my = it.first , mx = max( it.second, mx);
		}
		if (mx > n / 2)
			return my;
		else
			return -1;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
};

int main() {

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	int result = MajorityElement().majorityElement(nums);
	cout << result;
	return 0;
}

