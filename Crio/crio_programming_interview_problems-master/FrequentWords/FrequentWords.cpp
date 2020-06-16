#include<bits/stdc++.h>
using namespace std;
//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
bool cmp(pair<int, string>a , pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
vector<string> frequentWords(vector<string>& words , int k) {
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int n = words.size();
	map<string, int> M;
	for ( int i = 0; i < n; i++) {
		M[words[i]]++;
	}
	vector<pair<int, string> > v;
	for ( auto it : M) {
		v.push_back({it.second, it.first});
	}
	assert(k <= v.size());
	sort( v.begin() , v.end() , cmp);
	vector<string> ans;
	for ( int i = 0; i < k; i++) {
		ans.push_back(v[i].second);
	}
	return ans;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main() {
	int n, k;
	cin >> n;
	vector<string> v(n);
	for ( int i = 0; i < n; i++) cin >> v[i];
	cin >> k;
	vector<string> ans = frequentWords(v, k);
	for ( auto it : ans) {
		cout << it << endl;
	}
}
