#include <bits/stdc++.h>
#include "FastIO.hpp"

using namespace std;

class FactorialTrailingZeroes {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        for(long int i = 5; i <= n; i*=5) {
            ans += n/i;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return ans;
    }
};

int main() {
	FastIO();
	int n;
	cin >> n;
	int result = FactorialTrailingZeroes().trailingZeroes(n);
	cout << result;
	return 0;
}
