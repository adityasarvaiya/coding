#include<bits/stdc++.h>
using namespace std;


bool isUnique(string s) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int count[300];
	memset(count , 0 , sizeof count);
	for(int i = 0 ; i < s.size() ; i++) {
		if(count[s[i]] >= 1) {
			return false;
		}
		count[s[i]]++;
	}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	return true;
}

int main() {
	string s;
	cin >> s;
	bool answer = isUnique(s);
	if(answer) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}
