#include<bits/stdc++.h>
using namespace std;

string compress(string &s) {
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	string ans = "";
	int i = 0 , j = 0;
	while(i < s.size()) {
		char temp = s[i];
		int count = 0;
		while(s[j] == temp) {
			j++;
			count++;
		}
		ans += s[i];
		ans += to_string(count);
		i = j;
	}
	if(ans.size() < s.size()) {
		return ans;
	} else {
		return s;
	}
	// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}

int main()
{
	string s;
	cin >> s;
	string result = compress(s);
	cout << result;
	return 0;
	
}
