#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"

using namespace std;

class SingleNumber {
public:
    int singleNumber(vector<int>& nums) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; i++)
        	x ^= nums[i];
        return x;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	int n;
	cin >> n;
	vector<int> nums;
	ReadMatrix<int>().OneDMatrix(n, nums);
	int result = SingleNumber().singleNumber(nums);
	cout << result;
	return 0;
}
