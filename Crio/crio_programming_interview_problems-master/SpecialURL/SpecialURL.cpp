#include<bits/stdc++.h>
using namespace std;

void replace(string &s) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	string ans = "";
	for(int i = 0 ; i < s.size() ; i++) {
		if(s[i] == ' ') {
			ans += '%';
			ans += '2';
			ans += '0';
		} else {
			ans += s[i];
		}
	}
	s = ans;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	string s;
	getline(cin,s);
	replace(s);
	cout << s;
	return 0;
}
