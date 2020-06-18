#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class CountPrimes {
public:
    int countPrimes(int n) {
        int ans = 0;
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        for(int i = 2; i < n; i++) {
            bool flag=true;
            for(int j = 2; j*j <= i; j++) {
                if(i % j == 0) {
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return ans;
    }
};

int main() {
	FastIO();
	int n;
	cin >> n;
	int result = CountPrimes().countPrimes(n);
	cout << result;
	return 0;
}
