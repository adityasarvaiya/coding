#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include "PrintMatrix.hpp"

using namespace std;

class PlusOne {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = digits.size();
        int carry = 1;
        for(int i = n - 1; i >= 0; i--) {
            int res = digits[i] + carry;
            v.push_back(res%10);
            carry = res/10;
        }
        if(carry) v.push_back(carry);
        reverse(v.begin(), v.end());
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return v;
    }
};

int main() {
	FastIO();
	string s;
	getline(cin, s);
	vector<int> digits;
	for(auto x : s) {
		if(x == ' ')
			continue;
		digits.push_back(x - '0');
	}
	vector<int> result = PlusOne().plusOne(digits);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
