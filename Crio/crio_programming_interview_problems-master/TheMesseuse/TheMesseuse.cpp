#include<bits//stdc++.h>
using namespace std;
long long theMesseuse( vector<long long> A) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int n = A.size();
	vector<long long> dp(n + 4);
	dp[0] = A[0];
	dp[1] = A[1];
	for ( int i = 2; i < n ; i++) {
		dp[i] = max( dp[i - 1] , dp[i - 2] + A[i]);
	}
	return  dp[n - 1];
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main() {

	int n;
	cin >> n;
	vector<long long> A(n);
	for ( int i = 0 ; i < n ; i++) {
		cin >> A[i];
	}
	cout << theMesseuse(A) << endl;


}