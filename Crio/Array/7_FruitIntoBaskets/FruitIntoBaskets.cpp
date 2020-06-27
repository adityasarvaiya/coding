#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& tree) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	map<int,int>m;
	int low = 0 , high = 0,ans = 0;
	while(high < tree.size()) {
		if(m.size() > 2) {
			m[tree[low]]--;
			if(m[tree[low]] == 0) {
				m.erase(tree[low]);
			}
			low++;
			continue;
		}
		m[tree[high]]++;
		if(m.size() <= 2) {
			ans = max(ans,high-low+1);
			high++;
		} else {
			m[tree[low]]--;
			if(m[tree[low]] == 0) {
				m.erase(tree[low]);
			}
			low++;
			high++;
		}
	}	
	return ans;
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	int n;
	cin >> n;
	vector<int>tree(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> tree[i];
	}
	int answer = totalFruit(tree);
	cout << answer;
	return 0;
}
