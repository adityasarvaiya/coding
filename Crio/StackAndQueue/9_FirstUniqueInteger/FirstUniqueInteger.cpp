#include<bits/stdc++.h>
using namespace std;
int firstUniqueInteger(vector<int> &v) {
	//CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int n = v.size();
	queue<int> Q;
	map<int, int > M;
	for ( int i = 0; i < n; i++) {
		if (M.find(v[i]) == M.end()) {
			Q.push(v[i]);
		}
		M[v[i]]++;
	}
	while (!Q.empty()) {
		int number = Q.front();
		Q.pop();
		if (M[number] == 1) {
			return number;
		}
	}
	return -1;
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
int main() {
	int n, m;
	cin >> n;
	vector<int> v(n);
	for ( int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = firstUniqueInteger(v);
	cout << ans << endl;
}