#include<bits/stdc++.h>
using namespace std;
int candyToKids(int n, vector<int>&goodness) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int candy = 0;
	vector<pair<int, int> > candies(n);
	vector<int> actualCandies(n, 1);
	for (int i = 0; i < n; i++) {
		candies[i].first = goodness[i];
		candies[i].second = i;
	}
	sort(candies.begin(), candies.end());
	for ( int i = 0; i < n; i++) {
		pair<int, int> P = candies[i];
		if (P.second > 0 && goodness[P.second - 1] > goodness[P.second]) {
			actualCandies[P.second - 1]  = max( actualCandies[P.second - 1], actualCandies[P.second] + 1);
		}
		if ( P.second < n - 1 && goodness[P.second + 1] > goodness[P.second]) {
			actualCandies[P.second + 1] = max( actualCandies[P.second + 1] , actualCandies[P.second] + 1);
		}
	}
	for ( int i = 0; i < n; i++) {
		candy += actualCandies[i];
	}
	return candy;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main() {
	int n, m;
	cin >> n;
	vector<int> goodness(n);
	for (int i = 0; i < n; i++) cin >> goodness[i];
	int ans = candyToKids(n, goodness);
	cout << ans << endl;
}
