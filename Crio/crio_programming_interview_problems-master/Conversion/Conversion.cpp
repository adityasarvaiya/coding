#include<bits/stdc++.h>
using namespace std;

int countConversionBits(long long a, long long b) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	long long xorr = a ^ b;
	int result = __builtin_popcountll(xorr);
	return result;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main() {
	long long a , b;
	cin >> a >> b;
	int answer = countConversionBits(a, b);
	cout << answer;
	return 0;
}
