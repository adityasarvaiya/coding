#include<bits/stdc++.h>
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
bool cmp( pair<int, int> &a , pair<int, int> &b) {
	if ( a.second == b.second)
		return a.first > b.first;
	if ( a.first == b.first)
		return a.second > b.second;
	return a.first >= b.first;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int circusTower( int n, vector<pair<int, int>> &v) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	sort(v.begin(), v.end());
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				dp[j] = max( dp[j], dp[i] + 1);
			}
		}
	}
	int mx = 1;
	for (int i = 0; i < n; i++) {
		mx = max(dp[i], mx);
	}
	return mx;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

}
int main() {

	int n;
	cin >> n;
	vector<pair<int, int> > v(n);
	for ( int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	cout << circusTower(n, v) << endl;

}