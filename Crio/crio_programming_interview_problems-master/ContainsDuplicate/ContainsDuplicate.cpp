#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"
using namespace std;

class ContainsDuplicate {
public:
    bool containsDuplicate(vector<int>& nums) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        sort(nums.begin(),nums.end());
        for(int i=0;i<int(nums.size()-1);i++)
            if(nums[i] == nums[i+1]) return true;
        return false;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	int n;
	cin >> n;
	vector<int> nums;
	ReadMatrix<int>().OneDMatrix(n, nums);
	bool result = ContainsDuplicate().containsDuplicate(nums);
	cout << boolalpha << result;
	return 0;
}
